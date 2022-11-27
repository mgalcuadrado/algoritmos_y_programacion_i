/*
2. Se sabe que la combinación de enfermedades aumenta los riesgos de mortalidad ante el COVID-19.
Se tiene un listado ordenado alfabéticamente de afectados por enfermedades cardíacas y otro
listado, también ordenado alfabéticamente, de afectados por hipertensión.
Implementar una función
char **pacientes_prioritarios(char *cardiacos[], size_t n_cardiacos,
char *hipertensos[], size_t n_hipertensos, size_t *n_prioritarios);
que reciba dos listados, el de los n_cardiacos ciudadanos cardiacos y el de los n_hipertensos
ciudadanos hipertensos y devuelva el listado de los ciudadanos con ambas afecciones por el
nombre y la cantidad en n_prioritarios.
Se debe devolver un arreglo de cadenas con los nombres. Ahora bien, no hace falta pedir memoria
para cada una de las cadenas, bien puede apuntarse a los nombres ya recibidos en cardiacos o
en hipertensos.
*/

char **pacientes_prioritarios(char *cardiacos[], size_t n_cardiacos,
char *hipertensos[], size_t n_hipertensos, size_t *n_prioritarios){
    char ** vip = malloc (sizeof(char *) * (n_cardiacos < n_hipertensos ? n_cardiacos : n_hipertensos)) ;
    if (vip == NULL) return NULL;

    size_t c = 0, h = 0; *n_prioritarios = 0;
    while (c < n_cardiacos && h < n_hipertensos){
        int cmp = strcmp(cardiacos[c], hipertensos[h]);
        if (cmp == 0){
            vip[(*n_prioritarios)++] = cardiacos[c++];
            h++;
        }
        (cmp < 0) ? c++ : h++;
    }
    return vip;
}