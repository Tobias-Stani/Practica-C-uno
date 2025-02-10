//ESCRIBIR  UNA  FUNCIÓN  LLAMADA  "EDADES"  QUE  RECIBA  2  EDADES  Y  DECIR  CUÁL  DE 
//ELLAS ES LA MAYOR Y CUANTO LE FALTA A LA MENOR PARA LLEGAR A LA EDAD MAYOR. 

#include <stdio.h>

void edades(int edad1, int edad2);

int main () {

    int edad1, edad2;

    printf("Ingrese edad 1: ");
    scanf("%d", &edad1);

    printf("Ingrese edad 2: ");
    scanf("%d", &edad2);

    edades(edad1, edad2);

    return 0;

}

void edades (int a, int b) {

    int faltante;

    if (a > b)
    {
        printf("La edad 1 es mayor\n");
        faltante = a - b;
        printf("Le falta para llegar a la edad mayor: %d", faltante);

    } else if (a < b)
    {
        printf("La edad 2 es mayor\n");
        faltante = b - a;
        printf("Le falta para llegar a la edad mayor: %d", faltante);
    } else {
        printf("Las edades son iguales");
    }

}