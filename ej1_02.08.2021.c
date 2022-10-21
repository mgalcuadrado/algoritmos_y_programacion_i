/*
Implementar una función
size_t distancia_en_bits(unsigned int a, unsigned int b);
que devuelva la cantidad de bits que son iguales entre el número a y el número b. A priori no se sabe la
cantidad de bits de la plataforma.
Por ejemplo si se recibieran los números 0xB2 y 0x63 y la plataforma fuera de 8 bits (sizeof(int) == 1)
la función debería devolver 4, porque coinciden los bits 1, 2, 3 y 5:
10110010 a
01100011 b
= === -> 4

*/

#include <stdio.h>

#define MASK_LSB 0x01

size_t distancia_en_bits(unsigned int a, unsigned int b){
   size_t bits_iguales = 0;
    for (size_t i = 0; i < (sizeof(int) * 8); i++)
        if ((a & (MASK_LSB << i)) == (b & (MASK_LSB << i))) bits_iguales++;
    return bits_iguales;
}

int main (void){
    unsigned int v = 0xB2, w = 0x63;
    printf ("%zd\n", distancia_en_bits (v, w));
    return 0;
}
