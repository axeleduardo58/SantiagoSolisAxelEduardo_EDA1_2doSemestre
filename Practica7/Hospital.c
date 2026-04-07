/*Práctica 7: Lista Ligada Circular.
Realizado por: Primero Reyes Monserrath, Santiago Solís Axel Eduardo, Ortiz Hernández Yesica, De la Cruz Flores Natalia.
Este archivo contiene las funciones necesarias para que el programa del sistema hospitalario funcione correctamente.
Incluye diferentes validaciones para evitar que el usuario ingrese datos incorrectos, así como funciones que permiten leer y verificar la información antes de guardarla.
Además, cuenta con las operaciones para agregar y visualizar los datos de hospitales, pacientes, doctores, trabajadores,
personal de intendencia, especialidades y equipos médicos.
*/

#include "Hospital.h"

/*------------------- VALIDACIONES ------------------*/
int soloLetras(char *t) {
    if (t[0] == '\0') //evita cadenas vacias
        return 0;
    for (int i = 0; t[i]; i++) { //recorre cada carecter del codigo
        if (t[i] == '\n') continue;  // Ignora el salto de linea
        if (!isalpha(t[i]) && t[i] != ' ') //verifica que sea un caracter una letra o espacio
            return 0;
    }
    return 1;
}

int soloNumeros(char *t) {
    if (t[0] == '\0') //evita cadenas vacias
        return 0;
    for (int i = 0; t[i]; i++) {
        if (!isdigit(t[i])) //verifica que la entrada sea un numero
            return 0;
    }
    return 1;
}

int nombreCorrecto(char *t) {
    int nuevaPalabra = 1;
    for (int i = 0; t[i]; i++) {
        if (t[i] == '\n')
            continue;
        if (t[i] == ' ')
            nuevaPalabra = 1; // variable que indica si empieza una nueva palabra
        else {
            if (nuevaPalabra) {
                if (!isupper(t[i])) // verifica que la entrada de datos sea correcta (iniciales con mayusculas)
                    return 0;
                nuevaPalabra = 0;
            }
        }
    }
    return 1;
}

int soloTextoLibre(char *t) {
    if (t[0] == '\0')
        return 0;
    for (int i = 0; t[i]; i++) {
        if (t[i] == '\n') continue;
        if (!isalnum(t[i]) && t[i] != ' ' && t[i] != '-' && t[i] != '_' //verifica la entrada de datos sea alfanumerico
                && t[i] != '/')
            return 0;
    }
    return 1;
}

/*---------------------- LECTURA DE DATOS -----------------*/
void leerTexto(char *mensaje, char *destino, int tam_destino) { //lee el texto del usuario y lo valida antes de guardarlo
    char buffer[200]; //buffer temporal para leer el texto
    while (1) { //se repite hasta que el usuario ingresee datos correctos
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
            printf("Error: solo se permite ingresar letras\n");
            continue;
        }
        if (!nombreCorrecto(buffer)) {
            printf("Error: cada nombre y apellidos deben iniciar con MAYUSCULAS\n");
            continue;
        }
        strncpy(destino, buffer, tam_destino - 1);
        destino[tam_destino - 1] = '\0';
        break;
    }
}

void leerTextoLibre(char *mensaje, char *destino, int tam_destino) {
    char buffer[200];
    while (1) {
        printf("%s", mensaje);
        if (!fgets(buffer, sizeof(buffer), stdin)) {
            printf("Error al leer\n");
            continue;
        }
        buffer[strcspn(buffer, "\n")] = 0; //Elimina salto de línea
        if (!soloTextoLibre(buffer)) {
            printf("Error: caracteres no válidos\n");
            continue;
        }
        strncpy(destino, buffer, tam_destino - 1);
        destino[tam_destino - 1] = '\0';
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
        num = atoi(buffer); //convierte texto a entero
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
        printf("\nHospital: %s\n", aux->nombre);
        printf("[N] siguente | [S] seleccionar\n");
        scanf(" %c", &op);
        getchar();
        if (op == 's' || op == 'S')
            return aux;
        if (op == 'n' || op == 'N')
            aux = aux->sig;
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
        printf("\nDoctor: %s\n", aux->nombre);
        printf("[N] siguiente | [S] seleccionar\n");
        scanf(" %c", &op);
        getchar();
        if (op == 's' || op == 'S')
            return aux;
        if (op == 'n' || op == 'N')
            aux = aux->sig;
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
        printf("\nEspecialidad: %s\n", aux->nombre);
        printf("[N] siguiente | [S] seleccionar\n");
        scanf(" %c", &op);
        getchar();
        if (op == 's' || op == 'S')
            return aux;
        if (op == 'n' || op == 'N')
            aux = aux->sig;
        else
            printf("Opcion invalida\n");
    }
}

