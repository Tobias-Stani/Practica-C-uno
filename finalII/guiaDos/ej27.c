//SE  PONEN A  LA  VENTA  LAS  ENTRADAS  PARA  UN  PARTIDO  DE  FÚTBOL  INTERNACIONAL, 
//CUYO  PRECIO  DEPENDE  DE  LA TRIBUNA, ASÍ: TRIBUNA    NORTE Y  SUR  CUESTAN  250  PESOS, 
//TRIBUNA ORIENTE CUESTA  450 PESOS  Y TRIBUNA OCCIDENTE CUESTA  650 PESOS.  
//DISEÑE LA SOLUCIÓN EN UN PROGRAMA QUE CONTROLE LA VENTA DE DICHAS ENTRADAS A 
//FIN  DE  PODER  SABER  LA  CANTIDAD  DE  PERSONAS  QUE  ASISTEN  A  CADA  TRIBUNA,  LA 
//CANTIDAD TOTAL DE PERSONAS Y EL MONTO TOTAL RECAUDADO POR LA VENTA DE TODAS 
//LAS  ENTRADAS.  FINALIZA  LA  VENTA  DE  ENTRADAS  CUANDO  SE  INGRESA  UNA  VENTA  A 
//TRIBUNA  IGUAL A “ZZZ”. 

#include <stdio.h>
#include <string.h>

int main() {
    char tribuna[20];
    int totalPersonas = 0, norteSur = 0, oriente = 0, occidente = 0;
    float totalRecaudado = 0;

    printf("Ingrese la tribuna (Norte, Sur, Oriente, Occidente) o 'ZZZ' para finalizar: ");
    scanf("%s", tribuna);

    while (strcmp(tribuna, "ZZZ") != 0) {
        if (strcmp(tribuna, "Norte") == 0 || strcmp(tribuna, "Sur") == 0) {
            norteSur++;
            totalRecaudado += 250;
        } else if (strcmp(tribuna, "Oriente") == 0) {
            oriente++;
            totalRecaudado += 450;
        } else if (strcmp(tribuna, "Occidente") == 0) {
            occidente++;
            totalRecaudado += 650;
        } else {
            printf("Tribuna no válida. Intente de nuevo.\n");
        }

        totalPersonas = norteSur + oriente + occidente;

        printf("Ingrese la tribuna (Norte, Sur, Oriente, Occidente) o 'ZZZ' para finalizar: ");
        scanf("%s", tribuna);
    }

    // Mostrar resultados
    printf("\nCantidad de personas por tribuna:\n");
    printf("Norte/Sur: %d\n", norteSur);
    printf("Oriente: %d\n", oriente);
    printf("Occidente: %d\n", occidente);
    printf("Total de personas: %d\n", totalPersonas);
    printf("Total recaudado: $%.2f\n", totalRecaudado);

    return 0;
}
