#include"tp_pilas.h"
#include<string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/**
    2.	Dada una pila cargada con valores al azar realizar los siguientes ejercicios:
 */

//  a.	Buscar una clave y determinar si existe en la Pila (sin perder la pila).
// Si la encuentra retorna true, caso contrario false
bool p_ej2_existeclave(Pila p, int clave){
    bool ext=false;
    Pila aux=p_crear();
    TipoElemento x;
    while(p_es_vacia(p)!=true && ext!=true){
        x=p_desapilar(p);
        if(x->clave==clave){
            ext=true;
        }
        p_apilar(aux,x);
    }
    while(p_es_vacia(aux)!=true){
        x=p_desapilar(aux);
        p_apilar(p,x);
    }
    free(aux);
    return ext;
}


//  b.	Colocar en una posición ordinal determinada, recibida por parámetro, un nuevo elemento (Insertar un elemento nuevo).
// Retorna la nueva pila con el nuevo elemento, caso contrario la pila original recibida.
Pila p_ej2_colocarelemento(Pila p, int posicionordinal,int clave){
    int i=1;
    Pila aux=p_crear();
    TipoElemento x;
    while(p_es_vacia(p)!=true && i<posicionordinal){
        x=p_desapilar(p);
        p_apilar(aux,x);
        i++;
    }
    p_apilar(p,te_crear(clave));
    while(p_es_vacia(aux)!=true){ 
        x=p_desapilar(aux);
        p_apilar(p,x);
    }
    free(aux);
    return p;
}

//  c.	Eliminar de una pila un elemento dado (primera ocurrencia encontrada por la clave).
// retorna la nueva pila sin la clave, si la encuentra, sino retorna la misma pila que recibio.
Pila p_ej2_eliminarclave(Pila p, int clave){
    bool ext=false;
    Pila aux=p_crear();
    TipoElemento x;
    while(p_es_vacia(p)!=true && ext!=true){
        x=p_desapilar(p);
        if(x->clave==clave){
            ext=true;
        }
        p_apilar(aux,x);
    }
    if (ext){
        x=p_desapilar(aux);
    }
    while(p_es_vacia(aux)!=true){
        x=p_desapilar(aux);
        p_apilar(p,x);
    }
    free(aux);
    return p;
}

//  d.	Intercambiar los valores de 2 posiciones ordinales de la pila, por ejemplo la 2da con la 4ta.
// retorna la nueva pila con las posiciones cambiadas, siempre que sea posible haerlo, caso contrario retorna la pila recibida.
Pila p_ej2_intercambiarposiciones(Pila p, int pos1, int pos2){
    if (p_es_vacia(p) || pos1 > p_ej2_cantidadelementos(p) || pos2 > p_ej2_cantidadelementos(p))return p;
    else if(pos1 == pos2) return p;
    int prim;
    int seg;
    if (pos1 < pos2) {
        prim = pos1;
        seg = pos2;}
    else {
        prim = pos2;
        seg = pos1;
    }
    int cont = 0;
    int longitud =p_ej2_cantidadelementos(p) + 1;
    TipoElemento TEaux;
    TipoElemento TEprim;
    TipoElemento TEseg;
    Pila Paux = p_crear();
    while (p_es_vacia(p)!=true) {
        cont++;
        TEaux = p_desapilar(p);

        if      (cont == seg) TEseg = TEaux;
        else if (cont == prim) TEprim = TEaux;

        p_apilar(Paux, TEaux);
    }
    cont = 0;
    while (p_es_vacia(Paux)!= true) {
        cont++;
        TEaux = p_desapilar(Paux);
        if(cont == longitud - prim){
            p_apilar(p, TEseg);}
        else if (cont == longitud - seg){
            p_apilar(p, TEprim);}
        else {p_apilar(p, TEaux);}
    }
    free(Paux);
    return p;
}