nodoEquipo* seleccionarEquipo(listaEquipo *l) {
    if (!l->h) {
        printf("No hay Equipos\n");
        return NULL;
    }
    nodoEquipo *aux = l->h;
    char op;
    while (1) {
        printf("\nEquipo: %s\n", aux->nombre);
        printf("[N] siguiente | [S] seleccionar\n");
        scanf(" %c", &op);
        getchar();
        if (op == 's' || op == 'S')
            return aux;
        if (op == 'n' || op == 'N')
            aux = aux->sig;
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
    leerTexto("Nombre hospital: \n", nuevo->nombre, sizeof(nuevo->nombre)); //evita que no haya desbordamiento de memoria (sizeof)
    leerTexto("Direccion: \n", nuevo->direccion, sizeof(nuevo->direccion));
    if (l->h == NULL) {
        l->h = nuevo;
        nuevo->sig = nuevo; 
    } else {
        nodoHospital *aux = l->h;
        while (aux->sig != l->h)
            aux = aux->sig;
        aux->sig = nuevo;
        nuevo->sig = l->h;
    }
    printf("Hospital agregado\n");
}

void agregarPaciente(listaPaciente *p, listaDoctor *d, listaEspecialidad *e, listaHospital *h) {
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
    nuevo->edad = leerEnteroPositivo("Edad: \n");
    do {
        nuevo->num_paciente = leerEnteroPositivo("Numero de paciente: ");
        if (existePaciente(p, nuevo->num_paciente))
            printf("Error: ya existe un paciente con ese ID\n");
    } while (existePaciente(p, nuevo->num_paciente));

    nuevo->hospital = seleccionarHospital(h);
    nuevo->doctor = seleccionarDoctor(d);

    if (nuevo->doctor != NULL)
        nuevo->especialidad = nuevo->doctor->especialidad;
    else
        nuevo->especialidad = NULL;

    if (nuevo->especialidad != NULL)
        nuevo->especialidad->num_pacientes++;

    if (p->h == NULL) {
        p->h = nuevo;
        nuevo->sig = nuevo;
    } else {
        nodoPaciente *aux = p->h;
        while (aux->sig != p->h)
            aux = aux->sig;
        aux->sig = nuevo;
        nuevo->sig = p->h;
    }
    printf("Paciente agregado\n");
}

void agregarDoctor(listaDoctor *d, listaEspecialidad *e, listaTrabajador *t, listaEquipo *eq) {
    nodoDoctor *nuevoDoctor = malloc(sizeof(nodoDoctor));
    nodoTrabajador *nuevoTrabajador = malloc(sizeof(nodoTrabajador));
    if (!nuevoDoctor || !nuevoTrabajador) {
        printf("Error no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre del doctor: ", nuevoDoctor->nombre, sizeof(nuevoDoctor->nombre));
    nuevoDoctor->edad = leerEnteroPositivo("Edad: ");

    /* Manejo de especialidad */
    if (e->h == NULL) {
        printf("No existen especialidades\n");
        printf("Se creara una nueva\n");
        agregarEspecialidad(e, eq);
    }
    printf("\nSeleccione especialidad\n");
    nuevoDoctor->especialidad = seleccionarEspecialidad(e);
    if (nuevoDoctor->especialidad)
        nuevoDoctor->especialidad->num_doctores++;

    /* Crear trabajador */
    printf("\nDatos del trabajador\n");
    do {
        nuevoTrabajador->num_trabajador = leerEnteroPositivo("ID del trabajador: \n");
        if (existeTrabajador(t, nuevoTrabajador->num_trabajador))
            printf("Error: ya existe un trabajador con ese ID\n");
    } while (existeTrabajador(t, nuevoTrabajador->num_trabajador));

    nuevoTrabajador->sindicalizado = leerBinario("Sindicalizado (1=si / 0=no): ");
    strcpy(nuevoTrabajador->tipo, "Doctor");
    nuevoDoctor->trabajador = nuevoTrabajador;

    /* Insertar trabajador */
    if (t->h == NULL) {
        t->h = nuevoTrabajador;
        nuevoTrabajador->sig = nuevoTrabajador;
    } else {
        nodoTrabajador *aux = t->h;
        while (aux->sig != t->h)
            aux = aux->sig;
        aux->sig = nuevoTrabajador;
        nuevoTrabajador->sig = t->h;
    }

    /* Insertar doctor */
    if (d->h == NULL) {
        d->h = nuevoDoctor;
        nuevoDoctor->sig = nuevoDoctor;
    } else {
        nodoDoctor *aux = d->h;
        while (aux->sig != d->h)
            aux = aux->sig;
        aux->sig = nuevoDoctor;
        nuevoDoctor->sig = d->h;
    }
    printf("Doctor agregado\n");
}

void agregarEspecialidad(listaEspecialidad *l, listaEquipo *eq) {
    if (!eq->h) {
        printf("Debe existir al menos un equipo medico equipo medico\n");
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
    if (l->h == NULL) {
        l->h = nuevo;
        nuevo->sig = nuevo;
    } else {
        nodoEspecialidad *aux2 = l->h;
        while (aux2->sig != l->h)
            aux2 = aux2->sig;
        aux2->sig = nuevo;
        nuevo->sig = l->h;
    }
    printf("Especialidad agregada\n");
}

void agregarTrabajador(listaTrabajador *t) {
    nodoTrabajador *nuevo = malloc(sizeof(nodoTrabajador));
    if (!nuevo) {
        printf("Error: no se pudo reservar memoria\n");
        return;
    }
    do {
        nuevo->num_trabajador = leerEnteroPositivo("ID del trabajador: \n");
        if (existeTrabajador(t, nuevo->num_trabajador))
            printf("Error: ya existe un trabajador con ese ID\n");
    } while (existeTrabajador(t, nuevo->num_trabajador));

    nuevo->sindicalizado = leerBinario("Sindicalizado (1=si / 0=no): ");
    printf("Tipo de trabajador: \n");
    printf("1 Doctor\n");
    printf("2 Intendencia\n");
    int tipo;
    do {
        tipo = leerNumero("seleccionar el tipo de trabajador(1 Doctor / 2 Intendencia): ");
        if (tipo != 1 && tipo != 2)
            printf("Error: opción invalida\n");
    } while (tipo != 1 && tipo != 2);

    if (tipo == 1)
        strcpy(nuevo->tipo, "Doctor");
    else
        strcpy(nuevo->tipo, "Intendencia");

    if (t->h == NULL) {
        t->h = nuevo;
        nuevo->sig = nuevo;
    } else {
        nodoTrabajador *aux = t->h;
        while (aux->sig != t->h)
            aux = aux->sig;
        aux->sig = nuevo;
        nuevo->sig = t->h;
    }
    printf("Trabajador agregado\n");
}

void agregarIntendencia(listaIntendencia *i, listaTrabajador *t) {
    nodoIntendencia *nuevo = malloc(sizeof(nodoIntendencia));
    if (!nuevo) {
        printf("Error no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre del intendente: \n", nuevo->nombre, sizeof(nuevo->nombre));
    nuevo->edad = leerEnteroPositivo("Edad: \n");
    
    //Verificar si hay trabajadores de intendencia
    nodoTrabajador *aux = t->h;
    int existeInt = 0;
    if (!aux) {
        printf("No existen trabajadores registrados\n");
        nuevo->trabajador = NULL;
    } else {
        do {
            if (strcmp(aux->tipo, "Intendencia") == 0) { //Solo muestra trabajadores de intendencia
                existeInt = 1;
                break;
            }
            aux = aux->sig;
        } while (aux != t->h);

        if (!existeInt) {
            printf("No existen trabajadores de tipo intendencia\n");
            nuevo->trabajador = NULL;
        } else {
            aux = t->h;
            char op;
            while (1) {
                if (strcmp(aux->tipo, "Intendencia") == 0) { //Solo muestra trabajadores de intendencia
                    printf("\nTrabajador ID: %d\n", aux->num_trabajador);
                    printf("Sindicalizado: %d\n", aux->sindicalizado);
                    printf("[N] siguiente | [S] seleccionar\n");
                    scanf(" %c", &op);
                    getchar();
                    if (op == 's' || op == 'S') {
                        nuevo->trabajador = aux;
                        break;
                    }
                    else if (op == 'n' || op == 'N') {
                        aux = aux->sig;
                    } else {
                        printf("Opnción invalida");
                    }
                }
                aux = aux->sig;
            }
        }
    }
    if (i->h == NULL) {
        i->h = nuevo;
        nuevo->sig = nuevo;
    } else {
        nodoIntendencia *aux2 = i->h;
        while (aux2->sig != i->h)
            aux2 = aux2->sig;
        aux2->sig = nuevo;
        nuevo->sig = i->h;
    }
    printf("Intendencia agregada\n");
}

void agregarEquipo(listaEquipo *l) {
    nodoEquipo *nuevo = malloc(sizeof(nodoEquipo));
    if (!nuevo) {
        printf("Error no se pudo reservar memoria\n");
        return;
    }
    leerTexto("Nombre equipo: ", nuevo->nombre, sizeof(nuevo->nombre));
    leerTextoLibre("Marca: ", nuevo->marca, sizeof(nuevo->marca));
    leerTextoLibre("Modelo: ", nuevo->modelo, sizeof(nuevo->modelo));
    if (l->h == NULL) { // verifica si la lista esta vacia
        l->h = nuevo;
        nuevo->sig = nuevo; // el nodo se apunta a si mismo
    } else {
        nodoEquipo *aux = l->h;
        while (aux->sig != l->h) // busca el ultimo nodo de la lista
            aux = aux->sig; //avanza al siguiente nodo
        aux->sig = nuevo; // el ultimo nodo ahora apunta al nuevo nodo
        nuevo->sig = l->h;  // el nuevo nodo apunta al primer nodo
    }
    printf("Equipo medico agregado\n");
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
        printf("Numero de paciente: %d\n", aux->num_paciente);
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
