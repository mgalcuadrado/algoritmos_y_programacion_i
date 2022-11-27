/*
3. Escribir una función que dada una cadena de caracteres y un 
carácter devuelva la cantidad de
apariciones de ese carácter en la cadena 
utilizando recursividad
*/

#include <stdio.h>
size_t caracter_apariciones(const char * s, char c){
    if (*s == '\0') return 0;
    if (s[0] == c) return 1 + caracter_apariciones(s + 1, c);
    return caracter_apariciones(s + 1, c);
}

int main (void){
    const char string[30] = "ornitorrinco";
    fprintf(stdout, "la letra o aparece en %s %zd veces\n", string, caracter_apariciones(string, 'o'));
    return 0;
}