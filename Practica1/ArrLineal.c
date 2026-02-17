//Ejercicio1_ Práctica 1: Arreglos Lineales 
//Santiago Solis Axel Eduardo, Ortíz Hernadez Yessica, Primero Reyes Monserrath

//ARREGLO LINEAL CON ENTEROS
//En este código se solicita al usuario el tamaño del arreglo y se especifica que se trabajará con valores enteros.Los datos ingresados se almacenan en el arreglo y, al finalizar la captura, se muestran en pantalla al final del programa.

#include<stdio.h>
int main() {
    //Se solicita el tamaño y se guardan números enteros
    int n;
    
    //Pedir tamaño del arreglo
    printf("¿Cuántos números quieres guardar? ");
    scanf("%d", &n);

    //arreglo lineal 
    int enteros[n];

    //Pedir valores al usuario
    for(int i=0; i<n; i++) {
        //Muestra qué número debe escribir el usuario.
         printf("ingresa el valor %d: ", i+1);
         scanf("%d", &enteros[i]);
     }    


//ARREGLO LINEAL CON FLOAT
//En este código se indica al usuario el tamaño del arreglo y que se trabajará con datos de tipo float. El programa solicita valores decimales, los guarda en el arreglo y finalmente los muestra en pantalla con dos cifras decimales al terminar la ejecución.

//Arreglo fijo de 17 posiciones con decimales
float flotantes[17];    

//Mostrar mensaje (de lo que se pide)
printf("Arreglo Lineal(float)\n");

//Llenar el arreglo 
for(int i=0; i<17; i++) {
    printf("Ingresa el valor flotante %d: ", i+1);
    scanf("%f", &flotantes[i]);
}


//ARREGLO LINEAL DE CARACTERES 
//En este código se le pide al usuario ingresar el tamaño del arreglo y se especifica que se trabajará con datos de tipo char y el arreglo es de minimo 7 datos y maximo 20. El programa solicita cada carácter uno por uno, los guarda en el arreglo correspondiente y, al finalizar la captura, muestra todos los caracteres almacenados en pantalla.

//Tamaño entre 7 y 20
int nChar;

//Se pide el tamaño del arreglo con un minimo y maximos de variables
printf("\nTamaño del arreglo de caracteres (7 a 20): ");
scanf("%d", &nChar);

//El arreglo de caracteres, guarda los datos ingresados
char caracteres[nChar];

//Llenamos el arreglo con el tipo de datos que se pide
for (int i=0; i<nChar; i++) {
    printf("Ingresa caracter %d: ", i+1);
    scanf(" %c", &caracteres[i]);
}

//Mostramos resultados de cada parte del código
    printf("\nARREGLO LINEAL CON ENTEROS\n");
    for (int i=0; i<n; i++) {
    printf("%d ", enteros[i]);
}

printf("\nARREGLO LINEAL CON FLOAT\n");
for (int i=0; i<17; i++) {
    printf("%.2f ", flotantes[i]);
}


printf("\nARREGLO LINEAL DE CARACTERES\n");
for (int i=0; i<nChar; i++) {
    printf("%c ",caracteres[i]);
}
return 0;
}
