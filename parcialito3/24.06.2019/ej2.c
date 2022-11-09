/*
2. Se tiene un archivo binario que contiene un size_t n seguido de n pares de coordenadas flotantes, según el siguiente
esquema:
+----+----+----+----+----+- -+----+----+
| n | x1 | y1 | x2 | y2 | ... | xn | yn |
+----+----+----+----+----+- -+----+----+
Teniendo definido typedef float coord_t[2]; se pide:
a. Escribir una función bool escribir_coordenadas(const char *r, coord_t *cs, size_t n); que reciba una
ruta r y un arreglo cs de n pares de coordenadas y los escriba en un archivo binario según el formato anterior.
b. Escribir una función coord_t *leer_coordenadas(const char *r, size_t *n); que reciba una ruta r a un
archivo binario y devuelva por nombre el arreglo de coordenadas contenido en él, y en n la cantidad de elementos
leídos.
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef float coord_t[2];

bool escribir_coordenadas(const char *r, coord_t *cs, size_t n){
    FILE * f = fopen(r, "wb");
    if (f == NULL) return false;
    if (fwrite (&n, sizeof(size_t), 1, f) != 1){
        fclose(f);
        return false;
    }
    for (size_t i = 0; i < n; i++){
            if (fwrite(&cs[i], sizeof(float), 2, f) != 2){
                fclose(f);
                return false;
            }
        }
    }
    if (fclose(f))
        return false
    return true;
}

coord_t *leer_coordenadas(const char *r, size_t *n){
    *n = 0;
    FILE * f = fopen(r, "rb");
    if (f == NULL) return NULL;
    if (fread(n, sizeof(size_t), 1, f) != 1){
        fclose(f);
        return NULL;
    }
    coord_t * lec = malloc (sizeof(coord_t) * (*n));
    if (lec == NULL){
        fclose(f);
        return NULL;
    }
    for (size_t i = 0; i < (*n); i++){
        if (fread(lec[i], sizeof(float), 2, f) != 2){
            free(lec);
            fclose(f);
            return NULL;
        }
    }
    fclose(f);
    return lec;
}
