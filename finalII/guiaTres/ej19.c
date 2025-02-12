//  CREAR  UN  PROGRAMA  EN  C  QUE  PIDA  POR  PANTALLA  UN  NÚMERO  DEL 1  AL  10  Y 
//MEDIANTE UNA FUNCIÓN MUESTRE POR PANTALLA EL NÚMERO ESCRITO EN LETRAS.

#include <stdio.h>

void mostrarNumeroEnLetras(int numero);

int main() {
    int numero;

    printf("Ingrese un numero del 1 al 10: ");
    scanf("%d", &numero);

    if (numero >= 1 && numero <= 10) {
        mostrarNumeroEnLetras(numero);
    } else {
        printf("Error: El numero debe estar entre 1 y 10.\n");
    }

    return 0;
}

void mostrarNumeroEnLetras(int numero) {
    switch (numero) {
        case 1: printf("Uno\n"); break;
        case 2: printf("Dos\n"); break;
        case 3: printf("Tres\n"); break;
        case 4: printf("Cuatro\n"); break;
        case 5: printf("Cinco\n"); break;
        case 6: printf("Seis\n"); break;
        case 7: printf("Siete\n"); break;
        case 8: printf("Ocho\n"); break;
        case 9: printf("Nueve\n"); break;
        case 10: printf("Diez\n"); break;
        default: printf("Numero fuera de rango\n"); 
    }
}
