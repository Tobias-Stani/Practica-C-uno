#include <stdio.h>
#include <string.h>

// Prototipo de función
int calculadorExpensas(char cat, char uso, char garaje);

int main() {
    char band = 's', tipoDepa, cochera, multa, uso;
    int montoMulta, totalPagar, contCatD = 0;

    while (band == 's') {
        printf("Ingrese el tipo de departamento ('p', 's', 'd' o 'm'): ");
        scanf(" %c", &tipoDepa);


        printf("¿Es uso profesional? (s/n): ");
        scanf(" %c", &uso);

        if(tipoDepa == 'd' && uso == 's'){
            contCatD ++;
        }

        printf("¿Tiene cochera? (s/n): ");
        scanf(" %c", &cochera);

        printf("¿Tiene multa? (s/n): ");
        scanf(" %c", &multa);

        // Verificar si hay multa
        if (multa == 's') {
            printf("Ingrese el monto de la multa: ");
            scanf("%d", &montoMulta);
        } else {
            // Si no hay multa, asignar un valor de 0 a montoMulta
            montoMulta = 0;
        }

        printf("El valor de las multas a pagar es de: %d\n", montoMulta);
        printf("El valor de la expensa es %d\n", calculadorExpensas(tipoDepa, uso, cochera));

        totalPagar = montoMulta + calculadorExpensas(tipoDepa, uso, cochera);

        printf("El valor total a pagar es de %d\n", totalPagar);

        printf("¿Desea ingresar más datos? (s/n): ");
        scanf(" %c", &band);

        limpiarPantalla();
    }

    printf("la cantidad de departamentos categoria 'd' y que son de uso profesional es de: %d\n", contCatD);

}

int calculadorExpensas(char cat, char uso, char garaje) {
    int expensa = 0;

    // Valor Base según la camtegoría
    if(cat == 'p') {
        expensa = 4000;
    } else if(cat == 's') {
        expensa = 3000;
    } else if(cat == 'd') {
        expensa = 2000;
    } else if(cat == 'm') {
        expensa = 1000;
    } else {
        printf("Categoría no válida.\n");
        return -1; // Valor de retorno para indicar un error
    }

    // Adicional Profesional
    if(uso == 's') {
        expensa += 2500;
    }

    // Adicional Cochera
    if(garaje == 's') {
        expensa += 1500;
    }

    return expensa;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}
