//SE REALIZA UNA ENCUESTA ENTRE 100 PERSONAS QUE VOTAN POR LOS CANDIDATOS A
//O B. SE PIDE INFORMAR LOS PORCENTAJES OBTENIDOS POR CADA CANDIDATO.

#include <stdio.h>

int main() {
    int i, votosA = 0, votosB = 0;  
    char voto;

    printf("Encuesta: Vote por el candidato A o B (ingrese 'A' o 'B')\n");

    for (i = 0; i < 100; i++) {  // Iterar 100 veces
        printf("Persona %d - Ingrese su voto: ", i + 1);
        scanf(" %c", &voto);  // Espacio antes de %c para ignorar espacios en blanco

        // Contabilizar el voto
        if (voto == 'A' || voto == 'a') {
            votosA++;
        } else if (voto == 'B' || voto == 'b') {
            votosB++;
        } else {
            printf("Voto inválido. Intente nuevamente.\n");
            i--;  // Restar 1 al contador para que la persona vuelva a votar
        }
    }

    // Calcular porcentajes
    float porcentajeA = (votosA / 100.0) * 100;
    float porcentajeB = (votosB / 100.0) * 100;

    // Mostrar resultados
    printf("\nResultados:\n");
    printf("Candidato A: %.2f%% (%d votos)\n", porcentajeA, votosA);
    printf("Candidato B: %.2f%% (%d votos)\n", porcentajeB, votosB);

    return 0;
}
