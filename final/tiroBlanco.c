#include <stdio.h>

#define MAX 2

// Prototipos de las funciones
void limpiarPantalla();
void limpiarBuffer();
void ingresoDatos(int tirador[], int distancia[], char posicion[]);
void resultados(int tirador[], int distancia[], char posicion[]);
int calcularResultados(char posicion, int distancia);

int main() {
    int opcion;
    int tirador[MAX], distancia[MAX];
    char posicion[MAX];

    do {
        printf("Menu:\n");
        printf("1 - Ingresar \n");
        printf("2 - resultados \n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresoDatos(tirador, distancia, posicion);
                break;
            case 2:
                resultados(tirador, distancia, posicion);
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

void ingresoDatos(int tirador[], int distancia[], char posicion[]) {
    int i;

    for (i = 0; i < MAX; i++) {
        printf("Ingrese el codigo del tirador: \n");
        scanf("%d", &tirador[i]);
        limpiarBuffer();

        printf("Ingrese la posicion (c, m, b): \n");
        scanf(" %c", &posicion[i]);
        limpiarBuffer(); 

        printf("Ingrese la distancia (1 o 2): \n");
        scanf("%d", &distancia[i]);
        limpiarBuffer();
    }

    limpiarPantalla();
}

void resultados(int tirador[], int distancia[], char posicion[]) {
    int i;
    int puntaje;

    for (i = 0; i < MAX; i++) {
        puntaje = calcularResultados(posicion[i], distancia[i]);
        printf("Tirador: %d, Posicion: %c, Distancia: %d, Puntaje: %d\n",
               tirador[i], posicion[i], distancia[i], puntaje);
    }
}

int calcularResultados(char posicion, int distancia) {
    int puntaje = 0;

    if (posicion == 'c') {
        if (distancia == 1) {
            puntaje = 100;
        } else if (distancia == 2) {
            puntaje = 200;
        }
    } else if (posicion == 'm') {
        if (distancia == 1) {
            puntaje = 50;
        } else if (distancia == 2) {
            puntaje = 100;
        }
    } else if (posicion == 'b') {
        if (distancia == 1) {
            puntaje = 10;
        } else if (distancia == 2) {
            puntaje = 20;
        }
    }

    return puntaje;
}
