#include <stdio.h>
#include <stdlib.h>

#define MAX 1

void limpiarPantalla();

int main() {

    char continuar = 's';
    
    while (continuar == 's' ) {
        
        printf("¿Desea continuar registrando corredores? (s/n): ");
        scanf(" %c", &continuar);
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