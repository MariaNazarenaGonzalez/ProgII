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
void p_mostrar_con_valor(Pila pila){
    if (p_es_vacia(pila)) {
        printf("PILA VACIA !!! \n");
        return;
    }
    Pila Paux = p_crear();
    TipoElemento X = te_crear(0);
    printf("Contenido de la pila con valor: (");
    // Recorro la pila desapilandola y pasandola al auxiliar
    while (p_es_vacia(pila) != true) {
        X = p_desapilar(pila);
        printf("%d:%i ", X->clave,*(int*)X->valor);
        p_apilar(Paux, X);
    }

    // Recorro la pila auxiliar para pasarla a la original
    while (p_es_vacia(Paux) != true) {
        X = p_desapilar(Paux);
        p_apilar(pila, X);
    }

    printf(").\n");
}
/*8. Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los 
valores (sin repetición) y la cantidad de veces que aparecen. No debe perderse la pila 
original. El proceso recibe la pila con las repeticiones y retorna una nueva pila. 
Determinar la complejidad algorítmica de la solución. 
Ejemplo: si “P” contiene (1, 2,1, 3, 4, 5, 2, 1, 3, 5, 5), la pila resultado del proceso será 
“PR” = (1:3, 2:2, 3:2, 4:1, 5:3). */

int main(){
    Pila p=p_crear();
    p=llenar(p);
    p_mostrar(p);
    Pila pr=p_ej8_sacarrepetidos(p);
    printf("Pila resumida:\n");
    p_mostrar_con_valor(pr);
    printf("Pila original:\n");
    p_mostrar(p);
    return 0;
}