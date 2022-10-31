/*
 * Una IPv4 se compone de 4 números llamados octetos que toman valores de entre 0 y 255, por ejemplo 192.168.0.1.
 * Ahora bien, la misma IPv4 puede representarse de forma compacta utilizando 32 bits para almacenar los 4 octetos. Se pide:
 * a. Declarar una estructura struct ipv4_octetos que modele a la IPv4 con un miembro para cada uno de los cuatro
 * octetos.
 * b. Declarar el tipo ipv4_octetos_t en base a la estructura anterior y el tipo ipv4_t en base al tipo uint32_t.
 * c. Escribir una función ipv4_t ipv4_compactar(const ipv4_octetos_t *o); que reciba un puntero o a una IPv4
 * representada por octetos y devuelva su representación compacta.
 *
 */

#include <stdio.h>
#include <stdint.h>

#define SHIFT_OCT1 24
#define SHIFT_OCT2 16
#define SHIFT_OCT3 8

 struct ipv4_octetos{
    uint8_t octeto1, octeto2, octeto3, octeto4;
 };

typedef struct ipv4_octetos ipv4_octetos_t;
typedef uint32_t ipv4_t;

ipv4_t ipv4_compactar(const ipv4_octetos_t *o){
    return ((o->octeto1 << SHIFT_OCT1) | (o->octeto2 << SHIFT_OCT2) | (o->octeto3 << SHIFT_OCT3) | o->octeto4);
}