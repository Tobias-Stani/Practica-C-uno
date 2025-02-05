//REALIZAR UN PROGRAMA QUE PIDA EL INGRESO DE 2 NÚMEROS Y LA OPERACIÓN A
//REALIZAR ENTRE ELLOS Y MUESTRE EL RESULTADO DE LA OPERACIÓN.

#include <stdio.h>

int main() {

    int n1, n2;
    char operacion;

    printf("Ingrese el valor: ");
    scanf("%d", &n1);

    printf("Ingrese el valor: ");
    scanf("%d", &n2);

    printf("Ingrese la operacion: ");
    scanf(" %c", &operacion);

    if (operacion == '*')
    {
        printf("El resultado de la multiplicacion es: %d", n1 * n2);
    } else if (operacion == '/')
    {
        printf("El resultado de la division es: %d", n1 / n2);
    }else if (operacion == '+')
    {
        printf("El resultado de la suma es: %d", n1 + n2);
    } else if (operacion == '-')
    {
        printf("El resultado de la resta es: %d", n1 - n2);
    }
    
    
    return 0;    

}