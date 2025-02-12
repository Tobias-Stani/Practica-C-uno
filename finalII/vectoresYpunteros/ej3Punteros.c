//Sumar dos números usando punteros

#include <stdio.h>

void suma(int *a, int *b){
    printf("La suma de los 2 punteros da: %d\n", *a + *b);
} 

int main () {

    int num = 10, num2 = 11;
    suma(&num, &num2);
}