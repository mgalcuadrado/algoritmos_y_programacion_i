/*
1. Teniendo un TDA lista enlazada de enteros definido como
typedef struct {
struct nodo *prim;
} lista_t;
y su nodo como
struct nodo {
struct nodo *sig;
int dato;
};
y además teniendo ya implementada la primitiva void lista_destruir(lista_t *l); imple-
mentar una primitiva
lista_t *lista_clonar(const lista_t *l);
que reciba una lista l y devuelva una copia idéntica de la misma en memoria nueva.
*/

typedef struct {
    struct nodo *prim;
} lista_t;

struct nodo {
    struct nodo *sig;
    int dato;
};

lista_t *lista_clonar(const lista_t *l){
    lista_t * list = malloc (sizeof(lista_t));
    if (list == NULL) return NULL;
    list->prim == NULL;
    if (l->prim == NULL) return list;
    struct nodo * act = l->prim, nant = NULL;
    while (act != NULL){
        struct nodo * n = nodo_crear(act->dato, NULL);
        if (n == NULL){
            lista_destruir(list);
            return NULL;
        }
        if (nant == NULL){
            list->prim = n;
        }
        nant->sig = n;
        nant = n;
        act = act->sig;
    }

    return list;

}