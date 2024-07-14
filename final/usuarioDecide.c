#include <stdio.h>
#include <stdlib.h>
#include <string.h> // Para usar strcmp

#define MAX 1

void limpiarPantalla();
void ();

int main() {
    char continuar = 's';

    while (continuar == 's') {

        printf("¿Desea continuar vendiendo entradas? (s/n): ");
        scanf(" %c", &continuar);

        limpiarPantalla();
    }

    return 0;
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void limpiarBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}