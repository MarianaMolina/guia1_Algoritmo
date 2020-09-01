#include <iostream>

using namespace std;

struct Nodo {
    int dato;
    Nodo *siguiente;
};

 //prototipo de funciones
void newNodo(Nodo *&, int);
void mostrar (Nodo *);
int buscar (Nodo *, int);

//main
int main() {

	//creando lista
    Nodo * list = NULL;

    //ingresando datos a la lista enlazada
    newNodo(list, 1);

    newNodo(list, 3);

    newNodo(list, 8);
    
    newNodo(list, 5);

    //funcion para contar los nodos
    cout << buscar(list, 1) << endl;

    cout << "lista completa:  ";
    mostrar(list);

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

int buscar (Nodo *lista, int nemo){
	Nodo *actual = new Nodo();
    actual = lista;
    int cont = 1;
    
    if (actual == NULL){
    	cout << "lista vacia";
	}
	else{
        while (actual != NULL){ 
          
            if((actual->dato) != nemo){
                cont = cont + 1;
                cout << "holi adentro del if" << endl;
                actual = actual->siguiente;
            }
            else{
                break;
            }
 
		}
		cout << "NEMOO! esta en la posicion: ";
        return cont;
	}
    
}
