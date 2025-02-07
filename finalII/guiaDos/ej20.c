//-UNA EMPRESA TIENE 4 VENDEDORES. CADA VENDEDOR CUANDO REALIZA UNA VENTA 
//EMITE UNA FACTURA. SE PROCESAN LOS DATOS HASTA  QUE SE INGRESA UN NUMERO DE 
//FACTURA IGUAL 0.  LOS DATOS INGRESADOS DE LA FACTURA SON: Nº DE FACTURA, Nº DE 
//VENDEDOR, MONTO DE LA FACTURA. SE DESEA CALCULAR E INFORMAR: 
// 
//A.  CUANTAS FACTURAS EMITIÓ CADA VENDEDOR. 
//B.  TOTAL FACTURADO POR CADA VENDEDOR Y EL TOTAL FINAL ACUMULADO 
//DE LOS VENDEDORES.-UNA EMPRESA TIENE 4 VENDEDORES. CADA VENDEDOR CUANDO REALIZA UNA VENTA 
//EMITE UNA FACTURA. SE PROCESAN LOS DATOS HASTA  QUE SE INGRESA UN NUMERO DE 
//FACTURA IGUAL 0.  LOS DATOS INGRESADOS DE LA FACTURA SON: Nº DE FACTURA, Nº DE 
//VENDEDOR, MONTO DE LA FACTURA. SE DESEA CALCULAR E INFORMAR: 
// 
//A.  CUANTAS FACTURAS EMITIÓ CADA VENDEDOR. 
//B.  TOTAL FACTURADO POR CADA VENDEDOR Y EL TOTAL FINAL ACUMULADO 
//DE LOS VENDEDORES.

#include <stdio.h>

int main () {

    int vendedor1 = 0, vendedor2 = 0, vendedor3 = 0 , vendedor4 = 0;
    int numFactura, numero, numVendedor;
    float monto, totalMonto = 0;

    printf("Ingrese el Numero de factura: ");
    scanf("%d", &numFactura);

    while (numFactura != 0) {

        printf("Ingrese el numero de vendedor (del 1 al 4): ");
        scanf("%d", &numVendedor);
        
        if (numVendedor == 1)
        {
            vendedor1 ++;
        } else if (numVendedor == 2)
        {
            vendedor2 ++;
        } else if (numVendedor == 3)
        {
            vendedor3 ++;
        } else if (numVendedor == 4)
        {
            vendedor4 ++;
        }
        
        printf("Ingrese el monto de la factura: ");
        scanf("%f", &monto);

        totalMonto += monto;

        printf("Ingrese el Numero de factura (0 para finalizar): ");
        scanf("%d", &numFactura);
    } 

    printf("\nResumen:\n");
    printf("Vendedor 1 emitió un total de %d facturas.\n", vendedor1);
    printf("Vendedor 2 emitió un total de %d facturas.\n", vendedor2);
    printf("Vendedor 3 emitió un total de %d facturas.\n", vendedor3);
    printf("Vendedor 4 emitió un total de %d facturas.\n", vendedor4);
    printf("\n---------\n");
    
    printf("El total final acumulado es de: $%.2f", totalMonto);

}