#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100




bool cadena_copiar_hasta (const char * string, char separador, char ** copia){
    size_t i;
    for (i = 0; string[i] != separador && string[i] != '\0'; i++);
    * copia = malloc ((i + 1) * sizeof(char));
    if (copia == NULL)
        return false;
    if (string[i] == '\0'){
        strcpy (*copia, string);
        return true;
    }
    size_t j;
    char aux[MAX];
    for (j = 0; j < i; j++){
        aux[j] = string[j];
    }
    aux[j] = '\0';
    strcpy (*copia, aux);
    return true;
}

int main (void){
    char cadena[MAX] = " hola qué tal, todo bien?";
    char * q;
    printf ("%s\n", cadena_copiar_hasta (cadena, ',', &q) ? "true" : "false");
    if (q == NULL)
        return 1;
    puts (q);
    free (q);
    return 0;
}