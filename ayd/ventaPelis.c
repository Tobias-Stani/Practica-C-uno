#include <stdio.h>

int stockPeli1 = 80, stockPeli2 = 80, stockPeli3 = 80;

int stockPelis(int peli1, int peli2, int peli3) {
    int estadoStock = 0; // Suponemos que hay suficiente stock

    if (peli1 > stockPeli1) {
        estadoStock = 1; // No hay suficiente stock de la película 1
    }
    if (peli2 > stockPeli2) {
        estadoStock = 1; // No hay suficiente stock de la película 2
    }
    if (peli3 > stockPeli3) {
        estadoStock = 1; // No hay suficiente stock de la película 3
    }

    return estadoStock; // Devolvemos el estado del stock
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}

int main() {
    char band = 's';
    int pelicula, contPeli1 = 0, unidadesCompra;

    while (band == 's') {
        printf("Seleccione la película que desea comprar (1-3)(solo puede comprar una unidad de cada una): ");
        scanf("%d", &pelicula);

        switch (pelicula) {
            case 1:
                printf("usted selecciono la peli 1 para comprar");
                contPeli1++;
                stockPeli1--;
                break;
            case 2:
                printf("usted selecciono la peli 2 para comprar");
                stockPeli2--;
                break;
            case 3:
                printf("usted selecciono la peli 3 para comprar");
                stockPeli3--;
                break;
            default:
                printf("Opción no válida.\n");
                break;
        }


        printf("¿Desea comprar otra película? (s/n): ");
        scanf(" %c", &band);
    }

    // Verificar si hay suficiente stock antes de finalizar
    int estadoStock = stockPelis(0, 0, 0); // Aquí deberías pasar la cantidad deseada de cada película
    if (estadoStock == 0) {
        printf("¡Se han realizado todas las compras con éxito!\n");
    } else {
        printf("¡No hay suficiente stock para alguna de las películas!\n");
    }

    printf("Fin del programa.\n");

    return 0;
}
