#ifndef _DISPLAYMENU_H_
#define _DISPLAYMENU_H_

#include <ti/devices/msp432p4xx/inc/msp.h>
#include <ti/devices/msp432p4xx/driverlib/driverlib.h>
#include <ti/grlib/grlib.h>
#include "LcdDriver/Crystalfontz128x128_ST7735.h"
#include "LcdDriver/HAL_MSP_EXP432P401R_Crystalfontz128x128_ST7735.h"
#include "HAL_I2C.h"
#include "HAL_TMP006.h"
#include <stdio.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>

/*define the port of the motor*/
#define WATER_MOTOR_PORT GPIO_PORT_P7
#define WATER_MOTOR_PIN GPIO_PIN2

/* Graphic library context */
Graphics_Context background_context;
Graphics_Context selected_context;

/*bools buttons*/
bool buttonUp;
bool buttonDown;
bool buttonCenter;

/* Variable for storing temperature value returned from TMP006 */
float temp;

/* Variable for storing humidity value returned from PIN A0 */
volatile uint16_t hum;

/* Variable for storing water value returned from PIN A3 */
volatile uint16_t lvlW;

/* VARIABLE WATER ON*/
int waterOn;

/* Threshold of humidity */
volatile uint8_t thum; //Default plant normal

/*clear the interrupt rise of the button*/
void resetButtons();

/*clear all context of the display*/
void clearDisplay();

/*
Definition of all the functions called by the function state.
Use to display something.
*/

void welcomeOn();               //State welcome!
void AOn();                     //"Add custom plant" selected
void BOn();                     //"insert water" selected
void COn();                     //"Verify state water" selected
void EOn();                     //"Remote connection" selected
void fn_AM1On(void);            //"Low humidity" selected
void fn_AM2On(void);            //"Medium humidity" selected
void fn_AM3On(void);            //"High humidity" selected
void fn_AM4On(void);            //"Custom humidity" selected
void fn_AM5On(void);            //"Go to menu" selected
void fn_AM4CUSTOMOn(void);      //"Change custom humidity"
void BMOn();                    //"Toggle water motor"
void CMOn();                    //"Level water"
void EMOn();                    //"Available soon"
void DoneOn();                  //Change done and saved of humidity threshold
void LowWaterDisplay();         //"Low water" shown on display

/*definition of all states*/
typedef enum {
    STATE_WELCOME,
    STATE_A,
    STATE_B,
    STATE_C,
    STATE_E,
    STATE_AM1,
    STATE_AM2,
    STATE_AM3,
    STATE_AM4,
    STATE_AM5,
    STATE_AM4CUSTOM,
    STATE_BM,
    STATE_CM,
    STATE_EM,
    STATE_DONE,
    STATE_LOWWATER,
    NUM_STATES
}State_t;

/*struct to state and ponter function(void)*/
typedef struct{
    State_t state;
    void (*state_function)(void);
} StateMachine_t;

/*varible to save the current state*/
State_t current_state;

/*states functions call the displays function and change the state depending on the inputs.*/
void fn_WELCOME(void);
void fn_A(void);
void fn_B(void);
void fn_C(void);
void fn_E(void);
void fn_AM1(void);
void fn_AM2(void);
void fn_AM3(void);
void fn_AM4(void);
void fn_AM5(void);
void fn_AM4CUSTOM(void);
void fn_BM(void);
void fn_CM(void);
void fn_EM(void);
void fn_DONE(void);
void fn_LOWWATER(void);

#endif
