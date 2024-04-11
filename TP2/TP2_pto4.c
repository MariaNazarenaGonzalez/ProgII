/*
4. Dadas dos listas L1 y L2, se pide compararlas siempre en el sentido L1L2. Por lo tanto 
    puede suceder que: L1 > L2, L1 = L2 o L1 < L2. La forma de obtener la comparación es por 
    la clave, posición a posición, donde si L1 tiene más cantidad de claves mayores que L2 se 
    considera L1 > L2, por el contrario se considera L1 < L2, o de lo contrario L1 será igual a L2. 
    Determinar la complejidad algorítmica de la solución empleada. 
(Listas L1,Lista L2)   
    */ 

#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validacion.h"

enum comp{
    mayor=1,
    igual=0,
    menor=-1,
    error=-2,
};

enum comp comparacion(Lista L1,Lista L2){//O(n)lineal
    enum comp c;
    int mayorL1=0;
    int mayorL2=0;
    Iterador it1=iterador(L1);
    Iterador it2=iterador(L2);
    TipoElemento x1;
    TipoElemento x2;
    if(l_longitud(L1)==l_longitud(L2)){
        while(hay_siguiente(it1)&&hay_siguiente(it2)){
            x1=siguiente(it1);
            x2=siguiente(it2);
            if(x1->clave>x2->clave){
                mayorL1++;
            }else if (x1->clave<x2->clave){
                mayorL2++;
            }
        }
        if(mayorL1>mayorL2){
            c=mayor;
        }else if(mayorL1<mayorL2){
            c=menor;
        }else {
            c=igual;
        }
    }else{
        c=error;
    }
    return c;
}

Lista llenar(Lista L1){
    /*
    entradas:
            Lista L1    lista a llenar con valores resividos por teclado;
    saliidas:
            Lista L1    la misma lista llenada con los valores recividos*/
    int N;
    printf("\tCuantos elementos desea ingresar:\n");
    N=entero_entre(1,100);
    for(int i=0;i<N;i++){
        printf("ingrese clave de elemento:\n");
        int c=entero_entre(0,100);
        l_agregar(L1,te_crear(c));
    }
    return L1;
}

int main(){
    Lista L1,L2;
    L1=l_crear();
    printf("CARGA LISTA 1:\n");
    L1=llenar(L1);
    l_mostrar(L1);
    L2=l_crear();
    printf("CARGA LISTA 2:\n");
    L2=llenar(L2);
    l_mostrar(L2);
    printf("COMPARO LAS DOS LISTAS");
    enum comp c=comparacion(L1,L2);
    if(c==-2){printf("se produjo un error");}
    else if(c==-1){printf("la lista 1 es menor que la lista 2");}
    else if (c==0){printf("la lista 1 es igual a la lista 2");}
    else if(c==1){printf("la lista 1 es mayor que la lista 2");}
    return 0;
}