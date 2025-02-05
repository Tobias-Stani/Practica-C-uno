//DADOS 2 NÚMEROS SI EL PRIMERO ES MAYOR QUE EL SEGUNDO RESTARLOS SINO
//MULTIPLICARLOS. INFORMAR EL RESULTADO.

#include <stdio.h>

int main () {

    int num1, num2;

    printf("Ingrese numero 1: ");
    scanf("%d", &num1);

    printf("Ingrese numero 2: ");
    scanf("%d", &num2);

    if (num1 > num2)
    {
        printf("Numero uno es mayor que numero dos y se van a restar y el resultado es: %d\n", num1 - num2);
    } else {
        printf("Numero uno es menor que numero dos y se van a restar dando el resultado de: %d\n", num1 * num2);
    }

    return 0;    

}