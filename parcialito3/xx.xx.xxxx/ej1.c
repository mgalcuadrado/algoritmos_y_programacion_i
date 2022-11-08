/*
1. Se quiere modelar el TDA polinomio, el cual representa a un polinomio de grado n dado por la ecuación
a0 +a1 x +a2 x2 +. . . +anxn. Se pide:
a. Declarar la estructura que encapsula el TDA. Explicar qué representa cada uno de los miembros.
b. Implementar la primitiva double polinomio_evaluar(const polinomio_t *p, double x); que eva-
lúe el polimomio en la x dada.
c. Implementar la primitiva polinomio_t *polinomio_derivar(const polinomio_t *p); que dado un
polinomio p(x)retorne el polinomio p(x)′, su derivada. Puede asumir que se encuentra implementada
una primitiva privada del TDA static polinomio_t *_polinomio_crear(size_t n); que crea un
polinomio de grado n.
*/

typedef struct polinomio{
    double * coef;
    size_t elem;
    //coef es un arreglo dinámico de doubles de elem elementos donde se guardan los coeficientes del polinomio en orden ascendente
    //coef[0] = a0, coef[1] = a1, ...
    //inv de rep: elem = 0 <=> coef = NULL
    //el polinomio es de grado = elem - 1
}polinomio_t;

static polinomio_t *_polinomio_crear(size_t n); //crea polinomio de grado n

static double _mi_pow(double x, size_t n){
    double rta = 1;
    for (size_t i = 1; i < n; i++)
        rta *= x;
    return rta;
}

double polinomio_evaluar(const polinomio_t *p, double x){
    double rta = 0;
    for (size_t i = 0; i < p->elem; i++)
        rta += p->coef[i] * _mi_pow(x, i);
    return rta;
}

polinomio_t *polinomio_derivar(const polinomio_t *p){
    polinomio_t * n = _polinomio_crear(p->elem - 2);
    //el polinomio original es de grado elem - 1, por lo que este es de grado elem - 2 (y por ende va a tener elem - 1 elementos)
    for (size_t i = 0; i < elem - 1; i++){
        n->coef[i] = (i + 1) * n->coef[i + 1];
    }
    return n;
}