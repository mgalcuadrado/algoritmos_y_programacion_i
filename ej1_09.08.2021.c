/*
La tabla ASCII está diseñada para realizar determinadas operaciones de forma sencilla mediante manejo
de bits.
Algunas de ellas son:
Todos los ASCIIs de números tienen la forma 0011xxxx donde xxxx corresponde a la representación
binaria del número (por ejemplo, el ASCII 00110011 se corresponde al '3').
Todas las mayúsculas son de la forma 010xxxxx donde xxxxx representa el número de letra (entre 1
y 26).
Todas las minúsculas son de la forma 011xxxxx donde xxxxx representa el número de letra (entre 1 y
26).
Todos los caracteres de control son de la forma 000xxxxx.
Utilizando operaciones de bits implementar las siguientes funciones:
bool es_control(char c); // Indica si un caracter es de control
bool es_numero(char c); // Indica si un caracter es numérico
bool es_minuscula(char c); // Indica si un caracter es minúscula
int a_numero(char c); // Convierte `'0'-'9'` en `0-9`
char a_mayusculas(char c); // Convierte una letra a mayúsculas
Nota: Se permite utilizar comparaciones sobre los valores indicados con equis en los ejemplos. No se
permite resolver los ejercicios con operaciones de comparación sobre el ASCII completo (es decir, es_numero
puede incluir chequear xxxx < 10 pero no puede incluir c <= '9' o c <= 39.
*/
#define MASK_NUMERO 0x30
#define MASK_VALOR_NUMERO 0x0F

#define MASK_MAYUS 0x40
#define MASK_CAPS 0x1F
#define MASK_MINUS 0x60

#define MASK_CONTROL 0x00
#define SHIFT_CONTROL 5

bool es_control (char c){
    return ((c >> SHIFT_CONTROL) == MASK_CONTROL);
}

bool es_numero (char c){
    return ((c & MASK_NUMERO) == MASK_NUMERO);
}

bool es_minuscula (char c){
    if ((c & MASK_CAPS) < 1 || (c & MASK_CAPS) > 26)
        return false;
    return ((c & MASK_MINUS) == MASK_MINUS);
}

bool es_mayuscula (char c){
    if ((c & MASK_CAPS) < 1 || (c & MASK_CAPS) > 26)
        return false;
    return ((c & MASK_MAYUS) == MASK_MAYUS);
}

int a_numero (char c){
    if (! es_numero(c)) return -1;
    return (c & MASK_VALOR_NUMERO);
}

char a_mayuscula (char c){
    if (! es_minuscula(c)) return c;
    return (c | MASK_MAYUS);
}
