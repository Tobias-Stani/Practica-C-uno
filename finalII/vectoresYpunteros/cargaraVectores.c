#include <stdio.h>
#define TAM 5  // Tamaño de los vectores

void cargarDatos(int *vec1, int *vec2, int *vec3, int tam);
void emitirReportes(int *vec1, int *vec2, int *vec3, int tam);

int main() {
    int opcion;
    int vector1[TAM], vector2[TAM], vector3[TAM];
    
    do {
        printf("\nMenu:\n");
        printf("1. Cargar datos en los vectores\n");
        printf("2. Emitir reportes\n");
        printf("3. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch(opcion) {
            case 1:
                cargarDatos(vector1, vector2, vector3, TAM);
                break;
            case 2:
                emitirReportes(vector1, vector2, vector3, TAM);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion no valida. Intente de nuevo.\n");
        }
    } while(opcion != 3);
    
    return 0;
}

void cargarDatos(int *vec1, int *vec2, int *vec3, int tam) {
    printf("\nIngrese los valores para los tres vectores:\n");
    for(int i = 0; i < tam; i++) {
        printf("Vector 1, posicion %d: ", i + 1);
        scanf("%d", (vec1 + i));
        printf("Vector 2, posicion %d: ", i + 1);
        scanf("%d", (vec2 + i));
        printf("Vector 3, posicion %d: ", i + 1);
        scanf("%d", (vec3 + i));
    }
}

void emitirReportes(int *vec1, int *vec2, int *vec3, int tam) {
    printf("\nDatos ingresados:\n");
    printf("Vector 1:\t");
    for(int i = 0; i < tam; i++) {
        printf("%d ", *(vec1 + i));
    }
    printf("\nVector 2:\t");
    for(int i = 0; i < tam; i++) {
        printf("%d ", *(vec2 + i));
    }
    printf("\nVector 3:\t");
    for(int i = 0; i < tam; i++) {
        printf("%d ", *(vec3 + i));
    }
    printf("\n\nCalculando suma total de cada vector...\n");
    int suma1 = 0, suma2 = 0, suma3 = 0;
    int max1 = *vec1, max2 = *vec2, max3 = *vec3;
    for(int i = 0; i < tam; i++) {
        suma1 += *(vec1 + i);
        suma2 += *(vec2 + i);
        suma3 += *(vec3 + i);
        if(*(vec1 + i) > max1) max1 = *(vec1 + i);
        if(*(vec2 + i) > max2) max2 = *(vec2 + i);
        if(*(vec3 + i) > max3) max3 = *(vec3 + i);
    }
    printf("Suma del Vector 1: %d\n", suma1);
    printf("Suma del Vector 2: %d\n", suma2);
    printf("Suma del Vector 3: %d\n", suma3);
    printf("\nEl mayor valor en Vector 1: %d\n", max1);
    printf("El mayor valor en Vector 2: %d\n", max2);
    printf("El mayor valor en Vector 3: %d\n", max3);
}

