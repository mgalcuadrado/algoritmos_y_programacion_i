/* Se tiene representada una matriz como un arreglo dinámico de arreglos dinámicos de flotantes con una
 * determinada cantidad de filas y columnas.
 * a. Implementar la función
 * float **matriz_crear(size_t filas, size_t columnas);
 * que dadas las dimensiones cree una matriz de ese tamaño. No hace falta inicializar los elementos de la
 * matriz.
 * b. Implementar la función
 * void matriz_destruir(float **matriz, size_t filas, size_t columnas);
 * que libere la memoria asociada a una matriz.
 */

#include <stdio.h>
#include <stdlib.h>

    

float **matriz_crear(size_t filas, size_t columnas){
    float ** m = malloc (filas * sizeof (float*));
    if (m == NULL)
        return NULL;
    for (size_t i = 0; i < filas; i++){
        m[i] = malloc (columnas * sizeof(float));
        if (m[i] == NULL){
            matriz_destruir (m, i, columnas);
            return NULL;
        }
    }
    return m;
}

void matriz_destruir(float **matriz, size_t filas, size_t columnas){
   for (size_t i = 0; i < filas; i++)
        free(m[i]);
    free(m);
}


