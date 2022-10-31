






//En punteros_busqueda.c

const int * posicion_busqueda_lineal (const int * v, size_t longitud, int objetivo);
/* Recibe un arreglo de elementos con su longitud y el elemento que busca encontrar (el objetivo)
 * Devuelve un puntero a la posición en la que se encuentra el elemento
 * De no pertenecer al arreglo, retorna un puntero a la longitud del arreglo
 */

bool encontro_elemento_busqueda_lineal(int * v, size_t longitud, int objetivo, int ** resultado);
/* Recibe un arreglo de elementos con su longitud, el elemento que busca encontrar y un puntero a puntero al resultado
 * Devuelve por el nombre un booleano diciendo si encontró el elemento
 * Devuelve por la interfaz la posición en la que se encuentra el elemento
 * De no hallarse el elemento en el arreglo, resultado apunta a NULL
 */