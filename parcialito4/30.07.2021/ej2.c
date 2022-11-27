/*
2. Implementar una función
void filtrar(void *v[], size_t *n, bool (*evaluar)(void *),
void (*eliminar)(void *));
que reciba un vector v de *n elementos y que elimine del vector todos los elementos sobre los
cuales la función evaluar devuelva true, cada elemento se destruye con eliminar. Al finalizar
la operación el vector debe contener sólo los elementos no eliminados y debe actualizarse la nueva
longitud.
*/


void filtrar(void *v[], size_t *n, bool (*evaluar)(void *),
void (*eliminar)(void *)){
    for (size_t i = 0; i < *n; i++){
        if (evaluar(v[i])){
            eliminar(v[i]);
            v[i--] = v[--(*n)];
        }
    }
}