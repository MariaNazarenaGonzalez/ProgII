/*5. Generar un algoritmo recursivo que le ponga los “.” de los miles a un String de 
números. 
Ejemplos: 
agregarSeparadorMiles (“123456”) => “123.456” 
agregarSeparadorMiles (“12345678”) => “12.345.678”*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void agregarSeparadorMilesR(char *a, int i, int c){
    if(i==0){
        printf("%c",a[i]);
    }
    else{
        if(c==3){
            agregarSeparadorMilesR(a,i-1,1);
            printf(".%c",a[i]);
            
        }else{
            agregarSeparadorMilesR(a,i-1,c+1);
            printf("%c",a[i]);
        } 
    }
}

void agregarSeparadorMiles(char* a){
    agregarSeparadorMilesR(a,strlen(a)-1,1);
}
int main(){
    int n=0;
    int i;
    do{
        printf("ejecucion %i\n",n);n++;
        char *cadena=(char*) malloc(sizeof(char)*100);
        printf("ingrese cadeana(fin entrada con Enter):");
        fflush(stdin);scanf("%s",cadena);
        agregarSeparadorMiles(cadena);
        printf("\nDesea terminar la ejecucion? (1==si):");
        fflush(stdin);scanf("%i",&i);
        free(cadena);
    }while(i!=1);
    printf("Fin de ejecucion");
    return 0;
}