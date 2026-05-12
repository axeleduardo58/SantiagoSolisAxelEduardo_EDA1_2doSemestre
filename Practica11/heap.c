/* Práctica 11: Recursividad
Realizado por: 
Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
Heap Sort organiza los datos como si fueran un árbol, colocando el valor más grande en la raíz para 
enviarlo al final del arreglo de forma ordenada. El proceso se repite hasta completar el ordenamiento. */

#include "heap.h"
//Combiete  los hijos en heap
void heapify(int arr[], int n, int i) {
  int largest = i;
  int l = 2 * i + 1; //hijo izquierdo
  int r = 2 * i + 2;//hijo derecho
  if(l < n && arr[l] > arr[largest]) // verifica si el hijo izquierdo es mayor
    largest = l;
  if(r < n && arr[r] > arr[largest]) // verifica si el hijo derecho es mayor
    largest = r;
  if(largest != i) { //Verifica si la raiz no es el mayor
    //intercambia elemtos 
    int temp = arr[i];
    arr[i] = arr[largest];
    arr[largest] = temp;
    heapify(arr, n, largest);//reorganiza el árbol y a sus hijos 
  }
}
//Función para ordenar el arreglo usando Heap Sort
void heapSort(int arr[], int n) {
  for(int i = n / 2 - 1; i >= 0; i--)//construye el heap
    heapify(arr, n, i);
  for(int i = n - 1; i > 0; i--) {//extraemos elementos uno por uno
    int temp = arr[0];
    arr[0] = arr[i];
    arr[i] = temp;
    heapify(arr, i, 0); //reacomoda el heap
  }
}
