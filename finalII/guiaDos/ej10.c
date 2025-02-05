//EN UNA OLIMPIADA DE TIRO AL BLANCO SE LLEGA A UN ACUERDO ENTRE LOS
//PARTICIPANTES PARA QUE EL PUNTAJE OBTENIDO SEA CALCULADO EN BASE AL PUNTAJE
//ORIGINAL (0 A 10) ALCANZADO EN EL TIRO EFECTUADO, MULTIPLICADO POR UN FACTOR
//SEGÚN LA SIGUIENTE TABLA:
//PARA UN TIRO REALIZADO DETERMINE EL PUNTAJE ALCANZADO APLICANDO EL FACTOR
//QUE LE CORRESPONDE.

#include <stdio.h>

int main () {

    int tiro, calculo;

    printf("Ingrese el valor del tiro");
    scanf("%d", &tiro);

    if (tiro == 0)
    {
        printf("su puntaje es de 0.");

    } else if (tiro >= 1 && tiro <= 5)
    {
        calculo = tiro * 6;
        printf("Su puntaje es de: %d ", calculo);

    } else if (tiro >= 6 && tiro <= 8)
    {
        calculo = tiro * 9;
        printf("Su puntaje es de: %d ", calculo);

    }else if (tiro >= 9 && tiro <= 10)
    {
        calculo = tiro * 10;
        printf("Su puntaje es de: %d ", calculo);
    }

return 0;    

}