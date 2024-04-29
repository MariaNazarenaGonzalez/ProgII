/*6. Dada una pila y una cola generada con valores al azar retornar en una lista todos los 
valores comunes a ambas y en qué posición ordinal se encontró cada uno en su 
estructura. No se deben destruir las estructuras originales. No se deben perderse las 
estructuras originales. Determinar la complejidad algorítmica de la solución empleada. */
//Ejemplo: si “P” = (2,5,8,19,3,4) y “C” = (4, 18, 12, 5, 6) la lista tendría L = (5:2:4, 4:6:1). 
#include"tp_colas.h"
#include <stdio.h>
#include"validacion.h"
/*
#include"colas.h"
#include <stdbool.h>
#include "colas.h"
#include "listas.h"
#include "pilas.h"*/

Pila p_llenar(Pila p);
Cola c_llenar(Cola c);
void l_mostrar_con_valor(Lista l);
int main(){
    printf("Pila \n");
    Pila p1=p_crear();
    p1=p_llenar(p1);
    p_mostrar(p1);
    printf("Cola \n");
    Cola c1=c_crear();
    c1=c_llenar(c1);
    c_mostrar(c1);
    Lista l=c_ej6_comunesapilaycola(p1,c1);
    l_mostrar_con_valor(l);
    p_mostrar(p1);
    c_mostrar(c1);
}
Pila p_llenar(Pila p){
    printf("Cuantos elementos decea apilar:\n");
    int n=entero_entre(0,10);
    int i=0;
    int x;
    while(!p_es_llena(p)&&i<n){
        printf("ingrese elemento a cargar:\n");
        x=entero_entre(0,10000);
        p_apilar(p,te_crear(x));
        i++;
    }
    return p;
}
Cola c_llenar(Cola c){
    printf("Cuantos elementos decea encolar:\n");
    int n=entero_entre(0,10);
    int i=0;
    int x;
    while(!c_es_llena(c)&&i<n){
        printf("ingrese elemento a cargar:\n");
        x=entero_entre(0,10000);
        c_encolar(c,te_crear(x));
        i++;
    }
    return c;
}
void l_mostrar_con_valor(Lista l){
    Iterador i=iterador(l);
    TipoElemento x;
    printf("Mostrar Lista con valor: {");
    while(hay_siguiente(i)){
        x=siguiente(i);
        printf("%i:%i:%i, ",x->clave,((pos)x->valor)->posP,((pos)x->valor)->posC);
    }
    printf("}\n");
}
