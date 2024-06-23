#include <stdio.h>

void cargarMatriz(int filas, int columnas, int matriz[filas][columnas]);
void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]);

int main() {
    int filas, columnas;

    // Solicitar el tamaño de la matriz
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Definir la matriz
    int matriz[filas][columnas];

    // Cargar la matriz con datos del usuario
    cargarMatriz(filas, columnas, matriz);

    // Imprimir la matriz en forma de tabla
    printf("Matriz cargada:\n");
    imprimirMatriz(filas, columnas, matriz);

    return 0;
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
