/*
1. Una palabra puede tener múltiples sinónimos. Se quiere modelar un TDA
sinónimos de palabra que permita almacenar la palabra y sus sinónimos.
Se pide:
a. Declarar la estructura que encapsula el TDA. Explicar qué representa
cada miembro y documentar el invariante de representación.
b. Implementar la primitiva size_t sinonimos_cantidad_sinonimos(const
sinonimos_t *s); que devuelva la cantidad de sinónimos que tiene
asociada la palabra.
c. Implementar la primitiva bool sinonimos_es_sinonimo(const
sinonimos_t *sinonimos, const sinonimos_t *palabra); que
diga si la palabra que representa palabra está contenida entre los
sinónimos de sinonimos.
Por ejemplo (palabra: sinónimos):
• Programar: Exponer, planificar, plantear, proyectar, sistematizar,
esquematizar, bosquejar.
• Exponer: Explicar, explanar, manifestar, referir, plantear, formular, afirmar, alegar, declarar, describir, razonar.
Entonces sinonimos_es_sinonimo(programar, exponer) ->
true y sinonimos_es_sinonimo(exponer, programar) -> false.
*/

typedef struct sinonimos{
    char * palabra[MAX_STR];
    size_t nsin;
    //palabra es un arreglo dinámico de nsin cadenas de longitud MAX_STR
    //en la primera posición del arreglo se guarda la palabra y en las demás posiciones los sinónimos
    //el arreglo apunta a NULL <=> nsin = 0 <=> no hay palabra 
}sinonimos_t;

size_t sinonimos_cantidad_sinonimos(const sinonimos_t *s){
    return s->nsin - 1;
}

bool sinonimos_es_sinonimo(const sinonimos_t *sinonimos, const sinonimos_t *palabra){
    for (size_t i = 0; i < sinonimos->nsin; i++){
        if (! strcmp (sinonimos->palabra[i], palabra->palabra[0])) return true;
    }
    return false;
}