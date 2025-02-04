//DESARROLLAR UN DIAGRAMA DE FLUJO PARA QUE PIDA 2 VALORES Y REALIZA EL CÁLCULO (A+B)*(A-B).

#include <stdio.h>

int main() {

    int a, b, calculo;

    printf("Ingrese numero a: ");
    scanf("%d", &a);

    printf("Ingrese numero b: ");
    scanf("%d", &b);

    calculo = (a + b) * (a - b);

    printf("El resultado del calculo es: %d", calculo);

    return 0;
}