#include<stdio.h>
#include<stdlib.h>


/**
 * declaramos la pila
 */
struct nodo{
    int info;
    struct nodo *sig;
};


/**
 * declaramos el nodo que apunta al primer elemento de la pila
 */
struct nodo *raiz=NULL;


/* * funcion para insertar un dato en la pila
 * @param x
 */
void insertar(int x){
    struct nodo *nuevo;
    //Usamos de malloc por trabajar una memoria dinamica en un nuevo nodo sucesivamente
    nuevo = malloc(sizeof (struct nodo));
    nuevo->info = x;
    //validamos que la raiz sea nula
    if (raiz == NULL) {
        raiz=nuevo;
        nuevo->sig=NULL;
    }else{
        //Ahora el dato "raiz" sera el siguiente que extraeremos despues del que acabamos de ingresar
        nuevo->sig = raiz;
        //El dato ingresado pasa a ser raiz, y a estar en la cima de la pila
        raiz=nuevo;
    }
}

/**
 * funcion para imprimir los datos de la pila
 */
void imprimir(){
    struct nodo *reco=raiz;
    //La funcion funcionará mientras la pila aun tenga datos que mostrar
    while(reco!=NULL){
        //imprimimos la pila
        printf("%i ", reco->info);
        reco=reco->sig;
    }
    printf("\n");
}


/**
 * funcion que busca en la pila el dato ingresado y si encuentra coincidencia lo cambia
 * @param pila
 * @param antiguo
 * @param nuevo
 */
void reemplazar(struct nodo *pila, int antiguo, int nuevo ){
    //Validamos la pila sea diferente a nula
    if(pila != NULL){
        //Mientras la validacion se mantenga se recorrera el bucle
        while(pila!=NULL){
            //validamos que si se encuentra que el valor ingresado esta en la pila
            if(pila->info == antiguo){
                //Se guardara el segundo dato es decir el nuevo elemento
                pila->info = nuevo;
            }
            pila = pila->sig;
        }
    }else{
        printf("No se encontro coincidencia con la pila\n");
    }
}

int main(){
    //Se declaran la variables que haran la funcion de nuevo y antiguo elemento
    int antiguo,nuevo;

    //Ingresamos datos a la pila atravez de la funcion insertar
    insertar(10);
    insertar(40);
    insertar(3);
    insertar(7);
    insertar(3);

    printf("\nLista inicial de la pila :\n");
    imprimir();
    //Pedimos el dato antiguo
    printf("Ingrese el numero antiguo:\n");
    scanf("%d", &antiguo);
    //Pedimos el dato nuevo
    printf("Ingrese el numero nuevo:\n");
    scanf("%d", &nuevo);
    //llamamos la funcion reemplazar e igualmente pasamos los parametros ingresados a la funcion reemplazar
    reemplazar(raiz,antiguo, nuevo);
    printf("\nSe sustituyó el valor antiguo = %d por el valor nuevo ingresado = %d",antiguo,nuevo);
    printf("\nLa lista queda:\n");
    //Imprimimos los datos de la pila atravez de la funcion imprimir
    printf("\nLista final de la pila :\n");
    imprimir();

    return 0;
}