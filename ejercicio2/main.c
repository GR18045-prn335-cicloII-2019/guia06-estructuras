#include <stdio.h>
#include <stdlib.h>

struct nodoPrimero{
    int dato;
    struct nodoPrimero*siguiente;
};
struct nodoSegundo{
    int dato;
    struct nodoPrimero*siguiente;
};

struct nodoPrimero*raiz=NULL;
struct nodoSegundo*raiz2=NULL;

//void agregarPila(nodoPrimero*&pila,int n);

//void agregarPila(struct nodoPrimero *&pila,int n){
  //  struct nodoPrimero nuevoNodo;
//}
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

void imprimirPila1(){
    struct nodoPrimero *reco=raiz;
    printf("Pila original.\n");
    while (reco!=NULL){
        printf("%i\n",reco->dato);
        reco=reco->siguiente;
    }
    printf("\n");
}
void imprimirPila2(){
    struct nodoSegundo *reco=raiz2;
    printf("Pila invertida.\n");
    while (reco!=NULL){
        printf("%i\n",reco->dato);
        reco=reco->siguiente;
    }
    printf("\n");
}

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