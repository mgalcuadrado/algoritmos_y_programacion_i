/*
 * Implementar una función char *leer_digitos(); que lea de stdin caracteres de a uno por vez hasta leer
 * uno que no sea un dígito. Se debe devolver la cadena con los caracteres leídos (sin incluir el valor que no es
 * un dígito).
 * Usar la función booleana int isdigit(int c); que indica si un valor es dígito o no. (Observación:
 * isdigit(EOF) -> false)

 */


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define INIT_SIZE 20
#define MULTI 2

char * cadena_redimensionar(char * cadena, size_t * size) { //necesitás devolver el size por interfaz porque si no solo puede redimensionar una vez
    *size *= MULTI;
    char * aux = realloc (cadena, (*size) * sizeof(char));
    if (aux == NULL){
        free (cadena);
        return NULL;
    }
    return aux;
}

char * leer_digitos (){
    char c, *cadena = malloc (INIT_SIZE * sizeof(char));
    if (cadena == NULL) return NULL;
    size_t i, size = INIT_SIZE;
    for (i = 0; isdigit(c=getchar()) && (cadena[i] = c); i++){
        if (i == size){
            
            cadena = cadena_redimensionar(cadena, &size); 
            if (cadena == NULL) return NULL;
        }
    }
    cadena[i] = '\0';
    return cadena;
}


int main (void){
    puts (leer_digitos());
    return 0;
}