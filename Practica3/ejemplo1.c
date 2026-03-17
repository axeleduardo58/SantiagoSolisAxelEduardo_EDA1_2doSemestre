/*Práctica 3: Estructuras.
Ejercicio 1.
Integrantes: De la Cruz Flores Natalia, Ortiz Hernandez Yesica, Primero Reyes Monserrath, Santiago Solis Axel Eduardo.

Este codigo simula una base de datos de un hospital, permitiendo dar de alta a doctores y pacientes, ambas estructuras permiten 
registrar datos como el nombre del paciente y/o doctor, edad, número de trabajador, dirección del paciente y el doctor que le atiende.*/

/* ================= BIBLIOTECAS ================= */
#include <stdio.h> //Permite usar funciones de entrada y salida
#include <string.h> //Permite trabajar con cadenas de texto

/* ================= ESTRUCTURA HOSPITAL ================= */
//Se crea un tipo de dato nuevo (Hospital)
typedef struct {
    char nombre[30]; //Guarda el nombre del hospital
    char direccion[40]; // Guarda la dirección
} Hospital;

/* ================= ESTRUCTURA DOCTOR ================= */
//Doctor guarda toda la información relacionada con un doctor 
typedef struct {
    char nombre[30];
    int edad;
    int numTrabajador;   //Identificador de trabajo dentro del rango de 1000 - 1999.
    int cantidadPacientes; //Cantidad de pacientes asignados al doctor
} Doctor;

/* ================= ESTRUCTURA PACIENTE ================= */
//Hacemos uso de estructuras dentro de estructuras (estructura anidada).
typedef struct {
    char nombre[30];
    int edad;
    int numPaciente;

    Doctor doctor;       // estructura anidada: el paciente se le asigna un doctor 
    Hospital hospital;   // estructura anidada: hospital donde se atiende 
} Paciente;

/* ================= ARREGLOS ================= */

Doctor doctores[20];
Paciente pacientes[10];

int contadorDoctores = 0;
int contadorPacientes = 0;

/* ================= FUNCION PARA PEDIR ENTERO ================= */

int pedirEntero() { 
    int numero;
    char ter;

    while(scanf("%d%c", &numero, &ter) != 2 || ter != '\n') { /*Se repite hasta que el usuario ingrewse un número valido.*/
        printf("Error: Ingresa solo numeros enteros: ");
        while(getchar() != '\n'); /*Limpia el buffer de entrada (caracteres incorrectos evita que el programa
                                    se quede atrapado en ciclo.*/
    }
    
    return numero; //Devuelve el número validado
}

/*==============FUNCION PARA VALIDAR EL NOMBRE=================*/

int nombreValido(char nombre[]) { /*Verifica que el nombre solo contenga letras mayusculas, minusculas o espacios.*/
    
    for (int i = 0; nombre[i] != '\0'; i++) { /*el caracter nulo indica el final del string.*/
        
        //Verificamos los caracteres a ingresar
        if (!((nombre[i] >= 'A' && nombre[i] <= 'Z') || 
              (nombre[i] >= 'a' && nombre[i] <= 'z') || 
               nombre[i] == ' ')) {
            return 0; // Es invalido
        }
    }
    return 1; // Es valido
}

/* ================= AGREGAR DOCTOR ================= */

void agregarDoctor() {

    if(contadorDoctores == 20) {
        printf("Ya no se pueden agregar mas doctores.\n");
        return;
    }

    printf("\n--- Agregar Doctor ---\n");

    do {
        printf("Nombre: ");
        scanf(" %[^\n]", doctores[contadorDoctores].nombre);

        if (nombreValido(doctores[contadorDoctores].nombre) == 0) {
            printf("El nombre solo puede contener letras y espacios. Intente de nuevo.\n");
        }
    } while (nombreValido(doctores[contadorDoctores].nombre) == 0);
    
    printf("Edad: ");
    doctores[contadorDoctores].edad = pedirEntero();

    do {
        printf("Numero de trabajador (1000-1999): ");
        doctores[contadorDoctores].numTrabajador = pedirEntero();

        if(doctores[contadorDoctores].numTrabajador < 1000 ||
           doctores[contadorDoctores].numTrabajador > 1999) {

            printf("Error: Debe estar entre 1000 y 1999\n");
        }

    } while(doctores[contadorDoctores].numTrabajador < 1000 ||
            doctores[contadorDoctores].numTrabajador > 1999);

    doctores[contadorDoctores].cantidadPacientes = 0;

    contadorDoctores++;

    printf("Doctor agregado correctamente.\n");
}

/* ================= AGREGAR PACIENTE ================= */

