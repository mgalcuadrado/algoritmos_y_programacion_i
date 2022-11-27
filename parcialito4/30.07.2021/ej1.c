/*
1. Teniendo un TDA lista enlazada ordenada de enteros definido como
typedef struct {
struct nodo *prim;
} lista_ordenada_t;
y su nodo como
struct nodo {
struct nodo *sig;
int dato;
};
implementar una primitiva
bool lista_ordenada_completar(lista_ordenada_t *l);
que reciba una lista l y complete tanto los números faltantes como elimine los repetidos. Por
ejemplo, si la función recibe la lista [1, 3, 3, 4, 6] la misma debe quedar como [1, 2, 3,
4, 5, 6].
En caso de una falla de memoria interrumpir el procesamiento y devolver false, no hace falta
restaurar a l a su condición previa
*/

typedef struct {
    struct nodo *prim;
} lista_ordenada_t;

struct nodo {
    struct nodo *sig;
    int dato;
};

struct nodo * nodo_crear(int dato, struct nodo * prox){
    struct nodo * n = malloc (sizeof(struct nodo));
    if (n == NULL) return NULL;
    n->dato = dato;
    n->sig = prox;
}

void nodo_destruir(struct nodo * n){
    free(n);
}

bool lista_ordenada_completar(lista_ordenada_t *l){
    if (l->prim == NULL) return true;
    struct nodo * act = l->prim;
    while (act->sig != NULL){
        struct nodo * sig = act->sig;
        if (act-> dato + 1 < sig->dato){
            struct nodo * nuevo = nodo_crear(act->dato + 1, sig);
            if (nuevo == NULL) return false;
            act->sig = nuevo;
            act = nuevo;
        }
        else if (act->dato == sig->dato){
            act->sig = sig->sig;
            nodo_destruir(sig);
        }
        else /*if (act->dato + 1 == sig->dato)*/ 
            //no puede ser mayor porque está ordenada
            act = sig;
    }
    return true;
}
