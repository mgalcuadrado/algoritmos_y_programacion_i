/*
1. Escribir una función
bool extraer_par(int par[2], const char s[]);
que dada una cadena de caracteres s que consiste en dos valores enteros separados por una coma
(',') almacene dichos valores en el vector par. La función debe retornar true si encontró dos
valores en la cadena y false en caso contrario.
Un ejemplo de una cadena válida puede ser "25,-8\n" y su traducción será {25, -8}.
Aclaración: Sólo está permitido utilizar la función atoi() de <stdlib.h>, cualquier otra función
que se necesite se debe implementar.
A fines de simplicidad una cadena como "25hola,8mundo\n" puede interpretarse como {25, 8}.

Acá está la resolución original, y después propongo una más linda usando punteros

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define SEPARADOR ','
#define MAX_STR 100

bool extraer_par (int par[2], const char s[]){
    size_t separador = 0;
    for (size_t i = 0; s[i] != '\0'; i++){
        if (s[i] == SEPARADOR){
            separador++;
            if (s[i + 1] == '\0' && separador == 1)
                return false;
        }
    }
    if (separador != 1)
        return false; 
    size_t copiar_desde = 0, j;
    for (size_t i = 0; i < 2; i++){
        char aux[MAX_STR];
        for (j = copiar_desde; s[j] != SEPARADOR && s[j] != '\0' && s[j] != '\n'; j++){
            aux[j - copiar_desde] = s[j];
        }
        aux[j - copiar_desde] = '\0';
        par[i] = atoi(aux);
        copiar_desde = j + 1; 
    }
    return true; 
}


acá dejo una función que extraería cada parte individual y devolvería cada sector por el nombre y la posición desde la que empezaría a leer en el siguiente llamado por interfaz
size_t _extraer_parte (size_t *posicion, char auxiliar[]){
    size_t i;
    char extra[MAX];
    for (i = 0; auxiliar[*posicion] != SEPARADOR && auxiliar[*posicion] != '\n'; i++, *posicion = *posicion + 1)
        extra[i] = auxiliar[*posicion];
    extra[i] = '\0';
    *posicion = *posicion + 1;
    return atoi(extra);
}



size_t leer_pares (int pares[][2], size_t max){
    size_t pares_leidos = 0;
    for(size_t i = 0; i < max; i++){
        char lecturas[MAX_STR];
        puts("Ingrese pares de enteros separados por coma");
        if (fgets(lecturas, MAX_STR, stdin) == NULL)
            return pares_leidos;
        if (! extraer_par(pares[i], lecturas))
            return pares_leidos; 
        else pares_leidos++;
    }
    return pares_leidos;
}

void matriz_inicializada_ceros (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] = 0;
        }
    }
}

int main (void){
    int matriz[5][2];
    matriz_inicializada_ceros (5, 2, matriz);
    leer_pares(matriz, 5);
    for (size_t i = 0; i < 5; i++){
        for (size_t j = 0; j < 2; j++)
            printf("%d ", matriz[i][j]);
    }
    return 0;
}

3. Escribir una función es_impar que dada una matriz de vectores de 2 pares (como la del ejercicio
anterior) y su longitud devuelva si todos los elementos son impares o no.

*/

#include <stdio.h>
#include <stdbool.h>

bool es_impar (size_t filas, int m[][2]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < 2; j++){
            if (!(m[i][j] % 2))
                return false;
        }
    }
    return true;
}

void matriz_inicializada_unos (size_t filas, size_t columnas, int m[filas][columnas]){
    for (size_t i = 0; i < filas; i++){
        for (size_t j = 0; j < columnas; j ++){
            m[i][j] = 1;
        }
    }
}
int main (void){
    int matriz[5][2];
    matriz_inicializada_unos (5, 2, matriz);
    printf ("La matriz%ses impar\n", es_impar(5, matriz) ? " " : " no ");
    return 0;
}
