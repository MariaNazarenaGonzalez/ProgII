#include "tp_arboles.h"


/**
2.	Dado un árbol binario no vacío determinar:  
 */

//  a.	Retornar una lista con todos los nodos terminales u hojas.
void a_ej2_hojasR(NodoArbol N,Lista L){
    if((n_hijoderecho(N)==NULL)&&(n_hijoizquierdo(N)==NULL)){
        TipoElemento x=n_recuperar(N);
        l_agregar(L,x);
    }else{
        a_ej2_hojasR(n_hijoizquierdo(N),L);
        a_ej2_hojasR(n_hijoderecho(N),L);
    }
}

Lista a_ej2_hojas(ArbolBinario A){
    Lista L=l_crear();
    a_ej2_hojasR(a_raiz(A),L);
    return L;
}

//  b.	Retornar en una estructura todos los nodos interiores (los que no son ni hojas ni raíz)
void a_ej2_interioresR(NodoArbol N,Lista L,ArbolBinario a){
    if(((n_hijoderecho(N)!=NULL)||(n_hijoizquierdo(N)!=NULL))&&(a_raiz(a)!=N)){
        TipoElemento x=n_recuperar(N);
        l_agregar(L,x);
    }else{
        a_ej2_interioresR(n_hijoizquierdo(N),L,a);
        a_ej2_interioresR(n_hijoderecho(N),L,a);
    }
}

Lista a_ej2_interiores(ArbolBinario A){
    Lista L=l_crear();
    a_ej2_interioresR(a_raiz(A),L,A);
    return L;
}

//  c.	Buscar todas las ocurrencias de una clave dentro del árbol. Retornar la posición de cada ocurrencia (puntero al nodo).
void  a_ej2_buscarR(NodoArbol N, int clave,Lista L){
    if(N!=NULL){
        TipoElemento x=n_recuperar(N);
        if(x->clave==clave){
            l_agregar(L,x);
        }
        a_ej2_buscarR(n_hijoizquierdo(N),clave,L);
        a_ej2_buscarR(n_hijoderecho(N),clave,L);
    }
}

Lista a_ej2_buscarclave(ArbolBinario A, int clave){
    Lista L=l_crear();
    a_ej2_buscarR(a_raiz(A),clave,L);
    return L;
}

/**
3.	Para un nodo del árbol binario determinado:

 */

// a.	Indicar el nombre del nodo padre (clave).
void a_ej3_clavepadreR(NodoArbol actual, NodoArbol hijo, bool *encontrado, NodoArbol *retorno) {
    if (actual != NULL) {
        if (n_hijoizquierdo(actual) == hijo || n_hijoderecho(actual) == hijo) {
            *encontrado = true;
            *retorno = actual;
        }
        else {
            a_ej3_clavepadreR(n_hijoizquierdo(actual), hijo, encontrado, retorno);
            a_ej3_clavepadreR(n_hijoderecho(actual), hijo, encontrado, retorno);
        }
    }
}

int a_ej3_clavepadre(ArbolBinario A, int clavehijo){
    //if (A == NULL || clavehijo == n_recuperar(a_raiz(A))->clave )return 0;

    NodoArbol hijo =n_crear(te_crear(clavehijo));
    bool encontrado = false;
    NodoArbol retorno = NULL;
    a_ej3_clavepadreR(a_raiz(A), hijo, &encontrado, &retorno);
    return n_recuperar(retorno)->clave;
    //if (retorno != NULL) 
    //else                 return 0;
}

// b.	Listar los hijos (solo las clave/s).
void a_ej3_hijosR(NodoArbol NP, int clavepadre,Lista L){
    if((n_hijoderecho(NP)!=NULL)||(n_hijoizquierdo(NP)!=NULL)){
        NodoArbol ND,NI;
        TipoElemento XP,XD,XI;
        XP=n_recuperar(NP);
        if(XP->clave==clavepadre){
            ND=n_hijoderecho(NP);
            NI=n_hijoizquierdo(NP);
            XD=n_recuperar(ND);
            XI=n_recuperar(NI);
            if(ND!=NULL){l_agregar(L,XD);}
            if(NI!=NULL){l_agregar(L,XI);}
        }else{
            a_ej3_hijosR(n_hijoderecho(NP),clavepadre,L);
            a_ej3_hijosR(n_hijoizquierdo(NP),clavepadre,L); 
        }
    }
}

