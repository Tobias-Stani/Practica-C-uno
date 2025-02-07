//ESCRIBIR UN ALGORITMO PARA SUMAR LOS NÚMEROS ENTEROS DE 1 A 100 
//UTILIZANDO:  A)  ESTRUCTURA  FOR;  B)  ESTRUCTURA  MIENTRAS;  C)  ESTRUCTURA  HACER 
//MIENTRAS.


#include <stdio.h>

int main() {
    int sumaFor = 0, sumaWhile = 0, sumaDoWhile = 0;
    
    for (int i = 1; i <= 100; i++) {
        sumaFor += i;  
    }

    int iWhile = 1;
    while (iWhile <= 100) {
        sumaWhile += iWhile;  
        iWhile++;  
    }

    int iDoWhile = 1;
    do {
        sumaDoWhile += iDoWhile;  
        iDoWhile++;  
    } while (iDoWhile <= 100);


    printf("La suma de los números de 1 a 100 usando FOR es: %d\n", sumaFor);
    printf("La suma de los números de 1 a 100 usando WHILE es: %d\n", sumaWhile);
    printf("La suma de los números de 1 a 100 usando DO-WHILE es: %d\n", sumaDoWhile);
    
    return 0;
}
