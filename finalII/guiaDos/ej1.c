//DADA LA NOTA Y EL LEGAJO DE UN ALUMNO. INFORMAR EL LEGAJO Y SI LA NOTA ES
//SUPERIOR A 6.

#include <stdio.h>

int main () {
    int nota, legajo;

    printf("Ingrese el legajo del alumno: ");
    scanf("%d", &legajo);

    printf("Ingrese la nota del alumno: ");
    scanf("%d", &nota);

    if (nota >= 6)
    {            
        printf("El alumno con Legajo %d tiene una nota mayor a 6 \n", legajo);
    } else {
        printf("El alumno con Legajo %d NO TIENE LA NOTA SUFICIENTE \n", legajo);
    }
    
    
}