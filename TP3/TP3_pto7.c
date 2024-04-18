#include "pilas.h"
#include"tp_pilas.h"
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

/*7. Dada dos pilas realizar una función que permita determinar los elementos que tienen 
en común. Debe retornar una nueva pila con esos elementos (que están en ambas 
pilas) sin perder las pilas originales. Determinar la complejidad algorítmica de la 
solución. 
Ejemplo: si “P1” contiene (1, 4, 7, 9, 8) y “P2” contiene (4,1,6,9,3) el resultado será la 
pila “PR” = (1,4,9). */
int main(){
    printf("Pila 1\n");
    Pila pila1=p_crear();
    pila1=llenar(pila1);
    p_mostrar(pila1);
    printf("Pila 2\n");
    Pila pila2=p_crear();
    pila2=llenar(pila2);
    p_mostrar(pila2);
    Pila com =p_ej7_eliminarclave(pila1,pila2);
    printf("Pila con los elementos en comun:\n");
    p_mostrar(com);
    printf("Pila original 1:\n");
    p_mostrar(pila1);
    printf("Pila original 2:\n");
    p_mostrar(pila2);
    return 0;
}