#include <stdio.h>
#include<stdio.h>
#include<stdbool.h>
#include "validacion.h"

bool divisiblePor7(int n){
    /*
    entrada:
        int n   valor a analizar para saver si es divisible por 7 
    salida:
        bool    verdadero si n es divisible por 7 y falso de lo contrario
    */
    if(n<70){
        n=n%7;
        if (n==0){return true;}
        else{return false;}
    }else{
        int n1;
        n1=(n%10)*2;
        n=(n/10)-n1;
        return divisiblePor7(n);
    }
}

int main(){

    int n=0;int i;
    do{
        printf("ejecucion %i\n",n);n++;
        int num;
        printf("\tvalor a analiza si es divisible por 7\n");
        num=entero_entre(0,100000);
        if(divisiblePor7(num)){printf("SI es divisible por 7\n");}
        else{printf("NO es divisible por 7\n");}
        printf("Desea terminar la ejecucion? (1==si):");
        fflush(stdin);scanf("%i",&i);
    }while(i!=1);
    printf("Fin de ejecucion");
    return 0;
}
