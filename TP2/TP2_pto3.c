/*
3. Dadas 2 listas (L1 y L2) determinar si L2 es múltiplo de L1. Se considera múltiplo si cada 
    elemento de L2 se divide en forma exacta por el valor L1 de la misma posición. Usar la 
    clave como campo de datos solamente. 
    Ejemplo: si L1 = (2, 5, 7, 3) y L2 = (8, 20, 28, 12) entonces L2 es múltiplo por L1 porque 
    cada posición de L2 se divide por el valor de L1 de la misma posición en forma exacta 
    (sin decimales). Si el resultado de la división retorna el mismo valor para cada posición 
    se dice que “L2” es múltiplo de “L1” por un “escalar”. Para este caso “4” es el escalar 
    de L1. El algoritmo debe contemplar esta situación.
*/
#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validacion.h"
Lista llenar(Lista L1);
int multiplo(Lista L1, Lista L2);

int main(){
    Lista L1,L2;
    L1=l_crear();
    L1=llenar(L1);
    L2=l_crear();
    L2=llenar(L2);
    int m=multiplo(L1,L2);
    if(m==-1){
        printf("la lista 2 no es multiplo de la lista 1");
    }else if(m==0){
        printf("la lista 2 es multiplo de la lista 1, pero sin un escalar constante");
    }else if(m>=1){
        printf("la lista 2 es multiplo de la lista 1,con un escalar constante de %i",m);
    }
    return 0;
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
int multiplo(Lista L1, Lista L2){
    /* 
    entrada: 
    salida:
    es un entero (escalar)que retorna:
                                     -1 si no es multimplo 
                                     0 si es multiplo sin ningun escalar 
                                     y el escalar en caso de que los posea*/

    int escalar=-1;
    int mod,div,divprim;
    int primdiv=0;
    TipoElemento X1,X2;
    if(l_longitud(L1)==l_longitud(L2)){
        for(int pos=1;pos<=l_longitud(L1);pos++){
            X1=l_recuperar(L1,pos);
            X2=l_recuperar(L2,pos);
            mod=X2->clave%X1->clave;
            div=X2->clave/X1->clave;
            if(mod==0){
                escalar=0;
                if(primdiv==0){
                    primdiv=1;
                    divprim=div;
                }else if(div==divprim){
                    escalar=div;
                }
            }
        }
    }
    return escalar;
}