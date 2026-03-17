/*Práctica 5: Pila y Cola.
Ejercicio 2.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este codigo se encuentran las funciones y una estructura, para el manejo de una cola de datos; se agregan datos al final y se quitan datos desde el inicio.
Permite eliminar y agregar datos, saber si la cola esta vacia, mostrar el primer dato y borrar toda la cola, se hace uso de memoria dinamica para guardar los datos*/

#include "cola.h"
#include <stdlib.h>

/* Nodo privado de la lista */
struct Nodo {
    Cliente dato;
    Nodo *sig;
};

void cola_init(Cola *c) {
    if (!c) return;
    c->frente = NULL;
    c->final  = NULL;
    c->tam    = 0;
}

int cola_esta_vacia(Cola *c) { 
    if (!c) return 1;
    return (c->tam == 0) ? 1 : 0;
}

int cola_tamano(Cola *c) {  
    return c ? c->tam : 0;
}

int cola_encolar(Cola *c, Cliente valor) {  //se van agregando elementos
    if (!c) return 0;

    Nodo *n = (Nodo*)malloc(sizeof(Nodo));  //se reserva memoria para el nodo
    if(!n) return 0;

    n->dato = valor;  //guarda el ultimo dato
    n->sig = NULL;

    (c->frente == NULL) ? (c->frente = n) : (c->final->sig = n);  /*condicional ternario, si la cola esta vacia el nuevo nodo es 
    el frente, si no, el ultimo nodo ahora apunta al nuevo*/

    c->final = n; //el nuevo nodo ahora es el ultimo

    c->tam++;  //aumenta el tamaño
    return 1;
}

int cola_desencolar(Cola *c, Cliente *salida) {
    Nodo *aux;
    if (!c->frente) return 0;  //si la cola esta vacia no hace nada
    
    aux = c->frente;  //guarda el primer nodo

    *salida = aux->dato; //copia el dato y lo deuvelve
    c->frente = c->frente->sig; //el frente de la cola pasa a ser el siguiente nodo

    c->final = (c->frente == NULL) ? NULL : c->final; /*si la cila queda vacia despues de mover el frente y queda igual a NULL,
    el final tambien sera NULL*/

    free(aux);  //se libera memoria
    c->tam--;  //se reduce el tamaño

    return 1;
}

int cola_frente(Cola *c, Cliente *salida) { //nos deja ver el primer elemento y no lo borra
    if (!c->frente) return 0;
    *salida = c->frente->dato;

    return 1;
}

void cola_clear(Cola *c) {
    if (!c) return;

    Nodo *it = c->frente;
    while (it) {
        Nodo *sig = it->sig;
        free(it);
        it = sig;
    }

    c->frente = NULL;
    c->final  = NULL;
    c->tam    = 0;
}

void cola_destroy(Cola *c) {
    cola_clear(c);
}
