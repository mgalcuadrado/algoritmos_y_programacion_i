/*
1. Se quiere modelar un TDA que sirva para que un restaurant lleve el pedido de cada una de las mesas. Los
comensales durante su estadía van pidiendo diferentes ítems que se van consignando en el pedido. Se pide:
a. Declarar la estructura que encapsula el TDA pedido_t que representa el pedido de una mesa particular.
Explicar qué representa cada miembro y documentar el invariante de representación.
b. Implementar la primitiva size_t pedido_cantidad(const pedido_t *p, const char *item);
que dado el nombre de un item indique cuántas unidades del mismo se pidieron en el pedido p.
c. Implementar la primitiva bool pedido_agregar(pedido_t *p, const char *item); que agregue
un item al pedido p. La función debe devolver true de poder realizar la operación.
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define INIT_SIZE 5
#define MAX_STRING 50
//a 

struct item{
    //item contiene una cadena de longitud MAX_STRING para el nombre del item y una variable para almacenar la cantidad de elementos pedidos de ese ítem
    //inv de rep: siempre que se crea nombre es una cadena vacía y la cantidad es cero
    char nombre[MAX_STRING];
    size_t cantidad;
};

typedef struct item item_t;

struct pedido{
    //pedido contiene un arreglo dinámico de ítems i, una cantidad de ítems pedidos y una variable cantidad 
    //para almacenar la capacidad de elementos del arreglo pedidos con memoria
    //inv de rep: el arreglo siempre tiene pedido al menos un elemento
    size_t items_pedidos, capacidad;
    struct item * i;

};

typedef struct pedido pedido_t;

//b.

size_t pedido_cantidad(const pedido_t *p, const char *item){
    for (size_t n = 0; n < p->items_pedidos; n++){
        if (! strcmp (p->i[n].nombre, item))
            return p->i[n].cantidad;
    }
    return 0;
}

bool pedido_agregar(pedido_t *p, const char *item){
    for (size_t n = 0; n < p->items_pedidos; n++){
        if (! strcmp (p->i[n].nombre, item)){
            p->i[n].cantidad++;
            return true;
        }
    }
    if (p->capacidad == p->items_pedidos + 1)
        //realloc de memoria
    strcpy(p->i[p->items_pedidos].nombre, item);
    p->i[p->items_pedidos].cantidad++;
    p->items_pedidos++,                ;
    return true;
}

void inicializar_item_n(item_t * it, size_t n){
    strcpy("\0", it[n].nombre);
    it[n].cantidad = 0;
}

