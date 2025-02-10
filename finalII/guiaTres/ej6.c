//REALIZAR  UNA  FUNCIÓN  LLAMADA  NEGATIVO,  QUE  TOMA  UN  NÚMERO  ENTERO  COMO 
//PARÁMETRO, Y DEVUELVE 1 SI ES NEGATIVO O 0 SI NO LO ES.  

#include <stdio.h>

void negativo(int n);

int main () {

    int n;

    printf("Ingrese un numero: ");
    scanf("%d", &n);

    negativo(n);

}

void negativo (int a) {

    if (a >= 0)
    {
        printf("El numero es POSITIVO");
    } else if (a < 0)
    {
        printf("El numero es NEGATIVO");
    }

}