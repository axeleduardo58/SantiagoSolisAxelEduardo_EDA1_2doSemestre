/*Práctica: 10 Estrategia para la contrucción de algoritmos I
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
Insertion Sort ordena un arreglo tomando un elemento y colocándolo en su posición correcta dentro de una parte ya ordenada del arreglo. 
Para ello, desplaza los elementos mayores hacia la derecha y finalmente inserta el valor en su lugar adecuado.
*/

#include "insertion.h"

//Funcióm que ordena el arreglo usando insertionSort
void insertionSort(int arr[], int n) {
  for(int i = 1; i < n; i++) { //Recorre desde el segundo elemento
    int key = arr[i]; // elemento actual a insertar
    int j = i - 1; // indice del elemento anterior
    //// Mueve los elementos mayores que 'key' una posicion adelante
    while(j >= 0 && arr[j] > key) {
       arr[j+1] = arr[j]; //Desplaza el elemento
      j--; //retrocede en el arreglo
    }
    arr[j+1] = key; //colaca al elemento en su posicicón correcta.
   } 
  }
