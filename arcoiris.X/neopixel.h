//------------------------------------------------------------------------------
//Neopìxel lamp, for ayu, with <3 from skaptor
//------------------------------------------------------------------------------
#ifndef _NEOPIXEL_H_
#define _NEOPIXEL_H_

#include <stdint.h>

#define N_LEDS  15

typedef struct _NEOPIXEL_{
    uint8_t  red;
    uint8_t  grn;
    uint8_t  blu;
}NEOPIXEL_t;

void neo_initialize(void);
void neo_updateStrip(void);
void fx_arcoIris(void);

#endif
