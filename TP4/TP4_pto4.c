/*4. Dada una cola de números enteros, no ordenada, construir un algoritmo que permita 
pasar a otra cola todos los elementos que no se repiten en la primera, sin destruir el 
contenido de la cola original y dejándola en su estado inicial. Determinar la 
complejidad algorítmica de la solución. */
//Ejemplo: si "C" contiene (12,6, 8, 5, 8, 12, 12) la cola resultado del proceso sería (6,5). 
/*5. Dada una cola de valores enteros no repetidos y mayores o iguales a 2, obtener todos 
los valores que son Divisores Totales o parciales. Se dice que un valor es Divisor Total
si permite dividir a todos los demás valores de la cola en forma exacta. Se dice que un 
divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola 
(es decir a la mitad de los elementos). Determinar la complejidad algorítmica de la 
solución. */
/*Ejemplo: si “C” contiene (8, 12, 2, 6, 4) se dice que “2” es el divisor total de la cola 
porque divide al resto en forma exacta. Y “4” es divisor parcial por divide a 8,12 y el 
mismo. */

/*7. Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en 
cada ventanilla. Un día, dos de los tres empleados que atienden las ventanillas no 
pueden asistir al trabajo, quedando uno solo para atender a las tres colas. Este 
empleado decide que, a medida que lleguen los clientes, atenderá por cierta cantidad 
de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas 
equitativamente. 
Se pide que implemente un algoritmo que modele esta situación y dé como resultado 
el orden en que fueron atendidos los clientes. 
Ejemplo: El algoritmo recibe un Q de tiempo que atenderá a cada cola y las tres colas 
cargadas con clientes, donde cada cliente es la cantidad de tiempo que se necesita 
para atenderlo.*/
/*
Q = 10 
Cola1 = (40, 20, 30) 
Cola2 = (20, 10) 
Cola3 = (10, 10, 10) 
Resultado = 
Cliente 1 Cola 3, 
Cliente 1 Cola 2, 
Cliente 2 Cola 3, 
Cliente 2 Cola 2, 
Cliente 3 Cola 3, 
Cliente 1 Cola 1, 
Cliente 2 Cola 1, 
Cliente 3 Cola 1*/
#include"colas.h"
#include"validacion.h"
#include"tp_colas.h"
Cola llenar(Cola c);
int main(){
    printf("Cola\n");
    Cola c1=c_crear();
    c1=llenar(c1);
    c_mostrar(c1);
    Cola c2=c_crear();
    c2=c_ej4_colanorepetidos(c1);
    printf("Cola Original\n");
    c_mostrar(c1);
    printf("Cola Resumida\n");
    c_mostrar(c2);
    return 0;
}
Cola llenar(Cola c){
    printf("Cuantos elementos decea encolar:\n");
    int n=entero_entre(0,10);
    int i=0;
    int x;
    while(!c_es_llena(c)&&i<n){
        printf("ingrese elemento a cargar:\n");
        x=entero_entre(0,10000);
        c_encolar(c,te_crear(x));
        i++;
    }
    return c;
}