#include <stdio.h>



int main (int argc, char * argv[]){
    if (argc != 3){
        fprintf(stderr, "Uso del programa: %s [archivo_entrada] [archivo_salida]\n", argv[0]);
        return 1;
    }
    FILE * entrada = fopen (argv[1], "rb");
    if (entrada == NULL) return 1;
    FILE * salida  = fopen (argv[2], "wb");
    if (salida == NULL) {
        fclose(entrada);
        return 1;
    }

    char c;
    while (fread(&c, sizeof(c), 1, entrada) == 1){ //que copie de a un byte para ahorrar quilombos
        fwrite(&c, sizeof(c), 1, salida);
    }

    fclose(entrada);
    if (fclose(salida)){
        return 1;
    }
    return 0;
}