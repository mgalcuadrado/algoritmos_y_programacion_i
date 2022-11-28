/*
1. Teniendo representado el TDA lista genérica como typedef struct {struct nodo *prim;} lista_t; y el nodo
struct nodo {struct nodo *sig; void *dato;}; implementar una función
lista_t *lista_filtrar(lista_t *l, bool (*f)(void *));
que retorne una nueva lista que contenga todos los elementos de l donde la función f aplicada al dato devuelva true.
Los elementos deben ser retirados de la lista l*/

//difícil este amigo

lista_t *lista_filtrar(lista_t *l, bool (*f)(void *)){
    lista_t * p = lista_crear();
    if (p == NULL) return NULL;
    if (l->prim == NULL) return NULL; //??
    struct nodo * pact = NULL;

    while (l->prim != NULL && f(l->prim->dato)){
        struct nodo * actual = l->prim;
        l->prim = actual->sig;
        if (pact == NULL){
            p->prim = actual;
        }
        else{
            pact->sig = actual;
        }
        pact = actual;
    }   

    if (l->prim == NULL) return p;
    struct nodo * ant = l->prim;
    while  (ant->sig != NULL){
        struct nodo * act = ant->sig;
        if (f(act->dato)){
            ant = act->sig;
            if (pact == NULL){
                pact = act;
            }
            else pact->sig = act;
            pact = act;
        }
        else{
            ant = act;
        }
    }
    return p;
}

