//DESARROLLE UN ALGORITMO PARA CALCULAR EL IMPORTE DE UNA VENTA EN UN
//SUPERMERCADO. EL USUARIO DEBE INGRESAR EL NOMBRE DEL PRODUCTO, EL PRECIO POR
//UNIDAD Y EL NÚMERO DE UNIDADES. EL PROGRAMA MOSTRARÁ POR PANTALLA EL
//NOMBRE DEL PRODUCTO, EL NÚMERO DE UNIDADES VENDIDAS Y EL PRECIO TOTAL.

#include <stdio.h>

int main(){

    char nombreProdu[30];
    float precioUni;
    int unidades;

    printf("Ingrese su nombre Del producto: ");
    scanf(" %s", nombreProdu);

    printf("Ingrese el precio por unidad: $");
    scanf("%f", &precioUni);

    printf("Ingrese la cantidad de unidades: ");
    scanf("%d", &unidades);

    float precioTotal = unidades * precioUni;

    printf("El nombre del producto que va a llevar el %s, se vendio un total de: %d y el precio total es de: $%.2f", 
    nombreProdu, unidades, precioTotal);

    return 0; 

}