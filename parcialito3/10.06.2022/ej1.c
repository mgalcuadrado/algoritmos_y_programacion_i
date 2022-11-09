/*
Se quiere modelar el TDA polinomio, el cual representa a un polinomio de grado n dado por la ecuación 
a0 + a1 x + a2 x2 + . . . + an xn. Se pide:
a. Declarar la estructura que encapsula el TDA. Explicar qué representa cada miembro y documentar el invariante de
representación.
b. Implementar la primitiva size_t polinomio_grado(const polinomio_t *p) que devuelva el grado del polinomio.
c. Implementar la primitiva polinomio_t *polinomio_derivar(const polinomio_t *p); que dado un polinomio
p(x) retorne el polinomio p(x)
0
, su derivada. Puede asumir que se encuentra implementada la función static
polinomio_t *_polinomio_crear(size_t n); que crea un polinomio de grado n.
*/

typedef struct polinomio{
    float * arr;
    size_t elem;
    size_t grado;
}polinomio_t;

size_t polinomio_grado(const polinomio_t *p){
    return p->grado;
}

polinomio_t *polinomio_derivar(const polinomio_t *p){
    polinomio_t * der = _polinomio_crear(p->grado - 1);
    if (der == NULL) return NULL;
    for (size_t i = 0; i < p->elem - 1; i++){
        der->arr[i] = p->arr[i + 1] * (i + 1);
    }
    der->elem = p->elem - 1;
    der->grado = p->grado -1;
    return der;
}