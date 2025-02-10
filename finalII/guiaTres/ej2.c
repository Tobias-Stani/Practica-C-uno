//REALIZAR  UNA  FUNCIÓN  PARA  INGRESAR  DOS  NÚMEROS  Y  OTRA  PARA  MOSTRAR  POR 
//PANTALLA LOS VALORES INTERCAMBIANDO LAS VARIABLES. 

#include <stdio.h>

int ingresarNumero();
void mostrarNumeros(int a, int b);

int main() {
    int a, b;

    // Se asignan los valores ingresados a las variables
    a = ingresarNumero();
    b = ingresarNumero();
    
    mostrarNumeros(a, b);  // Mostramos los valores originales

    // Intercambio de valores usando variable auxiliar
    int temp = a;
    a = b;
    b = temp;

    printf("Valores intercambiados:\n");
    mostrarNumeros(a, b);

    return 0;
}


int ingresarNumero() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);
    return num;
}

void mostrarNumeros(int num1, int num2) {
    printf("Numero 1: %d\n", num1);
    printf("Numero 2: %d\n", num2);
}
