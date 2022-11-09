/*1. Luego del bochorno de las elecciones del 2015 la AFA quiere establecer un sistema de votación digital. En
estas elecciones no hay candidatos postulados sino que cada uno de los asambleístas presentes vota por
quien él considera apropiado.
Se pide modelar el TDA votación que permita llevar adelante la elección. Se pide:
a. Declarar la estructura que encapsula el TDA. Explicar qué representa cada miembro y documentar el
invariante de representación.
b. Implementar la primitiva char *votacion_ganador(const votacion_t *v); que devuelva el nombre del ganador de la elección.
(Como la cantidad de asambleístas es impar no puede haber un empate. . . o sí puede, pero en el caso
de empate devolver cualquiera de los ganadores.)
c. Implementar la primitiva bool votacion_votar(votacion_t *v, const char *nombre); que emita un sufragio a favor de la persona identificada con el nombre dado.
*/

struct candidatos{
    char nombre[MAX_STR];
    size_t votos;
};
//votados contiene el nombre del cantidado y la cantidad de votos que recibió
//si el nombre está inicializado sus votos asociados son al menos 1

typedef struct votacion{
    struct candidatos * c;
    size_t l;
    //votacion contiene un arreglo de struct votados de longitud l
    //INV DE REP= l = 0 <=> v = NULL
}votacion_t;

typedef struct candidatos candidatos_t;

char *votacion_ganador(const votacion_t *v){
    size_t pmax = 0;
    for (size_t pos = 1; pos < v->l; pos++){
        if (v->c[pos].votos > v->c[pmax].votos)
            pmax = pos;
    }
    return v->c[pmax].nombre;
}

bool votacion_votar(votacion_t *v, const char *nombre){
    for (size_t i = 0; i < v->l; i++){
        if (! strcmp(nombre, v->c[i].nombre))
            v->c[i].votos++;
    }
    candidatos_t * aux = realloc(v->c, (l + 1) * sizeof(candidatos_t));
    if (aux == NULL) return false;
    v->c = aux;
    strcpy(v->c[l].nombre, nombre);
    v->c[l++].votos = 1;
    return true;
}



