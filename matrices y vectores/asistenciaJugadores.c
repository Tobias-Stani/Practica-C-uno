#include <stdio.h>
#include <stdlib.h>

#define FILAS 3
#define COLUMNAS 3 // Cambiado a 3 columnas para acomodar jugador, asistencias y goles

void limpiarPantalla();
void cargarMatriz(int filas, int columnas, int matriz[filas][columnas]);
void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]);
int valorMaximo(int filas, int columnas, int matriz[filas][columnas]);

int main() {
    int opcion;
    int matriz[FILAS][COLUMNAS]; // Inicializar la matriz con las constantes definidas

    do {
        printf("Menu:\n");
        printf("1 - Cargar\n");
        printf("2 - Mostrar matriz\n");
        printf("3 - Informar valor maximo de la matriz\n");
        printf("4 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                cargarMatriz(FILAS, COLUMNAS, matriz);
                break;
            case 2:
                imprimirMatriz(FILAS, COLUMNAS, matriz); 
                break;
            case 3:
                printf("El valor máximo de asistencias en la matriz es: %d\n", valorMaximo(FILAS, COLUMNAS, matriz));
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
        printf("Ingrese el numero del jugador: ");
        scanf("%d", &matriz[i][0]);

        printf("Ingrese las asistencias: ");
        scanf("%d", &matriz[i][1]);

        printf("Ingrese la cantidad de goles: ");
        scanf("%d", &matriz[i][2]);
        
        while (getchar() != '\n'); // Limpiar el buffer de entrada
    }
}

void imprimirMatriz(int filas, int columnas, int matriz[filas][columnas]) {
    printf("Jugador\tAsistencias\tGoles\n");

    for (int i = 0; i < filas; i++) {
        printf("%d\t%d\t\t%d\n", matriz[i][0], matriz[i][1], matriz[i][2]);
    }
}

int valorMaximo(int filas, int columnas, int matriz[filas][columnas]) {
    int max = matriz[0][1]; // Suponer que el primer elemento es el máximo
    int maxCam = matriz[0][0];
    int sumaAsistencias = 0; // Para almacenar la suma de las asistencias
    int sumaGoles = 0;

    printf("El jugador que más asistencias realizó hizo: %d\n", max);

    for (int i = 0; i < filas; i++) {
        if (matriz[i][1] > max) {
            max = matriz[i][1];
        }
        sumaAsistencias += matriz[i][1]; // Sumar las asistencias
        sumaGoles += matriz[i][2]; // Sumar los goles (asumiendo que los goles están en la tercera columna)
    }

    for (int i = 0; i < filas; i++) {
        if (matriz[i][0] > maxCam) {
            maxCam = matriz[i][0]; // Aquí se corrige para obtener el número de camiseta correcto
        }
    }

    printf("El número máximo de camiseta es: %d\n", maxCam);

    // Calcular el promedio de asistencias
    float promAsistencia = (float)sumaAsistencias / filas;
    printf("El promedio de asistencias es: %.2f\n", promAsistencia);

    // Calcular el promedio de goles
    float promGoles = (float)sumaGoles / filas;
    printf("El promedio de goles es: %.2f\n", promGoles);

    return max;
}
