/*todavia no vimos compo se resuelve*/

#include <stdlib.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "lista.h"
static const int TAMANIO_MAXIMO = 100;
static const int NULO=-1;
struct Nodo {
    TipoElemento Dato;
    int sig;
};

struct ListaRep{
    struct Nodo * cursor;
    int inicio;
    int libre;
    int cantidad;
};
typedef struct ListaRep *Lista;
struct IteradorRep{
    Lista lista;
    int pos_actual;
};
typedef struct IteradorRep *Iterador;

// Operaciones del TAD

Lista l_crear (){
    Lista l=(Lista)malloc(sizeof(struct ListaRep *));
    l->cursor=calloc(TAMANIO_MAXIMO,sizeof(struct Nodo));
    l->cantidad=0;
    l->inicio=NULO;
    for(int i=0;i<TAMANIO_MAXIMO-2;i++){
        l->cursor[i].sig=i+1;
    }
    l->libre=0;
    l->cursor[TAMANIO_MAXIMO-1].sig=NULO;
    return l;
}
//Crea la lista vacía. Retorna el puntero a la misma.

bool l_es_vacia (Lista lista){
    return (lista->libre==NULO);
}
// determinar si la lista esta vacía. Retorna “true” cuando esto sucede, caso contrario retorna “False”.

bool l_es_llena (Lista lista){
    return (lista->cantidad==TAMANIO_MAXIMO);
}
//determinar si la lista esta llena. Retorna “true” cuando esto sucede, caso contrario retorna “False”.

int l_longitud (Lista lista){
    return lista->cantidad;
}
//determinar la cantidad de elementos de la lista.

bool l_agregar (Lista lista, TipoElemento elemento){
    if(l_es_llena(lista)){return false;}
    int p;
    p=lista->libre;
    lista->libre=lista->cursor[p].sig;
    lista->cursor[p].Dato=elemento;
    lista->cursor[p].sig=NULO;
    if(lista->inicio==NULO){
        lista->inicio=p;
    }else{
        int q=lista->inicio;
        while(lista->cursor[q].sig==NULO){
            q=lista->cursor[q].sig;
        }
        lista->cursor[q].sig=p;
    }
    lista->cantidad++;
    return true;
}
//Agrega un elemento al final de la lista, incrementando la cantidad de elementos de la misma.

bool l_borrar (Lista lista, int clave){
    if (l_es_vacia(lista)) {return false;}

    bool borre = false;int q;
    int p = lista->inicio;

    // borro las claves que coinciden con el inicio
    while ((p != NULO) && (lista->cursor[p].Dato->clave == clave)) {
        q = p;
        lista->inicio = lista->cursor[p].sig;
        // recupero el nodo en el libre para no perderlo
        lista->cursor[q].sig = lista->libre;
        lista->libre = q;
        // Descuento 1 y arranco de nuevo desde el inicio
        lista->cantidad--;
        p = lista->inicio;
        borre = true;
    }

    // Borro las claves en el resto de la lista
    int qant;
    p = lista->inicio;
    while (p != NULO) {
        // pregunto por uno adelantado
        if (lista->cursor[p].Dato->clave == clave) {
            q = p;
            lista->cursor[qant].sig = lista->cursor[p].sig;
            // Preservo en el libre
            lista->cursor[q].sig = lista->libre;
            lista->libre = q;
            lista->cantidad--;
            p = qant;  //vuelvo a tomar el qant para revisar que no existan otras claves iguales
            borre = true;
        } else {
            qant = p;  // guardo el anterior
            p = lista->cursor[p].sig;
        }
    }
    return borre;
}
/*Borra un elemento de lista. 
Recibe como parámetro la lista y la clave a borrar.
En caso de tener claves repetidas borrará todas las
ocurrencias.*/

TipoElemento l_buscar (Lista lista, int clave){
    int p = lista->inicio;
    while (p != NULO) {
        if (lista->cursor[p].Dato->clave == clave) {
            return lista->cursor[p].Dato;
        }
        p = lista->cursor[p].sig;
    }
    return NULL;
}
/* Busca un elemento en la lista recorriéndola.
Si hay repetidos retorna la primer ocurrencia.
Si la clave a buscar no existe retorna la constante “NULL”.*/

bool l_insertar (Lista lista, TipoElemento elemento, int pos){
    // Controla si la posicion ordinal es mayor a la cantidad
    // llama automaticamente al agregar
    if (pos > l_longitud(lista)) {
        l_agregar(lista, elemento);
        return false;
    }

    // Sino asigna espacio tomando del libre
    int p = lista->libre;
    lista->libre = lista->cursor[p].sig;
    lista->cursor[p].Dato = elemento;
    lista->cursor[p].sig = NULO;

    // valida si es la primer posicion
    if (pos == 1) {
        lista->cursor[p].sig= lista->inicio;
        lista->inicio = p;
    } else {
        int temp2 = lista->inicio;
        for (int i = 0; i < pos - 2; i++) {
            temp2 = lista->cursor[temp2].sig;
        }
        lista->cursor[p].sig = lista->cursor[temp2].sig;
        lista->cursor[temp2].sig = p;
    }
    // Cuenta uno mas
    lista->cantidad++;
    return true;
}
// Inserta un elemento en las posición “pos” dentro de la lista. Incrementa la cantidad.-

bool l_eliminar (Lista lista, int pos){
    int p;
    bool borre = false;
    int actual = lista->inicio;

    if (1 <= pos && pos <= l_longitud(lista)) {
        if (pos == 1) {
            p = actual;
            lista->inicio = lista->cursor[actual].sig;
            lista->cursor[p].sig = lista->libre;
            lista->libre = p;
	    borre = true;
        } else {
            for (int i = 0; i < pos - 2; i++) {
                actual = lista->cursor[actual].sig;
            }
            // actual apunta al nodo en posición (pos - 1)
            p = lista->cursor[actual].sig; // nodo en pos
            lista->cursor[actual].sig = lista->cursor[p].sig; // nodo en pos + 1
            lista->cursor[p].sig = lista->libre;
            lista->libre = p;
            borre = true;
        }
        lista->cantidad--;
    }
    return borre;
}
/*Elimina una posición de la lista sin importar el dato que esta en 
esa posición.
Se diferencia de la función borrar porque el “borrar” elimina a 
partir de una clave y borra todas las ocurrencias.*/

TipoElemento l_recuperar (Lista lista, int pos){
    int temp2 = lista->inicio;
    for (int i = 0; i < pos - 1; i++) {
        temp2 = lista->cursor[temp2].sig;
    }
    return lista->cursor[temp2].Dato;
}
//retorna el elemento (dato) de la posición “pos” recibida como parámetro.

void l_mostrar (Lista lista){
    int q=lista->inicio;
    printf("mostrar el contenido de la lista:\n");
    while(lista->cursor[q].sig==NULO){
        prinf("%i\n",lista->cursor[q].Dato->clave);
        q=lista->cursor[q].sig;
    }
}
//Muestra las claves de lista en la pantalla.


// Funciones de iterador de la lista

Iterador iterador(Lista lista) {
    Iterador iter = (Iterador) malloc(sizeof(struct IteradorRep));
    iter->lista = lista;
    iter->pos_actual = lista->inicio;
    return iter;
}


bool hay_siguiente(Iterador iterador) {
    return (iterador->pos_actual != NULO);
}


TipoElemento siguiente(Iterador iterador) {
    TipoElemento actual = iterador->lista->cursor[iterador->pos_actual].Dato;
    iterador->pos_actual = iterador->lista->cursor[iterador->pos_actual].sig;
    return actual;
}