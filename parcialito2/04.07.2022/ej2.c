/*
 *  a. Implementar una función
 * char **clonar_arreglo_cadenas(char *ss[]);
 * que reciba un arreglo de cadenas de caracteres ss el cual contiene cadenas en sus primeras posiciones y el centinela
 * NULL en su última posición y que devuelva una copia en memoria nueva de dicho arreglo.
 * b. Implementar una función
 * void destruir_arreglo_cadenas(char *ss[]);
 * que reciba un arreglo dinámico de cadenas dinámicas como el del ítem anterior y libere la memoria asociada a é
 */

//Si querés  escribirbmaenca uno es acá el problema  seguime
//hacete el archivito de errores!
void destruir_arreglo_cadenas(char *ss[]){
    for (size_t i = 0; ss[i] != NULL; i++)
        free (ss[i]);
    free (ss);
}

char **clonar_arreglo_cadenas(char *ss[]){
    size_t cant_cadenas = 0;
    while(ss[cant_cadenas] != NULL) cant_cadenas++;
    char ** p = malloc (cant_cadenas * sizeof(char*));
    if (p == NULL)
        return NULL;
    for (size_t i = 0; i < cant_cadenas; i++){
        p[i] = malloc ((strlen(ss[i]) + 1) * sizeof(char));
        if (p[i] != NULL){
            for (size_t j = 0; j < i; j++)
                free (p[j]);
            free (p);
            return NULL;
        }
        strcpy (p[i], ss[i]);
    }
    return p;
}
