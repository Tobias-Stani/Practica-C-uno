//Dado un vector de 10 elementos determinar el máximo y el mínimo y en qué posición se 
//encuentran.

#include <stdio.h>

#define max 6  

void obtenerMaximo(int arr[], int tam, int *maximo, int *posicion) {
    *maximo = arr[0]; // Inicializamos con el primer elemento
    *posicion = 0;    // La posición inicial es 0

    for (int i = 1; i < tam; i++) {
        if (arr[i] > *maximo) { // Si encontramos un número mayor
            *maximo = arr[i];   // Actualizamos el máximo
            *posicion = i + 1;      // Guardamos la posición
        }
    }
}

void obtenerMinimo(int arr[], int tam, int *minimo, int *posicion) {
    *minimo = arr[0]; // Inicializamos con el primer elemento
    *posicion = 0;    // La posición inicial es 0

    for (int i = 1; i < tam; i++) {
        if (arr[i] < *minimo) { // Si encontramos un número mayor
            *minimo = arr[i];   // Actualizamos el máximo
            *posicion = i + 1;      // Guardamos la posición
        }
    }
}



int main() {
    int numeros[max], i, maximo, posicion, minimo;

    printf("Ingrese 6 numeros: \n");
    for (i = 0; i < max; i++) {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    obtenerMaximo(numeros, max, &maximo, &posicion);
    printf("El número máximo en el array es: %d\n", maximo);
    printf("Se encontraba en la posición: %d\n", posicion);

    obtenerMinimo(numeros, max, &minimo, &posicion);
    printf("El número minimo en el array es: %d\n", minimo);
    printf("Se encontraba en la posición: %d\n", posicion);


    return 0;
}
