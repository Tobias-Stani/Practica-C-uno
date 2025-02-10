// DADA LA CANTIDAD DE HORAS TRABAJADAS, LA ANTIGÜEDAD, Y LA CATEGORÍA DEL 
//EMPLEADO. 
//a. SABIENDO QUE COBRA 50 PESOS POR CADA AÑO TRABAJADO Y QUE EL VALOR 
//DE LA HORA SEGÚN LA CATEGORÍA: CAT 1= 10, CAT 2= 20, CAT 3= 25, CAT 4= 30. 
//b. DETERMINAR SUELDO DEL EMPLEADO. 
//c. INFORMAR SI EL SUELDO SUPERA LOS 1000 PESOS. 
//EFECTUAR EL EJERCICIO CON AL MENOS 2 FUNCIONES: UNA PARA CALCULAR EL COBRO POR 
//ANTIGÜEDAD Y OTRA PARA CALCULAR EL COBRO POR HORAS.

#include <stdio.h>

int calcularSueldo(int horas, int antiguedad, int categoria);
void esMayor(int sueldo);

int main () {

    int horas, antiguedad, categoria, sueldo;

    printf("Ingrese las horas trabajadas: ");
    scanf("%d", &horas);

    printf("Ingrese la antiguedad: ");
    scanf("%d", &antiguedad);

    printf("Ingrese la categoria: CAT  ");
    scanf("%d", &categoria);

    sueldo = calcularSueldo(horas, antiguedad, categoria);

    printf("El sueldo es: %d\n", sueldo);

    esMayor(sueldo);

    return 0;

}

int calcularSueldo (int h, int a, int c) {

    int sueldo;

    if (c == 1)
    {
        sueldo = h * 10;
    } else if (c == 2)
    {
        sueldo = h * 20;
    } else if (c == 3)
    {
        sueldo = h * 25;

    } else if (c == 4)
    {
        sueldo = h * 30;

    }
    
    sueldo += a * 50;

    return sueldo;

}

void esMayor(int sueldo){

    if (sueldo > 1000)
    {
        printf("El sueldo supera los $1000");
    } 

}