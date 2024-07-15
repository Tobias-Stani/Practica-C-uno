#include <stdio.h>

#define MAX 5
#define MAX_CADENA 5

// Prototipos de las funciones
void limpiarPantalla();
void limpiarBuffer();
void ingresoDatos(char patentes[MAX][MAX_CADENA], char vehiculo[], int tiempo[], int *contador);
void generarInforme(char patentes[MAX][MAX_CADENA], char vehiculo[], int tiempo[], int *contador);

int main() {
    int opcion = 0; // Inicializar opcion para evitar warnings
    char patentes[MAX][MAX_CADENA];
    char vehiculo[MAX];
    int tiempo[MAX];

    int contador = 0; // Inicializa el contador

    do {
        printf("Menu:\n");
        printf("1 - Ingresar \n");
        printf("2 - Generar informe\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        limpiarBuffer(); // Limpiar buffer después de scanf

        switch (opcion) {
            case 1:
                ingresoDatos(patentes, vehiculo, tiempo, &contador);
                break;
            case 2:
                generarInforme(patentes, vehiculo, tiempo, &contador);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente nuevamente.\n");
        }

        if (opcion != 3) {
            printf("Presione Enter para continuar...");
            limpiarBuffer(); // Limpiar buffer después de getchar
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

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ingresoDatos(char patentes[MAX][MAX_CADENA], char vehiculo[], int tiempo[], int *contador) {
    if (*contador < MAX) {
        printf("Ingrese patente: ");
        scanf("%s", patentes[*contador]);
        limpiarBuffer();

        printf("Ingrese tipo de vehiculo ('C' camion, 'A' auto, 'M' moto): ");
        scanf(" %c", &vehiculo[*contador]);
        limpiarBuffer();

        printf("Ingrese tiempo: ");
        scanf("%d", &tiempo[*contador]);
        limpiarBuffer();

        (*contador)++;
    } else {
        printf("No se pueden ingresar más datos. Límite alcanzado.\n");
    }

    limpiarPantalla();
}

void generarInforme(char patentes[MAX][MAX_CADENA], char vehiculo[], int tiempo[], int *contador) {
    int valorCam = 200, valorAuto = 100, valorMoto = 50;
    int gasto, gastoMenor, i, acumuladorDinero = 0;
    int min;

    printf("Generando informe punto a\n");

    for (i = 0; i < *contador; i++) {
        printf("Vehiculo[%d]: %c, Patente[%d]: %s, Tiempo[%d]: %d\n", i, vehiculo[i], i, patentes[i], i, tiempo[i]);

        // Comparar con caracteres en minúscula
        if (vehiculo[i] == 'C' || vehiculo[i] == 'c') {
            gasto = valorCam * tiempo[i];
            acumuladorDinero += gasto;

            if (gasto < gastoMenor) {
                gastoMenor = gasto;
            }

            printf("Camioneta - Patente: %s, Tiempo: %d, Gasto: %d\n", patentes[i], tiempo[i], gasto);

        } else if (vehiculo[i] == 'A' || vehiculo[i] == 'a') {
            gasto = valorAuto * tiempo[i];
            acumuladorDinero += gasto;
            printf("Auto - Patente: %s, Tiempo: %d, Gasto: %d\n", patentes[i], tiempo[i], gasto);

        } else if (vehiculo[i] == 'M' || vehiculo[i] == 'm') {
            gasto = valorMoto * tiempo[i];
            acumuladorDinero += gasto;
            printf("Moto - Patente: %s, Tiempo: %d, Gasto: %d\n", patentes[i], tiempo[i], gasto);

        } else {
            printf("Vehiculo desconocido: %c\n", vehiculo[i]);
        }
    }

    printf("El monto total del dia fue de: $%d\n", acumuladorDinero);

    printf("El menor gasto de una camioneta fue de: $%d\n", gastoMenor);

}
