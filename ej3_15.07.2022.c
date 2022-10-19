/*
 * Implementar una función
 * int *generar_ruido(int maximo, size_t *n);
 * que llame a la función int rand(void); sucesivas veces hasta que la misma devuelva un valor superior a maximo. Todos
 * los valores devueltos por random() deben ser almacenados en un vector y devueltos. En n devolver la cantidad de
 * valores almacenados.
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define INIT_SIZE 5
#define ADIT_SIZE 10

int * generar_ruido (int maximo, size_t * n){
    int * valores = malloc (INIT_SIZE * sizeof(int));
    if (valores == NULL)
        return NULL;
    size_t i, size = INIT_SIZE;
    bool pasa_maximo = false;
    for (i = 0; !pasa_maximo; i++){
        if (i == size){
            size += ADIT_SIZE;
            int * aux = realloc (valores, size * sizeof(int));
            if (aux == NULL){
                free (valores);
                return NULL;
            }
            valores = aux;
        }
        valores[i] = rand();
        if (valores[i] > maximo){
            pasa_maximo = true;
        }
    }
    *n = i;
    return valores;
}

int main (void){
    int max = 1964289383;
    size_t largo;
    int * p = generar_ruido(max, &largo);
    if (p == NULL)
        return 1;
    for (size_t i = 0; i < largo; i++)
        printf ("valor[%zd] = %d\n", i, p[i]);
    free(p);
    return 0; 
}