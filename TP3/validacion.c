//filtrar entrada de datos enteros con "scanf"
#include<stdio.h>
#include "validacion.h"
int entero_entre(int mayor_a, int menor_a){
    int datoInt,convertidos,bandera;
    float datoFloat;
    bandera = 0;
    do{
        if (bandera>1){
            printf("ingerse un entero dentro de (%i a %i): ",mayor_a,menor_a); //pide el dato  nueva mente
        }
        else{
            printf("ingerse un entero dentro de (%i a %i): ",mayor_a,menor_a); //pide el dato por primara ves 
            bandera ++; //quito bandera
        }
        fflush(stdin);//limpio el bufer
        convertidos=scanf("%f",&datoFloat);//scanf:pide un dato flotante y convertidos devuelse la cantidad de datos que scanf pudo concertir a flotante
        datoInt=datoFloat;//almaceno en un int el flotante- si el dato resivido es int seran iguales-
    }while((convertidos==0||datoInt!=datoFloat)||(datoInt<mayor_a || datoInt>menor_a));
    //mientras nose podo convertir el dato a float (convertido==0) se repire el ciclo XQ no es numero
                //o el dato int y el dato float son distintos (datoInt!=datoFloat)  se repire el ciclo XQ no es entero
                //o el dato no esta en el intervalo deseado (datoInt<mayor_a || datoInt>menor_a) se repire el ciclo 
    
    return datoInt;
}

float flotante_entre(float mayor_a,  float menor_a){
    int convertidos,bandera;
    float datoFloat;
    bandera = 0;
    do{
        if (bandera>1){
            printf("ingerse un entero dentro de (%.5f a %.5f): ",mayor_a,menor_a); //pide el dato  nuevamente
        }
        else{
            printf("ingerse un entero dentro de (%.5f a %.5f): ",mayor_a,menor_a); //pide el dato por primara ves 
            bandera ++; //quito bandera
        }
        fflush(stdin);//limpio el bufer
        convertidos=scanf("%f",&datoFloat);//scanf:pide un dato flotante y convertidos devuelse la cantidad de datos que scanf pudo concertir a flotante
    }while((convertidos==0)||(datoFloat<mayor_a || datoFloat>menor_a));
    //mientras nose podo convertir el dato a float (convertidos==0) se repire el ciclo XQ no es numero
                //o el dato int y el dato float son distintos (datoInt!=datoFloat)  se repire el ciclo XQ no es entero
                //o el dato no esta en el intervalo deseado (datoInt<mayor_a || datoInt>menor_a) se repire el ciclo 
    
    return datoFloat;
}