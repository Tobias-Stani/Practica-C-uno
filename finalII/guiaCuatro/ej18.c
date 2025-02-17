//Escribir un programa que lea del teclado dos cadenas, las muestre en pantalla  e 
//informe si las cadenas ingresadas son iguales o no.

#include <stdio.h>
#include <string.h>

#define max 20

void comparacion(char cadena1[max], char cadena2[max]){

    if (strcmp(cadena1, cadena2) == 0) {
        printf("Las cadenas son iguales: \n");
    } else {
        printf("las cadenas no son iguales\n");
    }

}

int main() {
    char palabra[max], cadena2[max]; 

    printf("Ingresa una palabra: ");
    scanf("%19s", palabra); // Se limita a 19 caracteres para evitar desbordamiento

    printf("Ingresa una palabra 2: ");
    scanf("%19s", cadena2);

    comparacion(palabra, cadena2);

    return 0;
}
