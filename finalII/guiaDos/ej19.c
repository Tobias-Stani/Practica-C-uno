//CONSTRUIR UN PROGRAMA QUE PUEDA INGRESAR VARIOS NUMEROS ENTEROS, 
//DISTINTOS DE CERO, DE UNO POR VEZ. FINALIZA EL INGRESO DE LOS DATOS AL LLER UN 
//VALOR NULO. INFORMAR:    A) LA CANTIDAD DE VALORES INGRESADOS COMPRENDIDOS 
//ENTRE PI  Y  3PI.   B) EL MENOR VALOR INGRESADO. 

#include <stdio.h>

#define PI 3.1416  // Definir PI como constante

int main() {
    int numero, cantidadEntrePIy3PI = 0, menorValor;
    int primerNumero = 1;  // Variable para manejar el primer número ingresado

    printf("Ingrese un número entero (0 para finalizar): ");
    scanf("%d", &numero);

    while (numero != 0) {
        // Contar los números que están en el rango [PI, 3PI]
        if (numero >= PI && numero <= 3 * PI) {
            cantidadEntrePIy3PI++;
        }

        // Determinar el menor valor ingresado
        if (primerNumero) { 
            menorValor = numero;  // El primer número se guarda como menor inicial
            primerNumero = 0;
        } else if (numero < menorValor) {
            menorValor = numero;  // Si el número actual es menor, se actualiza
        }

        printf("Ingrese otro número entero (0 para finalizar): ");
        scanf("%d", &numero);
    }

    // Mostrar resultados si se ingresaron valores
    if (!primerNumero) {
        printf("\nA) Cantidad de valores entre PI y 3PI: %d\n", cantidadEntrePIy3PI);
        printf("B) El menor valor ingresado: %d\n", menorValor);
    } else {
        printf("\nNo se ingresaron valores válidos.\n");
    }

    return 0;
}
