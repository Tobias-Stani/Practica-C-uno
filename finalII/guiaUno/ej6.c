//INGRESAR 3 NÚMEROS E IMPRIMIR EL DOBLE, EL TRIPLE Y LA MITAD DE CADA UNO.
 
#include <stdio.h>

int main(){

    float num1, num2, num3;

    printf("Ingrese numero 1: ");
    scanf("%f", &num1);

    printf("Ingrese numero 2: ");
    scanf("%f", &num2);

    printf("Ingrese numero 3: ");
    scanf("%f", &num3);

    printf("Para el numero %.2f: Doble= %.2f, Triple= %.2f, Mitad= %.2f\n", num1, num1 * 2, num1 * 3, num1 / 2);
    printf("Para el numero %.2f: Doble= %.2f, Triple= %.2f, Mitad= %.2f\n", num2, num2 * 2, num2 * 3, num2 / 2);
    printf("Para el numero %.2f: Doble= %.2f, Triple= %.2f, Mitad= %.2f\n", num3, num3 * 2, num3 * 3, num3 / 2);

    return 0;

}