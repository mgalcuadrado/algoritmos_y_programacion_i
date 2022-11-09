/*
2. a. Implementar la función
bool leer_linea_csv(FILE *f, char columnas[][MAX_STRING], size_t *n)
que dado un archivo de texto f en formato CSV lea de él una línea y guarde cada una de las columnas
de la misma. Se debe devolver a través de n la cantidad de columnas leídas y por el nombre true en
caso de haber sido correcta la lectura. Asumir que tanto la cantidad de columnas como MAX_STRING
son suficientes para realizar la operación.
b. Proponer un formato binario que sea “cómodo” para volcar una fila de un archivo CSV.
Implementar la función
bool escribir_fila(const char *ruta, const char *columnas[], size_t n);
que dado el nombre del archivo binario ruta agregue en él las n columnas conforme al formato
propuesto. La función debe devolver true en caso de poder realizar la operación.
Ayuda: Para agregar algo al final de un archivo puede ser abierto en modo “a”, append.
Nota: Cuando se diseñe el formato pensarlo para que sea no sólo fácil de escribir sino facil de leer
después.
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_AUX 200
#define MAX_STRING 30

bool leer_linea_csv(FILE *f, char columnas[][MAX_STRING], size_t *n){
    char aux[MAX_AUX], extra[MAX_STRING];
    size_t lpos = 0, epos = 0;
    if (fgets(aux, MAX_AUX, f) == NULL) return false;
    for (*n = 0; aux[lpos] != '\0' && aux[lpos] != '\n'; (*n)++){
        for (epos = 0; aux[lpos] != ',' && aux[lpos] != '\0' && aux[lpos] != '\n'; epos++){
            extra[epos] = aux[lpos++];
        }
        extra[epos] = '\0';
        lpos++;
        strcpy(columnas[*n], extra);
    }
    return true;
}

bool escribir_fila(const char *ruta, const char *columnas[], size_t n){
    FILE * f = fopen(ruta, "at");
    if (f == NULL) return false;
    for (size_t c = 0; c < n; c++){
        fprintf(f, "%s", columnas[c]);
        fputc((c != (n - 1)) ? ',' : '\n', f);
    }
    if (fclose(f)) return false;
    return true;
}


