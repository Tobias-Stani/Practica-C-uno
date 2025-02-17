#include <stdio.h>

#define MAX_PEDIDOS 50 // Máximo de pedidos permitidos

// Función para ingresar datos de un pedido
void ingresarPedido(int *celulares, char *tiposNegocio, int *zonas, int *numPedidos) {
    // Verifica si se alcanzó el límite de pedidos
    if (*numPedidos >= MAX_PEDIDOS) {
        printf("\nNo se pueden ingresar más pedidos.\n");
        return;
    }

    // Accedemos a la posición actual con aritmética de punteros
    int *celularActual = celulares + *numPedidos;
    char *tipoActual = tiposNegocio + *numPedidos;
    int *zonaActual = zonas + *numPedidos;

    // Pedimos los datos al usuario
    printf("\nIngrese el celular: ");
    scanf("%d", celularActual);

    printf("Ingrese tipo de negocio (S: Salida a calle, L: Local, D: Deposito, O: Oficina): ");
    scanf(" %c", tipoActual); // Espacio antes de %c para evitar problemas con ENTER previo

    // Si el negocio es un depósito, preguntamos por la zona
    if (*tipoActual == 'D') {
        printf("Ingrese la zona (1: Urbana, 0: No Urbana): ");
        scanf("%d", zonaActual);
    } else {
        *zonaActual = 1; // Automáticamente urbana para otros negocios
    }

    (*numPedidos)++; // Aumentamos la cantidad de pedidos registrados
}

// Función para calcular y mostrar cotizaciones
void mostrarCotizaciones(int *celulares, char *tiposNegocio, int *zonas, int numPedidos) {
    int contadorDepositosNoUrbanos = 0;

    printf("\n--- INFORME DE COTIZACIONES ---\n");
    for (int i = 0; i < numPedidos; i++) {
        // Accedemos a cada posición usando punteros
        int *celularActual = celulares + i;
        char *tipoActual = tiposNegocio + i;
        int *zonaActual = zonas + i;

        // Determinamos el costo base según el tipo de negocio
        int costoBase;
        switch (*tipoActual) {
            case 'S': costoBase = 50000; break;
            case 'L': costoBase = 40000; break;
            case 'D': costoBase = 80000; break;
            case 'O': costoBase = 30000; break;
            default: costoBase = 0; // En caso de error
        }

        int costoTotal = costoBase;

        // Si es un depósito en zona no urbana, sumamos $5000
        if (*tipoActual == 'D' && *zonaActual == 0) {
            costoTotal += 5000;
            contadorDepositosNoUrbanos++;
        }

        // Mostramos los datos de la cotización
        printf("Celular: %d - Costo de cotización: $%d\n", *celularActual, costoTotal);
    }

    // Mostramos el total de depósitos en zona no urbana
    printf("\nCantidad de cotizaciones de depósitos/galpones en zona no urbana: %d\n", contadorDepositosNoUrbanos);
}

int main() {
    // Arrays para almacenar pedidos
    int celulares[MAX_PEDIDOS];
    char tiposNegocio[MAX_PEDIDOS];
    int zonas[MAX_PEDIDOS];

    int numPedidos = 0; // Contador de pedidos ingresados
    int opcion;

    do {
        // Menú de opciones
        printf("\n--- MENÚ ---\n");
        printf("1 - Ingresar datos de pedidos\n");
        printf("2 - Informar cotizaciones\n");
        printf("3 - Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        // Limpiar buffer para evitar errores con scanf de caracteres
        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                ingresarPedido(celulares, tiposNegocio, zonas, &numPedidos);
                break;
            case 2:
                if (numPedidos == 0) {
                    printf("\nNo hay pedidos ingresados.\n");
                } else {
                    mostrarCotizaciones(celulares, tiposNegocio, zonas, numPedidos);
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
