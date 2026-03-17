/*Práctica 5: Pila y Cola.
Ejercicio 1.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este archivo se implementan las funciones que permiten el funcionamiento de la pila definida en pila.h. Aqui se desarrolla la logica
para inicializar la pila, insertar nodos, eliminar el elemento del tope, consultar datos y liberar la memoria utilizada. Para ello se utiliza
memoria dinamica y nodos enlazados, permitiendo que la pila crezca o disminuya segun las operaciones realizadas.*/

#include "pila.h" /* Importa el archivo donde estan:
                     - la estructura pila
					 - las declaraciones de las funciones */
#include <stdlib.h> //Permite usar funciones de de memoria dinámica

/* Nodo de la pila */
struct Nodo {
	Dato dato;   // valor almacenado
	Nodo *sig;  // puntero al siguiente nodo
};

/* Inicializa la pila */
void pila_init(Pila *p) {
	if (!p) return;   //verifica que el puntero exista 
	p->tope = NULL;   //pila vacía
	p->tam = 0;      //tamaño inicial 
}

/* Verificamos que la pila este vacía */
int pila_esta_vacia(Pila *p) {
	if (!p) return 1;
	return (p->tam == 0) ? 1 : 0; //terna condicional 
}

/* Inserta un nuevo elemento en la pila */
int pila_push(Pila *p, Dato valor) {
	if (!p) return 0;
	Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo)); //se reserva memoria para un nodo
	if (!nuevo) return 0; // verificamos que se halla reservado memoria 
	nuevo->dato = valor; // guarda el dato dentro del nodo
	nuevo->sig = p->tope; // apunta al tamaño anterior del tope

	p->tope = nuevo;  // el nuevo nodo se vuelve el tope
	p->tam++;  // aumenta el tamaño de la pila
	return 1;
		
}

/* Elimina el elemento del tope */
int pila_pop(Pila *p, Dato *salida) {
	if (!p || pila_esta_vacia(p)) return 0; // si la pila no existe o está vacía, no se puede eliminar
	Nodo *nodo = p->tope; //guardamos el nodo superior
	if (salida)
		*salida = nodo->dato; // se guarda el valor eliminado
	p->tope = nodo->sig; //el tope apunta al siguiente dato
	free(nodo);
	p->tam--;
	return 1;
	
}

/* Permite ver el tope sin eliminarlo */
int pila_peek(Pila *p, Dato *salida) {
	if (!p || pila_esta_vacia(p)) return 0;
	if (salida)
		*salida = p->tope->dato; // se obtiene el valor del tope 
	return 1;
	
}

/*Limpiar la pila */
void pila_clear(Pila *p) { //elimina todos los nodos
	if (!p) return; 
	Dato aux; //variable auxiliar para recibir valores
	while (!pila_esta_vacia(p)){ //Mientras la pila tenga elementos
		pila_pop(p, &aux);	     // se eliminan uno por uno
	}
	
}
/* Libera todos los nodos antes de terminar el programa */
void pila_destroy(Pila *p) {
	pila_clear(p);
}

int pila_tamano(Pila *p){
	if (!p) return 0;
	return p->tam;
}
