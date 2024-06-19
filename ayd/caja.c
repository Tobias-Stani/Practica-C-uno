#include <stdio.h>

#define DIAS_MES 31

void ingresarMovimientos(float *movimientos);
void evaluarFlujoDeFondos(float *movimientos);
void limpiarPantalla();

int main() {
    float movimientos[DIAS_MES] = {0};
    int opcion;

    do {
        printf("Menu:\n");
        printf("1 - Ingresar datos de Movimientos de Fondos\n");
        printf("2 - Evaluar el Flujo de Fondos\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarMovimientos(movimientos);
                break;
            case 2:
                evaluarFlujoDeFondos(movimientos);
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
    } while(opcion != 3);

    return 0;
}

void ingresarMovimientos(float *movimientos) {
    int dia;
    char codigo;
    float monto;

    printf("Ingrese el dia del movimiento (1 a 31): ");
    scanf("%d", &dia);
    if (dia < 1 || dia > 31) {
        printf("Dia invalido. Debe estar entre 1 y 31.\n");
        return;
    }

    printf("Ingrese el codigo de movimiento ('I' para Ingreso, 'E' para Egreso): ");
    scanf(" %c", &codigo);
    if (codigo != 'I' && codigo != 'E') {
        printf("Codigo de movimiento invalido.\n");
        return;
    }

    printf("Ingrese el monto del movimiento (positivo): ");
    scanf("%f", &monto);
    if (monto <= 0) {
        printf("Monto invalido. Debe ser un valor positivo.\n");
        return;
    }

    // Ajustar el movimiento en el vector
    if (codigo == 'I') {
        *(movimientos + dia - 1) += monto;
    } else if (codigo == 'E') {
        *(movimientos + dia - 1) -= monto;
    }

    printf("Movimiento registrado exitosamente.\n");
}

void evaluarFlujoDeFondos(float *movimientos) {
    float saldoInicial, saldoDia;
    printf("Ingrese el Saldo Inicial de Caja: ");
    scanf("%f", &saldoInicial);

    saldoDia = saldoInicial;

    printf("Saldo de Caja por dia:\n");
    for (int i = 0; i < DIAS_MES; i++) {
        saldoDia += *(movimientos + i);
        printf("Dia %2d: Saldo = %.2f\n", i + 1, saldoDia);
    }

    printf("Saldo final de Caja del mes: %.2f\n", saldoDia);
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}
