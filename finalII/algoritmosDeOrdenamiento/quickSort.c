#include <stdio.h>

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low - 1);
    int temp;

    for (int j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    }
    
    temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;

}

void quickSort(int arr[], int low, int high){
    if (low < high)
    {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
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

    quickSort(arr, 0, n - 1);

    printf("Array ordenado mediante insertion sort: ");
    imprimirArray(arr, n);

}