
#include"tp_colas.h"
#include<stdlib.h>
#include"validacion.h"
/**
    2.	Resolver los siguientes puntos:
 */

//  a.	Informar si un elemento dado se encuentra en la cola.
// Si la encuentra retorna true, caso contrario false
bool c_ej2_existeclave(Cola c, int clave){
    TipoElemento x;
    Cola aux=c_crear();
    bool resu=false;
    while(!c_es_vacia(c)){
        x=c_desencolar(c);
        if(x->clave==clave){
            resu=true;
        }
        c_encolar(aux,x);
    }
    while(!c_es_vacia(aux)){
        x=c_desencolar(aux);
        c_encolar(c,x);
    }
    return resu;
}

//  b.	Agregar un nuevo elemento en una posición dada (colarse).
// Retorna la nueva cola con el elemento insertado, caso contrario la cola original recibida.
Cola c_ej2_colarelemento(Cola c, int posicionordinal){
    int i=1;
    TipoElemento x;
    Cola caux=c_crear();
    int clave=entero_entre(0,10000);
    while(!c_es_vacia(c)){
        x=c_desencolar(c);
        if(i==posicionordinal){c_encolar(caux,te_crear(clave));}
        c_encolar(caux,x);
        i++;
    }
    while(!c_es_vacia(caux)){
        x=c_desencolar(caux);
        c_encolar(c,x);
    }
    return c;
}

//  c.	Dado un elemento sacarlo de la cola todas las veces que aparezca.
// Retorna la nueva cola sin el/los elemento/s, caso contrario la cola original recibida.
Cola c_ej2_sacarelemento(Cola c, int clave){
    TipoElemento x;
    Cola aux=c_crear();
    while(!c_es_vacia(c)){
        x=c_desencolar(c);
        if(x->clave!=clave){
            c_encolar(aux,x);
        }
    }
    while(!c_es_vacia(aux)){
        x=c_desencolar(aux);
        c_encolar(c,x);
    }
    return c;
}

//  d.	Contar los elementos de la cola.
// Retorna la cantidad de elementos de la cola, o 0 (cero) si esta vacia.
int c_ej2_contarelementos(Cola c){
    int CantC=0;
    TipoElemento x;
    Cola aux=c_crear();
    while(!c_es_vacia(c)){
        x=c_desencolar(c);
        c_encolar(aux,x);
        CantC++;
    }
    while(!c_es_vacia(aux)){
        x=c_desencolar(aux);
        c_encolar(c,x);
    }

    return CantC;
}

//  e.	Realizar una función que realice una copia de una cola.
// Retorna la cola copia tal cual la original, no debe perserse la original.  Si es vacia retorna vacia.
Cola c_ej2_copiar(Cola c){
    TipoElemento x;
    Cola aux=c_crear();
    Cola copia=c_crear();
    while(!c_es_vacia(c)){
        x=c_desencolar(c);
        c_encolar(aux,x);
    }
    while(!c_es_vacia(aux)){
        x=c_desencolar(aux);
        c_encolar(copia,x);
        c_encolar(c,x);
    }
    return copia;
}

//  f.	Invertir el contenido de una cola sin destruir la cola original.
// Retorna la cola al reves (invertida), no debe perserse la original. Si es vacia retorna vacia.
Cola c_ej2_invertir(Cola c){
    Cola cinv=c_crear();
    TipoElemento x;
    Pila p=p_crear();
    int i=0;int c_cant=c_ej2_contarelementos(c);
    while(c_cant>i){
        x=c_desencolar(c);
        p_apilar(p,x);
        c_encolar(c,x);
        i++;
    }
    while(!p_es_vacia(p)){
        x=p_desapilar(p);
        c_encolar(cinv,x);
    }
    free(p);
    return cinv;
}

/**
3.	Dadas dos colas, determinar si sus contenidos son iguales tanto en posición como en datos (solo comparar por la clave),
	sin destruirlas. Utilizar para la resolución del problema una sola cola auxiliar.
 */
// retorna true si son exactamente iguales, caso contrario retorna false.
bool c_ej3_iguales(Cola c1, Cola c2){
    if (c_ej2_contarelementos(c1)!=c_ej2_contarelementos(c2))return false;
    bool igual=true;
    Cola aux=c_crear();
    TipoElemento TEaux;
    TipoElemento TE1;
    TipoElemento TE2;
    int c_cant=c_ej2_contarelementos(c1);
    while(!c_es_vacia(c1)&&igual){//mientras son vacias cola 1 y 2 y sus elementos son iguales
        TE1=c_desencolar(c1);
        TE2=c_desencolar(c2);
        if (TE1->clave!=TE2->clave){igual=false;}
        else{c_encolar(aux,TE1);}
    }
    if(!igual){//si no son iguales salvo el ultimo elemento desencolado
        c_encolar(c1,TE1);
        c_encolar(c2,TE2);
    }
    int i=0;
    while(!c_es_vacia(aux)){//recupero de guerdado en la cola auxiliar 
        TEaux=c_desencolar(aux);
        c_encolar(c1,TEaux);
        c_encolar(c2,TEaux);
        c_cant--;
    }
    if(!igual){
        while(c_cant>i){// re ordena los elementos ya que no la recorro completa si no es igual
            TE1=c_desencolar(c1);
            TE2=c_desencolar(c2);
            c_encolar(c1,TE1);
            c_encolar(c2,TE2);
            i++;
        }
    }
    return igual;
}

