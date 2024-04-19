#include "pilas.h"
#include "validacion.h"
#include "tipo_elemento.h"
#include"tp_pilas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
Pila llenar(Pila p);
int main(){
    Pila pila=p_crear();
    pila=llenar(pila);
    p_mostrar(pila);
    printf("elemento de la pila:\n");
    int clave=entero_entre(0,1000);
    if(p_ej2_existeclave(pila,clave)){printf("el elemento existe en la pila\n");}
    else{printf("el elemento NO existe en la pila\n");}
    p_mostrar(pila);
    printf("ingrese posicion de la pila para colocar:\n");
    int pos=entero_entre(1,10);
    p_ej2_colocarelemento(pila,pos);
    p_mostrar(pila);
    printf("ingrese elemento para eliminar de la pila:\n");
    clave=entero_entre(0,1000);
    p_ej2_eliminarclave(pila,clave);
    p_mostrar(pila);
    printf("intercambiar\n");
    printf("posision 1\n");
    int pos1=entero_entre(0,10);
    printf("posision 2\n");
    int pos2=entero_entre(0,10);
    p_ej2_intercambiarposiciones(pila,pos1,pos2);
    p_mostrar(pila);
    Pila p=p_ej2_duplicar(pila);
    printf("MUESTRA DUPLICADO\n");
    p_mostrar(p);
    printf("MUESTRA ORIGINAL\n");
    p_mostrar(pila);
    printf("cantidad de elementos:%i",p_ej2_cantidadelementos(pila));
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
