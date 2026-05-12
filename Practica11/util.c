/* Práctica 11: Recursividad
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.

El archivo utils.c apoya al programa para que todo funcione bien. leerEnteroEnRango evita errores al validar lo que 
escribe el usuario, llenarArreglo genera datos aleatorios y copiarArreglo permite trabajar con copias para comparar 
los algoritmos de forma justa.
*/

#include <stdio.h>
#include <stdlib.h> // lo usamos por el rand(), que nos arroja los números aleatorios
#include "utils.h" // El programa se vincula 
//Validamos entradas del usuario
int leerEnteroEnRango(const char *mensaje, int min, int max){ 
  int valor; // lo que el usuario intenta ingresar
  int resultado; // lo que devuelve scanf (datos validos leidos)
  do {
    printf("%s", mensaje);
    resultado = scanf("%d", &valor); // se lee un entero
    if (resultado != 1) {
      printf("Entrada invalida, ingrese una opción correcta\n");
      while(getchar() != '\n'); // limpiar buffer
      continue;
    }
    if (valor < min || valor > max) { // en caso de que el número este fuera del rango permitido
      printf("Opcion fuera de rango (%d - %d). Intenta de nuevo.\n", min, max);
    }
  } while (valor < min || valor > max);
  return valor; // devuelve un entero
}
void llenarArreglo(int arr[], int n){ // recibe un arreglo y su tamaño
  for(int i = 0; i < n; i++){
    arr[i] = rand() % 10000; // asigna un numero aleatorio entre 0 y 9999 se limita a 10000.
  }
}
void copiarArreglo(int origen[], int destino[], int n) { //recibe dos arreglos y su tamaño
  for(int i = 0; i < n; i++) {
    destino[i] = origen[i]; // copia elemento por elemento
  }
}
