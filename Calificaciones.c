/*Práctica 1: Arreglos lineales y matriciales.
Ejercicio 2.
Integrantes:
Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

Lo que este programa hace es recibir las calificaciones de 20 alumnos para poder obtener el
promedio de la clase, además de mostrar el arreglo lineal de las calificaciones.
*/

#include <stdio.h>

int main() {

    float calificaciones[20];
    float suma = 0, promedio;
    int i;

    for(i = 0; i < 20; i++) {

        do {
            printf("Ingrese la calificacion del alumno %2d : ", i + 1);
            scanf("%f", &calificaciones[i]);

            if(calificaciones[i] < 0 || calificaciones[i] > 10) {  //se verifica que la calificacion sea válida.
                printf("La calificacion debe estar entre 0 y 10.\n");
            }

        } while(calificaciones[i] < 0 || calificaciones[i] > 10);

        suma += calificaciones[i]; //se van sumando las calificaciones para el promedio.
    }

    promedio = suma / 20; //se obtiene el promedio de las calificaciones del grupo.

    printf("\n=========== Arreglo lineal ===========\n");
    printf("====== Calificaciones del grupo ======\n");

    for(i = 0; i < 20; i++) {  //se imprime el arreglo de forma lineal (horizontal).
        printf("%.2f  ", calificaciones[i]);
    }

    printf("\n\nPromedio del grupo: %.2f\n", promedio);

    return 0;
}