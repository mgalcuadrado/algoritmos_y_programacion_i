
/* Retornar dinámicamente las estructuras dirección y persona
 */



#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

#define MAX_PAIS 40 //direccion_t
#define MAX_PROVINCIA 30 //direccion_t
#define MAX_CIUDAD 20 //direccion_t
#define MAX_DIRECCION 30 //direccion_t
#define MAX_CP 10 //direccion_t

#define MAX_NOMBRE 40 //persona_t
#define MAX_APELLIDO 40 //persona_t

/* b. Una para manejar una dirección física que contiene arreglos para el país (máximo 40 caracteres),
 * la provincia (máximo 30 caracteres), la ciudad (máx. 20), la dirección (máx. 30) y el código postal (10).
*/

typedef struct{
    char pais[MAX_PAIS];
    char provincia[MAX_PROVINCIA];
    char ciudad[MAX_CIUDAD];
    char direccion[MAX_DIRECCION];
    char cp[MAX_CP];
}direccion_t;



/* c. Una persona, con un arreglo para el nombre, 
 * otro para el apellido y una estructura como la del inciso anterior.
*/

typedef struct {
    char *nombre, *apellido;
    direccion_t * direccion;
}persona_t;

void destruir_direccion (direccion_t * d){
    free (d);
}



direccion_t * crear_direccion(void){
    direccion_t * d = malloc (sizeof(direccion_t));
    if (d == NULL)
        return NULL;
    return d;
}

void destruir_persona(persona_t * p){
    free(p->nombre);
    free(p->apellido);
    destruir_direccion(p->direccion);
    free(p);
}

persona_t * crear_persona (){
    persona_t * p = malloc (sizeof(persona_t));
    if (p == NULL)
        return NULL;
    p->nombre = malloc(MAX_NOMBRE * sizeof(char));
    if (p->nombre == NULL){
        free(p);
        return NULL;
    }
    p->apellido = malloc(MAX_APELLIDO * sizeof(char));
    if (p->apellido == NULL){
        free (p->nombre);
        free(p);
        return NULL;
    }
    p->direccion = crear_direccion();
    if (p->direccion == NULL){
        destruir_persona(p);
        return NULL;
    }
    return p;
}

int main (void){

    destruir_direccion(dir);
    
    return 0;
}






/* if (GANAS_DE_SUFRIR)

typedef struct{
    char *pais;
    char *provincia;
    char *ciudad;
    char *direccion;
    char *cp;
}direccion2_t;


    void destruir_direccion2 (direccion2_t * d){
    free (d -> pais);
    free (d -> provincia);
    free (d -> ciudad);
    free (d -> direccion);
    free (d -> cp);
    free (d);
}

direccion2_t * crear_direccion2 (void){
    direccion2_t * d = malloc(sizeof(direccion2_t));
    if (d == NULL)
        return false;
    d -> pais = malloc (MAX_PAIS * sizeof(char));
    if (d -> pais == NULL){
        free (d);
        return NULL;
    }
    d -> provincia = malloc (MAX_PROVINCIA * sizeof(char));
    if (d -> provincia == NULL){
        free (d -> pais);
        free (d);
        return NULL; 
    }
    d -> ciudad = malloc (MAX_CIUDAD * sizeof(char));
    if (d -> ciudad == NULL){
        free (d -> pais);
        free (d -> provincia);
        free(d);
        return NULL;
    }
    d -> direccion = malloc (MAX_DIRECCION * sizeof(char));
    if (d -> direccion == NULL){
        free (d -> pais);
        free (d -> provincia);
        free (d -> ciudad);
        free(d);
        return NULL;
    }
    d -> cp = malloc (MAX_CP * sizeof(char));
    if (d -> cp == NULL){
        destruir_direccion2(d);
        return NULL;
    }
    return d;
}

*/