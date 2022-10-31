#include <stdio.h>
#include <stdint.h>

#define MASK_MSB 0x80000000
#define MASK_LSB 0x00000001
#define MASK_BYTE 0x000000FF
#define SHIFT_BYTE 8

//leading zeros count (ceros desde MSB hasta primer 1)
int lzcnt(uint32_t n){
    int contador = 0;
    for (size_t i = 0; i < 32; i++){
        if (n & (MASK_MSB >> i))
            return contador;
        else contador++;    
    }
    return contador;
}

int popcnt(uint32_t n){
    int contador = 0;
    for (size_t i = 0; i < 32; i++){
        if (n & (MASK_MSB >> i))
            contador++;    
    }
    return contador;
}
//inc
uint32_t bextr(uint32_t a, uint16_t b){
uint32_t inicio = (b & MASK_BYTE), longitud = (b & (MASK_BYTE << SHIFT_BYTE)), rta;
rta = (a << inicio);

}

//extract lowest set isolated bit
uint32_t blsi(uint32_t n){
    for (size_t i = 0; i < 32; i++){
        if (n & (MASK_LSB << i))
            return MASK_LSB << i;
    }
    return 0x00;

}

//reset lowest set bit
uint32_t blsr(uint32_t n){
    for (size_t i = 0; i < 32; i++){
        if (n & (MASK_LSB << i))
            return n & ~(MASK_LSB << i);
    }
    return n;
}

//trailing zeros count
int tzcnt(uint32_t n){
int contador = 0;
    for (size_t i = 0; i < 32; i++){
        if (n & (MASK_LSB << i))
            return contador;
        else contador++;    
    }
    return contador;
}

int main (void){
    uint32_t r = 0xAC9653;
    printf ("Cantidad de ceros: %d\n", lzcnt(r));
    printf ("Cantidad de unos: %d\n", popcnt(r));
    return 0;

}
