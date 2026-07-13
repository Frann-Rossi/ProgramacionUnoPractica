#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idArtista;
    char nombre[50];
    char nacionalidad[50];
    char generoPrincipal[100];
} stArtista;

typedef struct
{
    int idCancion;
    int idArtista; //Relacion con el artista
    int duracion; //En segundos
    char nombreCancion[50];
    int topRanking;
} stCancion;

char seguir (char msj[])
{
    char control;
    printf("%s",msj);
    scanf(" %c",&control);
    return control;
}

int pedirNum (char msj[])
{
    int num;
    printf("%s",msj);
    scanf("%d",&num);
    return num;
}

//EJERCICIO 1
//==================================================
void arrDinCanciones(stCancion** arr, int cant)
{
    *arr = calloc(cant,sizeof(stCancion));
}

int cantDeElemPorDuracion(char archivoCanciones[])
{
    FILE* buffer = fopen(archivoCanciones,"rb");
    stCancion cancion;
    int cant = 0;

    if(buffer)
    {
        while(fread(&cancion,sizeof(stCancion),1,buffer)>0)
        {
            if(cancion.duracion > 120 && cancion.duracion  < 240)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return cant;
}

int cargarCanciones(char archivoCanciones[],stCancion** arrCanciones)
{
    FILE* buffer = fopen(archivoCanciones,"rb");
    stCancion cancion;
    int i = 0;
    int cant = cantDeElemPorDuracion(archivoCanciones);
    arrDinCanciones(arrCanciones,cant);

    if(buffer)
    {
        while(fread(&cancion,sizeof(stCancion),1,buffer)>0)
        {
            if(cancion.duracion > 120 && cancion.duracion  < 240)
            {
                (*arrCanciones)[i] = cancion;
                i++;
            }
        }
        fclose(buffer);
    }
    return i;
}
//==================================================

//EJERCICIO 2
//==================================================
void redimensionarArrCanciones(stArtista** arrArtistas,int cant)
{
    *arrArtistas = realloc(*arrArtistas,cant*sizeof(stArtista));
}

int cargarArtistasPorCancion(char archivoArtistas[],char genero[],stArtista** arrArtista)
{
    FILE* buffer = fopen(archivoArtistas,"rb");
    stArtista artista;
    int i = 0;
    int dim = 10;
    *arrArtista = malloc(dim * sizeof(stArtista));

    if(buffer)
    {
        while(fread(&artista,sizeof(stArtista),1,buffer)>0)
        {
            if(strcmpi(artista.generoPrincipal,genero)==0)
            {
                if(i == dim)
                {
                    dim += 10;
                    redimensionarArrCanciones(arrArtista,dim);
                }
                (*arrArtista)[i] = artista;
                i++;
            }
        }
        fclose(buffer);
    }
    return i;
}
//==================================================

int main()
{
    return 0;
}
