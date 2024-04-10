#include <stdlib.h>
#include <stdbool.h>
#include "tipo_elemento.h"
#include "lista.h"
static const int TAMANIO_MAXIMO = 100;

struct ListaRep{
    TipoElemento *valores;
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
    Lista l=(Lista)malloc(sizeof(struct ListaRep));
    l->valores=(TipoElemento *) calloc(TAMANIO_MAXIMO,sizeof(struct TipoElementoRep));
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
    if(l_es_llena(lista)!=true){
        lista->valores[lista->cantidad]=elemento;
        lista->cantidad++;
        return true;
    }
    return false;
}

bool l_borrar (Lista lista, int clave){
    if(l_es_vacia(lista)){
        return false;
    }
    int pos=0;bool borre=false;
    while(pos<lista->cantidad){
        if(clave==lista->valores[pos]->clave){
            for(int i=pos; i<lista->cantidad-1;i++){
                lista->valores[i]=lista->valores[i+1];
            }
            lista->cantidad--;
            borre =true;
        }else{pos++;}
    }
    return borre;
}

TipoElemento l_buscar (Lista lista, int clave){
    int pos=0;
    while(pos<lista->cantidad){
        if(clave==lista->valores[pos]->clave){
            return lista->valores[pos];
        }
        pos++;
    }
    return NULL;
}

bool l_insertar (Lista lista, TipoElemento elemento, int pos){
    if(1<=pos&& pos>=l_longitud(lista)){
        for(int i=lista->cantidad; i>=pos;i--){
            lista->valores[i]=lista->valores[i-1];
        }
        lista->valores[pos-1]= elemento;
        lista->cantidad++;
        return true;
    }
    return false;
}

bool l_eliminar (Lista lista, int pos){
    if(1<=pos&& pos>=l_longitud(lista)){
        for(int i=pos-1; i<lista->cantidad;i++){
            lista->valores[i]=lista->valores[i+1];
        }
        lista->cantidad--;
        return true;
    }
    return false;
}

TipoElemento l_recuperar (Lista lista, int pos){
    return lista->valores[pos-1];
}

void l_mostrar (Lista lista){
    printf("mostrar el contenido de la lista:\n");
    for(int i=0; i<lista->cantidad;i++){
        printf("%i\n",lista->valores[i]->clave);
    }
}



// Funciones de iterador de la lista

Iterador iterador (Lista lista){
    Iterador i=(Iterador)malloc(sizeof(struct IteradorRep));
    i->lista=lista;
    i->pos_actual=0;
}

bool hay_siguiente (Iterador iterador){
    return iterador->pos_actual<iterador->lista->cantidad;
}

TipoElemento siguiente (Iterador iterador){
    return iterador->lista->valores[iterador->pos_actual++];
}