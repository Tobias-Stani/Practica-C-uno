/*
Final Julio 2019 versión 2
*/
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define tam 31

// obligatorioas
void armarresultados(float *vx);
// opcionales
int menu();

main()
{
      int opc=0, i=0, j, dia, codigo, vmenu;    
      float monto, vmonto[tam]={0};
      
      vmenu=menu();
      while(vmenu!=3)
      {       
         switch(vmenu)
         {
             case 1:
                  printf("EVALUACION DE FLUJO DE FONDOS:\n");
                  printf("-------\n\n");
                  printf("Ingresar Dia de 1 a 31: \n");
                  fflush(stdin);
                  scanf("%d",&dia);
                  printf("Ingrese Codigo de Movimiento I/E:\n");
                  fflush(stdin);
                  scanf("%c",&codigo);
                  printf("Ingrese Monto del Movimiento:\n");
                  fflush(stdin);
                  scanf("%f",&monto);
                
                   j=dia-1;  // posición según el día
     
                   if (codigo=='I') { vmonto[j]=vmonto[j] + monto;}
                   else { vmonto[j]= vmonto[j]- monto;}
                     
                  getch();
                  system("CLS");
                  break;
             case 2:  
                  armarresultados(vmonto);
                  getch();
                  break;                    
         }
        vmenu=menu();
}
}
////////////////////////////////////////////////////////////////////////////////
void armarresultados(float *vx)
{ 
     float saldo_inicial, saldo;
     int j;
     
     printf("Ingresar Saldo Inicial de Caja: \n");
     fflush(stdin);
     scanf("%f",&saldo_inicial); 
     
     saldo=saldo_inicial;
    
        for(j=0;j<31;j++) // recorro el vector
        { 
        saldo=saldo+*vx;
        printf("Saldo día parcial%d\t %f\n", j+1, *vx);  // lo agregué para ver que hay en el vector 
        printf("Saldo día acumulado %d\t %f\n", j+1, saldo);   
        vx++;  
        }      
    printf("Saldo final %f\n", saldo);          
    system("pause");
     
}
////////////////////////////////////////////////////////////////////////////////
int menu()
{
    int opc;
         printf("PROGRAMA FINANZAS\n");
         printf("*****************\n\n\n");
         printf("1-Cargar Movimientos de Fondos\n");
         printf("2-Evaluar Flujo de Caja\n");
         printf("3-Salir\n");
         scanf("%i",&opc);
         return opc;
}    
