#include <stdio.h>

#define MAX 3

// Prototipos de las funciones
void limpiarPantalla();
void limpiarBuffer();
void ingresoDatos();

int main() {
    int opcion;

    do {
        printf("Menu:\n");
        printf("1 - Ingresar \n");
        printf("2 - Menu 2\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresoDatos();
                break;
            case 2:
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
    } while (opcion != 3);

    return 0;
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void ingresoDatos() {
    int i;

    for (i = 0; i < MAX; i++)
    {
        printf("Ingrese tipo de movimiento 'i' Ingreso o 'E' Egreso: \n");
        //scanf(" %c", &vecMov[i]);
        limpiarBuffer();

        printf("Ingrese la cantidad a ingresar o egresar: \n");
        //scanf(" %d", &monto[i]);
        limpiarBuffer(); 
    }

    limpiarPantalla();
}



