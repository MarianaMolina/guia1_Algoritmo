#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

 //prototipo de funciones
void newNodo(Nodo *&, int);
void mostrar (Nodo *);
void impares_pares (Nodo *);

//main
int main() {

	//creando lista
    Nodo * list = NULL;

    //ingresando datos a la lista enlazada
    newNodo(list, 1);

    newNodo(list, 2);

    newNodo(list, 3);
    
    newNodo(list, 4);


    //funcion para contar los nodos
    impares_pares(list);

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


void impares_pares (Nodo *lista){
	Nodo *listPares = NULL;
	Nodo *listImpares = NULL;
	
    Nodo *actual = new Nodo();
    actual = lista;
    
    if (actual == NULL){
    	cout << "lista vacia";
	}
	else{
		
		while (actual!=NULL){ 
		
			if((actual->dato)%2 == 0) { 
                newNodo(listPares, actual->dato);
            }else {
                newNodo(listImpares, actual->dato);
            }

    		actual = actual->siguiente;
		}
		
		cout << "lista completa: "; 
		mostrar (lista); 
		cout << endl << "numero pares: ";
		mostrar (listPares);
		cout << endl << "numero impares: ";
		mostrar (listImpares);
	}
    
}
