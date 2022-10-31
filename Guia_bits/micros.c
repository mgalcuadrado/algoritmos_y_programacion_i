#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>


#define MASK_TXCIE 0x40 //ej9

#define MAX_STR 100

#define MASK_SPIE 0x80
#define MASK_CPOL 0x08
#define MASK_FDIV 0x06

#define SHIFT_FDIV 1
// ej9

typedef int fdiv_t;


bool transmision_completa (uint8_t registro){
    return (registro & MASK_TXCIE);
}

//ej11

bool getSPIE(uint8_t registro){
    return (registro & MASK_SPIE);
}

bool getCPOL(uint8_t registro){
    return (registro & MASK_CPOL);
}

void getCOMControl(uint8_t registro, bool * spie, bool * cpol, fdiv_t * fdiv){
    *spie = registro & MASK_SPIE;
    *cpol = registro & MASK_CPOL;
    *fdiv = (registro & MASK_FDIV) >> SHIFT_FDIV;
}

void setCPOL (uint8_t * control, bool on){
    if (on == true){
        *control |= MASK_CPOL;
    }
    if (on == false){
        *control &= (~MASK_CPOL);
    }
}

int main (void){
    uint8_t r1 = 0143;
    //ej9
    printf ("%s\n", transmision_completa(r1) ? "True" : "False");
    //
    bool spie, cpol;
    fdiv_t fdiv;
    getCOMControl (r1, &spie, &cpol, &fdiv);
    printf ("SPIE: %s\n", spie ? "True" : "False");   
    printf ("CPOL: %s\n", cpol ? "True" : "False");     
    setCPOL(&r1, true);
    printf ("CPOL: %s\n", getCPOL(r1) ? "True" : "False");     

    return 0;
}



