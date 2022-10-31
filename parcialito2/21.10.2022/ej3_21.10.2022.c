char * leer_palabra(){
    int c;
    char * s = malloc (INIT_SIZE * sizeof(char));
    if (s == NULL) return NULL;
    size_t size = INIT_SIZE, pos = 0;
    while (isalnum(c = getchar())){
        if ((pos + 1) == size){
            size *= MULT;
            char * aux = realloc (s, size * sizeof(char));
            if (aux == NULL){
                free(s);
                return NULL;
            }
            s = aux;
        }
        s[pos++] = c;
    }
    s[pos] = '\0';
    return s;
}