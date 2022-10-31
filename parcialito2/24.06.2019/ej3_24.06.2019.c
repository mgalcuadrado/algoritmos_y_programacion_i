/* Un número de teléfono consta de una _cursiva(referencia) que indica qué representa ese número y que es un texto de
 * no más de MAX_CADENA elementos y de un entero largo sin signo que representa al número.
 * Un contacto en una agenda tiene el nombre del contacto, una cadena de no más de MAX_CADENA elementos y
 * de un vector de n (nunca más de MAX_NUMEROS) números telefónicos.
 * a. Declarar las estructuras struct numero y struct contacto que representen un número telefónico y
 * un contacto respectivamete.
 * b. Definir los tipos numero_t y contacto_t en base a las estructuras anteriores.
 * c. Escribir una función
 * bool numero_en_contacto(const contacto_t *c, unsigned long numero);
 * que retorne si numero es uno de los números del contacto c.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CADENA 100
#define MAX_NUMERO 20


typedef unsigned long ulong; 

struct numero{
    char * rep;
    ulong num;
};

struct contacto {
    char nombre[MAX_CADENA];
    struct numero n[MAX_NUMERO];
};

typedef struct numero numero_t;
typedef struct contacto contacto_t;



bool numero_en_contacto (const contacto_t * c, unsigned long numero){
    for (size_t i = 0; i < MAX_NUMERO; i++)
        if (c->n[i].num == numero)
            return true;
    return false;
}

int main(void){
    contacto_t c = {    
        .nombre = "Eze",
        .n[0].num = 1126122266,
        .n[1].num = 1159224809,
        .n[2].num = 1157541224,
        .n[3].num = 1153830102
    };
    c.n[0].rep = malloc (MAX_CADENA * sizeof(char));
    if (c.n[0].rep == NULL) return EXIT_FAILURE;
    strcpy (c.n[0].rep, "Trabajo");
    
    c.n[1].rep = malloc (MAX_CADENA * sizeof(char));
    if (c.n[1].rep == NULL){
        free (c.n[0].rep);
        return EXIT_FAILURE;
    }
    strcpy (c.n[1].rep, "Casa");

    c.n[2].rep = malloc (MAX_CADENA * sizeof(char));
    if (c.n[2].rep == NULL){
        free (c.n[0].rep);
        free (c.n[1].rep);
        return EXIT_FAILURE;
    }
    strcpy (c.n[2].rep, "Mama");

    printf ("El número%sse halló en la agenda\n", numero_en_contacto (&c, 1126122266) ? " " : " no ");
    return EXIT_SUCCESS;
}

