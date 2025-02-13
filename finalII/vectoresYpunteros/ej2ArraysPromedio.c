//Calcular el promedio de un array


int promedio(int arr[], int tam){

    int suma = 0, i;

    for (i = 0; i < tam; i++)
    {
        suma += arr[i];
    }
    
    return  suma / tam;
}

int main() {

    int numeros[5], i, promedioArray;

    printf("Ingrese 5 numeros: \n");
    for (i = 0; i < 5; i++)
    {
        printf("Numero %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }
    
    promedioArray = promedio(numeros, 5);
    
    printf("El promedio es de: %d\n", promedioArray);

    return 0;

}