// DESARROLLE  UN  ALGORITMO  QUE  PERMITA  LEER  UN  VALOR  CUALQUIER  N  Y  ESCRIBA  SI 
//DICHO NÚMERO ES PAR O IMPAR. 
//EFECTUAR EL EJERCICIO UTILIZANDO UNA FUNCIÓN PARA DETERMINAR SI EL NÚMERO ES PAR 
//O NO.

#include <stdio.h>

int esPar(int n);

int main () {

    int n, par;

    printf("Ingrese el numero: ");
    scanf("%d", &n);

    par = esPar(n);

    if (par == 1)
    {
        printf("El numero es PAR\n");
    } else{
        printf("El numero es IMPAR\n3");
    }

    return 0; 

}

int esPar(int num){

    if (num % 2 == 0)
    {
        return 1;
    } else {
        return 0; 
    }
    
}