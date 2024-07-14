#include <stdio.h>

#define MAX 3

// Prototipos de las funciones
void limpiarPantalla();
void ingresoDatos(int vecX[], int vecY[]);
void cargarVectores(int x, int y, int vecX[], int vecY[]);
void habilidadRobot(int vecX[], int vecY[]);

int main() {
    int opcion;
    int vecX[MAX] = {0}, vecY[MAX] = {0};

    do {
        printf("Menu:\n");
        printf("1 - Ingresar datos de los tiros al arco.\n");
        printf("2 - Evaluar habilidades del arquero robot.\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresoDatos(vecX, vecY);
                break;
            case 2:
                habilidadRobot(vecX, vecY);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente nuevamente.\n");
        }

        if (opcion != 3) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            getchar(); // Esperar a que el usuario presione Enter
            limpiarPantalla();
        }
    } while (opcion != 3);

    return 0;
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void ingresoDatos(int vecX[], int vecY[]) {
    int x, y;

    printf("Ingrese las coordenadas de los tiros\n\n");

    printf("Ingrese la coordenada x: ");
    scanf("%d", &x);

    printf("Ingrese la coordenada y: ");
    scanf("%d", &y);

    cargarVectores(x, y, vecX, vecY);
}

void cargarVectores(int x, int y, int vecX[], int vecY[]) {
    int i;

    // Buscar la primera posición vacía en los vectores
    for (i = 0; i < MAX; i++) {
        if (vecX[i] == 0 && vecY[i] == 0) { // Si encuentra una posición vacía
            vecX[i] = x; // Asignar la coordenada x
            vecY[i] = y; // Asignar la coordenada y
            break; // Salir del ciclo una vez que se haya asignado
        }
    }

    printf("Datos cargados en los vectores:\n");
    for (i = 0; i < MAX; i++) {
        printf("Coordenada %d: (%d, %d)\n", i + 1, vecX[i], vecY[i]);
    }
}

void habilidadRobot(int vecX[], int vecY[]) {
    int contGoles = 0;
    int i;

    for (i = 0; i < MAX; i++) {
        if (vecX[i] <= 500 && vecY[i] <= 250) {
            printf("GOLAZOOOO\n");
            contGoles++;
        } else {
            printf("Fallaste burraso, sos un caballo\n");
        }
    }

    printf("La cantidad de goles fue de: %d\n", contGoles);
}

