#include <stdio.h>
#include <stdint.h>

#define MASK_BIT 0x01

uint8_t set(uint8_t datos, short linea){
    return datos |= (MASK_BIT << linea);
}

uint8_t clear(uint8_t datos, short linea){
    return datos &= (~(MASK_BIT << linea));
}

int main (void){
    uint8_t r = 0x44;
    printf("0x%X\n", r);
    printf("0x%X\n", set(r, 4));
    printf("0x%X\n", clear(r, 4));
    return 0;
}

