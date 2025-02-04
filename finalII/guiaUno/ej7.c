// INGRESAR UN IMPORTE EN PESOS Y MOSTRAR EL 80%, 20% Y 15 % DE DICHO VALOR.

#include <stdio.h>

int main(){
    float monto;

    printf("Ingrese el monto en pesos: $");
    scanf("%f", &monto);

    printf("El 80%% es: %.2f | El 20%% es: %.2f | El 15%% es: %.2f ", monto * 0.80, monto * 0.20, monto * 0.15);
}