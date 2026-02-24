#include <stdio.h>

/* declaramos las Funciones */

void suma(double a, double b, double *resultado){
    *resultado = a + b;
}

void resta(double a, double b, double *resultado){
    *resultado = a - b;
}

void multiplicacion(double a, double b, double *resultado){
    *resultado = a * b;
}

void division(double a, double b, double *resultado){
    if(b != 0){
        *resultado = a / b;
    } else {
        printf("Error: No se puede dividir entre cero.\n");
        *resultado = 0;
    }
}

void modulo(int a, int b, int *resultado){
    if(b != 0){
        *resultado = a % b;
    } else {
        printf("Error: No se puede sacar modulo entre cero.\n");
        *resultado = 0;
    }
}

void divisionEntera(int a, int b, int *resultado){
    if(b != 0){
        *resultado = a / b;
    } else {
        printf("Error: No se puede dividir entre cero.\n");
        *resultado = 0;
    }
}



int main(){

    char opcion;

    do{

        printf("\n----- CALCULADORA -----\n");
        printf("a) Suma\n");
        printf("b) Resta\n");
        printf("c) Multiplicacion\n");
        printf("d) Division\n");
        printf("e) Modulo\n");
        printf("f) Division Entera\n");
        printf("g) Salir\n");
        printf("Elige una opcion: ");
        scanf(" %c", &opcion);

        switch(opcion){

            case 'a': case 'A':{
                double num1, num2, resultado;

                printf("Ingresa el primer numero: ");
                while(scanf("%lf", &num1) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el primer numero nuevamente: ");
                    scanf("%*s");
                }

                printf("Ingresa el segundo numero: ");
                while(scanf("%lf", &num2) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el segundo numero nuevamente: ");
                    scanf("%*s");
                }

                suma(num1, num2, &resultado);
                printf("Resultado: %.2lf\n", resultado);
                break;
            }

            case 'b': case 'B':{
                double num1, num2, resultado;

                printf("Ingresa el primer numero: ");
                while(scanf("%lf", &num1) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el primer numero nuevamente: ");
                    scanf("%*s");
                }

                printf("Ingresa el segundo numero: ");
                while(scanf("%lf", &num2) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el segundo numero nuevamente: ");
                    scanf("%*s");
                }

                resta(num1, num2, &resultado);
                printf("Resultado: %.2lf\n", resultado);
                break;
            }

            case 'c': case 'C':{
                double num1, num2, resultado;

                printf("Ingresa el primer numero: ");
                while(scanf("%lf", &num1) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el primer numero nuevamente: ");
                    scanf("%*s");
                }

                printf("Ingresa el segundo numero: ");
                while(scanf("%lf", &num2) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el segundo numero nuevamente: ");
                    scanf("%*s"); // elimina lo que el usuario haya ingresado en casi de que no fuera un numero
                }

                multiplicacion(num1, num2, &resultado);
                printf("Resultado: %.2lf\n", resultado);
                break;
            }

            case 'd': case 'D':{
                double num1, num2, resultado;

                printf("Ingresa el primer numero: ");
                while(scanf("%lf", &num1) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el primer numero nuevamente: ");
                    scanf("%*s");
                }

                printf("Ingresa el segundo numero: ");
                while(scanf("%lf", &num2) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el segundo numero nuevamente: ");
                    scanf("%*s");
                }

                division(num1, num2, &resultado);
                printf("Resultado: %.2lf\n", resultado);
                break;
            }

            case 'e': case 'E':{
                int num1, num2, resultado;

                printf("Ingresa el primer numero entero: ");
                while(scanf("%d", &num1) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el primer numero nuevamente: ");
                    scanf("%*s");
                }

                printf("Ingresa el segundo numero entero: ");
                while(scanf("%d", &num2) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el segundo numero nuevamente: ");
                    scanf("%*s");
                }

                modulo(num1, num2, &resultado);
                printf("Resultado: %d\n", resultado);
                break;
            }

            case 'f': case 'F':{
                int num1, num2, resultado;

                printf("Ingresa el primer numero entero: ");
                while(scanf("%d", &num1) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el primer numero nuevamente: ");
                    scanf("%*s");
                }

                printf("Ingresa el segundo numero entero: ");
                while(scanf("%d", &num2) != 1){
                    printf("Solo se permiten numeros en las operaciones.\n");
                    printf("Ingresa el segundo numero nuevamente: ");
                    scanf("%*s");
                }

                divisionEntera(num1, num2, &resultado);
                printf("Resultado: %d\n", resultado);
                break;
            }

            case 'g': case 'G':
                printf("Salida de la calculadora\n");
                break;

            default:
                printf("Opcion no valida (seleccione una de las opciones del menu)\n");
                break;
        }

    }while(opcion != 'g' && opcion != 'G');

    return 0;
}