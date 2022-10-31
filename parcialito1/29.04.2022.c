/*  1er parcialito – 29/04/2022
1. a. Escribir una función
void left_trim(char cadena[]);
que elimine todos los caracteres de espacio que haya al comienzo de la cadena. Por ejemplo, si se le pasara la
cadena " hola mundo " después de ejecutar la función la misma deberá ser "hola mundo ".
No se permite el uso de funciones de biblioteca en este ejercicio. Todo lo necesario debe ser implementado.
b. Con un pequeño código de ejemplo mostrar cómo utilizar a la función con las cadenas del ejemplo
anterior.
2. Una matriz cuadrada es triangular superior si todos los elementos debajo de su diagonal principal son iguales
a cero.
a. Escribir una función es_triangular_superior que reciba una matriz de flotantes de tamaño N×N y
que retorne si es triangular superior o no.
b. Teniendo #define N 3 escribir un pequeño ejemplo de código que declare y defina una matriz, llame a
la función del punto anterior e imprima un mensaje para el usuario según el resultado.
3. Escribir un programa que le pida un número al usuario y que, de ser posible, le muestre su raíz cuadrada.
(Nota: para calcular una raíz cuadrada puede utilizarse la función double sqrt(double x); de la biblioteca
<math.h>.)
*/

//1 left trim

/* 
#include <stdio.h>

#define MAX 100

void left_trim (char cadena[]){
    size_t i = 0, j;
    while (cadena[i] == ' '){
        i++;
    }
    for (j = 0; (cadena[j] = cadena[i]); j++, i++);
    cadena[j] = '\0';
}

int main (void){
    char cadena[100] = " hola mundo ";
    left_trim(cadena);
    for (size_t i = 0; cadena[i] != '\0'; i++){
        printf("%c", cadena[i]);
    }
    return 0;
}

2. Una matriz cuadrada es triangular superior si todos los elementos debajo de su diagonal
 * principal son iguales a cero.
 * a. Escribir una función es_triangular_superior que reciba una matriz de flotantes de tamaño N×N y
 * que retorne si es triangular superior o no.
 * b. Teniendo #define N 3 escribir un pequeño ejemplo de código que declare y defina una matriz, llame a
 * la función del punto anterior e imprima un mensaje para el usuario según el resultado.


#include <stdio.h>
#include <stdbool.h>

#define N 3
#define MENSAJE_ES_TRIANGULAR_SUPERIOR "La matriz es triangular superior"
#define MENSAJE_NO_ES_TRIANGULAR_SUPERIOR "La matriz no es triangular superior"

bool es_triangular_superior (size_t n, float matriz[n][n]){
    for (size_t i = 1; i < n; i++){ 
        for (size_t j = 0; j < i; j++){
            if (i > j && matriz[i][j] != 0)
                return false;
        }
    }
    return true;
}

int main(void){
    float a[N][N] = {
        {1, 2, 3},
        {0, 1, 4},
        {0, 1, 8},
    };
    if (es_triangular_superior(N, a))
        puts(MENSAJE_ES_TRIANGULAR_SUPERIOR);
    else puts (MENSAJE_NO_ES_TRIANGULAR_SUPERIOR);
    return 0;

}

*/

/* 3. Escribir un programa que le pida un número al usuario y que, de ser posible, le muestre su raíz cuadrada.
(Nota: para calcular una raíz cuadrada puede utilizarse la función double sqrt(double x); de la biblioteca
<math.h>.)
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 100

#define MENSAJE_INGRESO_TECLADO "Ingrese un número por teclado para que se calcule su raíz cuadrada."
#define MENSAJE_RAIZ_CUADRADA "La raíz cuadrada del número ingresado es: "
#define MENSAJE_NUMERO_NEGATIVO "Este programa no calcula raíces de números negativos"

int main (void){
    char string[MAX];
    puts(MENSAJE_INGRESO_TECLADO);
    fgets(string, MAX, stdin);
    double n = atof(string);
    if (n < 0){
         puts (MENSAJE_NUMERO_NEGATIVO);
         return 1;
    }
    else{
        printf("%s %f\n", MENSAJE_RAIZ_CUADRADA, sqrt(n));
        return 0;
    }  
        
}