//  e.	Duplicar el contenido de una pila.
// retorna la nueva pila. Si esta vacia retorna otra vacia.
Pila p_ej2_duplicar(Pila p){
    Pila Pdup=p_crear();
    Pila aux=p_crear();
    TipoElemento x;
    while(p_es_vacia(p)!=true){
        x=p_desapilar(p);
        p_apilar(aux,x);
    }
    while(p_es_vacia(aux)!=true){
        x=p_desapilar(aux);
        p_apilar(p,x);
        p_apilar(Pdup,x);
    }
    free(aux);
    return Pdup;
}

//  f.	Contar los elementos de la pila.
// retorna la cantidad de elementos de la pila. Si esta vacia retorna 0 (cero).
int p_ej2_cantidadelementos(Pila p){
    int cant=0;
    Pila aux=p_crear();
    TipoElemento x;
    while(p_es_vacia(p)!=true ){
        x=p_desapilar(p);
        p_apilar(aux,x);
        cant ++;
    }
    while(p_es_vacia(aux)!=true){
        x=p_desapilar(aux);
        p_apilar(p,x);
    }
    free(aux);
    return cant;
}

/**
 3.	Dadas dos pilas, determinar si sus contenidos son exactamente iguales (solo por la clave), sin destruirlas.
	Utilizar para la resolución del problema una única pila auxiliar.
	Determinar la complejidad algorítmica de la solución.
 */
// retorna true si son exactamente iguales, caso contrario retorna false
bool p_ej3_iguales(Pila p1, Pila p2){
    if (p_ej2_cantidadelementos(p1)!=p_ej2_cantidadelementos(p2))return false;
    bool igual=true;
    Pila aux=p_crear();
    TipoElemento TEaux;
    TipoElemento TE1;
    TipoElemento TE2;
    while(p_es_vacia(p1)!=true && igual){
        TE1=p_desapilar(p1);
        TE2=p_desapilar(p2);
        if (TE1->clave!=TE2->clave){
            igual=false;
        }else {
            p_apilar(aux,TE1);
        }
    }
    if (igual!=true){
        p_apilar(p1,TE1);
        p_apilar(p2,TE2);
    }
    while(p_es_vacia(aux)!=true){
        TEaux=p_desapilar(aux);
        p_apilar(p1,TEaux);
        p_apilar(p2,TEaux);
    }
    free(aux);
    return igual;
}


/**
 4.	Construir un algoritmo que, utilizando el TAD Pila, permita convertir un número decimal pasado como parámetro,
	a su correspondiente valor expresado en una base de 2 a 16 (hexadecimal).
	Determinar la complejidad algorítmica de la solución.
 */
// retorna el valor cambiado de base como un string (char*).  Si la base no esta entre 2 y 16 retorno el mismo numero recibido como string (char*).
char*  p_ej4_cambiarbase(int nrobasedecimal, int nrootrabase){//O(n)->lineal
    char * inversa;
    TipoElemento x;
    Pila Paux=p_crear();
    int aux,i=0;
    if( nrootrabase<=16){
        while(nrobasedecimal>0){
            char c[]="0123456789ABCDEF";
            aux=nrobasedecimal% nrootrabase;
            aux=(int)c[aux];
            x=te_crear(aux);
            p_apilar(Paux,x);
            nrobasedecimal=nrobasedecimal/ nrootrabase;
            i++;
        }
        if(i>0){
            inversa=(char*)calloc(i+1,sizeof(char));
            inversa[i]=0;
            i=0;
            while(!p_es_vacia(Paux)){
                x=p_desapilar(Paux);
                inversa[i]=x->clave;
                i++;
            }
        }
    }
    return inversa;
}

/**
 5.	Invertir el contenido de una pila sin destruir la pila original.
	Se debe retornar la nueva pila invertida y la original no se debe perder.
	Determinar la complejidad algorítmica de la solución.
 */
Pila  p_ej5_invertir(Pila p){//O(n)->lineal
    Pila aux=p_crear();
    Pila invertida=p_crear();
    TipoElemento x;
    while(p_es_vacia(p)!=true){
        x=p_desapilar(p);
        p_apilar(aux,x);
        p_apilar(invertida,x);
    }
    while(p_es_vacia(aux)!=true){
        x=p_desapilar(aux);
        p_apilar(p,x);
    }
    return invertida;
}

