#include <stdio.h>
#define TAM 5  

// Función para guardar el tipo de vehículo y el monto en los vectores
void guardarDatosSalida(char *tipoVehiculos, int *montos, char tipo, int monto, int *contador) {
    if (*contador < TAM) {  
        tipoVehiculos[*contador] = tipo;
        montos[*contador] = monto;
        (*contador)++;  
    } else {
        printf("No se pueden guardar más registros.\n");
    }
}

void salidaVehiculo(char *tipoVehiculos, int *montos, int *contador) {
    char tipo;
    int horas, monto = 0;

    printf("Ingrese el tipo de vehiculo (c, a, m): ");
    scanf(" %c", &tipo);

    printf("Ingrese las horas de estadia: ");
    scanf("%d", &horas);

    if (tipo == 'c') {
        monto = 200 * horas;
    } else if (tipo == 'a') {
        monto = 100 * horas;
    } else if (tipo == 'm') {
        monto = 50 * horas;
    } else {
        printf("Tipo de vehículo inválido.\n");
        return;
    }

    printf("El valor a pagar por el vehículo tipo %c es: $%d\n", tipo, monto);

    // Guardar datos en los vectores
    guardarDatosSalida(tipoVehiculos, montos, tipo, monto, contador);
}


void generarInforme(char *tipoVehiculos, int *montos, int contador) {
    int totalCaja = 0, totalCamionetas = 0, totalAutos = 0, totalMotos = 0;
    int menorGastoCamioneta = -1;  // Inicializamos en -1 para manejar si no hay camionetas

    for (int i = 0; i < contador; i++) {
        totalCaja += montos[i];

        if (tipoVehiculos[i] == 'c') {
            totalCamionetas += montos[i];

            // Buscar el menor gasto pagado por una camioneta
            if (menorGastoCamioneta == -1 || montos[i] < menorGastoCamioneta) {
                menorGastoCamioneta = montos[i];
            }
        } else if (tipoVehiculos[i] == 'a') {
            totalAutos += montos[i];
        } else if (tipoVehiculos[i] == 'm') {
            totalMotos += montos[i];
        }
    }

    printf("\n--- RESUMEN DEL DÍA ---\n");
    printf("Monto total en caja: $%d\n", totalCaja);
    printf("Total recaudado por tipo de vehículo:\n");
    printf("  - Camionetas: $%d\n", totalCamionetas);
    printf("  - Autos: $%d\n", totalAutos);
    printf("  - Motos: $%d\n", totalMotos);

    if (menorGastoCamioneta != -1) {
        printf("El menor gasto pagado por una camioneta fue: $%d\n", menorGastoCamioneta);
    } else {
        printf("No se registraron camionetas hoy.\n");
    }
}

int main() {
    int opcion, contador = 0;
    char tipoVehiculos[TAM];
    int montos[TAM];

    do {
        printf("\nMenu:\n");
        printf("1. Salida de un vehículo y cálculo del gasto\n");
        printf("2. Generar Informe Resumen del día\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                salidaVehiculo(tipoVehiculos, montos, &contador);
                break;
            case 2:
                generarInforme(tipoVehiculos, montos, contador);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while(opcion != 3);

    return 0;
}
