// ESCRIBIR UN PROGRAMA QUE LEA EXACTAMENTE 3 NÚMEROS Y LUEGO ESCRIBA LA SUMA DE TODOS ELLOS.

#include <stdio.h>

int main() {

    int n1, n2, n3, suma;

    printf("ingrese Numero 1: ");
    scanf("%d", &n1);

    printf("ingrese Numero 2: ");
    scanf("%d", &n2);

    printf("ingrese Numero 3: ");
    scanf("%d", &n3);

    suma = n1 + n2 + n3;

    printf("La suma de los 3 numeros es: %d", suma);


}