/*7. Se tiene una cadena que representa una onda digital de señales L (Low) y H (High). Se 
pide obtener recursivamente la onda que representa utilizando “_” y “|”. 
Ejemplos: 
ondaDigital (“LHLHL”) => “_ |¯ |_|¯ |_” 
ondaDigital (“HHHHLLLLHHHHHLLHH”) => “|¯ ¯ ¯ ¯ | _ _ _ _ |¯ ¯ ¯ ¯ ¯ | _ _ | ¯ ¯*/
#include<stdio.h>
#include <string.h>
#include<stdlib.h>
void ondaDigitalR(char* lh,int i,int l){
    char LHcom[]="LH";
    if(strlen(lh)==i){//fin cadena;
        printf("\n");
    }else{
        if(lh[i]==LHcom[0]&& (l==0||l==2)){
            printf("_");
        }else if(lh[i]==LHcom[0]&& l==1){
            printf("|_");
            l=0;
        }else if(lh[i]==LHcom[1]&& (l==1||l==2)){
            printf("T");
        }else if(lh[i]==LHcom[1]&& l==0){
            printf("|T");
            l=1;}
        ondaDigitalR(lh,i+1,l);
    }
}

void ondaDigital(char*lh){
    ondaDigitalR(lh,0,2);
}

int main(){
    int n=0;
    int i;
    do{
        printf("ejecucion %i\n",n);n++;
        char *cadena=(char*) malloc(sizeof(char)*100);
        printf("ingrese una serie de L(Low) y H (High):");
        fflush(stdin); scanf("%s",cadena);
        ondaDigital(cadena);
        free(cadena);
        printf("Desea terminar la ejecucion? (1==si):");
        fflush(stdin);scanf("%i",&i);
    }while(i!=1);
    printf("Fin de ejecucion");
    return 0;
}
