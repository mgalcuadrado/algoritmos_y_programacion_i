/*
1. Teniendo un TDA lista enlazada genérica definido como
typedef struct { struct nodo *prim; } lista_t;
y su nodo como
struct nodo { struct nodo *sig; void *dato; };
implementar una primitiva
bool lista_esta_ordenada(const lista_t *l, int (*cmp)(const void *, const void *));
que indique si la lista está ordenada
*/

typedef struct {
    struct nodo *prim;
} lista_t;

struct nodo {
    struct nodo *sig;
    int dato;
};

bool lista_esta_ordenada(const lista_t *l, int (*cmp)(const void *, const void *)){
    if (l->prim == NULL || l->prim->sig == NULL) return true;
    struct nodo * actual = l->prim;
    while (actual->sig != NULL){
        struct nodo * sig = actual->sig;
        if (!cmp(actual->dato, sig->dato))
            return false; 
        actual = actual->sig; 
    }
    return true;
}