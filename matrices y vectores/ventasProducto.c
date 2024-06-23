//matriz[FILAS][COLUMNAS]

#include <stdio.h>

#define PRODUCTO 2
#define DIAS 2

// Prototipos de las funciones
void cargarProductos(int ventas[PRODUCTO][DIAS]);
void mostrarProductos(int ventas[PRODUCTO][DIAS]);
void mostrarRanking(int ventas[PRODUCTO][DIAS]);

int main() {
    int ventas[PRODUCTO][DIAS] = {0};

    cargarProductos(ventas);
    mostrarProductos(ventas);
    mostrarRanking(ventas);

    return 0;
}

void cargarProductos(int ventas[PRODUCTO][DIAS]) {
    for (int i = 0; i < PRODUCTO; i++) {
        for (int j = 0; j < DIAS; j++) {
            printf("Ingrese las ventas para Producto %d, Dia %d: ", i + 1, j + 1);
            scanf("%d", &ventas[i][j]);
        }
    }
}

void mostrarProductos(int ventas[PRODUCTO][DIAS]) {
    printf("\nVentas de Productos:\n");
    printf("          ");
    for (int j = 0; j < DIAS; j++) {
        printf("Dia %d -\t", j + 1);
    }
    printf("Total Ventas\n");

    for (int i = 0; i < PRODUCTO; i++) {
        int totalVentas = 0;
        printf("Producto %d\t", i + 1);
        for (int j = 0; j < DIAS; j++) {
            printf("%d\t", ventas[i][j]);
            totalVentas += ventas[i][j];
        }
        printf("%d\n", totalVentas);
    }
}

void mostrarRanking(int ventas[PRODUCTO][DIAS]) {
    int totalVentas[PRODUCTO] = {0};
    int maxVentas = 0;
    int productoMax = 0;

    for (int i = 0; i < PRODUCTO; i++) {
        for (int j = 0; j < DIAS; j++) {
            totalVentas[i] += ventas[i][j];
        }
        if (totalVentas[i] > maxVentas) {
            maxVentas = totalVentas[i];
            productoMax = i;
        }
    }

    printf("\nRanking de productos por cantidad de ventas:\n");
    printf("Producto %d con %d ventas\n", productoMax + 1, maxVentas);
}