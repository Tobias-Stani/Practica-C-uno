// Lea  10  números  por  teclado,  almacénelos  en  un  array  y  muestre  la  suma,  resta, 
//multiplicación y división de todos.  

#include <stdio.h>

int suma(int arr[], int tam){

    int suma = 0, i;

    for (i = 0; i < tam; i++)
    {
        suma += arr[i];
    }
    
    return  suma;
}

int resta(int arr[], int tam){

    int resta = 0, i;

    for (i = 0; i < tam; i++)
    {
        resta -= arr[i];
    }
    
    return  resta;
}

int multiplicacion(int arr[], int tam){

    int multiplicacion = 1, i;

    for (i = 0; i < tam; i++)
    {
        multiplicacion *= arr[i];
    }
    
    return  multiplicacion;
}

int division(int arr[], int tam){

    int division = arr[0], i;

    for (i = 1; i < tam; i++)
    {
        division /= arr[i];
    }
    
    return  division;
}


int main() {

    int numeros[5], i, sumaArray, restaArray, multiplicacionArray, divisionArray;

    printf("Ingrese 5 numeros: \n");
    for (i = 0; i < 5; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    sumaArray = suma(numeros, 5);
    printf("La suma es de: %d\n", sumaArray);

    restaArray = resta(numeros, 5);
    printf("La resta es de: %d\n", restaArray);

    multiplicacionArray = multiplicacion(numeros, 5);
    printf("La multiplicacion es de: %d\n", multiplicacionArray);

    divisionArray = division(numeros, 5);
    printf("La division es de: %d\n", divisionArray);

    return 0;

}