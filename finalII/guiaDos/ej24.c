//UN NEGOCIO DE PERFUMERÍA EFECTÚA DESCUENTOS EN SUS VENTAS SEGÚN EL IMPORTE DE 
//ESTAS, CON LA SIGUIENTE ESCALA: 
//MENOR  A 50 PESOS EL 3.5% 
//ENTRE 50 Y 150 PESOS EL 10% 
//ENTRE 151 Y 300 PESOS EL 20% 
//MAYOR A 300 PESOS EL 25%
//CONFECCIONAR  UN  PROGRAMA  QUE SOLICITE  UN PRECIO  ORIGINAL  E  INFORME: EL  DESCUENTO 
//A  EFECTUAR Y  PRECIO  NETO A  COBRAR  CON  MENSAJES ACLARATORIOS.  SE  DEBE  CONTEMPLAR 
//QUE SE PUEDE INGRESAR VARIOS IMPORTES Y PARA FINALIZAR SE INGRESA UN VALOR NEGATIVO.  

#include <stdio.h>

int main () {

    float precio, descuento, precioFinal;

    do {
        printf("\nIngrese el precio del producto (negativo para finalizar): $");
        scanf("%f", &precio);

        if (precio < 0) {
            printf("Programa finalizado.\n");
            break;
        }

        // Determinar el descuento según el precio
        if (precio < 50) {
            descuento = precio * 0.035;
            printf("El descuento a efectuar es del 3.5%%.\n");
        } else if (precio >= 50 && precio <= 150) {
            descuento = precio * 0.10;
            printf("El descuento a efectuar es del 10%%.\n");
        } else if (precio >= 151 && precio <= 300) {
            descuento = precio * 0.20;
            printf("El descuento a efectuar es del 20%%.\n");
        } else { 
            descuento = precio * 0.25;
            printf("El descuento a efectuar es del 25%%.\n");
        }

        precioFinal = precio - descuento;
        printf("El precio neto a cobrar es: $%.2f\n", precioFinal);

    } while (precio >= 0);

    return 0;
}