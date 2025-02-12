#include <stdio.h>

int main() {
    int x = 10;    // Variable normal
    int *ptr = &x; // ptr almacena la dirección de x

    printf("Valor de x: %d\n", x);     // 10
    printf("Direccion de x: %p\n", &x); // Dirección en memoria
    printf("Valor de ptr: %p\n", ptr);  // Muestra la dirección almacenada en ptr
    printf("Valor al que apunta ptr: %d\n", *ptr); // 10

    return 0;
}
