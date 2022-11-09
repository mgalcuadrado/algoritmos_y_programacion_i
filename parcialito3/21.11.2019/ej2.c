/*
2. Se tiene un archivo binario que contiene un size_t n seguido de n valores flotantes de doble precisión, según el
siguiente esquema:
+----+----+----+----+----+- -+----+
| n | a1 | a2 | a3 | a4 | ... | an |
+----+----+----+----+----+- -+----+
a. Escribir una función bool escribir_doubles(const char *r, const double a[], size_t n); que reciba una
ruta r y un arreglo a de n doubles y los escriba en un archivo binario según el formato anterior.
b. Escribir una función double *leer_doubles(const char *r, size_t *n); que reciba una ruta r a un archivo
binario y devuelva por el nombre el arreglo de doubles contenido en él y en n la cantidad de elementos leídos.
*/

bool escribir_doubles(const char *r, const double a[], size_t n){
    FILE * f = fopen (r, "wb");
    if (f == NULL) return false;
    if (fwrite(&n, sizeof(size_t), 1, f) != 1){
        fclose(f);
        return false;
    }
    if (fwrite(&a[i], sizeof(double), n, f) != 1){
        fclose(f);
        return false;
    }
    return (fclose(f) != EOF);
}

double * leer_doubles(const char *r, size_t *n){
    FILE * f = fopen(r, "rb");
    if (f == NULL) return NULL;
    if (fread (n, sizeof(size_t), 1, f) != 1){ //inicialmente puse fread(&(*n), ...) pero es lo mismo poner n directo
        fclose(f);
        return NULL; 
    }
    double * arr = malloc ((*n) * sizeof(double));
    if (arr == NULL){
        fclose(f);
        return NULL;
    }
    if (fread(&arr[i], sizeof(double), (*n), f) != 1){
           free(arr);
           fclose(f);
           return NULL;
    }
    if (fclose(f))
        return NULL;
    return arr;
}

