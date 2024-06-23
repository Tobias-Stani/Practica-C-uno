//encontrar el maximo y el minimo de un vector y mostrarlo en pantalla.

#include <stdio.h>

#define MAX 5

int main () {

    int i, vector[MAX], max, min;

    for(i=0; i<MAX; i++){
        printf("ingrese los numeros del vector %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("los elementos del vector son: \n");
    for(i=0; i<MAX; i++){
        printf("%d ", vector[i]);
    }

    // Inicializar max y min con el primer elemento del vector
    max = vector[0];
    min = vector[0];

    for (i=0; i<MAX; i++){
        if (vector[i] > max){
        max=vector[i];
        }
    }

    for (i = 1; i < MAX; i++) {
        if (vector[i] < min) {
            min = vector[i];
        }
    }

    printf("el valor maximo es: %d \n", max);
    printf("el valor minimo es: %d \n", min);

}