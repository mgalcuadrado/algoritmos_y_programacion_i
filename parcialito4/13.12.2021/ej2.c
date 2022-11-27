/*
2. Se pide implementar una función
int arreglo_reducir(const int arreglo[], size_t n, int (*f)(int a, int b));
que reciba un arreglo de n enteros y le aplique, de a pares, la función f a sus 
elementos y al resultado de la operación.
Si el arreglo tuviera sólo un elemento se debe devolver ese elemento, si tuviera más
de uno, el resultado se originará de la función f.
Ejemplo, si el arreglo fuera {1, 2, 4, 6} y f fuera la suma se debería devolver 13; 
en cambio si f fuera el producto se debería devolver 48.
*/

int arreglo_reducir(const int arreglo[], size_t n, int (*f)(int a, int b)){
    if (n == 1) return arreglo[0];
    int i, r = arreglo[0];
    for (i = 1; i < n; i += 1){
        int p = f(r, arreglo[i]);
    }
    return r;
}