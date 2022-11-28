/*
3. Implementar una función float sumar_elementos(float v[], size_t n); que utilizando recursividad calcule la
suma de los elementos de un vector v de n flotantes.
*/

float sumar_elementos(float v[], size_t n){
    if (n == 1) return v[0];
    float izq = sumar_elementos(v, n/2);
    float der = sumar_elementos(v + n/2, n - n/2);
    return izq + der;
}