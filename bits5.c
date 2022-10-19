//big endian - decimal


#include <stdio.h>
#include <stdint.h>

#define MASK_ENDIAN 0xFF

//(x[3] << 24) | (x[2] << 16) | (x[1] << 8) | x[0]
uint32_t endian_a_decimal (uint32_t v[], size_t len){
    uint32_t rta = v[0];
    for (size_t i = 1; i < len; i++){
        rta |= v[i] << i * 8;
    }
    return rta;
}



int main (void){
    //DECIMAL A BIG ENDIAN
    uint32_t n = 271590900;
    uint32_t x[4] = {0};
    for (size_t i = 0; i < 4; i++){
        x[i] = (n & (MASK_ENDIAN << i * 8)) >> i * 8;
        printf ("x[%zd] = 0x%2x\n", i, x[i]);
    }
    //BIG ENDIAN A DECIMAL
    printf ("%d\n", endian_a_decimal (x, 4));
    return 0;
}

