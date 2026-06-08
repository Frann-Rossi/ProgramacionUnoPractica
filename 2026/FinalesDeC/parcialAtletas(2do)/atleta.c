#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "atleta.h"

stAtleta cargarUnAtleta()
{
    stAtleta atleta;
    printf("\nIngrese el ID:");
    scanf("%d",&atleta.id);
    printf("\nIngrese el NOMBRE:");
    scanf("%s",atleta.nombre);
    printf("\nIngrese la CATEGORIA:");
    scanf("%s",atleta.categoria);
    printf("\nIngrese la EDAD:");
    scanf("%d",&atleta.edad);
    printf("\nIngrese el TIEMPO de CARRERA:");
    scanf("%f",&atleta.tiempoCarrera);
    printf("\nIngrese los PUNTOS:");
    scanf("%d",&atleta.puntos);
    return atleta;
}

void cargarArchivoDeAtleta(char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");
    stAtleta atleta;
    char control = 's';
    if(buffer)
    {
        while(control == 's')
        {
            atleta = cargarUnAtleta();
            fwrite(&atleta,sizeof(stAtleta),1,buffer);
            control = continuar("\nDesea seguir cargando ATLETAS 's/n':");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo...");
    }
}

int pasarArrToArchiPorCateg(char archivo[],stAtleta arr[], int dim,char categoria[])
{
    FILE* buffer = fopen(archivo,"rb");
    stAtleta atleta;
    int i = 0;

    if(buffer)
    {
        while(fread(&atleta,sizeof(stAtleta),1,buffer)>0 && i < dim)
        {
            if(strcmpi(categoria,atleta.categoria) == 0)
            {
                arr[i] = atleta;
                i++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo...");
    }
    return i;
}

void mostrarUnAtleta(stAtleta atleta)
{
    printf("\nIngrese el ID:%d",atleta.id);
    printf("\nIngrese el NOMBRE:%s",atleta.nombre);
    printf("\nIngrese la CATEGORIA:%s",atleta.categoria);
    printf("\nIngrese la EDAD:%d",atleta.edad);
    printf("\nIngrese el TIEMPO de CARRERA:%.2f",atleta.tiempoCarrera);
    printf("\nIngrese los PUNTOS:%d",atleta.puntos);
}

void mostrarArchivoDeAtleta(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    stAtleta atleta;

    if(buffer)
    {
        while(fread(&atleta,sizeof(stAtleta),1,buffer)>0)
        {
            mostrarUnAtleta(atleta);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo...");
    }
}

void mostrarArrDeAtleta(stAtleta arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarUnAtleta(arr[i]);
    }
}

int contarJugadoresRecur(stAtleta arr[],int val,int i)
{
    int contador = 0;
    if(i < val)
    {
        if(arr[i].edad >= 18 && arr[i].puntos > 20)
        {
            contador++;
        }
        contador += contarJugadoresRecur(arr,val,i+1);
    }
    return contador;
}

int buscarAtleta(stAtleta arr[],int val,int i, int id)
{
    int rta = -1;
    if(i < val)
    {
        if(arr[i].id == id)
        {
            rta = i;
        }
        else
        {
            rta = buscarAtleta(arr,val,i+1,id);
        }

    }
    return rta;
}

void guardarEnArchiPorEdad(stAtleta arr[],int val, char archiMayores[],char archiMenores[])
{
    FILE* buffer = fopen(archiMayores,"wb");
    FILE* buffer2 = fopen(archiMenores,"wb");

    if(buffer && buffer2)
    {
        for(int i = 0; i < val; i++)
        {
            if(arr[i].edad >= 18)
            {
                fwrite(&arr[i],sizeof(stAtleta),1,buffer);
            }
            else
            {
                fwrite(&arr[i],sizeof(stAtleta),1,buffer2);
            }
        }
        fclose(buffer);
        fclose(buffer2);
    }
}

void aumentarPuntos(char archivo[],float tiempo)
{
    FILE* buffer = fopen(archivo,"r+b");
    stAtleta atleta;
    if(buffer)
    {
        while(fread(&atleta,sizeof(stAtleta),1,buffer)>0)
        {
            if(atleta.tiempoCarrera > tiempo)
            {
                atleta.puntos += 5;
                fseek(buffer,-sizeof(stAtleta),SEEK_CUR);
                fwrite(&atleta,sizeof(stAtleta),1,buffer);
            }
        }
        fclose(buffer);
    }
}

void arrDinamico(float** arr, int cant)
{
    (*arr) = calloc(cant,sizeof(float));
}

int contarCant(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;

    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stAtleta);
        fclose(buffer);
    }
    return cant;
}

int contarTiemposMenores20(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    stAtleta atleta;
    int cant = 0;

    if(buffer)
    {
        while(fread(&atleta,sizeof(stAtleta),1,buffer) > 0)
        {
            if(atleta.tiempoCarrera < 20)
            {
                cant++;
            }
        }

        fclose(buffer);
    }

    return cant;
}

int pasarToArrTiempoMenores(char archivo[],float** arr)
{
    FILE* buffer = fopen(archivo,"rb");
    stAtleta atleta;
    int cant = contarCant(archivo);
    int i = 0;
    arrDinamico(arr,cant);

    if(buffer)
    {
        while(fread(&atleta,sizeof(stAtleta),1,buffer)>0)
        {
            if(atleta.tiempoCarrera < 20)
            {
                (*arr)[i] = atleta.tiempoCarrera;
                i++;
            }
        }
        fclose(buffer);
    }
    return i;
}

float promedio(float arr[], int val)
{
    float suma = 0;

    for(int i = 0; i < val; i++)
    {
        suma += arr[i];
    }

    return suma / val;
}

float sumarRecu(float arr[],int val, int i)
{
    int suma = 0;

    if(i<val)
    {
        suma = arr[i] + sumarRecu(arr,val,i+1);
    }
    return suma;
}

char continuar(char msj[])
{
    char opcion;
    printf("%s",msj);
    scanf(" %c",&opcion);
    return opcion;
}
