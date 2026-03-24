/*Práctica 6: Cola Circular y Cola Doble.
Ejercicio 2.
Código completado y modificado por: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

En este codigo se modifica el código anterior y se simula la fila de una tienda, donde se le permite al usuario agregar clientes de manera dinamica,
decidiendo si agregarlos al inicio o final de la cola, así como atenderlos (desencolar) de la misma manera, también puede visualizar el cliente que esta
hasta enfrente, el tamaño de la cola y todos los elementos dentro.*/

#include <stdio.h> //Permite el uso de funciones de entrada y salida 
#include <ctype.h> //Funciona para verificar caracteres 
#include "cola.h" // definición de estructuras y funciones de cola

// función para validar un número entero 
int leerEntero() {
    int x;
    while (scanf("%d", &x) != 1) { // verifica que la entrada sea un entero
        printf("Solo numeros, intente de nuevo: ");
        scanf("%*s"); // limpia los datos que son inválidos en la entrada 
    }
    return x;
}

//función para validar un número decimal 
float leerFloat() {
    float x;
    while (scanf("%f", &x) != 1) {
        printf("Solo numeros, intente de nuevo: ");
        scanf("%*s");
    }
    return x;
}

// función para validar que nombre solo contenga letras 
void leerNombre(char nombre[]) {
    int valido;

    do {
        valido = 1;
        scanf("%s", nombre);

        // recorre cada carácter del nombre 
        for (int i = 0; nombre[i] != '\0'; i++) {
            if (!isalpha(nombre[i])) { // verifica que sean letras 
                valido = 0;
                break;
            }
        }

        if (!valido)
            printf("El nombre solo puede contener letras, intente de nuevo: ");

    } while (!valido); // se repite hasta que sea válido 
}

int main(void) { 

    int n, opcion, capacidad;
    Cola c;
    Cliente cliente;

    printf("Ingrese la capacidad de la cola: ");
    while (scanf("%d", &capacidad) != 1 || capacidad <= 0) {
        printf("Ingrese un numero valido mayor a 0: ");
        scanf("%*s");
    }
    
// inicializa la cola 
    cola_init(&c, capacidad);

    printf("¿Cuantos clientes desea ingresar?: ");
    n = leerEntero();
    
    // registro inicial de clientes 
    for (int i = 0; i < n; i++) {
        printf("\nCliente %d\n", i+1);

        printf("Ingrese numero de cliente: ");
        cliente.numCliente = leerEntero();

        printf("Ingrese nombre: ");
        leerNombre(cliente.nombre);

        printf("Ingrese numero de articulos: ");
        cliente.articulos = leerEntero();

        printf("Ingrese total de compra: ");
        cliente.total = leerFloat();
        
        // coloca al cliente al final de la cola 
        if (!cola_encolar(&c, cliente)) {
            printf("La cola esta llena\n");
            break;
        }
    }

    do {
        printf("\n---MENU---\n");
        printf("1. Agregar 1 cliente al final.\n");
        printf("2. Agregar varios clientes al final\n");
        printf("3. Agregar 1 cliente al inicio.\n");
        printf("4. Atender cliente al frente\n");
        printf("5. Atender cliente al final\n");
        printf("6. Ver tamaño de la cola\n");
        printf("7. Ver cliente al frente\n");
        printf("8. Mostrar toda la cola\n");
        printf("9. Salir\n");
        printf("Opcion: ");

        opcion = leerEntero();

        switch(opcion) {

            case 1: // inserta a un cliente al final 
                printf("Numero de cliente: ");
                cliente.numCliente = leerEntero();

                printf("Nombre: ");
                leerNombre(cliente.nombre);

                printf("Articulos: ");
                cliente.articulos = leerEntero();

                printf("Total: ");
                cliente.total = leerFloat();

                if (!cola_encolar(&c, cliente)) {
                    printf("La cola esta llena\n");
                }
            break;

            case 2: // coloca varios clientes al final 
                printf("¿Cuántos clientes desea agregar?: ");
                n = leerEntero();

                for (int i = 0; i < n; i++) {
                    printf("\nCliente %d\n", i+1);

                    printf("Numero de cliente: ");
                    cliente.numCliente = leerEntero();

                    printf("Nombre: ");
                    leerNombre(cliente.nombre);

                    printf("Articulos: ");
                    cliente.articulos = leerEntero();

                    printf("Total: ");
                    cliente.total = leerFloat();

                    if (!cola_encolar(&c, cliente)) {
                        printf("La cola esta llena\n");
                        break;
                    }
                }
            break;

            case 3: // coloca a un cliente al inicio 
                printf("Numero de cliente: ");
                cliente.numCliente = leerEntero();

                printf("Nombre: ");
                leerNombre(cliente.nombre);

                printf("Articulos: ");
                cliente.articulos = leerEntero();

                printf("Total: ");
                cliente.total = leerFloat();

                if (!cola_encolar_frente(&c, cliente)) {
                    printf("La cola esta llena\n");
                }
            
            break;

            case 4: { // elimina a un cliente del frente 
                Cliente x;
                if (cola_desencolar(&c, &x))
                    printf("Atendido: %d %s, total: %.2f\n", x.numCliente, x.nombre, x.total);
                else
                    printf("La cola esta vacia\n");
            
                break;
            }

            case 5: { // elimina a un cliente del final 
                Cliente x;
                if (cola_desencolar_final(&c, &x))
                    printf("Atendido (final): %d %s, total: %.2f\n", x.numCliente, x.nombre, x.total);
                else
                    printf("La cola esta vacia\n");
                break;
            }
            
            case 6: // muestra el tamaño de la cola 
                printf("Tamaño actual: %d\n", cola_tamano(&c));
            break;

            case 7: { // muestra el cliente al frente sin eliminarlo 
                Cliente f;
                if (cola_frente(&c, &f))
                    printf("Frente: %d %s, total: %.2f\n", f.numCliente, f.nombre, f.total);
                else
                    printf("La cola esta vacia\n");
            
                break;
            }

            case 8: // muestra todos los elementos que hay en la cola 
                cola_mostrar(&c);
            break;

            case 9: 
                printf("Saliendo.\n");
            break;

            default: // opción inválida 
                printf("Opcion invalida\n");
        }

    } while(opcion != 9);

    cola_destroy(&c);// libera la memoria de la cola 

    return 0;
}
