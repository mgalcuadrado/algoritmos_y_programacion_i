#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


/* 14. Implementá una función que retorne una matriz dinámica, 
    de un tamaño pasado como argumento,  siendo la misma inicializada con:
    a. ceros,
    b. unos,
    c. la identidad,
    d. números aleatorios.
*/

/*
<tipo> ** matriz = malloc (filas * sizeof(<tipo>));
if (*matriz == NULL)
    ...
for (size_t i = 0; i < filas; i++){
    matriz[i] = malloc (columnas * sizeof(<tipo>));
    if (matriz == NULL){
        for (; i >= 0; i++){
            free (matriz[i]);
        }
        free(matriz);
    }
}
//cantidad de mallocs pedidos = filas + 1


*/

void destruir_matriz (size_t filas, int ** m){
    for (size_t i = 0; i < filas; i++){
        free (m[i]);
    }
    free(m);
}
//holu

// m es una matriz dinámica de enteros
bool matriz_inicializada_ceros (size_t filas, size_t columnas, int *** m){
    int ** matriz = malloc (filas * sizeof(int *));
    if (matriz == NULL)
        return false;
    for (size_t i = 0; i < filas; i++){
        matriz[i] = malloc (columnas * sizeof(int));
        if (matriz[i] == NULL){
            destruir_matriz (i, matriz);
            return false;
        }
    }
    //cantidad de mallocs pedidos = filas + 1
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            matriz[i][j] = 0;
        }
    }
    *m = matriz;
    return true;
}

bool matriz_inicializada_unos (size_t filas, size_t columnas, int *** m){
    int ** matriz = malloc (filas * sizeof(int *));
    if (matriz == NULL)
        return false;
    for (size_t i = 0; i < filas; i++){
        matriz[i] = malloc (columnas * sizeof(int));
        if (matriz[i] == NULL){
            destruir_matriz (i, matriz);
            return false;
        }
    }
    //cantidad de mallocs pedidos = filas + 1
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            matriz[i][j] = 1;
        }
    }
    *m = matriz;
    return true;
}

bool matriz_inicializada_identidad (size_t filas, size_t columnas, int *** m){
    int ** matriz = malloc (filas * sizeof(int *));
    if (matriz == NULL)
        return false;
    for (size_t i = 0; i < filas; i++){
        matriz[i] = malloc (columnas * sizeof(int));
        if (matriz[i] == NULL){
            destruir_matriz (i, matriz);
            return false;
        }
    }
    //cantidad de mallocs pedidos = filas + 1
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            if (i == j) matriz[i][j] = 1;
            else matriz[i][j] = 0;
        }
    }
    *m = matriz;
    return true;
}

void matriz_imprimir_enteros (size_t filas, size_t columnas, int ** m){
    for (size_t i = 0; i < filas; i++){
        printf ("\n");
        for (size_t j = 0; j < columnas; j ++){
            printf ("%d \t", m[i][j]);
        }
    }
    putchar('\n');
}



int main (void){
    /*int mat[2][3] ={
        {1, 1, 1},
        {2, 2, 2},
    }; */
    int ** m;
    printf ("%s\n", matriz_inicializada_identidad (5, 7, &m) ? "funcionó" : "no había memoria");
    if (m == NULL)
        return 1;
    matriz_imprimir_enteros (5, 7, m);
    destruir_matriz (5, m);
    return 0;
}