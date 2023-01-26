#include "displaymenu.h"

/*set all the button to unpressed*/
void resetButtons(){
    buttonUp=false;
    buttonCenter=false;
    buttonDown=false;
}

/*clear all context*/
void clearDisplay(){
    Graphics_clearDisplay(&background_context);
    Graphics_clearDisplay(&selected_context);
}

/*show welcome on display*/
void welcomeOn(){
    Graphics_drawStringCentered(&background_context, (int8_t *) "WELCOME!", AUTO_STRING_LENGTH, 64, 64, true);
}

/*
Show menu with the FIRST choose selected.
On the top coreners, humidity and temperature are shown.
*/
void AOn(){

    /* Display temperature */
    char string[10];
    sprintf(string, "%f", temp);
    Graphics_drawString(&background_context, (int8_t *) string, 5, 90, 8,
    true);

    sprintf(string, "C");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 120, 8,
    true);

    /* Display humidity */
    sprintf(string, "H: ");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 0, 8,
    true);

    sprintf(string, "%d", hum);
    Graphics_drawString(&background_context, (int8_t *) string, 5, 20, 8,
    true);

    Graphics_drawString(&background_context, (int8_t *) "%", 5, 35, 8,
    true);

    /*Display menu*/

    Graphics_drawStringCentered(&background_context, (int8_t *) "MENU:",
    AUTO_STRING_LENGTH,64, 30, OPAQUE_TEXT);

    Graphics_drawStringCentered(&selected_context, (int8_t *) "Add Custom Plant",
    AUTO_STRING_LENGTH,64, 50, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Insert Water",
    AUTO_STRING_LENGTH,64, 70, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Verify State Water",
    AUTO_STRING_LENGTH,64, 90, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Remote Connection",
    AUTO_STRING_LENGTH,64, 110, OPAQUE_TEXT);
}

/*
Show menu with the SECOND choose selected.
On the top coreners, humidity and temperature are shown.
*/
void BOn(){

   /* Display temperature */
    char string[10];
    sprintf(string, "%f", temp);
    Graphics_drawString(&background_context, (int8_t *) string, 5, 90, 8,
    true);

    sprintf(string, "C");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 120, 8,
    true);

    /* Display humidity */
    sprintf(string, "H: ");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 0, 8,
    true);

    sprintf(string, "%d", hum);
    Graphics_drawString(&background_context, (int8_t *) string, 5, 20, 8,
    true);

    Graphics_drawString(&background_context, (int8_t *) "%", 5, 35, 8,
    true);

    /*Display menu*/

    Graphics_drawStringCentered(&background_context, (int8_t *) "MENU:",
    AUTO_STRING_LENGTH,64, 30, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Add Custom Plant",
    AUTO_STRING_LENGTH,64, 50, OPAQUE_TEXT);

    Graphics_drawStringCentered(&selected_context, (int8_t *) "Insert Water",
    AUTO_STRING_LENGTH,64, 70, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Verify State Water",
    AUTO_STRING_LENGTH,64, 90, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Remote Connection",
    AUTO_STRING_LENGTH,64, 110, OPAQUE_TEXT);

}

/*
Show menu with the THIRD choose selected.
On the top coreners, humidity and temperature are shown.
*/
void COn(){


    /* Display temperature */
    char string[10];
    sprintf(string, "%f", temp);
    Graphics_drawString(&background_context, (int8_t *) string, 5, 90, 8,
    true);

    sprintf(string, "C");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 120, 8,
    true);

    /* Display humidity */
    sprintf(string, "H: ");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 0, 8,
    true);

    sprintf(string, "%d", hum);
    Graphics_drawString(&background_context, (int8_t *) string, 5, 20, 8,
    true);

    Graphics_drawString(&background_context, (int8_t *) "%", 5, 35, 8,
    true);

    /*Display menu*/

    Graphics_drawStringCentered(&background_context, (int8_t *) "MENU:",
    AUTO_STRING_LENGTH,64, 30, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Add Custom Plant",
    AUTO_STRING_LENGTH,64, 50, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Insert Water",
    AUTO_STRING_LENGTH,64, 70, OPAQUE_TEXT);

    Graphics_drawStringCentered(&selected_context, (int8_t *) "Verify State Water",
    AUTO_STRING_LENGTH,64, 90, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Remote Connection",
    AUTO_STRING_LENGTH,64, 110, OPAQUE_TEXT);

}

