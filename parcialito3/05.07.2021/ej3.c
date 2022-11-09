/*
Escribir un programa que se ejecute como:
$ ./cut [archivo] [c0] <[c1] <[c2] ...>>
que dado un archivo de texto en formato CSV muestre por stdout sólo las columnas cn indicadas.
Por ejemplo si se tiene el archivo.csv:
Tomates,2.00,200
Pollo,2.5,600
Papa,5.0,210
y se invoca
$ ./cut archivo.csv 1 2
la salida deberá ser:
2.00,200
2.5,600
5.0,210
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_FILAS 3
#define MAX_COLUMNAS 10
#define MAX_STRING 30
#define MAX_AUX 200


bool leer_linea_csv(FILE *f, char columnas[][MAX_STRING], size_t *n){
    *n = 0;
    int c;
    size_t i = 0;
    while ((c = fgetc(f)) != EOF){
        if (c == '\n'){
            columnas[*n][i] = '\0';
            (*n) ++;
            return true;
        }
        else if (c == ','){
            columnas[*n][i] = '\0';
            (*n) ++;
            i = 0;
        }
        else columnas[*n][i] = c;
    }
    return false;
}


int main (int argc, char * argv[]){
    if (argc < 3){
        fprintf(stderr, "Uso del programa: %s [archivo] [c0] < [c1] < [c2] ...\n", argv[0]);
        return 1;
    }
    FILE * f = fopen(argv[1], "rt");
    if (f == NULL){
        fprintf(stderr, "El archivo no se pudo abrir\n");
        return 1;
    }
    char columnas[MAX_COLUMNAS][MAX_STRING]; 
    //en realidad columnas debería pedirse con memoria dinámica pero no es el objetivo del ejercicio
    size_t ncols;
    while (leer_linea_csv(f, columnas, &ncols)){
        //size_t col = 0;
        for (size_t a = 2; a < argc; a++){
            size_t n = atoi(argv[a]);
            /*if (n >= ncols){
                fprintf(stderr, "La columna %s no se encuentra en la matriz del archivo\n", argv[a]);
                return 1;
            }
            if (col > n){
            fprintf(stderr, "Uso del programa: %s [archivo] [c0] < [c1] < [c2] ...\n", argv[0]);
            return 1;   
            }
            while (col != n) col++;
            */
            fprintf(stdout, "%s", columnas[n]);
            (a != (argc - 1)) ? fputc(',', stdout) : fputc('\n', stdout);
        }
    }
    if (fclose(f)){
        fprintf(stderr, "el archivo no se pudo cerrar correctamente\n");
        return 1;
    }
    return 0;
}