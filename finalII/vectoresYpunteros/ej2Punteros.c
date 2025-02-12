//Cambiar el valor de una variable usando punteros

#include <stdio.h>

void modificarValor(int *ptr){
    *ptr = 100;
} 

int main () {

    int num = 10;

    printf("Valor original de num: %d\n", num);
    modificarValor(&num);
    printf("Valor modificado de num: %d\n", num);

}