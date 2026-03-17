/*Práctica 5: Pila y Cola.
Ejercicio 1.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este programa permite al usuario agregar nodos con codigo y nombre, los cuales se almacenan en la pila. Se usa un menu interactivo que permite agregar nodos,
eliminar el nodo superior, ver el tamaño de la pila y finalizar el programa.*/

#include <stdio.h> /*Permite el uso de funciones de entrada y salida */
#include <ctype.h> /*Se utilizó para validar letras con comparaciones 
                    directas (A-Z y a-z).*/
#include "pila.h" /* Contiene:
                   - la estructura Pila
				   - la estructura Dato
				   - las funciones de pila */

int main() {
	/*--------VARIABLES---------*/
	int n, opcion;
	Pila pila;
	Dato dato;
	pila_init(&pila);  // estado inicial de la pila (vacia)

	printf("¿Cuántos nodos desea ingresar?: ");
	while (scanf("%d", &n) != 1) {
		printf("Error: ingrese un numero valido: ");
		scanf("%*s"); // elimina cualquier entrada no valida 
	}

    /*-----INGRESO DE NODOS INICIALES-----*/
	for (int i = 0; i < n; i++) {
		printf("\nNodo %d\n", i+1);

		// VALIDAR CODIGO
		printf("Ingrese el codigo: ");
		while (scanf("%d", &dato.codigo) != 1) {
			printf("Error: solo numeros. Intente de nuevo: ");
			scanf("%*s"); // descarta entrada incorrecta
		}

		// VALIDAR NOMBRE
		int valido;
		printf("Ingrese nombre: ");
		do { //repite hasta que el nombre sea válido 
			valido = 1;
			scanf("%s", dato.nombre);

			for (int j = 0; dato.nombre[j] != '\0'; j++) {
				if (!(dato.nombre[j] >= 'A' && dato.nombre[j] <= 'Z') &&
				    !(dato.nombre[j] >= 'a' && dato.nombre[j] <= 'z')) {
					valido = 0;
					break;
				}
			}

			if (!valido) {
				printf("Error: solo letras. Intente de nuevo: ");
			}

		} while (!valido); 

		pila_push(&pila, dato); // coloca el nodo arriba de la pila
	}
	
	/*----------------MENU-----------------*/	
	do {
		printf("\n---MENU---\n");
		printf("1. Agregar 1 nodo\n");
		printf("2. Agregar varios nodos\n");
		printf("3. Ver tamaño de la pila\n");
		printf("4. Eliminar nodo\n");
		printf("5. Salir\n");
		printf("Opcion: ");

		while (scanf("%d", &opcion) != 1) {
			printf("Error: ingrese un numero valido: ");
			scanf("%*s");
		}

		switch(opcion) {
			case 1:
				printf("Codigo: ");
				while (scanf("%d", &dato.codigo) != 1) {
					printf("Error: solo numeros. Intente de nuevo: ");
					scanf("%*s");
				}

				printf("Nombre: ");
				int valido1;
				do {
					valido1 = 1;
					scanf("%s", dato.nombre);

					for (int j = 0; dato.nombre[j] != '\0'; j++) {
						if (!(dato.nombre[j] >= 'A' && dato.nombre[j] <= 'Z') &&
						    !(dato.nombre[j] >= 'a' && dato.nombre[j] <= 'z')) {
							valido1 = 0;
							break;
						}
					}

					if (!valido1) {
						printf("Error: solo letras. Intente de nuevo: ");
					}

				} while (!valido1);

				pila_push(&pila, dato); //se crea un nodo nuevo y se coloca en el tope
			break;

			case 2: 
				printf("¿Cuántos nodos desea agregar?: ");
				while (scanf("%d", &n) != 1) {
					printf("Error: ingrese un numero valido: ");
					scanf("%*s");
				}

				for(int i=0; i<n; i++) {
					printf("Codigo: ");
					while (scanf("%d", &dato.codigo) != 1) {
						printf("Error: solo numeros. Intente de nuevo: ");
						scanf("%*s");
					}

					printf("Nombre: ");
					int valido2;
					do {
						valido2 = 1;
						scanf("%s", dato.nombre);

						for (int j = 0; dato.nombre[j] != '\0'; j++) {
							if (!(dato.nombre[j] >= 'A' && dato.nombre[j] <= 'Z') &&
							    !(dato.nombre[j] >= 'a' && dato.nombre[j] <= 'z')) {
								valido2 = 0;
								break;
							}
						}

						if (!valido2) {
							printf("Error: solo letras. Intente de nuevo: ");
						}

					} while (!valido2);

					pila_push(&pila, dato);
				}
			break;

			case 3:
				printf("Tamaño de la pila: %d\n", pila_tamano(&pila));
			break;

			case 4:
				if(pila_pop(&pila, &dato)) //elimina el tope y devuelve sus datos.
					printf("Nodo eliminado: %d %s\n", dato.codigo, dato.nombre);
				else
					printf("La pila esta vacia\n");
			break;	

			case 5:
				printf("Saliendo del programa...\n");
			break;

			default:
				printf("Opcion invalida. Intente nuevamente.\n");
		}
	} while(opcion != 5); // si el usuario ingresa 5, el programa termina

	pila_destroy(&pila); // se eliminan todos los nodos de la memoria
	
	return 0;
}
