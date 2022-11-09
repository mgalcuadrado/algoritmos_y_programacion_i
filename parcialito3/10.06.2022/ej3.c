/*
3. Dado el formato (y las funciones) del ejercicio 2 escribir un programa que se ejecute:
$ ./transformar entrada salida a b
que cargue en memoria el arreglo de flotantes de doble precisión contenido en el archivo binario entrada y aplique la
transformación ax +b a cada uno de sus elementos y lo guarde en el archivo binario salida.
Se deben utilizar las funciones desarrolladas en el punto 2.
*/


bool escribir_doubles(const char * r, const double a[], size_t n);
double * leer_doubles(const char * r, size_t *n);

int main (int argc, char * argv[]){
    if (argc != 5){
        fprintf(stderr, "Uso: %s entrada salida a b\n", argv[0]);
        return 1;
    }
    size_t n;
    double * arr = leer_doubles(argv[1], &n);
    if (arr == NULL) return 1;
    float a = atof(argv[3]), b = atof(argv[4]);
    for (size_t i = 0; i < n; i++)
        arr[i] = a * arr[i] + b;
    if (!escribir_doubles(argv[2], arr, n)){
        free(arr);
        return 1;
    }
    free(arr);
    return 0;
}