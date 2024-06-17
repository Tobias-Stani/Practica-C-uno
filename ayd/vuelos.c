#include <stdio.h>
#include <string.h>

int calcularTiempoEscala(int, int ,int);
void limpiarPantalla();

int main() {
    char band = 's', destino, escalas;
    int nVuelo, tiempoVuelo, cantEscalas, tiempoEscala;

    while (band == 's') {

        printf("Ingrese el numero de vuelo: \n");
        scanf(" %d", &nVuelo);

        printf("Ingrese el destino N nacional, M internacional mercosur, I internacional fuera de mercosur: \n");
        scanf(" %c", &destino);

        printf("Ingrese el tiempo de vuelo: \n");
        scanf("%d", &tiempoVuelo);

        printf("Ingrese si hay escalas (s/n): \n");
        scanf(" %c", &escalas);

        if(escalas == 's'){
            printf("Ingrese la cantidad de escalas: \n");
            scanf("%d", &cantEscalas);

            printf("ingrese la cantidad de tiempo en escalas: \n");
            scanf(" %d", &tiempoEscala);
        }

        limpiarPantalla();

        printf("¿Desea ingresar más datos? (s/n): ");
        scanf(" %c", &band);

        if(escalas == 'n') {

            printf("El número de vuelo es: %d\n", nVuelo);
            printf("El tiempo de vuelo es: %d\n", tiempoVuelo);
        } else if(escalas == 's'){

            printf("El número de vuelo es: %d\n", nVuelo);
            printf("El tiempo de vuelo total es de:  %d\n", calcularTiempoEscala(tiempoVuelo, cantEscalas, tiempoEscala));
        }

        limpiarPantalla();
    }

}

int calcularTiempoEscala(int tiempoVuelo, int cantEscalas, int tiempoEscala){
    int tiempoTotalVuelo;
    tiempoTotalVuelo = (tiempoVuelo + tiempoEscala) * cantEscalas;
    return tiempoTotalVuelo;
}

void limpiarPantalla() {
#ifdef _WIN32
    system("cls"); // Para sistemas Windows
#else
    system("clear"); // Para sistemas Unix/Linux
#endif
}
