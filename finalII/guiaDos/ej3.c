//LEER TRES NÚMEROS Y MOSTRAR UN MENSAJE SI SE ENCUENTRAN EN ORDEN
//ASCENDENTE.

#include <stdio.h>

int main() {
    int num1, num2, num3;

    printf("Ingrese el primer número: ");
    scanf("%d", &num1);
    
    printf("Ingrese el segundo número: ");
    scanf("%d", &num2);
    
    printf("Ingrese el tercer número: ");
    scanf("%d", &num3);

    if (num1 < num2 && num2 < num3)
    {
        printf("Los numeros se encuentran ordenados en forma ascendente");
    } else {
        printf("Los numeros no se encuentran ordenados");
    }
    

    return 0; 

}