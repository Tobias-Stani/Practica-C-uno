//DESARROLLE UN ALGORITMO QUE PERMITA DETERMINAR EL ÁREA Y VOLUMEN DE UN
//CILINDRO DADO SU RADIO Y SU ALTURA.

#include <stdio.h>

int main () {
    float radio, altura, area, volumen;

    printf("Ingrese el radio: ");
    scanf("%f", &radio);

    printf("Ingrese el altura: ");
    scanf("%f", &altura);

    area = 2 * 3.14159 * radio * altura;
    volumen = 3.14159 * radio * radio * altura;

    printf("El área lateral del cilindro es: %.2f\n", area);
    printf("El volumen del cilindro es: %.2f\n", volumen);

}