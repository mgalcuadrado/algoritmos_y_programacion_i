/* Implementá una función que lea una cadena de caracteres de largo indefinido (de cualquier FILE *)
y la retorne por el nombre. Implementar otra función que realice lo mismo, 
pero retornando la cadena leída por la interfaz y si todo salió bien por el nombre. Prototipos:
char * readline(FILE * f);
bool readline(FILE *f, char **s);
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define INIT_SIZE 100
#define MULT 2

char * readline(FILE * f){
    char * cadena = malloc (INIT_SIZE * sizeof(char));
    if (cadena == NULL) return NULL;
    size_t size = INIT_SIZE,  pos = 0; 
    int c;
    while ((c = fgetc(f)) != EOF && c != '\0' && c != '\n'){
        if ((pos + 1) == size){
            size *= MULT;
            char * aux = realloc (cadena, size * sizeof(char));
            if (aux == NULL){
                free(cadena);
                return NULL;
            }
            cadena = aux;
        }
        cadena[pos++] = c;
    }
    cadena[pos] = '\0';
    return cadena;
}

bool _readline(FILE *f, char **s){
    *s = malloc (INIT_SIZE * sizeof(char));
    if (*s == NULL) return false;
    size_t size = INIT_SIZE,  pos = 0; 
    int c;
    while ((c = fgetc(f)) != EOF && c != '\0' && c != '\n'){
        if ((pos + 1) == size){
            size *= MULT;
            char * aux = realloc (*s, size * sizeof(char));
            if (aux == NULL){
                free(*s);
                return false;
            }
            *s = aux;
        }
        *s[pos++] = c;
    }
    *s[pos] = '\0';
    return true;

}

int main (int argc, char * argv[]){
    if (argc != 2){
        fprintf(stderr, "Uso: %s [archivo]", argv[0]);
        return 1;
    }
    FILE * f = stdin;
    if (strcmp (argv[1], "stdin")) f = fopen(argv[1], "rt");
    if (f == NULL) return 1;
    printf ("hola??\n");
    char * cadena = readline(f);
    if (cadena == NULL) return 1;
    puts(cadena);
    free(cadena);
    if (f != stdin) fclose(f);
    return 0;
}