/*
2. Se tiene un archivo binario que contiene un size_t n seguido de n flotantes, según el siguiente esquema:
+----+----+----+----+----+- -+----+
| n | a1 | a2 | a3 | a4 | ... | an |
+----+----+----+----+----+- -+----+
a. Escribir una función bool escribir_arreglo(const char *r, const float *a, size_t n); que reciba una
ruta r y un arreglo a de n elementos y los escriba en un archivo binario según el formato anterior.
b. Escribir una función float *leer_arreglo(const char *r, size_t *n); que reciba una ruta r a un archivo
binario y devuelva por nombre el arreglo contenido en él, y en n la cantidad de elementos leídos.
*/

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