#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "planeta.h"

stPlaneta cargarUnPlaneta()
{
    stPlaneta planeta;
    printf("\nIngrese Nombre del PLANETA:");
    scanf("%s",planeta.nombrePlaneta);
    printf("\nIngrese Nombre de la ESTRELLA:");
    scanf("%s",planeta.estrella);
    printf("\nIngrese cantidad de SATELITES:");
    scanf("%d",&planeta.cantidadSatelites);
    printf("\nIngrese del planeta la MASA:");
    scanf("%f",&planeta.masa);
    printf("\nIngrese del planeta la temp. MAX:");
    scanf("%d",&planeta.tempMax);
    printf("\nIngrese del planeta la temp. MIN:");
    scanf("%d",&planeta.tempMin);
    return planeta;
}

int cargarPlanetas(stPlaneta arr[],int dim)
{
    char control = 's';
    int i = 0;
    while(control == 's' && i < dim)
    {
        arr[i] = cargarUnPlaneta();
        i++;
        printf("\nDesea continuar cargando PLANETAS s/n:");
        scanf(" %c",&control);
    }
    return i;
}

void mostrarUnPlaneta(stPlaneta planeta)
{
    printf("\nNombre del PLANETA:%s",planeta.nombrePlaneta);
    printf("\nNombre de la ESTRELLA:%s",planeta.estrella);
    printf("\nCantidad de SATELITES:%d",planeta.cantidadSatelites);
    printf("\nMASA del planeta:%.2f",planeta.masa);
    printf("\nTemp. MAX del planeta:%d",planeta.tempMax);
    printf("\nTemp. MIN del planeta:%d",planeta.tempMin);
}

void mostrarPlanetas(stPlaneta arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarUnPlaneta(arr[i]);
    }
}

int contarSatelites(stPlaneta arr[],int val, int i)
{
    int contador = 0;
    if(i < val)
    {
        contador = arr[i].cantidadSatelites + contarSatelites(arr,val,i+1);
    }
    return contador;
}

int contarCantElemArchi(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;

    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stPlaneta);

        fclose(buffer);
    }
    return cant;
}

void arrDinamico(stPlaneta** arr,int cant)
{
    (*arr) = calloc(cant,sizeof(stPlaneta));
}

int pasarArchiToArr(char archivo[],stPlaneta** arr)
{
    FILE* buffer = fopen(archivo,"rb");
    stPlaneta planeta;
    int cant = contarCantElemArchi(archivo);
    arrDinamico(arr,cant);
    int i = 0;
    if(buffer)
    {
        while(fread(&(*arr)[i],sizeof(stPlaneta),1,buffer)>0)
        {
            i++;
        }
        fclose(buffer);
    }
    return i;
}

float pedirFloat (char msj[])
{
    float num;
    printf("%s",msj);
    scanf("%f",&num);
    return num;
}
