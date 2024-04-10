#include<stdio.h>
#include <stdlib.h>
#include "validacion.h"

int explosion(int n,int b,int i,int * explo){
    /*
    entradas:
        int n       el numero que explota
        int b       la bomba que hace explotar a n
        int i       indice para almacenar los fragmantos en *explo
        int *explo  puntero que almacena los fragmentos de la explocion
    salida:
        int *explo  puntero que almacena los fragmentos de la explocion
    */
    int n1,n2; //variables axuliares para los dos fracmentos de la explocio
    if(n<=b){
        *(explo + (i))=n;
        return i+1;
    }else{
        n1=n/b;
        n2=n-(n1);
        i=explosion(n1,b,i,explo);
        i=explosion(n2,b,i,explo);
    }
    return i; 
}

int main(){
    int n,b,i;
    printf("\tel numero que explota\n");
    n=entero_entre(0,1000);
    printf("\tla bomba\n");
    b=entero_entre(0,1000);
    int *explo=(int*) malloc(sizeof(int)*n);
    i=explosion(n,b,0,explo);
    printf("inicio explocion...\n");
    for (int j = 0; j < i; j++){printf("%i  ",*(explo + (j)));}
    printf("\n...fin explocion.");
    free(explo);
    return 0;
}
