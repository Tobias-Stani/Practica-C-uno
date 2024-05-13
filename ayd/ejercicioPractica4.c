#include <stdio.h>
#include <string.h>

int potenciar(int cali, int coop, int ana) {
    if (cali >= 4 && coop >= 4 && ana >= 4) {
        return 1;
    } else {
        return 0;
    }
}

void capacidad(int cod, int resultado_potenciar) {
    if (resultado_potenciar == 1) {
        printf("El empleado de código %d tiene potencial.\n", cod);
    } else {
        printf("El empleado de código %d NO tiene potencial.\n", cod);
    }
}

int main() {
    char band = 's', profesional[3];

    int codEmpleado, diasTrabajados, calidad, cooperacion, analisis, resultado_potenciar, 
    contadorFueraNivel = 0, maxDiasTrabajados = 0, codEmpleadoMaxDias = 0;

    float promedioFueraNivel;

    while (band == 's') {
        printf("Codigo del empleado: ");
        scanf("%d", &codEmpleado);

        printf("Dias trabajados: ");
        scanf("%d", &diasTrabajados);

        if (diasTrabajados > maxDiasTrabajados) {
            maxDiasTrabajados = diasTrabajados;
            codEmpleadoMaxDias = codEmpleado;
        }

        printf("Es profesional? (si/no): ");
        scanf("%s", profesional);

        printf("Calidad y cantidad de trabajo: ");
        scanf("%d", &calidad);

        printf("Cooperacion: ");
        scanf("%d", &cooperacion);

        printf("Capacidad de analisis: ");
        scanf("%d", &analisis);

        // Calcula el resultado del potencial llamando a la función potenciar()
        resultado_potenciar = potenciar(calidad, cooperacion, analisis);

        // Llama a la función capacidad() para mostrar si el empleado tiene potencial o no
        capacidad(codEmpleado, resultado_potenciar);

        promedioFueraNivel = (calidad + cooperacion + analisis) / 3.0;

        // Verifica si el empleado es profesional y si su promedio está fuera de nivel
        if (strcmp(profesional, "si") == 0 && promedioFueraNivel < 3) {
            contadorFueraNivel++;
        }

        printf("¿Desea ingresar más empleados? (s/n): ");
        scanf(" %c", &band);
    }

    printf("La cantidad de empleados fuera de nivel son: %d\n", contadorFueraNivel);

    printf("El empleado de codigo: %d es el que mas dias trabajo con un total de %d\n", codEmpleadoMaxDias, maxDiasTrabajados);
 
    printf("Fin del ingreso de empleados.\n");

    return 0;
}
