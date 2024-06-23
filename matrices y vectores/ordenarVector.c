//Ordeenar un vector

#include <stdio.h>

#define MAX 5

int main () {

    int i, j, vector[MAX], aux;

    for(i=0; i<MAX; i++){
        printf("ingrese los numeros del vector %d: ", i + 1);
        scanf("%d", &vector[i]);
    }

    printf("los elementos del vector son: \n");
    for(i=0; i<MAX; i++){
        printf("%d ", vector[i]);
    }
 
//ordenamiento burbuja ordenado de minimo a maximo

    for(i = 0; i < MAX - 1; i++){
        for(j=i+1; j < MAX; j++){
            if(vector[i] > vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j]= aux;
            }
        }
    }

    printf("los elementos ordenados son: \n");
    for(i=0; i<MAX; i++){
        printf("%d ", vector[i]);
    }

//ordenamiento burbuja ordenado de maximo a minimo

    for(i = 0; i < MAX - 1; i++){
        for(j=i+1; j < MAX; j++){
            if(vector[i] < vector[j]){
                aux = vector[i];
                vector[i] = vector[j];
                vector[j]= aux;
            }
        }
    }

    printf("los elementos ordenados son: \n");
    for(i=0; i<MAX; i++){
        printf("%d ", vector[i]);
    }

}