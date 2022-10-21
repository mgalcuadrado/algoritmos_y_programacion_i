/*
La tabla ASCII está diseñada para realizar determinadas 
operaciones de forma sencilla mediante manejo de bits.
Algunas de ellas son:
Todos los ASCIIs de números tienen la forma 0011xxxx 
donde xxxx corresponde a la representación binaria del número (por ejemplo, el ASCII 00110011 se corresponde al '3').
Todos los caracteres de control son de la forma 000xxxxx.
Utilizando operaciones de bits implementar las siguientes funciones:
bool es_control(char c); // Indica si un caracter es de control
bool es_numero(char c); // Indica si un caracter es numérico
int a_numero(char c); // Convierte `'0'-'9'` en `0-9`
Nota: Se permite utilizar comparaciones sobre los valores indicados con equis en los ejemplos. No se
permite resolver los ejercicios con operaciones de comparación sobre el ASCII completo (es decir, es_numero
puede incluir chequear xxxx < 10 pero no puede incluir c <= '9' o c <= 39.)
*/
#include <stdio.h>
#include <stdbool.h>

#define MASK_REP_NUMERO 0x30
#define MASK_VALOR_NUMERO 0x0F
#define MASK_CONTROL 0x00

#define SHIFT_CONTROL 5

bool es_control (char c){
    return (c >> SHIFT_CONTROL == MASK_CONTROL);
}
bool es_numero(char c){
    return ((c & MASK_REP_NUMERO) == MASK_REP_NUMERO);
}

int a_numero (char c){
    if (! es_numero(c)) return -1;
    return (MASK_VALOR_NUMERO & c);
}


int main (void){
    char a = '1', b = '\0', c = 'c', d = '4';
    printf ("%s es un caracter de control\n", es_control(c)? "c" : "c no");
    printf ("%s es un caracter de control\n", es_control(b)? "b" : "b no");
    printf ("%d \n", a_numero(b));
    printf ("%d \n", a_numero(a));
    printf ("%d \n", a_numero(d));
    return 0;
}

