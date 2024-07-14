#include <stdio.h>

#define DIA 3

// Prototipos de las funciones
void limpiarPantalla();
void limpiarBuffer();
void ingresoDatos(int vecDia[], char vecMov[], int monto[]);
void evaluarCobranzas(int vecDia[], char vecMov[], int monto[], int saldoActual[]);

int main() {
    int opcion;
    int vecDia[DIA] = {0}, monto[DIA] = {0}, saldoActual[DIA] = {0};
    char vecMov[DIA] = {0};

    do {
        printf("Menu:\n");
        printf("1 - Ingresar datos de los movimientos.\n");
        printf("2 - Evaluar habilidades del arquero robot.\n");
        printf("3 - Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                ingresoDatos(vecDia, vecMov, monto);
                break;
            case 2:
                evaluarCobranzas(vecDia, vecMov, monto, saldoActual);
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
    } while (opcion != 3);

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

void ingresoDatos(int vecDia[], char vecMov[], int monto[]) {
    int i;
    int contDia = 0;

    for (i = 0; i < DIA; i++)
    {
        printf("Ingrese tipo de movimiento 'i' Ingreso o 'E' Egreso: \n");
        scanf(" %c", &vecMov[i]);
        limpiarBuffer();

        printf("Ingrese la cantidad a ingresar o egresar: \n");
        scanf(" %d", &monto[i]);
        limpiarBuffer();

        contDia ++;
        vecDia[i] = contDia;   
    }

    limpiarPantalla();
}

void evaluarCobranzas(int vecDia[], char vecMov[], int monto[], int saldoActual[]){

    int saldoInicial;
    int saldoFinal = 0;

    printf("Ingrese el Saldo Inicial de Caja: ");
    scanf("%d", &saldoInicial);
    limpiarBuffer(); 

    saldoActual[0] = saldoInicial + (vecMov[0] == 'I' ? monto[0] : -monto[0]);
    printf("Saldo del día %d: %d\n", vecDia[0], saldoActual[0]);

    for (int i = 1; i < DIA; i++) {
        saldoActual[i] = saldoActual[i-1] + (vecMov[i] == 'I' ? monto[i] : -monto[i]);
        printf("Saldo del día %d: %d\n", vecDia[i], saldoActual[i]);
    }

    saldoFinal = saldoActual[DIA-1];
    printf("Saldo final de Caja del mes: %d\n", saldoFinal);

}

