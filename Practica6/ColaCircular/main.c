/*Práctica 6: Cola Circular.
Ejercicio 1.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este programa se maneja un menú interactivo que permite al usuario trabajar con la cola circular.
Se puede agregar procesos, eliminarlos, ver todos los procesos, así como consultar el primero (head) y el último (tail).
Además, los procesos se generan automáticamente y no se repiten mientras estén en la cola.
También se simula el comportamiento de un sistema operativo, ya que después de eliminar un proceso se puede agregar uno nuevo.*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ColaCircular.h"

int main() {

    ColaCircular cola;  // se crea la cola 
    int cap, opcion;
    char op;

    srand(time(NULL)); // se encarga de que los valores sean aleatorios

    
    printf("Ingrese capacidad de la cola: "); // pide el la capacidad de la cola
    scanf("%d", &cap); // lo guarda en la variable cap

    while (scanf("%d", &cap) != 1 || cap <= 0) { // verifica que solo se ingresen numeros 
            printf("Entrada invalida. Intente de nuevo: ");
            scanf("%*s"); // descarta lo que se metió
        }

    cola_init(&cola, cap); // se inicializa la cola 

    do {     
        printf("\n--- MENU ---\n");
        printf("1. Encolar proceso\n");
        printf("2. Desencolar proceso\n");
        printf("3. Mostrar cola\n");
        printf("4. Ver HEAD\n");
        printf("5. Ver TAIL\n");
        printf("6. Salir\n");
        printf("Opcion: ");
    
        while (scanf("%d", &opcion) == 0) { // Si mete letra
            printf("Error, solo numeros: ");
            scanf("%*s"); // Borra lo que escribió mal
        }

        switch (opcion) {

        /*CASE 1:
        Permite agregar un proceso a la cola. Primero verifica si la cola está llena,
        si no lo está, genera un proceso automáticamente y lo encola al final.
        y muestra los datos del proceso agregado.*/
        case 1: {
            if (cola_llena(&cola)) {
                printf("\nCola llena\n");
            } else {
                Proceso p;
                generarProceso(&cola, &p);
                encolar(&cola, p);

                printf("\nProceso agregado:\n");
                printf("Nombre: %s\nPID: %d\nRAM: %.2f GB\n",
                       p.nombre, p.numProcess, p.ram);
            }
            break;
        }

        /*CASE 2:
        Permite eliminar (desencolar) el proceso que está al inicio de la cola.
        Si la cola no está vacía, muestra los datos del proceso eliminado y
        pregunta al usuario si desea agregar un nuevo proceso.*/
        case 2: {
            if (cola_vacia(&cola)) {
                printf("\nCola vacia\n");
            } else {
                Proceso p;
                desencolar(&cola, &p);

                printf("\nProceso atendido:\n");
                printf("Nombre: %s\nPID: %d\nRAM: %.2f GB\n",
                       p.nombre, p.numProcess, p.ram);

                printf("\nDesea agregar otro proceso? (s/n): ");
                do {
                    scanf(" %c", &op); // lee el caracter

                 if (op != 's' && op != 'S' && op != 'n' && op != 'N') {
                    printf("Entrada invalida. Solo s/n: ");
                 }

                } while (op != 's' && op != 'S' && op != 'n' && op != 'N');

                if (op == 's' || op == 'S') {
                    if (!cola_llena(&cola)) {
                        Proceso nuevo;
                        generarProceso(&cola, &nuevo);
                        encolar(&cola, nuevo);

                        printf("\nNuevo proceso agregado:\n");
                        printf("Nombre: %s\nPID: %d\nRAM: %.2f GB\n",
                               nuevo.nombre, nuevo.numProcess, nuevo.ram);
                    } else {
                        printf("Cola llena\n");
                    }
                }
            }
            break;
        }

        /*CASE 3:
        Muestra todos los procesos que se encuentran actualmente en la cola,
        recorriéndola desde el inicio hasta regresar al mismo punto.*/
        case 3:
            mostrarCola(&cola);
            break;

        /*CASE 4:
        Muestra el proceso que está al inicio de la cola (head)*/
        case 4: {
            Proceso p;
            if (verHead(&cola, &p)) {
                printf("\nHEAD:\n");
                printf("Nombre: %s\nPID: %d\nRAM: %.2f GB\n",
                       p.nombre, p.numProcess, p.ram);
            } else {
                printf("\nCola vacia\n");
            }
            break;
        }

        /*CASE 5:
        Muestra el proceso que está al final de la cola (tail),
        osea, el último que se agregó.*/
        case 5: {
            Proceso p;
            if (verTail(&cola, &p)) {
                printf("\nTAIL:\n");
                printf("Nombre: %s\nPID: %d\nRAM: %.2f GB\n",
                       p.nombre, p.numProcess, p.ram);
            } else {
                printf("\nCola vacia\n");
            }
            break;
        }

        /*CASE 6:
        Finaliza la ejecución del programa y libera la memoria utilizada por la cola.*/
        case 6:
            printf("\nSaliendo del Sistema Operativo\n");
            break;

        default:
            printf("\nOpcion invalida\n");
        }

    } while (opcion != 6);

    liberarCola(&cola);
    return 0;
}
