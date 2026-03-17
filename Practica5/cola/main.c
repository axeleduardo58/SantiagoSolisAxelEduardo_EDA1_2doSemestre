/*Práctica 5: Pila y Cola.
Ejercicio 2.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este codigo se prueba el funcionamiento de la cola, crea varios clientes y los agrega a la cola, miestra la informacion del primero, luego va eliminando uno a la vez 
y muestra los datos hasta que la cola queda vacia.*/


#include <stdio.h>
#include "cola.h"

int main(void) {
    Cola c;
    cola_init(&c);

    printf("¿Cola vacía? %d\n", cola_esta_vacia(&c));

    /* Se crean clientes */
    Cliente cl1 = {23, "Margarita", 4, 57.88};
    Cliente cl2 = {24, "Guadalupe", 7, 508.9};
    Cliente cl3 = {25, "Juan", 1, 35.5};
    Cliente cl4 = {26, "Diego", 17, 3788.00};
    Cliente cl5 = {27, "Mercedes", 9, 701.34};

    /* Encolar algunos valores */
    cola_encolar(&c, cl1);
    cola_encolar(&c, cl2);
    cola_encolar(&c, cl3);
    cola_encolar(&c, cl4);
    cola_encolar(&c, cl5);

    printf("Tamaño tras encolar: %d\n", cola_tamano(&c));

    /* Consultar el frente (peek) */
    Cliente f;
    if (cola_frente(&c, &f))
        printf("Frente actual. Cliente: %d %s, compra total: $%.2f\n", f.numCliente, f.nombre, f.total);

    /* Desencolar todos */
    Cliente x;
    while (cola_desencolar(&c, &x)) {
        printf("Desencolado. Cliente atendido #%d %s, articulos vendidos: %d, total: $%.2f (clientes restantes=%d)\n",
            x.numCliente, x.nombre, x.articulos, x.total, cola_tamano(&c));
    }

    printf("¿Cola vacía al final? %d\n", cola_esta_vacia(&c));

    cola_destroy(&c);
    return 0;
}
