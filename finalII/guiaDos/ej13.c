//DADA LAS EDADES Y ESTATURAS DE 6 ALUMNOS. SE PIDE DETERMINAR: LA EDAD
//PROMEDIO, LA ESTATURA PROMEDIO, LA CANTIDAD DE ALUMNOS MAYORES A 10 AÑOS Y
//LA CANTIDAD DE ALUMNOS QUE MIDEN MÁS DE 1.40 MT.

#include <stdio.h>

int main () {

    int edad1, edad2, edad3, edadProm, acumMayorDiez = 0;

    printf("Ingrese la edad 1: ");
    scanf("%d", &edad1);
    if (edad1 >= 10)
    {
        acumMayorDiez ++;
    }
    
    printf("Ingrese la edad 2: ");
    scanf("%d", &edad2);
    if (edad2 >= 10)
    {
        acumMayorDiez ++;
    }

    printf("Ingrese la edad 3: ");
    scanf("%d", &edad3);
        if (edad3 >= 10)
    {
        acumMayorDiez ++;
    }

    edadProm = (edad1 + edad2 + edad3) / 3;

    printf("El promedio de edad es de: %d \n", edadProm);
    printf("Los alumnos mayores a 10 son: %d", acumMayorDiez);

    return 0;
}