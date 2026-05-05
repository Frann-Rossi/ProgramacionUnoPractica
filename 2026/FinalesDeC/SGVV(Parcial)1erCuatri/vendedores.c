#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "vendedores.h"


int cargarNombres(char arr[][LARGO_NOMBRE], int dim)
{
    char control = 's';
    int i  = 0;

    while(control == 's' && i < dim)
    {
        printf("Ingrese un nombre:");
        scanf("%29s",arr[i]);
        i++;
        printf("\nDesea seguir cargando nombres 's/n':");
        scanf(" %c",&control);
    }
    return i;
}

char pedirLetra()
{
    char letra;
    printf("\nIngrese una letra para buscar nombres:");
    scanf(" %c",&letra);
    return letra;
}

void mostrarNombresPorInicial (char arr[][LARGO_NOMBRE],int val,char letra)
{
    int flag = 0;
    for(int i = 0; i < val; i++)
    {
        if(letra == arr[i][0])
        {
            printf("|%s|\n",arr[i]);
            flag = 1;
        }
    }

    if(!flag)
    {
        printf("No hay nombres con la letra solicitada\n");
    }
}

void mostrarNombres(char arr[][LARGO_NOMBRE],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%s|\n",arr[i]);
    }
}

int modificarRegistros(char arr[][LARGO_NOMBRE],int val)
{
    int i = 0;
    for(i; i < val; i++)
    {
        arr[i][0] = toupper(arr[i][0]);
    }
    return i;
}

