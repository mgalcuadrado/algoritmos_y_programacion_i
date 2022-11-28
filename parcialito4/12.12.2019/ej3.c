/*
3. Escribir una función bool esta_ordenado(float v[], size_t n); que utilizando recursividad 
indique si un vector v de n elementos se encuentra ordenado o no.
*/

bool esta_ordenado (float v[], size_t n){
    if (n == 1) return true;
    if (v[0] > v[1]) return false;
    return esta_ordenado(v + 1, n - 1);
}