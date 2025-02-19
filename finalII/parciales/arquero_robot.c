#include <stdio.h>

#define TAM 2
#define LARGO 500
#define ANCHO 250

void cargarDatos(int *vec1, int *vec2, int tam) {
    char opcion;
    int i = 0;

    printf("\nIngrese los valores para los tres vectores:\n");
    while (i < tam) {
        printf("Vector 1, posicion %d: ", i + 1);
        scanf("%d", (vec1 + i));
        printf("Vector 2, posicion %d: ", i + 1);
        scanf("%d", (vec2 + i));
        
        i++;
        
        if (i < tam) {
            printf("\nDesea continuar ingresando datos? (s/n): ");
            scanf(" %c", &opcion);
            if (opcion == 'n' || opcion == 'N') {
                break;
            }
        }
    }
}

void emitirReportes(int *x, int *y, int tam) {
    int cantGoles = 0, noGoles = 0;

    for (int i = 0; i < tam; i++) {
        printf("Tiro %d en coordenadas (X: %d, Y: %d): ", i + 1, x[i], y[i]);

        if (x[i] >= 0 && x[i] <= 500 && y[i] >= 0 && y[i] <= 250) {
            printf("GOOOOOOL!\n");
            cantGoles++;
        } else {
            printf("AFUERA!\n");
            noGoles++;
        }
    }

    printf("\nResumen del partido:\n");
    printf("Goles anotados: %d\n", cantGoles);
    printf("Tiros fallidos: %d\n", noGoles);
}


int main() {
    int opcion;
    int x[TAM], y[TAM];
    
    do {
        printf("\nMenu:\n");
        printf("1. Cargar datos de los goles\n");
        printf("2. Emitir reportes\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                cargarDatos(x, y, TAM);
                break;
            case 2:
                emitirReportes(x, y, TAM);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while(opcion != 3);
    
    return 0;
}