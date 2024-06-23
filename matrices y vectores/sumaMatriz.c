//sumarDosMatrices

#include <stdio.h>

void cargarMatriz(int filas, int columnas, int matriz[filas][columnas],int matriz2[filas][columnas]);
void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas],int matriz2[filas][columnas]);
void sumarMatriz(int filas, int columnas, int matriz[filas][columnas],int matriz2[filas][columnas]);

int main() {
    int filas, columnas;

    // Solicitar el tamaño de la matriz
    printf("Ingrese el número de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el número de columnas: ");
    scanf("%d", &columnas);

    // Definir la matriz
    int matriz[filas][columnas];
    int matriz2[filas][columnas];

    // Cargar la matriz con datos del usuario
    cargarMatriz(filas, columnas, matriz, matriz2);

    // Imprimir la matriz en forma de tabla
    printf("Matriz cargada:\n");
    imprimirMatriz(filas, columnas, matriz, matriz2);

    printf("La suma de la matriz es: ");
    sumarMatriz(filas, columnas, matriz, matriz2);

    return 0;
}

void cargarMatriz(int filas, int columnas, int matriz[filas][columnas], int matriz2[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el elemento [%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

//cargar matriz 2
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("Ingrese el elemento de la 2da matriz [%d][%d]: ", i, j);
            scanf("%d", &matriz2[i][j]);
        }
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas],int matriz2[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz[i][j]);  // \t se usa para tabular
        }
        printf("\n");
    }

        printf("\n");

    //matriz 2

    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz2[i][j]);  // \t se usa para tabular
        }
        printf("\n");
    }
}


void sumarMatriz(int filas, int columnas, int matriz[filas][columnas],int matriz2[filas][columnas]){
    int i, j, sum[filas][columnas];

    // Sumar las dos matrices
    for(i = 0; i < filas; i++) {
        for(j = 0; j < columnas; j++) {
            sum[i][j] = matriz[i][j] + matriz2[i][j];
        }
    }

    // Imprimir la suma de las matrices en forma de tabla
    printf("La suma de las matrices es:\n");
    for(i = 0; i < filas; i++) {
        for(j = 0; j < columnas; j++) {
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
}
