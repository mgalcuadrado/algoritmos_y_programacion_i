/*
2. En un país hipotético el gobierno se dio cuenta de que puede redefinir de forma automática sus políticas de subsidios a
los servicios cruzando listados de diferentes organismos. Se tiene un listado ordenado por número de DNI de todos los
titulares de servicios y se tiene otro listado, también ordenado por DNI, que tiene a todas las personas que cobran más
de $350.000 al mes. Implementar una función:
int *mantienen_subsidio(int titulares[], size_t n_titulares, int salarios_altos[],
size_t n_salarios_altos, size_t *n_mantienen);
que reciba un vector con los n_titulares titulares de servicios, otro vector con los n_salarios_altos
salarios_altos personas de altos ingreso, compute de forma eficiente y luego devuelva un vector con los
n_mantienen que mantienen su subsidio.
*/

int *mantienen_subsidio(int titulares[], size_t n_titulares, int salarios_altos[],
size_t n_salarios_altos, size_t *n_mantienen){
    int * sub = malloc (sizeof(int) * n_titulares);
    if (sub == NULL) return NULL; //O titulares si no le importa perder plata al estado
    size_t t = 0, a = 0, *n_mantienen = 0;
    while (t < n_titulares && a < n_salarios_altos){
        if (titulares[t] < salarios_altos[a]){
            sub[(*n_mantienen)++] = titulares[t++];
        }
        else if (titulares[t] == salarios_altos[a]){
            t++; a++;
        }
        else /*if (titulares[t] > salarios_altos)*/
            a++;
    }
    while (t < n_titulares)
        sub[(*n_mantienen)++] = titulares[t++];
    
    return sub;
}
