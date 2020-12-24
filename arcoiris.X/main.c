//------------------------------------------------------------------------------
//Neopìxel lamp, for ayu, with <3 from skaptor
//------------------------------------------------------------------------------
#include "mcc_generated_files/mcc.h"
#include "neopixel.h"


//------------------------------------------------------------------------------
void arcoIris(void)
{
    uint8_t i;

    for(i=0 ; i<N_LEDS ; i++){

    }
}
//------------------------------------------------------------------------------
void main(void)
{
    // initialize the device
    SYSTEM_Initialize();

    TRISB5 = 1;

    //initialize the strip
    neo_initialize();

    for(;;){
        fx_arcoIris();

        neo_updateStrip();
        __delay_ms(15);
    }
}
