//DADA LA CANTIDAD DE HORAS TRABAJAS, LA ANTIGÜEDAD, Y LA CATEGORÍA DEL
//EMPLEADO, Y ADEMÁS SABEMOS QUE COBRA 650 PESOS POR CADA AÑO TRABAJADO Y
//QUE EL VALOR DE LA HORA SEGÚN LA CATEGORÍA ES: CAT 1= 100, CAT 2= 200, CAT 3=
//250, CAT 4= 300.
//a. DETERMINAR SUELDO DEL EMPLEADO.
//b. INFORMAR SI EL SUELDO SUPERA LOS 20000 PESOS.

#include <stdio.h>

int main () {

    int horas, antiguedad, categoria, sueldo, adicionalAntiguedad;

    printf("Ingrese el valor del tiro");
    scanf("%d", &horas);

    printf("Ingrese el valor del tiro");
    scanf("%d", &antiguedad);

    printf("Ingrese el valor del tiro");
    scanf("%d", &categoria);    

    if (categoria == 1)
    {
        adicionalAntiguedad = antiguedad * 650;
        sueldo = (horas * 100) + adicionalAntiguedad;

        if (sueldo >= 20000)
        {
            printf("El sueldo supera los 20mil.");
        }
        

    } else if (categoria == 2)
    {
        /* code */

    } else if (categoria == 3)
    {
        /* code */

    } else if (categoria == 4)
    {
        /* code */
        
    }
    
    
    
    

}