/*
 * Una direccion IPv4 se compone de 4 octetos, donde cada octeto es un número de 8 bits. Es decir, una
 * dirección IP como 192.168.0.46 no es otra cosa que una representación de un número de 32 bits donde 192
 * será el contenido de su byte más pesado.
 * Los bits más pesados de una IP representan a la subred mientras que los más livianos representan a un
 * equipo dentro de esa red. Por ejemplo, si una IP fuera 192.168.1.10/23 ese 23 es la máscara de subred y la
 * misma indica que los primeros 23 bits de la IP corresponden a la subred y el resto al equipo. Entonces,
 * la IP del ejemplo anterior y la de este pertenecen a la misma subred dado que sus primeros 23 bits son
 * idénticos.
 * Se tiene la estructura
 * typedef struct {
 *      uint8_t octeto1, octeto2, octeto3, octeto4;
 * } ip_t;
 * que define los 4 octetos de una IP, por ejemplo (ip_t ){192, 168, 0, 46}.
 * a. Escribir una función uint32_t ip_a_int(const ip_t *ip); que reciba una IP como octetos y
 * devuelva su representación como entero.
 * b. Escribir una función bool misma_subred(const ip_t *ipa, const ip_t *ipb, int mascara);
 * que diga si ipa y ipb pertenencen a la misma subred, estando la mascara representada por el número
 *de bits (o sea, no es una máscara, es el número de bits prendidos que debería tener la máscara). Para
 *que las dos IPs pertenezcan a la misma subred deben coincidir sus primeros mascara bits.
 *
 */

#define SHIFT_OCTETO1 24
#define SHIFT_OCTETO2 16
#define SHIFT_OCTETO3 8

#define MASK_MSB 0x80

 typedef struct {
    uint8_t octeto1, octeto2, octeto3, octeto4;
 } ip_t;


uint32_t ip_a_int(const ip_t *ip){
    return ((ip->octeto1 << SHIFT_OCTETO1) | (ip->octeto2 << SHIFT_OCTETO2) | (ip->octeto3 << SHIFT_OCTETO3) | ip->octeto4);
}

 bool misma_subred(const ip_t *ipa, const ip_t *ipb, int mascara){
    if (mascara <= 0 || mascara > 32) return false; //debería ser precondición que te pidan una cantidad de bits posible pero lo hacemos abp porque no se especifica
    uint32_t a = ip_a_int(ipa), b = ip_a_int(ipb); 
    for (size_t i = 0; i < mascara; i++){
        if ((a & (MASK_MSB >> i)) != (b & (MASK_MSB >> i)))
            return false;
    }
    return true;
 }


