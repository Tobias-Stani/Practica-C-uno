//Escribir un programa que ingrese una palabra y a continuación muestre la palabra y 
//la cantidad de letras que compone la palabra. 

#include <stdio.h>
#include <string.h>

#define MAX 20

void contadorLetras(char word[]) {
    int cantidadLetras = strlen(word); 
    printf("La palabra ingresada es: %s\n", word);
    printf("Cantidad de letras: %d\n", cantidadLetras);
}

int main() {
    char palabra[MAX];

    printf("Ingresa una palabra: ");
    scanf("%19s", palabra); // Se limita a 19 caracteres para evitar desbordamiento

    contadorLetras(palabra); 

    return 0;
}