/*
Show menu with the FOURTH choose selected.
On the top coreners, humidity and temperature are shown.
*/
void EOn(){

    /* Display temperature */
    char string[10];
    sprintf(string, "%f", temp);
    Graphics_drawString(&background_context, (int8_t *) string, 5, 90, 8,
    true);

    sprintf(string, "C");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 120, 8,
    true);

    /* Display humidity */
    sprintf(string, "H: ");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 0, 8,
    true);

    sprintf(string, "%d", hum);
    Graphics_drawString(&background_context, (int8_t *) string, 5, 20, 8,
    true);

    Graphics_drawString(&background_context, (int8_t *) "%", 5, 35, 8,
    true);

    /*Display menu*/

    sprintf(string, "C");
    Graphics_drawString(&background_context, (int8_t *) string, 5, 120, 8,
    true);

    Graphics_drawStringCentered(&background_context, (int8_t *) "MENU:",
    AUTO_STRING_LENGTH,64, 30, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Add Custom Plant",
    AUTO_STRING_LENGTH,64, 50, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Insert Water",
    AUTO_STRING_LENGTH,64, 70, OPAQUE_TEXT);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Verify State Water",
    AUTO_STRING_LENGTH,64, 90, OPAQUE_TEXT);

    Graphics_drawStringCentered(&selected_context, (int8_t *) "Remote Connection",
    AUTO_STRING_LENGTH,64, 110, OPAQUE_TEXT);

}

/*display menu add custom plant with FIRST choose selected*/
void AM1On(){

    Graphics_drawStringCentered(&selected_context, (int8_t *) "GRASSE: HUM 30%", AUTO_STRING_LENGTH, 64, 20, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "NORMALE: HUM 50%", AUTO_STRING_LENGTH, 64, 40, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "TROPICALE: HUM 70%", AUTO_STRING_LENGTH, 64, 60, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "CUSTOM", AUTO_STRING_LENGTH, 64, 80, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "<- MENU", AUTO_STRING_LENGTH, 40, 110, true);
}

/*display menu add custom plant with SECOND choose selected*/
void AM2On(){

    Graphics_drawStringCentered(&background_context, (int8_t *) "GRASSE: HUM 30%", AUTO_STRING_LENGTH, 64, 20, true);
    Graphics_drawStringCentered(&selected_context, (int8_t *) "NORMALE: HUM 50%", AUTO_STRING_LENGTH, 64, 40, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "TROPICALE: HUM 70%", AUTO_STRING_LENGTH, 64, 60, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "CUSTOM", AUTO_STRING_LENGTH, 64, 80, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "<- MENU", AUTO_STRING_LENGTH, 40, 110, true);
}

/*display menu add custom plant with THIRD choose selected*/
void AM3On(){

    Graphics_drawStringCentered(&background_context, (int8_t *) "GRASSE: HUM 30%", AUTO_STRING_LENGTH, 64, 20, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "NORMALE: HUM 50%", AUTO_STRING_LENGTH, 64, 40, true);
    Graphics_drawStringCentered(&selected_context, (int8_t *) "TROPICALE: HUM 70%", AUTO_STRING_LENGTH, 64, 60, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "CUSTOM", AUTO_STRING_LENGTH, 64, 80, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "<- MENU", AUTO_STRING_LENGTH, 40, 110, true);
}

/*display menu add custom plant with FOURTH choose selected*/
void AM4On(){

    Graphics_drawStringCentered(&background_context, (int8_t *) "GRASSE: HUM 30%", AUTO_STRING_LENGTH, 64, 20, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "NORMALE: HUM 50%", AUTO_STRING_LENGTH, 64, 40, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "TROPICALE: HUM 70%", AUTO_STRING_LENGTH, 64, 60, true);
    Graphics_drawStringCentered(&selected_context, (int8_t *) "CUSTOM", AUTO_STRING_LENGTH, 64, 80, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "<- MENU", AUTO_STRING_LENGTH, 40, 110, true);
}

/*display menu add custom plant with FIFTH choose selected*/
void AM5On(){

    Graphics_drawStringCentered(&background_context, (int8_t *) "GRASSE: HUM 30%", AUTO_STRING_LENGTH, 64, 20, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "NORMALE: HUM 50%", AUTO_STRING_LENGTH, 64, 40, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "TROPICALE: HUM 70%", AUTO_STRING_LENGTH, 64, 60, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "CUSTOM", AUTO_STRING_LENGTH, 64, 80, true);
    Graphics_drawStringCentered(&selected_context, (int8_t *) "<- MENU", AUTO_STRING_LENGTH, 40, 110, true);
}

