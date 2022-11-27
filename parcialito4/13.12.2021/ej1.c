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
bool lista_ordenada_insertar(lista_ordenada_t *l, int dato);
que inserte el dato en la lista l.
*/

typedef struct {
    struct nodo *prim;
} lista_ordenada_t;

struct nodo {
    struct nodo *sig;
    int dato;
};


//se aconseja no confiar demasiado en esta resolución
bool lista_ordenada_insertar(lista_ordenada_t *l, int dato){
    struct nodo * n = nodo_crear(dato, NULL);
    if (n == NULL) return false;
    if (l->prim == NULL  || l->prim->dato > dato){
        n->sig = l->prim;
        l->prim = n;
        return true;
    }
    struct nodo * actual = l->prim, prox = actual->sig;
    while (prox != NULL){
        if (prox->dato >= n->dato){
            struct nodo * ref = prox;
            actual->sig = n;
            n->sig = ref;
            return true;
        }
        if (prox->dato < n->dato){
            actual = prox;
            prox = actual->sig;
        }
    }
    actual->sig = n;
    return true;
}