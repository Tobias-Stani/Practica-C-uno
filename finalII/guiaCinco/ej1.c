#include <stdio.h>

void suma (int *n1, int *n2){

    int suma = *n1 + *n2;
    printf("la suma da: %d", suma);

}


int main () {

    int num1 = 10;
    int num2 = 2;

    suma(&num1, &num2);

}