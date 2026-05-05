#include <stdio.h>
#include <string.h>
#include <time.h>   // Libreria para clock_t y clock()

void intercambiar(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}

void permutar(char *a, int l, int r) {
    int i;
    if (l == r) {
        // En una prueba de rendimiento real, podrias comentar el printf
        // para medir solo el calculo de las permutaciones.
        printf("%s\n", a); 
    } else {
        for (i = l; i <= r; i++) {
            intercambiar((a + l), (a + i));
            permutar(a, l + 1, r);
            intercambiar((a + l), (a + i)); // BACKTRACK
        }
    }
}

int main() {
    char str[] = "ABC";
    int n = strlen(str);
    
    // Variables para medir tiempo
    clock_t inicio, fin;
    double tiempo_total;

    printf("Generando permutaciones para: %s\n", str);
   
    // Iniciar medicion
    inicio = clock();

    permutar(str, 0, n - 1);

    // Finalizar medicion
    fin = clock();

    // Calcular diferencia
    tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;

   
    printf("Tiempo de ejecucion: %f segundos\n", tiempo_total);
    
    return 0;
}
