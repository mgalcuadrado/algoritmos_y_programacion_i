/*
1. a. Escribir una función
bool tiene_extension(const char archivo[], const char extension[]);
que dada una cadena que representa el nombre de un archivo y otra cadena que representa
su extension devuelva si el archivo tiene esa extension o no.
Ejemplo:
tiene_extension("listado.txt", ".txt") --> true
tiene_extension("paquete.zip", ".rar") --> false
Aclaración: No está permitido el uso de funciones de la biblioteca. Todas las necesarias
deben ser implementadas.
b. Dar un mínimo ejemplo de invocación de la función.


#include <stdio.h>
#include <stdbool.h>

#define MAX_FILE 100
#define MAX_EXT 15

#define MENSAJE_MISMA_EXTENSION "tienen la misma extensión"

bool tiene_extension (const char archivo[], const char extension[]){
    size_t i, j;
    for (i = 0; archivo[i] != '\0'; i++);
    for (j = 0; extension[j] != '\0'; j++);

    if (j > i)
        return false;
    
    for (i = i - 1, j = j - 1; archivo[i] != '.'; i--, j--){
        if (archivo[i] != extension[j])
            return false;
    }
    return true;
}

int main (void){
    char archivo[MAX_FILE] = "archivo.txt";
    char extension[MAX_EXT] = ".rar";
    printf ("%s%s \n", tiene_extension(archivo, extension) ? " " : "No ", MENSAJE_MISMA_EXTENSION);
    return 0;
    
}

2. Una matriz es no-negativa si todos sus elementos son mayores o iguales a cero.
a. Escribir una función es_nonegativa que reciba una matriz de flotantes de tamaño N×M y
que retorne si es no-negativa o no.
b. Teniendo #define N 3 y #define M 2 escribir un pequeño ejemplo de invocación que
declare y defina una matriz, llame a la función del ítem anterior e imprima un mensaje para
el usuario según el resultado.




#include <stdio.h>
#include <stdbool.h>

#define N 3
#define M 2

bool es_nonegativa (size_t n, size_t m, float matriz[n][m]){
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < m; j++){
            if (matriz[i][j] < 0)
                return false;
        }
    }
    return true;
}

int main (void){
    float matriz[N][M] = {
        {1, 2},
        {0, 4},
        {2, 3},
    };
    printf("La matriz%ses no negativa \n", es_nonegativa(N, M, matriz) ? " " : " no ");
    return 0;
}

3. 
Escribir un programa que le pida al usuario un grado sexagesimal expresado como sus grados, sus
minutos y sus segundos (pueden pedirse por separado) y que imprima su representación decimal.
Por ejemplo, si el usuario ingresa el grado 20º15’45" como:
20
15
45
deberá imprimirse 20.2625.
Realizar todas las validaciones pertinentes.
(Al igual que en las horas, 60 minutos representan un grado y 60 segundos representan un minuto.
Se pide expresar el grado con su fracción correspondiente.)

*/

#include <stdio.h>
#include <stdlib.h>

#define MENSAJE_INICIAL "se le pedirán por separado los grados, minutos y segundos para calcular la representación decimal del grado sexagesimal ingresado."
#define MENSAJE_INGRESO_INVALIDO "Solo se aceptan números positivos"
#define MENSAJE_GRADOS "Ingrese los grados"
#define MENSAJE_MINUTOS "Ingrese los minutos"
#define MENSAJE_SEGUNDOS "Ingrese los segundos"
#define MENSAJE_DECIMAL "El grado sexagesimal ingresado corresponde en decimales a:"

#define MAX_STR 100

int main (void){
    char auxiliar[MAX_STR];
    printf ("%s\n %s\n", MENSAJE_INICIAL, MENSAJE_GRADOS);
    fgets (auxiliar, MAX_STR, stdin);
    int grados = atoi(auxiliar);
    puts (MENSAJE_MINUTOS);
    fgets (auxiliar, MAX_STR, stdin);
    int minutos = atoi(auxiliar);
    puts (MENSAJE_SEGUNDOS);
    fgets (auxiliar, MAX_STR, stdin);
    int segundos = atoi(auxiliar);
    if (segundos < 0 || minutos < 0 || grados < 0 || segundos > 60 || minutos > 60 || grados > 360){
        puts (MENSAJE_INGRESO_INVALIDO);
        return 1;
    }
    printf ("%s %.4f\n", MENSAJE_DECIMAL, grados + ((float) minutos / 60) + ((float) segundos / 3600));
    return 0;

}



