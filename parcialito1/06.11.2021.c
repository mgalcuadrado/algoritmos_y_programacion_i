
/* 1. a. Escribir una función
void eliminar_caracter(char s[], char c);
que dada una cadena de caracteres s y un carácter c modifique la cadena eliminando todas
las ocurrencias del carácter c.
Por ejemplo, si se llamara a la función con "algoritmos y programacion" como cadena y
con 'o' como carácter la cadena debe ser modificada a "algritms y prgramacin".
Aclaración: No está permitido el uso de funciones de la biblioteca. Todas las necesarias
deben ser implementadas.
b. Dar un mínimo ejemplo de invocación de la función.
2. a. Escribir una función que reciba una matriz M en R
N×N y que devuelva si la matriz recibida
es la matriz identidad.
b. Dar un mínimo ejemplo de invocación de la función.
3. Los parcialitos de Algoritmos y Programación se puntuan del 0 al 10 y se aprueban con más de 4.
Escribir un programa que deje que el docente ingrese la nota de un parcialito y que le diga si el
alumno aprobó o reprobó.
Realizar todas las validaciones pertinentes.
*/

/* EJ 1
#include <stdio.h>

#define MAX 100

void eliminar_caracter(char s[], char c){
    size_t i, j;
    for (i = 0, j = 0; s[i] != '\0'; i++){
        if (s[i] != c){
            s[j] = s[i];
            j++;
        }
    }
    s[j] = '\0';
}

int main (void){
   char string[MAX] = "algoritmos y programacion";
   eliminar_caracter(string, 'o');
   for (size_t i = 0; string[i] != '\0'; i++){ //mi implementación de puts(char str[]);
    printf("%c", string[i]);
   }
   putchar ('\n');
   return 0; 
}



//EJ 2 ES MATRIZ IDENTIDAD

#include <stdio.h>
#include <stdbool.h> 


bool es_matriz_identidad (size_t n, int m[n][n]){
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++){
            if (i != j && m[i][j] != 0)
                return false;
            if (i == j && m[i][j] != 1)
                return false;
        }
    }
    return true;
}

int main (void){
    int matriz[3][3] ={
        {1, 0, 0},
        {0, 1, 0},
        {0, 1, 1},
    };
    if (es_matriz_identidad (3, matriz))
        puts("Es la matriz identidad");
    else puts ("No es la matriz identidad");
    return 0;
}

*/

// EJ3 Nota parcialitos

#include <stdio.h>
#include <stdlib.h>

#define NOTA_APROBACION 4
#define MAX 15
#define MENSAJE_INGRESO_NOTAS "Ingrese la nota del alumno a continuación: "
#define MENSAJE_NOTA_INVALIDA "La nota ingresada es inválida"
#define NOTA_MINIMA 0
#define NOTA_MAXIMA 10

int main (void){
    char string[MAX];
    puts (MENSAJE_INGRESO_NOTAS);
    fgets (string, MAX, stdin);
    int nota = atoi(string);
    if (nota < NOTA_MINIMA || nota > NOTA_MAXIMA){
        puts(MENSAJE_NOTA_INVALIDA);
        return 1;
    }
    printf ("EL ALUMNO %s\n", (nota >= NOTA_APROBACION) ? "APROBÓ" : "REPROBÓ");
    return 0;
}

