/*
3. Escribir un programa que se ejecute “$ ./convertir entrada” donde entrada es el nombre de un archivo
binario de personas que imprima por stdout cada una de las personas del archivo en formato CSV. Si el
programa se ejecutara “$ ./convertir --help” se debe imprimir una pequeña ayuda y terminar
*/

bool leer_persona(FILE *f, persona_t *p);
void escribir_persona(FILE *f, const persona_t *p);

int main (int argc, char * argv[]){
    if (argc > 2){
        fprintf (stderr, "Uso: %s [archivo] o Uso: %s --help\n", argv[0], argv[0]);
        return 1;
    }
    if (!strcmp(argv[1], "--help")){
        fprintf (stderr, "El programa recibe el nombre de un archivo binario de personas y luego imprime las personas por pantalla en formato CSV\n");
        return 0;
    }
    persona_t * p = malloc (sizeof(persona_t));
    if (p == 0) return 1;
    FILE * f = fopen(argv[1], "rb");
    if (f == NULL){
        free(p);
        return 1;
    }
    while (leer_persona(f, p)) escribir_persona(stdout, p);
    free(p);
    if (fclose(f)) return 1;
    return 0;
}


bool leer_persona(FILE *f, persona_t *p){
    size_t len;
    if (fread (&len, sizeof(size_t), 1, f) != 1) return false;
    if (len + 1 > MAX) return false;
    if (fread(p->nombre, sizeof(char), len, f) != len) return false;
    if (fread(p->dni, sizeof(unsigned int), 1, f) != 1) return false;
    if (fread(p->altura, sizeof(float), 1, f) != 1) return false;
    return true;
}

void escribir_persona(FILE *f, const persona_t *p){
    fprintf(f, "%s,%d,%f\n", p->nombre, p->dni, p->altura);
}