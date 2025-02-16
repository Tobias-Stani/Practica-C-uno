//Escribir un programa que lea una matriz de números enteros y que devuelva la suma 
//de los elementos positivos de la matriz y la suma de los elementos negativos. 

#include <stdio.h>

#define max 2

int sumaPositivos(int mat[max][max]){
    int i, j, acumPositivos = 0;
    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++)
        {
            if (mat[i][j] >= 0)
            {
                acumPositivos += mat[i][j];
            }
            
        }
    }
    return acumPositivos;
}

int sumaNegativos(int mat[max][max]){
    int i, j, acumNegativos = 0;
    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++)
        {
            if (mat[i][j] <= 0)
            {
                acumNegativos += mat[i][j];
            }
            
        }
    }
    return acumNegativos;
}

int main() {
    int n[max][max], i, j, sumaPosi, sumaNega;

    for (i = 0; i < max; i++) {
        for (j = 0; j < max; j++)
        {
            printf("\nIngrese el vaalor de la posicion [%d][%d] ", i, j);
            scanf("%d", &n[i][j]);
        }
    }

    sumaPosi = sumaPositivos(n);
    printf("La suma de los positivos es: %d\n", sumaPosi);

    sumaNega = sumaNegativos(n);
    printf("La suma de los Negativos es: %d", sumaNega);


    return 0;
}