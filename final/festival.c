#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strcmp

#define MAX 1

void limpiarPantalla();
int generadorTicket();
int ticketYPrecio(char* ubicacion);
void ubicaciones(char* ubicacion);


int main() {
    char continuar = 's', ubicacion[100];
    int dia;
    int contadorDia3 = 0;

    while (continuar == 's') {
        printf("Ingrese la ubicacion a adquirir ('cam', 'pla', 'pal'): ");
        scanf("%99s", ubicacion); // %99s para evitar el desbordamiento del buffer

        printf("Ingrese el dia que desea ir (1 al 3): ");
        scanf("%d", &dia);

        if (dia == 3) {
            contadorDia3++;
        }

        ubicaciones(ubicacion);

        printf("¿Desea continuar vendiendo entradas? (s/n): ");
        scanf(" %c", &continuar);

        limpiarPantalla();
    }

    printf("La cantidad de entradas vendidas el día 3 fue de: %d\n\n\n", contadorDia3);

    return 0;
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int generadorTicket() {
    static int numeroTicket = 0; // Variable estática para almacenar el número de ticket
    return ++numeroTicket;
}

int ticketYPrecio(char* ubicacion) {
    int precio = 0;

    if (strcmp(ubicacion, "cam") == 0) {
        precio = 60;
    } else if (strcmp(ubicacion, "pla") == 0) {
        precio = 80;
    } else if (strcmp(ubicacion, "pal") == 0) {
        precio = 120;
    }

    return precio;
}

void ubicaciones(char* ubicacion){

    int ticketNumero = generadorTicket();

    limpiarPantalla();

        if (strcmp(ubicacion, "cam") == 0 && ticketNumero > 3500) {
            printf("Lo sentimos, se acabaron las entradas para el campo.\n");
        } else if (strcmp(ubicacion, "pla") == 0 && ticketNumero > 1000) {
            printf("Lo sentimos, no hay más entradas para la platea.\n");
        } else if (strcmp(ubicacion, "pal") == 0 && ticketNumero > 500) {
            printf("Lo sentimos, no hay más entradas para el palco.\n");
        } else {
            printf("Su ticket es el número: %d\n", ticketNumero);
            printf("El precio de su entrada es: %d\n", ticketYPrecio(ubicacion));
        }
}