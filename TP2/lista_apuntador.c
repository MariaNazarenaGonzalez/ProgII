#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include "tipo_elemento.h"
#include "lista.h"
static const int TAMANIO_MAXIMO = 100;

struct Nodorep {
    TipoElemento Dato;
    struct Nodorep *N_sig;
};
struct ListaRep{
    int cantidad;
    struct Nodorep *N_prim;
};
typedef struct ListaRep *Lista;
struct IteradorRep{
    struct Nodorep *N_actual;
};
typedef struct IteradorRep *Iterador;

// Operaciones del TAD

Lista l_crear (){
    Lista l=(Lista)malloc(sizeof(struct ListaRep));
    l->N_prim=NULL;
    l->cantidad=0;
    return l;
}

bool l_es_vacia (Lista lista){
    return (lista->cantidad==0);
}

bool l_es_llena (Lista lista){
    return (lista->cantidad==TAMANIO_MAXIMO);
}

int l_longitud (Lista lista){
    return lista->cantidad;
}

bool l_agregar (Lista lista, TipoElemento elemento){
    if(l_es_llena(lista)){return false;}
    struct Nodorep *n_nuevo=(struct Nodorep *)malloc(sizeof(struct Nodorep));
    n_nuevo->Dato=elemento;
    n_nuevo->N_sig=NULL;
    if(lista->N_prim==NULL){
        lista->N_prim=n_nuevo;
    }else{
        struct Nodorep * n_temp=lista->N_prim;
        while(n_temp->N_sig!=NULL){
            n_temp=n_temp->N_sig;
        }
        n_temp->N_sig=n_nuevo;
    }
    lista->cantidad++;
    return true;
}

bool l_borrar (Lista lista, int clave){
    if(l_es_vacia(lista)){
        return false;
    }
    struct Nodorep * n_actual=lista->N_prim;
    bool borre=false;
    while(n_actual!=NULL&&n_actual->Dato->clave==clave){
        lista->N_prim=n_actual->N_sig;
        free(n_actual);
        n_actual=lista->N_prim;
        lista->cantidad--;
        borre =true;
    }
    while(n_actual!=NULL&&n_actual->N_sig!=NULL){
        if(n_actual->N_sig->Dato->clave==clave){
            struct Nodorep * n_temp=n_actual->N_sig;
            n_actual->N_sig=n_temp->N_sig;
            free(n_temp);
            lista->cantidad--;
            borre =true;
        }else{
            n_actual=n_actual->N_sig;
        }
    }
    return borre;
}

TipoElemento l_buscar (Lista lista, int clave){
    struct Nodorep *actual = lista->N_prim;
    while (actual != NULL) {
        if (actual->Dato->clave == clave) {
            return actual->Dato;
        }
        actual = actual->N_sig;
    }
    return NULL;
}

bool l_insertar (Lista lista, TipoElemento elemento, int pos){
    if(l_es_llena(lista)){return false;}
    if (pos > l_longitud(lista)) {
        l_agregar(lista, elemento);
        return false;
    }
    struct Nodorep *n_nuevo=(struct Nodorep *)malloc(sizeof(struct Nodorep));
    n_nuevo->Dato=elemento;
    n_nuevo->N_sig=NULL;
    if(pos==1){
        n_nuevo->N_sig=lista->N_prim;
        lista->N_prim=n_nuevo;
        
    }else{
        struct Nodorep * n_temp=lista->N_prim;
        for(int i=1; i<pos-1;i++){
            n_temp=n_temp->N_sig;
        }
        n_nuevo->N_sig=n_temp->N_sig;
        n_temp->N_sig=n_nuevo;
    }
    lista->cantidad++;
    return true;
}

bool l_eliminar (Lista lista, int pos){
    if(l_es_vacia(lista)){return false;}
    struct Nodorep * n_actual=lista->N_prim;
    bool borre = false;
    if(1<=pos&&pos<=l_longitud(lista)){
        if(pos==1){
            lista->N_prim= n_actual->N_sig;
            free(n_actual);
            borre = true;  
        }else{
            for(int i=0; i<pos-2;i++){
                n_actual=n_actual->N_sig;
            }
            struct Nodorep * n_temp=n_actual->N_sig;
            n_actual->N_sig=n_temp->N_sig;
            free(n_temp);
            borre = true;  
        }
        lista->cantidad--;
    }
    return borre;
}

TipoElemento l_recuperar (Lista lista, int pos){
    if (pos > l_longitud(lista)) {
        return NULL;
    }
    // Si existe lo retorno
    struct Nodorep *temp2 = lista->N_prim;
    for (int i = 0; i < pos - 1; i++) {
        temp2 = temp2->N_sig;
    }
    return temp2->Dato;
}


void l_mostrar (Lista lista){
    struct Nodorep *temp2 = lista->N_prim;
    printf("Contenido de la lista: ");
    while (temp2 != NULL) {
        printf("%d ", temp2->Dato->clave);
        temp2 = temp2->N_sig;
    }
    printf("\n");
}


// Funciones de iterador de la lista

Iterador iterador (Lista lista){
    Iterador i=(Iterador)malloc(sizeof(struct IteradorRep));
    i->N_actual=lista->N_prim;
    return i;
}

bool hay_siguiente (Iterador iterador){
    return (iterador->N_actual!=NULL);
}

TipoElemento siguiente (Iterador iterador){
    TipoElemento te=iterador->N_actual->Dato;
    iterador->N_actual=iterador->N_actual->N_sig;
    return te;
}
