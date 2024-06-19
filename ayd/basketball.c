#include <stdio.h>

#define MAX_JUGADORES 50

void ingresarPuntajeContrario(int *puntajeContrario);
void ingresarDatosJugadores(int *numeros, char *posiciones, int *puntajes, int *tirosEnZona, int *tirosFueraZona, int *tirosLibres, int *numJugadores);
void evaluarPartido(int *numeros, char *posiciones, int *puntajes, int numJugadores, int puntajeContrario);
void limpiarPantalla();

int main() {
    int numeros[MAX_JUGADORES] = {0};
    char posiciones[MAX_JUGADORES] = {0};
    int tirosEnZona[MAX_JUGADORES] = {0};
    int tirosFueraZona[MAX_JUGADORES] = {0};
    int tirosLibres[MAX_JUGADORES] = {0};
    int puntajes[MAX_JUGADORES] = {0};
    int numJugadores = 0;
    int puntajeContrario = 0;
    int opcion;

    do {
        printf("Menu:\n");
        printf("1 - Ingresar puntaje final del equipo contrario\n");
        printf("2 - Ingresar datos de jugadores de la seleccion argentina\n");
        printf("3 - Evaluacion del partido\n");
        printf("4 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                ingresarPuntajeContrario(&puntajeContrario);
                break;
            case 2:
                ingresarDatosJugadores(numeros, posiciones, puntajes, tirosEnZona, tirosFueraZona, tirosLibres, &numJugadores);
                break;
            case 3:
                evaluarPartido(numeros, posiciones, puntajes, numJugadores, puntajeContrario);
                break;
            case 4:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente nuevamente.\n");
        }

        if (opcion != 4) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            getchar(); // Esperar a que el usuario presione Enter
            limpiarPantalla();
        }
    } while(opcion != 4);

    return 0;
}

void ingresarPuntajeContrario(int *puntajeContrario) {
    printf("Ingrese el puntaje final del equipo contrario: ");
    scanf("%d", puntajeContrario);
}

void ingresarDatosJugadores(int *numeros, char *posiciones, int *puntajes, int *tirosEnZona, int *tirosFueraZona, int *tirosLibres, int *numJugadores) {
    if (*numJugadores >= MAX_JUGADORES) {
        printf("Se ha alcanzado el maximo numero de jugadores permitidos.\n");
        return;
    }

    int numero;
    char posicion;
    int tirosZona, tirosFuera, tirosLib;

    printf("Ingrese el numero de camiseta del jugador: ");
    scanf("%d", &numero);

    printf("Ingrese la posicion en la cancha ('b' base, 'p' pilar, 'd' defensor): ");
    scanf(" %c", &posicion);

    printf("Ingrese la cantidad de tiros en zona anotados: ");
    scanf("%d", &tirosZona);

    printf("Ingrese la cantidad de tiros fuera de zona anotados: ");
    scanf("%d", &tirosFuera);

    printf("Ingrese la cantidad de tiros libres anotados: ");
    scanf("%d", &tirosLib);

    int puntaje = tirosZona * 2 + tirosFuera * 3 + tirosLib * 1;

    *(numeros + *numJugadores) = numero;
    *(posiciones + *numJugadores) = posicion;
    *(puntajes + *numJugadores) = puntaje;
    *(tirosEnZona + *numJugadores) = tirosZona;
    *(tirosFueraZona + *numJugadores) = tirosFuera;
    *(tirosLibres + *numJugadores) = tirosLib;

    (*numJugadores)++;

    printf("Datos del jugador ingresados exitosamente.\n");
}

void evaluarPartido(int *numeros, char *posiciones, int *puntajes, int numJugadores, int puntajeContrario) {
    int countBases = 0, countPilares = 0, countDefensores = 0;
    int mayorPuntaje = 0, camisetaMayorPuntaje = 0;
    int puntajeTotal = 0;

    for (int i = 0; i < numJugadores; i++) {
        puntajeTotal += *(puntajes + i);

        if (*(puntajes + i) > mayorPuntaje) {
            mayorPuntaje = *(puntajes + i);
            camisetaMayorPuntaje = *(numeros + i);
        }

        switch (*(posiciones + i)) {
            case 'b':
                countBases++;
                break;
            case 'p':
                countPilares++;
                break;
            case 'd':
                countDefensores++;
                break;
            default:
                printf("Posicion invalida para el jugador con camiseta %d\n", *(numeros + i));
        }
    }

    printf("Evaluacion del partido:\n");
    printf("Cantidad de jugadores por posicion:\n");
    printf("Bases: %d\n", countBases);
    printf("Pilares: %d\n", countPilares);
    printf("Defensores: %d\n", countDefensores);
    printf("El numero de camiseta que obtuvo el mayor puntaje es: %d\n", camisetaMayorPuntaje);
    printf("El puntaje total obtenido en el partido es: %d\n", puntajeTotal);

    if (puntajeTotal > puntajeContrario) {
        printf("La seleccion argentina gano el partido.\n");
    } else if (puntajeTotal < puntajeContrario) {
        printf("La seleccion argentina perdio el partido.\n");
    } else {
        printf("El partido termino en empate.\n");
    }
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}
