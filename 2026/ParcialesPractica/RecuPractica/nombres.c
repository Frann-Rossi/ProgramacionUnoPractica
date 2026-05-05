#include <stdio.h>
#include <stdlib.h>

#include "nombres.h"

// EJERCICIO 6
// **************************************************

int nombreExiste (char arrNombres[][LARGO_NOMBRE],int val, char palabra[])
{
    int flag = -1;
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(palabra,arrNombres[i]) == 0)
        {
            flag = i;
        }
    }
    return flag;
}

int cargarNombres(char arrNombres[][LARGO_NOMBRE],int dim)
{
    char control = 's';
    int i = 0;

    int nombre = 0;
    while (control == 's' && i < dim)
    {
        printf("Ingrese el nombre:");
        scanf("%s",&arrNombres[i]);
        nombre = nombreExiste (arrNombres,i,arrNombres[i]);
        if(nombre == -1)
        {
            i++;
        }
        else
        {
            printf("El Nombre ya existe\n");
        }
        printf("Desea seguir 's/n':");
        scanf(" %c", &control);
    }
    return i;
}

void mostrarNombres(char arrNombres[][LARGO_NOMBRE],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%s|\n",arrNombres[i]);
    }
}

// **************************************************
