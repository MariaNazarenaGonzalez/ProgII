#include<stdio.h>
#include "validacion.h" 


int main(){
    int datoInt=entero_entre(-100,100);
    printf("se resibio un entero %i\n",datoInt);//muestra el entero
    float datofloat =flotante_entre(-100.5, 100.5);
    printf("se resibio un flotante %.5f\n",datofloat);//muestra el entero
    return 0;
}