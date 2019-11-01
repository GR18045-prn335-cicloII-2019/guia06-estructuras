#include <stdio.h>
#include <stdlib.h>

//declaramos dos pilas la original, y donde guardaremos la invertida
struct nodoPrimero{
    int dato;
    struct nodoPrimero*siguiente;
};
struct nodoSegundo{
    int dato;
    struct nodoPrimero*siguiente;
};

//variables que apuntan a los primeros nodos de las pilas
struct nodoPrimero*raiz=NULL;
struct nodoSegundo*raiz2=NULL;

//funcion para poder insertar un nuevo nodo a la pila 1
void insertarPila1(int x){
    struct nodoPrimero *nuevo;
    nuevo = malloc(sizeof(struct nodoPrimero));
    nuevo->dato=x;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->siguiente=NULL;
    } else{
        nuevo->siguiente=raiz;
        raiz=nuevo;
    }
}
//funcion para poder insertar un nuevo nodo a la pila 2
void insertarPila2(int x){
    struct nodoSegundo *nuevo;
    nuevo = malloc(sizeof(struct nodoSegundo));
    nuevo->dato=x;
    if(raiz2==NULL){
        raiz2=nuevo;
        nuevo->siguiente=NULL;
    } else{
        nuevo->siguiente=raiz2;
        raiz2=nuevo;
    }
}
//funcion para imprimir toda la pila 1
void imprimirPila1(){
    struct nodoPrimero *reco=raiz;
    printf("Pila original.\n");
    while (reco!=NULL){
        printf("%i\n",reco->dato);
        reco=reco->siguiente;
    }
    printf("\n");
}
//funcion para imprimir toda la pila 2
void imprimirPila2(){
    struct nodoSegundo *reco=raiz2;
    printf("Pila invertida.\n");
    while (reco!=NULL){
        printf("%i\n",reco->dato);
        reco=reco->siguiente;
    }
    printf("\n");
}
//metodo para invertir las pilas
int invertir(){
    if(raiz!=NULL){
        while (raiz!=NULL){
            struct nodoPrimero *bor=raiz;
            insertarPila2(bor->dato);
            raiz=raiz->siguiente;
            free(bor);
        }
    } else{
        return -1;
    }
}
int main() {
    insertarPila1(10);
    insertarPila1(20);
    insertarPila1(40);
    imprimirPila1();
    invertir();
    imprimirPila2();
    return 0;
}