/*Práctica: 10 Estrategia para la contrucción de algoritmos I
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
El archivo main.c controla la ejecución del programa, permitiendo al usuario seleccionar el algoritmo de ordenamiento 
y el tamaño del arreglo. Genera datos aleatorios, mide el tiempo de ejecución y ejecuta el algoritmo elegido, 
coordinando todos los módulos del sistema. */ 

#include <stdio.h>
#include <stdlib.h>  //Funciones generales (rand, srand)
#include <time.h>   //Medicion de tiempo (clock, time)
#include "utils.h" //Funciones auxiliares (validacion, arreglos)
#include "bubble.h" //Bubble Sort
#include "insertion.h" // Insertion Sort
#include "selection.h" //Selection Sort

int main() {
  int opcionAlg, opcionTam, n; //Variables de control
  srand(time(NULL)); //Inicializa numeros aleatorios diferentes cada ejecucion
  
  printf("----- ALGORITMOS -----\n");
  printf("1. Bubble Sort\n");
  printf("2. Insertion Sort\n");
  printf("3. Selection Sort\n");
  opcionAlg = leerEnteroEnRango("Selecciona algoritmo: ", 1, 3);
  
  printf("\n----- TAMANOS -----\n");
  printf("1. 100\n");
  printf("2. 200\n");
  printf("3. 500\n");
  printf("4. 1000\n");
  printf("5. 10000\n");
  opcionTam = leerEnteroEnRango("Selecciona tamano: ", 1, 5);

  switch(opcionTam) {
    case 1: n = 100; break;
    case 2: n = 200; break;
    case 3: n = 500; break;
    case 4: n = 1000; break;
    case 5: n = 10000; break;
  }
  int arr[n];
  // MEDIR LA CREACION DEL ARREGLO
  clock_t inicio = clock(); //Inicio de medición
  llenarArreglo(arr, n); //Genera los numeros aleatorios
  clock_t fin = clock(); //Fin de la medición
  printf("\nTiempo de creacion: %f segundos\n",
           (double)(fin - inicio) / CLOCKS_PER_SEC);
  // ORDENAMIENTO
  inicio = clock(); // Inicio medicion del algoritmo
  if(opcionAlg == 1) {
    bubbleSort(arr, n);
    printf("Algoritmo: Bubble Sort\n");
  }
  else if(opcionAlg == 2) {
    insertionSort(arr, n);
    printf("Algoritmo: Insertion Sort\n");
  } 
  else{
    selectionSort(arr, n);
    printf("Algoritmo: Selection Sort\n");
  }
  fin = clock(); //fin medicion
  printf("Tiempo de ordenamiento: %f segundos\n",
         (double)(fin - inicio) / CLOCKS_PER_SEC);
  return 0;  
}
