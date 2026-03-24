/*Práctica 6: Cola Circular.
Ejercicio 1.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este archivo se definen las estructuras que se van a usar en el programa, como la del proceso y la de la cola circular.
También se declaran las funciones que permitirán trabajar con la cola, como agregar, eliminar, mostrar y validar datos.*/


#ifndef COLA_CIRCULAR_H
#define COLA_CIRCULAR_H

typedef struct Proceso {
    char nombre[16]; // se guarda el nombre del proceso
    int numProcess; // Aquí va el número o ID del proceso
    float ram;   // la cantidad de RAM necesita el proceso
} Proceso;

typedef struct Nodo {
    Proceso dato; // Aquí guardamos el proceso completo
    struct Nodo *sig; // Apuntador al siguiente nodo
} Nodo;

typedef struct ColaCircular {
    Nodo *head;    //Es el primero de la cola
    Nodo *tail;    //Es el ultimo de la cola
    int tam;       //la cantidad de nodos que hay en la cola 
    int capacidad; //cual es la capacidad de la cola 
} ColaCircular;

/* FUNCIONES */
int cola_init(ColaCircular *c, int capacidad);  // inicializara la cola 
int cola_vacia(ColaCircular *c);                // revisa si la cola esta vacia
int cola_llena(ColaCircular *c);                // revisa si la cola esta llena 

int encolar(ColaCircular *c, Proceso p);        // Ingresa a un proceso 
int desencolar(ColaCircular *c, Proceso *p);    // Saca un proceso 

void mostrarCola(ColaCircular *c);              // Muestra la cola completa 
void liberarCola(ColaCircular *c);              // Libera la memoria de la cola 

/* NUEVAS FUNCIONES */
int verHead(ColaCircular *c, Proceso *p);       // Muestra el primer proceso de la cola
int verTail(ColaCircular *c, Proceso *p);       // Muestra el ultimo proceso de la cola

/* VALIDACIONES */
int existeProceso(ColaCircular *c, int num);    // Ver si la existe el IDP

/* GENERAR */
void generarProceso(ColaCircular *c, Proceso *p); // genera un proceso en automatico 

#endif
