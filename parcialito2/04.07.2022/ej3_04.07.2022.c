/*
 * Escribir una función bool leer_enteros(int **pv, size_t *n); que lea valores enteros de stdin y los almacene en
 * un vector dinámico de enteros. Los parámetros pv y n son sólamente de salida y la función debe retornar a través de ellos
 * el vector dinámico y su longitud. A su vez debe retornar por el nombre true si todo está bien o false en caso de error.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_STR 30

#define INIT_SIZE 20
#define MULT 2 
//usé una estrategia de incremento geométrica para ganar tiempo (pero pierde eficiente en términos de memoria)



bool leer_enteros(int **pv, size_t *n){
    *n = INIT_SIZE;
    char lec[MAX_STR];
    int * p = malloc ((*n) * sizeof(int));
    if (p == NULL) return false;
    size_t leidos = 0;
    while (fgets(lec, MAX_STR, stdin) != NULL){
        if (leidos == *n){
            *n *= MULT;
            int * aux = realloc (p, (*n) * sizeof(int));
            if (aux == NULL){
                free (p);
                return false;
            }
            p = aux;
        }
        p[leidos++] = atoi(lec);
    }
    *pv = p;
    return true;
}

int main (void){
    int * vector;
    size_t n;
    if (!leer_enteros (&vector, &n))
        return 1;
    free (vector);
    return 0;
}