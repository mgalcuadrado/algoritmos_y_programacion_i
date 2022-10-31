//polinomio de grado n
#include <stdio.h>


double polyval(const int coeffs[], size_t grado, double x0);
void polyder (int coeffs[], size_t grado);
double polykderval(int coeffs[], size_t grado, double x0, size_t k);
void arreglo_imprimir (const double arreglo[], size_t longitud);
void polypolyval (const int coeffs[], size_t grado, double points[], size_t lpoints);

int main (void){
    int cubica[4]={3, 0, 1, -1};
    double points[3] = {-2, 0, 2};
    polypolyval (cubica, 3, points, 3);
    arreglo_imprimir (points, 3);
    return 0;
}

double polyval(const int coeffs[], size_t grado, double x0){
    double consts[grado + 1];
    consts[grado] = coeffs[grado];
    for (size_t i = grado; i > 0; i--)
        consts[i - 1] = coeffs[i - 1] + (consts[i] * x0);
    return consts[0];  
}

void polyder (int coeffs[], size_t grado){
    for (size_t i = 0; i < grado; i++){
        coeffs[i] = (i + 1) * coeffs[i + 1];
    }
    coeffs[grado] = 0; 
}

double polykderval(int coeffs[], size_t grado, double x0, size_t k){
    for (size_t i = 0; i < k; i++)  
        polyder(coeffs, (grado - i));
    return polyval(coeffs, (grado - k), x0);
}

void arreglo_imprimir (const double arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        printf ("%f \t", arreglo[i]);
    }
    printf ("\n");
}

void polypolyval (const int coeffs[], size_t grado, double points[], size_t lpoints){
    for (size_t i = 0; i < lpoints; i++)
        points[i] = polyval(coeffs, grado, points[i]);
}