/**
4.	Dada una cola de números enteros, no ordenada,
	construir un algoritmo que permita pasar a otra cola todos los elementos que no se repiten en la primera,
	sin destruir el contenido de la cola original y dejándola en su estado inicial.
 */
// Retorna la cola con las claves que no tienen repeticiones, caso contrario si todas se repiten retorna cola vacia.
Cola  c_ej4_colanorepetidos(Cola c){
    TipoElemento x;
    TipoElemento x1;
    Cola Ccopia=c_crear();
    Cola Cresu=c_crear();
    int i=0;int c_cant=c_ej2_contarelementos(c);
    while(c_cant>i){
        x=c_desencolar(c);
        c_encolar(Ccopia,x);
        c_encolar(c,x);
        i++;
    }
    while(!c_es_vacia(Ccopia)){
        x=c_desencolar(Ccopia);
        c_cant=c_ej2_contarelementos(Ccopia); i=0;
        bool esta=false;
        while(c_cant>i&&!c_es_vacia(Ccopia)){
            x1=c_desencolar(Ccopia);
            if(x->clave!=x1->clave){
                c_encolar(Ccopia,x1);
            }else{esta=true;}
            i++;
        }
        if(!esta){c_encolar(Cresu,x);}
    }
    free(Ccopia);
    return Cresu;
}

/**
5.	Dada una cola de valores enteros no repetidos y mayores o iguales a 2,
	obtener todos los valores que son Divisores Totales o parciales.
	Se dice que un valor es Divisor Total si permite dividir a todos los demás valores de la cola en forma exacta.
	Se dice que un divisor es parcial si al menos puede dividir en forma exacta al menos al 50% de la cola (es decir a la mitad de los elementos).
 */
// retorna el valor del divisor total o parcial en la función.   Si no hay ni divisor total ni parcial retornar "0".
// En la variable de referencia "&fuetotal" debe venir solo con true cual el divisor es total, caso contrario false.
int  c_ej5_divisortotal(Cola c, bool *fuetotal); 


/**
6.	Dada una pila y una cola generada con valores al azar retornar en una lista todos los valores comunes a ambas
	y en qué posición ordinal se encontró cada uno en su estructura.  Si existe mas de una vez la primer posicion encontrada.
	No se deben destruir las estructuras originales.
 */ 
// retornar una lista con los valores comunes segun las especificaciones del ejercicio.
// Si no existen valores comunes retornar la lista vacia.
//struct posRep{int posP;int posC};typedef struct posRep *pos;
Lista c_ej6_comunesapilaycola(Pila p, Cola c){
    TipoElemento px,cx;
    Lista l=l_crear(); Pila paux=p_crear();
    int i,j=0;int c_cant=c_ej2_contarelementos(c);
    bool esta;
    while(!p_es_vacia(p)){
        px=p_desapilar(p);
        i=1;j++;esta=false;
        while(c_cant>=i){
            cx=c_desencolar(c);
            if((!esta)&&(px->clave==cx->clave)){
                esta=true;
                pos valor;
                valor=(pos) malloc(sizeof(struct posRep));
                TipoElemento lx=te_crear_con_valor(px->clave,valor);
                ((pos)lx->valor)->posP=j;
                ((pos)lx->valor)->posC=i;
                l_agregar(l,lx);
            }
            c_encolar(c,cx);i++;
        }
        p_apilar(paux,px);
    }
    while(!p_es_vacia(paux)){
        px=p_desapilar(paux);
        p_apilar(p,px);
    }
    free(paux);
    return l;
}


/**
7.	Un negocio tiene 3 ventanillas para atender a sus clientes. Los clientes forman cola en cada ventanilla.
	Un día, dos de los tres empleados que atienden las ventanillas no pueden asistir al trabajo,
	quedando uno solo para atender a las tres colas. Este empleado decide que, a medida que lleguen los clientes,
	atenderá por cierta cantidad de minutos (que denominaremos Q) a cada cola, paseándose por todas las colas equitativamente.
	Se pide que implemente un algoritmo que modele esta situación y dé como resultado el orden en que fueron atendidos los clientes.
 */
// retornar la cola con los resultados de la atenciones de los clientes.  Ver el ejemplo en el PDF del TP.
// retornar en la clave el nro de cola que lo atendio y en el void* de cada elemento los textos "Cliente 1 Cola 3", Cliente 1 Cola 2, etc.
// Segun el ejemplo el primer item de la cola seria clave: 3, void* "Cliente 1 Cola 3".
// Si las colas estan vacias, retornar cola vacia.
Cola c_ej7_atenderclientes(Cola c1, Cola c2, Cola c3, int tiempoatencion);