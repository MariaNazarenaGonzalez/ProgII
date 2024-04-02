#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
bool recorrocadenapalindromo(char*cadena,int primero,int ultimo){    
    /*entradas:
        char*cadena     array de caracteres a analizas
        int primero     indice para manejar la cadena ubicado en el inicio de la cadena
        int ultimo      incide para manejar la cadena ubicado en el final de la cadena
    salida: 
        bool            verdadero si *cadena es palindromo o falso de lo contrario*/

    if(primero==strlen(cadena) || ultimo==0){ //primero llego al final de la cadena o ultimo llego al inicio de la cadena
        if(cadena[primero]==cadena[ultimo]){return true;}
    }else{
        if(cadena[primero]!=cadena[ultimo]){return false;}
        return recorrocadenapalindromo(cadena,primero+1,ultimo-1);
    }
}

bool palindromo(char*cadena){
    bool resultado;
    int ultimo=strlen(cadena)-1;
    if(recorrocadenapalindromo(cadena,0,ultimo)){resultado=true;}
    else{resultado=false;}
    return resultado;
}

int main(){
    int n=0;
    int i;
    do{
        printf("ejecucion %i\n",n);n++;
        char *cadena=(char*) malloc(sizeof(char)*100);
        printf("ingrese cadeana(fin entrada con Enter):");
        fflush(stdin);scanf("%s",cadena);
        if(palindromo(cadena)){printf("La cadena ingresada SI es palidromo");}
        else{printf("La cadena ingresada NO es palidromo");}
        printf("\nDesea terminar la ejecucion? (1==si):");
        fflush(stdin);scanf("%i",&i);
        free(cadena);
    }while(i!=1);
    printf("Fin de ejecucion");
    return 0;
}