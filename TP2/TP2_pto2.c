/*Dada una 2 listas (L1 y L2) cargadas con valores al azar (en la clave) realizar los siguientes 
ejercicios: 
a. Que retorne una lista con los valores de L1 que no están en L2. 
b. Que retorne una lista con los valores de L2 que no están en L1. 
c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
d. Que retorne los promedios de ambas listas. 
e. Que retorne el valor máximo de ambas listas y su posición ordinal.*/


#include "listas.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "validacion.h"
Lista llenar(Lista L1);
//a. Que retorne una lista con los valores de L1 que no están en L2.
//b. Que retorne una lista con los valores de L2 que no están en L1. 
Lista No_estan(Lista L1,Lista L2);
//c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).
Lista comunes(Lista L1,Lista L2);
//d. Que retorne los promedios de ambas listas. 
float promedio(Lista L1);
//e. Que retorne el valor máximo de ambas listas y su posición ordinal.
struct dato_pos{
    TipoElemento Dato;
    int pos;
};
struct dato_pos maximo(Lista L1);

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
    printf("LISTA DE LOS VALORES QUE no COMPARTEN:\n");
    Lista R1=No_estan(L1,L2);
    l_mostrar(R1);
    printf("LISTA DE LOS VALORES QUE no COMPARTEN:\n");
    Lista R2=No_estan(L2,L1);
    l_mostrar(R2);
    printf("LISTA DE LOS VALORES QUE COMPARTEN:\n");
    Lista R3=comunes(L1,L2);
    l_mostrar(R3);
    printf("%f\n",promedio(L1));
    printf("%f\n",promedio(L2));
    struct dato_pos d1=maximo(L1);
    printf("%i-%i\n",d1.Dato->clave,d1.pos);
    struct dato_pos d2=maximo(L2);
    printf("%i-%i\n",d2.Dato->clave,d2.pos);
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
//a. Que retorne una lista con los valores de L1 que no están en L2.
//b. Que retorne una lista con los valores de L2 que no están en L1. 
Lista No_estan(Lista L1,Lista L2){
    Lista LR=l_crear();
    TipoElemento X1;
    TipoElemento X2;
    for(int pos1=1;pos1<=l_longitud(L1);pos1++){
        X1=l_recuperar(L1,pos1);
        bool x1esta=false;
        int i=1;
        for(int pos2=1;pos2<=l_longitud(L2);pos2++){
            X2=l_recuperar(L2,pos2);
            if(X1->clave==X2->clave){
                x1esta=false;
                i=0;
            }else if((X1->clave!=X2->clave)&& i!=0){
                x1esta=true;
            }
        }
        if(x1esta==true){
            l_agregar(LR,X1);
        }
    }
    return LR;
}

//c. Que retorne una lista con todos los valores comunes a ambas listas (L1 y L2).

Lista comunes(Lista L1,Lista L2){
    Lista LR=l_crear();
    TipoElemento X1;
    TipoElemento X2;
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
    return LR;
}

//d. Que retorne los promedios de ambas listas. 
float promedio(Lista L1){
    Iterador it= iterador(L1);
    TipoElemento x;
    int acumulador=0;
    while(hay_siguiente(it)){
        x=siguiente(it);
        acumulador +=x->clave;
    }
    return ((float)acumulador/(float)l_longitud(L1));
}

struct dato_pos maximo(Lista L1){
    struct dato_pos D;
    TipoElemento Xact;
    D.Dato=l_recuperar(L1,1);
    D.pos=1;
    for(int pos1=2;pos1<=l_longitud(L1);pos1++){
        Xact=l_recuperar(L1,pos1);
        if(D.Dato->clave<Xact->clave){
            D.Dato=Xact;
            D.pos=pos1;
        }
    }
    return D;
}
