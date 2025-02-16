//Dado  un  vector  de  20  números.  Hallar  el  promedio  de  los  elementos  positivos  y  el 
//porcentaje de los negativos.

#include <stdio.h>

#define max 6  // Definir max como 6 sin igual ni punto y coma

void obtenerMaximo(int arr[], int tam) {
    int positivos = 0, negativos = 0, contadorPositivos = 0, promedio;
    float porcentaje;

    for (int i = 0; i < tam; i++) {
        if (arr[i] >= 0) {
            positivos += arr[i];
            contadorPositivos ++;
        } else {
            negativos ++;
        }
    }

    promedio = positivos / contadorPositivos;
    printf("El promedio de los positivos es: %d\n", promedio);

    porcentaje = (float) negativos / tam * 100;
    printf("El porcentaje de negativos es: %.2f%%\n", porcentaje);

}

int main() {
    int numeros[max], i;

    printf("Ingrese 6 numeros: \n");
    for (i = 0; i < max; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    obtenerMaximo(numeros, max);


    return 0;
}
