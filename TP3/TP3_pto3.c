
/*3. Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la 
clave), sin destruirlas. Utilizar para la resolución del problema una única pila auxiliar. 
Determinar la complejidad algorítmica de la solución.  
*/
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
int main(){
    printf("Pila 1\n");
    Pila pila1=p_crear();
    pila1=llenar(pila1);
    p_mostrar(pila1);
    printf("Pila 2\n");
    Pila pila2=p_crear();
    pila2=llenar(pila2);
    p_mostrar(pila2);
    if(p_ej3_iguales(pila1,pila2)){printf("Las pilas son iguales\n");}
    else{printf("Las pilas no son iguales\n");}
    p_mostrar(pila1);
    p_mostrar(pila2);
    return 0;
}