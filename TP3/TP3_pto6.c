
#include "pilas.h"
#include "tp_pilas.h"
#include "validacion.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

Pila llenar(Pila p){
    int e;
    printf("ingrese cantidad de elementos a apilar:");
    int c=entero_entre(0,10);
    for(int i=0; i<c;i++){
        printf("ingrese elemento a apilar:");
        e=entero_entre(0,1000);
        p_apilar(p,te_crear(e));
    }
    return p;
}

/*6. Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado 
ítem sin perder la pila original. Deberá retornar una nueva pila sin el ítem en 
consideración. Resolver iterativamente y recursivamente. Determinar la complejidad 
algorítmica de ambas soluciones. 
Ejemplo: si “P” contiene (1, 5, 7, 1, 3, 1, 8) y el ítem a eliminar es “1” entonces la pila 
resultante sería (5, 7, 3, 8). */

int main(){
    Pila org=p_crear();
    org=llenar(org);
    p_mostrar(org);
    printf("Elemento a eliminar:\n");
    int e=entero_entre(0,1000);
    Pila bor=p_ej6_eliminarclave(org,e);
    printf("Pila sin %i:\n",e);
    p_mostrar(bor);
    printf("Pila original\n");
    p_mostrar(org);
    return 0;
}