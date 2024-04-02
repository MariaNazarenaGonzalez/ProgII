/*4. Dados los números enteros m y n, construir una función recursiva que devuelva el 
cociente de ambos, calculando el mismo mediante restas sucesivas. Se deberá tener 
en cuenta que en el caso de que la división no sea exacta, se devolverán hasta 5 cifras 
decimales (si es necesario). 
Ejemplos: 
division (10,2) => 5 
division (22,3) => 7,33333*/


#include <stdio.h>
#include <string.h>
#include "validacion.h"

float resta(int *m,int *n,float c,float r){
    if(*m==*n){return r;
    }else{
        *n=*n-*m;
        r=r+c;
        return resta(m,n,c,r);
    }

}

float divisionR(int n,int m,float c,float r){
    float resultado;
    if(m<n){r=resta(&m,&n,c,r);}
    if(n==m){
        r+=c;
        resultado= r;}
    else if (r>=1||r==0){
        c=0.1;
        resultado=(r+=divisionR(n*10,m,c,0));}
    else if (r>=0.1){
        c=0.01;
        resultado=(r+=divisionR(n*10,m,c,0));}
    else if (r>=0.01){
        c=0.001;
        resultado=(r+=divisionR(n*10,m,c,0));}
    else if (r>=0.001){
        c=0.0001;
        resultado=(r+=divisionR(n*10,m,c,0));}
    else if (r>=0.0001){
        resultado= r;}
    return resultado;
}

float division(int n, int m){
    return divisionR(n,m,1.0,0.0);
}

int main(){
    int n=0;
    int i;
    int dividendo, divisor;
    do{
        printf("ejecucion %i\n",n);n++;
        printf("\tDIVISOR\n");
        divisor=entero_entre(0,40);
        printf("\tDIVIDENDO\n");
        dividendo=entero_entre(0,40);
        printf("division(%d,%d) ==> %.5f.\n", divisor, dividendo, division(divisor, dividendo));
        printf("Desea terminar la ejecucion? (1==si)(culquier char==no):");
        fflush(stdin);scanf("%i",&i);
    }while(i!=1);
    printf("Fin de ejecucion");
    return 0;
}