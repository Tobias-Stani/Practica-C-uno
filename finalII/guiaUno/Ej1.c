#include <stdio.h>


int main() {

    char nombre[30];
    int numCel;

        printf("Ingrese su nombre: ");
        scanf(" %s", nombre);

        printf("Ingrese el numero de celular");
        scanf("%d", &numCel);

        printf("El nombre ingresado es: %s\n", nombre);
        printf("El numero de celular ingresado es %d\n", numCel);

}


