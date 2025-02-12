// CREAR UNA FUNCIÓN “ESCRIBIRTABLAMULTIPLICAR”, QUE RECIBA COMO PARÁMETRO UN 
//NÚMERO ENTERO, Y ESCRIBA LA TABLA DE MULTIPLICAR DE ESE NÚMERO (POR EJEMPLO, 
//PARA EL 3 DEBERÁ LLEGAR DESDE 3X0=0 HASTA 3X10=30).


#include <stdio.h>

void calcularTabla(int n);

int main () {

    int n;

    printf("Ingrese el numero: ");
    scanf("%d", &n);

    calcularTabla(n);
    return 0;
}

void calcularTabla(int n){

    int i, calculo;
    for (i = 1; i < 10; i++)
    {
        calculo = n * i;
        printf("%d * %d :%d\n", n, i, calculo);
    }
    

}