void agregarPaciente() {

    if(contadorPacientes == 10) {
        printf("Ya no se pueden agregar mas pacientes.\n");
        return;
    }

    if(contadorDoctores == 0) { //No se registra paciente, si no existe doctor
        printf("Primero debes registrar un doctor.\n");
        return;
    }

    printf("\n--- Agregar Paciente ---\n");

    do {
        printf("Nombre del paciente: ");
        scanf(" %[^\n]", pacientes[contadorPacientes].nombre);

        if (nombreValido(pacientes[contadorPacientes].nombre) == 0) {
            printf("El nombre solo puede contener letras y espacios. Intente de nuevo.\n");
        }
    } while (nombreValido(pacientes[contadorPacientes].nombre) == 0);

    printf("Edad: ");
    pacientes[contadorPacientes].edad = pedirEntero();

    printf("Numero de paciente: ");
    pacientes[contadorPacientes].numPaciente = pedirEntero();

    printf("\nDoctores disponibles:\n");
    for(int i = 0; i < contadorDoctores; i++) { //Recorre el arreglo y muestra las opciones disponibles
        printf("%d. %s (ID: %d)\n", i+1,
               doctores[i].nombre,
               doctores[i].numTrabajador);
    }

    int opcion;

    do {
        printf("Seleccione doctor: ");
        opcion = pedirEntero(); //seleccion del doctor que atendera

        if(opcion < 1 || opcion > contadorDoctores) {
            printf("Opcion invalida.\n");
        }

    } while(opcion < 1 || opcion > contadorDoctores);

    /* ASIGNACION POR PARTES (NO estructura = estructura)*/ 
    
    /*copia el nombre del doctor seleccionado en el registro del paciente
    usamos strcpy por que los string no se pueden asignar directamente*/

    strcpy(pacientes[contadorPacientes].doctor.nombre,
           doctores[opcion-1].nombre);

    pacientes[contadorPacientes].doctor.edad =
           doctores[opcion-1].edad;

    pacientes[contadorPacientes].doctor.numTrabajador =
           doctores[opcion-1].numTrabajador;

    pacientes[contadorPacientes].doctor.cantidadPacientes =
           doctores[opcion-1].cantidadPacientes;

    doctores[opcion-1].cantidadPacientes++;

    printf("\nNombre del hospital: ");
    scanf(" %[^\n]", pacientes[contadorPacientes].hospital.nombre);

    printf("Direccion del hospital: ");
    scanf(" %[^\n]", pacientes[contadorPacientes].hospital.direccion);

    contadorPacientes++;

    printf("Paciente agregado correctamente.\n");
}

/* ================= MOSTRAR ================= */

void mostrarDoctores() {

    printf("\n--- DOCTORES ---\n");

    for(int i = 0; i < contadorDoctores; i++) {

        printf("Doctor %d\n", i+1);
        printf("Nombre: %s\n", doctores[i].nombre);
        printf("Edad: %d\n", doctores[i].edad);
        printf("ID: %d\n", doctores[i].numTrabajador);
        printf("Pacientes: %d\n", doctores[i].cantidadPacientes);
        printf("----------------------\n");
    }
}

void mostrarPacientes() {

    printf("\n--- PACIENTES ---\n");

    for(int i = 0; i < contadorPacientes; i++) {

        printf("Paciente %d\n", i+1);
        printf("Nombre: %s\n", pacientes[i].nombre);
        printf("Edad: %d\n", pacientes[i].edad);
        printf("Doctor: %s\n", pacientes[i].doctor.nombre);
        printf("Hospital: %s\n", pacientes[i].hospital.nombre);
        printf("----------------------\n");
    }
}

/* =================FUNCIÓN MAIN ================= */

int main() { //Controla el menu del sistema hospitalario

    int opcion;

    do {

        printf("\n===== SISTEMA HOSPITAL =====\n");
        printf("1. Agregar Doctor\n");
        printf("2. Agregar Paciente\n");
        printf("3. Mostrar Doctores\n");
        printf("4. Mostrar Pacientes\n");
        printf("5. Salir\n");

        printf("Seleccione opcion: ");
        opcion = pedirEntero();

        switch(opcion) { //ejecuta lo que se le este pidiendo

            case 1: agregarDoctor(); break;
            case 2: agregarPaciente(); break;
            case 3: mostrarDoctores(); break;
            case 4: mostrarPacientes(); break;
            case 5: printf("Saliendo...\n"); break;
            default: printf("Opcion invalida.\n");
        }

    } while(opcion != 5); // se ejecuta hasta que el usuario seleccione la opción de salir 

    return 0;

}
