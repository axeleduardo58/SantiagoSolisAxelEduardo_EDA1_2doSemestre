/*Práctica 8: Lista Doblemente Ligada y Lista Doblemente Circular.
Realizado por: Primero Reyes Monserrath, Ortiz Hernández Yesica, Santiago Solís Axel Eduardo, De la Cruz Flores Natalia.
Este archivo contiene las funciones necesarias para que el programa del sistema hospitalario funcione correctamente.
Incluye diferentes validaciones para evitar que el usuario ingrese datos incorrectos, así como funciones que permiten leer y verificar la información antes de guardarla.
Además, cuenta con las operaciones para agregar y visualizar los datos de hospitales, pacientes, doctores, trabajadores,
personal de intendencia, especialidades y equipos médicos.
*/

#include "Hospital.h"
#ifdef _WIN32 //para evitar errores en otros sistemas al copilar
#include <conio.h> //getch() (Solo Windows)
#endif

/*------------------- VALIDACIONES ------------------*/
int soloLetras(char *t) {
    if (t[0] == '\0') //evita cadenas vacias
        return 0;
    for (int i = 0; t[i]; i++) { //recorre cada carecter del codigo
        if (t[i] == '\n') continue;  // Ignora el salto de linea
        if (!isalpha(t[i]) && t[i] != ' ') //verifica que sea un caracter (letra o espacio)
            return 0;
    }
    return 1;
}

int soloNumeros(char *t) {
    if (t[0] == '\0') //evita cadenas vacias
        return 0;
    for (int i = 0; t[i]; i++) {
        if (!isdigit(t[i])) //verifica que la entrada sea un número
            return 0;
    }
    return 1;
}
int soloTextoLibre(char *t) {
    if (t[0] == '\0')
        return 0;
    for (int i = 0; t[i]; i++) {
        if (t[i] == '\n') continue;
        //verifica la entrada de datos pueda ser alfanumérico
        if (!isalnum(t[i]) && t[i] != ' ' && t[i] != '-' && t[i] != '_' 
            && t[i] != '/')
            return 0;
    }
    return 1;
}

/*------------------- UTILIDADES ------------------*/
void corregirNombre(char mensaje[]) {
    int i = 0;
    int j = 0;
    int espacio = 0;
    while (mensaje[i] == ' ')
        i++;
    while (mensaje[i] != '\0') {
        if (mensaje[i] == ' ') {
            if (espacio == 0) {
                mensaje[j] = ' ';
                j++;
                espacio = 1;
            }
        } else {
            mensaje[j] = mensaje[i];
            if (mensaje[j] >= 'A' && mensaje[j] <= 'Z')
                mensaje[j] += 32;
            j++;
            espacio = 0;
        }
        i++;
    }
    if (j > 0 && mensaje[j - 1] == ' ')
        j--;
    mensaje[j] = '\0';
    if (mensaje[0] >= 'a' && mensaje[0] <= 'z')
        mensaje[0] -= 32;
    for (int k = 1; mensaje[k] != '\0'; k++) {
        if (mensaje[k - 1] == ' ' && mensaje[k] >= 'a' && mensaje[k] <= 'z') {
            mensaje[k] -= 32;
        }
    }
}

