/*Práctica 7: Lista Ligada Circular.
Realizado por: Primero Reyes Monserrath, Santiago Solís Axel Eduardo, Ortiz Hernández Yesica, De la Cruz Flores Natalia.
/*Este archivo contiene el programa principal donde se controla todo el sistema
hospitalario mediante menús. Aquí se inicializan las listas y se le permite al usuario 
agregar o visualizar información de hospitales, pacientes, doctores, trabajadores, intendencia,
especialidades y equipos médicos, seleccionando opciones desde el menú.
*/
#include "Hospital.h"          // inclye todas las etsructuras y sus funciones 

int main() { 
    /*En esta parte se declaran las listas para cada tipo de dato dentro del proograma */
    listaHospital hospitales;
    listaDoctor doctores;
    listaPaciente pacientes;
    listaTrabajador trabajadores;
    listaIntendencia intendencias;
    listaEspecialidad especialidades;
    listaEquipo equipos;

    /*Se inicializan las listas y las dejamos vacias */
    inicializarHospital(&hospitales);
    inicializarDoctor(&doctores);
    inicializarPaciente(&pacientes);
    inicializarTrabajador(&trabajadores);
    inicializarIntendencia(&intendencias);
    inicializarEspecialidad(&especialidades);
    inicializarEquipo(&equipos);

    int op, sub;  // variables para opciones del menu 
    do {
        // menu principal 
        printf("\n-------- MENU PRINCIPAL --------\n");
        printf("1. Agregar datos\n");
        printf("2. Visualizar datos\n");
        printf("3. salir\n");
        printf("Opcion: ");

        // restruccion para asi validar la opcion
        while (scanf("%d", &op) != 1 || op < 1 || op > 3) {
            printf("Seleccione una opcion valida: ");
            while (getchar() != '\n');
        }

        switch (op) {
            case 1:
                do {
                    // sub menu para agregar datos 
                    printf("\n---------- MENU AGREGAR----------\n");
                    printf("1. Hospital\n");
                    printf("2. Paciente\n");
                    printf("3. Trabajador\n");
                    printf("4. Doctor\n");
                    printf("5. Intendencia\n");
                    printf("6. Especialidad\n");
                    printf("7. Equipo Medico\n");
                    printf("8. Regresar\n");
                    printf("Opcion: \n");

                    // validacion para el sub menu 
                    while (scanf("%d", &sub) != 1 || sub < 1 || sub > 8) {
                        printf("Seleccione una opcion valida: ");
                        while (getchar() != '\n');
                    }

                    getchar(); // sirve para limpiar los saltos de linea 

                    // Ejecuta la funcion segun la opcion elegida 
                    switch (sub) {
                        case 1: agregarHospital(&hospitales); break;
                        case 2: agregarPaciente(&pacientes, &doctores, &especialidades, &hospitales); break;
                        case 3: agregarTrabajador(&trabajadores); break;
                        case 4: agregarDoctor(&doctores, &especialidades, &trabajadores, &equipos); break;
                        case 5: agregarIntendencia(&intendencias, &trabajadores); break;
                        case 6: agregarEspecialidad(&especialidades, &equipos); break;
                        case 7: agregarEquipo(&equipos); break;
                    }

                } while (sub != 8); 
                break;

            case 2:
                do {
                    // sub menu para pider visualizar los datos 
                    printf("\n---------- MENU VISUALIZAR----------\n");
                    printf("1. Hospital\n");
                    printf("2. Paciente\n");
                    printf("3. Trabajador\n");
                    printf("4. Doctor\n");
                    printf("5. Intendencia\n");
                    printf("6. Especialidad\n");
                    printf("7. Equipo Medico\n");
                    printf("8. Regresar\n");
                    printf("Opcion: \n");

                    //validacion de opciones para el sub menu 
                    while (scanf("%d", &sub) != 1 || sub < 1 || sub > 8) {
                        printf("Seleccione una opcion valida: ");
                        while (getchar() != '\n');
                    }

                    getchar();
                    
                    // Llama a la funcion para mostrar los datos segun la opcion elegida 
                    switch (sub) {
                        case 1: mostrarHospital(&hospitales); break;
                        case 2: mostrarPaciente(&pacientes); break;
                        case 3: mostrarTrabajador(&trabajadores); break;
                        case 4: mostrarDoctor(&doctores); break;
                        case 5: mostrarIntendencia(&intendencias); break;
                        case 6: mostrarEspecialidad(&especialidades); break;
                        case 7: mostrarEquipo(&equipos); break;
                    }

                } while (sub != 8);
        }

    } while (op != 3); // el progrema deja de repetir hasta que se eliga salir 

    return 0;
}
