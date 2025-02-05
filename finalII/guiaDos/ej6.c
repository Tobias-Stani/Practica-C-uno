//DESARROLLE UN ALGORITMO QUE PERMITA LEER UN VALOR CUALQUIER N Y DETERMINE
//SI DICHO NÚMERO ES PAR O IMPAR.

#include <stdio.h>

int main() {

    int n;

    printf("Ingrese el valor");
    scanf("%d", &n);

    if (n % 2 == 0)
    {
        printf("EL NUMERO ES PAR");
    } else {
        printf("EL NUMERO ES imPAR");
    }
    
    return 0;
}