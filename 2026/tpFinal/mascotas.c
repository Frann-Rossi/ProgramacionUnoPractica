#include <stdio.h>
#include <stdlib.h>

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
    cargarEspecie(mascota.especie);
    printf("\nRaza Mascota:");
    scanf("%s",mascota.raza);
    printf("\nEdad Mascota:");
    scanf("%d",&mascota.edad);
    printf("\nID Duenio:");
    scanf("%d",&mascota.idDuenio);
    return mascota;
}
void cargarEspecie(char especie[])
{
    char especies[][DIM] =
    {
        "Perro",
        "Gato",
        "Pajaro",
        "Otro"
    };

    int opcion;

    printf("\n====== ESPECIE ======\n");

    for(int i = 0; i < 4; i++)
    {
        printf("%d. %s\n", i + 1, especies[i]);
    }

    printf("Seleccione una opcion: ");
    scanf("%d",&opcion);

    if(opcion >= 1 && opcion <= 4)
    {
        strcpy(especie, especies[opcion - 1]);
    }
    else
    {
        printf("\n[ERROR] Opcion invalida.\n");
        strcpy(especie,"Desconocido");
    }
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

void eliminarMascota(char archivo[],int id, Pila* pila)
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
                apilar(pila,id);
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

void pasarArchiToArrMascotas(char archi[],stMascota arr[], int dim)
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

    while(i >= 0 && elem.edad < arr[i].edad)
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

void mostrarMascotasConDuenios(char archiMascotas[],char archiDuenios[])
{
    FILE* bufferM = fopen(archiMascotas,"rb");
    FILE* bufferD;
    stMascota mascota;
    stDuenio duenio;
    if(bufferM)
    {
        while(fread(&mascota,sizeof(stMascota),1,bufferM) > 0)
        {
            bufferD = fopen(archiDuenios,"rb");
            if(bufferD)
            {
                while(fread(&duenio,sizeof(stDuenio),1,bufferD) > 0)
                {
                    if(mascota.idDuenio == duenio.idDuenio &&
                            mascota.eliminado == 0 &&
                            duenio.eliminado == 0)
                    {
                        mostrarUnaMascotaConDuenio(mascota,duenio);
                    }
                }
                fclose(bufferD);
            }
        }
        fclose(bufferM);
    }
}

void mostrarUnaMascotaConDuenio(stMascota mascota, stDuenio duenio)
{
    printf("\n====================================");
    printf("\n        MASCOTA Y DUENIO");
    printf("\n====================================");

    printf("\nMascota : %s", mascota.nombre);
    printf("\nEspecie : %s", mascota.especie);
    printf("\nRaza    : %s", mascota.raza);

    printf("\n------------------------------------");

    printf("\nDuenio  : %s %s",
           duenio.nombre,
           duenio.apellido);

    printf("\nTelefono: %s", duenio.telefono);

    printf("\n====================================\n");
}

