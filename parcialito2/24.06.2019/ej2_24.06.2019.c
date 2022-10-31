/*
 * a. Implementar una función char **leer_lineas(size_t *n); que lea líneas de stdin hasta que se
 * termine la entrada estándar y que devuelva un arreglo de cadenas que contenga cada una de esas líneas.
 * Debe devolverse la cantidad de líneas leídas a través de n.
 * b. Implementar la función void liberar_lineas(char **lineas, size_t n); que reciba un arreglo
 * dinámico de cadenas lineas de longitud n y libere la memoria asociada.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_STR 100
#define INIT_SIZE 20
#define MULT 2

void liberar_lineas (char ** lineas, size_t n){
    for (size_t i = 0; i < n; i++)
        free (lineas[i]);
    free (lineas);
}

char ** leer_lineas(size_t *n){
    char lectura[MAX_STR]; 
    size_t size = INIT_SIZE;
    *n = 0;
    char ** p = malloc (size * sizeof(char*));

    if (p == NULL) return NULL;
    while (fgets (lectura, MAX_STR, stdin) != NULL){
        if (*n == size){
            size *= MULT;
            char ** aux = realloc (p, size * sizeof(char*));
            if (aux == NULL){
                liberar_lineas (p, *n);
                return NULL;
            }
            //for (size_t i = 0; i < *n; i++)
               // aux[i] = p[i];
            p = aux;
        }
        p[*n] = malloc ((strlen(lectura) + 1) * sizeof(char));
        if (p[*n] == NULL){
            liberar_lineas (p, *n);
            return NULL;
        }
        strcpy (p[*n], lectura); 
        *n = *n + 1;
    }
    return p;
}


int main (void){
    size_t n;
    char ** cadenas = leer_lineas(&n);
    if (cadenas == NULL) return 1;
    for (size_t i = 0; i < n; i++)
        puts (cadenas[i]);
    liberar_lineas (cadenas, n);
    return 0; 
}