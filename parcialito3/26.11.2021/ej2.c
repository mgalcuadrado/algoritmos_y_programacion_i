/*
2. Se tiene un archivo binario en el cual se escribieron cadenas de caracteres de longitud variable como una
secuencia de size_t que dicen el largo n de la próxima cadena y luego una secuencia de n caracteres, por
ejemplo
+----+-----+-----+----+-----+----+-----+-----+
| 2 | '9' | '5' | 1 | '.' | 2 | '1' | '1' |
+----+-----+-----+----+-----+----+-----+-----+
para un archivo que contiene las cadenas {"95", ".", "11"}.
Se pide escribir una función char *leer_cadena(FILE *f); que dado un archivo ya abierto en modo de
lectura binaria lea una cadena. Si el archivo se hubiera terminado debe devolver la cadena vacía. Si hubiera
alguna falla debe devolver NULL.
*/

char * leer_cadena(FILE * f){
    size_t caracteres;
    if (fread (&caracteres, sizeof(size_t), 1, f) != 1) return "\0";
    char * cadena = malloc (sizeof(char) * (caracteres + 1));
    if (cadena == NULL) return NULL;
    if (fread(cadena; sizeof(char), caracteres, f) != caracteres){
        free(cadena);
        return NULL;
    }
    cadena[caracteres] = '\0';
    return cadena; 
}