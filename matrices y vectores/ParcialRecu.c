#include <stdio.h>

#define MAX 2

void ingresarFichada(int *codEmpleado, int *codSucursal, int *entSal, char *turno, int *turno1, int *turno2, int *turno3);
void generarInforme(int *codEmpleado, int *codSucursal, int *entSal, char *turno, int turno1, int turno2, int turno3);
void limpiarPantalla();

int main() {
    int codEmpleado[MAX] = {0};
    int codSucursal[MAX] = {0};
    int entSal[MAX] = {0};
    int opcion;
    char turno[MAX];
    int turno1 = 0, turno2 = 0, turno3 = 0; // Contadores para 'm', 't', 'n'

    do {
        printf("Menu:\n");
        printf("1 - Ingresar Datos del fichaje\n");
        printf("2 - Generar informe\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarFichada(codEmpleado, codSucursal, entSal, turno, &turno1, &turno2, &turno3);
                break;
            case 2:
                generarInforme(codEmpleado, codSucursal, entSal, turno, turno1, turno2, turno3);
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

void ingresarFichada(int *codEmpleado, int *codSucursal, int *entSal, char *turno, int *turno1, int *turno2, int *turno3){

    int i;

    for(i=0; i < MAX; i++){
        printf("Ingrese el numero de empleado: ");
        scanf("%d", &codEmpleado[i]);

        printf("Ingrese el codigo de sucursal: ");
        scanf("%d", &codSucursal[i]);

        printf("Ingrese la entrada o salida (1/2): ");
        scanf("%d", &entSal[i]); 

        // Consumir el carácter de nueva línea pendiente en el búfer
        while (getchar() != '\n');

        printf("Ingrese el turno 'm', 't', 'n': ");
        scanf("%c", &turno[i]);

        if (turno[i] == 'm') {
            (*turno1)++;
        } else if (turno[i] == 't') {
            (*turno2)++;
        } else if (turno[i] == 'n') {
            (*turno3)++;
        }

    }

    printf("Datos del fichaje ingresados exitosamente.\n");

}

void generarInforme(int *codEmpleado, int *codSucursal, int *entSal, char *turno, int turno1, int turno2, int turno3){
    int contadorEntradasSucursal2 = 0;
    int contadorSalidasSucursal2 = 0;
    int totFichajes = 0;

    printf("\nInforme de fichajes:\n");
    printf("Nro. Empleado\tCod. Sucursal\tEnt/Sal\t\tTurno\n");

    for (int i = 0; i < MAX; i++) {
        printf("%d\t\t%d\t\t%d\t\t%c\n", codEmpleado[i], codSucursal[i], entSal[i], turno[i]);

        // Contar entradas y salidas de la sucursal 2
        if (codSucursal[i] == 2) {
            if (entSal[i] == 1) {
                contadorEntradasSucursal2++;
            } else if (entSal[i] == 2) {
                contadorSalidasSucursal2++;
            }
        }
    }

    // Informar si la sucursal 2 tuvo más entradas que salidas
    printf("\nResumen de sucursal 2:\n");
    printf("Entradas: %d\n", contadorEntradasSucursal2);
    printf("Salidas: %d\n", contadorSalidasSucursal2);
    if (contadorEntradasSucursal2 > contadorSalidasSucursal2) {
        printf("La sucursal 2 tuvo más entradas que salidas.\n");
    } else {
        printf("La sucursal 2 tuvo igual o menos entradas que salidas.\n");
    }

    // Mostrar resumen de turnos 'm', 't', 'n'
    printf("\nResumen de turnos:\n");
    printf("'m': %d veces\n", turno1);
    printf("'t': %d veces\n", turno2);
    printf("'n': %d veces\n", turno3);
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls"); // Para sistemas Windows
    #else
        system("clear"); // Para sistemas Unix/Linux
    #endif
}
