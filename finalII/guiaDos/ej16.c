//DESARROLLE UN DIAGRAMA DE FLUJO QUE PERMITA CALCULAR EL PROMEDIO DE LAS
//NOTAS DE UN CURSO. EL ALGORITMO TERMINA CUANDO SE INGRESA LA NOTA 0.

#include <stdio.h>

int main() {
    int nota, acum = 0, totalNota = 0;
    float promedio;  

    do {
        printf("Ingrese una nota (0 para salir): ");
        scanf("%d", &nota);

        if (nota != 0) {  // Evita contar el 0 en el promedio
            totalNota += nota;
            acum++;
        }
    } while (nota != 0);

    if (acum > 0) {  // Evita división por 0
        promedio = (float) totalNota / acum;  // Convertir a float para resultado correcto
        printf("El promedio de las notas es: %.2f\n", promedio);
    } else {
        printf("No se ingresaron notas válidas.\n");
    }

    return 0;
}