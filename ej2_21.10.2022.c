int ** matriz_crear (size_t filas, size_t columnas){
    int ** p = malloc (filas * sizeof(int*));
    if (p == NULL) return NULL;
    *p = malloc ((filas * columnas) * sizeof(int));
    if (*p == NULL){
        free(p);
        return NULL;
    }
    for (size_t f = 1; f < filas; f++)
        p[f] = * p[f * columnas]; //ese puntero es ¡muy! importante
    return p;
}

void matriz_destruir (int **m, size_t filas, size_t columnas){
    free (*m);
    free(m);
}

