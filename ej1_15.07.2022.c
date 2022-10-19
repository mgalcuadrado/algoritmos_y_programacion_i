/*
 * La tabla ASCII está diseñada para realizar determinadas operaciones de forma sencilla mediante manejo de bits.
 * Algunas de ellas son:
 * Todas las mayúsculas son de la forma 010xxxxx donde xxxxx representa el número de letra (entre 1 y 26).
 * Todas las minúsculas son de la forma 011xxxxx donde xxxxx representa el número de letra (entre 1 y 26).
 * Utilizando operaciones de bits implementar las siguientes funciones:
 *      bool es_minuscula(char c); // Indica si un caracter es minúscula
 *      char a_mayusculas(char c); // Si una letra es minúscula la convierte a mayúsculas
 * Nota: El ejercicio debe resolverse utilizando bits. Se permite utilizar comparaciones sobre los valores indicados con
 * equis en los ejemplos. No se permite resolver los ejercicios con operaciones de comparación sobre el ASCII completo (es
 * decir, es_minúscula puede incluir chequear xxxxx <= 26 pero no puede incluir c <= 'z' o c <= 'a'.)
 */


#include <stdio.h>
#include <stdbool.h>

#define MASK_MINUS 0x60
#define MASK_CAPS 0x20

#define MASK_LETRA 0x1F


#define SHIFT_CAPS 5

bool es_minuscula (char c){
    if ((c & MASK_LETRA) < 1 || (c & MASK_LETRA) > 26)
        return false;
    if (((c >> SHIFT_CAPS) & (MASK_MINUS >> SHIFT_CAPS)) != (MASK_MINUS >> SHIFT_CAPS))
        return false;
    return true;
}

char a_mayuscula (char c){
    if (! es_minuscula (c)) return c;
    return c &= (~MASK_CAPS);
}


int main (void){
    printf ("debería ser min, es: %s\n", es_minuscula ('i') ? "min" : "no min");
    printf ("debería no ser min, es: %s\n", es_minuscula ('T') ? "min" : "no min");
    printf ("debería no ser min, es: %s\n", es_minuscula (4) ? "min" : "no min");
    printf("%c en mayúscula es %c\n", 'd', a_mayuscula('d'));
    return 0;
}