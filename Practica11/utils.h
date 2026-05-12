/* Práctica 11: Recursividad 
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
Se hizo uso de "directivas de procesador (#ifndef, #define, #endif) para evitar repetirlo en cada código, así
para así el programa no tenga errores de copilación. */

#ifndef UTILS_H //si UTILS_H no esta definido, entonces continua
#define UTILS_H //Apartir de aquí UTILS_H ya existe  

int leerEnteroEnRango(const char *mensaje, int min, int max);
void llenarArreglo(int arr[], int n); //Llenar arreglo con aleatorios
void copiarArreglo(int origen[], int detino[], int n); // copiar arreglos
#endif
