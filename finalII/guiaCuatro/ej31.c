//Dado un vector de 10 elementos ={1, 2, 3, 4, 4, 7, 8, 9, 5, 4}, escribir un programa en 
//C  (haciendo uso de puntero) que muestre las direcciones de memoria de cada elemento 
//del vector. 

#include <stdio.h>

#define MAX 20

int main() {

    int vector[] = {1, 2, 3, 4, 4, 7, 8, 9, 5, 4};

    int size = sizeof(vector) / sizeof(vector[0]);  

    for (int i = 0; i < size; i++) {
        printf("Elemento %d: Valor = %d, Dirección de memoria = %p\n", i, vector[i], (void*)&vector[i]);
    }

    return 0;
}
