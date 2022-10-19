/* 
 * El formato de codificación UTF-8 permite representar millones de caracteres usando 1, 2, 3 o 4 bytes para
 * cada uno de ellos según necesite.
 * Particularmente los caracteres codificados en tres bytes tienen la siguiente estructura: {1110aaaa,
 * 10bbbbbb, 10cccccc} donde el valor asociado a ese símbolo (llamado code point) es el número 
 * aaaabbbb bbcccccc.
 * Se pide:
 * a. Programar una función
 * bool es_utf8_3bytes_valido(const unsigned char bytes[3]);
 * que diga si los bytes recibidos configuran un valor UTF-8 de 3 bytes válido.
 * b. Programar una función
 * unsigned int utf8_3bytes_a_codepoint(const unsigned char bytes[3]);
 * que reciba un conjunto de bytes válido y que devuelva el valor del code point que representa.
 * Por ejemplo, las secuencias {0x8A, 0x8F, 0xA0} o {0xEF, 0xAF, 0xC0} son inválidas mientras que la
 * secuencia {0xE2, 0x82, 0xAC} es válida y representa el code point 0x20AC
*/

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define MASK_FIRST_UTF 0xE0
#define MASK_OTHER_UTF 0x80

#define SHIFT_FIRST 4
#define SHIFT_OTHER 6

#define MASK_FIRST_CODE 0x0F
#define MASK_OTHERS_CODE 0x3F

#define SHIFT_POS_A 12
#define SHIFT_POS_B 6



bool es_utf8_3bytes_valido(const unsigned char bytes[3]){
    if ((bytes[0] >> SHIFT_FIRST) != (MASK_FIRST_UTF >> SHIFT_FIRST))
        return false;
    if ((bytes[1] >> SHIFT_OTHER) != (MASK_OTHER_UTF >> SHIFT_OTHER)) 
        return false;
    if ((bytes[2] >> SHIFT_OTHER) != (MASK_OTHER_UTF >> SHIFT_OTHER)) 
        return false;
    return true;
}

unsigned int utf8_3bytes_a_codepoint(const unsigned char bytes[3]){
    if (!es_utf8_3bytes_valido (bytes)){
        return 0; 
    }
    unsigned int rta = ((bytes[0] & MASK_FIRST_CODE) << SHIFT_POS_A) | ((bytes[1] & MASK_OTHERS_CODE) << SHIFT_POS_B) | (bytes[2] & MASK_OTHERS_CODE);
    return rta;
}


int main (void){
    // {0xE2, 0x82, 0xAC}
    unsigned char bytes[3] ={
        [0] = 0xE2,
        [1] = 0x82,
        [2] = 0xAC,
    };
    printf ("%s\n", es_utf8_3bytes_valido (bytes) ? "válido" : "no válido");
    printf ("0x%X\n", utf8_3bytes_a_codepoint(bytes));
    return 0; 
}

