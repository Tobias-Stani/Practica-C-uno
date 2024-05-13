#include <stdio.h>
#include <string.h>

int maxCampo = 3, maxPlatea = 2, maxPalco = 1;
int totalEntradasVendidas = 0, totalRecaudado = 0;

int numeroTicket();
void mostrarInformacionVenta(int numeroTicket, int precio);
void informarSinLugar();
void limpiarPantalla();

int main() {
    char band = 's', ubicacion[4];
    int dia, precioEntrada;

    while (band == 's') {
        printf("Ingrese el día: ");
        scanf("%d", &dia);

        printf("Ingrese la ubicación (cam, pla o pac): ");
        scanf("%3s", ubicacion);

        // Determinar el precio de la entrada y actualizar la cantidad máxima disponible
        if(strcmp(ubicacion, "cam") == 0 && maxCampo > 0) {
            precioEntrada = 60;
            maxCampo--;
        } else if(strcmp(ubicacion, "pla") == 0 && maxPlatea > 0) {
            precioEntrada = 80;
            maxPlatea--;
        } else if(strcmp(ubicacion, "pac") == 0 && maxPalco > 0) {
            precioEntrada = 120;
            maxPalco--;
        } else {
            informarSinLugar();
            continue; // Volver al inicio del bucle para volver a solicitar la entrada
        }

        // Actualizar el total de entradas vendidas y el total recaudado
        totalEntradasVendidas++;
        totalRecaudado += precioEntrada;

        mostrarInformacionVenta(numeroTicket(), precioEntrada);

        printf("¿Desea vender más entradas? (s/n): ");
        scanf(" %c", &band);
    }

    // Informar cantidad de entradas campo vendidas del día 3 y totales
    printf("Cantidad de entradas campo vendidas del día 3: %d\n", 3 - maxCampo);
    printf("Total de entradas vendidas: %d\n", totalEntradasVendidas);
    printf("Total recaudado: %d\n", totalRecaudado);

    limpiarPantalla();

    printf("Fin del programa.\n");
    return 0;
}

int numeroTicket() {
    static int numeroTicket = 0; // Variable estática para almacenar el número de ticket
    return ++numeroTicket;
}

void mostrarInformacionVenta(int numeroTicket, int precio) {
    limpiarPantalla();
    printf("Su número de entrada es: %d\n", numeroTicket);
    printf("Precio de la entrada: $%d\n", precio);
}

void informarSinLugar() {
    limpiarPantalla();
    printf("No hay lugar disponible en esta ubicación.\n");
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}
