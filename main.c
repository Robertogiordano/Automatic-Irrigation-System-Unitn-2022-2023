#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "lib/LcdDriver/Crystalfontz128x128_ST7735.h"
#include "lib/LcdDriver/HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.h"
#include "lib/HAL_I2C.h"
#include "lib/HAL_TMP006.h"
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#include "lib/displaymenu.h"

/*End Includes*/

/*Define constants*/
#define HUMIDITY_SENSOR_PORT GPIO_PORT_P5
#define HUMIDITY_SENSOR_PIN GPIO_PIN5

#define WATER_SENSOR_PORT GPIO_PORT_P5
#define WATER_SENSOR_PIN GPIO_PIN2

/*Number of timer interrupts*/
uint32_t val=0;
uint32_t val2=0;

/*Enter in emergency state provocated by low water level*/
bool emergency_state=0;

/*Array of func pointers and FSM*/
StateMachine_t fsm[] = {
            {STATE_WELCOME, fn_WELCOME},
            {STATE_A, fn_A},
            {STATE_B, fn_B},
            {STATE_C, fn_C},
            {STATE_E, fn_E},
            {STATE_AM1, fn_AM1},
            {STATE_AM2, fn_AM2},
            {STATE_AM3, fn_AM3},
            {STATE_AM4, fn_AM4},
            {STATE_AM5, fn_AM5},
            {STATE_AM4CUSTOM, fn_AM4CUSTOM},
            {STATE_BM, fn_BM},
            {STATE_CM, fn_CM},
            {STATE_EM, fn_EM},
            {STATE_DONE, fn_DONE},
            {STATE_LOWWATER, fn_LOWWATER}
};

/*Initialize the values for the background context of LCD 128x128 display*/
void _graphicsInit()
{
    /* Initializes display */
    Crystalfontz128x128_Init();

    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    /* Initializes graphics context */
    Graphics_initContext(&background_context, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);
    Graphics_setForegroundColor(&background_context, GRAPHICS_COLOR_BLACK);
    Graphics_setBackgroundColor(&background_context, GRAPHICS_COLOR_WHITE);
    GrContextFontSet(&background_context, &g_sFontFixed6x8);
    Graphics_clearDisplay(&background_context);

}

/*Initialize the values for the selected context of LCD 128x128 display*/
void _graphicsInitSelectedString()
{
    /* Initializes display */
    Crystalfontz128x128_Init();

    /* Set default screen orientation */
    Crystalfontz128x128_SetOrientation(LCD_ORIENTATION_UP);

    /* Initializes graphics context */
    Graphics_initContext(&selected_context, &g_sCrystalfontz128x128, &g_sCrystalfontz128x128_funcs);
    Graphics_setForegroundColor(&selected_context, GRAPHICS_COLOR_BLACK);
    Graphics_setBackgroundColor(&selected_context, GRAPHICS_COLOR_GRAY);
    GrContextFontSet(&selected_context, &g_sFontFixed6x8);
    Graphics_clearDisplay(&selected_context);

}

/*
configure ADC14 sampling multiple values from different analog inputs.
The clock sampling time is set to MCLK.

Humidity sensor from port A0 saves the value in MEM0.
Water level sensor from port A2 saves the value in MEM2.
TMP sensor from MSP432 board from input A22 saves the values into MEM2.

*/
void configureADC14(){

    /* Initializing Variables */
    hum = 0;
    lvlW = 0;
    temp=0;

    /* Configuring GPIOs (5.5 A0) */
    GPIO_setAsPeripheralModuleFunctionInputPin(HUMIDITY_SENSOR_PORT, HUMIDITY_SENSOR_PIN,
    GPIO_TERTIARY_MODULE_FUNCTION);

     /* Configuring GPIOs (5.2 A3) */
    GPIO_setAsPeripheralModuleFunctionInputPin(WATER_SENSOR_PORT, WATER_SENSOR_PORT,
    GPIO_TERTIARY_MODULE_FUNCTION);

    /* Enable ADC block*/
    ADC14_enableModule();

    //![Single Sample Mode Configure]
    /* Initializing ADC (MCLK/1/4) */
    ADC14_initModule(ADC_CLOCKSOURCE_MCLK, ADC_PREDIVIDER_1, ADC_DIVIDER_4,0);

    /* Configuring ADC Memory */
    ADC14_configureMultiSequenceMode(ADC_MEM0, ADC_MEM1, true);

    ADC14_configureConversionMemory(ADC_MEM0, ADC_VREFPOS_AVCC_VREFNEG_VSS,ADC_INPUT_A0, false);

    ADC14_configureConversionMemory(ADC_MEM1, ADC_VREFPOS_AVCC_VREFNEG_VSS,ADC_INPUT_A3, false);

    /* Configuring Sample Timer */
    ADC14_enableSampleTimer(ADC_MANUAL_ITERATION);

    /* Enabling interrupts */
    ADC14_enableInterrupt(ADC_INT1); /***************/
    Interrupt_enableInterrupt(INT_ADC14);
}

