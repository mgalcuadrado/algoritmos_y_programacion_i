#include <stdio.h>
#include <stdbool.h>

#define MAX 100


char * invertir(char * string){
    size_t i, j;
    char aux;
    for (i = 0; string[i] != '\0'; i++);
    size_t longitud = i;
    for (j = 0, i = i - 1; j < i; i--, j++){
        aux = string[j];
        string[j] = string[i];
        string[i] = aux;
    }
    string[longitud] = '\0';
    return string;
}


bool es_palindroma(const char * string){
    size_t i, j;
    for (i = 0; string[i] != '\0'; i++);
    for (j = 0, i = i - 1; j < i; i--, j++){
        if (string[i] != string[j])
            return false;
    }
    return true;
}



char * strupper(char * string){
    for (size_t i = 0; string[i] != '\0'; i++){
        if islower(string[i]){
            string[i] = toupper(string[i]);
        }
    }
    return string;
}


char * strlower(char * string){
    for (size_t i = 0; string[i] != '\0'; i++){
        if isupper(string[i]){
            string[i] = tolower(string[i]);
        }
    }
    return string;
}

char * strinvertcase(char * string){
    for (size_t i = 0; string[i] != '\0'; i++){
        if isupper(string[i])
            string[i] = tolower(string[i]);
        if islower(string[i])
            string[i] = toupper(string[i]);
    }
    return string;
}

char * justify(char * string, size_t n){
    for (size_t i = 0; string[i] != '\0'; i++){
        if (i % n == 0)
            putchar ('\n');
    }
    return string;
}

int main (void){
    char cadena[MAX] = "algoritmos";
    printf ("La cadena%ses palíndroma\n", es_palindroma(cadena) ? " " : " no ");
    return 0;
}
