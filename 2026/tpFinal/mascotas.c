#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"

stMascota cargarUnaMascota(char archi[])
{
    stMascota mascota;
    mascota.eliminado = 0;


    printf("\n========== CARGAR MASCOTA ==========\n");
    do
    {
        printf("\nID Mascota : ");
        scanf("%d",&mascota.idMascota);

        if(idExistenteMascota(archi, mascota.idMascota))
        {
            printf("\n[ERROR] El ID ya existe. Ingrese otro.\n");
        }

    }
    while(idExistenteMascota(archi, mascota.idMascota));
    printf("\nNombre Mascota:");
    scanf("%s",mascota.nombre);
    printf("\nEspecie Mascota:");
    scanf("%s",mascota.especie);
    printf("\nRaza Mascota:");
    scanf("%s",mascota.raza);
    printf("\nEdad Mascota:");
    scanf("%d",&mascota.edad);
    printf("\nID Duenio:");
    scanf("%d",&mascota.idDuenio);
    return mascota;
}

/*
void cargarMascotaArchi (char archi[])
{
    FILE* buffer = fopen(archi, "ab");
    stMascota mascota;
    char control = 's';

    if(buffer)
    {
        while(control == 's' || control == 'S')
        {
            mascota = cargarUnaMascota(archi);
            fwrite(&mascota,sizeof(stMascota),1,buffer);
            fflush(buffer);
            printf("\nDesea seguir cargando mascotas 's/n':");
            scanf(" %c",&control);
        }
        fclose(buffer);
    }
}
*/
void cargarMascotaArchi (char archi[])
{
    FILE* buffer;
    stMascota mascota;
    char control = 's';

    while(control == 's' || control == 'S')
    {
        buffer = fopen(archi, "ab");
        if(buffer)
        {
            mascota = cargarUnaMascota(archi);
            fwrite(&mascota,sizeof(stMascota),1,buffer);
            printf("\n[OK] Mascota cargada correctamente.\n");
            printf("\nDesea cargar otra mascota? (s/n): ");
            scanf(" %c",&control);
            fclose(buffer);
        }
        else
        {
            printf("\n[ERROR] No se pudo abrir el archivo.\n");
        }
    }
}

void mostrarUnaMascota(stMascota mascota)
{
    printf("\n=========== MASCOTA ===========\n");
    printf("ID Mascota : %d\n", mascota.idMascota);
    printf("Nombre     : %s\n", mascota.nombre);
    printf("Especie    : %s\n", mascota.especie);
    printf("Raza       : %s\n", mascota.raza);
    printf("Edad       : %d\n", mascota.edad);
    printf("ID Duenio  : %d\n", mascota.idDuenio);
    printf("================================\n");
}

void mostrarMascotasArchi(char archi[])
{
    FILE* buffer = fopen(archi,"rb");
    stMascota mascota;
    if(buffer)
    {
        while(fread(&mascota,sizeof(stMascota),1,buffer)>0)
        {
            if(mascota.eliminado == 0)
            {
                mostrarUnaMascota(mascota);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

int idExistenteMascota(char archi[],int id)
{
    FILE* buffer = fopen(archi,"rb");
    stMascota mascotaRepe;
    int flag = 0;
    if(buffer)
    {
        while(fread(&mascotaRepe,sizeof(stMascota),1,buffer)>0 && flag == 0)
        {
            if(mascotaRepe.idMascota == id && mascotaRepe.eliminado == 0)
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

void modificarMascota(char archivo[],int id)
{
    FILE* buffer = fopen(archivo,"r+b");
    stMascota mascota;
    int encontrado = 0;
    if(buffer)
    {
        while(fread(&mascota,sizeof(stMascota),1,buffer)>0)
        {
            if(mascota.idMascota == id && mascota.eliminado == 0)
            {
                printf("\n======= MODIFICAR MASCOTA =======\n");
                mascota = cargarUnaMascota(archivo);
                fseek(buffer, -sizeof(stMascota), SEEK_CUR);
                fwrite(&mascota,sizeof(stMascota),1,buffer);
                encontrado = 1;
                printf("\n[OK] Mascota modificada correctamente.\n");
                break;
            }
        }
        if(encontrado == 0)
        {
            printf("\n[INFO] No se encontro ninguna mascota con ese ID.\n");
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

void eliminarMascota(char archivo[],int id)
{
    FILE* buffer = fopen(archivo,"r+b");
    stMascota mascota;
    int encontrado = 0;
    if(buffer)
    {
        while(fread(&mascota,sizeof(stMascota),1,buffer)>0)
        {
            if(mascota.idMascota == id && mascota.eliminado == 0)
            {
                printf("\n======= ELIMINAR MASCOTA =======\n");
                fseek(buffer, -sizeof(stMascota), SEEK_CUR);
                mascota.eliminado = 1;
                fwrite(&mascota,sizeof(stMascota),1,buffer);
                encontrado = 1;
                printf("\n[OK] Mascota eliminada correctamente.\n");
                break;
            }
        }
        if(encontrado == 0)
        {
            printf("\n[INFO] No se encontro ninguna mascota con ese ID.\n");
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

void buscarMascotaPorId (char archivo[],int id)
{
    FILE* buffer = fopen(archivo,"rb");
    stMascota mascota;
    int encontrado = 0;
    if(buffer)
    {
        while(fread(&mascota,sizeof(stMascota),1,buffer)>0)
        {
            if(mascota.idMascota == id && mascota.eliminado == 0)
            {
                mostrarUnaMascota(mascota);
                encontrado = 1;
                break;
            }
        }
        if(encontrado == 0)
        {
            printf("\n[INFO] No se encontro ninguna mascota con ese ID.\n");
        }
        fclose(buffer);
    }
    else
    {
        printf("\n[ERROR] No se pudo abrir el archivo.\n");
    }
}

void pasarArchiToArr(char archi[],stMascota arr[], int dim)
{
    FILE* buffer = fopen(archi,"rb");
    stMascota mascota;
    int i = 0;

    if(buffer)
    {
        while(fread(&mascota,sizeof(stMascota),1,buffer)> 0 && i < dim)
        {
            if(mascota.eliminado == 0)
            {
                arr[i] = mascota;
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

void mostrarMascotasArr(stMascota arr[],int val)
{
    printf("\n======= LISTADO DE MASCOTAS =======\n");
    for(int i = 0; i < val; i++)
    {
        mostrarUnaMascota(arr[i]);
    }
    printf("\n=================================\n");
}

void insertar(stMascota arr[],int val,stMascota elem)
{
    int i = val - 1;

    while(i >= 0 && strcmpi(elem.nombre,arr[i].nombre)<0)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = elem;
}

void ordenamientoPorInsercion(stMascota arr[],int val)
{
    for(int i = 1; i < val; i++)
    {
        insertar(arr,i,arr[i]);
    }
}