/*Init TMP sensor of boosterpack */
void _temperatureSensorInit()
{
    /* Temperature Sensor initialization */
    /* Initialize I2C communication */
    Init_I2C_GPIO();
    I2C_init();
    /* Initialize TMP006 temperature sensor */
    TMP006_init();
    __delay_cycles(100000);

}

/*configure buttons of boosterpack connected to port P3.5, P4.1, P5.1 (joystick button)*/

void configureButtons(){
     /* P3.5 as input for button */
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P3, GPIO_PIN5);
    GPIO_enableInterrupt(GPIO_PORT_P3, GPIO_PIN5);

    /* P4.1 as input for button */
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P4, GPIO_PIN1);
    GPIO_enableInterrupt(GPIO_PORT_P4, GPIO_PIN1);

    /* P5.1 as input for button */
    GPIO_setAsInputPinWithPullUpResistor(GPIO_PORT_P5, GPIO_PIN1);
    GPIO_enableInterrupt(GPIO_PORT_P5, GPIO_PIN1);


    /* Enable interrupts on Port 3-4-5 (to catch P3.5,P4.1,P5.1) */
    Interrupt_enableInterrupt(INT_PORT3);
    Interrupt_enableInterrupt(INT_PORT4);
    Interrupt_enableInterrupt(INT_PORT5);
}

/*
Two timers are set.
The first is 4 times faster than the second.

The first, when fires the interrupt, check always the input and the logic to do.
Each 0.25 sec.

The second, when fires the interrupt, refresh the current state in the display, 
giving the possibility to see the input values continously change.
*/

/* Application Defines  */
#define TIMER_PERIOD    0xB71B

/* Timer_A UpMode Configuration Parameter */
const Timer_A_UpModeConfig upConfig =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_64,          // SMCLK/64 = 46875 Hz
        TIMER_PERIOD/4,                           // 46875/4 tick period: 4 tick per second
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR                        // Clear value
};

void configureTimer(){
    /* Configuring Timer_A1 for Up Mode */
    Timer_A_configureUpMode(TIMER_A1_BASE, &upConfig);

    /* Enabling interrupts and starting the timer */
    Interrupt_enableSleepOnIsrExit();
    Interrupt_enableInterrupt(INT_TA1_0);
    Timer_A_startCounter(TIMER_A1_BASE, TIMER_A_UP_MODE);
}

/* Timer_A UpMode Configuration Parameter for 1 sec*/
const Timer_A_UpModeConfig upConfigSlow =
{
        TIMER_A_CLOCKSOURCE_SMCLK,              // SMCLK Clock Source
        TIMER_A_CLOCKSOURCE_DIVIDER_64,          // SMCLK/64 = 46875 Hz
        TIMER_PERIOD,                           // 46875 tick period: 1 tick per second
        TIMER_A_TAIE_INTERRUPT_DISABLE,         // Disable Timer interrupt
        TIMER_A_CCIE_CCR0_INTERRUPT_ENABLE ,    // Enable CCR0 interrupt
        TIMER_A_DO_CLEAR                        // Clear value
};

void configureSlowTimer(){
    /* Configuring Timer_A2 for Up Mode */
    Timer_A_configureUpMode(TIMER_A2_BASE, &upConfigSlow);

    /* Enabling interrupts and starting the timer */
    Interrupt_enableSleepOnIsrExit();
    Interrupt_enableInterrupt(INT_TA2_0);
    Timer_A_startCounter(TIMER_A2_BASE, TIMER_A_UP_MODE);
}

void _hwInit()
{
    /* Stop WDT  */
    WDT_A_holdTimer();

    buttonUp=false;
    buttonDown=false;
    buttonCenter=false;
    thum=50;
    current_state = STATE_WELCOME; //the state is initially welcome, waiting for all the settings. After two seconds changes.

    /* Halting WDT and disabling master interrupts */
    Interrupt_disableMaster();

    /*MOTOR WATER SET AS OUTPUT P5.1*/
    GPIO_setAsOutputPin(WATER_MOTOR_PORT,  WATER_MOTOR_PIN);
    GPIO_setOutputLowOnPin(WATER_MOTOR_PORT,WATER_MOTOR_PIN);

    /* Set the core voltage level to VCORE1 */
    PCM_setCoreVoltageLevel(PCM_VCORE1);

    /* Set 2 flash wait states for Flash bank 0 and 1*/
    FlashCtl_setWaitState(FLASH_BANK0, 2);
    FlashCtl_setWaitState(FLASH_BANK1, 2);

    /* Initializes Clock System */
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_48);
    CS_initClockSignal(CS_MCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_HSMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1);
    CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_16);
    CS_initClockSignal(CS_ACLK, CS_REFOCLK_SELECT, CS_CLOCK_DIVIDER_1);

    /* Initializes all modules*/
     _graphicsInitSelectedString();
     _graphicsInit();
    _temperatureSensorInit();
    configureButtons();
    configureADC14();
    configureTimer();
    configureSlowTimer();
}



