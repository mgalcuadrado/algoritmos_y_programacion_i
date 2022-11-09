/*
1. Se quiere modelar un TDA que represente una recta en R2. Se pide:
a. Declarar la estructura recta_t que representa al TDA. Explicar qué modela cada uno de los miembros y sus
valores posibles.
b. Implementar la primitiva bool recta_x_en_rango(const recta_t *r, float x); que indique si la coordenada
x está entre los extremos de la recta.
c. Implementar la primitiva bool recta_agregar_punto(recta_t *r, float x, float y); que agrega un punto
a la recta.
*/

#include <stdbool.h>

typedef struct punto{
    float x, y;
}punto_t;

typedef struct recta{
    punto_t i, f;
}recta_t;

bool recta_x_en_rango(const recta_t *r, float x){
    return (x >= r->i.x && x <= r->f.x);
}

bool recta_agregar_punto(recta_t *r, float x, float y){
    float m = (r->f.y - r->i.y) / (r->f.x - r->i.x), b = r->f.y - m * r->f.x;
    if ((m * x + b) != y) return false;
    if (x < r->i.x){
        r->i.x = x;
        r->i.x = y;
    }
    if (x > r->f.x){
        r->f.x = x;
        r->f.x = y;
    }
    return true;
}