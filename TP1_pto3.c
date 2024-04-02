#include <stdio.h>
#include "validacion.h"

/*3. Generar un algoritmo recursivo que calcule el k-ésimo número de la serie de Fibonacci. 
Ejemplos: 
terminoSeridFibonacci (1) => 1 
terminoSeridFibonacci (5) => 8*/

int terminoSeridFibonacci(int k){
    int resultado;
    if(k<=1){
        return 1;}
    else{return(terminoSeridFibonacci(k-1)+terminoSeridFibonacci(k-2));}
}


int main(){
    int n=0;
    int i,num;
    do{
        printf("ejecucion %i\n",n);n++;
        printf("\tNUMERO\n");
        num=entero_entre(0,40);
        printf("El fibonacci de %i es %i\n",num,terminoSeridFibonacci(num));
        printf("Desea terminar la ejecucion? (1==si)(culquier char==no):");
        fflush(stdin);scanf("%i",&i);
    }while(i!=1);
    printf("Fin de ejecucion");
    return 0;
}