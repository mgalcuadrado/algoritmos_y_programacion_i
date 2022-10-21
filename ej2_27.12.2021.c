/* Se tiene una estructura:
struct persona {
    char *nombre, *apellido;
    int DNI;
};
a. Escribir una función:
struct persona *clonar_persona(const struct persona *p);
que devueva una copia de p en memoria nueva o NULL en caso de falla.
b. Escribir una función:
void destruir_persona(struct persona *p);
que elimine la memoria asociada a una persona.
*/

struct persona {
    char *nombre, *apellido;
    int DNI;
};

struct persona *clonar_persona(const struct persona *p){
    struct persona * clon = malloc (sizeof(struct persona));
    if (clon == NULL)
        return NULL;
    clon->nombre = malloc (sizeof(char) * (strlen(p->nombre) + 1));
    if (clon->nombre == NULL){
        free (clon);
        return NULL;
    }
    clon->apellido = malloc (sizeof(char) * (strlen(p->apellido) + 1));
    if (clon->apellido == NULL){
        free (clon->nombre);
        free (clon);
        return NULL;
    }
    clon->DNI = p->DNI;
    return clon;
}

void destruir_persona(struct persona *p){
    free (p->nombre);
    free (p->apellido);
    free (p);
}
