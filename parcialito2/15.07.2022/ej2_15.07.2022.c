/* 
 *  Implementar una función
 * char *join(const char **ss, char sep);
 * que reciba en ss un arreglo dinámico de cadenas y devuelva la concatenación de cada una de ellas separadas por el
 * separador sep. La cantidad de cadenas está indicada con un centinela NULL en la última posición.
 * Por ejemplo join({"Hola", "que", "tal", NULL}, '|') debe devolver "Hola|que|tal".

 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Pre: arreglo dinámico con al menos 2 cadenas
char * join (char ** s, char sep){
   char separador[2] = {[0] = sep, [1] = '\0'};
   size_t largo = 1;
   for (size_t i = 0; s[i] != NULL; i++){
        largo += strlen(s[i]) + 1;
   }
   char * cadena = malloc (largo * sizeof(char));
   if (cadena == NULL)
    return NULL;
   strcpy (cadena, s[0]);
   for (size_t i = 1; s[i] != NULL; i++){
        strcat(cadena, separador);
        strcat(cadena, s[i]);
   }
   return cadena;
}



char *joineze (char ** s, char sep) {
   size_t tamano = 0, cant_cadenas = 0, i, j, k = 0;
   
   for(size_t i = 0; s[i] != NULL; i++){
      tamano += strlen(s[i]);
      cant_cadenas++; //Posible mejora -> cant_cadenas = i en este ciclo, por ende podrías llamar a i cant_cadenas y listo!
   }

   char *cadena = malloc(sizeof(char) * (tamano + cant_cadenas)); //Sería cant_cadenas - 1 pero así me aseguro de incluir el \0.
   if(cadena == NULL) return NULL;

   for(i = 0; i < cant_cadenas; i++){
      for(j = 0; s[i][j] != '\0'; j++, k++){
         cadena[k] = s[i][j];
      }
      (s[i+1] == NULL) ? (cadena[k++] = '\0') : (cadena[k++] = sep);
   }
   return cadena;
}

int main (void){
    char ** a = malloc (4 * sizeof(char *));
    if (a == NULL)
        return 1;
    char aux[20] = "Hola";
    for (size_t i = 0; i < 4; i++){
        a[i] = malloc (20 * sizeof(char));
        if (a[i] == NULL){
            for (size_t j = 0; j < i; j++)
                free(a[j]);
            free(a);
            return 1;
        }
        if (i != 3)
            strcpy (a[i], aux);
        else a[i] = NULL;
    }
    char * cadena = joineze(a, '!');
    puts(cadena);
    for (size_t j = 0; j < 4; j++)
        free(a[j]);
    free(a);
    free (cadena);
    return 0;
}

    