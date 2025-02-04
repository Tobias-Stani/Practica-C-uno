//DADA UNA COMPRA DE 30 PC PARA UNA EMPRESA Y SABIENDO QUE CADA UNA
//CUESTA 11500 PESOS.
//SÉ QUE EL PROVEEDOR ME HACE UN 20% DE DESCUENTO.
//SÉ QUE EL ENVÍO ME COBRA UN 5% DEL TOTAL.
//SÉ QUE EL SEGURO DE TRASLADO ES 12% DEL TOTAL EL CUAL SE DEVUELVEN SI LOS
//EQUIPOS LLEGAN BIEN.
//OBTENER EL PRECIO SIN DESCUENTOS. EL PRECIO CON TODOS LOS DESCUENTOS SI
//TODAS LAS PC LLEGAN BIEN. EL PRECIO CON TODOS LOS DESCUENTOS SI LAS PC
//LLEGAN MAL. SOLAMENTE EL PRECIO DEL DESCUENTO, SOLAMENTE EL PRECIO DEL
//ENVÍO.

#include <stdio.h>

int main() {

    // Datos iniciales
    int totalPC = 30;
    int precio = 11500;
    int precioTotal, descuento, precioConDescuento;
    float costoEnvio, costoSeguro, precioFinalBien, precioFinalMal;

    // Precio total sin descuento
    precioTotal = totalPC * precio;
    printf("El precio total sin descuentos es: $%d\n", precioTotal);

    // Calcular el descuento (20% del precio total)
    descuento = precioTotal * 0.20;

    // Precio con el descuento aplicado
    precioConDescuento = precioTotal - descuento;

    printf("El precio con descuento del proveedor es: $%d\n", precioConDescuento);

    // Calcular el costo de envío (5% del precio con descuento)
    costoEnvio = precioConDescuento * 0.05;

    // Calcular el costo del seguro (12% del precio con descuento)
    costoSeguro = precioConDescuento * 0.12;

    // Precio total si las PCs llegan bien (se devuelve el seguro)
    precioFinalBien = precioConDescuento + costoEnvio;  // El seguro se devuelve

    // Precio total si las PCs llegan mal (no se devuelve el seguro)
    precioFinalMal = precioConDescuento + costoEnvio + costoSeguro;

    // Resultados
    printf("El precio con todos los descuentos si todas las PC llegan bien es: $%.2f\n", precioFinalBien);
    printf("El precio con todos los descuentos si las PC llegan mal es: $%.2f\n", precioFinalMal);
    printf("El precio del descuento aplicado es: $%d\n", descuento);
    printf("El precio del envío es: $%.2f\n", costoEnvio);

    return 0;
}
