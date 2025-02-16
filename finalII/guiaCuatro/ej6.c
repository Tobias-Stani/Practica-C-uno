//Dado un vector con 5 notas de alumnos.  Determinar cuántas notas son mayores a 6.

#include <stdio.h>

int obtenerMaximo(int arr[], int tam){
    int maximo = 0;

    for (int i = 0; i < tam; i++)
    {
        if (arr[i] >= 6) 
        {
            maximo ++;
        }
        
    }
    return maximo;
}

int main() {

    int numeros[5], i, maximo;

    printf("Ingrese 5 numeros: \n");
    for (i = 0; i < 5; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    maximo = obtenerMaximo(numeros, 5);
    printf("Las notas mayores a 6 son: %d\n", maximo);

    return 0;

}