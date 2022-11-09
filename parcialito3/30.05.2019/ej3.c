/*
Dado el formato (y las funciones) del ejercicio 2 escribir un programa que se ejecute
$ ./escalar entrada salida valor
que cargue en memoria el arreglo contenido en el archivo binario entrada, multiplique cada uno de sus elementos por
el escalar valor y lo guarde en el archivo binario salida
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


float *leer_arreglo(const char *r, size_t *n);
bool escribir_arreglo(const char *r, const float *a, size_t n); 


int main (int argc, char * argv[]){
    if (argc != 4){
        fprintf(stderr, "Uso: %s [archivo_entrada] [archivo_salida] [multiplicador]\n", argv[0]);
        return 1;
    }
    size_t n;
    float * arr = leer_arreglo (argv[1], &n);
    if (arr == NULL) return 1;
    size_t valor = atoi(argv[3]);
    for (size_t i = 0; i < n; i++){
        arr[i] *= valor;
    }
    if (!escribir_arreglo(argv[2], arr, n)){
        free(arr);
        return 1;
    }
    free(arr);
    return 0;
}









bool escribir_arreglo(const char *r, const float *a, size_t n){
    FILE * f = fopen (r, "wb");
    if (f == NULL) return false;
    fwrite(&n, sizeof(size_t), 1, f);
    for (size_t i = 0; i < n; i++)
        fwrite(&a[i], sizeof(float), 1, f);
    if (fclose(f)) return false;
    return true;
}

float *leer_arreglo(const char *r, size_t *n){
    FILE * f =fopen (r, "rb");
    if (f == NULL) return NULL;
    if (fread (n, sizeof(size_t), 1, f) != 1){
        fclose(f);
        return NULL;
    }
    float * arr = malloc ((*n) * sizeof(float));
    if (arr == NULL){
        fclose(f);
        return NULL;
    }
    for (size_t i = 0; i < (*n); i++)
        if (fread(&arr[i], sizeof(float), 1, f) != 1){
            free(arr);
            fclose(f);
            return NULL;
        }
    if (fclose(f)){
        free(arr);
        return NULL;
    }
    return arr;
}