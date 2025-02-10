//REALIZAR  UNA  FUNCIÓN  QUE  ME  PERMITA  ESTABLECER  SI  UN NÚMERO  ES  PAR  O  NO 
//UTILIZANDO FUNCIONES.

#include <stdio.h>

int esPar(int a);

int main () {

    int a;

    printf("Ingrese Numero: ");
    scanf("%d", &a);

    esPar(a);

    return 0;
}

int esPar(int n){

    if (n % 2 == 0) {
        printf("El número %d es PAR.\n", n);
    } else {
        printf("El número %d es IMPAR.\n", n);
    }

}