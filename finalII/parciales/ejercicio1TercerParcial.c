#include <stdio.h>

#define JUGADORES 3
#define PARTIDOS 5
#define COLUMNAS (PARTIDOS + 1) 

void cargarDatos(int matriz[JUGADORES][COLUMNAS]) {
    for (int i = 0; i < JUGADORES; i++) {
        printf("\nJugador %d\n", i + 1);
        
        // Ingresar número de camiseta
        printf("Ingrese número de camiseta: ");
        scanf("%d", &matriz[i][0]);

        // Ingresar goles en cada partido
        for (int j = 1; j <= PARTIDOS; j++) {
            printf("Ingrese goles en partido %d: ", j);
            scanf("%d", &matriz[i][j]);
        }
    }
}

void mostrarDatos(int matriz[JUGADORES][COLUMNAS]) {
    printf("\n--- Datos Ingresados ---\n");
    printf("Camiseta | P1 | P2 | P3 | P4 | P5\n");
    printf("-----------------------------------\n");

    for (int i = 0; i < JUGADORES; i++) {
        printf("   %d    |", matriz[i][0]); // Número de camiseta
        for (int j = 1; j <= PARTIDOS; j++) {
            printf("  %d |", matriz[i][j]); // Goles en cada partido
        }
        printf("\n");
    }
}

int main() {
    int datos[JUGADORES][COLUMNAS];

    cargarDatos(datos);  /
    mostrarDatos(datos); 

    return 0;
}