/**
6.	Dada una pila con valores al azar eliminar todas las ocurrencias de un determinado ítem sin perder la pila original.
	Deberá retornar una nueva pila sin el ítem en consideración.
	Resolver iterativamente y recursivamente.
	Determinar la complejidad algorítmica de ambas soluciones.
 */
// retornar la nueva pila sin la clave que se debe sacar (eliminar). Si la clave no esta se retorna la pila recibida.
// La definicion vale para ambas resoluciones
Pila p_ej6_eliminarclave(Pila p, int clave){//O(n)->lineal
    Pila Paux=p_crear();
    Pila Pborrada=p_crear();
    TipoElemento x;
    while (p_es_vacia(p)!= true){
        x=p_desapilar(p);
        p_apilar(Paux,x);
    }
    while(p_es_vacia(Paux)!= true){
        x=p_desapilar(Paux);
        if(x->clave!=clave){
            p_apilar(Pborrada,x);
        }
        p_apilar(p,x);
    }
    free(Paux);
    return Pborrada;
}

/**
7.	Dada dos pilas realizar una función que permita determinar los elementos que tienen en común.
	Debe retornar una nueva pila con esos elementos (que están en ambas pilas) sin perder las pilas originales.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves en comun de ambas Pilas recibidas por parametro.  Si no hay claves en comun retornar una pila vacia.
Pila p_ej7_eliminarclave(Pila p1, Pila p2){//O(n^2)->cuadratica
    Pila Pcont=p_crear();
    Pila aux1=p_crear();
    Pila aux2=p_crear();
    TipoElemento x1;
    TipoElemento x2;
    while(p_es_vacia(p1)!=true){
        x1=p_desapilar(p1);
        bool esta=false;
        int c=x1->clave;
        while(p_es_vacia(p2)!=true){
            x2=p_desapilar(p2);
            if(c==x2->clave){
                p_apilar(Pcont,x1);
            }
            p_apilar(aux2,x2);
        }
        while(p_es_vacia(aux2)!=true){
            x2=p_desapilar(aux2);
            p_apilar(p2,x2);
        }
        p_apilar(aux1,x1);
    }
    while(p_es_vacia(aux1)!=true){
        x1=p_desapilar(aux1);
        p_apilar(p1,x1);
    }
    return Pcont;
}

/**
8.	Dada una pila con valores repetidos, se desea obtener una nueva pila con todos los valores (sin repetición) y la cantidad de veces que aparecen.
	No debe perderse la pila original.  El proceso recibe la pila con las repeticiones  y retorna una nueva pila.
	Determinar la complejidad algorítmica de la solución.
 */
// retornar la nueva pila con las claves unicas (no deben existir repetidas) y por cada una la cantidad de veces que aparecia en la Pila recibida por parametro
// Si la pila estavacia retorna pila vacia.
Pila p_ej8_sacarrepetidos(Pila p){//O(n^2)->cuadratica
    int prim =1;
    Pila pr=p_crear();
    Pila aux=p_crear();Pila aux1=p_crear();
    TipoElemento x;TipoElemento x1;
    while(p_es_vacia(p)!= true){
        x=p_desapilar(p);
        bool esta=false;
        int *valor=(int*)malloc(sizeof(int));
        (*valor)=1;
        while(p_es_vacia(pr)!=true&& esta!=true){
            x1=p_desapilar(pr);
            if(x->clave==x1->clave){
                (*(int*)x1->valor)++;
                esta=true;
            }
            p_apilar(aux1,x1);
        }
        while(p_es_vacia(aux1)!=true){
            x1=p_desapilar(aux1);
            p_apilar(pr,x1);
        }
        if(!esta){
            p_apilar(pr,te_crear_con_valor(x->clave,valor));
        }
        p_apilar(aux,x);
    }
    while(p_es_vacia(aux)!=true){
        x=p_desapilar(aux);
        p_apilar(p,x);
    }
    return pr;
}