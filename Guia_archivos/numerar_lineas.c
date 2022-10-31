
#include <stdio.h>
#include <stdlib.h>

#define MAX_STR 100

/* //esto imprime todas las líneas 
int main (int argc, char * argv[]){
    if (argc != 2){
        fprintf(stderr, "Uso del programa: %s [archivo_entrada] \n", argv[0]);
        return 1;       
    }
    FILE * entrada = fopen (argv[1], "rt");
    if (entrada == NULL) return 1;
    size_t linea = 1;
    char aux[MAX_STR];
    while ((fgets (aux, MAX_STR, entrada) != NULL)){
        fprintf(stdout, "%zd: %s", linea++, aux);
    }
    fclose(entrada);
    return 0;
}
*/

//esto imprime a partir de cierta línea pasada por CLA 
int main (int argc, char * argv[]){
    if (argc != 3){
        fprintf(stderr, "Uso del programa: %s [archivo_entrada] [imprimir desde esta línea] \n", argv[0]);
        return 1;       
    }
    int argv2 = atoi(argv[2]);
    FILE * entrada = fopen (argv[1], "rt");
    if (entrada == NULL) return 1;
    size_t linea = 1;
    char aux[MAX_STR];
    while ((fgets (aux, MAX_STR, entrada) != NULL)){
        if (linea >= argv2) fprintf(stdout, "%zd: %s\n", linea++, aux);
        else linea++;
    }
    fclose(entrada);
    return 0;
}
