#include <stdio.h>
#include <stdbool.h>
#include <time.h> // Librería necesaria para medir el tiempo

// Podemos cambiar N para ver cómo aumenta el tiempo de ejecución
#define N 4 

void imprimirTablero(int tablero[N][N]) {
    int i, j;
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++)
            printf(" %s ", tablero[i][j] ? "R" : ".");
        printf("\n");
    }
}

bool esSeguro(int tablero[N][N], int fila, int col) {
    int i, j;
    // Verifica la fila hacia la izquierda
    for (i = 0; i < col; i++)
        if (tablero[fila][i]) return false;
    
    // Verifica diagonal superior izquierda
    for (i = fila, j = col; i >= 0 && j >= 0; i--, j--)
        if (tablero[i][j]) return false;
    
    // Verifica diagonal inferior izquierda
    for (i = fila, j = col; j >= 0 && i < N; i++, j--)
        if (tablero[i][j]) return false;
    
    return true;
}

bool resolverReinas(int tablero[N][N], int col) {
    int i;
    if (col >= N) return true; 

    for (i = 0; i < N; i++) {
        if (esSeguro(tablero, i, col)) {
            tablero[i][col] = 1; 
            if (resolverReinas(tablero, col + 1)) return true;
            tablero[i][col] = 0; // BACKTRACK
        }
    }
    return false;
}

int main() {
    // Declaración de variables para tiempo
    clock_t inicio, fin;
    double tiempo_total;
    int tablero[N][N] = {0};

    printf("Resolviendo para un tablero de %dx%d...\n", N, N);

    // Captura el tiempo inicial
    inicio = clock();

    if (resolverReinas(tablero, 0)) {
        // Captura el tiempo final antes de imprimir (para no medir el tiempo del printf)
        fin = clock();
        imprimirTablero(tablero);
    } else {
        fin = clock();
        printf("No hay solucion\n");
    }

    // Calcula la diferencia
    tiempo_total = (double)(fin - inicio) / CLOCKS_PER_SEC;

    printf("Tiempo de ejecucion: %f segundos\n", tiempo_total);

    return 0;
}