int main(void)
{
     _hwInit();
    (*fsm[current_state].state_function)();

    /*everything is initialized, the menu can appear*/

    /* Enabling MASTER interrupts */
    Interrupt_enableMaster();

    /* Sleeping when not in use */
    while (1)
    {
        PCM_gotoLPM0();
    }
}

/*rapid clock handler*/
void TA1_0_IRQHandler(void)
{
    ++val;

    /* Obtain temperature value from TMP006*/
    temp = (TMP006_getTemp()-32.0f)*5.0f/9.0f;


    /* Enabling/Toggling Conversion */
    ADC14_enableConversion();
    ADC14_toggleConversionTrigger();
    //![Single Sample Mode Configure]

    /*
    When interrupt it toggled, verified that the level of the water is enough to irrigate
    a plant, otherwise an error will appear on the display and the whole system will be blocked
    until the container is filled again.

    The interrupt continues to be exectued in order to check the level.
    */

    if(current_state!=STATE_WELCOME){
        if(lvlW<10){
            if(!emergency_state){
                emergency_state=1;
                (*fsm[STATE_LOWWATER].state_function)();
            }
        }else{
            emergency_state=0;
        }

        /*Unless the irrigation is not in manually mode, the interrupts continuosly
        check if the humidity of the soil is lower than the threshold set.
        If it, the water motor is turned on.*/

        if(current_state!=STATE_BM){
            if(hum<thum){
                GPIO_setOutputHighOnPin(WATER_MOTOR_PORT,WATER_MOTOR_PIN);
                waterOn=1;
            }else{
                GPIO_setOutputLowOnPin(WATER_MOTOR_PORT,WATER_MOTOR_PIN);
                waterOn=0;
            }
        }
    }

    Timer_A_clearCaptureCompareInterrupt(TIMER_A1_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_0);

  }

/*slow timer handler*/

/*each second update the values on the display calling the same state.*/
void TA2_0_IRQHandler(void)
{
    ++val2;

        /*after two seconds, exit from welcom state and show the menu*/
       if(val2==2){
        clearDisplay();
        current_state=STATE_A;
       }

        /*refresh display with new values*/
        if((current_state!=STATE_BM) && (!emergency_state)){
            (*fsm[current_state].state_function)();
        }

        Timer_A_clearCaptureCompareInterrupt(TIMER_A2_BASE,TIMER_A_CAPTURECOMPARE_REGISTER_0);
}

/* Port3 ISR for button */
void PORT3_IRQHandler(void)
{
    /* Check which pins generated the interrupts */
    uint_fast16_t status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P3);
    /* clear interrupt flag (to clear pending interrupt indicator */
    GPIO_clearInterruptFlag(GPIO_PORT_P3, status);
    /* check if we received P1.1 or P1.4 interrupt */
    if((status & GPIO_PIN5)){
        buttonDown=true;

        if(current_state < NUM_STATES){
                (*fsm[current_state].state_function)();
        }
        else{
            /* serious error */
        }
    }
}

/* Port5 ISR for button*/
void PORT4_IRQHandler(void)
{
    /* Check which pins generated the interrupts */
    uint_fast16_t status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P4);
    /* clear interrupt flag (to clear pending interrupt indicator */
    GPIO_clearInterruptFlag(GPIO_PORT_P4, status);
    /* check if we received P1.1 or P1.4 interrupt */
    if((status & GPIO_PIN1)){

        buttonCenter=true;

        if(current_state < NUM_STATES){
                (*fsm[current_state].state_function)();
        }
        else{
            /* serious error */
        }
    }
}

/* Port5 ISR for button*/
void PORT5_IRQHandler(void)
{
    /* Check which pins generated the interrupts */
    uint_fast16_t status = GPIO_getEnabledInterruptStatus(GPIO_PORT_P5);
    /* clear interrupt flag (to clear pending interrupt indicator */
    GPIO_clearInterruptFlag(GPIO_PORT_P5, status);
    /* check if we received P1.1 or P1.4 interrupt */
    if((status & GPIO_PIN1)){

        buttonUp=true;

        if(current_state < NUM_STATES){
                (*fsm[current_state].state_function)();
        }
        else{
            /* serious error */
        }
    }
}

 //![Single Sample Result]
/* ADC Interrupt Handler. This handler is called whenever there is a conversion
 * that is finished for ADC_MEM2.
 */
void ADC14_IRQHandler(void)
{
        /* should be between 0 and 16384. 14 bits sampling.*/

    uint64_t status = ADC14_getEnabledInterruptStatus();
    ADC14_clearInterruptFlag(status);

    if (ADC_INT1 & status)
    {

        hum = 100-((ADC14_getResult(ADC_MEM0)-5000)*100)/(16383-5000);
        lvlW = (ADC14_getResult(ADC_MEM1)*100)/16383;

        /* next sample */
        ADC14_disableConversion();
    }

}
//![Single Sample Result]
