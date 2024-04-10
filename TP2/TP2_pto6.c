/*6. Generar un algoritmo que determine si una lista es sublista de otra. Se considera que es 
    una sublista si todos los valores de la segunda se encuentran dentro de la primera sin 
    importar el orden o posición de cada elemento. La comparación es solo por la clave. Se 
    pide además determinar la complejidad algorítmica de la solución. 
    Ejemplo: si “L1” contiene los elementos (7, 3, 4, 5, 9, 2) y “L2” contiene los elementos 
    (4, 7, 2) se dice que “L2” es sublista de “L1”.*/
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validacion.h"
bool subllista(Lista L1,Lista L2){//solucion con complejidad O(N^2)
    Lista LR=l_crear();
    TipoElemento X1;
    TipoElemento X2;
    if(l_longitud(L1)<l_longitud(L2)){
        return false;
    }else{
        for(int pos1=1;pos1<=l_longitud(L1);pos1++){
            X1=l_recuperar(L1,pos1);
            bool x1esta=false;
            for(int pos2=1;pos2<=l_longitud(L2);pos2++){
                X2=l_recuperar(L2,pos2);
                if(X1->clave==X2->clave){
                    x1esta=true;
                }
            }
            if(x1esta){
                l_agregar(LR,X1);
            }
        }
        if(l_longitud(LR)==l_longitud(L2)){
            return true;
        }else{
            return false;
        }
    }
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
    if(subllista(L1,L2)==true){
        printf("la lista 2 es sublista de la lista 1");
    }else{printf("la lista 2 NO es sublista de la lista 1");}
    return 0;
}