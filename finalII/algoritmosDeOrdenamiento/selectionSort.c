#include <stdio.h>

void selectionSort(int arr[], int n){
    int i, j, minIdx, temp;

    for (i = 0; i < n -1; i++)
    {
        minIdx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIdx])
            {
                minIdx = j;
            }
            
        }
        
        temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
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

    selectionSort(arr, n);

    printf("Array ordenado mediante selection sort: ");
    imprimirArray(arr, n);

}