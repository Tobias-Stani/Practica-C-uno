#include <stdio.h>
#include <stdlib.h>

#define MAX 2

void limpiarPantalla();
void cotizacionesMateriaPrima(float preciosUnitarios[], int cantidadesAEntregar[], int codigosProveedores[]);
int codigoProveedores(float precioUnitario, int cantidadAEntregar);
void cargarVectores(float precioUnitario, int cantidadAEntregar, int codigoProveedor, float preciosUnitarios[], int cantidadesAEntregar[], int codigosProveedores[]);
void analisisDeCotizaciones(float ultimoPrecio, int cantidadAEntregar, float preciosUnitarios[], int cantidadesAEntregar[], int codigosProveedores[], int contador);

int contador = 0; // Declarar contador como una variable global
float preciosUnitarios[MAX];
int cantidadesAEntregar[MAX];
int codigosProveedores[MAX];

int main() {
    int opcion;

    do {
        printf("Menu:\n");
        printf("1 - Ingresar cotizaciones de precios de materia prima\n");
        printf("2 - Analisis de cotizaciones\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch(opcion) {
            case 1:
                cotizacionesMateriaPrima(preciosUnitarios, cantidadesAEntregar, codigosProveedores);
                break;
            case 2:
                analisisDeCotizaciones(0.0, 0, preciosUnitarios, cantidadesAEntregar, codigosProveedores, contador);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Por favor, intente nuevamente.\n");
        }

        if (opcion != 3) {
            printf("Presione Enter para continuar...");
            while (getchar() != '\n'); // Limpiar el buffer de entrada
            getchar(); // Esperar a que el usuario presione Enter
            limpiarPantalla();
        }
    } while(opcion != 3);

    return 0;
}

void limpiarPantalla() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void cotizacionesMateriaPrima(float preciosUnitarios[], int cantidadesAEntregar[], int codigosProveedores[]) {
    float precioUnitario;
    int cantidadAEntregar;
    int codigoProveedor;

    printf("Ingrese el precio unitario del material: ");
    scanf("%f", &precioUnitario);

    printf("Ingrese la cantidad de unidades que puede entregar el proveedor al mes: ");
    scanf("%d", &cantidadAEntregar);

    codigoProveedor = codigoProveedores(precioUnitario, cantidadAEntregar);

    cargarVectores(precioUnitario, cantidadAEntregar, codigoProveedor, preciosUnitarios, cantidadesAEntregar, codigosProveedores);
}

int codigoProveedores(float precioUnitario, int cantidadAEntregar) {
    static int codigoProveedor = 0;
    
    codigoProveedor += 1;

    printf("El código de proveedor para este producto es: %d\n", codigoProveedor);
    printf("Precio unitario: %.2f\n", precioUnitario);
    printf("Cantidad a entregar: %d\n", cantidadAEntregar);

    return codigoProveedor;
}

void cargarVectores(float precioUnitario, int cantidadAEntregar, int codigoProveedor, float preciosUnitarios[], int cantidadesAEntregar[], int codigosProveedores[]){
    if (contador < MAX) {
        preciosUnitarios[contador] = precioUnitario;
        cantidadesAEntregar[contador] = cantidadAEntregar;
        codigosProveedores[contador] = codigoProveedor;
        contador++;
    } else {
        printf("No hay espacio para más datos.\n");
    }

    printf("\nDatos almacenados:\n");
    for (int i = 0; i < contador; i++) {
        printf("Proveedor %d: Precio Unitario: %.2f, Cantidad a Entregar: %d, Código de Proveedor: %d\n",
               i + 1, preciosUnitarios[i], cantidadesAEntregar[i], codigosProveedores[i]);
    }
}

void analisisDeCotizaciones(float ultimoPrecio, int cantidadAEntregar, float preciosUnitarios[], int cantidadesAEntregar[], int codigosProveedores[], int contador){
    int proveedorElegido = -1;
    float precioMinimo = ultimoPrecio + 1.0;

    for (int i = 0; i < contador; i++) {
        if (preciosUnitarios[i] < precioMinimo && cantidadesAEntregar[i] >= cantidadAEntregar) {
            precioMinimo = preciosUnitarios[i];
            proveedorElegido = i;
        }
    }

    if (proveedorElegido != -1) {
        printf("El proveedor que cotizó el precio mínimo y puede entregar al menos %d unidades es el de código %d\n",
               cantidadAEntregar, codigosProveedores[proveedorElegido]);
    } else {
        printf("No se encontró ningún proveedor que cumpla con los requisitos.\n");
    }
}
