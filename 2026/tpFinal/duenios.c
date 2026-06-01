#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "duenios.h"

stDuenio cargarUnDuenio(char archi[])
{
    stDuenio duenio;
    duenio.eliminado = 0;


    printf("\n========== CARGAR DUENIO ==========\n");
    do
    {
        printf("\nID Duenio : ");
        scanf("%d",&duenio.idDuenio);

        if(idExistenteDuenio(archi, duenio.idDuenio))
        {
            printf("\n[ERROR] El ID ya existe. Ingrese otro.\n");
        }

    }
    while(idExistenteDuenio(archi, duenio.idDuenio));
    printf("\nNombre Duenio:");
    scanf("%s",duenio.nombre);
    printf("\nApellido Duenio: ");
    scanf("%s",duenio.apellido);
    printf("\nTelefono Duenio: ");
    scanf("%s",duenio.telefono);

    return duenio;
}

void cargarDueniosArchi (char archi[])
{
    FILE* buffer;
    stDuenio duenio;
    char control = 's';

    while(control == 's' || control == 'S')
    {
        buffer = fopen(archi, "ab");
        if(buffer)
        {
            duenio = cargarUnDuenio(archi);
            fwrite(&duenio,sizeof(stDuenio),1,buffer);
            printf("\n[OK] Duenio cargado correctamente.\n");
            printf("\nDesea cargar otro duenio? (s/n): ");
            scanf(" %c",&control);
            fclose(buffer);
        }
        else
        {
            printf("\n[ERROR] No se pudo abrir el archivo.\n");
        }
    }
}

void mostrarUnDuenio(stDuenio duenio)
{
    printf("\n=========== DUENIO  ===========\n");
    printf("ID Duenio  : %d\n", duenio.idDuenio);
    printf("Nombre     : %s\n", duenio.nombre);
    printf("Apellido   : %s\n", duenio.apellido);
    printf("Telefono   : %s\n", duenio.telefono);
    printf("================================\n");
}

void mostrarDueniosArchi(char archi[])
{
    FILE* buffer = fopen(archi,"rb");
    stDuenio duenio;
    if(buffer)
    {
        while(fread(&duenio,sizeof(stDuenio),1,buffer)>0)
        {
            if(duenio.eliminado == 0)
            {
                mostrarUnDuenio(duenio);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

int idExistenteDuenio(char archi[],int id)
{
    FILE* buffer = fopen(archi,"rb");
    stDuenio duenioRepe;
    int flag = 0;
    if(buffer)
    {
        while(fread(&duenioRepe,sizeof(stDuenio),1,buffer)>0 && flag == 0)
        {
            if(duenioRepe.idDuenio == id && duenioRepe.eliminado == 0)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");;
    }
    return flag;
}

void modificarDuenio(char archivo[],int id)
{
    FILE* buffer = fopen(archivo,"r+b");
    stDuenio duenio;
    int encontrado = 0;
    if(buffer)
    {
        while(fread(&duenio,sizeof(stDuenio),1,buffer)>0)
        {
            if(duenio.idDuenio  == id && duenio.eliminado == 0)
            {
                printf("\n======= MODIFICAR DUENIO =======\n");
                duenio = cargarUnDuenio(archivo);
                fseek(buffer, -sizeof(stDuenio), SEEK_CUR);
                fwrite(&duenio,sizeof(stDuenio),1,buffer);
                encontrado = 1;
                printf("\n[OK] Duenio modificado correctamente.\n");
                break;
            }
        }
        if(encontrado == 0)
        {
            printf("\n[INFO] No se encontro ninguna duenio con ese ID.\n");
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

void eliminarDuenio(char archivo[],int id)
{
    FILE* buffer = fopen(archivo,"r+b");
    stDuenio duenio;
    int encontrado = 0;
    if(buffer)
    {
        while(fread(&duenio,sizeof(stDuenio),1,buffer)>0)
        {
            if(duenio.idDuenio  == id && duenio.eliminado == 0)
            {
                printf("\n======= ELIMINAR DUENIO  =======\n");
                fseek(buffer, -sizeof(stDuenio), SEEK_CUR);
                duenio.eliminado = 1;
                fwrite(&duenio,sizeof(stDuenio),1,buffer);
                encontrado = 1;
                printf("\n[OK] Duenio eliminado correctamente.\n");
                break;
            }
        }
        if(encontrado == 0)
        {
            printf("\n[INFO] No se encontro ninguna duenio con ese ID.\n");
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

void buscarDuenioPorId (char archivo[],int id)
{
    FILE* buffer = fopen(archivo,"rb");
    stDuenio duenio;
    int encontrado = 0;
    if(buffer)
    {
        while(fread(&duenio,sizeof(stDuenio),1,buffer)>0)
        {
            if(duenio.idDuenio  == id && duenio.eliminado == 0)
            {
                mostrarUnDuenio(duenio);
                encontrado = 1;
                break;
            }
        }
        if(encontrado == 0)
        {
            printf("\n[INFO] No se encontro ninguna duenio con ese ID.\n");
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

void pasarArchiToArrDuenios(char archi[],stDuenio arr[], int dim)
{
    FILE* buffer = fopen(archi,"rb");
    stDuenio duenio;
    int i = 0;

    if(buffer)
    {
        while(fread(&duenio,sizeof(stDuenio),1,buffer)> 0 && i < dim)
        {
            if(duenio.eliminado == 0)
            {
                arr[i] = duenio;
                i++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

void mostrarDueniosArr(stDuenio arr[],int val,int i)
{
    if(i < val)
    {
        mostrarUnDuenio(arr[i]);
        mostrarDueniosArr(arr,val,i+1);
    }
}

int posMenor(stDuenio arr[],int val, int pos)
{
    int posMenor = pos;

    for(int i = pos + 1 ; i < val; i++)
    {
        if(strcmpi(arr[i].apellido, arr[posMenor].apellido) < 0)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenamientoPorSeleccion(stDuenio arr[],int val)
{
    int menor = 0;
    stDuenio aux;
    for(int i = 0 ; i < val; i++)
    {
        menor = posMenor(arr,val,i);
        aux = arr[i];
        arr[i] = arr[menor];
        arr[menor] =aux;
    }
}
