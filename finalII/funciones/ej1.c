#include <stdio.h>

int sumar(int a, int b);

int main () {

    int n1, n2;
    printf("====Ingrese los numeros que desa sumar====\n");

    printf("ingrese n1: ");
    scanf("%d", &n1);

    printf("ingrese n2: ");
    scanf("%d", &n2);

    sumar(n1, n2);

    return 0;

}

int sumar (int a, int b){

    int suma;

    suma = a + b;

    printf("La suma da: %d", suma);

    return suma;
}