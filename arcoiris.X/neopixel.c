//------------------------------------------------------------------------------
//Neopìxel lamp, for ayu, with <3 from skaptor
//------------------------------------------------------------------------------
#include "mcc_generated_files/mcc.h"
#include "neopixel.h"

NEOPIXEL_t pixels[N_LEDS];

static void stream(NEOPIXEL_t *pPixel);
static void wheel(uint16_t idx, uint8_t pos);

//------------------------------------------------------------------------------
void neo_initialize(void)
{
    uint8_t i;

    for(i=0 ; i<N_LEDS ; i++){
        pixels[i].red = 0x00;
        pixels[i].grn = 0x00;
        pixels[i].blu = 0x00;
    }
}
//------------------------------------------------------------------------------
void neo_updateStrip(void)
{
    uint8_t i;

    for(i=0 ; i<N_LEDS ; i++){
        stream(&pixels[i]);
    }
}
//------------------------------------------------------------------------------
void fx_arcoIris(void)
{
    uint8_t i;
    static uint16_t wheelPos = 0;

    for(i=0 ; i<N_LEDS ; i++){
        wheel(i, (((i * 0xFF / (N_LEDS)) + wheelPos) & 0xFF));
    }

    //set the new wheel position
    wheelPos = (wheelPos < 1280) ? wheelPos+1 : 0;
}

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
static void sendPixelByte(uint8_t data){
     uint8_t i=0;
     for(i=0; i<8 ; i++){
        SSP1BUF = (((data<<i) & 0x80)) ? 0xFE : 0xC0;
     }
}
//------------------------------------------------------------------------------
static void stream(NEOPIXEL_t *pPixel)
{
    sendPixelByte(pPixel->grn);
    sendPixelByte(pPixel->red);
    sendPixelByte(pPixel->blu);
}
//------------------------------------------------------------------------------
static void wheel(uint16_t idx, uint8_t pos)
{
    uint8_t wheelPos = pos;

    if(pos < 85){
        pixels[idx].red = wheelPos * 3;
        pixels[idx].grn = 255 - wheelPos * 3;
        pixels[idx].blu = 0;
    }else if(pos < 170){
        wheelPos -= 85;
        pixels[idx].red = 255 - wheelPos * 3;
        pixels[idx].grn = 0;
        pixels[idx].blu = wheelPos * 3;
    }else{
        wheelPos -= 170;
        pixels[idx].red = 0;
        pixels[idx].grn = wheelPos * 3;
        pixels[idx].blu = 255 - wheelPos * 3;
    }
}