/* Implementar la función char *join(char *strs[], size_t n, char delim); que reciba en strs un
 * arreglo de n cadenas de caracteres y devuelva una cadena que contenga la concatenación de todas ellas usando
 * el carácter delim como delimitador.
 *Por ejemplo, si se llama a join({"hola", "que", "tal"}, 3, ' ') debe devolverse "hola que tal".
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char * join(char *strs[], size_t n, char delim){
    char separador[2] = {[0] = delim, [1] = '\0'};
    size_t cant = 0;
    for (size_t i = 0; i < n; i++){
        cant += strlen(strs[i]) + 1;
    }
    char * cadena = malloc (cant * sizeof (char));
    if (cadena == NULL)
        return NULL;
    strcpy (cadena, strs[0]);
    for (size_t j = 1; j < n; j++){
        strcat (cadena, separador);
        strcat (cadena, strs[j]);
    }
    return cadena;
}

int main (void){
    char ** string = malloc (5 * sizeof(char*));
    if (string == NULL)
        return 1;
    for (size_t i = 0; i < 5; i++){
        string[i] = malloc (20 * sizeof(char));
        if (string[i] == NULL){
           for (size_t j = 0; j < i; j++)
                free (string[i]);
            free (string);
        }
    }
    strcpy (string[0], "Hola");
    strcpy (string[1], "que");
    strcpy (string[2], "tal,");
    strcpy (string[3], "todo");
    strcpy (string[4], "bien");
    puts (join(string, 5, ' '));
    for (size_t j = 0; j < 5; j++)
        free (string[j]);
    free (string);
    return 0;
}