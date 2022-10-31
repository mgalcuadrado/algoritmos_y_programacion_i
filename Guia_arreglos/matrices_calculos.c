#include <stdio.h>

#define MENSAJE_TRANSPUESTA "\n Transpuesta \n"
#define MENSAJE_TRAZA "\n Traza \n"
#define MENSAJE_POSITIVIDAD "\n Positividad \n"


long matriz_traza(size_t filas, size_t columnas, int a[filas][columnas]);
void matriz_sumar_a_componentes (size_t filas, size_t columnas, int m[filas][columnas], int k);
void matriz_multiplicar_a_componentes (size_t filas, size_t columnas, int m[filas][columnas], int k);
void matriz_transpuesta (size_t filas, size_t columnas, int m[filas][columnas]);
void matriz_imprimir_enteros (size_t filas, size_t columnas, int m[filas][columnas]);
void matriz_positividad (size_t filas, size_t columnas, int m[filas][columnas]);
int matriz_determinante_dim_2 (int m[2][2]);
int matriz_determinante_dim_3 (int m[3][3]);
void matriz_inicializar_con_ceros (size_t filas, size_t columnas, int m[filas][columnas]);
void matrices_multiplicar (size_t n, size_t k, int a[n][k], size_t m, int b[k][m], int c[n][m]);
int matriz_maximo (size_t filas, size_t columnas, int m[filas][columnas]);


int main (void){
    int matriz1[4][3] = {
        {1, 1, 1},
        {2, 2, 2},
        {3, 15, 3},
        {4, 4, 4},
    };
    int matriz2[3][2] = {
        {2, 1},
        {4, 0},
        {3, 2},
    };
    
    printf ("ESPERO 15, DA: %d \n", matriz_maximo (4, 3, matriz1));
    printf ("ESPERO 4, DA: %d \n", matriz_maximo (3, 2, matriz2));
    return 0;
}



long matriz_traza(size_t filas, size_t columnas, int a[filas][columnas]){
    long traza = 0;
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
        if (i == j)
            traza += a[i][j];
        }
    }
    return traza;
}

void matriz_sumar_a_componentes (size_t filas, size_t columnas, int m[filas][columnas], int k){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] += k;
        }
    }
}

void matriz_multiplicar_a_componentes (size_t filas, size_t columnas, int m[filas][columnas], int k){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] *= k;
        }
    }
}


void matriz_transpuesta (size_t filas, size_t columnas, int m[filas][columnas]){
    int aux;
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            if (i < j){
                aux = m[i][j];
                m[i][j] = m[j][i];
                m[j][i] = aux;
            }
        }
    }
}

// 2 si positiva, 1 si no neg, 0 si nada, -1 si no pos, -2 si neg
void matriz_positividad (size_t filas, size_t columnas, int m[filas][columnas]){
    int ceros = 0;
    int positivos = 0;
    int negativos = 0;
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j++){
            if (m[i][j] < 0)
                negativos++;
            if (m[i][j] == 0)
                ceros++;
            if (m[i][j] > 0)
                positivos++;
        }
    }
    if (positivos && negativos) printf ("NADA");
    if (positivos && ceros) printf ("NO NEGATIVA");
    if (negativos && ceros) printf ("NO_POSITIVA");
    if (positivos) printf ("POSITIVA");
    if (negativos) printf ("NEGATIVA");
}

void matriz_imprimir_enteros (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        putchar ('\n');
        for (size_t j = 0; j < columnas; j ++){
            printf ("%d \t", m[i][j]);
        }
    }
    putchar ('\n');
}   

int matriz_determinante_dim_2 (int m[2][2]){
    return (m[0][0] * m[1][1]) - (m[1][0] * m[0][1]);
}

int matriz_determinante_dim_3 (int m[3][3]){
    return m[0][0] * ((m[1][1] * m[2][2]) - (m[1][2] * m[2][1])) - m[1][1] * ((m[0][0] * m[2][2]) - (m[0][2] * m[2][0])) + m[2][2] * ((m[1][1] * m[0][0]) - (m[1][0] * m[0][1]));
}



void matrices_multiplicar (size_t n, size_t k, int a[n][k], size_t m, int b[k][m], int c[n][m]){
    matriz_inicializar_con_ceros (n, m, c);
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            for (size_t p = 0; p < k; p++){
                c[i][j] += (a[i][p] * b[p][j]);
            }
        }
    }
}

void matriz_inicializar_con_ceros (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++)
            m[i][j] = 0;
    }
}

int matriz_maximo (size_t filas, size_t columnas, int m[filas][columnas]){
    int maximo = m[0][0];
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j++){
            if (m[i][j] > maximo)
                maximo = m[i][j];
        }
    }
    return maximo;
}