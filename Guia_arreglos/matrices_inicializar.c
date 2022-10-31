

#include <stdio.h>
#include <stdlib.h>

void matriz_inicializada_ceros (size_t filas, size_t columnas, int m[filas][columnas]);
void matriz_imprimir_enteros (size_t filas, size_t columnas, int m[filas][columnas]);
void matriz_inicializada_unos (size_t filas, size_t columnas, int m[filas][columnas]);
void matriz_inicializada_multiplos (size_t filas, size_t columnas, int m[filas][columnas]);
void matriz_inicializada_usuario (size_t filas, size_t columnas, int m[filas][columnas]);
void matriz_inicializada_fibonacci (size_t filas, size_t columnas, int m[filas][columnas]);
void matriz_inicializada_random (size_t filas, size_t columnas, int m[filas][columnas]);


int main (void){
    int m1[2][2];
    matriz_inicializada_ceros (2, 2, m1);
    matriz_imprimir_enteros (2, 2, m1);
    matriz_inicializada_unos (2, 2, m1);
    matriz_imprimir_enteros (2, 2, m1);
    matriz_inicializada_multiplos (2, 2, m1);
    matriz_imprimir_enteros (2, 2, m1);
    matriz_inicializada_random (2, 2, m1);
    matriz_imprimir_enteros (2, 2, m1);
    matriz_inicializada_usuario (2, 2, m1);
    matriz_imprimir_enteros (2, 2, m1);

    int m2[5][7];
    matriz_inicializada_fibonacci (5, 7, m2);
    matriz_imprimir_enteros (5, 7, m2);

    return 0;
}










void matriz_imprimir_enteros (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        printf ("\n");
        for (size_t j = 0; j < columnas; j ++){
            printf ("%d \t", m[i][j]);
        }
    }
}

void matriz_inicializada_ceros (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] = 0;
        }
    }
}

void matriz_inicializada_unos (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] = 1;
        }
    }
}

void matriz_inicializada_multiplos (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] = i * j;
        }
    }
}

void matriz_inicializada_usuario (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] = getchar();
        }
    }
}

void matriz_inicializada_random (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] = rand();
        }
    }
}

void matriz_inicializada_fibonacci (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            if (m[i][j] == (m[0][0] || m[0][1]))
                m[i][j] = 1;
            if (j - 2 == -2)
                m[i][j] = m[i - 1][columnas - 2] + m[i - 1][columnas -1];
            if (j - 2 == -1)
                m[i][j] = m[i - 1][columnas - 1] + m[i][0];
            else m[i][j]= m[i][j - 1] + m[i][j - 2];
        }
    }
}
