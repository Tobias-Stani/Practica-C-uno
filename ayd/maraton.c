#include <stdio.h>
#include <stdlib.h>

#define MAX_CORREDORES 100

typedef struct {
    int numero;
    char categoria;
} Corredor;

void registrarCorredores(Corredor corredores[], int *cantidadCorredores) {
    char continuar = 's';
    
    while (continuar == 's' && *cantidadCorredores < MAX_CORREDORES) {
        printf("Ingrese el número de pechera del corredor que llegó a la meta: ");
        scanf("%d", &corredores[*cantidadCorredores].numero);
        
        printf("Ingrese la categoría del corredor (A-E): ");
        scanf(" %c", &corredores[*cantidadCorredores].categoria);
        
        (*cantidadCorredores)++;
        
        printf("¿Desea continuar registrando corredores? (s/n): ");
        scanf(" %c", &continuar);
    }
}

void calcularGanadores(Corredor corredores[], int cantidadCorredores) {
    char categorias[] = {'A', 'B', 'C', 'D', 'E'};
    int ganadores[5] = {0};
    
    for (int i = 0; i < cantidadCorredores; i++) {
        for (int j = 0; j < 5; j++) {
            if (corredores[i].categoria == categorias[j]) {
                if (ganadores[j] == 0) {
                    ganadores[j] = corredores[i].numero;
                }
            }
        }
    }
    
    for (int i = 0; i < 5; i++) {
        printf("Ganador de categoría %c: %d\n", categorias[i], ganadores[i]);
    }
}

int main() {
    Corredor corredores[MAX_CORREDORES];
    int cantidadCorredores = 0;
    int opcion;
    
    do {
        printf("\nMenú:\n");
        printf("1. Registrar corredores\n");
        printf("2. Calcular ganadores\n");
        printf("3. Salir\n");
        
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                registrarCorredores(corredores, &cantidadCorredores);
                break;
            case 2:
                calcularGanadores(corredores, cantidadCorredores);
                break;
            case 3:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Por favor, seleccione nuevamente.\n");
        }
    } while (opcion != 3);
    
    return 0;
}