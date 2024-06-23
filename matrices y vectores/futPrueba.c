//cargar un vector de jugadores, goles y partidos y mostrar el jugador que mas goels hizo.

#include <stdio.h>

#define MAX 5

// Prototipos de las funciones
void cargarVectores(int camiseta[], int goles[], int partido[]);
void mostrarVectores(int camiseta[], int goles[], int partido[]);
void mostrarCamisetaMaxGoles(int camiseta[], int goles[]);

int main() {
    int camiseta[MAX], goles[MAX], partido[MAX];

    cargarVectores(camiseta, goles, partido);
    mostrarVectores(camiseta, goles, partido);
    mostrarCamisetaMaxGoles(camiseta, goles);

    return 0;
}

void cargarVectores(int camiseta[], int goles[], int partido[]) {
    int i;

    for(i = 0; i < MAX; i++) {
        printf("Ingrese el número de camiseta %d: ", i + 1);
        scanf("%d", &camiseta[i]);

        printf("Ingrese la cantidad de goles %d: ", i + 1);
        scanf("%d", &goles[i]);

        printf("Ingrese el partido %d: ", i + 1);
        scanf("%d", &partido[i]);
    }
}

void mostrarVectores(int camiseta[], int goles[], int partido[]) {
    int i;

    printf("\nLos elementos de los vectores son:\n");
    printf("Camiseta\tGoles\tPartido\n");
    for(i = 0; i < MAX; i++) {
        printf("%d\t\t%d\t%d\n", camiseta[i], goles[i], partido[i]);
    }
}

void mostrarCamisetaMaxGoles(int camiseta[], int goles[]) {
    int maxGoles = goles[0];
    int indiceMax = 0;
    for (int i = 1; i < MAX; i++) {
        if (goles[i] > maxGoles) {
            maxGoles = goles[i];
            indiceMax = i;
        }
    }
    printf("\nEl número de camiseta que hizo más goles es: %d con %d goles.\n", camiseta[indiceMax], maxGoles);
}