//ESCRIBIR UN ALGORITMO QUE SOLICITE UNA NOTA E IMPRIMA POR PANTALLA LA
//CALIFICACIÓN EN FORMATO “APROBÓ” O “NO APROBÓ” SEGÚN SI LA NOTA ES MAYOR O
//IGUAL QUE 7 O MENOR QUE 7.

#include <stdio.h>

int main() {

    int nota;

    printf("Ingrese la nota: ");
    scanf("%d", &nota);

    if (nota >= 7)
    {
        printf("APROBADO");
    } else {
        printf("DESAPROBADO");
    }
    

}