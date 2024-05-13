#include <stdio.h>

int main() {
    char band = 's';
    char nombreProducto[50];
    char tipoProdu;
    float importe;
    int cantUnidades;
    char descuento;

    while (band == 's') {
        printf("Nombre del producto: ");
        scanf("%s", nombreProducto);

        printf("Tipo de producto ('l' para lácteos, 'h' higiene, 'e' electrodomésticos, 'c' conservas): ");
        scanf(" %c", &tipoProdu);

        printf("Importe del producto sin IVA: ");
        scanf("%f", &importe);

        printf("Cantidad de unidades del producto: ");
        scanf("%d", &cantUnidades);

        printf("El producto posee descuento? (s/n): ");
        scanf(" %c", &descuento);

        printf("\nProducto ingresado:\n");
        printf("Nombre: %s\n", nombreProducto);

        if(descuento == 's') {
            printf("Importe sin IVA por el total de unidades: %.2f y su descuento es %.2f\n", importe * cantUnidades, importe * 0.10);
        } else {
            printf("Importe sin IVA por el total de unidades: %.2f\n", importe * cantUnidades);
        }

        printf("¿Desea ingresar más productos? (s/n): ");
        scanf(" %c", &band);
    }

    printf("Fin del ingreso de productos.\n");

    return 0;
}
