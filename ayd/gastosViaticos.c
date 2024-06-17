#include <stdio.h>
#include <string.h>

int calculoViaticos(int, int, int);
void limpiarPantalla();

int main() {
    char band = 's', catEmpleado;
    int legajo, km, peaje, comida, anticipo, contEmpleadoTipoV = 0; 

    while (band == 's') {

        printf("Ingrese el legajo: \n");
        scanf(" %d", &legajo);

        printf("Ingrese el tipo de empleado ('v' vendedor, 'j' jefe, 'g' gerente): \n");
        scanf(" %c", &catEmpleado);

        printf("Ingrese la cantidad de kilometros recorridos: \n");
        scanf("%d", &km);

        printf("Ingrese los gastos de peaje: \n");
        scanf("%d", &peaje);

        printf("Ingrese los gastos en comida: \n");
        scanf("%d", &comida);

        if(catEmpleado == 'v'){
            printf("Ingrese el monto del anticipo: \n");
            scanf("%d", &anticipo);
            contEmpleadoTipoV++;
        }

        printf("El valor de los viaticos es %d\n", calculoViaticos(km, peaje, comida) - anticipo);

        if (calculoViaticos(km, peaje, comida) >= 0)
        {
            printf("importe a pagar por la empresa \n");
        } else {
            printf("importe a pagar por el empleado \n");
        }
        
        printf("¿Desea ingresar más datos? (s/n): ");
        scanf(" %c", &band);

        limpiarPantalla();
    }

    printf("La cantidad de empleados vendedores es de: %d\n", contEmpleadoTipoV);
    limpiarPantalla();

}

int calculoViaticos(int km, int gastoPeajes, int gastoComida){
    int montoViaticos;

    if(km <= 2000) {
        km = km * 10;
    } else {
        km = km * 5;
    }

    montoViaticos = km + gastoPeajes + gastoComida;
    return montoViaticos;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}
