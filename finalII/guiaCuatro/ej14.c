//Escribir un programa que lea una matriz de 3 filas y 3 columnas de valores enteros. A 
//continuación, el programa debe pedir el número de una fila. El programa deberá 
//devolver el máximo de esa fila

#include <stdio.h>

#define max 2

void mostrarMatriz(int mat[max][max]){
    int i, j;
    printf("\nMatriz ingresada:\n");
    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++) {
            printf("%d\t", mat[i][j]); // Usamos "\t" para dar formato tipo tabla
        }
        printf("\n"); 
    }
}

int obtenerMaximoFila(int mat[max][max], int fila){
    int maximo = mat[fila][0];
    for (int j = 1; j < max; j++)
    {
        if (mat[fila][j] > maximo)
        {
            maximo = mat[fila][j];
        }
    }
    return maximo;
}

int main() {
    int n[max][max], i, j, filaSeleccionada, maximo;

    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++)
        {
            printf("\nIngrese el vaalor de la posicion [%d][%d] ", i, j);
            scanf("%d", &n[i][j]);
        }
    }

    mostrarMatriz(n);

    printf("\nIngrese el número de la fila (0 a %d) para obtener el máximo: ", max - 1);
    scanf("%d", &filaSeleccionada);

    maximo = obtenerMaximoFila(n, filaSeleccionada);
    printf("\nEl número máximo de la fila %d es: %d\n", filaSeleccionada, maximo);

    return 0;
}