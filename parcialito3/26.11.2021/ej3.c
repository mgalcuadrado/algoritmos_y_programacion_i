/*
3. Dado el formato (y la función) del ejercicio 2 escribir un programa que se ejecute:
$ ./leer_n_cadenas entrada n
que imprima las primeras n cadenas del archivo binario entrada como líneas por stdout.
(Debe utilizarse la función previamente desarrollada.)
*/

int main (int argc, char * argv[]){
    if (argc != 3){
        fprintf(stderr, "Uso: %s [archivo_entrada] n", argv[0]);
        return 1;
    }
    size_t n = atoi(argv[2]);
    FILE * f = fopen(argv[1], "rb");
    if (f == NULL) return 1;
    for (size_t i = 0; i < n; i++){
        if ((char * cadena = leer_cadena(f)) == NULL){
            fclose(f);
            return 1;
        }
        fprintf(stdout, "%s\n", cadena);
        free(cadena);
    }
    if (fclose(salida)) return 1;
    return 0;
}