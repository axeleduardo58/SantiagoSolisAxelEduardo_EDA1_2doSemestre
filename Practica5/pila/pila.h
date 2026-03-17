/*Práctica 5: Pila y Cola.
Ejercicio 1.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este archivo se definen las estructuras y prototipos de funciones que permiten manipular una pila dinamica en C, tales como insertar, eliminar, consultar elementos y liberar memoria utilizada.
Se establece el tipo de dato que almacenara cada nodo (codigo y nombre) y la estructura que representa la pila con su tope y tamaño.*/

#ifndef PILA_H
#define PILA_H

/* Estructuras del dato que guardara la pila */
typedef struct {
    int codigo;
    char nombre[50];
} Dato;

/* Declaración adelantada del nodo */
typedef struct Nodo Nodo;

/* Estructura pila */
typedef struct {
	Nodo *tope;
	int tam;        /* Ahora el tamaño es un entero normal */
} Pila;

/* Funciones */
void pila_init(Pila *p);
int  pila_esta_vacia(Pila *p);

int  pila_push(Pila *p, Dato valor);
int  pila_pop(Pila *p, Dato *salida);
int  pila_peek(Pila *p, Dato *salida);
int pila_tamano(Pila *p);

void pila_clear(Pila *p);
void pila_destroy(Pila *p);

#endif
