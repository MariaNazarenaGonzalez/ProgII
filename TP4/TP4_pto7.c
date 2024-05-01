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
#include"string.h"
#include"tp_colas.h"
Cola llenar(Cola c);
void c_mostrar_con_valor(Cola cresu);
int main(){
    printf("Cola1\n");
    Cola c1=c_crear();
    c1=llenar(c1);
    c_mostrar(c1);
    printf("Cola 2\n");
    Cola c2=c_crear();
    c2=llenar(c2);
    c_mostrar(c2);
    printf("Cola 3\n");
    Cola c3=c_crear();
    c3=llenar(c3);
    c_mostrar(c3);
    printf("Indique el tiempo de atencion\n");
    int Q=entero_entre(0,1000);
    Cola cresu=c_ej7_atenderclientes(c1, c2, c3,Q);
    c_mostrar_con_valor(cresu);
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
void c_mostrar_con_valor(Cola cola){
    if (c_es_vacia(cola)) {
        printf("COLA VACIA !!! \n");
        return;
    }

    Cola Caux = c_crear();
    TipoElemento X = te_crear(0);
    
    printf("Orden de Atencion\n");
    // La cola se debe desencolar y guardar en una auxiliar
    while (c_es_vacia(cola) != true) {
        X = c_desencolar(cola);
        printf("Cliente %i",X->clave);
        printf(" %s,\n",(char *)X->valor);
        c_encolar(Caux, X);
    }

    // ahora paso la auxiliar a la cola de nuevo para dejarla como estaba
    while (c_es_vacia(Caux) != true) {
        X = c_desencolar(Caux);
        c_encolar(cola, X);
    }

    printf("\n");
}