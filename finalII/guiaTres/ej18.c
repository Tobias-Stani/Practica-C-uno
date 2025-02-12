//CREAR UN PROGRAMA EN C QUE MUESTRE UN MENÚ CON LAS OPCIONES SUMAR, RESTAR, 
//MULTIPLICAR  Y  DIVIDIR,  EL  PROGRAMA  SOLICITARÁ  UNA  OPCIÓN  Y  REALIZARÁ  LA  TAREA 
//ELEGIDA,  SE  DEBE  USAR  UNA  FUNCIÓN  PARA  MOSTRAR  EL  MENÚ,  PEDIR  LOS  DATOS  EN  EL 
//MAIN Y DESPUÉS USAR FUNCIONES PARA REALIZAR LOS CÁLCULOS.  

#include <stdio.h>
#include <stdlib.h>

int sumar(int n1, int n2);
int restar(int n1, int n2);
int multiplicar(int n1, int n2);
int dividir(int n1, int n2);
void mostrarMenu();

int main() {
    int n1, n2, opcion, resultado;

    do {
        mostrarMenu();
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        if (opcion >= 1 && opcion <= 4) {
            printf("Ingrese el numero 1: ");
            scanf("%d", &n1);
            printf("Ingrese el numero 2: ");
            scanf("%d", &n2);
        }

        switch (opcion) {
            case 1:
                resultado = sumar(n1, n2);
                printf("La suma es: %d\n", resultado);
                break;
            case 2:
                resultado = restar(n1, n2);
                printf("La resta es: %d\n", resultado);
                break;
            case 3:
                resultado = multiplicar(n1, n2);
                printf("La multiplicacion es: %d\n", resultado);
                break;
            case 4:
                if (n2 == 0) {
                    printf("Error: No se puede dividir por cero.\n");
                } else {
                    resultado = dividir(n1, n2);
                    printf("La division es: %d\n", resultado);
                }
                break;
            case 5:
                printf("Saliendo del programa...\n");
                break;
            default:
                printf("Opción inválida. Intente nuevamente.\n");
        }

        printf("\nPresione Enter para continuar...");
        getchar(); // Capturar el Enter previo
        getchar(); // Esperar que el usuario presione Enter
        system("clear"); // Cambiar a system("cls"); en Windows

    } while (opcion != 5);

    return 0;
}

void mostrarMenu() {
    printf("========= MENU =========\n");
    printf("1 - Sumar\n");
    printf("2 - Restar\n");
    printf("3 - Multiplicar\n");
    printf("4 - Dividir\n");
    printf("5 - Salir\n");
    printf("========================\n");
}

int sumar(int n1, int n2) {
    return n1 + n2;
}

int restar(int n1, int n2) {
    return n1 - n2;
}

int multiplicar(int n1, int n2) {
    return n1 * n2;
}

int dividir(int n1, int n2) {
    return n1 / n2;
}
