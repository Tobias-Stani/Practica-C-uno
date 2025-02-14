#include <stdio.h>


void insertionSort(int arr[], int n){
    int i, j, key;

    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j --;
        }
        
        arr[j + 1] = key;
    }
    
}


void imprimirArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main (){
    int arr[] = {20,10,14,37,13};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Array original: ");
    imprimirArray(arr, n);

    insertionSort(arr, n);

    printf("Array ordenado mediante insertion sort: ");
    imprimirArray(arr, n);

}