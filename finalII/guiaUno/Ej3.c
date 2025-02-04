// ESCRIBIR UN ALGORITMO EN EL CUAL SE INGRESAN DOS VARIABLES A Y B. REALICE LA
//SUMA, LA RESTA, LA DIVISIÓN Y LA MULTIPLICACIÓN DE A CON B. MUESTRE LOS CUATRO
//RESULTADOS POR PANTALLA. LUEGO INTERCAMBIE EL VALOR DE LAS DOS VARIABLES Y
//MOSTRAR LOS VALORES INTERCAMBIADOS.

#include <stdio.h>

int main(){

    int a, b, sum, res, div, mul, temp;

    printf("Ingrese el numero A: ");
    scanf("%d", &a);

    printf("Ingrese el numero B: ");
    scanf("%d", &b);

    sum = a + b;
    res = a - b;
    div = a / b;
    mul = a * b;

    printf("El valor de la suma es: %d\n El valor de la resta es: %d\n El valor de la division es: %d\n EL valor de la multiplicacion es: %d\n", sum, res, div, mul);

    printf("///////////////////////// con valores invertidos //////////////////// \n");

    temp = a;
    a = b;
    b = temp;


    sum = a + b;
    res = a - b;
    div = a / b;
    mul = a * b;

    printf("El valor de la suma es: %d\n El valor de la resta es: %d\n El valor de la division es: %d\n EL valor de la multiplicacion es: %d\n", sum, res, div, mul);


}