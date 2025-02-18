#include <stdio.h>

#define MAX_PEDIDOS 31


void ingresarPedido(int *dia, char *tipoMov, int *monto, int *movimientos) {

    printf("\nIngrese el dia (1-31): ");
    scanf("%d", dia);

    printf("Ingrese tipo de movimiento (I = Ingreso, E = Egreso): ");
    scanf(" %c", tipoMov); 

    printf("\nIngrese el monto: $ ");
    scanf("%d", monto);

    // Calcular el índice para el vector de movimientos (Día - 1)
    int idx = *dia - 1;

    // Actualizar el valor en el vector de movimientos según el tipo de movimiento
    if (*tipoMov == 'I') {
        movimientos[idx] += *monto; // Incrementar el monto si es un ingreso
    } else if (*tipoMov == 'E') {
        movimientos[idx] -= *monto; // Decrementar el monto si es un egreso
    }
}

void evaluarCobranzas(int *movimientos) {
    int saldoInicial, saldoAcumulado;

    // Solicitar el Saldo Inicial de Caja
    printf("\nIngrese el Saldo Inicial de Caja: $");
    scanf("%d", &saldoInicial);

    // Inicializar el saldo acumulado con el saldo inicial
    saldoAcumulado = saldoInicial;

    printf("\n--- SALDO DE CAJA POR DÍA ---\n");
    for (int i = 0; i < MAX_PEDIDOS; i++) {
        saldoAcumulado += *(movimientos + i); // Se acumula el saldo día a día
        printf("Día %2d: Saldo $%d\n", i + 1, saldoAcumulado);
    }

    // Mostrar el saldo final del mes
    printf("\nSaldo Final de Caja del mes: $%d\n", saldoAcumulado);
}


int main() {

    int movimientos[MAX_PEDIDOS] = {0};
    int dia[MAX_PEDIDOS];
    char movimiento[MAX_PEDIDOS];
    int monto[MAX_PEDIDOS];

    int numPedidos = 0; 
    int opcion;

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
                ingresarPedido(dia, movimiento, monto, movimientos);
                break;
            case 2:
                if (numPedidos == 0) {
                    printf("\nNo hay pedidos ingresados.\n");
                } else {
                    evaluacionCobranza(movimientos);
                }
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
