/*
1. Teniendo representado el TDA lista de enteros como typedef struct {struct nodo *prim;} lista_t; y el nodo
struct nodo {struct nodo *sig; int dato;}; implementar una función
void unir_listas_ordenadas(lista_t *d, lista_t *o);
que reciba dos listas ordenadas d y o y que junte ambas listas en d. La lista resultante debe quedar ordenada y la lista o
debe quedar vacía.
(Nota: Sólo se puede recorrer las listas una única vez.)
*/

typedef struct {
    struct nodo *prim;
} lista_t;

struct nodo {
    struct nodo *sig;
    int dato;
};

void unir_listas_ordenadas(lista_t * d, lista_t * o){
    if (o->prim == NULL) return;
    if (d->prim == NULL){
        d->prim = o->prim;
        o->prim = NULL;
        return;
    }
    struct nodo * dact = d->prim, dant = d->prim, oact = o->prim;
    while (dact->sig != NULL && oact->sig != NULL){
        if (dact->dato < oact->dato){
            dant = dact;
            dact = dact->sig;
        }
        else if (dact->dato > oact->dato){
            //esto se explica bien en esta mini presentación que hice: https://docs.google.com/presentation/d/1LuU4lCz9aFyEj9zdVwtjcLiSE7lAygo8SPEIS8-K1-k/edit?usp=sharing
            struct nodo * oant = oact;
            oact = oact ->sig;
            oant->sig = dact;
            dant->sig = oant;
            dant = dant->sig;
        }
        else{
            dant = dact;
            dact = dact->sig;
            oact = oact->sig;
        }
    }
    if (dact == NULL){
        dact = oact;
        return;
    }
}
