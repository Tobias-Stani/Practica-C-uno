//sumar elementos de un vector

#include <stdio.h>

#define MAX 5

int main () {

    int i, vector[MAX], suma = 0;

    for(i=0; i<MAX; i++){
        printf("ingrese los numeros del vector %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("los elementos del vector son: \n");
    for(i=0; i<MAX; i++){
        printf("%d ", vector[i]);
    }


    for(i=0; i<MAX; i++){
        suma += vector[i];
    }

    printf("\n la suma de los elementos es: %d\n", suma);
}