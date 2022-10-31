#include <stdio.h>

void suma(int a, int b, long int * suma);
void resta(int a, int b, long int * resta);
void producto(int multiplicando, int multiplicador, float * producto);
void division(int dividendo, int divisor, double * resultado_division);
void modulo (int dividendo, int divisor, double * resto);

int main (void){
    int q = 8, r = 2;
    long int sum, substract;
    float mult;
    double div, mod;
    suma (q, r, &sum);
    resta (q, r, &substract);
    producto (q, r, &mult);
    division (q, r, &div);
    modulo (q, r, &mod);
    printf ("SUMADOS: %ld \n", sum);
    printf ("RESTADOS: %ld \n", substract);
    printf ("MULTIPLICADOS: %f \n", mult);
    printf ("DIVIDIDOS: %2f \n", div);
    printf ("RESTO: %2f \n", mod);
    return 0;
}


void suma(int a, int b, long int * suma){
    * suma = a + b;
}

void resta(int a, int b, long int * resta){
    * resta = a - b;
}

void producto(int multiplicando, int multiplicador, float * producto){
    *producto = multiplicando * multiplicador;
}

void division(int dividendo, int divisor, double * resultado_division){
    *resultado_division = dividendo / divisor;
}

void modulo (int dividendo, int divisor, double * resto){
    * resto = dividendo % divisor;
}

