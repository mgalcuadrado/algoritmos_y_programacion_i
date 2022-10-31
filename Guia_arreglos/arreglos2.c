#include <stdio.h>

#define MENSAJE_SUMA "La suma de los elementos del arreglo es:"
#define SIZE 15

void inicializar_aleatorio (int arreglo, size_t longitud){
    for (size_t i = 0; i < longitud; i++)
        arreglo[i]=rand();
}


int main (void){
   //ej2 a. Un arreglo de enteros con 15 elementos, todos ellos de valor 0.

    int arreglo_a[15]= {0};
    int suma_arreglo_a;
    for (size_t i = 0; i<15; i++){
        printf("vector [%zd] = %d \n", i, arreglo_a[i]);
        suma_arreglo_a += arreglo_a[i];
    }
    printf ("\n %s %d \n", MENSAJE_SUMA, suma_arreglo_a);
    //ej2 b. 7 elementos double todos inicializados a 3.0

    double arreglo_b[7]= {3.0,3.0,3.0,3.0,3.0,3.0,3.0};
    double suma_arreglo_b;
    for (size_t i = 0; i < 7; i++){
        printf("vector [%zd] = %2f \n", i, arreglo_b[i]);
        suma_arreglo_b += arreglo_b[i];
    }
    printf ("\n %s %2f \n", MENSAJE_SUMA, suma_arreglo_b);
    //ej2 c. 

    float arreglo_c[SIZE]={0};
    float suma_arreglo_c;
    for (size_t i = 0; i < SIZE; i++){
        printf("vector [%zd] = %f \n", i, arreglo_c[i]);
        suma_arreglo_c += arreglo_c[i];
    }
    printf ("\n %s %f \n", MENSAJE_SUMA, suma_arreglo_c);

    // EJ2 d. Un arreglo de 4 enteros con los valores 9 5 1 1

    int arreglo_d[4]={9,5,1,1};
    int suma_arreglo_d;
    for (size_t i = 0; i<4; i++){
        printf("vector [%zd] = %d \n", i, arreglo_d[i]);
        suma_arreglo_d += arreglo_d[i];
    }
    printf ("\n %s %d \n", MENSAJE_SUMA, suma_arreglo_d);
    //ej2 e. arreglo de 4 chars hola 

    char arreglo_e[4]= {'h', 'o', 'l', 'a'}; 
    char suma_arreglo_e;
    for (size_t i = 0; i<4; i++){
        printf("vector [%zd] = %d \n", i, arreglo_e[i]);
        suma_arreglo_e += arreglo_e[i];
    }
    printf ("\n %s %d \n", MENSAJE_SUMA, suma_arreglo_e);

    char arreglo_f[4]= {104, 111, 108, 97}; 
    char suma_arreglo_f;
    for (size_t i = 0; i<4; i++){
        printf("vector [%zd] = %d \n", i, arreglo_f[i]);
        suma_arreglo_f += arreglo_f[i];
    }
    printf ("\n %s %d \n", MENSAJE_SUMA, suma_arreglo_f);

    int arreglo_g[SIZE];
    inicializar_aleatorio (arreglo_g, SIZE);
    int suma_arreglo_g;
    for (size_t i = 0; i < SIZE; i++){
        printf("vector [%zd] = %d \n", i, arreglo_g[i]);
        suma_arreglo_g += arreglo_g[i];
    }
    printf ("\n %s %d \n", MENSAJE_SUMA, suma_arreglo_g);
    //ej2 e. arreglo de 4 chars hola 


}









