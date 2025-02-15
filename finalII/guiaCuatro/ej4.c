// Escribir un programa que pida 10 números enteros por teclado, los cargue en un vector  
//y que imprima por pantalla:  
// 
//i. Cuántos de esos números son pares.  
//ii. Cuál es el valor del número máximo.  
//iii. Cuál es el valor del número mínimo.

#include <stdio.h>

int obtenerMaximo(int arr[], int tam){
    int maximo = arr[0];

    for (int i = 1; i < tam; i++)
    {
        if (arr[i] > maximo) 
        {
            maximo = arr[i];
        }
        
    }
    return maximo;
}

int obtenerMinimo(int arr[], int tam){
    int minimo = arr[0];

    for (int i = 1; i < tam; i++)
    {
        if (arr[i] < minimo) 
        {
            minimo = arr[i];
        }
        
    }
    return minimo;
}

int main() {

    int numeros[5], i, maximo, minimo, par;

    printf("Ingrese 5 numeros: \n");
    for (i = 0; i < 5; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    maximo = obtenerMaximo(numeros, 5);
    printf("El numero maximo del array es: %d\n", maximo);

    minimo = obtenerMinimo(numeros, 5);
    printf("El numero maximo del array es: %d\n", minimo);

    return 0;

}