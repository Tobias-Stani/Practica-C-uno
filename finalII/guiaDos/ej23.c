//DETERMINE  EL  MENOR  VALOR  DE  5  NÚMEROS,  INDICANDO  ADEMÁS  A  QUÉ  ORDEN 
//PERTENECE.  CONSIDERE  QUE  EL  MENOR  VALOR  PUEDE  REPETIRSE.  POR  EJEMPLO:  SI  LOS 
//NÚMEROS  INGRESADOS  FUERAN:  14,  19,  14,  16,  15.  LOS  RESULTADOS  DEBEN  SER:  EL 
//MENOR VALOR INGRESADO FUE 14 Y CORRESPONDEN AL PRIMER NÚMERO, TERCER 
//NÚMERO.

#include <stdio.h>

int main () {

    int num, i, menor, primerNumero = 1, contador = 0;
    int posiciones[5];

    for (i = 0; i < 5; i++) {
        printf("Ingrese número %d: ", i + 1);
        scanf("%d", &num);

        if (primerNumero) {
            menor = num;
            contador = 1;
            posiciones[0] = i + 1; // Guardar la primera posición
            primerNumero = 0;
        } else if (num < menor) {
            menor = num;
            contador = 1; // Reiniciamos el contador
            posiciones[0] = i + 1; // Guardamos la nueva posición
        } else if (num == menor) {
            posiciones[contador] = i + 1; // Guardar la posición
            contador++; // Aumentamos el contador
        }
    }
    
    printf("\nEl menor valor ingresado fue %d y corresponde a la posición: ", menor);
    for (i = 0; i < contador; i++) {
        printf("%d", posiciones[i]);
        if (i < contador - 1) {
            printf(", ");
        }
    }
    printf(".\n");

    return 0;

}