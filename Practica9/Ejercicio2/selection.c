/* Práctica: 10 Estrategia para la contrucción de algoritmos I
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
Selection Sort ordena un arreglo buscando el elemento más pequeño en cada iteración y 
colocándolo en su posición correcta. Este proceso se repite hasta ordenar completamente el arreglo. */

#include "selection.h"
//Función auxiliar para intercambiar valores
static void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
//Función para ordenar el arreglo usando Selection Sort
void selectionSort(int arr[], int n) {
  for(int i = 0; i < n - 1; i++) {
    int min = i; //Supone que el minimo esta en la posición actual
    // Busca al elemento mas pequeño de todo el arreglo
    for(int j = i + 1; j < n; j++) {  
      if(arr[j] < arr[min]) {
        min = j; //Actualiza la posicion del minimo
      }
    }
    //Intercambia al minimo con pasicion actual
    swap(&arr[i], &arr[min]);
  }
}
