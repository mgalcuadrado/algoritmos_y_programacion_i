/*
1. Se quiere modelar un TDA que represente a un vector en Rn. Se pide:
a. Declarar la estructura vector_t que representa el TDA. Explicar qué modela cada uno de los miembros y sus
valores posibles (invariante).
b. Implementar la primitiva size_t vector_dimension(const vector_t *v); que retorne la dimensión ndel
vector.
c. Implementar la primitiva double vector_norma(const vector_t *v); que devuelve la norma del vector, ||v||.
d. Implementar la primitiva bool vector_sumar(vector_t *a, const vector_t *b); que sume b en a, si es que
son sumables. La función devuelve true si la operación pudo ser realizada.
*/

#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct vector{
    float * vect;
    size_t n;
    //arreglo dinámico de flotantes vect de longitud n
    // n = 0 <=> vect = NULL
}vector_t;


size_t vector_dimension(const vector_t *v){
    return v->n;
}

double vector_norma(const vector_t *v){
    double norma = 0;
    for (size_t i = 0; i < v->n; i++){
        norma += v->vect[i] * v->vect[i];
    }
    return sqrt(norma);
}

bool vector_sumar(vector_t *a, const vector_t *b){
    if (b->n != a->n) return false;
    for (size_t i = 0; i < b->n; i++){
        a->vect[i] += b->vect[i];
    }
    return true;
}
