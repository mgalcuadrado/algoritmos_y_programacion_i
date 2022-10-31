
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char * argv[]){
    if (argc == 1){
        fprintf(stderr, "Uso: %s \"cadena centinela entre comillas\"\n", argv[0]);
        return 1;
    }
    char * centinela = malloc (sizeof(char) * strlen(argv[1] + 2)); //barra n y barra cero
    if (centinela == NULL) return 1;
    size_t pos;
    for (pos = 0; argv[1][pos] != '\0'; pos++){
       centinela[pos] = argv[1][pos]; 
    }
    centinela[pos++] = '\n';
    centinela[pos] = '\0';
    char aux[100];
    FILE * f = fopen("salida.txt", "wt");
    if (f == NULL) return 1;
    while (fgets (aux, sizeof(aux), stdin) != NULL){
        if (! strcmp(aux, centinela)) break;
        fputs (aux, f);
    }
    if (fclose(f)) return 1;
    return 0;
}