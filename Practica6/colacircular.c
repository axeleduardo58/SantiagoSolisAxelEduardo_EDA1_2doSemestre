/*Práctica 6: Cola Circular.
Ejercicio 1.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este archivo se encuentra la implementación de las funciones de la cola circular.
Aquí se realiza la lógica para agregar procesos al final, eliminarlos desde el inicio, mostrar los elementos y verificar si la cola está vacía o llena.
También se valida que no se repitan los números de proceso y se generan procesos de forma aleatoria.
*/
#include "ColaCircular.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* INICIALIZAR */
int cola_init(ColaCircular *c, int capacidad) { // verifica que este bien par a poder iniciar el proceso (c válido y capacidad > 0)
    if (!c || capacidad <= 0) return 0;
    c->head = NULL;  // no hay nada en la cola todavia
    c->tail = NULL;
    c->tam = 0;     // se inicializa la cola en 0
    c->capacidad = capacidad;
    return 1;
}

int cola_vacia(ColaCircular *c) {  //verifica si la cola esta vacia
    return (c->tam == 0);
}

int cola_llena(ColaCircular *c) { // verifica cuando ya la cola esta llena 
    return (c->tam == c->capacidad);
}

/* ENCOLAR (FINAL) */
int encolar(ColaCircular *c, Proceso p) {
    if (cola_llena(c)) return 0; // si la cola esta llena entonces no se permitira nada mas 

    Nodo *nuevo = (Nodo*)malloc(sizeof(Nodo)); // creal el espacio de memoria para ingresar un nuevo nodo 
    if (!nuevo) return 0;

    nuevo->dato = p;  // guarda el proceso en el nuevo nodo que se agrega

    if (cola_vacia(c)) {  // si es el primer elemento 
        nuevo->sig = nuevo;  // se apunta hacia mismo 
        c->head = nuevo;     // apunta al unico dato que hay en la cola 
        c->tail = nuevo;     // apunta al unico dato que hay en la cola
    } else {    // si ya hay datos en la cola 
        nuevo->sig = c->head; // aounta al proimer proceso de la cola 
        c->tail->sig = nuevo; // el ultimo nodo apunta al nuevo
        c->tail = nuevo;      // ahora el nuevo nodo es el ultimo 
    }

    c->tam++;   // se aumenta tamaño de la cola
    return 1;
}

/* DESENCOLAR (FRENTE) */
int desencolar(ColaCircular *c, Proceso *p) {
    if (cola_vacia(c)) return 0;   // verifica si la cola esta vacia entonces no hara nada 

    Nodo *temp = c->head;     //Se crea un nodo temporal para no perder de referencia el primer nodo

    if (p) *p = temp->dato;   //copea los datos del nodo al que esta apuntando temp y los guarda en una variable p  

    if (c->tam == 1) {    //si solo hay uno 
        c->head = NULL;   // queda nulo por que ya no hay nada
        c->tail = NULL;   // de igual forma que el tail
    } else {              // si hay mas de uno 
        c->head = temp->sig;    // el segundo pasa a ser el primero osea el HEAD
        c->tail->sig = c->head; // el ultimo siemore va apuntar al primero 
    }

    free(temp);  // libera la memoria 
    c->tam--;    //se encarga de disminuir el tamaño
    return 1;
}

/* MOSTRAR */
void mostrarCola(ColaCircular *c) {  // se encarga de mostrar todos los procesos que estan en la cola
    if (cola_vacia(c)) {            // verifica si la cola esta vacia
        printf("\nCola vacia\n");    //entonces mandara el mensaje 
        return;
    }

    Nodo *aux = c->head;  // se crea un apuntador auxiliar el cual va a partir del primer proceso 

    printf("\n--- PROCESOS EN COLA ---\n"); 
    do {
        printf("Nombre: %s | PID: %d | RAM: %.2f GB\n",
               aux->dato.nombre,
               aux->dato.numProcess,
               aux->dato.ram);  // imprime los datos del nodo 
        aux = aux->sig;  // el auxiliar se mueve hacia el segundo nodo
    } while (aux != c->head); // se  repite hasta que regrese al inicio 
}

/* LIBERAR */
void liberarCola(ColaCircular *c) {   // vacia la cola 
    Proceso p;   
    while (desencolar(c, &p));  // va sacando procesos hasta que ya no haya ni uno 
}

/* VALIDAR PID */
int existeProceso(ColaCircular *c, int num) {  //verifica si ya existe un numero 
    if (cola_vacia(c)) return 0;   // si no hay elementos en la cola entonces no hay ningun PID

    Nodo *aux = c->head;     //Empieza desde el primer nodo las asignacion del PID
    do {
        if (aux->dato.numProcess == num)  //hace la comparacion si existe regresa 
            return 1;
        aux = aux->sig;  // si no existe avnaza y recorre toda la cola 
    } while (aux != c->head);

    return 0;
}

/* GENERAR PROCESO */
void generarProceso(ColaCircular *c, Proceso *p) {  // genera un proceso automatico 
    char *nombres[] = {
        "Chrome","Word","Excel","Spotify","Discord",
        "Teams","Zoom","Edge","Notion","Slack",
        "Telegram","Photoshop","VSCode","Netflix","Steam"
    };

    int total = 15; // la cantidad de posibles procesos 

    strcpy(p->nombre, nombres[rand() % total]);  // se escoge el proceso al azar

    do {
        p->numProcess = rand() % 9000 + 1000; // se genera un IDP de 4 digitos
    } while (existeProceso(c, p->numProcess)); // si ya existe repite la creacion

    p->ram = (rand() % 100) / 10.0 + 0.5;  // gernera un valor de RAM aleatorio 
}

/* -------- VER HEAD -------- */
int verHead(ColaCircular *c, Proceso *p) {   // funcion para obtener el primer proceso 
    if (cola_vacia(c)) return 0; // si la cola esta vacia entonces no hay ningun proceso 
    *p = c->head->dato; // copia el primer proceso en la variable p
    return 1;
}

/* -------- VER TAIL -------- */
int verTail(ColaCircular *c, Proceso *p) {  //Funcion para obtener el ultimo proceso 
    if (cola_vacia(c)) return 0;  // si la cola esta vacia entonces no hay ningun proceso 
    *p = c->tail->dato; //Copia el ultimo proceso y lo aloja en la variable p
    return 1;
}
