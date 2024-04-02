#include<stdio.h>
#include<string.h>
#include "validacion.h"

void chinosR(int ch,int i){
    char chinoiz[]=".-)";
    char chinoder[]="(-.";
    char chino[]="-)";
    if (i>=ch){
        printf("%s",chino);
    }
    else{
        printf("%s",chinoder);
        chinosR(ch,i+1);
        if(i!=0){
            printf("%s",chinoiz);
        }
    }
}
void chinos(int ch){
    chinosR(ch,0);
}
int main(){
    int n=0;
    int i,ch;
    do{
        printf("ejecucion %i\n",n);n++;
        printf("\tCHINOS\n");
        ch=entero_entre(0,1000);
        chinos(ch);
        printf("\nDesea terminar la ejecucion? (1==si):");
        fflush(stdin);scanf("%i",&i);
    }while(i!=1);
    printf("Fin de ejecucion");
    return 0;
}
