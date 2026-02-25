/*El programan trata de recabar las 7 calificaciones de 10 alumnos y con esto podemos sacar 
la media y el promedio tanto por alumno individualmente como de foema grupal*/

// Creado por: Santiago Solis Axel Eduardo 


#include <stdio.h>

// esta parte de codigo se encarga de de llenar el apartado de las calificaciones de los estudiantes 
void llenarcali(float calificaciones[10][7]) {

    int i, j;

    for(i = 0; i < 10; i++) {

        printf("\nIngrese las 7 calificaciones del alumno %d\n", i + 1);

        for(j = 0; j < 7; j++) {

            printf("Calificacion %d: ", j + 1);

            // Esta parte se encarga de validar que el usuario ingrese un numero y no un caracter si no mandar un error
            while(scanf("%f", &calificaciones[i][j]) != 1) {
                printf("error ingrese un numero valido: ");
                scanf("%*s");
            }

            //Este bloque de codigo se encarga de validar que la calificacion sea de 0 a 1o si no mansara un error
            while(calificaciones[i][j] < 0 || calificaciones[i][j] > 10) {
                printf("Error. Ingrese una calificacion entre 0 y 10: ");
                scanf("%f", &calificaciones[i][j]);
            }
        }
    }
}

// Este bloque de codigo se encarga de calcular el promedio y media del alumno 
void PromAlumno(float calificaciones[10][7], float promedioAlumno[10]) {

    int i, j;
    float suma;

    for(i = 0; i < 10; i++) {

        suma = 0;

        for(j = 0; j < 7; j++) {
            suma = suma + calificaciones[i][j];
        }

        promedioAlumno[i] = suma / 7;
    }
}

// Este bloque de codigo se encarga de calcular el promedio y media del alumno 
void PromGrupo(float promedioAlumno[10], float *promedioGrupo) {

    int i;
    float suma = 0;

    for(i = 0; i < 10; i++) {
        suma = suma + promedioAlumno[i];
    }

    *promedioGrupo = suma / 10;
}

// y por utimo este se encarga de mostrar los resultados obtenidos 
void resultados(float promedioAlumno[10], float promedioGrupo) {

    int i;

    printf("\n===== RESULTADOS =====\n");

    for(i = 0; i < 10; i++) {
        printf("Media del alumno %d: %.2f\n", i + 1, promedioAlumno[i]);
        printf("Promedio del alumno %d: %.2f\n\n", i + 1, promedioAlumno[i]);
    }

    printf("Media del grupo: %.2f\n", promedioGrupo);
    printf("Promedio del grupo: %.2f\n", promedioGrupo);
}

// dentro del main ya solo se mandan a llamar las funciones que se declararon con anterioridad 
int main() {

    float calificaciones[10][7];
    float promedioAlumno[10];
    float promedioGrupo;

    llenarcali(calificaciones);
    PromAlumno(calificaciones, promedioAlumno);
    PromGrupo(promedioAlumno, &promedioGrupo);
    resultados(promedioAlumno, promedioGrupo);

    return 0;
}