#include <stdio.h>
#include <stdlib.h>

#include "arreglo.h"

int cargarArr(int arr[],int dim)
{
    char control = 's';
    int i = 0;
    while(control == 's' && i < dim)
    {
        printf("Ingrese un num:");
        scanf("%d",&arr[i]);
        i++;
        printf("\nDesea seguir cargando numero 's/n':");
        scanf(" %c",&control);
    }
    return i;
}

void mostrarArr(int arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%d|",arr[i]);
    }
}

int cantNumPares(int arr[], int val)
{
    int cont = 0;
    for(int i = 0; i < val; i++)
    {
        if(arr[i] % 2 == 0)
        {
            cont++;
        }
    }
    return cont;
}

int* cant(int cant)
{
    int* arr = malloc(sizeof(int)*cant);
    return arr;
}

void pasarArrAArrDim (int arr[],int val,int arrDim[])
{
    int j = 0;
    for(int i = 0; i < val; i++)
    {

        if(arr[i] % 2 == 0)
        {
            arrDim[j] = arr[i];
            j++;
        }

    }

}

void arrDimDoble (int arr[],int val,int** arrDim)
{
    *arrDim = malloc(sizeof(int) * val);
    int j = 0;
    for(int i = 0; i < val; i++)
    {

        if(arr[i] % 2 == 0)
        {
            arrDim[j] = arr[i];
            j++;
        }

    }
}


