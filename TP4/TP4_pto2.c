/*2. Resolver los siguientes puntos: 
a. Informar si un elemento dado se encuentra en la cola. 
b. Agregar un nuevo elemento en una posición dada (colarse). 
c. Dado un elemento sacarlo de la cola todas las veces que aparezca. 
d. Contar los elementos de la cola. 
e. Realizar una función que realice una copia de una cola. 
f. Invertir el contenido de una cola sin destruir la cola original. */
#include"colas.h"
#include"validacion.h"
#include"tp_colas.h"
Cola llenar(Cola c);
int main(){
    Cola c=c_crear();
    c=llenar(c);
    c_mostrar(c);
    printf("ingrese elemento a encontrar:\n");
    int clave=entero_entre(0,10000);
    if(c_ej2_existeclave(c,clave)){printf("el elemento existe en la cola\n");}
    else{printf("el elemento NO existe en la cola\n");}
    c_mostrar(c);
    printf("ingrese posicion para colocar el elemento:\n");
    int pos=entero_entre(1,10);
    c_ej2_colarelemento(c,pos);
    c_mostrar(c);
    printf("ingrese elemento para eliminar:\n");
    clave=entero_entre(0,1000);
    c_ej2_sacarelemento(c,clave);
    c_mostrar(c);
    printf("La cola tiene %i elementos\n",c_ej2_contarelementos(c));
    Cola copia=c_ej2_copiar(c);
    printf("MUESTRA DUPLICADO\n");
    c_mostrar(copia);
    printf("MUESTRA ORIGINAL\n");
    c_mostrar(c);
    Cola inv=c_ej2_invertir(c);
    printf("MUESTRA INVERTIDO\n");
    c_mostrar(inv);
    printf("MUESTRA ORIGINAL\n");
    c_mostrar(c);
    return 0;
}

Cola llenar(Cola c){
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
