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
    struct nodo * dact = d->prim, oact = o->prim;
    while (dact->sig != NULL && oact->sig != NULL){
        if (dact->dato < oact->dato){
            dact = dact->sig;
        }
        else if (dact->dato > oact->dato){
            struct nodo * oant = oact;
            oact = oact ->sig;
            oant->sig = dact->sig;
            dact->sig = oant;
            dact = oant->sig;
        }
        else{
            dact = dact->sig;
            oact = oact->sig;
        }
    }
    if (dact->sig == NULL){
        dact->sig = oact;
    }
}
