//INGRESAR TRES VALORES AMBIENTALES DE TEMPERATURAS Y CALCULAR E
//INFORMAR LA SUMA Y EL PROMEDIO DE DICHOS VALORES.

#include <stdio.h>

int main () {

    float temp1, temp2, temp3;

    printf("Ingrese el valor de la temperatura 1: ");
    scanf("%f", &temp1);
    
    printf("Ingrese el valor de la temperatura 2: ");
    scanf("%f", &temp2);
    
    printf("Ingrese el valor de la temperatura 3: ");
    scanf("%f", &temp3); 

    printf("La suma total de las temperaturas es de %.2f", temp1 + temp2 + temp3);
    printf("El promedio total de las temperaturas es de %.2f", (temp1 + temp2 + temp3) / 3);

    return 0;

}