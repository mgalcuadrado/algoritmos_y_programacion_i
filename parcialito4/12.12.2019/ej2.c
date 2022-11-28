/*
2. Para un evento que duró 2 días se tienen dos vectores que cada uno de ellos 
contiene los DNIs de los asistentes al primero y al segundo día ordenados 
por número de DNI. Se quiere obtener una lista con los asistentes únicos al evento,
es decir, una lista que consolide los asistentes de los dos días sin duplicados. 
Escribir una función: int *consolidar_asistentes(const int dia1[], size_t n1, 
const int dia2[], size_t n2, size_t *n_asis);
que, de forma eficiente, consolide y 
devuelva un vector con los DNIs de los asistentes. 
Debe devolver en n_asis el tamaño del vector resultante. 
(Nota: No importa si sobra memoria en el vector.)
*/

int *consolidar_asistentes(const int dia1[], size_t n1, 
const int dia2[], size_t n2, size_t *n_asis){
    int * asis = malloc(sizeof(int) * (n1 + n2));
    if (asis == NULL) return NULL;
    size_t uno = 0, dos = 0, *n_asis = 0;
    while (uno < n1 && dos < n2){
        if (dia1[uno] < dia2[dos]){
            asis[(*n_asis)++] = dia1[uno++];
        }
        else if (dia1[uno] == dia2[dos]){
            asis[(*n_asis)++] = dia1[uno++];
            dos++;
        }
        else /* if (dia1[uno] > dia2[dos])*/{
            asis[(*n_asis)++] = dia2[dos++];
        }
    }
    //solo va a entrar a uno de los whiles de acá abajo
    while (uno < n1){
        asis[(*n_asis)++] = dia1[uno++];
    }
    while (dos < n2){
        asis[(*n_asis)++] = dia2[dos++];
    }
    return asis;
}