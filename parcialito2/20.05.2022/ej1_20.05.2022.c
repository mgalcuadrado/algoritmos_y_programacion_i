/*
 * Un dispositivo transmite datos de 7 bits en paquetes de 1 byte donde el bit más significativo se usa como
 * paridad y los 7 bits restantes como dato. El bit de paridad vale 0 si la cantidad de unos en los 7 bits del dato
 * son pares y 1 si son impares.
 * Implementar una función 
 * bool verificar_paridad(uint8_t dato); 
 *que indique si el dato es válido. Por ejemplo verificar_paridad(1111 0000) -> true, verificar_paridad(0000 1100) -> true y
 * verificar_paridad(0101 1101) -> false.

 */



#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MASK_PARIDAD 0x80 //honestly I don't think I'll need this
#define MASK_LSB 0x01
#define BIT_PARIDAD 7

//primero realizo un popcnt y después verifico si ese contador % 2 da igual que dato >> SHIFT_PARIDAD
bool verificar_paridad (uint8_t dato){
    size_t contador = 0;
    for (size_t i = 0; i < BIT_PARIDAD; i++)
        if (dato & (MASK_LSB << i))
            contador++;
    return ((dato >> BIT_PARIDAD) == (contador % 2));
}

int main (void){
    uint8_t d = 0xF0, e = 0x5D;
    printf ("este debería dar true, da: %s\n", verificar_paridad(d) ? "true" : "false");
    printf ("este debería dar false, da: %s\n", verificar_paridad(e) ? "true" : "false");
    return 0;

}