//Escribir un programa que lea una matriz de 4 filas y 3 columnas, la visualice por 
//pantalla y a continuación  encuentre el mayor y el menor elemento de la matriz y sus 
//posiciones.

#include <stdio.h>

#define max 2

void obtenerMaximo(int matriz[4][3], int *maximo, int *filaMax, int *colMax) {
    *maximo = matriz[0][0]; // Inicializamos con el primer elemento
    *filaMax = 0;
    *colMax = 0;    // La posición inicial es 0

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            if (matriz[i][j] > *maximo) { // Si encontramos un número mayor
                *maximo = matriz[i][j];   // Actualizamos el máximo
                *filaMax = i;  // Guardamos la fila
                *colMax = j;   // Guardamos la columna
            }
        }
    }
}

int main() {
    int matriz[4][3], i, j, maximo, filaMax, colMax;

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 3; j++)
        {
            printf("\nIngrese el vaalor de la posicion [%d][%d] ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    obtenerMaximo(matriz, &maximo, &filaMax, &colMax);
    printf("El número máximo en el array es: %d\n", maximo);
    printf("Se encuentra en la posicion: [%d] [%d]\n", filaMax, colMax);

    return 0;
}