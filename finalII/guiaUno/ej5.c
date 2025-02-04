//ESCRIBIR UN PROGRAMA QUE CALCULE LA POTENCIA DE UN NÚMERO INTRODUCIENDO EL NÚMERO BASE Y EL EXPONENTE.

#include <stdio.h>

int main () {

    int num, exp, calculo = 1, i;

    printf("Ingrese el numero base: ");
    scanf("%d", &num);

    printf("Ingrese el Exponente: ");
    scanf("%d", &exp);

    for (i = 0; i < exp; i++) {
        calculo *= num;
    }

    printf("El resultado de %d^%d es: %d\n", num, exp, calculo);

    return 0; 
}