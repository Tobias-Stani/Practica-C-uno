#include <stdio.h>
#include <stdlib.h>

#define FILAS 2
#define COLUMNAS 2

void limpiarPantalla();
void cargarMatriz(int filas, int columnas, int matriz[filas][columnas]);
void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]);
int valorMaximo(int filas, int columnas, int matriz[filas][columnas]);

int main() {
    int opcion;
    int matriz[FILAS][COLUMNAS]; // Inicializar la matriz con las constantes definidas

    do {
        printf("Menu:\n");
        printf("1 - Cargar matriz\n");
        printf("2 - Mostrar matriz\n");
        printf("3 - Informar valor maximo de la matriz\n");
        printf("4 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                cargarMatriz(FILAS, COLUMNAS, matriz); // Pasar la matriz como argumento
                break;
            case 2:
                imprimirMatriz(FILAS, COLUMNAS, matriz); // Pasar la matriz como argumento
                break;
            case 3:
                printf("El valor máximo de la matriz es: %d\n", valorMaximo(FILAS, COLUMNAS, matriz));
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente nuevamente.\n");
        }

        if (opcion != 4) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            getchar(); // Esperar a que el usuario presione Enter
            limpiarPantalla();
        }
    } while(opcion != 4);

    return 0;
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void cargarMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz[i][j]);  // \t se usa para tabular
        }
        printf("\n");
    }
}

int valorMaximo(int filas, int columnas, int matriz[filas][columnas]) {
    int max = matriz[0][0]; // Suponer que el primer elemento es el máximo

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            if (matriz[i][j] > max) {
                max = matriz[i][j];
            }
        }
    }

    return max;
}
