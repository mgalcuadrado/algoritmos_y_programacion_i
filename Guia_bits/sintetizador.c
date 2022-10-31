#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MASK_AFT 0x80
#define MASK_BNDAM 0x40
#define MASK_FDIV 0x3E
#define MASK_SYN 0x01

#define SHIFT_FDIV 1

int get_synthesizer_divider(uint8_t registro){
    return ((registro & MASK_FDIV) >> SHIFT_FDIV) + 1;
}

bool es_am (uint8_t registro){
    return (registro & MASK_BNDAM); 
}

int main (void){
    uint8_t r = 0275;
    printf ("%s\n", es_am(r) ? "Es AM" : "No es AM");
    printf ("Espero 31, da: %d\n", get_synthesizer_divider(r));
    return 0;
}

