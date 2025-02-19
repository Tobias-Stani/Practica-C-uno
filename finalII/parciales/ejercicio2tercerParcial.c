#include <stdio.h>

#define TAM 31

void ingresarDatos(int *tel, int *invitados, int *dia, int *numRegistros){

    printf("\nIngrese el telefono: ");
    scanf("%d", (tel + *numRegistros));
    printf("\nIngrese la cantidad de invitados: ");
    scanf("%d", (invitados + *numRegistros));
    printf("\nIngrese el dia: ");
    scanf("%d", (dia + *numRegistros));

    (*numRegistros)++;
}

void emitirReportes(int *hora, int *minutos, int *velocidad, int *codCamion, int numRegistros){

}

int main() {
    int telefono[TAM], invitados[TAM], dia[TAM];
    int opcion;
    int numRegistros = 0;

    do {

        printf("\n--- MENÚ ---\n");
        printf("1 - Ingresar datos de pedidos\n");
        printf("2 - Mostrar reservas del mes\n");
        printf("3 - Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                ingresarDatos(telefono, invitados, dia, &numRegistros);
                break;
            case 2:
                
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