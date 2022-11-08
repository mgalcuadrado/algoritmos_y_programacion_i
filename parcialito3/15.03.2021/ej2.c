/*
2. Se tiene un producto definido como
typedef struct {
unsigned int id;
char nombre[MAX_NOMBRE];
float precio;
} producto_t;

a. Escribir una función bool escribir_producto_csv(const producto_t *p, FILE *f); que dado un producto p y un 
archivo f vuelque el producto en una línea de archivo de texto en formato CSV.
b. Escribir una función bool leer_productos(const char *r, producto_t ps[], size_t max, size_t *n); 
que reciba una ruta r y un vector ps con max productos. El archivo guardado en r
contiene el volcado binario de n estructuras de tipo producto_t. Se deben leer todos los productos del archivo 
hasta un máximo max y guardarlos en ps. Se debe devolver por n la cantidad de productos leídos 
y por el nombre false en caso de falla (que el archivo no contuviera ningún producto o que hubiera 
menos de max productos no es una falla) o true de haber podido realizar la operación.
El archivo binario es tan sólo una sucesión de productos:
+----+----+----+----+- -+----+
| p1 | p2 | p3 | p4 | ... | pn |
+----+----+----+----+- -+----+

*/

typedef struct{
unsigned int id;
char nombre[MAX_NOMBRE];
float precio;
} producto_t;

bool escribir_producto_csv(const producto_t *p, FILE *f){
    if (p == NULL) return false;
    fprintf(f, "%d%s," strlen(p->nombre), p->nombre);
    fprintf(f, "%d,%f\n", p->id, p->precio);
    return true;
}

bool leer_productos(const char *r, producto_t ps[], size_t max, size_t *n){
    FILE * f = fopen(r, "rb");
    if (f == NULL) return false;
    for (*n = 0; *n < max; (*n)++){
        size_t len;
        if (fread(&len, sizeof(size_t), 1, f) != 1) return true;
        if (fread(ps[*n].nombre, sizeof(char), len, f)) return false;
        ps[*n].nombre[len] = '\0';
        if (fread(&ps[*n].id, sizeof(unsigned int), 1, f) != 1) return false;
        if (fread(&ps[*n].precio, sizeof(float), 1, f) != 1) return false;
    }
    if (fclose(f)) return false;
    return true;
}
