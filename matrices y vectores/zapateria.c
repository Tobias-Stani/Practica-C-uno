#include <stdio.h>
#include <stdlib.h>

#define FILAS 2
#define COLUMNAS 4

void limpiarPantalla();
void cargarMatriz(int filas, int columnas, int matriz[filas][columnas]);
void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]);
void mostrarFacturacionPorZona(int filas, int columnas, int matriz[filas][columnas]);
void mostrarVentasYFacturacionTotal(int filas, int columnas, int matriz[filas][columnas]);

int main() {
    int opcion;
    int matriz[FILAS][COLUMNAS]; // Inicializar la matriz con las constantes definidas

    do {
        printf("Menu:\n");
        printf("1 - Cargar ventas\n");
        printf("2 - Mostrar matriz\n");
        printf("3 - Mostrar facturación por zona\n");
        printf("4 - Mostrar ventas totales y facturación total\n");
        printf("5 - Salir\n");
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
                mostrarFacturacionPorZona(FILAS, COLUMNAS, matriz); // Mostrar facturación por zona
                break;
            case 4:
                mostrarVentasYFacturacionTotal(FILAS, COLUMNAS, matriz); // Mostrar ventas totales y facturación total
                break;
            case 5:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente nuevamente.\n");
        }

        if (opcion != 5) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            getchar(); // Esperar a que el usuario presione Enter
            limpiarPantalla();
        }
    } while(opcion != 5);

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
        printf("Cargando datos para la venta %d:\n", i + 1);

        printf("Ingrese el importe de la venta: ");
        scanf("%d", &matriz[i][0]);

        printf("Ingrese el código del producto: ");
        scanf("%d", &matriz[i][1]);

        printf("Ingrese la zona: ");
        scanf("%d", &matriz[i][2]);

        printf("Ingrese el día de la venta: ");
        scanf("%d", &matriz[i][3]);
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Matriz de ventas:\n");
    printf("Importe\tCodigo\tZona\tDia\n");
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void mostrarFacturacionPorZona(int filas, int columnas, int matriz[filas][columnas]) {
    // Definir un rango arbitrariamente grande para las zonas
    int max_zona = 10;
    int totalPorZona[max_zona];
    
    // Inicializar el arreglo totalPorZona
    for (int i = 0; i < max_zona; i++) {
        totalPorZona[i] = 0;
    }

    // Calcular la facturación total por zona
    for (int i = 0; i < filas; i++) {
        int zona = matriz[i][2];
        if (zona >= 0 && zona < max_zona) {
            totalPorZona[zona] += matriz[i][0];
        } else {
            printf("Zona fuera de rango: %d\n", zona);
        }
    }

    // Mostrar la facturación total por zona
    printf("Facturación por zona:\n");
    printf("Zona\tTotal Facturación\n");
    for (int i = 0; i < max_zona; i++) {
        if (totalPorZona[i] != 0) {
            printf("%d\t%d\n", i, totalPorZona[i]);
        }
    }
}

void mostrarVentasYFacturacionTotal(int filas, int columnas, int matriz[filas][columnas]) {
    int totalVentas = 0;
    int totalFacturacion = 0;

    for (int i = 0; i < filas; i++) {
        totalVentas++;
        totalFacturacion += matriz[i][0];
    }

    printf("Total de ventas: %d\n", totalVentas);
    printf("Facturación total: %d\n", totalFacturacion);
}
