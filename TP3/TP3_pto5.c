#include "pilas.h"
#include "tp_pilas.h"
#include "validacion.h"
#include "tipo_elemento.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/*5. Invertir el contenido de una pila sin destruir la pila original. Se debe retornar la nueva 
pila invertida y la original no se debe perder. Determinar la complejidad algorítmica 
de la solución. 
*/
Pila llenar(Pila p);

int main(){
    Pila org=p_crear();
    org=llenar(org);
    p_mostrar(org);
    Pila inv=p_ej5_invertir(org);
    printf("Pila invertida:\n");
    p_mostrar(inv);
    printf("Pila original\n");
    p_mostrar(org);
    return 0;
}

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

