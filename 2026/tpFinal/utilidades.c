#include <stdio.h>
#include <stdlib.h>

#include "utilidades.h"

int pedirNum(char msj[])
{
    int num;
    printf("%s",msj);
    scanf("%d",&num);
    return num;
}

void crearArregloDinamicoMascotas(stMascota** arr,int val)
{
    (*arr) = calloc(val,sizeof(stMascota));
}


int cantidadElemArchiMascotas(char archi[])
{
    FILE* buffer = fopen(archi,"rb");
    stMascota mascota;
    int cant = 0;

    if(buffer)
    {
        while(fread(&mascota,sizeof(stMascota),1,buffer)>0)
        {
            if(mascota.eliminado == 0)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return cant;
}

int cantidadElemArchiDuenios(char archi[])
{
    FILE* buffer = fopen(archi,"rb");
    stDuenio duenio;
    int cant = 0;

    if(buffer)
    {
        while(fread(&duenio,sizeof(stDuenio),1,buffer)>0)
        {
            if(duenio.eliminado == 0)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return cant;
}
/*
int cantidadElemArchiMascotas(char archi[])
{
    FILE* buffer = fopen(archi,"rb");
    int cant = 0;

    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stMascota);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return cant;
}
*/
