/* Se tiene representada a una cadena de caracteres sobre una estructura que contiene una cadena dinámica y
 * la longitud de la misma.
 * a. Declarar la estructura de la cadena.
 * b. Redefinir la estructura declarada como el tipo cadena_t.
 * c. Implementar la función
 * bool cadena_concatenar(cadena_t *destino, const cadena_t *origen);
 * que concatene la cadena representada en origen a la cadena destino. En caso de error no debe
 * modificarse destino y debe devolverse false.
*/



#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char * cadena;
    char longitud;
}cadena_t;

bool cadena_concatenar1 (cadena_t * destino, const cadena_t *origen){
    if (origen -> cadena == NULL || destino -> cadena == NULL)
        return false;
    char * aux = realloc (destino-> cadena, destino->longitud + origen->longitud + 1);
    if (aux == NULL)
        return false;
    destino -> cadena = aux;
    strcat (destino->cadena, origen->cadena);
    return true;
}

bool cadena_concatenar2 (cadena_t * destino, const cadena_t *origen){
    if (origen -> cadena == NULL || destino -> cadena == NULL)
        return false;
    char * aux = realloc (destino-> cadena, destino->longitud + origen->longitud + 1);
    if (aux == NULL)
        return false;
    destino -> cadena = aux;
    for (size_t j = destino->longitud; j < (destino->longitud + origen->longitud + 1); j++)
        destino->cadena[j] = origen->cadena [j - destino->longitud];
    return true;
}


//esto no se pedía pero lo hice para probar que todo funcionase correctamente
int main (void){
    cadena_t * cad = malloc (sizeof(cadena_t));
    if (cad == NULL)
        return 1;
    cad->cadena = malloc (7 * sizeof(char));
    if (cad->cadena == NULL){
        free (cad);
        return 1;
    }
    strcpy (cad->cadena, "Hola");
    cadena_t * str = malloc (sizeof(cadena_t));
    if (str == NULL){
        free (cad->cadena);
        free(cad);
        return 1;
    }
    str->cadena = malloc (10 * sizeof(char));
    if (str->cadena == NULL){
        free (cad->cadena);
        free (cad);
        free (str);
        return 1;
    }
    strcpy (str->cadena, " mundo");
    cadena_concatenar1(cad, str);
    puts (cad->cadena);
    free (cad->cadena);
    free (cad);
    free (str->cadena);
    free (str);
    return 0;
}