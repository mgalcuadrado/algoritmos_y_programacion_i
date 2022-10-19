/*
 * Se tiene al tipo persona_t representado sobre una estructura. Una persona se compone por un nombre de
 * tipo char *, un apellido de tipo char * y un DNI de tipo int.
 * a. Implementar la función 
 * persona_t *persona_clonar(const persona_t *p); 
 * que reciba una persona p y la clone en memoria nueva.
 * b. Implementar una función void persona_destruir(persona_t *p); que reciba una persona p y libere
 * su memoria asociada
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STR 50

 typedef struct{
    char * nombre;
    char * apellido;
    int dni;
 }persona_t;

void persona_destruir (persona_t * p){
    free (p -> nombre);
    free (p -> apellido);
    free (p);
}

persona_t *persona_clonar1(const persona_t *p){
    persona_t * clon = malloc (sizeof(persona_t));
    if (clon == NULL)
        return NULL;
    clon -> nombre = malloc (MAX_STR * sizeof(char));
    if (clon -> nombre == NULL){
        free (clon);
        return NULL;
    }
    clon -> apellido = malloc (MAX_STR * sizeof(char));
    if (clon -> apellido == NULL){
        persona_destruir(clon);
        return NULL;
    }
    strcpy (clon -> nombre, p -> nombre);
    strcpy (clon -> apellido, p -> apellido);
    clon -> dni = p -> dni;
    return clon;
}

void _cadena_copiar (char * a, const char * b){
    size_t i;
    for (i = 0; b[i] != '\0'; i++)
        a[i] = b[i];
    a[i] = '\0';
}

persona_t *persona_clonar2(const persona_t *p){
    persona_t * clon = malloc (sizeof(persona_t));
    if (clon == NULL)
        return NULL;
    clon -> nombre = malloc (MAX_STR * sizeof(char));
    if (clon -> nombre == NULL){
        free (clon);
        return NULL;
    }
    clon -> apellido = malloc (MAX_STR * sizeof(char));
    if (clon -> apellido == NULL){
        persona_destruir(clon);
        return NULL;
    }
    _cadena_copiar (clon -> nombre, p -> nombre);
    _cadena_copiar (clon -> apellido, p -> apellido);
    clon -> dni = p -> dni;
    return clon;
}




int main (void){
    persona_t ts = {"Taylor", "Swift", 13};
    persona_t * clon = persona_clonar1(&ts);
    printf ("Nombre: %s\nApellido: %s\nDNI: %d\n", clon->nombre, clon->apellido, clon->dni);
    persona_destruir(clon);
    return 0;
}

