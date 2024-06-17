#include <stdio.h>
#include <stdlib.h>

#define MAX_TIROS 50
#define ANCHO_ARCO 500
#define ALTO_ARCO 250

void ingresarDatos(int *coordenadasX, int *coordenadasY, int *numTiros);
void evaluarHabilidades(int *coordenadasX, int *coordenadasY, int numTiros);
void limpiarPantalla();

int main() {
    int coordenadasX[MAX_TIROS], coordenadasY[MAX_TIROS];
    int numTiros = 0;
    int opcion;

    do {
        printf("Menu:\n");
        printf("1 - Ingresar datos de tiros al arco\n");
        printf("2 - Evaluar habilidades del arquero robot\n");
        printf("3 - Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarDatos(coordenadasX, coordenadasY, &numTiros);
                break;
            case 2:
                if (numTiros == 0) {
                    printf("No hay tiros ingresados para evaluar.\n");
                } else {
                    evaluarHabilidades(coordenadasX, coordenadasY, numTiros);
                }
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción inválida. Por favor, intente nuevamente.\n");
        }

        if (opcion != 3) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            getchar(); // Esperar a que el usuario presione Enter
            limpiarPantalla();
        }
    } while(opcion != 3);

    return 0;
}

void ingresarDatos(int *coordenadasX, int *coordenadasY, int *numTiros) {
    if (*numTiros >= MAX_TIROS) {
        printf("Se ha alcanzado el máximo número de tiros permitidos.\n");
        return;
    }

    printf("Ingrese la coordenada X (>=0): ");
    scanf("%d", &coordenadasX[*numTiros]);

    printf("Ingrese la coordenada Y (>=0): ");
    scanf("%d", &coordenadasY[*numTiros]);

    (*numTiros)++;
    printf("Tiro ingresado exitosamente.\n");
}

void evaluarHabilidades(int *coordenadasX, int *coordenadasY, int numTiros) {
    int goles = 0, fuera = 0;

    for (int i = 0; i < numTiros; i++) {
        int x = *(coordenadasX + i);
        int y = *(coordenadasY + i);

        printf("Tiro %d - Coordenadas: (%d, %d) - ", i + 1, x, y);

        if (x >= 0 && x <= ANCHO_ARCO && y >= 0 && y <= ALTO_ARCO) {
            printf("GOL\n");
            goles++;
        } else {
            printf("AFUERA\n");
            fuera++;
        }
    }

    printf("\nTotal de Goles: %d\n", goles);
    printf("Total de Tiros Afuera: %d\n", fuera);
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}
