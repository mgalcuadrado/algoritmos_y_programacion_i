#include <stdio.h>
#include <stdint.h>

#define MASK_DIA 0x1F
#define MASK_MES 0x01E0
#define MASK_YEAR 0x1FFE00
#define MASK_SIGNO 0x400000

#define SHIFT_MES 5
#define SHIFT_YEAR 9

struct tiempo{
    unsigned int dia, mes;
    int year;
};

typedef struct tiempo sttiempo_t;
typedef uint32_t tiempo_t;

void tiempo_a_sttiempo (tiempo_t t, sttiempo_t * st){
    st->dia = (t & MASK_DIA);
    st->mes = ((t & MASK_MES) >> SHIFT_MES);
    st->year = ((t & MASK_YEAR) >> SHIFT_YEAR) * ((t & MASK_SIGNO) ? -1 : 1);
}

int main (void){
    

    return 0;
}