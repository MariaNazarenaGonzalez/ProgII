/*3. Para un nodo del árbol binario determinado: 
a. Indicar el nombre del nodo padre (clave). 
b. Listar los hijos (solo las clave/s). 
c. Listar el hermano (solo la clave). 
d. Calcular el nivel en el que se encuentra. 
e. Calcular la altura de su rama (Altura del Subárbol)
f. Listar todos los nodos que están en el mismo nivel (solo la clave).*/
#include"tp_arboles.h"
#include"validacion.h"
#include"stdio.h"
ArbolBinario a_cargar(ArbolBinario a);
void a_mostrar_pre_orden(ArbolBinario a);

int main(){
    int clave;
    ArbolBinario A=a_crear();
    A=a_cargar(A);
    printf("Mostrar arbol cargado:\n");
    a_mostrar_pre_orden(A); 
    printf("ingrese clave del nodo a trabajar:\n");
    clave=entero_entre(1,10000);
    printf("Su padre es: %i\n",a_ej3_clavepadre(A,clave));
    printf("El/Los hijo/s es/son:\n");
    Lista hijos=a_ej3_hijos(A,clave);
    l_mostrar(hijos);
    printf("El hermano es: %i\n",a_ej3_hermano(A,clave));
    int nivel=a_ej3_nivel(A,clave);
    printf("El nivel es: %i\n",nivel);
    printf("La altura de la rama (subarbol) es: %i\n",a_ej3_alturarama(A,clave));
    printf("El/los elemento/s que comparten nivel es/son:\n");
    Lista e_nivel=a_ej3_clavesmismonivel(A,nivel);
    l_mostrar(e_nivel);
    return 0;
}

void a_cargarR(NodoArbol N,int pos,ArbolBinario a){
    /*ENTRADA:  N -> nodo padre con el cual se conesta el nuevo nodo
                pos -> entero que toma valores -1,0 y 1 para indicar la posicion den la que se coloca el nuevo nodo
                a -> arbol en el que se cargan los datos*/
    int val;//entero que resive los datos por pantalla
    printf("valor(0=NULL):");
    val=entero_entre(0,10000);//hay que modificar la carga para que e criterio de corte sea un punto
    if(val!=0){//si el valor no es 0(si se quiere cargar el nodo)
        NodoArbol N1;
        if(pos==0){N1 =a_establecer_raiz(a,te_crear(val));}//si el nodo a cargar es la raiz
        else if(pos==1){N1=a_conectar_hd(a,N,te_crear(val));}//si el nodo a cargar es el derecho
        else if(pos==-1){N1=a_conectar_hi(a,N,te_crear(val));}//si el nodo a cargar es el izquierdo
        //llamadas recurcivas para seguir cargando tanto por iz como por der
        a_cargarR(N1,1,a);
        a_cargarR(N1,-1,a);
    }
}

ArbolBinario a_cargar(ArbolBinario a){
    //funcion a modo de mascara que llama a la recurciva
    //el nodo padre Nulo, la posicion en raiz, y el arbol a cargar
    a_cargarR(NULL,0,a);
    return a;
}

void a_mostrar_pre_ordenR(NodoArbol N){
    if(N==NULL){//si nodo nulo muestro un punto
        printf(". ");
    }else{//si lo muestro el dato y llamo a los hijos
        TipoElemento x=n_recuperar(N);
        printf("%i ",x->clave);
        a_mostrar_pre_ordenR(n_hijoderecho(N));
        a_mostrar_pre_ordenR(n_hijoizquierdo(N));
    }
}

void a_mostrar_pre_orden(ArbolBinario a){
    printf("Mostrar en pre_orden\n");
    a_mostrar_pre_ordenR(a_raiz(a));
    printf("\n");
}

