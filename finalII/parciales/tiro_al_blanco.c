#include <stdio.h>

#define TAM 3
#define MAX_TIRADORES 10

int calcularPuntaje(char posicion, int distancia);
void cargarDatos(int *codigo, char *posicion, int *distancia, int tam);
void mostrarResultados(int *codigo, char *posicion, int *distancia, int tam, int *puntajesAcumulados);
int obtenerGanador(int *puntajesAcumulados, int tam);

int calcularPuntaje(char posicion, int distancia) {
    if (posicion == 'C' || posicion == 'c') {
        return (distancia == 1) ? 100 : 200;
    } else if (posicion == 'M' || posicion == 'm') {
        return (distancia == 1) ? 50 : 100;
    } else if (posicion == 'B' || posicion == 'b') {
        return (distancia == 1) ? 10 : 20;
    } else if (posicion == 'F' || posicion == 'f') {
        return (distancia == 1) ? -10 : -20;
    }
    return 0; 
}

void cargarDatos(int *codigo, char *posicion, int *distancia, int tam) {
    printf("\nIngrese los valores para los tres vectores:\n");
    for (int i = 0; i < tam; i++) {
        printf("Ingrese el codigo del tirador: ");
        scanf("%d", &codigo[i]);
        printf("Ingrese la posicion en el blanco (C, M, B, F): ");
        scanf(" %c", &posicion[i]);  
        printf("Ingrese la distancia (1 o 2): ");
        scanf("%d", &distancia[i]);
    }
}

void mostrarResultados(int *codigo, char *posicion, int *distancia, int tam, int *puntajesAcumulados) {
    int puntaje;
    int totalPuntaje;
    
    printf("\nResultados:\n");
    for (int i = 0; i < tam; i++) {
        puntaje = calcularPuntaje(posicion[i], distancia[i]);
        totalPuntaje = puntajesAcumulados[i] + puntaje;
        puntajesAcumulados[i] = totalPuntaje;  // Acumula el puntaje del tirador

        printf("Tirador %d - Posición: %c - Distancia: %d - Puntaje: %d\n", 
               codigo[i], posicion[i], distancia[i], puntaje);
    }

    int ganador = obtenerGanador(puntajesAcumulados, tam);
    printf("\nEl tirador ganador es el código %d con un puntaje total de %d\n", 
           codigo[ganador], puntajesAcumulados[ganador]);
}

int obtenerGanador(int *puntajesAcumulados, int tam) {
    int maxPuntaje = puntajesAcumulados[0];
    int ganador = 0;
    
    for (int i = 1; i < tam; i++) {
        if (puntajesAcumulados[i] > maxPuntaje) {
            maxPuntaje = puntajesAcumulados[i];
            ganador = i;
        }
    }
    
    return ganador;
}

int main() {
    int opcion;
    int codigo[TAM], distancia[TAM];
    char posicion[TAM];
    int puntajesAcumulados[MAX_TIRADORES] = {0}; 
    
    do {
        printf("\nMenu:\n");
        printf("1. Ingresar datos de los tiros\n");
        printf("2. Mostrar resultados y tirador ganador\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                cargarDatos(codigo, posicion, distancia, TAM);
                break;
            case 2:
                mostrarResultados(codigo, posicion, distancia, TAM, puntajesAcumulados);
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
