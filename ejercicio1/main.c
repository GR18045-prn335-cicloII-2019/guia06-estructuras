#include <stdio.h>
#include <stdlib.h>

struct nodo{
    int info;
    struct nodo*sig;
};

//vardiable global que apunta al primer nodo de la lista
struct nodo*raiz=NULL;

void insertar(int x){
    struct nodo*nuevo;
    nuevo=malloc(sizeof(struct nodo));
    nuevo->info=x;
    if(raiz==NULL){
        raiz=nuevo;
        nuevo->sig=NULL;
    }
    else{
        nuevo->sig=raiz;
        raiz=nuevo;
    }
}
void imprimir(){
    struct nodo*reco=raiz;
    printf("Lista completa.\n");
    while (reco!=NULL){
        printf("%i",reco->info);
        printf("\n");
        reco=reco->sig;
    }
    printf("\n");
}
int extraer(){
    if(raiz!=NULL){
        int informacion=raiz->info;
        struct nodo*bor=raiz;
        raiz=raiz->sig;
        free(bor);
        return informacion;
    }
}

void liberar(){
struct nodo*reco=raiz;
struct nodo*bor;
while (reco!=NULL){
    bor=reco;
    reco=reco->sig;
    free(bor);
}
}

int calcularTamanio(){
    int contador=0;
    struct nodo*reco=raiz;
    printf("Calcular tamanio.\n");
    while (reco!=NULL){
        contador=contador+1;
        reco=reco->sig;
    }
    //printf("el tamanio es: %d \n",contador);
    return contador;
}

int isEmpty(){
    struct nodo*reco=raiz;
    if((raiz->info)){
        return 1;
    }else{
        return 0;
    }
}

int main() {
    insertar(10);
    insertar(40);
    insertar(3);
    if(calcularTamanio()==1){
        printf("la pila esta vacia");
    }else{
        printf("la pila no esta vacia");
    }
    imprimir();
    printf("hay: %i nodos",calcularTamanio());
    printf("extraemos de la pila:%i\n",extraer());
    if(calcularTamanio()){
        printf("la pila esta vacia");
    }else{
        printf("la pila no esta vacia");
    }
    imprimir();
    liberar();
    return 0;
}