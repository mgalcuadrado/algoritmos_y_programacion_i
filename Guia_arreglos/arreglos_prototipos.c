

//En arreglos2.c

void inicializar_aleatorio (int arreglo, size_t longitud);
/* Recibe un arreglo y su longitud.
 * Inicializa todos los elementos en valores pseudoaleatorios utilizando rand().
 */

//En arreglos3.c

void inicializar_a_cero (int arreglo, int longitud);
/* Recibe un arreglo y su longitud.
 * Inicializa todos los elementos en cero. 
 */

void sumar_a_vector (int vector, int longitud, int valor);
/* Recibe un arreglo y su longitud, y el valor a sumar.
 * A todos los elementos del arrreglo les suma valor.
 * Funciona para restarle un valor también, ingresando un valor negativo.
 */

void sumar_porcentaje (long salarios, int longitud, int porcentaje);
/* Recibe un arreglo y su longitud, y el porcentaje a sumar.
 * A todos los elementos del arrreglo les suma el porcentaje.
 * Funciona para restarle un porcentaje también, ingresando un porcentaje negativo. 
 */


//En arreglos8.c

void arreglo_completar_con_ceros (int arreglo[], size_t longitud);
/* Recibe un arreglo y su longitud.
 * Completa con ceros los elementos no inicializados.
 */

void arreglo_completar_con_unos (int arreglo[], size_t longitud);
/* Recibe un arreglo y su longitud.
 * Completa con unos los elementos no inicializados seguidos por el cero.
 */

long arreglo_sumar_elementos (const int arreglo[], size_t longitud);
/* Recibe un arreglo y su longitud.
 * Retorna por el nombre la summa de los elementos del arreglo.
 */

float arreglo_media_elementos (const int arreglo[], size_t longitud){
/* Recibe un arreglo y su longitud.
 * Retorna por el nombre el promedio del valor de los elementos del arreglo.
 */

int arreglo_maximo_elementos (const int arreglo[], size_t longitud);
/* Recibe un arreglo y su longitud.
 * Retorna por el nombre el elemento más grande, o el elemento máximo, del arreglo.
 */

int arreglo_minimo_elementos (const int arreglo[], size_t longitud);
/* Recibe un arreglo y su longitud.
 * Retorna por el nombre el elemento más chico, o el elemento mínimo, del arreglo.
 */

void arreglo_al_cuadrado_elementos (int arreglo[], size_t longitud);
/* Recibe un arreglo y su longitud.
 * Eleva al cuadrado todos los elementos del arreglo.
 */

void arreglo_imprimir (const int arreglo[], size_t longitud);
/* Recibe un arreglo y su longitud.
 * Imprime los elementos del arreglo.
 */



//En arreglos9_14.c

bool veccpy(double dest[], size_t ldest, const double orig[], size_t lorig);
/* Recibe dos arreglos de doubles con sus longitudes.
 * Retorna por el nombre un booleano indicando si se realizó la copia.
 * Copia el arreglo de origen en destino.
 */

bool arreglos_son_iguales(const double dest[], size_t ldest, const double orig[], size_t lorig);
/* Recibe dos arreglos de doubles con sus longitudes.
 * Retorna por el nombre un booleano indicando si los arreglos son iguales.
 */


