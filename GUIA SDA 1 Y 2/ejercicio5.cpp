#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

 //prototipo de funciones
int multiplicacion (Nodo *);
void newNodo(Nodo *&, int);

//main
int main() {

    Nodo * list = NULL;

    //ingresando datos a la lista enlazada
    newNodo(list, 1);

    newNodo(list, 2);

    newNodo(list, 3);


    //funcion para contar los nodos
    cout << "la multiplicacion es: " << multiplicacion(list) << endl ;

    return 0;
}

//funciones
void newNodo(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato < n)){
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1){
        lista = nuevo_nodo;
    }
    else{
        aux2->siguiente = nuevo_nodo;
    }

    nuevo_nodo->siguiente = aux1;
    
}

int multiplicacion (Nodo *lista){
    Nodo *actual = new Nodo();
    actual = lista;
    int resul = 1;
    
    if (actual == NULL){
    	return 0;
	}
	else{
		while (actual!=NULL){
    	resul = resul * actual->dato;
    	actual = actual->siguiente;
		}
		return resul;
	}
    
}
