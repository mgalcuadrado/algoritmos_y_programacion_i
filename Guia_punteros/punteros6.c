#include <stdio.h>

void swap (int * a, int * b);

int main (void){
    int uno = 1, dos = 2;
    swap (&uno, &dos);
    printf ("%d %d \n", uno, dos);
    return 0;
}

void swap (int * a, int * b){
    int aux = *a;
    *a = *b;
    *b = aux;
}