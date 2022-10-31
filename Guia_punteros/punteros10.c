
#include <stdio.h>
#include <stdbool.h>


bool veccpy(double * dest, size_t ldest, const double * orig, size_t lorig){
    if (ldest < lorig)
        return false;
    for (size_t i = 0; (*(dest + i) = *(orig + i)); i++);
    return true;
}

/* 
11. Implementar una función que reciba 2 vectores y sus longitudes, y retorne un valor
booleano, por la interfaz, si los vectores son iguales.
*/

int comparar_arreglos (double * dest, size_t ldest, const double * orig, size_t lorig, bool * son_iguales){
    if (ldest != lorig){
        * son_iguales = false;
        return 1;
    }
    for (size_t i = 0; *(orig + i) != '\0'; i++)
        if (*(dest + i) != *(orig + i)){
            * son_iguales = false;
            return 1;
        }
    * son_iguales = true;
    return 0;
    
}

void arreglo_imprimir (const double arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        printf ("%.2f \t", arreglo[i]);
    }
    printf ("\n");
}

int main (void){
    double origen[4] = {1, 2, 4};
    double destino1[3] = {0};
    double destino2[7] = {0};
    bool son_iguales;
    printf ("%s\n", veccpy(destino1, 3, origen, 4) ? "SE COPIA" : "NO SE COPIA");
    comparar_arreglos (destino1, 3, origen, 4, &son_iguales);
    printf ("%s \n", son_iguales ? "TRUE" : "FALSE");
    printf ("%s\n", veccpy(destino2, 7, origen, 4) ? "SE COPIA" : "NO SE COPIA");
    comparar_arreglos (destino2, 7, origen, 4, &son_iguales);
    printf ("%s \n", son_iguales ? "TRUE" : "FALSE");
    arreglo_imprimir (destino2, 7);
    return 0;
}