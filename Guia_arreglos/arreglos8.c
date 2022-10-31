/*Implementar funciones que reciban un arreglo de números y su longitud y realicen las siguientes operaciones:

    a. completar el vector con ceros,
    b. completar el vector con unos,
    c.calcular y retornar la suma,
    d. calcular y retornar la media,
    e. calcular y retornar la varianza,
    f. retornar el valor máximo del arreglo,
    g. retornar el valor mínimo del arreglo,
    h. modificar los elementos del vector reemplazándolos por sus valores al cuadrado,
    i. modificar los elementos del arreglo reemplazando cada elemento por su signo.
    j. diferencia elementos */

// MAMÁ HABLÓ 20 MINUTOS POR TELEFONO 
#include <stdio.h>

#define SIZE_1 10
#define SIZE_2 12

#define MENSAJE_SUMAR "La suma de los elementos es:"
#define MENSAJE_MEDIA "La media de los elementos es:"
#define MENSAJE_MAXIMO "El elemento máximo es:"
#define MENSAJE_MINIMO "El elemento mínimo es:"


//como condición deben ingresarse arreglos inicializados en al menos un elemento
void arreglo_completar_con_ceros (int arreglo[], size_t longitud);

//como condición deben ingresarse arreglos inicializados en al menos un elemento, 
// si se quiere mantener un cero el elemento siguiente debe estar inicializado de forma no nula
void arreglo_completar_con_unos(int arreglo[], size_t longitud);

long arreglo_sumar_elementos (const int arreglo[], size_t longitud);
float arreglo_media_elementos (const int arreglo[], size_t longitud);
float arreglo_varianza_elementos (const int arreglo[], size_t longitud);
int arreglo_maximo_elementos (const int arreglo[], size_t longitud);
int arreglo_minimo_elementos (const int arreglo[], size_t longitud);
void arreglo_al_cuadrado_elementos (int arreglo[], size_t longitud);
void arreglo_signo_elementos (int arreglo[], size_t longitud);
void arreglo_imprimir (const int arreglo[], size_t longitud);
void arreglo_diferencia_elementos (int arreglo[], size_t longitud);






void arreglo_completar_con_ceros (int arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        if (! arreglo[i])
            arreglo[i] = 0; 
    }
}

    /* void arreglo_completar_con_unos (int longitud, int arreglo[]){
        for (size_t i = 0; i < (longitud - 1); i++){
        if (! arreglo[i])
            arreglo[i] = 1;
        } */

// en completar con unos solo encuentro la manera de mantener valores inicializados como cero si son seguidos de un elemento no nulo
void arreglo_completar_con_unos (int arreglo[], size_t longitud){
    for (size_t i = 0; i < (longitud - 1); i++){
        if (! arreglo[i]){
            if (!arreglo [i+1])
                 arreglo[i] = 1; 
        }
    }
    if (! arreglo[longitud])
        arreglo[longitud] = 1;
}

long arreglo_sumar_elementos (const int arreglo[], size_t longitud){
    long suma = 0;
    for (size_t i = 0; i < longitud; i++){
        suma += arreglo[i];
    }
    return suma;
}

float arreglo_media_elementos (const int arreglo[], size_t longitud){
    float media = 0;
    for (size_t i = 0; i < longitud; i++){
        media += arreglo[i];
    }
    return (media / longitud);
}

float arreglo_varianza_elementos (const int arreglo[], size_t longitud){
    float varianza = 0;
    for (size_t i = 0; i < longitud; i++){
        varianza += (arreglo[i]*arreglo[i]);
    }
    return (varianza / longitud);
}

int arreglo_maximo_elementos (const int arreglo[], size_t longitud){
    int maximo = arreglo[0];
    for (size_t i = 1; i < longitud; i++){
        if (arreglo[i] > maximo)
            maximo = arreglo[i];
    }
    return maximo;
}

int arreglo_minimo_elementos (const int arreglo[], size_t longitud){
    int minimo = arreglo[0];
    for (size_t i = 1; i < longitud; i++){
        if (arreglo[i] < minimo)
            minimo = arreglo[i];
    }
    return minimo;
}

void arreglo_al_cuadrado_elementos (int arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        arreglo[i] *= arreglo[i];
    }
}

void arreglo_signo_elementos (int arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        if (arreglo[i] >= 0)
            arreglo[i] = 1;
        else arreglo[i] = -1;
    }
}

void arreglo_imprimir (const int arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        printf ("%d \t", arreglo[i]);
    }
    printf ("\n");
}

void arreglo_diferencia_elementos (int arreglo[], size_t longitud){
    for (size_t i = 0; i < (longitud-1); i++)
        arreglo[i] = arreglo[i+1] - arreglo[i];
}
