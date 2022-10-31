

//En memdin1.c

 char * cadena_copiar (const char * string);
 /* Recibe una cadena
  * Retorna una copia de la cadena en memoria dinámica
  */

bool copio_cadena (const char * string, char * copia);
/* Recibe una cadena
  * Retorna por el nombre un booleano indicando si se copió correctamente la cadena
  * Devuelve por interfaz una copia de la cadena en memoria dinámica
  */

int * arreglo_copiar (const int * v, size_t longitud);
/* Recibe un arreglo y su longitud
 * Deuvle por el nombre una copia de ese arreglo en memoria dinámica
 */

bool copio_arreglo (const int * v, size_t longitud, int * copia);

char * cadena_copiar_hasta (const char * string, char separador);
 /*PIDE MEMORIA DINÁMICA (1M)*/
