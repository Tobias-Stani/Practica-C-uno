#include <stdio.h>
#define PARTIDOS 3  // Número de partidos
#define JUGADORES 3  // Número de jugadores

void cargarDatos(int *matriz, int partidos, int jugadores);
void emitirReportes(int *matriz, int partidos, int jugadores);
int jugadorConMasGoles(int *matriz, int partidos, int jugadores);

int main() {
    int opcion;
    int goles[PARTIDOS][JUGADORES];
    
    do {
        printf("\nMenu:\n");
        printf("1. Cargar datos de goles\n");
        printf("2. Emitir reportes de goles\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                cargarDatos((int *)goles, PARTIDOS, JUGADORES);
                break;
            case 2:
                emitirReportes((int *)goles, PARTIDOS, JUGADORES);
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

void cargarDatos(int *matriz, int partidos, int jugadores) {
    printf("\nIngrese la cantidad de goles por jugador en cada partido:\n");
    for(int i = 0; i < partidos; i++) {
        for(int j = 0; j < jugadores; j++) {
            printf("Partido %d, Jugador %d: ", i + 1, j + 1);
            scanf("%d", (matriz + i * jugadores + j));  // Uso de aritmética de punteros
        }
    }
}

void emitirReportes(int *matriz, int partidos, int jugadores) {
    printf("\nReporte de goles:\n");
    for(int i = 0; i < partidos; i++) {
        printf("Partido %d:\n", i + 1);
        for(int j = 0; j < jugadores; j++) {
            printf("Jugador %d: %d goles\n", j + 1, *(matriz + i * jugadores + j));  // Uso de aritmética de punteros
        }
    }
    int mejorJugador = jugadorConMasGoles(matriz, partidos, jugadores);
    printf("\nEl jugador con más goles es el Jugador %d\n", mejorJugador + 1);
}

int jugadorConMasGoles(int *matriz, int partidos, int jugadores) {
    int totalGoles[JUGADORES] = {0};
    for(int i = 0; i < partidos; i++) {
        for(int j = 0; j < jugadores; j++) {
            totalGoles[j] += *(matriz + i * jugadores + j);
        }
    }
    int maxGoles = totalGoles[0], mejorJugador = 0;
    for(int j = 1; j < jugadores; j++) {
        if(totalGoles[j] > maxGoles) {
            maxGoles = totalGoles[j];
            mejorJugador = j;
        }
    }
    return mejorJugador;
}