char leerTecla() {
    #ifdef _WIN32
    return getch();
    #else
    char c;
    scanf(" %c", &c);
    return c;
    #endif
}
/*---------------------- LECTURA DE DATOS -----------------*/
void leerTexto(char *mensaje, char *destino, int tam) { //lee el texto del usuario y lo valida antes de guardarlo
    char buffer[200]; //buffer temporal para leer el texto
    while (1) { //se repite hasta que el usuario ingrese datos correctos
        printf("%s", mensaje);
        if (!fgets(buffer, sizeof(buffer), stdin)) { //lee texto
            printf("Error al leer\n"); 
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0; //Elimina salto de línea
        if (strlen(buffer) == 0) { //verifica que no este vacio
            printf("Error: no puede estar vacio\n");
            continue;
        }
        if (!soloLetras(buffer)) { //valida el texto
            printf("Error: solo se permiten letras y espacios\n");
            continue;
        }
        //corrección automática del formato del nombre
        corregirNombre(buffer);
        strncpy(destino, buffer, tam - 1); // Copia el contenido del buffer hacia el destino
        destino[tam - 1] = '\0'; // Garantiza que la cadena termine correctamente
        break;
    }
}

void leerTextoLibre(char *mensaje, char *destino, int tam) {
    char buffer[200];
    while (1) {
        printf("%s", mensaje);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error al leer\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0; //Elimina el salto de línea
        if(strlen(buffer) == 0) {
            printf("Error: no puede estar vacío\n");
            continue;
        }
        if (!soloTextoLibre(buffer)) {
            printf("Error: caracteres no válidos\n");
            continue;
        }
        strncpy(destino, buffer, tam - 1);
        destino[tam - 1] = '\0';
        break;
    }
}

int leerNumero(char *mensaje) { 
    char buffer[100];
    int num;
    while (1) {
        printf("%s", mensaje);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error al leer\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0;
        if (!soloNumeros(buffer)) {
            printf("Error: solo se permite ingresar números\n");
            continue;
        }
        num = strtol(buffer, NULL, 10); 
        return num;
    }
}

int leerEnteroPositivo(char *mensaje) {
    int num;
    do {
        num = leerNumero(mensaje);
        if (num <= 0)
            printf("Debe ser mayor que 0\n");
    } while (num <= 0);
    return num;
}

int leerBinario(char *mensaje) {
    int num;
    do {
        num = leerNumero(mensaje);
        if (num != 0 && num != 1)
            printf("solo 1 o 0\n");
    } while (num != 0 && num != 1);
    return num;
}

/*---------------------- INICIALIZAR LISTAS ----------------------*/
void inicializarHospital(listaHospital *l) { l->h = NULL; } 
void inicializarDoctor(listaDoctor *l) { l->h = NULL; }
void inicializarPaciente(listaPaciente *l) { l->h = NULL; }
void inicializarTrabajador(listaTrabajador *l) { l->h = NULL; }
void inicializarIntendencia(listaIntendencia *l) { l->h = NULL; }
void inicializarEspecialidad(listaEspecialidad *l) { l->h = NULL; }
void inicializarEquipo(listaEquipo *l) { l->h = NULL; }

/*---------------------- ID DUPLICADO ----------------------*/
int existePaciente(listaPaciente *l, int id) { //busca al paciente con ese ID y que no se repita
    if (!l->h) return 0; // verifica si la lista esta vacia
    nodoPaciente *aux = l->h; // empieza el primer nodo
    do {
        if (aux->num_paciente == id) //Compara el ID
            return 1;
        aux = aux->sig;
    } while (aux != l->h);
    return 0;
}

int existeTrabajador(listaTrabajador *l, int id) {
    if (!l->h) return 0; //si lista esta vacia
    nodoTrabajador *aux = l->h;
    do {
        if (aux->num_trabajador == id)
            return 1;
        aux = aux->sig;
    } while (aux != l->h);
    return 0;
}

/*---------------------- FUNCIONES DE SELECCION ----------------------*/
nodoHospital* seleccionarHospital(listaHospital *l) {  //recorre la lista y selecciona un elemento
    if (!l->h) {
        printf("No hay hospitales registrados\n");
        return NULL;
    }
    nodoHospital *aux = l->h;
    char op;
    while (1) {
        printf("\n------------ HOSPITAL --------------\n");
        printf("\nNombre: %s\n", aux->nombre);
        printf("\nDirección: %s\n", aux->direccion);
        printf("[S] siguiente | [A] anterior | [R] seleccionar\n");
        op = leerTecla();
        if (op == 'r' || op == 'R')
            return aux;
        else if (op == 's' || op == 'S')
            aux = aux->sig;
        else if (op == 'a' || op == 'A')
            aux = aux->ant;
        else
            printf("Opcion invalida\n");
    }
}

nodoPaciente* seleccionarPaciente(listaPaciente *l) { //recorre la lista y selecciona un elemento
    if (!l->h) {
        printf("No hay Pacientes\n");
        return NULL;
    }
    nodoPaciente *aux = l->h;
    char op;
    while (1) {
        printf("\n------------ PACIENTE --------------\n");
        printf("\nNombre: %s\n", aux->nombre);
        printf("Edad: %d\n", aux->edad);
        printf("\nID: %04d\n", aux->num_paciente);
        if(aux->doctor)
            printf("\ndoctor: %s\n", aux->doctor->nombre);
        if(aux->hospital)
            printf("\nHospital: %s\n", aux->hospital->nombre);
        printf("[S] siguiente | [A] anterior | [R] seleccionar\n");
        op = leerTecla();
        if (op == 'r' || op == 'R')
            return aux;
        else if (op == 's' || op == 'S')
            aux = aux->sig;
        else if (op == 'a' || op == 'A')
            aux = aux->ant;
        else
            printf("Opcion invalida\n");
    }
}

nodoTrabajador* seleccionarTrabajador(listaTrabajador *l) { //recorre la lista y selecciona un elemento
    if (!l->h) {
        printf("No hay Trabajadores Registrados\n");
        return NULL;
    }
    nodoTrabajador *aux = l->h;
    char op;
    while (1) {
        printf("\n------------ TRABAJADOR --------------\n");
        printf("\nID: %d\n", aux->num_trabajador);
        printf("Tipo: %s\n", aux->tipo);
        printf("Sindicalizado: %d\n", aux->sindicalizado);
        printf("[S] siguiente | [A] anterior | [R] seleccionar\n");
        op = leerTecla();
        if (op == 'r' || op == 'R')
            return aux;
        else if (op == 's' || op == 'S')
            aux = aux->sig;
        else if (op == 'a' || op == 'A')
            aux = aux->ant;
        else
            printf("Opcion invalida\n");
    }
}

nodoDoctor* seleccionarDoctor(listaDoctor *l) { //recorre la lista y selecciona un elemento
    if (!l->h) {
        printf("No hay doctores\n");
        return NULL;
    }
    nodoDoctor *aux = l->h;
    char op;
    while (1) {
        printf("\n------------ DOCTOR --------------\n");
        printf("\nNombre: %s\n", aux->nombre);
        printf("[S] siguiente | [A] anterior | [R] seleccionar\n");
        op = leerTecla();
        if (op == 'r' || op == 'R')
            return aux;
        else if (op == 's' || op == 'S')
            aux = aux->sig;
        else if (op == 'a' || op == 'A')
            aux = aux->ant;
        else
            printf("Opcion invalida\n");
    }
}

nodoEspecialidad* seleccionarEspecialidad(listaEspecialidad *l) {
    if (!l->h) {
        printf("No hay Especialidades\n");
        return NULL;
    }
    nodoEspecialidad *aux = l->h;
    char op;
    while (1) {
        printf("\n------------ ESPECIALIDAD --------------\n");
        printf("\nNombre de la especialidad: %s\n", aux->nombre);
        printf("Doctores: %d\n", aux->num_doctores);
        printf("Pacientes: %d\n", aux->num_pacientes);
        if(aux->equipo)
            printf("Equipo: %s\n", aux->equipo->nombre);
        printf("[S] siguiente | [A] anterior | [R] seleccionar\n");
        op = leerTecla();
        if (op == 'r' || op == 'R')
            return aux;
        else if (op == 's' || op == 'S')
            aux = aux->sig;
        else if (op == 'a' || op == 'A')
            aux = aux->ant;
        else
            printf("Opcion invalida\n");
    }
}

nodoEquipo* seleccionarEquipo(listaEquipo *l) {
    if (!l->h) {
        printf("No hay Equipos Médicos\n");
        return NULL;
    }
    nodoEquipo *aux = l->h;
    char op;
    while (1) {
        printf("\n------- EQUIPO MÉDICO ------\n");
        printf("\nNombre del equipo médico: %s\n", aux->nombre);
        printf("\nMarca: %s\n", aux->marca);
        printf("\nModelo: %s\n", aux->modelo);
        printf("[S] siguiente | [A] anterior | [R] seleccionar\n");
        op = leerTecla();
        if (op == 'r' || op == 'R')
            return aux;
        else if (op == 's' || op == 'S')
            aux = aux->sig;
        else if (op == 'a' || op == 'A')
            aux = aux->ant;
        else
            printf("Opcion invalida\n");
    }
}

/*------------------------ REGISTROS (CONTAR) --------------------------*/
int contarHospitales(listaHospital *l) {
    if (!l->h) return 0;
    int c = 0;
    nodoHospital *aux = l->h;
    do { c++; aux = aux->sig; } while (aux != l->h);
    return c;
}

int contarPacientes(listaPaciente *l) {
    if (!l->h) return 0;
    int c = 0;
    nodoPaciente *aux = l->h;
    do { c++; aux = aux->sig; } while (aux != l->h);
    return c;
}

int contarEspecialidades(listaEspecialidad *l) {
    if (!l->h) return 0;
    int c = 0;
    nodoEspecialidad *aux = l->h;
    do { c++; aux = aux->sig; } while (aux != l->h);
    return c;
}

int contarDoctores(listaDoctor *l) {
    if (!l->h) return 0;
    int c = 0;
    nodoDoctor *aux = l->h;
    do { c++; aux = aux->sig; } while (aux != l->h);
    return c;
}

int contarTrabajadores(listaTrabajador *l) {
    if (!l->h) return 0;
    int c = 0;
    nodoTrabajador *aux = l->h;
    do { c++; aux = aux->sig; } while (aux != l->h);
    return c;
}

int contarIntendencia(listaIntendencia *l) {
    if (!l->h) return 0;
    int c = 0;
    nodoIntendencia *aux = l->h;
    do { c++; aux = aux->sig; } while (aux != l->h);
    return c;
}

int contarEquipos(listaEquipo *l) {
    if (!l->h) return 0;
    int c = 0;
    nodoEquipo *aux = l->h;
    do { c++; aux = aux->sig; } while (aux != l->h);
    return c;
}

/*------------------------ FUNCIONES PARA AGREGAR -----------------------*/
void agregarHospital(listaHospital *l) {
    nodoHospital *nuevo = malloc(sizeof(nodoHospital)); // crea el nodo
    if (!nuevo) {
        printf("Error: no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre del hospital: \n", nuevo->nombre, sizeof(nuevo->nombre)); //evita que no haya desbordamiento de memoria (sizeof)
    leerTexto("Direccion: \n", nuevo->direccion, sizeof(nuevo->direccion));
    if (l->h == NULL) {
        l->h = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        nodoHospital *ultimo = l->h->ant; 
        ultimo->sig = nuevo;
        nuevo->ant = ultimo;
        nuevo->sig = l->h;
        l->h->ant = nuevo;
    }
    printf("Hospital agregado\n");
}

void agregarEquipo(listaEquipo *l) {
    nodoEquipo *nuevo = malloc(sizeof(nodoEquipo));
    if (!nuevo) {
        printf("Error: no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre del equipo: ", nuevo->nombre, sizeof(nuevo->nombre));
    leerTextoLibre("Marca: ", nuevo->marca, sizeof(nuevo->marca));
    leerTextoLibre("Modelo: ", nuevo->modelo, sizeof(nuevo->modelo));
    if (l->h == NULL) { // verifica si la lista esta vacia
        l->h = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo; 
    } else {
        nodoEquipo *ultimo = l->h->ant;
        ultimo->sig = nuevo; 
        nuevo->ant = ultimo;
        nuevo->sig = l->h;
        l->h->ant = nuevo;
    }
    printf("Equipo medico agregado\n");
}

void agregarEspecialidad(listaEspecialidad *l, listaEquipo *eq) {
    if (!eq->h) {
        printf("Debe existir al menos un equipo medico\n");
        return;
    }
    nodoEspecialidad *nuevo = malloc(sizeof(nodoEspecialidad));
    if (!nuevo) {
        printf("Erro: no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre especialidad: ", nuevo->nombre, sizeof(nuevo->nombre));
    nuevo->num_doctores = 0;
    nuevo->num_pacientes = 0;
    printf("Seleccione equipo medico\n");
    nuevo->equipo = seleccionarEquipo(eq);
    if (l->h == NULL) { // verifica si la lista esta vacia
        l->h = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo; 
    } else {
        nodoEspecialidad *ultimo = l->h->ant;
        ultimo->sig = nuevo; 
        nuevo->ant = ultimo;
        nuevo->sig = l->h;
        l->h->ant = nuevo;
    }
    printf("Especialidad agregada\n");
}

void agregarDoctor(listaDoctor *d, listaEspecialidad *e, listaTrabajador *t) {
    if (!e->h) {
        printf("Debe existir una especialidad\n");
        return;
    }
    nodoDoctor *nuevoDoctor = malloc(sizeof(nodoDoctor));
    nodoTrabajador *nuevoTrabajador = malloc(sizeof(nodoTrabajador));
    if (!nuevoDoctor || !nuevoTrabajador) {
        printf("Error no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre del doctor: ", nuevoDoctor->nombre, sizeof(nuevoDoctor->nombre));
    nuevoDoctor->edad = leerEnteroPositivo("Edad: ");
    printf("\nSeleccione especialidad\n");
    nuevoDoctor->especialidad = seleccionarEspecialidad(e);
    if (nuevoDoctor->especialidad)
        nuevoDoctor->especialidad->num_doctores++;
    int id;
    do {
        id = leerEnteroPositivo("ID trabajador (1000-1999): ");
            if (id < 1000 || id > 1999)
            printf("El ID debe estar entre 1000 y 1999\n");
            else if (existeTrabajador(t,id))
            printf("Ese ID ya existe\n");
    } while (id < 1000 || id > 1999 || existeTrabajador(t,id));  
    nuevoTrabajador->num_trabajador = id;
    nuevoTrabajador->sindicalizado = leerBinario("Sindicalizado (1=si / 0=no): "); 
    strcpy(nuevoTrabajador->tipo, "Doctor");
    nuevoDoctor->trabajador = nuevoTrabajador;
    /* Insertar trabajador */
    if (!t->h) {
        t->h = nuevoTrabajador;
        nuevoTrabajador->sig = nuevoTrabajador;
        nuevoTrabajador->ant = nuevoTrabajador;
    } else {
        nodoTrabajador *ultimo = t->h->ant;
        ultimo->sig = nuevoTrabajador;
        nuevoTrabajador->ant = ultimo;
         nuevoTrabajador->sig = t->h;
        t->h->ant = nuevoTrabajador;
    }
    /* Insertar doctor */
    if (!d->h) {
        d->h = nuevoDoctor;
        nuevoDoctor->sig = nuevoDoctor;
        nuevoDoctor->ant = nuevoDoctor;
    } else {
        nodoDoctor *ultimo = d->h->ant;
        ultimo->sig = nuevoDoctor;
        nuevoDoctor->ant = ultimo;
        nuevoDoctor->sig = d->h;
        d->h->ant = nuevoDoctor;
    }
    printf("Doctor agregado\n");
}

void agregarIntendencia(listaIntendencia *i, listaTrabajador *t) {
    nodoIntendencia *nuevo = malloc(sizeof(nodoIntendencia));
    nodoTrabajador *nuevoTrabajador = malloc(sizeof(nodoTrabajador));
    if (!nuevo || !nuevoTrabajador) {
        printf("Error no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre del intendente: ", nuevo->nombre, sizeof(nuevo->nombre));
    nuevo->edad = leerEnteroPositivo("Edad: \n");
    int id;
    do {
        id = leerEnteroPositivo("ID trabajador (2000-2999): ");
            if (id < 2000 || id > 2999)
            printf("El ID debe estar entre 2000 y 2999\n");
            else if (existeTrabajador(t,id))
            printf("Ese ID ya existe\n");
    } while (id < 2000 || id > 2999 || existeTrabajador(t,id));  
    nuevoTrabajador->num_trabajador = id;
    nuevoTrabajador->sindicalizado = leerBinario("Sindicalizado (1=si / 0=no): "); 
    strcpy(nuevoTrabajador->tipo, "Intendencia");
    nuevo->trabajador = nuevoTrabajador;
    /* Insertar trabajador */
    if (!t->h) {
        t->h = nuevoTrabajador;
        nuevoTrabajador->sig = nuevoTrabajador;
        nuevoTrabajador->ant = nuevoTrabajador;
    } else {
        nodoTrabajador *ultimo = t->h->ant;
        ultimo->sig = nuevoTrabajador;
        nuevoTrabajador->ant = ultimo;
        nuevoTrabajador->sig = t->h;
        t->h->ant = nuevoTrabajador;
    }
    /* Insertar doctor */
    if (!i->h) {
        i->h = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        nodoIntendencia *ultimo = i->h->ant;
        ultimo->sig = nuevo;
        nuevo->ant = ultimo;
        nuevo->sig = i->h;
        i->h->ant = nuevo;
    }
    printf("Intendencia agregada\n");
}

void agregarPaciente(listaPaciente *p, listaDoctor *d, listaHospital *h) {
    if (!h->h) {
        printf("Debe existir un hospital\n");
        return;
    }
    if (!d->h) {
        printf("Debe existir un doctor\n");
        return;
    }
    nodoPaciente *nuevo = malloc(sizeof(nodoPaciente));
    if (!nuevo) {
        printf("Error: no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre del paciente: ", nuevo->nombre, sizeof(nuevo->nombre));
    nuevo->edad = leerEnteroPositivo("Edad: ");
    do {
        nuevo->num_paciente = leerEnteroPositivo("Numero de paciente (0001 y 0999): ");
        if(nuevo->num_paciente < 1 || nuevo->num_paciente > 999) {
            printf("El numero debe estar entre 0001 y 0999\n");
            continue;
        }
        if (existePaciente(p, nuevo->num_paciente)) {
            printf("Error: ya existe un paciente con ese ID\n");
        }
    } while (nuevo->num_paciente < 1 || 
             nuevo->num_paciente > 999 || 
             existePaciente(p, nuevo->num_paciente));
    printf("\nSeleccione hospital\n");
    nuevo->hospital = seleccionarHospital(h);
    printf("\nSeleccione doctor\n");
    nuevo->doctor = seleccionarDoctor(d);
    if (nuevo->doctor)
        nuevo->especialidad = nuevo->doctor->especialidad;
    else
        nuevo->especialidad = NULL;
    if (nuevo->especialidad )
        nuevo->especialidad->num_pacientes++;
    if (p->h == NULL) {
        p->h = nuevo;
        nuevo->sig = nuevo;
        nuevo->ant = nuevo;
    } else {
        nodoPaciente *ultimo = p->h->ant;
        ultimo->sig = nuevo; 
        nuevo->ant = ultimo;
        nuevo->sig = p->h;
        p->h->ant = nuevo;    
    }
    printf("Paciente agregado\n");
}
/*------------------------ FUNCIONES PARA MOSTRAR -----------------------*/
void mostrarHospital(listaHospital *l) {
    if (!l->h) {
        printf("Lista vacia\n");
        return;
    }
    nodoHospital *aux = l->h;
    char op;
    do {
        printf("\nHospital: %s\n", aux->nombre);
        printf("\nDirección: %s\n", aux->direccion);
        printf("\nN siguiente | S salir\n");
        scanf(" %c", &op);
        getchar();
        if (op == 'n' || op == 'N')
            aux = aux->sig;
    } while (op != 's' && op != 'S');
}

void mostrarPaciente(listaPaciente *l) {
    if (!l->h) {  // verificamos si la lista esta vacia
        printf("Lista vacia\n");
        return;
    }
    nodoPaciente *aux = l->h;
    char op;
    do {
        printf("\nPaciente: %s\n", aux->nombre);
        printf("Edad: %d\n", aux->edad);
        printf("Numero de paciente: %04d\n", aux->num_paciente);
        if (aux->doctor) // verifica que haya doctor
            printf("Doctor: %s\n", aux->doctor->nombre);
        if (aux->hospital) // verifica que haya hospital
            printf("Hospital: %s\n", aux->hospital->nombre);
        printf("\nN siguiente | S salir\n");
        scanf(" %c", &op);
        getchar(); // elimina el enter que queda en el buffer
        if (op == 'n' || op == 'N')
            aux = aux->sig;
    } while (op != 's' && op != 'S');
}

void mostrarDoctor(listaDoctor *l) {
    if (!l->h) {
        printf("Lista vacia\n");
        return;
    }
    nodoDoctor *aux = l->h;
    char op;
    do {
        printf("\nDoctor: %s\n", aux->nombre);
        printf("Edad: %d\n", aux->edad);
        if (aux->especialidad)
            printf("Especialidad: %s\n", aux->especialidad->nombre);
        else
            printf("Especialidad: No asignada\n");
        printf("\nN siguiente | S salir\n");
        scanf(" %c", &op);
        getchar();
        if (op == 'n' || op == 'N')
            aux = aux->sig;
    } while (op != 's' && op != 'S');
}

void mostrarTrabajador(listaTrabajador *l) {
    if (!l->h) {
        printf("Lista vacia\n");
        return;
    }
    nodoTrabajador *aux = l->h;
    char op;
    do {
        printf("\nID del Trabajador: %d\n", aux->num_trabajador);
        printf("Sindicalizado: %d\n", aux->sindicalizado);
        printf("Tipo: %s\n", aux->tipo);
        printf("\nN siguiente | S salir\n");
        scanf(" %c", &op);
        getchar();
        if (op == 'n' || op == 'N')
            aux = aux->sig;
    } while (op != 's' && op != 'S');
}

void mostrarIntendencia(listaIntendencia *l) {
    if (!l->h) {
        printf("Lista vacia\n");
        return;
    }
    nodoIntendencia *aux = l->h;
    char op;
    do {
        printf("\nIntendencia : %s\n", aux->nombre);
        printf("Edad: %d\n", aux->edad);
        /*Mostrar datos del trabajador*/
        if (aux->trabajador) {
            printf("ID del trabajador: %d\n", aux->trabajador->num_trabajador);
            printf("Sindicalizado: %d\n", aux->trabajador->sindicalizado);
            printf("Tipo: %s\n", aux->trabajador->tipo);
        }
        printf("\nN siguiente | S salir\n");
        scanf(" %c", &op);
        getchar();
        if (op == 'n' || op == 'N')
            aux = aux->sig;
    } while (op != 's' && op != 'S');
}

void mostrarEspecialidad(listaEspecialidad *l) {
    if (!l->h) {
        printf("Lista vacia\n");
        return;
    }
    nodoEspecialidad *aux = l->h;
    char op;
    do {
        printf("Especialidad: %s\n", aux->nombre);
        printf("\nDoctores: %d\n", aux->num_doctores);
        printf("Pacientes: %d\n", aux->num_pacientes);
        if (aux->equipo)
            printf("Equipo: %s\n", aux->equipo->nombre);
        printf("\nN siguiente | S salir\n");
        scanf(" %c", &op);
        getchar();
        if (op == 'n' || op == 'N')
            aux = aux->sig;
    } while (op != 's' && op != 'S');
}

void mostrarEquipo(listaEquipo *l) {
    if (!l->h) {
        printf("Lista vacia\n");
        return;
    }
    nodoEquipo *aux = l->h;
    char op;
    do {
        printf("Equipo: %s\n", aux->nombre);
        printf("\nMarca: %s\n", aux->marca);
        printf("Modelo: %s\n", aux->modelo);
        printf("\nN siguiente | S salir\n");
        scanf(" %c", &op);
        getchar();
        if (op == 'n' || op == 'N')
            aux = aux->sig;
    } while (op != 's' && op != 'S');
}
