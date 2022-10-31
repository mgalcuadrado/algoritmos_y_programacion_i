#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>




/* 12. Implementá una función que reciba dos vectores de números y retorne 
 * un nuevo vector con los números de ambos vectores concatenados.
 */

bool arreglo_concatenar (int * v, size_t lv, int * w, size_t lw, int ** concat){
    int * c = malloc ((lv + lw) * sizeof(int));
    if (c == NULL)
        return false;
    for (size_t i = 0; i < lv; i++){
        c[i] = v[i];
    }
    for (size_t i = lv; i < (lv + lw); i++){
        c[i] = w[i - lv];
    }
    *concat = c;
    return true;
}

/* 13. Implementá una función similar a la del ejercicio anterior, 
 * pero en lugar de retornar un nuevo vector, modifica el primero 
 * pegándole el segundo
*/

bool arreglo_concatenar_ (size_t lv, int * v[lv], size_t lw, int * w){
    int * aux = malloc ((lv + lw) * sizeof(int));
    if (aux == NULL)
        return false;
    for (size_t i = 0; i < lv; i++){
        aux[i] = *v[i];
    }
    for (size_t i = lv; i < (lv + lw); i++){
        aux[i] = w[i - lv];
    }
    *v = aux;
    return true;
}

void arreglo_imprimir (const int arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        printf ("%d \t", arreglo[i]);
    }
    printf ("\n");
}

int main (void){
    int arr[4] = {1, 2, 3, 4};
    int vect[7] = {1, 2, 3, 4, 5, 6, 7};
    printf ("%s \n", arreglo_concatenar_ (4, &arr, 7, vect) ? "true" : "false");
    if (arr == NULL)
        return 1;
    arreglo_imprimir (arr, 11);
    free (arr);
    return 0;
}