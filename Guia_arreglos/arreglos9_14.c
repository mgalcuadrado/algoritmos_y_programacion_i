#include <stdio.h>
#include <stdbool.h>

#define ERROR_MENSAJE_ARREGLO_COPIA "No se pudo copiar el vector de origen en el de destino"

//bool veccpy(double dest[], size_t ldest, const double orig[], size_t lorig);
//bool arreglos_son_iguales(const double dest[], size_t ldest, const double orig[], size_t lorig);
//bool arreglo_ordenado (const double a[], size_t longitud);
//bool arreglo_ordenado_mayor_menor (const double a[], size_t longitud);
bool arreglo_ordenado_menor_mayor (const double a[], size_t longitud);
//bool arreglo_buscar_elemento_lineal (const double a[], size_t longitud, double elemento);
size_t arreglo_posicion_buscar_elemento_lineal (const double a[], size_t longitud, double elemento);
size_t arreglo_posicion_buscar_elemento_binario (const double a[], size_t longitud, double elemento);


//void arreglo_imprimir (const double arreglo[], size_t longitud);

int main (void){
    //double destino1[1]={0};
    double origen1[4]= {1.2, 3.4, 5.6, 7.8};
    //veccpy (destino1, 1, origen1, 4);
    double vector[7] = {1.2, 4, -3, -2, 5.1, -24};
    if (arreglo_ordenado_menor_mayor(vector, 7))
        printf ("true");
    else printf ("false");

    
    printf ("%zd \n", arreglo_posicion_buscar_elemento_lineal(origen1, 4, 1.2));
    printf ("%zd \n", arreglo_posicion_buscar_elemento_binario (origen1, 4, 1.2));
    printf ("%zd \n", arreglo_posicion_buscar_elemento_lineal(origen1, 4, 1.5));
    printf ("%zd \n", arreglo_posicion_buscar_elemento_binario (origen1, 4, 1.5));
    
    return 0;
}



/*
bool veccpy(double dest[], size_t ldest, const double orig[], size_t lorig){
    if (ldest < lorig){
        return false;
    }
    for (size_t i = 0; i < lorig; i++)
        dest[i] = orig[i];
    return true;
}

void arreglo_imprimir (const double arreglo[], size_t longitud){
    for (size_t i = 0; i < longitud; i++){
        printf ("%.2f \t", arreglo[i]);
    }
    printf ("\n");
}

bool arreglos_son_iguales(const double dest[], size_t ldest, const double orig[], size_t lorig){
    if (lorig != ldest)
        return false;
    for (size_t i = 0; i < lorig; i++){
        if (orig[i] != dest[i])
            return false;
    }
    return true;
}
*/
bool arreglo_ordenado_menor_mayor (const double a[], size_t longitud){
    if (a[0] > a[longitud-1]){
        return false;
    }
    for (size_t i = 0; i < (longitud - 1); i++){
        if (a[i] > a[i+1])
            return false;
    }
    return true;
}
/*
bool arreglo_ordenado_mayor_menor (const double a[], size_t longitud){
    if (a[0] < a[longitud-1]) //si ya se ve directamente nos ahorramos el for
        return false;
    for (size_t i = 0; i < (longitud - 1); i++){
        if (a[i] < a[i+1])
            return false;
    }
    return true;
}

bool arreglo_ordenado (const double a[], size_t longitud){
    return (arreglo_ordenado_mayor_menor || arreglo_ordenado_menor_mayor);
}

bool arreglo_buscar_elemento_lineal (const double a[], size_t longitud, double elemento){
    for (size_t i = 0; i < longitud; i++){
        if (a[i] == elemento)
            return true;
    }
    return false;
}
*/


//si falla, se decidió que devuelva longitud ya que no puede ser un elemento del arreglo
//el resultado debería validarse con que sea menor a longitud!
size_t arreglo_posicion_buscar_elemento_lineal (const double a[], size_t longitud, double elemento){
    for (size_t i = 0; i < longitud; i++){
        if (a[i] == elemento)
            return i;
    }
    return longitud;
}

//si falla, se decidió que devuelva longitud. 
// solo aplica para ordenados de menor a mayor
size_t arreglo_posicion_buscar_elemento_binario (const double a[], size_t longitud, double elemento){
    if (!arreglo_ordenado_menor_mayor(a, longitud))
        return longitud;
    if (a[0] == elemento)
        return 0;
    size_t inicio = 0;
    size_t final = longitud - 1;
    while (inicio < final){
        size_t medio = (inicio + final) / 2; 
        if (a[medio] < elemento)
            inicio = medio + 1;
        if (a[medio] > elemento)
            final = medio - 1;
        if (a[medio] == elemento)
            return medio;
    }
    return longitud;
}

