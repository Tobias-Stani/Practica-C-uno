//ESCRIBIR UN ALGORITMO QUE PIDA UNA CANTIDAD EN PESOS ARGENTINOS Y LA
//CONVIERTA EN DÓLARES ESTADOUNIDENSES (1 DÓLAR ESTADOUNIDENSE = 15.40 PESOS
//ARGENTINOS).

#include <stdio.h>

int main () {

    float pesos, dolar = 15.40;

    printf("Ingrese la cantidad de pesos que desea convertir: ");
    scanf("%f", &pesos);

    printf("$%.2f pesos convertido a dolares es: USD%.2f", pesos, pesos / dolar);

}