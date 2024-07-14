#include <stdio.h>

#define MAX 50

// Prototipos de las funciones
void limpiarPantalla();
void limpiarBuffer();
void ingresoDatos(int *hora, int *minutos, int *velocidad, int *codigo, int *contador);
void cargarVectores(int *hora, int *minutos, int *velocidad, int *codigo, int h, int m, int v, int c, int idx);
void emitirReportes(int *hora, int *minutos, int *velocidad, int *codigo, int contador);

int main() {
    int opcion;
    int hora[MAX] = {0};
    int minutos[MAX] = {0};
    int velocidad[MAX] = {0};
    int codigo[MAX] = {0};
    int contador = 0;

    do {
        printf("Menu:\n");
        printf("1 - Ingresar y guardar datos de la simulacion. \n");
        printf("2 - Emitir reportes\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresoDatos(hora, minutos, velocidad, codigo, &contador);
                break;
            case 2:
                emitirReportes(hora, minutos, velocidad, codigo, contador);
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

void ingresoDatos(int *hora, int *minutos, int *velocidad, int *codigo, int *contador) {
    if (*contador >= MAX) {
        printf("No se pueden ingresar más datos, el límite es %d.\n", MAX);
        return;
    }

    int h, m, v, c;

    printf("\\INGRESO DE DATOS//\n");

    printf("Ingrese la hora: ");
    scanf("%d", &h);
    limpiarBuffer();

    printf("Ingrese los minutos: ");
    scanf("%d", &m);
    limpiarBuffer();

    printf("Ingrese la velocidad: ");
    scanf("%d", &v);
    limpiarBuffer();

    printf("Ingrese el codigo de camion: ");
    scanf("%d", &c);
    limpiarBuffer();

    cargarVectores(hora, minutos, velocidad, codigo, h, m, v, c, *contador);

    (*contador)++;

    limpiarPantalla();
}

void cargarVectores(int *hora, int *minutos, int *velocidad, int *codigo, int h, int m, int v, int c, int idx) {
    *(hora + idx) = h;
    *(minutos + idx) = m;
    *(velocidad + idx) = v;
    *(codigo + idx) = c;

    printf("Datos cargados en los vectores en la posición %d.\n", idx);
}

void emitirReportes(int *hora, int *minutos, int *velocidad, int *codigo, int contador) {
    int maxVelocidad = -1; // Asumiendo que la velocidad no puede ser negativa
    int idxMaxVelocidad = -1;
    
    printf("Reporte del Camion 2:\n");
    for (int i = 0; i < contador; i++) {
        if (*(codigo + i) == 2) {
            printf("Hora: %d, Minutos: %d, Velocidad: %d, Codigo: %d\n", *(hora + i), *(minutos + i), *(velocidad + i), *(codigo + i));
            if (*(velocidad + i) > maxVelocidad) {
                maxVelocidad = *(velocidad + i);
                idxMaxVelocidad = i;
            }
        }
    }
    
    if (idxMaxVelocidad != -1) {
        printf("La máxima velocidad registrada para el camión 2 es %d.\n", maxVelocidad);
    } else {
        printf("No se encontraron registros para el camión 2.\n");
    }
}
