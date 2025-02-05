//DADO UN NÚMERO VERIFICAR SI ES POSITIVO, NEGATIVO O NULO.

#include <stdio.h>

int main() {

    int n;

    printf("Ingrese el valor");
    scanf("%d", &n);

    if (n >= 0)
    {
        printf("El numero es positivo");
    } 
    else if (n < 0)
    {
        printf("Numero negativo");
    } else 
    {
        printf("Numero nulo");
    }
    
    
}