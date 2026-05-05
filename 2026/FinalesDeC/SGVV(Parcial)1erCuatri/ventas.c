#include <stdio.h>

#include "pila.h"

int registrarVentas(int arr[],int dim)
{
    char control = 's';
    int i = 0;
    int num;
    while(control == 's' && i < dim)
    {
        printf("\nIngrese un valor > 0:");
        scanf("%d",&num);
        if(num > 0)
        {
            arr[i] = num;
            i++;
        }
        else
        {
            printf("Valor invalido. Debe ser mayor a 0.\n");
        }
        printf("Desea seguir cargando numeros 's/n':");
        scanf(" %c",&control);
    }
    return i;
}

void mostrarVentas(int arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%d|",arr[i]);
    }
}

float calcularPromedio(int arr[], int val)
{
    int sum = 0;
    int cant = 0;
    float promedio = 0;
    for(int i = 0; i < val ; i++)
    {
        sum += arr[i];
        cant++;
    }
    promedio = (float) sum / cant;
    return promedio;
}

//void (Pila* bajoPromedio, Pila* igualYSobrePromedio, int arr[], int val)