/*display menu SET CUSTOM HUMIDITY*/
void AM4CUSTOMOn(){

    //Converti il valore in una stringa
    char str[10];
    sprintf(str, "%d", thum);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Umidita: ", AUTO_STRING_LENGTH, 64, 50, true);
    Graphics_drawStringCentered(&selected_context, (int8_t *) str, 5, 64, 70, true);
    Graphics_drawStringCentered(&selected_context, (int8_t *) "%", AUTO_STRING_LENGTH, 75, 70, true);
}

/*
Turn on water motor if WaterOn=1. It depends on the manually activation.
Show the current state of the motor on the display.
*/
void BMOn(){
    if(waterOn){
        GPIO_setOutputHighOnPin(WATER_MOTOR_PORT,  WATER_MOTOR_PIN);
    }else{
        GPIO_setOutputLowOnPin(WATER_MOTOR_PORT,  WATER_MOTOR_PIN);
    }

    Graphics_drawStringCentered(&background_context, (int8_t *) "Water: ", AUTO_STRING_LENGTH, 64, 50, true);
    if(waterOn){
        Graphics_drawStringCentered(&background_context, (int8_t *) "On ", AUTO_STRING_LENGTH, 64, 70, true);
    }else{
        Graphics_drawStringCentered(&background_context, (int8_t *) "Off", AUTO_STRING_LENGTH, 64, 70, true);
    }

    Graphics_drawString(&selected_context, (int8_t *) "MENU", AUTO_STRING_LENGTH, 0, 90, true);
}

/*
Show the water value.
Create a stars indicator.
1 star=LOW
10 stars=HIGH
*/
void CMOn(){

    //Converti il valore in una stringa
    char str[10];
    sprintf(str, "%d", lvlW);

    Graphics_drawStringCentered(&background_context, (int8_t *) "Water Level: ", AUTO_STRING_LENGTH, 64, 50, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) str, AUTO_STRING_LENGTH, 64, 70, true);
    Graphics_drawStringCentered(&background_context, (int8_t *) "%", AUTO_STRING_LENGTH, 74, 70, true);

    int i;
    int offset=40;

    for(i=0; i<10;i++){
        if(i<(lvlW/10)){
            Graphics_drawString(&background_context, (int8_t *) "*", 5, offset, 80, true);
            offset+=5;
        }else{
            Graphics_drawString(&background_context, (int8_t *) "_", 5, offset, 80, true);
            offset+=5;
        }
    }

    Graphics_drawString(&selected_context, (int8_t *) "MENU", AUTO_STRING_LENGTH, 0, 100, true);

}

/*Create a suspended state.*/
void EMOn(){
    Graphics_drawStringCentered(&selected_context, (int8_t *) "AVAILABLE SOON!", AUTO_STRING_LENGTH, 64, 64, true);
}

/*Display the new value store correctly.*/
void DoneOn(){
    Graphics_drawStringCentered(&background_context, (int8_t *) "Value stored", AUTO_STRING_LENGTH, 64, 50, true);
    Graphics_drawStringCentered(&selected_context, (int8_t *) "correctly!", AUTO_STRING_LENGTH, 64, 70, true);
}

/*Display low water*/
void LowWaterDisplay(){
    Graphics_drawStringCentered(&selected_context, (int8_t *) "Low Water", AUTO_STRING_LENGTH, 64, 50, true);
}

void fn_WELCOME(){
    welcomeOn();
}

void fn_A(){
        AOn();

        if(buttonDown) {resetButtons(); current_state=STATE_B; fn_B();}
        if(buttonUp) {resetButtons(); current_state=STATE_E; fn_E();}
        if (buttonCenter) {clearDisplay(); resetButtons(); current_state=STATE_AM1; fn_AM1();}
}

void fn_B(){
        BOn();

        if(buttonDown) {resetButtons(); current_state=STATE_C; fn_C();}
        if(buttonUp) {resetButtons(); current_state=STATE_A; fn_A();}
        if (buttonCenter) {clearDisplay();resetButtons(); waterOn=0; current_state=STATE_BM; fn_BM();}
}

void fn_C(){
        COn();

        if(buttonDown) {resetButtons(); current_state=STATE_E; fn_E();}
        if(buttonUp) {resetButtons(); current_state=STATE_B; fn_B();}
        if (buttonCenter) {clearDisplay(); resetButtons(); current_state=STATE_CM; fn_CM();}
}


