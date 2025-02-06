//DESARROLLE UN ALGORITMO QUE LE PERMITA DETERMINAR DE UNA LISTA DE
//NÚMEROS:
//a. CUANTOS ESTÁN ENTRE EL 50 Y EL 75, AMBOS INCLUSIVE.
//b. CUANTOS SON MAYORES DE 80.
//c. CUANTOS SON MENORES DE 30.
//EL ALGORITMO FINALIZA CUANDO SE INGRESA EL NÚMERO 0.

#include <stdio.h>

int main() {
    int num;
    int entre50y75 = 0, mayores80 = 0, menores30 = 0;  // Contadores

    printf("Ingrese números (0 para finalizar): \n");

    do {
        printf("Número: ");
        scanf("%d", &num);

        if (num >= 50 && num <= 75) {
            entre50y75++;
        }
        if (num > 80) {
            mayores80++;
        }
        if (num < 30 && num != 0) {  
            menores30++;
        }

    } while (num != 0);  // El bucle termina cuando se ingresa 0

    printf("\nResultados:\n");
    printf("Números entre 50 y 75: %d\n", entre50y75);
    printf("Números mayores a 80: %d\n", mayores80);
    printf("Números menores a 30: %d\n", menores30);

    return 0;
}
