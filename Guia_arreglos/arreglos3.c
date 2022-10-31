// ejercicio 3. escribir ciclos que realicen las operaciones
#include <stdio.h>



#define ELEMENTOS_A_INICIALIZAR_CERO 10



void inicializar_a_cero (int arreglo, int longitud);
void sumar_a_vector (int vector, int longitud, int valor);
void sumar_porcentaje (long salarios, int longitud, int porcentaje);

int main (void){
    int arreglo_a[ELEMENTOS_A_INICIALIZAR_CERO];
    inicializar_a_cero(arreglo_a, ELEMENTOS_A_INICIALIZAR_CERO);
    


}






//ej3 a. inicializar a cero 
void inicializar_a_cero (int arreglo, int longitud){
    for (size_t i = 0; i < longitud; i++)
        arreglo[i] = 0;
}

//ej3 b. 
void sumar_a_vector (int vector, int longitud, int valor){
    for (size_t i = 0; i < longitud; i++)
        vector[i] += valor;

}

// ej3 e. Sumar un 30% a cada uno de los 20 elementos del arreglo de números
void sumar_porcentaje (long salarios, int longitud, int porcentaje){
    for (size_t i = 0; i < longitud; i++){
        salarios [i] *= ((float) (100 + porcentaje)/100);
    }
}