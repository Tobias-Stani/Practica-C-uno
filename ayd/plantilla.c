#include <stdio.h>
#include <string.h>

void limpiarPantalla();

int main() {
    char band = 's';

    while (band == 's') {

        printf("¿Desea ingresar más datos? (s/n): ");
        scanf(" %c", &band);

        limpiarPantalla();
    }

}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}
