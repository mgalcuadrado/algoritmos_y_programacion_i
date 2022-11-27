/*
3. Se desea saber si una cadena contiene los caracteres de otra cadena patrón de forma ordenada (pero no 
necesariamente consecutiva). Implementar una función:
bool cadena_contiene(const char *cadena, const char *patron);
que usando recursividad indique si la cadena patron se encuentra intercalada en la cadena cadena.
Por ejemplo: cadena_contiene("anticonstitucional", "tonto") -> true, cadena_contiene("hola", "ola")
-> true, cadena_contiene("ballena", "llenaba") -> false
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_CADENA 30

bool cadena_contiene(const char *cadena, const char *patron){
    if (patron[0] == '\0') return true;
    if (cadena[0] == '\0') return false; //queda implícito el && patron[0] != '\0' por el if anterior
    return cadena_contiene(cadena + 1, patron + ((cadena[0] == patron[0]) ? 1 : 0));
}


int main (void){
    const char cad[MAX_CADENA] = "periodica";
    const char pat[MAX_CADENA] = "roca";
    const char otra[MAX_CADENA] = "ostra";
    fprintf(stdout, "la cadena %s%scontiene el patrón %s\n", cad, cadena_contiene(cad, pat) ? " sí " : " no ", pat);
    fprintf(stdout, "la cadena %s%scontiene el patrón %s\n", cad, cadena_contiene(cad, otra) ? " sí " : " no ", otra);
    return 0;
}