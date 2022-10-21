/* 
Se tiene un producto definido como:
struct producto {
char codigo[5];
char nombre[21];
};
escribir una función:
struct producto *leer_productos(size_t *n);
que lea de stdin productos hasta que se termine la entrada. Los productos tienen un código de 4 dígitos y
un nombre de hasta 20 caracteres. La función debe devolver un arreglo con los n productos leídos y su
cantidad a través de n.
Por ejemplo la entrada podría ser:
0123Sidra
0213Pan dulce
1234Turron muy duro
dame un seg que leo la consigna
*/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STR 100
#define INIT_SIZE 20
#define MULT 2


struct producto {
char codigo[5];
char nombre[21];
};

struct producto *leer_productos(size_t *n){
    char lec[MAX_STR];
    size_t size = INIT_SIZE;
    *n = 0;
    struct producto * p = malloc (size * sizeof(struct producto));
    if (p == NULL) return NULL;
    while (fgets (lec, MAX_STR, stdin) != NULL){
        if (size == *n){
            size *= MULT;
            struct producto * aux = realloc (p, size * sizeof(struct producto));
            if (aux == NULL){
                free (p);
                return NULL;
            }
            p = aux;
        }
        size_t lpos, npos;
        for (lpos = 0; isdigit(lec[lpos]) && (lpos < 5) && lec[pos] != '\0'; lpos++){
            p[*n].codigo[lpos] = lec[lpos]; 
        }
        p[*n].codigo[lpos] = '\0';
        for (npos = 0; lec[lpos] != '\0' && lpos < 24; lpos++, npos++){
            p[*n].nombre[npos] = lec[lpos];
        }
        p[*n].nombre[npos] = '\0';
        *n = *n + 1;
    }
    if (*n != size){
        struct producto * aux = realloc (p, (*n) * sizeof(struct producto));
        if (aux == NULL){ 
            *n = size;
            return p;
        }
        p = aux;
    }
    return p;
}


int main (void){
    struct producto * p;
    size_t n;
    p = leer_productos(&n);
    printf ("Este es de prueba, veamos la primera cadena, que era \n codigo: %s\n nombre: %s\n", p[0].codigo, p[0].nombre);
    free (p);
    return 0;
}