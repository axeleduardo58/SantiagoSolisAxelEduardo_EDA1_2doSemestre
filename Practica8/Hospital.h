/*Práctica 8: Lista Doblemente Ligada y Lista Doblemente Circular.
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.

Este archivo contiene las estructuras y funciones necesarias para manejar el sistema hospitalario
Incluye hospitales, doctores, pacientes, trabajadores, intendencia, especialidades y equipos médicos, 
así como funciones para validar datos, leer información y realizar operaciones de agregar y mostrar registros.
El sistema utiliza listas doblemente ligadas circulares y relaciones entre entre estructuras para
mantener una organización y sincronización con los datos que se manejan*/

#ifndef HOSPITAL_H
#define HOSPITAL_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // sirve para la validacion de caracteres 

/*------------------- VALIDACIONES --------------------*/
int soloLetras(char *);  // valida que solo haya letras 
int soloNumeros(char *);  //valida que solo haya numeros 
int soloTextoLibre(char *); // permite que el texto sea mas flexible 
int esConector(char *); 
void corregirNombre(char *); 

/*---------------------- LECTURA DE DATOS -------------------*/
void leerTexto (char *, char *, int);    
void leerTextoLibre (char *, char *, int);
int leerNumero (char *);
int leerEnteroPositivo (char *);
int leerBinario (char *);

/*------------------ HOSPITAL -------------------*/
typedef struct nodoHospital { // se crea la estructura y sus elemntos dentro de ella 
 char nombre[100];  //nombre del hospital 
 char direccion[150];  //direccion del hospital 
struct nodoHospital *sig; // el apuntador al siguente nodo 
struct nodoHospital *ant; // el apuntador al nodo anterior 
}nodoHospital;
typedef struct { 
 nodoHospital *h;  //apuntador al inicio de la lista
}listaHospital;

/*------------------ DOCTOR -------------------*/
typedef struct nodoDoctor {  
 char nombre[100];  
 int edad; 
 int num_doctor; //ID del doctor (1000-1999)
 struct nodoEspecialidad *especialidad;  
 struct nodoTrabajador *trabajador; 
 struct nodoDoctor *sig;
 struct nodoDoctor *ant;
}nodoDoctor;
typedef struct {
 nodoDoctor *h;  // da inicio a la lista de doctores 
}listaDoctor;

/*------------------ PACIENTE -------------------*/
typedef struct nodoPaciente {  
 char nombre[100];  
 int edad; 
 int num_paciente; //ID unico
 struct nodoDoctor *doctor; // doctor asignado 
 struct nodoEspecialidad *especialidad;  // especialidad a la que entra 
 struct nodoHospital *hospital;  // hospital donde se esta acudiendo 
 struct nodoPaciente *sig; 
 struct nodoPaciente *ant; 
}nodoPaciente;
typedef struct {
 nodoPaciente *h;   
}listaPaciente;

/*------------------ TRABAJADOR -------------------*/
typedef struct nodoTrabajador { 
 int num_trabajador; 
 int sindicalizado;  
 char tipo[20]; // Doctor o intendencia
 struct nodoTrabajador *sig; 
 struct nodoTrabajador *ant; 
}nodoTrabajador;
typedef struct {  
 nodoTrabajador *h;   
}listaTrabajador;

/*------------------ INTENDENCIA -------------------*/
typedef struct nodoIntendencia {  
 char nombre [100];   
 int edad;   
 int num_intendente; //ID (2000-2999)
 struct nodoTrabajador *trabajador;
 struct nodoIntendencia *sig;   
 struct nodoIntendencia *ant;
}nodoIntendencia;
typedef struct {
 nodoIntendencia *h;  // inicia la lista del personal de intendencia 
}listaIntendencia;

/*------------------ ESPECIALIDAD -------------------*/
typedef struct nodoEspecialidad {   
 char nombre [100];   
 int num_doctores;    
 int num_pacientes;  
 struct nodoEquipo *equipo; 
 struct nodoEspecialidad *sig;
 struct nodoEspecialidad *ant;
}nodoEspecialidad;
typedef struct {
 nodoEspecialidad *h;   //incio de la lista especialidad 
}listaEspecialidad;

/*------------------ EQUIPO MEDICO -------------------*/
typedef struct nodoEquipo {
 char nombre [100];    
 char marca [100];  
 char modelo [100];  
 struct nodoEquipo *sig;
 struct nodoEquipo *ant; 
} nodoEquipo;
typedef struct {
 nodoEquipo *h;    
}listaEquipo;

/*------------------------ INICIALIZAR LISTAS -----------------------*/
void inicializarHospital(listaHospital*);
void inicializarDoctor(listaDoctor*);
void inicializarPaciente(listaPaciente*);
void inicializarTrabajador(listaTrabajador*);
void inicializarIntendencia(listaIntendencia*);
void inicializarEspecialidad(listaEspecialidad*);
void inicializarEquipo(listaEquipo*);

/*----------- FUNCIONES DE CONTROL ------------*/
int existePaciente(listaPaciente*, int);
int existeTrabajador(listaTrabajador*, int);

/*------------------ AGREGAR -------------------*/
void agregarHospital(listaHospital*);
void agregarDoctor(listaDoctor*, listaEspecialidad*, listaTrabajador*);
void agregarPaciente(listaPaciente*, listaDoctor*, listaHospital*);
void agregarIntendencia(listaIntendencia*, listaTrabajador*);
void agregarEspecialidad(listaEspecialidad*, listaEquipo*);
void agregarEquipo(listaEquipo*);

/*------------------ MOSTRAR -------------------*/
void mostrarHospital(listaHospital*);
void mostrarDoctor(listaDoctor*);
void mostrarPaciente(listaPaciente*);
void mostrarTrabajador(listaTrabajador*);
void mostrarIntendencia(listaIntendencia*);
void mostrarEspecialidad(listaEspecialidad*);
void mostrarEquipo(listaEquipo*);
#endif
