#include <stdio.h>

void bubbleSort(int arr[], int n){
    int i, j, temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            
        }
        
    }
    
}


void imprimirArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main () {
    int arr[] = {90, 50, 40, 70, 10, 80, 20, 60, 30, 100};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, n);

    bubbleSort(arr, n);

    printf("Array ordenado com bubble sort: ");
    imprimirArray(arr, n);

    return 0;
}