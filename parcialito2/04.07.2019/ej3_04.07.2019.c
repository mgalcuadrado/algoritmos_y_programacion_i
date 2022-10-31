// bool leer_flotantes(float ** pv, size_t *n);
// lee valores de stdin y los almacena en un arreglo dinámico de flotantes 
// devuelve por interfaz el vector dinámico pv y la longitud n del vector

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR 30

#define INIT_SIZE 20
#define MULT 2 
//usé una estrategia de incremento geométrica para ganar tiempo (pero pierde eficiente en términos de memoria)


bool leer_flotantes (float ** pv, size_t * n){
    *n = INIT_SIZE;
    float * pointer = malloc ((*n) * sizeof(float));
    if (pointer == NULL) return false;
    char lectura [MAX_STR];
    size_t leidos = 0;
    while (fgets(lectura, MAX_STR, stdin) != NULL){
        if (leidos == *n){
            *n *= MULT;
            float * aux = realloc (pointer, (*n) * sizeof(float));
            if (aux == NULL){
                free (pointer);
                return false;
            }
            pointer = aux;
        }
        pointer[leidos++] = atof(lectura);
    }
    *pv = pointer;
    return true;
}

int main (void){
    float * vector;
    size_t n;
    if (!leer_flotantes (&vector, &n))
        return 1;
    free(vector);
    return 0;
}