void fn_E(){
        EOn();

        if(buttonDown) {resetButtons(); current_state=STATE_A; fn_A(); }
        if(buttonUp) {resetButtons(); current_state=STATE_C; fn_C(); }
        if (buttonCenter) {clearDisplay(); resetButtons(); current_state=STATE_EM; fn_EM(); }
}

/*if pressed, saves the threshold of humidity to 30%*/
void fn_AM1(){
        AM1On();

        if(buttonDown) {resetButtons(); current_state=STATE_AM2; fn_AM2(); }
        if(buttonUp) {resetButtons(); current_state=STATE_AM5; fn_AM5(); }
        if (buttonCenter){
            thum=30;
            clearDisplay();
            resetButtons();
            current_state=STATE_DONE;
            fn_DONE();
        }
}

/*if pressed, saves the threshold of humidity to 50%*/
void fn_AM2(){
        AM2On();

        if(buttonDown) {resetButtons(); current_state=STATE_AM3; fn_AM3(); }
        if(buttonUp) {resetButtons(); current_state=STATE_AM1; fn_AM1(); }
        if (buttonCenter){
            thum=50;
            clearDisplay();
            resetButtons();
            current_state=STATE_DONE;
            fn_DONE();
        }
}

/*if pressed, saves the threshold of humidity to 70%*/
void fn_AM3(){
        AM3On();

        if(buttonDown) {resetButtons(); current_state=STATE_AM4; fn_AM4(); }
        if(buttonUp) {resetButtons(); current_state=STATE_AM2; fn_AM2(); }
        if (buttonCenter){
            thum=70;
            clearDisplay();
            resetButtons();
            current_state=STATE_DONE;
            fn_DONE();
        }
}

/*if pressed, saves the threshold of humidity to 50% and pass the control to the user to change it*/
void fn_AM4(){
        AM4On();

        if(buttonDown) {resetButtons(); current_state=STATE_AM5; fn_AM5(); }
        if(buttonUp) {resetButtons(); current_state=STATE_AM3; fn_AM3(); }
        if (buttonCenter){
            thum=50;
            clearDisplay();
            resetButtons();
            current_state=STATE_AM4CUSTOM;
            fn_AM4CUSTOM();

        }
}

/*come back to menu*/
void fn_AM5(){
        AM5On();

        if(buttonDown) {resetButtons(); current_state=STATE_AM1; fn_AM1(); }
        if(buttonUp) {resetButtons(); current_state=STATE_AM3; fn_AM4(); }
        if (buttonCenter){
            clearDisplay();
            resetButtons();
            current_state=STATE_A;
            fn_A();
        }
}

/*change the threshold between 10% and 95%*/
void fn_AM4CUSTOM(){
        AM4CUSTOMOn();

        if(buttonUp) {

            if(thum<95){
                thum+=5;
            }

            resetButtons();
            current_state=STATE_AM4CUSTOM;
            fn_AM4CUSTOM();
        }

        if(buttonDown) {
            if(thum>10){
                thum-=5;
            }

            resetButtons();
            current_state=STATE_AM4CUSTOM;
            fn_AM4CUSTOM();
        }

        if (buttonCenter){
            clearDisplay();
            resetButtons();
            current_state=STATE_DONE;
            fn_DONE();
        }
}

/*
toggles the water motor.
If comes back to the menu, the water motor automatically is turn off.
*/
void fn_BM(void){
    BMOn();

    if(buttonDown || buttonUp){
        if(waterOn){
            waterOn=0;
            GPIO_setOutputLowOnPin(WATER_MOTOR_PORT,  WATER_MOTOR_PIN);
        }

        clearDisplay();
        resetButtons();
        current_state=STATE_B;
        fn_B();
    }

    if(buttonCenter) {
        waterOn=(waterOn+1)%2;
        BMOn();
    }
}

void fn_CM(){
        CMOn();

        if(buttonDown || buttonUp) {clearDisplay(); resetButtons(); current_state=STATE_C; fn_C(); }
}

void fn_EM(){
    EMOn();

    if(buttonDown || buttonUp) {clearDisplay(); resetButtons(); current_state=STATE_E; fn_E(); }
}

void fn_DONE(){

        DoneOn();

        clearDisplay();
        resetButtons();
        current_state=STATE_A;
        fn_A();

}

void fn_LOWWATER(){
        clearDisplay();
        resetButtons();

        LowWaterDisplay();
}
