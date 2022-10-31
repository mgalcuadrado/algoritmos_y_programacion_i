/* EJ 8 GUÍA: Escribir una función que convierta un número que representa 
 una cantidad de segundos,a su equivalente en horas, minutos y segundos, 
 retornando las partes por la interfaz, bool por  el nombre, indicando el 
 resultado de la operación: true de ser posible, false si no. 
 Realizar las validaciones pertinentes.
 */

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100

bool se_convirtio_a_segundos (long int segundos_dados, int * segundos, int * minutos, int * horas);


int main (void){
    char aux[MAX];
    puts ("Ingrese una cantidad de segundos por teclado:");
    fgets (aux, MAX, stdin);
    int n = atoi(aux);
    int s, m, h;
    if (! se_convirtio_a_segundos (n, &s, &m, &h)){
        puts ("Solo se aceptan números positivos");
        return 1;
    }
    printf ("El número ingresado corresponde a %d HORA(S), %d MINUTO(S), %d SEGUNDO(S). \n", h, m, s);
    return 0;
}


bool se_convirtio_a_segundos (long int segundos_dados, int * segundos, int * minutos, int * horas){
    if (segundos_dados < 0)
        return false;
    *horas = segundos_dados / 3600;
    *minutos = (segundos_dados % 3600) / 60;
    *segundos = ((segundos_dados % 3600) % 60);
    return true;
}