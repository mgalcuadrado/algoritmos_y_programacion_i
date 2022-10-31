
/*
1. 
void subcadena(char destino[], const char origen[], size_t inicio, size_t fin);
que reciba una cadena de origen y extraiga de ella los elementos entre inicio (inclusivo) y fin (no
inclusivo) y los guarde como una cadena en destino. En el caso de que alguno de los índices se escape
del rango de origen se truncará al tamaño de la longitud. Siempre debe realizarse la operación, en el
peor de los casos, el resultado será una cadena vacía.
Por ejemplo subcadena(d, "Algoritmos", 2, 6) --> d = "gori"
No se permite el uso de funciones de biblioteca en este ejercicio. Todo lo necesario debe ser implementado.
b. Con un pequeño código de ejemplo mostrar cómo utilizar a la función con las cadenas del ejemplo
anterior.


#include <stdio.h>

#define MAX 100

void subcadena(char destino[], const char origen[], size_t inicio, size_t fin){
    size_t i, len;
    for (len = 0; origen[len] != '\0'; len++);
    
    if (inicio > len)
        inicio = len;
    if (fin > len)
        fin = len;

    for (i = inicio; i < fin && origen[i] != '\0'; i++){
        destino[i - inicio] = origen[i];
    }
    destino [i - inicio] = '\0';    
}

int main (void){
    char d[MAX];
    subcadena (d, "Algoritmos", 2, 6);
    for (size_t i = 0; d[i] != '\0'; i++)
        putchar (d[i]);
    putchar('\n');
    return 0; 
}

2. a. Escribir una función combinar_filas que reciba una matriz de flotantes de tamaño N×M, dos índices y
un multiplicador flotante. La función debe sumarle a la fila indicada por el primer índice los elementos
de la fila indicada por el segundo índice multiplicados por el multiplicador.
b. Teniendo #define N 3 y #define M 3 escribir un pequeño ejemplo de código que declare y defina una
matriz, y llame a la función del punto anterior.



// a y b deben ser menores que la cantidad de filas


#include <stdio.h>

#define N 3
#define M 3


void combinar_filas (size_t a, size_t b, size_t columnas, float matriz[][columnas], float multiplicador){
    for (size_t i = 0; i < columnas; i++)
        matriz[a][i] += matriz[b][i] * multiplicador;
}


int main (void){
    float m[N][M] ={
        {1, 0, 1},
        {1, 1, 1},
        {4, 5, 7},
    };
    combinar_filas(0, 1, M, m, 0.5);
    for (size_t i = 0; i < N; i++){
        for (size_t j = 0; j < M; j++)
            printf("%f \t", m[i][j]);
        putchar ('\n');
    }
    return 0;
}



3. Escribir un programa que reciba primero la cantidad de veces que se va a tirar el dado, después la cantidad
de repeticiones consecutivas de algún valor que indicarían que el dado está cargado y, finalmente, los valores
de los ensayos.
Si se detectara que un número se repitió esa cantidad consecutiva se debe interrumpir la carga e imprimir un
mensaje. Si se alcanzara la cantidad de ensayos se debe terminar el programa con un mensaje de que el dado
no estaba cargado. Si se ingresara un valor inválido el programa debe abortarse.
Por ejemplo, si se dice que van a hacerse 10 ensayos y que con 3 repeticiones el dado está cargado, la secuencia
[1, 1, 2, 6, 5, 4, 4, 2, 2, 1] terminaría correctamente, mientras que para la secuencia [1, 1, 2, 6, 5, 5, 5] se diría
que el dado está cargado.
*/


#define MENSAJE_DADO_INVALIDO "El dado solo puede tomar valores entre 1 y 6, y se ingresó un valor que no estaba en el rango."
#define MENSAJE_DADO_CARGADO "El dado se encuentra cargado D:"
#define MENSAJE_DADO_NO_CARGADO "El dado no se encuentra cargado :D"

int dado_esta_cargado (size_t ensayos, size_t repeticiones, size_t valores[ensayos]){
    size_t centinela = 1;
    for (size_t i = 0; i < ensayos - 1; i++){
        if (valores[i] < 1 || valores [i] > 6){
            puts (MENSAJE_DADO_INVALIDO);
            return -1;
        }

        if (valores[i] == valores[i + 1]){
            centinela++;
        }
        if (valores[i] != valores[i + 1]){
            centinela = 1;
        }
        if (centinela == repeticiones){
            puts (MENSAJE_DADO_CARGADO);
            return 1;
        }
    }
    if (valores[ensayos - 1] < 1 || valores [ensayos - 1] > 6){
        puts (MENSAJE_DADO_INVALIDO);
        return -1;
    }
    puts (MENSAJE_DADO_NO_CARGADO);
    return 0;
}

// dado cargado pero obteniendo de teclado los datos. 
#define MENSAJE_DADO_INVALIDO "El dado solo puede tomar valores entre 1 y 6, y se ingresó un valor que no estaba en el rango."
#define MENSAJE_DADO_CARGADO "El dado se encuentra cargado D:"
#define MENSAJE_DADO_NO_CARGADO "El dado no se encuentra cargado :D"


#define MAX_STRING 100
#define MENSAJE_DADO_INGRESAR_ENSAYOS "Ingrese el número de veces que se tirará el dado"
#define MENSAJE_DADO_INGRESAR_REPETICIONES "Ingrese el número de repeticiones máximas"
#define MENSAJE_DADO_INGRESAR_DADO "Ingrese el dado número "
int main (void){
    char auxiliar[MAX_STRING];
    size_t dado_anterior = 0, dado_actual, centinela = 1;
    puts(MENSAJE_DADO_INGRESAR_ENSAYOS);
    fgets (auxiliar, MAX_STRING, stdin);
    size_t ensayos = atoi(auxiliar);
    puts(MENSAJE_DADO_INGRESAR_REPETICIONES);
    fgets (auxiliar, MAX_STRING, stdin);
    size_t repeticiones = atoi(auxiliar); 
    for (size_t i = 0; i < ensayos; i++){
        printf ("%s %zd \n", MENSAJE_DADO_INGRESAR_DADO, i + 1);
        fgets (auxiliar, MAX_STRING, stdin);
        dado_actual = atoi(auxiliar);
        if (dado_actual < 1 || dado_actual > 6){
            puts (MENSAJE_DADO_INVALIDO);
            return -1;
        }
        if (dado_actual == dado_anterior)
            centinela++;
        if (dado_actual != dado_anterior)
            centinela = 1;
        if (centinela == repeticiones){
            puts (MENSAJE_DADO_CARGADO);
            return 1;
        }
        dado_anterior = dado_actual;
    }
    puts (MENSAJE_DADO_NO_CARGADO);
    return 0;
}