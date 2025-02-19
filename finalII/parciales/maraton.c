#include <stdio.h>

#define TAM 10

void ingresarDatos(int *numero, char *categoria, int *numRegistros){
    int opcion;

    // Verifica que no se haya llegado al límite de registros
    if (*numRegistros >= TAM) {
        printf("\nNo se pueden ingresar más registros.\n");
        return;
    }

    do {   
        printf("\nIngrese el numero: ");
        scanf("%d", (numero + *numRegistros));
    
        printf("\nIngrese la categoria (A, B, C, D): ");
        scanf(" %c", (categoria + *numRegistros));

        printf("\nIngrese 1 para continuar: ");
        scanf("%d", &opcion);
        
    } while (opcion == 1 && *numRegistros < TAM);
    
    (*numRegistros)++;
}

void calculoGanadores(int *numero, char *categoria, int numRegistros){

    for (int i = 0; i < numRegistros; i++) {
        int esPrimero = 1;  // Suponemos que el registro actual es el primero
        int primerNumero = numero[i];  // Guardamos el primer número

        // Recorremos los registros anteriores para ver si ya aparece la misma categoría
        for (int j = 0; j < i; j++) {
            if (categoria[j] == categoria[i]) {
                esPrimero = 0;  // Si ya apareció la categoría, no es el primero
                break;
            }
        }

        if (esPrimero) {
            printf("Para la categoría '%c', el primer número es: %d\n", categoria[i], numero[i]);
        }
    }
}

int main() {
    int numero[TAM];
    char categoria [TAM];
    int opcion;
    int numRegistros = 0;

    do {

        printf("\n--- MENÚ ---\n");
        printf("1 - Ingresar datos de pedidos\n");
        printf("2 - Informar cotizaciones\n");
        printf("3 - Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);

        while (getchar() != '\n');

        switch (opcion) {
            case 1:
                ingresarDatos(numero, categoria, &numRegistros);
                break;
            case 2:
                calculoGanadores(numero, categoria, numRegistros);
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
