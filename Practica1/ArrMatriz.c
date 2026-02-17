/*Ejercicio1_ Práctica 1: Arreglos Matriciales
Santiago Solis Axel Eduardo, Ortiz Hernández Yesica, Primero Reyes Monserrath_

ARREGLO MATRICIAL CON ENTEROS
En este código se solicita al usuario el número de filas y columnas.
Los datos ingresados se almacenan en la matriz y al final se muestran en forma de tabla con un buen formato
*/

#include <stdio.h>

int main() {

    // variables que ocuparemos en el programa 
    int filas, columnas; // para arreglos con enteros
    int f2, c2; // para arreglos con flotantes
    int f3, c3; // para arreglos con caracteres


    // se le pide al usuario la cantidad de filas en el arreglo matricial
    printf("Cuantas filas tendra la matriz de enteros? ");
    scanf("%d", &filas);

    // se le pide al usuario la cantidad de filas en el arreglo matricial
    printf("Cuantas columnas tendra la matriz de enteros? ");
    scanf("%d", &columnas);

    int enteros[filas][columnas];

    // Llenar matriz
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf("Ingresa valor en [%d][%d]: ", i, j);
            scanf("%d", &enteros[i][j]);
        }
    }

    // Mostrar matriz final con los numeros dados por el usuario
    printf("\nMATRIZ DE ENTEROS\n\n");
    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            printf("%d\t", enteros[i][j]);
        }
        printf("\n");
    }


// ARREGLO MATRICIAL CON FLOAT(FLOTANTES)
// Este codigo se encarga de imprimir una matriz una vez que el usiario ya haya predetermiando la cantidad 
// de filas y de columnas de la matriz, esta se imprimira con un fomato ya establecido

    // se le pide al usuario la cantidad de filas en el arreglo matricial
    printf("\nCuantas filas tendra la matriz float? ");
    scanf("%d", &f2);

    // se le pide al usuario la cantidad de columnas en el arreglo matricial
    printf("Cuantas columnas tendra la matriz float? ");
    scanf("%d", &c2);

    float flotantes[f2][c2];

    // se llena la matriz
    for(int i = 0; i < f2; i++) {
        for(int j = 0; j < c2; j++) {
            printf("Ingresa valor flotante en [%d][%d]: ", i, j);
            scanf("%f", &flotantes[i][j]);
        }
    }

    // Mostrar matriz final con los numeros dados por el usuario
    printf("\nMATRIZ DE FLOAT\n\n");
    for(int i = 0; i < f2; i++) {
        for(int j = 0; j < c2; j++) {
            printf("%.2f\t", flotantes[i][j]);
        }
        printf("\n");
    }


/*ARREGLO MATRICIAL CON CARACTERES
En este código se solicita al usuario el número de filas y columnas.
Los datos ingresados se almacenan en la matriz y al final se muestran en forma de tabla con un buen formato.
*/

    // se le pide al usuario la cantidad de filas en el arreglo matricial
    printf("\nCuantas filas tendra la matriz de caracteres? ");
    scanf("%d", &f3);
        
    // se le pide al usuario la cantidad de columnas en el arreglo matricial
    printf("Cuantas columnas tendra la matriz de caracteres? ");
    scanf("%d", &c3);

    char caracteres[f3][c3];

    // se llena la matriz
    for(int i = 0; i < f3; i++) {
        for(int j = 0; j < c3; j++) {
            printf("Ingresa caracter en [%d][%d]: ", i, j);
            scanf(" %c", &caracteres[i][j]);
        }
    }

    // se imprime la matriz ya con el fomato predetermiando
    printf("\nMATRIZ DE CARACTERES\n\n");
    for(int i = 0; i < f3; i++) {
        for(int j = 0; j < c3; j++) {
            printf("%c\t", caracteres[i][j]);
        }
        printf("\n");
    }

    return 0;
}
