// CREAR UN PROGRAMA PARA CALCULAR EL SALARIO SEMANAL DE UNOS EMPLEADOS A LOS 
//QUE SE  LES  PAGA  50 PESOS  POR HORA SI  ÉSTAS  NO SUPERAN  LAS  35 HORAS.  CADA HORA POR 
//ENCIMA DE 35 SE CONSIDERARÁ EXTRA Y SE PAGA A 75 PESOS. 
//EL  PROGRAMA  PIDE  LAS  HORAS  DEL  TRABAJADOR  Y  DEVUELVE  EL  SALARIO  QUE  SE  LE  DEBE 
//PAGAR. 
//ADEMÁS  EL  PROGRAMA  DEBE  PREGUNTAR  SI  DESEAMOS  CALCULAR  OTRO  SALARIO,  SI  ES ASÍ 
//EL PROGRAMA SE VUELVE A REPETIR 
//EFECTUAR EL EJERCICIO CON UNA FUNCIÓN QUE CALCULE EL SALARIO.

#include <stdio.h>

int calcularSalario(int horas);

int main () {

    int horas, sueldo, condition;

    do
    {
        printf("Ingrese las horas trabajadas: ");
        scanf("%d", &horas);

        sueldo = calcularSalario(horas);

        printf("El sueldo es de : $%d\n", sueldo);
        printf("Desea calcular otro sueldo? (1 si / 2 no) = ");
        scanf("%d", &condition);

    } while (condition == 1);
    
}

int calcularSalario(int h){

    int sueldo;

    if (h <= 35)
    {
        sueldo = h * 50;
    } else if (h > 35)
    {
        sueldo = (35 * 50) + ((h - 35) * 75);
    }
    
  return sueldo;  

}