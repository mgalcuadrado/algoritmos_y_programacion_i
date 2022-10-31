/*
 * Implementá una función que reciba una cadena y retorne una copia de la misma, 
 * utilizando memoria dinámica, por el nombre. Si por algún motivo no se puede, retornar NULL.
 * Ahora implementá una función equivalente, pero en vez de retornar la copia por el nombre, 
 * que lo haga por la interfaz, mientras que por el nombre retorna un estado, bool, 
 * indicando el resultado de la operación.
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <stdbool.h>
 #include <ctype.h>
 #include <string.h>

 #define MAX 100

 char * cadena_copiar (const char * string){
    size_t i;
    for (i = 0; string[i] != '\0'; i++);
    char * copia = malloc ((++i) * sizeof(char));
    if (copia == NULL){
        return NULL;
    }
    for (size_t j = 0; j < i; j++)
        copia[j] = string [j];
    
    return copia;
 }


  bool copio_cadena (const char * string, char ** copia){
    char * cadena = malloc ((strlen (string) + 1) * sizeof(char));
    if (cadena == NULL){
        return false;
    }
    strcpy (cadena, string);
    *copia = cadena;
    return true;
 }

 //copiar arreglos de números

 int * arreglo_copiar (const int * v, size_t longitud){
    int * copia = malloc (longitud * sizeof(int));
    if (copia == NULL){
        return NULL;
    }
    for (size_t j = 0; j < longitud; j++)
        copia[j] = v[j];
    return copia;
 }


bool copio_arreglo (const int * v, size_t longitud, int * copia){
    copia = malloc (longitud * sizeof(int));
    if (copia == NULL){
        return false;
    }
    for (size_t j = 0; j < longitud; j++)
        copia[j] = v[j];
    return true;
 }

void arreglo_imprimir (const int arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        printf ("%d \t", arreglo[i]);
    }
    printf ("\n");
}

/* 3. Implementá una función que reciba una cadena de caracteres y un carácter. 
 * La función retorna una copia de la cadena, pero elimina todo lo que esté después 
 * del carácter recibido. Utilizá memoria dinámica.
 */

char * cadena_copiar_hasta (const char * string, char separador){ /*PIDE MEMORIA DINÁMICA (1M)*/
    size_t i;
    for (i = 0; string[i] != separador && string[i] != '\0'; i++);
    char * copia = malloc (i * sizeof(char));
    if (copia == NULL)
        return NULL;
    size_t j;
    for (j = 0; (copia[j] = string[j]) && j < i; j++);
    if (copia[j - 1] != '\0'){
        copia[j] = '\0';
    }
    return copia;
}

/* Implementá una función que reciba una cadena de caracteres que comienza con espacios y retorna, 
 * por la interfaz, una copia de la cadena sin los espacios del comienzo. 
 * Realizar las validaciones necesarias.

*/
 bool left_trim (const char * string, char ** copia){
    size_t i, k;
    for (k = 0; isspace(string); k++);
    char cadena [MAX];
    strcpy (cadena, string);
    for (i = 0; string[k] != '\0'; k++, i++){
        cadena[i] = string[k];
    }
    cadena[i] = '\0';
    *copia = malloc ((strlen(cadena) + 1) * sizeof(char));
    if (*copia == NULL){
        return false;
    }
    strcpy (*copia, cadena);
    return true;
 }

 int main (void){
    char cadena[MAX] = "         El pollito pio, el pollito pio";
    /*char * q; 
    printf ("%s\n", left_trim_interfaz (cadena, q) ? "se hizo el left trim" : "no se hizo el left trim");
    printf("%s\n", q);
    free (q);
    return 0;
    */
    char * copia1;
    printf ("%s \n", left_trim (cadena, &copia1) ? "TRUE" : "FALSE");
    puts (copia1);
    //int vect[10] = {1, 2, 3, 4, 4, 5, 6, 7};
    //int * copia2 = arreglo_copiar (vect, 10);
    //arreglo_imprimir (copia2, 10);
    //printf ("%s \n", copio_arreglo (vect, 10, copia2) ? "TRUE" : "FALSE");
    free (copia1);
    //free (copia2);
    //*/
    return 0;
 }