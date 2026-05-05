/*Práctica: 10 Estrategia para la contrucción de algoritmos I
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
Bubble Sort ordena un arreglo comparando elementos consecutivos e intercambiándolos si están en desorden. 
Utiliza dos ciclos para recorrer el arreglo y una variable booleana para detectar si ya está ordenado, 
optimizando así su ejecución */ 

#include <stdbool.h> //Activa el tipo booleano (true/false) para controlar condiciones
#include "bubble.h" //mandamos a llamar las funciones de bubble.h
/*Función auxiliar para intercambiar dos valores en memoria*/
static void swap(int* a, int* b) { 
int temp = *a; // guarda el valor de a temporalmente
*a = *b;
*b = temp; // coloca el valor original de a en b.
}
/*Función principal que ordena el arreglo usando Bubble Sort*/
void bubbleSort(int arr[], int n) {
  bool swapped; // detecta si hubo cambios 
  for(int i = 0; i < n - 1; i++) {
    swapped = false; // se recicla en cada recorrido
    for(int j = 0; j < n - i - 1; j++) {
       if(arr[j] > arr[j+1]) { // si estan en desorden 
         swap(&arr[j], &arr[j+1]); //se intercambian
           swapped = true; //marca el cambio
       }
    }
    if(!swapped) break; // de no haber intercambio ya esta ordenado
  }
}
