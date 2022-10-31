#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX 100

/* 

//EJ5
const char str[] = {"Winter is coming"};
const char str[] = {'W', 'i', 'n', 't', 'e', 'r', ' ', 'i', 's', ' ', 'c', 'o', 'm', 'i', 'n', 'g'};
const char str[] = {[0] = 'W', [1] = 'i', [2] = 'n', [3] = 't', [4] = 'e', [5] = 'r', [6] = ' ', [7] = 'i', [8] = 's', [9] = ' ', [10] = 'c', [11] = 'o', [12] = 'm', [13] ='i', [14] = 'n', [15] = 'g'};

*/

//EJS 7-8

int main (void){
    char string[MAX];
    puts ("Ingrese una cadena de caracteres:");
    fgets (string, MAX, stdin);
    size_t i;
    for (i = 0; string[i] != '\0'; i++){
        fprintf (stdout, "%zd \t %c \t %d \n", i, string[i], string[i]);
    }
    fprintf (stdout, "%zd \t %c \t %d \n", i, string[i], string[i]);

    return 0;
}



//EJ9 ctype.h
//Este ejercicio hubiese quedado MUCHO MEJOR con un arreglo de funciones pero en su momento no se me ocurrió

void analizar_cadenas_ctype (const char cadena);
int main(void){
    const char[9][10]{
        {[0][3] = 'i'},
        {for (size_t i = 0; i < 10; i++)
            [1][i] = 'i';
        [1][3] = 's'},
        
    };
    char string[MAX];
    fgets (string, MAX, stdin);
    for (size_t i = 0; string[i] != '\0'; i++){
        printf ("%c\t", string[i]);
        isdigit(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        isalpha(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        isalnum(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        isxdigit(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        islower(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        isupper(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        isspace(string[i])  ? putchar('*') : putchar(' ');
        putchar('\t');
        iscntrl(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        ispunct(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        isprint(string[i]) ? putchar('*') : putchar(' ');
        putchar('\t');
        isgraph(string[i]) ? putchar('*') : putchar(' ');
        putchar('\n');
    }
}



//EJ10 Cadena vacía

bool cadena_vacia (const char * string){
    return (string[0] == '\0');
}

