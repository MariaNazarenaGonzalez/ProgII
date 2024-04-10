#ifndef LISTAS_H
#define LISTAS_H
#include <stdbool.h>
#include "tipo_elemento.h"

struct ListaRep;
typedef struct ListaRep *Lista;
struct IteradorRep;
typedef struct IteradorRep *Iterador;

// Operaciones del TAD

Lista l_crear ();
//Crea la lista vacía. Retorna el puntero a la misma.

bool l_es_vacia (Lista lista);
// determinar si la lista esta vacía. Retorna “true” cuando esto sucede, caso contrario retorna “False”.

bool l_es_llena (Lista lista);
//determinar si la lista esta llena. Retorna “true” cuando esto sucede, caso contrario retorna “False”.

int l_longitud (Lista lista);
//determinar la cantidad de elementos de la lista.

bool l_agregar (Lista lista, TipoElemento elemento);
//Agrega un elemento al final de la lista, incrementando la cantidad de elementos de la misma.

bool l_borrar (Lista lista, int clave);
/*Borra un elemento de lista. 
Recibe como parámetro la lista y la clave a borrar.
En caso de tener claves repetidas borrará todas las
ocurrencias.*/

TipoElemento l_buscar (Lista lista, int clave);
/* Busca un elemento en la lista recorriéndola.
Si hay repetidos retorna la primer ocurrencia.
Si la clave a buscar no existe retorna la constante “NULL”.*/

bool l_insertar (Lista lista, TipoElemento elemento, int pos);
// Inserta un elemento en las posición “pos” dentro de la lista. Incrementa la cantidad.-

bool l_eliminar (Lista lista, int pos);
/*Elimina una posición de la lista sin importar el dato que esta en 
esa posición.
Se diferencia de la función borrar porque el “borrar” elimina a 
partir de una clave y borra todas las ocurrencias.*/

TipoElemento l_recuperar (Lista lista, int pos);
//retorna el elemento (dato) de la posición “pos” recibida como parámetro.

void l_mostrar (Lista lista);
//Muestra las claves de lista en la pantalla.


// Funciones de iterador de la lista

Iterador iterador (Lista lista);
//Inicializa el iterador para poder hacer un recorrido de la lista.

bool hay_siguiente (Iterador iterador);
//Retorna “true” mientras existen mas elementos por recorrer de la lista. Caso contrario retorna “false”.

TipoElemento siguiente (Iterador iterador);
//Retorna el próximo elemento de la lista a recorrer.

#endif // LISTAS_H