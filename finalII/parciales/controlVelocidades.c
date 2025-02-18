#include <stdio.h>

#define TAM 10

void ingresarDatos(int *hora, int *minutos, int *velocidad, int *codCamion, int *numRegistros){

    printf("\nIngrese la hora: ");
    scanf("%d", (hora + *numRegistros));
    printf("\nIngrese los minutos: ");
    scanf("%d", (minutos + *numRegistros));
    printf("\nIngrese la velocidad: ");
    scanf("%d", (velocidad + *numRegistros));
    printf("\nIngrese el codigo del camion (1 al 3): ");
    scanf("%d", (codCamion + *numRegistros));

    (*numRegistros)++;
}

void emitirReportes(int *hora, int *minutos, int *velocidad, int *codCamion, int numRegistros){

    int maxVelocidad = 0;
    int indiceMaxVelocidad = -1;

    printf("\n--- Reporte del Camión 2 ---\n");

    for (int i = 0; i < numRegistros; i++)
    {
        printf("Hora: %d : %d - velocidad %dkmh\n", *(hora + i), *(minutos + i), *(velocidad + i));

        if (*(velocidad + i) > maxVelocidad) {
            maxVelocidad = *(velocidad + i);
            indiceMaxVelocidad = i;
        }
    }
    
    if (indiceMaxVelocidad != -1) {
        printf("\nMáxima velocidad registrada del Camión 2:\n");
        printf("Hora: %02d:%02d - Velocidad: %d km/h\n",
               *(hora + indiceMaxVelocidad), *(minutos + indiceMaxVelocidad), maxVelocidad);
    } else {
        printf("\nNo se registraron datos para el Camión 2.\n");
    }

}

int main() {
    int hora[TAM], minutos[TAM], velocidad[TAM], codCamion[TAM];
    int opcion;
    int numRegistros = 0;

    do {

        printf("\n--- MENÚ ---\n");
        printf("1 - Ingresar datos de pedidos\n");
        printf("2 - Informar cotizaciones\n");
        printf("3 - Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                ingresarDatos(hora, minutos, velocidad, codCamion, &numRegistros);
                break;
            case 2:
                emitirReportes(hora, minutos, velocidad, codCamion, numRegistros);
                break;
            case 3:
                printf("\nSaliendo del programa...\n");
                break;
            default:
                printf("\nOpción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 3);

    return 0;
}