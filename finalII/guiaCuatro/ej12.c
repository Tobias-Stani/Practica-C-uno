//Una  compañía  inmobiliaria  tiene  25  vendedores.  Cada  operación  que  hace  un 
//vendedor se guarda con las siguientes informaciones: número del vendedor (int), nombre 
//del vendedor (20 char), monto de la venta (float). Estas informaciones se almacenarán 
//en tres vectores, y se deberá escribir un programa que calcule el total de ventas realizado

#include <stdio.h>

#define max 3 

void mostrarDatos(int nVendedor[], char nombre[][20], float monto[]){

    int i;

    printf("\n/// VENTAS REALIZADAS ///\n");
    for (i = 0; i < max; i++) {
        printf("Vendedor #%d: %s - Venta: $%.2f\n", nVendedor[i], nombre[i], monto[i]);
    }
}

int main() {
    int numeroVendedor[max], i;;
    float monto[max];
    char nombre[max][20];

    printf("Ingresos de las ventas: \n");
    for (i = 0; i < max; i++) {
        printf("Numero de vendedor: ");
        scanf("%d", &numeroVendedor[i]);

        printf("Nombre del vendedor: ");
        scanf("%s", nombre[i]);

        printf("Monto de la venta: $ ");
        scanf("%f", &monto[i]);
    }

    mostrarDatos(numeroVendedor, nombre, monto);


    return 0;
}
