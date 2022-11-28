/*1. Teniendo una lista de enteros en la cual la lista se representa typedef struct {struct nodo *prim;} lista_t; y
el nodo se representa como struct nodo {struct nodo *sig; int dato;}; implementar la primitiva
void lista_enteros_borrar(lista_t *l, int e);
que borre todas las ocurrencias del dato e en la lista */

void lista_enteros_borrar(lista_t *l, int e){
    if (l->prim == NULL) return;
    struct nodo * ant = l->prim;
    struct nodo * act = l->prim;
    struct nodo * sig = l-prim->sig;
    while (sig != NULL){
        if (act->dato == e){
            ant->sig = sig;
            nodo_destruir(act);
            act = sig;
            sig = sig->sig;
        }
        else{
            ant = act;
            act = sig;
            sig = sig->sig;
        }
    }
}