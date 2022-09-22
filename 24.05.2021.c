
/* 1. a. Escribir una función
int mi_atoi(const char s[]);
que dada una cadena de caracteres s devuelva el número entero contenido en ella. No deben
realizarse validaciones.
Por ejemplo, si se llamara a la función con "75029511" como s la función devolvería el
entero 75029511.
Aclaración: No está permitido el uso de funciones de la biblioteca. Todas las necesarias
deben ser implementadas.
b. Dar un mínimo ejemplo de invocación de la función.
2. Una matriz tiene paridad si los elementos de las posiciones pares son pares y los de las posiciones
impares son impares, donde la posición es la suma de la fila y la columna.
Por ejemplo la matriz
A =

4 9 6 7
5 8 1 8
0 2 3 1

no tiene paridad porque en la posición (2, 1) que es impar está el 2 que es par y en la posición
(2, 2) que es par está el 3 que es impar.
a. Escribir una función tiene_paridad que reciba una matriz de enteros en Z
N×M y que
devuelva si la matriz recibida tiene paridad.
b. Dar un mínimo ejemplo de invocación de la función.
3. El pH de una solución se calcula en función de la concentración de iones hidronio (H3O+) según
la fórmula:
pH = log 1
[H3O+]
Escribir un programa que le pida al usuario una concentración de hidronio y que imprima el pH
correspondiente a dicha concentración.
Realizar todas las validaciones pertinentes.
Ayuda: Para calcular un logaritmo decimal puede usarse la función double log10(double) de
la biblioteca <math.h>.


*/ 
//EJ1
#include <stdio.h>

#define MAX 20

int mi_atoi (const char string[]){
    size_t i = 0;
    int multiplicador;
    if (string[0] == '-'){
        multiplicador = -1;
        i++;
    }
    else multiplicador = 1;

    int valor = 0; //IMPORTANTE INICIALIZAR EL RESULTADO
    for (; string[i] != '\0'; i++){
        valor = (valor * 10) + (string[i] - '0');
    }
    return valor * multiplicador;
}

int main (void){
    char cadena[MAX] = "123456";
    fprintf (stdout, "%d \n", mi_atoi(cadena));
    return 0;
}

/*

//EJ 2 TIENE PARIDAD

#include <stdio.h>
#include <stdbool.h>

bool tiene_paridad (size_t n, int m[n][n]){
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            if ((m[i][j] % 2) != ((i + j) % 2))
                return false;
        }
    }
    return true;
}

int main (void){
    int matriz[3][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
    };
    printf(" la matriz%stiene paridad \n", tiene_paridad(3, matriz) ? " " : " no ");
    return 0;
}

*/

//EJ 3 CONCENTRACION IONES HIDRONIO

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MENSAJE_INGRESAR_TECLADO "Ingrese la concentración de iones de hidronio:"
#define MENSAJE_NUMERO_NEGATIVO "Se debe ingresar un número entre cero y uno. "
#define MENSAJE_IMPRESION_PH "El pH es de: "
#define MAX 15

int main (void){
    char auxiliar[MAX];
    fgets (auxiliar, MAX, stdin);
    float h3o = atof(auxiliar);
    if (h3o <= 0 || h3o > 1){
        puts (MENSAJE_NUMERO_INVALIDO);
        return 1;
    }
    else{
    printf ("%s %.f \n", MENSAJE_IMPRESION_PH, log (1 / h3o));
    return 0;
    }
}