Lista a_ej3_hijos(ArbolBinario A, int clavepadre){
    Lista L=l_crear();
    a_ej3_hijosR(a_raiz(A),clavepadre,L);
    return L;
}

// c.	Listar el hermano (solo la clave).
void a_ej3_hermanoR(NodoArbol N, int clave,int* hermano){
    if(N!=NULL){
        TipoElemento x1=n_recuperar(n_hijoderecho(N));
        TipoElemento x2=n_recuperar(n_hijoizquierdo(N));
        if((x1->clave==clave)||(x2->clave==clave)){
            if(x1->clave==clave){
                *hermano= x2->clave;
            }else{
                *hermano= x1->clave;
            }
        }else{
            return a_ej3_hermanoR(n_hijoderecho(N),clave,hermano);
            return a_ej3_hermanoR(n_hijoizquierdo(N),clave,hermano);
        }
    }
}

int a_ej3_hermano(ArbolBinario A, int clave){
    int hermano=0;
    a_ej3_hermanoR(a_raiz(A),clave,&hermano);
    return hermano;
}

// d.	Calcular el nivel en el que se encuentra.
void a_ej3_nivelR(NodoArbol actual, int clave, int *nivel, int cant) {
    if (actual != NULL) {
        TipoElemento x = n_recuperar(actual);

        if (x->clave == clave) *nivel = cant;

        else {
            a_ej3_nivelR(n_hijoizquierdo(actual), clave, nivel, cant+1);
            a_ej3_nivelR(n_hijoderecho(actual), clave, nivel, cant+1);
        }
    }
}


int a_ej3_nivel(ArbolBinario a, int clave) {
    if (a_raiz(a) == NULL) return -1;
    else if ((n_recuperar(a_raiz(a)))->clave == clave)    return 0;

    int nivel = -1;
    a_ej3_nivelR(a_raiz(a), clave, &nivel, 0);
    return nivel;
}

// e.	Calcular la altura de su rama (Altura del Subárbol)

void a_ej3_alturaramaR(NodoArbol actual, int *altura, int suma) {
    if (actual != NULL) {

        suma++;
        *altura = suma;

        a_ej3_alturaramaR(n_hijoizquierdo(actual), altura, suma);
        a_ej3_alturaramaR(n_hijoderecho(actual), altura, suma);
    }
}

//funcion interna 
void a_buscarR(NodoArbol N, int clave,NodoArbol* retorna){
    if(N!=NULL){
        TipoElemento x=n_recuperar(N);
        if(x->clave==clave){
            *retorna =N;
        }else{
            a_buscarR(n_hijoderecho(N),clave,retorna);
            a_buscarR(n_hijoizquierdo(N),clave,retorna); 
        }
    }
}

int a_ej3_alturarama(ArbolBinario A, int clave){
    NodoArbol n;
    a_buscarR(a_raiz(A),clave,&n);
    if (n == NULL) return -1;

    int altura = 0;
    a_ej3_alturaramaR(n, &altura, 0);
    return altura;
}

// f.	Listar todos los nodos que están en el mismo nivel (solo la clave).
void a_ej3_clavesmismonivelR(NodoArbol raiz, int nivel, Lista L) {
    if (raiz != NULL) {
        if (nivel == 0) l_agregar(L, n_recuperar(raiz));

        else if (nivel > 0) {
            a_ej3_clavesmismonivelR(n_hijoizquierdo(raiz), nivel - 1, L);
            a_ej3_clavesmismonivelR(n_hijoderecho(raiz), nivel - 1, L);
        }
    }
}

Lista a_ej3_clavesmismonivel(ArbolBinario a, int nivel) {
    if (a_raiz(a) == NULL) return NULL;

    int cont = 0;
    Lista L = l_crear();

    if (nivel == 0) l_agregar(L, n_recuperar(a_raiz(a)));
    else            a_ej3_clavesmismonivelR(a_raiz(a), nivel, L);
    
    return L;
}



/**
4.	Para Árboles “N-arios”:
 */
// a.	Dado un árbol n-ario, devolver en forma de lista el resultado del recorrido en anchura del árbol  (solo las claves).
Lista a_ej4_anchura(ArbolBinario A);

// b.	Escribir una función que, dado un árbol n-ario, devuelva el número (cantidad) de hojas de dicho árbol.
int a_ej4_q_hojas(ArbolBinario A);

// c.	Escribir una función booleana que dados dos árboles generales determine si tienen la misma estructura, sin importar los datos del mismo (árbol similar).
bool a_ej4_similares(ArbolBinario A, ArbolBinario B);

