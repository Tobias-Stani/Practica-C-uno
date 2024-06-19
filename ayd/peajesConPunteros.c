#include <stdio.h>
#include <string.h>

#define MAX_VEHICULOS 50
#define PRECIO_CAMIONETA 200
#define PRECIO_AUTO 100
#define PRECIO_MOTO 50

typedef struct {
    char patente[10];
    char tipo;
    float horas;
    float gasto;
} Vehiculo;

void mostrarMenu();
void salidaVehiculo(Vehiculo *vehiculos, int *numVehiculos);
void generarInforme(Vehiculo *vehiculos, int numVehiculos);
float calcularGasto(char tipo, float horas);

int main() {
    Vehiculo vehiculos[MAX_VEHICULOS];
    int numVehiculos = 0;
    int opcion;

    do {
        mostrarMenu();
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                salidaVehiculo(vehiculos, &numVehiculos);
                break;
            case 2:
                generarInforme(vehiculos, numVehiculos);
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
        }
    } while(opcion != 3);

    return 0;
}

void mostrarMenu() {
    printf("\nMenu:\n");
    printf("1 - Salida de un vehículo y cálculo del gasto de estacionamiento a pagar\n");
    printf("2 - Generar Informe Resumen del día\n");
    printf("3 - Salir\n");
    printf("Seleccione una opción: ");
}

void salidaVehiculo(Vehiculo *vehiculos, int *numVehiculos) {
    if (*numVehiculos >= MAX_VEHICULOS) {
        printf("Se ha alcanzado el máximo número de vehículos permitidos.\n");
        return;
    }

    Vehiculo nuevoVehiculo;
    printf("Ingrese la patente del vehículo: ");
    scanf("%s", nuevoVehiculo.patente);

    printf("Ingrese el tipo de vehículo ('c' = camioneta, 'a' = auto, 'm' = moto): ");
    scanf(" %c", &nuevoVehiculo.tipo);

    printf("Ingrese el tiempo en horas de permanencia: ");
    scanf("%f", &nuevoVehiculo.horas);

    nuevoVehiculo.gasto = calcularGasto(nuevoVehiculo.tipo, nuevoVehiculo.horas);

    *(vehiculos + *numVehiculos) = nuevoVehiculo;
    (*numVehiculos)++;

    printf("El gasto de estacionamiento a pagar es: $%.2f\n", nuevoVehiculo.gasto);
}

void generarInforme(Vehiculo *vehiculos, int numVehiculos) {
    float totalCamioneta = 0, totalAuto = 0, totalMoto = 0, totalDia = 0;
    float menorGastoCamioneta = -1;

    for (int i = 0; i < numVehiculos; i++) {
        switch ((vehiculos + i)->tipo) {
            case 'c':
                totalCamioneta += (vehiculos + i)->gasto;
                if (menorGastoCamioneta == -1 || (vehiculos + i)->gasto < menorGastoCamioneta) {
                    menorGastoCamioneta = (vehiculos + i)->gasto;
                }
                break;
            case 'a':
                totalAuto += (vehiculos + i)->gasto;
                break;
            case 'm':
                totalMoto += (vehiculos + i)->gasto;
                break;
        }
        totalDia += (vehiculos + i)->gasto;
    }

    printf("\nInforme Resumen del día:\n");
    printf("Monto ingresado por tipo de vehículo:\n");
    printf("Camionetas: $%.2f\n", totalCamioneta);
    printf("Autos: $%.2f\n", totalAuto);
    printf("Motos: $%.2f\n", totalMoto);
    printf("Monto total del día: $%.2f\n", totalDia);

    if (menorGastoCamioneta != -1) {
        printf("El menor gasto de estacionamiento pagado por una camioneta es: $%.2f\n", menorGastoCamioneta);
    } else {
        printf("No hubo camionetas.\n");
    }
}

float calcularGasto(char tipo, float horas) {
    switch (tipo) {
        case 'c':
            return PRECIO_CAMIONETA * horas;
        case 'a':
            return PRECIO_AUTO * horas;
        case 'm':
            return PRECIO_MOTO * horas;
        default:
            return 0;
    }
}

