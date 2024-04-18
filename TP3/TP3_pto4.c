/*4. Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número 
decimal pasado como parámetro, a su correspondiente valor expresado en una base 
de 2 a 16 (hexadecimal). Determinar la complejidad algorítmica de la solución. 
*/


#include "pilas.h"
#include "tp_pilas.h"
#include "validacion.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<string.h>
//resibe un numero decimal y la base a la que lo desea cambiar y revuelve el numero en la base pedida.

int main(){
    printf("ingrese el numero:");
    int num =entero_entre(0,1000);
    printf("ingrese nueva base:");
    int base=entero_entre(0,16);
    printf("%s",p_ej4_cambiarbase(num,base));
    return 0;
}
