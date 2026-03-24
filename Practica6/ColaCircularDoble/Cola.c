/*Práctica 6: Cola Circular y Cola Doble.
Ejercicio 2.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este codigo se encuentran las funciones y una estructura, para el manejo de una cola de datos; se agregan datos al final y se quitan datos desde el inicio.
Permite eliminar y agregar datos, saber si la cola esta vacia, mostrar el primer dato y borrar toda la cola, se hace uso de memoria dinamica para guardar los datos*/

#include "cola.h"
#include <stdio.h>
#include <stdlib.h>

/* Nodo privado de la lista */
struct Nodo {
    Cliente dato;
    Nodo *sig;
    Nodo *anterior;
};

void cola_init(Cola *c, int capacidad) { 
    if (!c || capacidad <= 0) return; //valida que la cola exista y la capacidad sea valida
    c->frente = NULL; //no hay primer ni ultimo elemento
    c->final  = NULL;
    c->tam    = 0; //tamaño inicial en 0
    c->capacidad = capacidad; //se asigna la caspcidad maxima
}

int cola_esta_vacia(Cola *c) { 
    return (c->tam == 0);
}

int cola_esta_llena(Cola *c) {
    return (c->tam == c->capacidad);
}

int cola_tamano(Cola *c) {  
    return c->tam;
}

int cola_encolar(Cola *c, Cliente valor) {  //se van agregando elementos al final
    if (!c || cola_esta_llena(c)) return 0; //se valida la cola y que no este llena

    Nodo *n = (Nodo*)malloc(sizeof(Nodo));  //se reserva memoria para el nodo
    if(!n) return 0;

    n->dato = valor;  //guarda el valor

    if(c->frente == 0){ //si la cola esta vacía 

        n->sig = n; //se apunta a si mismo en sig y en anterior
        n->anterior = n;
        c->frente = n; //se vuelve el frente y el final de la cola
        c->final = n;
    } else { //si hay mas nodos
        n->sig = c->frente; //el nuevo nodo apunta al frente
        n->anterior = c->final; //el anterior del nuevo nodo apunta al actual final 
        c->final->sig = n; //el siguiente del antiguo final apunta al nuevo nodo
        c->frente->anterior = n; //el anterior del frente apunta al nuevo nodo
        c->final = n; //se actualiza el final 
    }

    c->tam++; //aumenta el tamaño 
    return 1;
}

int cola_encolar_frente(Cola *c, Cliente valor) { //se ingresa al inicio de la cola
    if (!c || cola_esta_llena(c)) return 0; //se valida la cola, que no este llena

    Nodo *n = (Nodo*)malloc(sizeof(Nodo)); //se reserva la mamoria
    if (!n) return 0;

    n->dato = valor; //guarda el valor

    if (c->tam == 0) { //si esta vacia
        n->sig = n; //se apunta a si mismo
        n->anterior = n;
        c->frente = n; //el nodo es el frente y el final
        c->final = n;
    } else { //si hay mas nodos
        n->sig = c->frente; //el siguiente del nuevo nodo apunta al frente actual
        n->anterior = c->final; //su anterior apunta al final
        c->frente->anterior = n; //el anterior del frente actual apunta al nuevo nodo
        c->final->sig = n; //el siguiente del final apunta al nuevo nodo
        c->frente = n; //se actualiza el frente
    }

    c->tam++; //aumenta el tamaño
    return 1;
}

int cola_desencolar(Cola *c, Cliente *salida) { //quitar nodos al frente
    if (!c || cola_esta_vacia(c)) return 0;

    Nodo *aux = c->frente; //guarda el nodo que se va a quitar

    if (salida) 
        *salida = aux->dato; //guarda el dato que se va a eliminar

    if (c->tam == 1) { //si solo hay un nodo
        c->frente = NULL; //frente y final apuntan a NULL, iqeda vacia la cola
        c->final = NULL;
    } else { //si hay mas nodos
        c->frente = aux->sig; //el frente pasa al siguiente
        c->frente->anterior = c->final; //el anterior del frente apunta hacia el final
        c->final->sig = c->frente; //el final del sigueinte apunta al frente
    }

    free(aux); //se libera la memoria del nodo auxiliar
    c->tam--; //se reduce el tamaño

    return 1;
}

int cola_desencolar_final(Cola *c, Cliente *salida) { //quitar por el final
    if (!c || cola_esta_vacia(c)) return 0;

    Nodo *aux = c->final; //guarda el nodo

    if (salida)
        *salida = aux->dato; //guarda el dato

    if (c->tam == 1) { //si solo hay un elemento la cola queda vacía 
        c->frente = NULL;
        c->final = NULL;
    } else { //si hay mas
        c->final = aux->anterior; //el final pasa al anterior
        c->final->sig = c->frente; //el siguiente del final apunta al frente
        c->frente->anterior = c->final; //el anterior del frente apunta al final
    }

    free(aux); //se libera la memoria
    c->tam--; //se reduce el tamaño

    return 1;
}

int cola_frente(Cola *c, Cliente *salida) { //nos deja ver el primer elemento y no lo borra
    if (!c->frente) return 0;
    *salida = c->frente->dato;

    return 1;
}

void cola_mostrar(Cola *c) {
    if (cola_esta_vacia(c)) { //verifica si esta vacia
        printf("La cola esta vacia\n");
        return;
    }

    Nodo *aux = c->frente; //empieza desde el primer nodo (frente)

    printf("\nClientes esperando: \n");

    do {
        printf("%d %s | Articulos: %d | Total: %.2f\n", //va imprimiendo los datos del nodo
               aux->dato.numCliente,
               aux->dato.nombre,
               aux->dato.articulos,
               aux->dato.total);

        aux = aux->sig; //pasa al siguiente nodo

    } while (aux != c->frente); //termina cuando regresa al frente
}

void cola_clear(Cola *c) {
    Cliente temp;
    while (cola_desencolar(c, &temp));
}

void cola_destroy(Cola *c) {
    cola_clear(c);
    c->capacidad = 0;
}
