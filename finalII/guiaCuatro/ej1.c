//Rellene un array con los números pares comprendidos entre 1 y 100 y muéstrelos en 
//pantalla en orden ascendente.

#include <stdio.h>

int main () {

    int arr[50], index = 0;

    for (int i = 2; i <= 100; i+=2)
    {
        arr[index] = i;
        index++;
    }

    printf("Numeros pares en orden ascendente:\n");
    for (int i = 0; i < 50; i++)
    {
        printf("%d ", arr[i]);
    }
    

    printf("Numeros pares en orden descendente:\n");
    for (int i = 49; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    

}