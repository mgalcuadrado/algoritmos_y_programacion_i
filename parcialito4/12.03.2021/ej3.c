/*
3. Escribir una función recursiva que reciba dos cadenas de caracteres y devuelva la cantidad de
veces que la segunda cadena aparece en la primera.
Por ejemplo, la cadena "ssi" se encuentra dos veces en la cadena "Mississippi".
(Ayuda: La función strncmp(const char *s1, const char *s2, size_t n); compara los pri-
meros n caracteres de s1 y s2.)
*/

size_t _cadena_en_cadena (const char * str, size_t slen const char * cad, size_t clen){
    if (slen < clen) return 0;
    size_t n = strncmp(str, cad, len);
    if (n == 0) return 1 + _cadena_en_cadena(str + 1, slen - 1, cad, clen);
    return _cadena_en_cadena(str - 1, slen - 1, cad, clen);
}

size_t cadena_en_cadena(const char * str, const char * cad){
    return _cadena_en_cadena(str, strlen(str), cad, strlen(cad));
}