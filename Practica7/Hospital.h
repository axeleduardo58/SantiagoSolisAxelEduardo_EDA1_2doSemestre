/*Práctica 7: Lista Ligada Circular.
Realizado por: Primero Reyes Monserrath, Santiago Solís Axel Eduardo, Ortiz Hernández Yesica, De la Cruz Flores Natalia.
Este archivo contiene las estructuras y funciones necesarias para manejar el sistema hospitalario
Incluye la definición de hospitales, doctores, pacientes, trabajadores, intendencia, especialidades 
y equipos médicos, así como funciones para validar datos, leer información y realizar operaciones de agregar y mostrar registros.*/

#ifndef HOSPITAL_H
#define HOSPITAL_H 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h> // sirve para la validacion de caracteres 

/*------------------- VALIDACIONES --------------------*/
int soloLetras(char *);  // valida que solo haya letras 
int soloNumeros(char *);  //valida que solo haya numeros 
int nombreCorrecto(char *); //valida que el nombre  este en un formato correcto 
int soloTextoLibre(char *); // permite que el texto sea mas flexible 

/*------------------ HOSPITAL -------------------*/
typedef struct nodoHospital { // se crea la estructura y sus elemntos dentro de ella 
 char nombre[100];  //nombre del hospital 
 char direccion[150];  //direccion del hospital 
struct nodoHospital *sig; // el apuntador al siguente nodo 
}nodoHospital;
typedef struct { 
 nodoHospital *h;  //apuntador al inicio de la lsita
}listaHospital;

/*------------------ DOCTOR -------------------*/
typedef struct nodoDoctor {  // estructura del campo del doctor 
 char nombre[100];  // nombre del doctor
 int edad; // edad del doctor 
 int num_doctor; // numero de identificador del doctor
 int num_paciente; // pacientes asignados 
 struct nodoEspecialidad *especialidad;  // apuntador a la especialdad 
 struct nodoTrabajador *trabajador;  // apunta a la informacion laboral 
 struct nodoDoctor *sig; // apunta al siguiente doctor 
}nodoDoctor;
typedef struct {
 nodoDoctor *h;  // da inicio a la lista de doctores 
}listaDoctor;

/*------------------ PACIENTE -------------------*/
typedef struct nodoPaciente {  // estructura del paciente
 char nombre[100];  // nombre del paciente 
 int edad; // edad del mismo 
 int num_paciente; // identificador del paciente 
 struct nodoDoctor *doctor; // doctor asignado 
 struct nodoEspecialidad *especialidad;  // especialidad a la que entra 
 struct nodoHospital *hospital;  // hospital donde se esta acudiendo 
 struct nodoPaciente *sig;  // apunta al siguente paciente 
}nodoPaciente;
typedef struct {
 nodoPaciente *h;  // inicio de la lista de los pacientes 
}listaPaciente;

/*------------------ TRABAJADOR -------------------*/
typedef struct nodoTrabajador { //Estructura de los trabajadores 
 int num_trabajador; // identificador del trabajador
 int sindicalizado; // verificacion de sindicalizacion 
 char tipo[20]; // a que se dedica
 struct nodoTrabajador *sig;  // apunta al siguente  trabajador
}nodoTrabajador;
typedef struct {  
 nodoTrabajador *h;   // inicio de la lista de los trabajadores 
}listaTrabajador;

/*------------------ INTENDENCIA -------------------*/
typedef struct nodoIntendencia {   // estructura de las personas de intendencia 
 char nombre [100];   // nombre del trabajador
 int edad;    // la edad del trabajador 
 struct nodoTrabajador *trabajador; // apuntador al tipo de trabajador
 struct nodoIntendencia *sig;  // apuntador al siguiente personal de intendencia 
}nodoIntendencia;
typedef struct {
 nodoIntendencia *h;    // inicia la lista del personal de intendencia 
}listaIntendencia;

/*------------------ ESPECIALIDAD -------------------*/
typedef struct nodoEspecialidad {    // se crea la estructura de la especialidad 
 char nombre [100];  // el nombre de la misma  
 int num_doctores;   // el numero de doctores de esa especialidad 
 int num_pacientes;  // el numero de pacientes que se encuentran 
 struct nodoEquipo *equipo;   // apuntador a la estructira del equipo medico 
 struct nodoEspecialidad *sig;  // apuntador a la sigunete especialidad  
}nodoEspecialidad;
typedef struct {
 nodoEspecialidad *h;   //incio de la lista especialidad 
}listaEspecialidad;

/*------------------ EQUIPO MEDICO -------------------*/
typedef struct nodoEquipo {   // Creacion de la esctructura del equipo medico 
 char nombre [100];    // nombre del equipo 
 char marca [100];   // marca del equipo 
 char modelo [100];  // modelo del equipo 
 struct nodoEquipo *sig;   //a´puntador al siguiente equipo medico 
}nodoEquipo;
typedef struct {
 nodoEquipo *h;    // da inicio a la lista de equipo medico 
}listaEquipo;

/*
De aqui en adelante el nombre de las funciones es lo que hace no hace falta comentar su funcionamiento */
/*------------------------ LECTURA -----------------------*/
void leerTexto (char *, char *, int);    
void leerTextoLibre (char *, char *, int);
int leerNumero (char *);
int leerEnteroPositivo (char *);
int leerBinario (char *);
/*------------------------ FUNCIONES -----------------------*/
void inicializarHospital(listaHospital*);
void inicializarDoctor(listaDoctor*);
void inicializarPaciente(listaPaciente*);
void inicializarTrabajador(listaTrabajador*);
void inicializarIntendencia(listaIntendencia*);
void inicializarEspecialidad(listaEspecialidad*);
void inicializarEquipo(listaEquipo*);

/*------------------ AGREGAR -------------------*/
void agregarHospital(listaHospital*);
void agregarDoctor(listaDoctor*, listaEspecialidad*, listaTrabajador*, listaEquipo*);
void agregarPaciente(listaPaciente*, listaDoctor*, listaEspecialidad*, listaHospital*);
void agregarTrabajador(listaTrabajador*);
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








  
