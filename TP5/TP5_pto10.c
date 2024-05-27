#include"tp_arboles.h"
#include"validacion.h"
#include"stdio.h"

int main(){
    int N_rep,min,max,cantclaves;
    printf("insete cant repeticiones:\n");
    N_rep=entero_entre(0,1000);
    printf("cantidad de claves:\n");
    cantclaves=entero_entre(0,1000);
    printf("valor minimo de claves:\n");
    min=entero_entre(0,1000000);
    printf("valor maximo de claves:\n");
    max=entero_entre(0,1000000);
    Lista L=a_ej10_comparacionarboles(N_rep,min,max,cantclaves);
    printf("comparaciones\n");
    l_mostrar(L);
    return 0;
}


