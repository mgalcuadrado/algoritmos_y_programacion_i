/*
1. Se quiere modelar el TDA votación, el cual contiene una determinada cantidad de cadenas que representan las opciones
y los votos que tuvo cada opción. Se pide:
a. Declarar la estructura que encapsula el TDA. Explicar qué representa cada miembro y documentar el invariante de
representación.
b. Implementar la primitiva unsigned int votacion_votos_totales(const votacion_t *v); que devuelva la
cantidad de votos totales de todas las opciones.
c. Implementar la primitiva bool votacion_agregar_opcion(votacion_t *v, const char *opcion); que agre-
gue la opción a la lista de opciones.
*/

struct candidatos{
    char nombre[MAX_STR];
    size_t votos;
};

typedef struct votacion{
    struct candidatos * cand;
    size_t candidatos;
}votacion_t; 

typedef struct candidatos candidatos_t;

unsigned int votacion_votos_totales(const votacion_t *v){
    unsigned int total = 0;
    for (size_t i = 0; i < v->candidatos; i++){
        total += v->cand[i].votos;
    }
    return total;
}

bool votacion_agregar_opcion(votacion_t *v, const char *opcion){
    candidatos_t * aux = realloc(v->cand, sizeof(candidatos_t) * (v->candidatos + 1));
    if (aux == NULL) return false;
    v->cand = aux;
    strcpy (v->cand[v->candidatos].nombre, opcion);
    v->cand[v->candidatos++].votos = 0;
    return true;
}
