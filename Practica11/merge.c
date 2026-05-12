/* Práctica 11: Recursividad
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
Merge Sort divide el arreglo en partes pequeñas, las ordena y posteriormente las vuelve a unir de manera organizada 
hasta obtener el arreglo completamente ordenado. */

#include "merge.h"
//Une dos subarreglos ordenados
void merge(int arr[], int l, int m, int r) {
  int n1 = m - l + 1;
  int n2 = r - m;
  int L[n1], R[n2];// arreglos temporales
  for(int i = 0; i < n1; i++) // copia datos del arr izq
    L[i] = arr[l + i];
  for(int j = 0; j < n2; j++) // copia datos del arr derecho
    R[j] = arr[m + 1 + j];
  int i = 0, j = 0, k = l;
   while(i < n1 && j < n2) { //combina arreglos ordenados
     if(L[i] <= R[j]) {
       arr[k] = L[i];
       i++;
     }
     else {
       arr[k] = R[j];
       j++;
     }
     k++;
   }
  //copia lo que nos sobra del arreglo izquierdo
   while(i < n1) {
     arr[k++] = L[i++];
   }
  //copia lo que nos sobra del arreglo derecho
   while(j < n2) {
     arr[k++] = R[j++];
   }  
}
//Función para ordenar el arreglo usando merge sort recursivo
void mergeSort(int arr[], int l, int r) {
  if(l < r) {
    int m = l + (r - l) / 2; // divide el arreglo nos da la pocición 
    //ordena de izquierda a derecha
    mergeSort(arr, l, m); // divide por la izquierda
    mergeSort(arr, m + 1, r); // divide por la derecha
    merge(arr, l, m, r); // une ambas partes
  }
}
