/*
2. Se tiene una estructura que representa a una persona como typedef struct { char nombre[MAX];
unsigned int dni; float altura; } persona_t; se pide:
a. Escribir una función bool leer_persona(FILE *f, persona_t *p); que lea una persona del archivo
binario f y la guarde en la estructura p. La función debe devoler false de no poder realizar la operación.
b. Escribir una función void escribir_persona(FILE *f, const persona_t *p); que dado un archivo
de texto f escriba en él a la persona p en formato CSV “nombre;dni;altura”.
c. Escribir una función bool leer_personas(const char *r, persona_t v[], size_t max, size_t
*n); que reciba una ruta a un archivo binario r y un vector v de max elementos y cargue en él todas
las estructuras contenidas en el archivo hasta el máximo. La función debe retornar por n la cantidad de
estructuras leidas y false en caso de falla
*/

typedef struct {
    char nombre[MAX];
    unsigned int dni; 
    float altura; 
} persona_t;

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

bool leer_personas (const char *r, persona_t v[], size_t max, size_t *n){
    FILE * f = fopen(r, "rb");
    if (f == NULL) return false;
    for ((*n) = 0; (*n) < max  && leer_persona(f, &v[*n]); (*n)++);
    ((*n) != max - 1) ? return false : return true;
}