// d.	Retornar el padre de un nodo del árbol (tipo_elemento).
TipoElemento a_ej4_padre(ArbolBinario A, int clave);

// e.	Retornar los hermanos de un nodo del árbol (lista de hermanos).
Lista a_ej4_hermanos(ArbolBinario A, int clave);



/**
7.	Determinar si dos árboles binarios son equivalentes.
 */

bool a_ej7_equivalenteR(NodoArbol AB1,NodoArbol AB2){
    bool ret=true;
    TipoElemento x1,x2;
    if ((AB1 != NULL)&&(AB2 != NULL)){
        x1=n_recuperar(AB1);
        x2=n_recuperar(AB2);
        if(x1->clave!=x2->clave){
            ret=false;
            return ret;
        }
        ret=a_ej7_equivalenteR(n_hijoizquierdo(AB1),n_hijoizquierdo(AB2));
        ret=a_ej7_equivalenteR(n_hijoderecho(AB1),n_hijoderecho(AB2));
    }else if ((AB2 != NULL)||(AB1 != NULL)){
        ret=false;
        return ret;
        }
    return ret;
}
bool a_ej7_equivalente(ArbolBinario A, ArbolBinario B){
    bool x;
    x=a_ej7_equivalenteR(a_raiz(A),a_raiz(B));
    return x;
}
/**
8.	Dado un árbol “n-ario” se pide:
 */
// a.	Determinar la altura del mismo.
int c_ej8_altura(ArbolBinario A);

// b.	Determinar el nivel de un nodo.
int c_ej8_nivel(ArbolBinario A, int clave);

// c.	Listar todos los nodos internos (solo las claves).
Lista c_ej8_internos(ArbolBinario A);

// d.	Determinar si todas las hojas están al mismo nivel.
bool c_ej8_hojasmismonivel(ArbolBinario A);


/**
9.	Generar un algoritmo, recursivo o no, que permita construir un árbol binario de búsqueda balanceado (AVL) 
	a partir de un árbol binario sin un orden determinado.  
	Comparar las alturas de ambos árboles. Determinar la complejidad algorítmica.
 */
// Primero llamamos para construir el AVL
void a_ej9_construiravlR(ArbolAVL AVL,NodoArbol N){
    if(N!= NULL){
        TipoElemento X=n_recuperar(N);
        avl_insertar(AVL,X);
        a_ej9_construiravlR(AVL,n_hijoizquierdo(N));
        a_ej9_construiravlR(AVL,n_hijoderecho(N));
    }
}

ArbolAVL a_ej9_construiravl(ArbolBinario A){
    ArbolAVL AVL=avl_crear();
    a_ej9_construiravlR(AVL,a_raiz(A));
    return AVL;
}

// Luego con el resultado de la funcion anterior llamamos a una funcion para que nos retorne la diferencia de las alturas 
// comparadas como Altura(ArbolBinario) - Altura(ArbolAVL).
int a_ej9_diferenciaalturas(ArbolBinario A, ArbolAVL AVL){
    int AltA=0;
    int AltAVL=0;
    a_ej3_alturaramaR(a_raiz(A),&AltA,0);
    a_ej3_alturaramaR(avl_raiz(AVL),&AltAVL,0);
    return AltA - AltAVL;
}


/**
10.	Dada una serie de números generados al azar, cargar la misma serie en un árbol binario de búsqueda y en un árbol binario balanceado “AVL”.  
	Comparar la altura de ambos árboles.  
	Repetir el proceso “n” veces. 
	¿Qué puede concluir al respecto?
 */
// Generamos una lista con la serie de numeros (unicos no repetidos)
Lista a_ej10_generarlistaclaves(int cantidadclavesagenerar, int valorminimo, int valormaximo);

// Ahora se la paso a la funcion que crea los 2 arboles
ArbolBinarioBusqueda a_ej10_crearABB(Lista L);
ArbolAVL a_ej10_crearAVL(Lista L);

// Ahora llamos a la funcion que compara las alturas.  La comparacion es Altura(ABB) - Altura(AVL).
int a_ej10_difalturas(ArbolBinarioBusqueda ABB, ArbolAVL AVL);

// Este proceso se debera repetir N veces  (N se debera poder tomar por teclado).

// LLamada general del proceso.  retorna una lista con todas las diferencias de las comparaciones.
Lista a_ej10_comparacionarboles(int N_repeticiones, int valorminimo, int valormaximo, int cantidaclavesagenerar);