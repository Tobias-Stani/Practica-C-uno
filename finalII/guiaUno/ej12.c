// DADA UNA CANTIDAD EXPRESADA EN PIES, Y OTRA EN METROS. DETERMINAR LA
// SUMA PERO CONVERTIDA A PULGADAS, A YARDAS, A METROS Y A MILLAS POR SEPARADO.
// CONSIDERE LAS SIGUIENTES EQUIVALENCIAS:
// 1 MILLA = 1609 METROS, 1 PULGADA = 0.0254 METROS, 1 YARDA = 3 PIES, 1 PIE = 12
// PULGADAS.

#include <stdio.h>

int main () {
    float pies, metros;

    printf("Ingrese pies: ");
    scanf("%f", &pies);

    printf("Ingrese metros: ");
    scanf("%f", &metros);

    // Convertir a pulgadas
    printf("La suma de estos pero en pulgadas es de: %.2f\n", (metros / 0.0254) + (pies * 12));

    // Convertir a yardas
    printf("La suma de estos pero en yardas es de: %.2f\n", (metros / 0.9144) + (pies / 3));

    // Convertir a metros
    printf("La suma de estos pero en metros es de: %.2f\n", metros + (pies * 0.3048));

    // Convertir a millas
    printf("La suma de estos pero en millas es de: %.6f\n", (metros / 1609) + (pies * 0.000189394));

    return 0;
}