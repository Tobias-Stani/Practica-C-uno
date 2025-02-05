//DADOS LA CANTIDAD DE VARONES Y EL DE MUJERES DE UN CURSO, CALCULAR EL TOTAL
//DE ALUMNOS. SI EL TOTAL SUPERA LOS 35 ALUMNOS INFORMAR CURSO NUMEROSO.
//EN CASO CONTRARIO, CALCULAR E INFORMAR LO QUE SE DEBERÁ PAGAR PARA REALIZAR
//UNA SALIDA CON TODOS, SI CADA ALUMNO PAGA $55.-

#include <stdio.h>

int main() {

    int varones, mujeres, total; 

    printf("Ingrese la cantidad de alumnos varones: ");
    scanf("%d", &varones);

    printf("Ingrese la cantidad de alumnos mujeres: ");
    scanf("%d", &mujeres);

    total = varones + mujeres;

    if (total >= 35)
    {
        printf("curso NUMEROSO");
    } else {
        int calculo; 
        calculo = total * 55;
        printf("Si cada alumno paga $55 se debera pagar: $%d\n", calculo);
    }
    

}