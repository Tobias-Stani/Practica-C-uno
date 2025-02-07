//EN  UN  CAMPEONATO  INTER-COLEGIAL  SE  DESEA  CONOCER  LA  CATEGORÍA  A  LA  QUE 
//CORRESPONDE CADA PARTICIPANTE.  
//SE INGRESA EL NOMBRE Y LA EDAD DE CADA UNO DE ELLOS.  
// 
//EL PROGRAMA TERMINA CUANDO EL NOMBRE ES IGUAL A "ZZZ". 
//• CATEGORÍA INFANTIL, PARA LOS MENORES DE 11 AÑOS 
//• CATEGORÍA PUBER, ENTRE LOS 11 Y LOS 14 AÑOS 
//• CATEGORÍA JUVENIL, PARA LOS MAYORES DE 14 AÑOS 
// 
//INFORMAR NOMBRE Y CATEGORÍA.

#include <stdio.h>
#include <string.h> 

int main () {

    char nombre[15];
    int edad;

    printf("Ingrese el Nombre (zzz para finalizar): ");
    scanf("%s", nombre);

    while (strcmp(nombre, "zzz") !=0) {
        
        printf("Ingrese la edad: ");
        scanf("%d", &edad);

        if (edad < 11)
        {
            printf("El participante de nombre %s y %d anios es categoria INFANTIL\n", nombre, edad);
        } else if (edad >= 11 && edad <= 14 ) {
            printf("El participante de nombre %s y %d anios es categoria PUBER\n", nombre, edad);
        } else if (edad > 14)
        {
            printf("El participante de nombre %s y %d anios es categoria JUVENIL\n", nombre, edad);
        }

        printf("Ingrese el Nombre (zzz para finalizar): ");
        scanf("%s", nombre);
    } 

    return 0;

}