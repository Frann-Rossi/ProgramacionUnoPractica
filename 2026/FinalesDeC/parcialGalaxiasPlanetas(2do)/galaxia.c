#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "galaxia.h"
#include "planeta.h"

stGalaxia cargarUnaGalaxia()
{
    stGalaxia galaxia;
    printf("\n Ingrese nombre de la GALAXIA:");
    scanf("%s",galaxia.nombreGalaxia);
    printf("\n Ingrese el TIPO de GALAXIA:");
    scanf("%s",galaxia.tipoGalaxia);
    printf("\n Ingrese por quien fue DESCUBIERTA:");
    scanf("%s",galaxia.descubiertoPor);
    galaxia.valPlanetas = cargarPlanetas(galaxia.listaPlanetas,DIM);
    return galaxia;
}

int cargarGalaxias(stGalaxia arr[],int dim)
{
    char control = 's';
    int i = 0;

    while(control == 's' && i < dim)
    {
        arr[i] = cargarUnaGalaxia();
        i++;
        printf("\nDesea continuar cargando GALAXIAS s/n:");
        scanf(" %c",&control);
    }
    return i;
}

void mostrarUnaGalaxia(stGalaxia galaxia)
{
    printf("\nNombre de la GALAXIA:%s",galaxia.nombreGalaxia);
    printf("\nTIPO de GALAXIA:%s",galaxia.tipoGalaxia);
    printf("\nDESCUBIERTA por:%s",galaxia.descubiertoPor);
    mostrarPlanetas(galaxia.listaPlanetas,galaxia.valPlanetas);
}

void mostrarGalaxias(stGalaxia arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarUnaGalaxia(arr[i]);
    }
}

void mostrarGalaxiasPorTipo(stGalaxia arr[],int val, char tipoBuscado[])
{
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(tipoBuscado,arr[i].tipoGalaxia)==0)
        {
            mostrarUnaGalaxia(arr[i]);
        }
    }
}

int contarSatelitesDeGalaxias(stGalaxia arr[],int val)
{
    int total = 0;
    for(int i = 0; i < val; i++)
    {
        total += contarSatelites(arr[i].listaPlanetas,arr[i].valPlanetas,0);
    }
    return total;
}

void guardarPlanetasGalaxiasPorMasa(char archivo[],stGalaxia arr[],int val,float masa)
{
    FILE* buffer = fopen(archivo,"wb");

    if(buffer)
    {
        for(int i=0; i<val; i++)
        {
            for(int j=0; j<arr[i].valPlanetas; j++)
            {
                if(arr[i].listaPlanetas[j].masa > masa)
                {
                    fwrite(&arr[i].listaPlanetas[j],
                           sizeof(stPlaneta),
                           1,
                           buffer);
                }
            }
        }

        fclose(buffer);
    }
}


void pedirGalaxia(char galaxia[])
{
    printf("\nIngrese el tipo de galaxia que esta buscando:");
    scanf("%s",galaxia);
}
