#include <stdio.h>
#include <stdint.h>

//RGB = 0xRRGGBB
#define MASK_COLOR 0xFF
#define SHIFT_R 16
#define SHIFT_G 8

uint8_t get_rojo(uint32_t color){
    return (color >> SHIFT_R) & MASK_COLOR;
}

uint8_t get_verde(uint32_t color){
    return (color >> SHIFT_G) & MASK_COLOR;
}

uint8_t get_azul(uint32_t color){
    return color & MASK_COLOR;
}

void get_componentesRGB (uint32_t color, uint8_t * r, uint8_t * g, uint8_t * b){
    *r = (color >> SHIFT_R) & MASK_COLOR;
    *g = (color >> SHIFT_G) & MASK_COLOR;
    *b = color & MASK_COLOR;
}
int main (void){
    uint32_t c = 0xAACCDD;
    uint8_t red, green, blue;
    get_componentesRGB (c, &red, &green, &blue);
    printf ("color = 0x%X%X%X\n", red, green, blue);
    return 0;
}