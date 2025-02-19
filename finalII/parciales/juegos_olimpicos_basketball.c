#include <stdio.h>

#define TAM 50  

// Funciones
void ingresarPuntajeContrario(int *puntajeContrario);
void ingresarDatosJugador(int *camiseta, char *posicion, int *tirosZona, int *tirosFueraZona, int *tirosLibres, int tam);
void evaluarPartido(int *camiseta, char *posicion, int *tirosZona, int *tirosFueraZona, int *tirosLibres, int tam, int puntajeContrario);

int calcularPuntajeJugador(int tirosZona, int tirosFueraZona, int tirosLibres) {
    return (tirosZona * 2) + (tirosFueraZona * 3) + (tirosLibres * 1);
}

int main() {
    int opcion;
    int camiseta[TAM], tirosZona[TAM], tirosFueraZona[TAM], tirosLibres[TAM];
    char posicion[TAM];
    int puntajeContrario;

    do {
        printf("\nMenu:\n");
        printf("1. Ingresar puntaje final del equipo contrario\n");
        printf("2. Ingresar datos de jugadores\n");
        printf("3. Evaluar partido\n");
        printf("4. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                ingresarPuntajeContrario(&puntajeContrario);
                break;
            case 2:
                ingresarDatosJugador(camiseta, posicion, tirosZona, tirosFueraZona, tirosLibres, TAM);
                break;
            case 3:
                evaluarPartido(camiseta, posicion, tirosZona, tirosFueraZona, tirosLibres, TAM, puntajeContrario);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while(opcion != 4);
    
    return 0;
}

// Función para ingresar el puntaje del equipo contrario
void ingresarPuntajeContrario(int *puntajeContrario) {
    printf("\nIngrese el puntaje final del equipo contrario: ");
    scanf("%d", puntajeContrario);
}

// Función para ingresar los datos de los jugadores
void ingresarDatosJugador(int *camiseta, char *posicion, int *tirosZona, int *tirosFueraZona, int *tirosLibres, int tam) {
    for(int i = 0; i < tam; i++) {
        printf("\nJugador %d:\n", i + 1);
        
        printf("Ingrese el numero de camiseta: ");
        scanf("%d", &camiseta[i]);

        printf("Ingrese la posicion (b - base, p - pilar, d - defensor): ");
        scanf(" %c", &posicion[i]);

        printf("Ingrese los tiros en zona anotados: ");
        scanf("%d", &tirosZona[i]);

        printf("Ingrese los tiros fuera de zona anotados: ");
        scanf("%d", &tirosFueraZona[i]);

        printf("Ingrese los tiros libres anotados: ");
        scanf("%d", &tirosLibres[i]);

        // Confirmar si desea seguir ingresando datos
        char continuar;
        printf("\n¿Desea continuar ingresando datos de jugadores? (s/n): ");
        scanf(" %c", &continuar);
        if (continuar != 's') {
            break;
        }
    }
}

void evaluarPartido(int *camiseta, char *posicion, int *tirosZona, int *tirosFueraZona, int *tirosLibres, int tam, int puntajeContrario) {
    int totalPuntajeSeleccion = 0;
    int maxPuntaje = -1;
    int camisetaMayorPuntaje;
    int contadorBase = 0, contadorPilar = 0, contadorDefensor = 0;
    
    for (int i = 0; i < tam; i++) {
        int puntajeJugador = calcularPuntajeJugador(tirosZona[i], tirosFueraZona[i], tirosLibres[i]);
        
        // Sumar puntaje al total de la selección
        totalPuntajeSeleccion += puntajeJugador;

        // Encontrar el jugador con el mayor puntaje
        if (puntajeJugador > maxPuntaje) {
            maxPuntaje = puntajeJugador;
            camisetaMayorPuntaje = camiseta[i];
        }

        // Contabilizar la cantidad de jugadores por posición
        if (posicion[i] == 'b') {
            contadorBase++;
        } else if (posicion[i] == 'p') {
            contadorPilar++;
        } else if (posicion[i] == 'd') {
            contadorDefensor++;
        }
    }
    
    printf("\nEstadísticas del partido:\n");
    printf("Cantidad de bases: %d\n", contadorBase);
    printf("Cantidad de pilares: %d\n", contadorPilar);
    printf("Cantidad de defensores: %d\n", contadorDefensor);
    printf("Jugador con mayor puntaje: Camiseta %d con %d puntos\n", camisetaMayorPuntaje, maxPuntaje);
    printf("Puntaje total de la selección argentina: %d\n", totalPuntajeSeleccion);
    
    // Comparar el puntaje total de la selección con el equipo contrario
    if (totalPuntajeSeleccion > puntajeContrario) {
        printf("¡La selección argentina ganó el partido!\n");
    } else if (totalPuntajeSeleccion < puntajeContrario) {
        printf("La selección argentina perdió el partido.\n");
    } else {
        printf("El partido terminó en empate.\n");
    }
}
