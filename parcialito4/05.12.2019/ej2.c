/*
2. En las elecciones del Centro de Estudiantes se abren urnas en Paseo Colón y en Las Heras con el mismo padrón. Se
tiene un vector con todos los padrones que votaron en PC y otro con todos los padrones que votaron en LH ambos
ordenados por número de padrón creciente. Escribir una función:
int *detectar_duplicados(const int pc[], size_t n_pc, const int lh[], size_t n_lh, size_t *n_dup);
que, de forma eficiente, calcule y devuelva un vector con los padrones que duplicaron su voto en ambas sedes. Debe
devolver en n_dup el tamaño del vector resultante. (Nota: No importa si sobra memoria en el vector.)
*/

int *detectar_duplicados(const int pc[], size_t n_pc, const int lh[], size_t n_lh, size_t *n_dup){
    int * dups = malloc (sizeof(int) * (n_pc < n_lh ? n_pc : n_lh));
    if (dups == NULL) return NULL;
    size_t p = 0, l = 0; *n_dups = 0;
    while (p < n_pc && l < n_lh){
        if (pc[p] == lh[l]){
            dups[(*n_dups)++] = pc[p++];
            l++;
        }
        if (pc[p] < lh[l]){
            p++;
        }
        else l++;
    }
    return dups;
}