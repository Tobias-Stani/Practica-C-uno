// DADA LA CANTIDAD DE HORAS TRABAJADAS, LA ANTIGÜEDAD, Y LA CATEGORÍA DEL 
//EMPLEADO. 
//a. SABIENDO QUE COBRA 50 PESOS POR CADA AÑO TRABAJADO Y QUE EL VALOR 
//DE LA HORA SEGÚN LA CATEGORÍA: CAT 1= 10, CAT 2= 20, CAT 3= 25, CAT 4= 30. 
//b. DETERMINAR SUELDO DEL EMPLEADO. 
//c. INFORMAR SI EL SUELDO SUPERA LOS 1000 PESOS. 
//EFECTUAR EL EJERCICIO CON AL MENOS 2 FUNCIONES: UNA PARA CALCULAR EL COBRO POR 
//ANTIGÜEDAD Y OTRA PARA CALCULAR EL COBRO POR HORAS.

#include <stdio.h>

void calcularSueldo(int horas, int antiguedad, int categoria);

int main () {

    int horas, antiguedad, categoria;

    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &horas);

    printf("Ingrese la antiguedad: ");
    scanf("%d", &antiguedad);

    printf("Ingrese la categoria: CAT  ");
    scanf("%d", &categoria);

    calcularSueldo(horas, antiguedad, categoria);

    return 0;

}

void calcularSueldo (int h, int a, int c) {

}