/*
3. Dado el formato (y las funciones) del ejercicio 2 escribir un programa que se ejecute
$ ./rotar entrada salida radianes
que cargue en memoria el arreglo de coordenadas contenido en el archivo binario entrada, rote cada uno de sus
elementos por el ángulo radianes y lo guarde en el archivo binario salida.
(Recordar las funciones de transformación x′= xcos θ −y sin θ, y′= xsin θ + y cos θ.)
*/

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef float coord_t[2];

bool escribir_coordenadas(const char *r, coord_t *cs, size_t n);
coord_t *leer_coordenadas(const char *r, size_t *n);

int main (int argc, char * argv[]){
    if (argc !=4){
        fprintf(stderr, "Uso: %s [archivo_entrada] [archivo_salida] [radianes]\n", argv[0]);
        return 1;
    }
    size_t n;
    float rad = atoi(argv[3]);
    coord_t * p = leer_coordenadas(argv[1], &n);
    if (p == NULL) return 1;
    for (size_t i = 0; i < n; i++){
        p[i][0] = p[i][0] * cos(rad) - p[i][1] * sin (rad);
        p[i][1] = p[i][0] * sin(rad) + p[i][1] * cos (rad);
    }
    if (! escribir_coordenadas(argv[2], p, n)){
        free(p);
        return 1;
    }
    free(p);
    return 0;
}


bool escribir_coordenadas(const char *r, coord_t *cs, size_t n){
    FILE * f = fopen(r, "wb");
    if (f == NULL) return false;
    if (fwrite (&n, sizeof(size_t), 1, f) != 1){
        fclose(f);
        return false;
    }
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < 2; j++){
            if (fwrite(&cs[i][j], sizeof(float), 1, f) != 1){
                fclose(f);
                return false;
            }
        }
    }
    if (fclose(f))
         return false;
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
