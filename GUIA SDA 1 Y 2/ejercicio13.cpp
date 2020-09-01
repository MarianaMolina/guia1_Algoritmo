#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

 //prototipo de funciones
void newNodoAscen(Nodo *&, int);
void newNodoDecen(Nodo *&, int);
void mostrar (Nodo *);

//main
int main() {

	//creando lista
    Nodo * list = NULL;
    Nodo * list1 = NULL;

    //ingresando datos a la lista enlazada
    newNodoAscen(list, 1);

    newNodoAscen(list, 3);

    newNodoAscen(list, 8);
    
    newNodoAscen(list, 5);


    newNodoDecen(list1, 1);

    newNodoDecen(list1, 3);

    newNodoDecen(list1, 8);
    
    newNodoDecen(list1, 5);

    //funcion para conmostrar los nodos
    cout << "lista Ascendente:  "<< endl;
    mostrar(list);

    cout << "lista Decendente:  "<< endl;
    mostrar(list1);

    return 0;
}

//funciones
void newNodoAscen(Nodo *&lista, int n){
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

void newNodoDecen(Nodo *&lista, int n){
    Nodo *nuevo_nodo = new Nodo();
    nuevo_nodo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    while((aux1 != NULL) && (aux1->dato > n)){
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

void mostrar (Nodo * lista){
	Nodo *actual = new Nodo();
    actual = lista;
	
	if (actual == NULL){
    	cout << "lista vacia";
	}
	else{
		while (actual!=NULL){
    	cout << actual->dato << " , ";
    	actual = actual->siguiente;
		}
	}
}


