#include <stdio.h>
#include "validacion.h"

int producto(int m,int n){
    /*
    Entrada:
        int m   valor a sumar
        int n   veces a sumar
    salida:
        int resultado   producto de m y n realizado por sumas sucesivas
    */
    int resultado;
    if (n==0) resultado = 0;
    else resultado = m + producto (m, (n-1));
    return resultado;
}
int main(){
    int n=0;
    int i,mult,num,prod;
    do{
        printf("ejecucion %i\n",n);n++;
        printf("\tMULTIPLICADOR\n");
        mult=entero_entre(0,1000);
        printf("\tNUMERADOR\n");
        num=entero_entre(0,1000);
        prod=producto(mult,num);
        printf("el producto de %i y %i dio: %i\n",mult,num,prod);
        printf("Desea terminar la ejecucion? (1==si):");
        fflush(stdin);scanf("%i",&i);
    }while(i!=1);
    printf("Fin de ejecucion");
    return 0;
}

