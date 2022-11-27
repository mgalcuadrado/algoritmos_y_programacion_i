/*
3. Implementar una función recursiva que responda al siguiente prototipo
bool es_palindromo(const char *s);
que reciba una cadena de caracteres s y que indique si la misma es palíndroma o no. Una cadena es palíndroma si se lee
igual desde ambos lados, como por ejemplo "neuquen"
*/
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CADENA 20

bool _es_palindromo(const char * s, size_t l){
    if (l == 1 || l == 0){
        return true;
    }
    if (s[0] != s[l - 1]) return false;
    return _es_palindromo(s + 1, l - 2);
}


bool es_palindromo(const char *s){
    return _es_palindromo(s, strlen(s));
}

int main (void){
    const char s1[MAX_CADENA] = "neuquen";
    const char s2[MAX_CADENA] = "patagonia";
    fprintf(stdout, "la cadena %s%s es palíndroma\n", s1, es_palindromo(s1) ? " " : " no");
    fprintf(stdout, "la cadena %s%s es palíndroma\n", s2, es_palindromo(s2) ? " " : " no");
    return 0;

}