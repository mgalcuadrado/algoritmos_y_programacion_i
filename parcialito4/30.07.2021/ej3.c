/*
3. Implementar una función recursiva
size_t buscar(const int v[], size_t n, int elem);
que dado un vector v de longitud n devuelva la posición del vector en
la cual se encuentra el
elemento elem. Si elem no se encontrara en v se debe devolver n
*/

size_t buscar(const int v[], size_t n, int elem){
    if (n == 0) return 0;
    if (v[0] == elem) return 0;
    return 1 + buscar(v + 1, n - 1, elem);
}
