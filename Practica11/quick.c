/* Práctica 11: Recursividad
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
Quick Sort organiza los elementos separándolos alrededor de un pivote, colocando los menores a un lado y los mayores al otro. 
Después repite el proceso en cada sección hasta ordenar completamente el arreglo. */

#include "quick.h"
//Función auxiliar para intercambiar valores
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
//Divide el arreglo usando un pivote
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // Tomamos el ultimo elemento como pivote
  int i = low - 1;
  for(int j = low; j <= high - 1; j++) {
    if(arr[j] < pivot) { // si el elemento es menor al pivote
       i++;
       swap(&arr[i], &arr[j]);// Lo movemos a izquierda
    }
  }
  //colocamos al pivote en la pocición correcta
  swap(&arr[i + 1], &arr[high]);
  return i + 1;
}
//Función para ordenar el arreglo usando quick sort recursivo
void quickSort(int arr[], int low, int high) {
  if(low < high) {
    //verificamos que exitan elementos por ordenar
    int pi = partition(arr, low, high);
    //ordena de izquierda a derecha
    quickSort(arr, low, pi - 1);
    quickSort(arr, pi + 1, high);
    
  }
}
  
