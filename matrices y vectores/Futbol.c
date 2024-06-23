#include <stdio.h>

#define MAX_JUGADORES 2
#define MAX_PARTIDOS 2

// Prototipos de las funciones
void cargarGoles(int goles[MAX_JUGADORES][MAX_PARTIDOS]);
void mostrarGoles(int goles[MAX_JUGADORES][MAX_PARTIDOS]);
void mostrarRanking(int goles[MAX_JUGADORES][MAX_PARTIDOS]);

int main() {
    int goles[MAX_JUGADORES][MAX_PARTIDOS] = {0};

    cargarGoles(goles);
    mostrarGoles(goles);
    mostrarRanking(goles);

    return 0;
}

void cargarGoles(int goles[MAX_JUGADORES][MAX_PARTIDOS]) {
    int camiseta, partido, cantidadGoles;
    char continuar = 's';

    while (continuar == 's') {
        printf("Ingrese el número de camiseta (1-5): ");
        scanf("%d", &camiseta);

        printf("Ingrese el número de partido (1-5): ");
        scanf("%d", &partido);

        printf("Ingrese la cantidad de goles: ");
        scanf("%d", &cantidadGoles);

        goles[camiseta - 1][partido - 1] = cantidadGoles;

        printf("¿Desea ingresar otro dato? (s/n): ");
        scanf(" %c", &continuar);
    }
}

void mostrarGoles(int goles[MAX_JUGADORES][MAX_PARTIDOS]) {
    printf("\nCantidad de goles por camiseta y partido:\n\n");
    printf("Partido\t");
    for (int j = 1; j <= MAX_PARTIDOS; j++) {
        printf("%d\t", j);
    }
    printf("Total Goles\n");

    for (int i = 0; i < MAX_JUGADORES; i++) {
        int totalGoles = 0;
        printf("Camiseta %d\t", i + 1);
        for (int j = 0; j < MAX_PARTIDOS; j++) {
            printf("%d\t", goles[i][j]);
            totalGoles += goles[i][j];
        }
        printf("%d\n", totalGoles);
    }
}

void mostrarRanking(int goles[MAX_JUGADORES][MAX_PARTIDOS]) {
    int totalGoles[MAX_JUGADORES] = {0};

    for (int i = 0; i < MAX_JUGADORES; i++) {
        for (int j = 0; j < MAX_PARTIDOS; j++) {
            totalGoles[i] += goles[i][j];
        }
    }

    printf("\nRanking de jugadores por cantidad de goles:\n");
    for (int i = 0; i < MAX_JUGADORES; i++) {
        int maxIndex = 0;
        for (int j = 1; j < MAX_JUGADORES; j++) {
            if (totalGoles[j] > totalGoles[maxIndex]) {
                maxIndex = j;
            }
        }
        printf("Camiseta %d\tcon %d goles\n", maxIndex + 1, totalGoles[maxIndex]);
        totalGoles[maxIndex] = -1; // Marcamos el máximo actual como visitado
    }
}
