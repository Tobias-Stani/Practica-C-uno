// DESARROLLAR UN DIAGRAMA DE FLUJO PARA QUE SE INGRESE UNA TEMPERATURA EN
// GRADOS CENTÍGRADOS Y LUEGO PASARLA A GRADOS KELVIN Y A GRADOS FAHRENHEIT.

#include <stdio.h>

int main (){

    float temp;

    printf("Ingrese la temperatura: ");
    scanf("%f", &temp);

    printf("La temperatura ingresada es de %.0f, pasada a grados kelvin es de: %.2fK y en grados fahrenheit es de %.2f",
    temp, temp + 273.15, temp * 9/5 + 32 );

}