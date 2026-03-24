/*Práctica 6: Cola Circular y Cola Doble.
Ejercicio 2.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

Este codigo define la estructura y funciones de una cola, indicando como estan organizados los datos y que operaciones se pueden realizar.*/

#ifndef COLA_H
#define COLA_H

/* Declaración adelantada */
typedef struct Nodo Nodo;

typedef struct {
    int numCliente;
    char nombre[20];
    int articulos;
    float total;
} Cliente;

/*Cola FIFO basada en una cola circular doble*/

typedef struct Cola {
    Nodo *frente; /* head: primer elemento (sale primero) */
    Nodo *final;  /* tail: último elemento (entra último) */
    int   tam;    /* tamaño como entero */
    int capacidad;
} Cola;

/* Interfaz */
void cola_init(Cola *c, int capacidad);
int  cola_esta_vacia(Cola *c);
int  cola_esta_llena(Cola *c);
int  cola_tamano(Cola *c);

int  cola_encolar(Cola *c, Cliente valor);        /* enqueue O(1) */
int  cola_encolar_frente(Cola *c, Cliente valor);
int  cola_desencolar(Cola *c, Cliente *salida);   /* dequeue O(1) */
int  cola_desencolar_final(Cola *c, Cliente *salida);
int  cola_frente(Cola *c, Cliente *salida); /* peek O(1) */
void cola_mostrar(Cola *c);

void cola_clear(Cola *c);
void cola_destroy(Cola *c);

#endif /* COLA_H */
