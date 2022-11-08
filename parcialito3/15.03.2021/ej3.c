/*
3. Escribir un programa que se ejecute como:
$ ./convertir_productos [archivo_entrada] <[archivo_salida]>
donde el parámetro [archivo_entrada] es obligatorio mientras que el
parámetro <[archivo_salida]> es optativo.
El programa deberá levantar los producto_t del archivo binario
[archivo_entrada] y convertirlos a CSV. En el caso de que se haya
especificado un <[archivo_salida]> se volcarán en él, en el caso de que
no se haya especificado se volcarán en stdout.
El programa reutiliza las funciones del ejercicio 2
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 20
#define MAXIMO_PRODUCTOS 10


typedef struct{
    unsigned int id;
    char nombre[MAX_NOMBRE];
    float precio;
} producto_t;

//traje las funciones del ej2 para ver si había errores muy power de compilación
bool escribir_producto_csv(const producto_t *p, FILE *f){
    if (p == NULL) return false;
    fprintf(f, "%zd%s,", strlen(p->nombre), p->nombre);
    fprintf(f, "%d,%f\n", p->id, p->precio);
    return true;
}

bool leer_productos(const char *r, producto_t ps[], size_t max, size_t *n){
    FILE * f = fopen(r, "rb");
    if (f == NULL) return false;
    for (*n = 0; *n < max; (*n)++){
        size_t len;
        if (fread(&len, sizeof(size_t), 1, f) != 1) return true;
        if (len + 1 > MAX_NOMBRE) return false;
        if (fread(ps[*n].nombre, sizeof(char), len, f)) return false;
        ps[*n].nombre[len] = '\0';
        if (fread(&ps[*n].id, sizeof(unsigned int), 1, f) != 1) return false;
        if (fread(&ps[*n].precio, sizeof(float), 1, f) != 1) return false;
    }
    if (fclose(f)) return false;
    return true;
}


int main (int argc, char * argv[]){
    if (argc == 1 || argc > 3){
        fprintf(stderr, "Uso= %s [archivo_entrada] [archivo_salida_opcional]\n", argv[0]);
        return 1;
    }
    producto_t * ps = malloc (MAXIMO_PRODUCTOS * sizeof(producto_t));
    if (ps == NULL) return 1;
    size_t n;
    if (! leer_productos(argv[1], ps, MAXIMO_PRODUCTOS, &n)){
        free(ps);
        return 1;
    }
    FILE * f = stdout;
    if (argc == 3){
        FILE * f = fopen(argv[2], "wt");
        if (f == NULL){
            free(ps);
            return 1;
        }
    }
    free(ps);
    for (size_t j = 0; j < MAXIMO_PRODUCTOS; j++){
        if (! escribir_producto_csv(ps, f)) return 1;
    }
    if (f != stdout){
        if (fclose(f)) return 1;
    }
    return 0;
}