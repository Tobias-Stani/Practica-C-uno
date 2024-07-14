#include <stdio.h>

#define MAX 3

void limpiarPantalla();
void limpiarBuffer();
void ingresoDatos(int numero[], char categoria[], int *contador);
void calculoGanadores(int numero[], char categoria[], int *contador, int primeros[]);

int main() {
    int opcion;
    int numero[MAX] = {0};
    char categoria[MAX];
    int primeros[MAX]; // Array para almacenar los primeros corredores por categoría

    int contador = 0; // Inicializa el contador

    do {
        printf("Menu:\n");
        printf("1 - Ingresar \n");
        printf("2 - Calculo de los ganadores \n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresoDatos(numero, categoria, &contador);
                break;
            case 2:
                calculoGanadores(numero, categoria, &contador, primeros);
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

    // Mostrar los datos ingresados
    printf("Datos ingresados:\n");
    for (int i = 0; i < contador; i++) {
        printf("Numero: %d, Categoria: %c\n", numero[i], categoria[i]);
    }

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

void ingresoDatos(int numero[], char categoria[], int *contador) {
    printf("Ingrese el numero:  \n");
    scanf(" %d", &numero[*contador]);
    limpiarBuffer();

    printf("Ingrese categoria: \n");
    scanf(" %c", &categoria[*contador]);
    limpiarBuffer();

    (*contador)++;

    limpiarPantalla();
}


void calculoGanadores(int numero[], char categoria[], int *contador, int primeros[]){
    
    // Inicializar el array de primeros con 0, indicando que no hay ganador aún
    for (int i = 0; i < MAX; i++) {
        primeros[i] = 0;
    }

    // Encontrar el primer corredor de cada categoría
    for (int i = 0; i < MAX; i++) {
        char categoria_actual = categoria[i];
        int numero_actual = numero[i];

        // Si aún no se ha registrado un primer corredor para esta categoría
        if (primeros[categoria_actual - 'A'] == 0) {
            primeros[categoria_actual - 'A'] = numero_actual;
        }
    }

    // Mostrar los resultados
    printf("Resultados de los primeros corredores por categoría:\n");
    for (int i = 0; i < MAX; i++) {
        if (primeros[i] == 0) {
            printf("Categoría %c: No hubo primer corredor\n", 'A' + i);
        } else {
            printf("Categoría %c: Primer corredor número %d\n", 'A' + i, primeros[i]);
        }
    }

}