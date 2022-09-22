/*
1. a. Escribir una función
void reemplazar_caracter(char destino[], const char origen[], char viejo, char nuevo);
que almacene en destino el resultado de intercambiar todas las apariciones del carácter viejo por el carácter
nuevo en la cadena origen.
b. Con un pequeño código de ejemplo mostrar cómo utilizar a la función para cambiar las 'o' por 'e' en
la cadena "Los alumnos".


#include <stdio.h>

#define MAX 100

void reemplazar_caracter(char destino[], const char origen[], char viejo, char nuevo){
    size_t i;
    for (i = 0; origen[i] != '\0'; i++){
        if (origen[i] == viejo){
            destino[i] = nuevo;
        }
        else destino[i] = origen[i];
    }
    destino[i] = '\0';
}

int main (void){
    char cadena[MAX] = "Los alumnos";
    char dest[MAX];
    reemplazar_caracter(dest, cadena, 'o', 'e');
    puts (dest);
    return 0;
}



2. Una matriz cuadrada es triangular superior si todos los elementos debajo de su diagonal principal son iguales
a cero.
a. Escribir una función es_triangular_superior que reciba una matriz de flotantes de tamaño N×N y
que retorne si es triangular superior o no.
b. Teniendo #define N 3 escribir un pequeño ejemplo de código que declare y defina una matriz, llame a
la función del punto anterior e imprima un mensaje para el usuario según el resultado.

//COMO YA HICE ESTE EN EL PARCIALITO DEL 29.04.2022, VOY A HACER ES_TRIANGULAR_INFERIOR


bool es_triangular_inferior (size_t n, float m[n][n]){
    for (size_t i = 0; i < n - 1; i++){
        for (size_t j = i + 1; j < n; j++){
            if (i < j && m[i][j] != 0)
                return false;
        }
    }
    return true;
}


3. Escribir un programa que le pida un número al usuario y que, de ser posible, le muestre su raíz cuadrada.
(Nota: para calcular una raíz cuadrada puede utilizarse la función double sqrt(double x); de la biblioteca
<math.h>.)

*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

#define MENSAJE_INGRESO_TECLADO "Ingrese un número mayor o igual a cero a continuación:"
#define MENSAJE_NUMERO_NEGATIVO "Este programa solo calcula raíces para números mayores o iguales a cero"
#define MENSAJE_RAIZ_CUADRADA "La raíz cuadrada del número ingresado es: "

int main (void){
    char aux[MAX];
    puts (MENSAJE_INGRESO_TECLADO);
    fgets (aux, MAX, stdin);
    float numero = atof (aux);

    if (numero < 0){
        puts (MENSAJE_NUMERO_NEGATIVO);
        return 1;
    }
    else printf ("%s%f\n", MENSAJE_RAIZ_CUADRADA, sqrt(numero));
}

