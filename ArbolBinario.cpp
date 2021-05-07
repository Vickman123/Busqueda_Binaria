#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

struct Nodo{
	int dato;
	Nodo *der;
	Nodo *izq;
	Nodo *padre;
};

//Prototipos
void menu();
Nodo *crearNodo(int,Nodo *);
void insertarNodo(Nodo *&, int,Nodo *);
void mostrarArbol(Nodo *,int);
bool busqueda(Nodo *,int);
void preOrden(Nodo *);
void inOrden(Nodo *);
void postOrden(Nodo *);
void eliminar(Nodo *,int);
void eliminarNodo(Nodo *);
Nodo *minimo(Nodo *);
void reemplazar(Nodo *,Nodo *);
void destruirNodo(Nodo *);

Nodo *arbol = NULL;

int main(){	
	menu();
	
	getch();
	return 0;
}

////funcion de menu
void menu(){
	int dato, opcion,contador=0;
	
	do{
		cout<<"+-----------------------------------------+\n";
		cout<<"|            Busqueda Binaria        	  |\n";//Titulo tema
		cout<<"+-----------------------------------------+\n";
		cout<<"\t.:Menu:.\n"<<endl;
		cout<<"1. Insertar un nuevo nodo"<<endl;
		cout<<"2. Mostrar el arbol completo"<<endl;
		cout<<"3. Buscar un elemento en el arbol"<<endl;
		cout<<"4. Recorrer el arbol en PreOrden"<<endl;
		cout<<"5. Recorrer el arbol en InOrden"<<endl;
		cout<<"6. Recorrer el arbol en PostOrden"<<endl;
		cout<<"7. Eliminar un nodo del arbol"<<endl;
		cout<<"8. Salir"<<endl;
		cout<<"Opcion :  ";
		cin>>opcion;
		
	switch(opcion){
		case 1: cout<<"\nDigite un numero: ";
			cin>>dato;
			insertarNodo(arbol,dato,NULL); //Insertamos un nuevo
			cout<<"\n";
			system("pause");
			break;
		case 2: cout<<"\nMostrando el arbol completo: \n\n";
		    cout<<"\nDonde la izquierda inicia el arbol y la derecha donde termina\n";
		    mostrarArbol(arbol,contador);
		    cout<<"\n";
		    system("pause");
		    break;
		case 3: cout<<"\nDigite el elemento a buscar: ";
		    cin>>dato;
		    if(busqueda(arbol,dato) == true){
		    cout<<"\nElemento "<<dato<<" a sido encontrado en el arbol\n";	
		}
			else{
			cout<<"\nElemento no encontrado\n";	
		}
			cout<<"\n";
			system("pause");
			break;
		case 4: cout<<"\nRecorrido en PreOrden: ";
	        preOrden(arbol);
	        cout<<"\n\n";
	        system("pause");
	        break;
	    case 5: cout<<"\nRecorrido en InOrden: ";
	        inOrden(arbol);
	        cout<<("\n\n");
	        system("pause");
	        break;
	    case 6: cout<<"\nRecorrido en PostOrden: ";
	        postOrden(arbol);
	        cout<<"\n\n";
	        system("pause");
	        break;
	    case 7: cout<<"\nDigite el numero a eliminar: ";
	        cin>>dato;
	        eliminar(arbol,dato);
	        cout<<"\n";
	        system("pause");
	      break;
	}
		system("cls");
	}while(opcion != 4);
}
	


//Funcion para crear un nuevo nodo
Nodo *crearNodo(int n,Nodo *padre){
	Nodo *nuevo_nodo= new Nodo ();
	
	nuevo_nodo-> dato = n;
	nuevo_nodo-> der = NULL;
	nuevo_nodo-> izq = NULL;
	nuevo_nodo-> padre = padre;
	
	return nuevo_nodo;
}

//Funcion para insertar elementos en el arbol
void insertarNodo(Nodo *&arbol,int n, Nodo *padre){
	if (arbol == NULL){ //Si el arbol esta vacia
	Nodo *nuevo_nodo = crearNodo( n,padre);
	arbol = nuevo_nodo;
	}
	else{ //si el arbol tiene un nodo o mas
		int valorRaiz = arbol->dato;//obtenemos el valor de la raiz
		if(n < valorRaiz){// si el elemento es menor a la raiz, insertamos en izq
			insertarNodo(arbol->izq,n,arbol );
		}
	else{//si el elemento es mayor a la raiz, insertamos en der
	     insertarNodo(arbol->der,n, arbol);
	}
  }
}

//Funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol,int cont){//si el arbol esta vacio
	if(arbol == NULL){
		return;
	}
	else{
		mostrarArbol(arbol->der,cont+1);
		for(int i=0;i<cont;i++){
			cout<<"   ";
		}
		cout<<arbol->dato<<endl;
		mostrarArbol(arbol->izq,cont+1);
	}
}
//Funcion para buscar un elemento en el arbol
bool busqueda(Nodo *arbol,int n){
	if(arbol == NULL){//Si el arbol esta vacio
		return false;
	}
	else if(arbol->dato == n){//Si el nodo es igual al elemento
		return true;
	}
	else if(n < arbol->dato){
		return busqueda(arbol->izq,n);
	}
	else{
		return busqueda(arbol->der,n);
	}
}

//Funcion para recorrido en profundida - Preorden
void preOrden(Nodo *arbol){
     if(arbol == NULL){//Si el arbol esta vacio
     	return;
	 }
	 else{
	 	cout<<arbol->dato<<" - ";
	 	preOrden(arbol->izq);
	 	preOrden(arbol->der);
	 }
}

//Funcion para recorrido en profundida - InOrden
void inOrden(Nodo *arbol){
	if(arbol == NULL){
		return;
	}
	else{
		inOrden(arbol->izq);
		cout<<arbol->dato<<" - ";
		inOrden(arbol->der);
	}
}

//Funcion para recorrido en profundida - PostOrden
void postOrden(Nodo *arbol){
	if(arbol == NULL){//Si el arbol esta vacio
		return;
	}
	else{
		postOrden(arbol->izq);
		postOrden(arbol->der);
		cout<<arbol->dato<<" - ";
	}
}

//Funcion para eliminar un nodo del arbol
void eliminar (Nodo *arbol, int n){//Si el arbol esta vacio
	if(arbol == NULL){
		return; //No retorna nada
	}
	else if(n < arbol->dato){//si el valor es menor
		eliminar(arbol->izq,n);//Busca por la izquierda
	}
	else if(n > arbol->dato){//si el valor es mayor
		eliminar(arbol->der,n);//Busca por la izquierda
	}
	else{//si ya encontro el valor
		eliminarNodo(arbol);
	}
}

//Funcion para determinar el nodo mas izq posible
Nodo *minimo(Nodo *arbol){
	if(arbol == NULL){ //si el arbol vacio
		return NULL; //Retorna nulo
	}
	if(arbol->izq){//Si tiene hijo izq
		return minimo(arbol->izq);//Buscamos la parte mas izq posible
	}
	else{//si no tiene hijo izq
		return arbol;//retornamos el mismo nodo
	}
}

//Funcion para reemplazar dos nodos
void reemplazar(Nodo *arbol,Nodo *nuevoNodo){
     if(arbol->padre){
     	//arbol->padre hay que asignarle su nuevo hijo
     	if(arbol->dato == arbol->padre->izq->dato){
     		arbol->padre->izq = nuevoNodo;
		 }
		 else if(arbol->dato == arbol->padre->der->dato){
		 	arbol->padre->der = nuevoNodo;
		 }
	 }
	 if(nuevoNodo){
	 	//Procedemos a asignarle su nuevo padre
	 	nuevoNodo->padre = arbol->padre;
	 }
}
//Funcion para destruir un nodo
void destruirNodo(Nodo *nodo){
	nodo->izq = NULL;
	nodo->der = NULL;
	
	delete nodo;
}



//Funcion para eliminar el nodo encontrado
void eliminarNodo(Nodo *nodoEliminar){
	if(nodoEliminar->izq && nodoEliminar->der){//Siel nodo tiene hijo izq y der
		Nodo *menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	else if(nodoEliminar->izq){//Si tiene hijo izquierdo
	reemplazar(nodoEliminar,nodoEliminar->izq);
	destruirNodo(nodoEliminar);
	}
	else if(nodoEliminar->der){//Si tiene hijo derecho
		reemplazar(nodoEliminar,nodoEliminar->der);
		destruirNodo(nodoEliminar);
	}
	else{//No tiene hijo
		reemplazar(nodoEliminar,NULL);
		destruirNodo(nodoEliminar);
	}
}
