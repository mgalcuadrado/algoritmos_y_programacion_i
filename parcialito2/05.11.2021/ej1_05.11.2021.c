/* Un autito se controla por radio frecuencia a través del siguiente registro:
MSB LSB
+-----+-----+-----+-----+-----+-----+-----+-----+
| DER | FRE | G_2 | G_1 | G_0 | V_2 | V_1 | V_0 |
+-----+-----+-----+-----+-----+-----+-----+-----+
  7      6     5    4     3     2     1     0
donde el bit DER está en 1 si el coche va hacia la derecha y en 0 si va hacia la izquierda, el bit
FRE indica si está accionado el freno, los bits G indican el radio de giro, que es un número entre 0
y 7 (que será hacia la izquierda o hacia la derecha según el valor de DER) y los bits V indican la
velocidad.
Se pide programar una función
bool girar_derecha(uint8_t *r);
que dado el registro r incremente el giro hacia la derecha. Notar que qué hacer para incrementar
dependerá del sentido en el que está yendo el cochecito.
Se debe devolver true de poder incrementar el giro y false si el mismo ya estaba al máximo.
Ejemplos:
girar_derecha(DER: 0, G: 6) -> (DER: 0, G: 5) 
girar_derecha(DER: 0, G: 0) -> (DER: 1, G: 1) 
girar_derecha(DER: 1, G: 4) -> (DER: 1, G: 5)
girar_derecha(DER: 1: G: 7) -> (DER: 1, G: 7) // Falla => false
Aclaración: Deben usarse máscaras y operadores de bits para resolver este problema.
*/
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MASK_DER 0x80
#define MASK_GIRO 0x38
#define MASK_LSB 0x01

#define SHIFT_GIRO 3

bool girar_derecha(uint8_t *r){
    if ((*r & MASK_DER) && ((*r & MASK_GIRO) == MASK_GIRO)) return false;
    if (!(*r & MASK_DER) && (*r & MASK_GIRO) == 0){
        *r |= MASK_DER | (MASK_LSB << SHIFT_GIRO);
        return true;
    }
    //int agregador = (*r & MASK_DER) ? (1) : (-1);
    *r = (*r & (~MASK_GIRO)) | ((((*r & MASK_GIRO) >> SHIFT_GIRO) + /*agregador*/ ((*r & MASK_DER) ? 1 : -1)) << SHIFT_GIRO);
    return true;
}


int main (void){
    uint8_t reg = 0x88;
    printf ("%s\n", girar_derecha (&reg) ? "se giró" : "no se giró");
    printf ("0x88 -> 0x%X\n", reg);
    reg = 0x68;
    printf ("%s\n", girar_derecha (&reg) ? "se giró" : "no se giró");
    printf ("0x68 -> 0x%X\n", reg);
    reg = 0xF8;
    printf ("%s\n", girar_derecha (&reg) ? "se giró" : "no se giró");
    printf ("0xF8 -> 0x%X\n", reg);
    reg = 0x82;
    printf ("%s\n", girar_derecha (&reg) ? "se giró" : "no se giró");
    printf ("0x82 -> 0x%X\n", reg);
    reg = 0x42;
    printf ("%s\n", girar_derecha (&reg) ? "se giró" : "no se giró");
    printf ("0x42 -> 0x%X\n", reg);
    return 0;
}
