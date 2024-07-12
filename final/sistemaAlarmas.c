#include <stdio.h>
#include <ctype.h> // Necesario para tolower()

#define MAX 1

// Prototipos de las funciones
void limpiarPantalla();
void cargarVectores(int numeroTel[], int zona[], char tipoNegocio[], int *cotPuntoB);
void informeCotizaciones(int numeroTel[], int zona[], char tipoNegocio[], int cotPuntoB);

int main() {
    int opcion;
    int numeroTel[MAX], zona[MAX];
    char tipoNegocio[MAX];
    int cotPuntoB = 0; // Inicializar cotPuntoB

    do {
        printf("Menu:\n");
        printf("1 - Cargar\n");
        printf("2 - Informar cotizaciones\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                cargarVectores(numeroTel, zona, tipoNegocio, &cotPuntoB); // Pasar dirección de cotPuntoB
                break;
            case 2:
                informeCotizaciones(numeroTel, zona, tipoNegocio, cotPuntoB); // Pasar cotPuntoB
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

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void cargarVectores(int numeroTel[], int zona[], char tipoNegocio[], int *cotPuntoB) {
    int i;
    *cotPuntoB = 0;

    for(i = 0; i < MAX; i++) {
        printf("Ingrese el número telefónico %d: ", i + 1);
        scanf("%d", &numeroTel[i]);

        printf("Ingrese el Tipo de negocio 'S' 'L' 'D' 'O' para el negocio %d: ", i + 1);
        scanf(" %c", &tipoNegocio[i]); // Nota el espacio antes de %c para consumir el newline

        if (tipoNegocio[i] == 'd' || tipoNegocio[i] == 'D') {
            printf("Ingrese la zona para el negocio (0 o 1) %d: ", i + 1);
            scanf("%d", &zona[i]);
        } else {
            zona[i] = 0; // Asignar un valor por defecto si no es 'd' o 'D'
        }

        if (tipoNegocio[i] == 'd' && zona[i] == 0) {
            (*cotPuntoB)++; // Incrementar cotPuntoB si el tipo de negocio es 'd' y la zona es 0
        }
    }
}

void informeCotizaciones(int numeroTel[], int zona[], char tipoNegocio[], int cotPuntoB) {
    int i;
    int cotizacion = 0;
    int costoBase = 0;
    int costoAdicional = 0;

    printf("\nLos elementos de los vectores son:\n");
    printf("Numero\tZona\tNegocio\n");
    for(i = 0; i < MAX; i++) {
        printf("%d\t%d\t%c\n", numeroTel[i], zona[i], tipoNegocio[i]);
    }

    for(i = 0; i < MAX; i++) {
        char negocio = tolower(tipoNegocio[i]); // Convertir a minúscula para simplificar comparaciones

        // Determinar el costo base según el tipo de negocio
        if (negocio == 's') {
            costoBase = 5000;
        } else if (negocio == 'l') {
            costoBase = 4000;
        } else if (negocio == 'd') {
            costoBase = 8000;
        } else if (negocio == 'o') {
            costoBase = 30000;
        } else {
            costoBase = 0;
        }

        // Calcular costo adicional
        costoAdicional = (zona[i] == 0 && negocio == 'd') ? 5000 : 0;

        cotizacion = costoBase + costoAdicional;

        printf("Para el negocio con número %d, la cotización de la alarma es %d\n", numeroTel[i], cotizacion);
    }

    printf("\nLa cantidad de negocios con tipo 'D' y zona 0 es: %d\n", cotPuntoB);
}
