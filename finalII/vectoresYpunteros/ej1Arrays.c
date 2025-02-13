//Sumar los elementos de un arreglo
#include <stdio.h>

int main() {

    int numeros[5], suma = 0, i;

    printf("Ingrese 5 numeros: \n");
    for (i = 0; i < 5; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    for (i = 0; i < 5; i++)
    {
        suma += numeros[i];
    }
    
    printf("La suma de los numeros es de: %d\n", suma);

    return 0;

}