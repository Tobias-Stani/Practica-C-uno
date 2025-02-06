#include <stdio.h>

int main() {
    int codigo, codigoMasCaro = 0, codigoMasBarato = 0;
    float precio, precioMasCaro = 0, precioMasBarato = 999999;  

    printf("Ingrese el código del artículo (0 para finalizar): ");
    scanf("%d", &codigo);

    if (codigo == 0) {
        printf("No se ingresaron productos.\n");
        return 0;  // Termina el programa si no hay datos
    }

    do {
        printf("Ingrese el precio del artículo: ");
        scanf("%f", &precio);

        // Comparar para el más caro
        if (precio > precioMasCaro) {
            precioMasCaro = precio;
            codigoMasCaro = codigo;
        }

        // Comparar para el más barato
        if (precio < precioMasBarato) {
            precioMasBarato = precio;
            codigoMasBarato = codigo;
        }

        printf("Ingrese el código del siguiente artículo (0 para finalizar): ");
        scanf("%d", &codigo);

    } while (codigo != 0);

    // Mostrar resultados
    printf("\nEl artículo más caro es el código %d con un precio de %.2f\n", codigoMasCaro, precioMasCaro);
    printf("El artículo más barato es el código %d con un precio de %.2f\n", codigoMasBarato, precioMasBarato);

    return 0;
}
