// telefono, cantidad invitados diaMes
//
//
//
//
//


#include <stdio.h>


#define MAX 1

void registroReserva(int *telefono, int *cantInvitados, int *diaMes);
void generarReporte(int *telefono, int *cantInvitados, int *diaMes);
void limpiarPantalla();

int main() {
    int telefono[MAX] = {0}, cantInvitados[MAX] = {0}, diaMes[MAX] = {0};
    int opcion;

    do {
        printf("Menu:\n");
        printf("1 - Registrar reserva\n");
        printf("2 - Generar informe\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                registroReserva(telefono, cantInvitados, diaMes);
                break;
            case 2:
                generarReporte(telefono, cantInvitados, diaMes);
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

void registroReserva(int *telefono, int *cantInvitados, int *diaMes){

    int dia, i;
    int reservaExistente = 0;

    printf("Ingrese el dia del mes a realizar la fiesta: \n");
    scanf("%d", &dia);

    // Comprobar si ya hay una reserva en ese día
    for (i = 0; i < MAX; i++) {
        if (diaMes[i] == dia) {
            reservaExistente = 1;
            break;
        }
    }

    if (reservaExistente) {
        printf("Dia del mes ya reservado, intente con otro dia.\n");
    } else {
        for (i = 0; i < MAX; i++) {
            if (diaMes[i] == 0) { // Encontrar el primer espacio vacío en el array
                printf("Ingrese telefono de contacto: \n");
                scanf("%d", &telefono[i]);

                printf("Ingrese la cantidad de invitados: \n");
                scanf("%d", &cantInvitados[i]);

                diaMes[i] = dia;
                printf("Reserva registrada exitosamente.\n");
                break;
            }
        }
    }
}


void generarReporte(int *telefono, int *cantInvitados, int *diaMes){

    printf("\nInforme de reservas:\n");
    printf("Telefono\tCantidad de Invitados\tDia del Mes\n");

    for (int i = 0; i < MAX; i++) {
        if (diaMes[i] != 0) {
            printf("%d\t\t%d\t\t\t%d\n", telefono[i], cantInvitados[i], diaMes[i]);
        }
    }

}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); // Para sistemas Windows
    #else
        system("clear"); // Para sistemas Unix/Linux
    #endif
}