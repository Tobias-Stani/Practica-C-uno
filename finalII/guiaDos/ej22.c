//CREAR  UN  PROGRAMA  PARA  CALCULAR  EL  SALARIO  SEMANAL  DE  UNOS  EMPLEADOS A 
//LOS  QUE  SE  LES  PAGA  250  PESOS  POR  HORA  SI  ÉSTAS  NO  SUPERAN  LAS  35  HORAS.  CADA 
//HORA POR ENCIMA DE 35 SE CONSIDERARÁ EXTRA Y SE PAGA  A  85 PESOS. 
//EL  PROGRAMA  PIDE  LAS  HORAS  DEL  TRABAJADOR  Y  DEVUELVE  EL  SALARIO  QUE  SE  LE 
//DEBE PAGAR. 
//ADEMÁS  EL  PROGRAMA  DEBE  PREGUNTAR  SI  DESEAMOS  CALCULAR  OTRO  SALARIO,  SI  ES 
//ASÍ EL PROGRAMA SE VUELVE A REPETIR 

#include <stdio.h>

int main () {

    char flag;
    int horasTrabajadas, sueldo;

    do
    {
    
        printf("ingrese las horas trabajadas: ");
        scanf("%d", &horasTrabajadas);
    
        if(horasTrabajadas < 35) {
    
            sueldo = horasTrabajadas * 250;
    
        } else if (horasTrabajadas > 35)
        {
            int horasExtra = horasTrabajadas - 35;
            sueldo = (35 * 250) + (horasExtra * 85);
        }
    
        printf("El sueldo calculado es de $%d\n", sueldo);

        printf("Desea calcular otro sueldo? (s/n): ");
        scanf(" %c", &flag);

    } while (flag == 's'); 

    return 0;
}