//ESCRIBIR  UN  PROGRAMA  QUE  CALCULE  LA  POTENCIA  DE  UN  NÚMERO  INTRODUCIENDO  EL 
//NÚMERO BASE Y EL EXPONENTE. 
//EFECTUAR EL EJERCICIO CON UNA FUNCIÓN QUE RECIBA LA BASE Y EL EXPONENTE Y 
//DEVUELVA EL RESULTADO A LA FUNCIÓN PRINCIPAL DEL PROGRAMA.

#include <stdio.h>

int  calculadorPotencia(int base, int exponente);

int main () {

    int base, exponente;

    printf("Ingrese la base: ");
    scanf("%d", &base);

    printf("Ingrese el exponente: ");
    scanf("%d", &exponente);
    
    calculadorPotencia(base, exponente);

    return 0; 
}


int calculadorPotencia(int b, int e){

    int calculo = 1;  

    for (int i = 0; i < e; i++) { 
        calculo *= b;  
    }

    printf("El resultado de %d^%d es: %d\n", b, e, calculo);

    return calculo;

}

