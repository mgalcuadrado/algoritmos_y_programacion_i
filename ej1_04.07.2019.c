/* persona : char nombre [max_cadena], uint dni, ushort año nacimiento, padre, madre que son punteros a personas
bool tiene_padres_mayores (const persona_t * p, short edad)
alguno de los padres era mayor de edad años al nacer la persona. No referencia = no mayor
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX_CADENA 100

struct persona{
    char nombre[MAX_CADENA];
    unsigned int dni;
    unsigned short nacimiento;
    struct persona * padre;
    struct persona * madre;
};

typedef struct persona persona_t;

bool tiene_padres_mayores (const persona_t * p, short edad){
    //buscamos que nacimiento_hijo - nacimiento_padre >= edad
    if ((p->padre == NULL && p->madre == NULL)) return false;
    //else return (((p->nacimiento) - (p->padre->nacimiento)) >= edad);
    return (((p->nacimiento) - (p->padre->nacimiento)) >= edad || ((p->nacimiento) - (p->madre->nacimiento)) >= edad);
}


int main (void){
    persona_t * juan = malloc (sizeof (persona_t));
    if (juan == NULL)
        return 1;
    juan -> nacimiento = 2006;
    persona_t * maria = malloc (sizeof(persona_t));
    if (maria == NULL){
        free (juan);
        return 1;
    }
    maria -> nacimiento = 1971;

    persona_t * fernando = malloc (sizeof(persona_t));
    if (fernando == NULL){
        free(juan);
        free (maria);
        return 1;
    } 
    fernando-> nacimiento = 1968;

    juan -> padre = fernando;
    juan -> madre = maria;
    
    printf ("Juan%stiene padres mayores\n", tiene_padres_mayores(juan, 40) ? " " : " no ");
    free(juan);
    free (maria);
    free(fernando);
    return 0;
}
