
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define SIZE_TABLERO 8
#define SIZE_RANDOM 6

bool randomizar_booleanos();
void matriz_imprimir_booleanos (size_t filas, size_t columnas, bool m[filas][columnas]);


void inicializar_tablero(size_t dim, bool tablero[dim][dim]);
bool hay_mina(bool tablero[SIZE_TABLERO][SIZE_TABLERO], size_t x, size_t y);
int minas_linderas(bool tablero[SIZE_TABLERO][SIZE_TABLERO], size_t x, size_t y);

int main (void){
    srand(time (NULL));
    bool tablero1[SIZE_TABLERO][SIZE_TABLERO];
    inicializar_tablero (SIZE_TABLERO, tablero1);
    matriz_imprimir_booleanos (SIZE_TABLERO, SIZE_TABLERO, tablero1);
    if (hay_mina(tablero1, 4, 4))
        puts ("MINA");
    if (! hay_mina(tablero1, 4, 4))
        printf ("%d \n", minas_linderas(tablero1, 4, 4));

    if (hay_mina(tablero1, 0, 0))
        puts ("MINA");
    if (! hay_mina(tablero1, 0, 0))
        printf ("%d \n", minas_linderas(tablero1, 0, 0));
    return 0;
}


void inicializar_tablero(size_t dim, bool tablero[dim][dim]){
    int minas = 0;
    while (minas != 10){
        minas = 0;
        for (size_t i = 0; i < dim; i++){
            for (size_t j = 0; j < dim; j++){
                tablero[i][j] = randomizar_booleanos();
                if (tablero[i][j]) minas++;
            }
        } 
    }
}

bool hay_mina(bool tablero[SIZE_TABLERO][SIZE_TABLERO], size_t x, size_t y){
    return tablero[x][y];
}

/*
int minas_linderas(bool tablero[dim][dim], size_t x, size_t y){
    int minas = 0;
    for (size_t i = 0; i < dim; i++){
            for (size_t j = 0; j < dim; j++){
                if (i != 0 && j != 0 && i != x && j != y){
                    for (size_t k = i - 1; i <= i + 1; k++){
                        for (size_t l = j -1; l <= j + 1; l++)
                            minas += tablero[k][l];
                    }
                }
                
        } 
}

int minas_linderas(bool tablero[SIZE_TABLERO][SIZE_TABLERO], size_t x, size_t y){
    int minas = 0;
    printf ("%ld\t %ld \n ", x, y); //mgalcuadrado_debug
        for (long i = (long) x - 1; i <= (long) x +  1; i++){
            for (long j = (long) y - 1; j <= (long) y + 1; j++){
                printf ("%ld %ld\n", i, j); //mgalcuadrado_debug
                if ( i >= 0 && i <= SIZE_TABLERO && j >= 0 && j <= SIZE_TABLERO){
                     puts ("espacio lindero no nulo"); //mgalcuadrado_debug
                    minas += tablero[i][j];
                    printf ("minas linderas ahora: %d \n", minas); //mgalcuadrado_debug
                }
                else if ( i < 0 || i > SIZE_TABLERO || j < 0 || j > SIZE_TABLERO)   //mgalcuadrado_debug
                    printf ("espacio lindero nulo \n minas linderas ahora: %d \n", minas); //mgalcuadrado_debug
            }
        }  
        return minas;
    }      

*/

int minas_linderas(bool tablero[SIZE_TABLERO][SIZE_TABLERO], size_t x, size_t y){
    int minas = 0;
        for (long i = (long) x - 1; i <= (long) x +  1; i++){
            for (long j = (long) y - 1; j <= (long) y + 1; j++){
                if ( i >= 0 && i <= SIZE_TABLERO && j >= 0 && j <= SIZE_TABLERO){
                    minas += tablero[i][j];
                }
            }
        }  
        return minas;
    }      



/* void matriz_imprimir_booleanos (size_t filas, size_t columnas, bool m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        putchar ('\n');
        for (size_t j = 0; j < columnas; j ++){
            printf ("%d \t", m[i][j]);
        }
    }
    putchar ('\n');
}
*/

void matriz_imprimir_booleanos (size_t filas, size_t columnas, bool m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            printf ("[%zd][%zd] = %d \t", i, j, m[i][j]);
        }
        putchar ('\n');
    }
}



bool randomizar_booleanos (){
    return (rand () % SIZE_RANDOM == 0);
}
