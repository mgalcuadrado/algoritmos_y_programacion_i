#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define CANT_OPCIONES 3


typedef enum{
    l,
    w,
    c
}prefijo_t;

typedef struct{
    prefijo_t prefijo;
    char cadena[4];
    bool vino; //de prepo en false
    int valor;
}opcion_t;

int main (int argc, char * argv[]){
    if (argc < 3){
        fprintf(stderr, "Uso: %s [opcion1] ... [opcionn] [archivo1] ... [archivon]\n", argv[0]);
        return 1;
    }
    opcion_t opciones[CANT_OPCIONES] = {
        {l, "-l", false, 0},
        {w, "-w", false, 0},
        {c, "-c", false, 0},
    };

    size_t ultimo_prefijo;
    for (size_t i = 1; i < argc; i++){
        for (size_t j = 0; j < CANT_OPCIONES; j++){
            if (! strcmp(opciones[j].cadena, argv[i])){
                opciones[j].vino = true;
                ultimo_prefijo = i;
            }
        }
    }
    int lec;
    for (ultimo_prefijo += 1; ultimo_prefijo < argc; ultimo_prefijo++){
        FILE * f = fopen(argv[ultimo_prefijo], "rb");
        if (f == NULL) return 1;
        while ((lec = fgetc(f)) != EOF){
            opciones[c].valor ++;
            if (lec == '\n' && opciones[l].vino) opciones[l].valor ++;
            if (isspace(lec) && opciones[w].vino) opciones[w].valor ++;
        }
        if (fclose(f)) return 1;
        for (size_t j = 0; j < CANT_OPCIONES; j++){
            if (opciones[j].vino) {
                fprintf (stdout, "%2d ", opciones[j].valor);
                opciones[j].valor = 0;
            }
            else opciones[j].valor = 0;
        }
        fprintf (stdout, "%s\n", argv[ultimo_prefijo]);
    }
    return 0;
}