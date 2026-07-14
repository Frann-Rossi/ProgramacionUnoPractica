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

//EJERCICIO 1
//==================================================
int cantElemPorSeg (char archivoCanciones[]);
void arrDinCanciones(stCancion** arrCanciones,int cant);
int pasarArchiToArrCanciones(char archivoCanciones[],stCancion** arrCanciones);
//==================================================

//EJERCICIO 2
//==================================================
int pasarArchiToArrArtistas(char archivoArtistas[],stArtista** arrArtistas,char generoBuscado[]);
//==================================================

//EJERCICIO 3
//==================================================
int verificaArtista(int idBuscado,char archivoArtistas[]);
void agregarCancion(stCancion cancion,int idBuscado,char archivoArtistas[],char archivoCanciones[]);
//==================================================


//EJERCICIO 4
//==================================================
int mejorRanking(stCancion arrCancione[],int val, int i);
//==================================================

//EJERCICIO 5
//==================================================
void mostrarUnArtista(stArtista artista);
int buscarYMostrarArtista(char archivoArtista[],int idArtistaBuscado);
void mostrarUnaCancion(stCancion cancion);
void mostrarCancionesDeArtista(stCancion arrCanciones[],int val,int idArtistaBuscado, char archivoArtista[]);
//==================================================

//UTILIDADES
//==================================================
char seguir (char msj[]);
int pedirNum (char msj[]);
void menu();
stCancion cargarUnaCancion();
//==================================================

int main()
{
    char control  = 's';
    int opcion;

    char archivoCanciones[] = "archivoCanciones.bin";
    stCancion* arrCancionesDin = NULL;
    int valCancionesDin = 0;

    char archivoArtistas[] = "archivoArtistas.bin";
    stArtista* arrArtistasDin = NULL;
    int valArtistasDin = 0;
    char genero[20];

    stCancion nuevaCancion;
    int idBuscado;

    int posMejorRanking  = 0;
    stCancion mejor;

    int idArtistaBuscado;

    while(control == 's')
    {
        menu();
        opcion = pedirNum("\nIngrese una opcion:");

        switch(opcion)
        {
        case 1:
            valCancionesDin = pasarArchiToArrCanciones(archivoCanciones,&arrCancionesDin);
            break;
        case 2:
            printf("\nIngrese un genero para hacer su arr:");
            scanf("%s",genero);
            valArtistasDin = pasarArchiToArrArtistas(archivoArtistas,&arrArtistasDin,genero);
            break;
        case 3:
            nuevaCancion = cargarUnaCancion();
            idBuscado = pedirNum("\nIngrese un id para buscar y agregar la cancion:");
            agregarCancion(nuevaCancion,idBuscado,archivoArtistas,archivoCanciones);
            break;
        case 4:
            posMejorRanking  = mejorRanking(arrCancionesDin,valCancionesDin,0);
            mejor = arrCancionesDin[posMejorRanking];
            printf("\nMejor raking %d",mejor.topRanking);
            break;
        case 5:
            idArtistaBuscado = pedirNum("\nIngrese un id del artista para mostrar informacion:");
            mostrarCancionesDeArtista(arrCancionesDin,valCancionesDin,idArtistaBuscado,archivoArtistas);
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....");
            break;
        default:
            printf("\nIngrese una opcion valida");
        }

        if(control == 's')
        {
            control = seguir("\nDesea seguir en el programa 's/n'");
        }
    }

    return 0;
}

//UTILIDADES
//==================================================
void menu()
{
    printf("\nPasar archivo de canciones a ARR dinamico == 1");
    printf("\nArr dinamico de generos == 2");
    printf("\nAgregar nueva cancion == 3");
    printf("\nMostrar mejor ranking == 4");
    printf("\nMostrar artista y canciones == 5");
    printf("\nSalir == 0");
}

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

stCancion cargarUnaCancion()
{
    stCancion cancion;
    printf("Ingrese ID de la cancion");
    scanf("%d",&cancion.idCancion);
    printf("Ingrese ID del artista");
    scanf("%d",&cancion.idArtista);
    printf("Ingrese duracion de la cancion");
    scanf("%d",&cancion.duracion);
    printf("Ingrese nombre de la cancion");
    scanf("%s",cancion.nombreCancion);
    printf("Ingrese Ranking de la cancion");
    scanf("%d",&cancion.topRanking);
    return cancion;
}
//==================================================


//EJERCICIO 1
//==================================================
int cantElemPorSeg (char archivoCanciones[])
{
    FILE* buffer = fopen(archivoCanciones,"rb");
    stCancion cancion;
    int cant = 0;
    if(buffer)
    {
        while(fread(&cancion,sizeof(stCancion),1,buffer)>0)
        {
            if(cancion.duracion > 120 && cancion.duracion < 240)
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

void arrDinCanciones(stCancion** arrCanciones,int cant)
{
    *arrCanciones = malloc(cant*sizeof(stCancion));
}

int pasarArchiToArrCanciones(char archivoCanciones[],stCancion** arrCanciones)
{
    FILE* buffer = fopen(archivoCanciones,"rb");
    stCancion cancion;

    int cant = cantElemPorSeg(archivoCanciones);
    arrDinCanciones(arrCanciones,cant);
    int i = 0;

    if(buffer)
    {
        while(fread(&cancion,sizeof(stCancion),1,buffer)>0)
        {
            if(cancion.duracion > 120 && cancion.duracion < 240)
            {
                (*arrCanciones)[i] = cancion;
                i++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return i;
}
//==================================================

//EJERCICIO 2
//==================================================
int pasarArchiToArrArtistas(char archivoArtistas[],stArtista** arrArtistas,char generoBuscado[])
{
    FILE* buffer = fopen(archivoArtistas,"rb");
    stArtista artista;
    int i = 0;
    int dim = 10;
    *arrArtistas = malloc(dim*sizeof(stArtista));

    if(buffer)
    {
        while(fread(&artista,sizeof(stArtista),1,buffer)>0)
        {
            if(strcmpi(artista.generoPrincipal,generoBuscado)== 0)
            {
                if(dim == i)
                {
                    dim += 10;
                    *arrArtistas = realloc(*arrArtistas,dim*sizeof(stArtista));
                }
                (*arrArtistas)[i] = artista;
                i++;
            }
        }
        fclose(buffer);
    }
    return i;
}
//==================================================

//EJERCICIO 3
//==================================================
int verificaArtista(int idBuscado,char archivoArtistas[])
{
    FILE* buffer = fopen(archivoArtistas,"rb");
    stArtista artista;
    int flag = 0;

    if(buffer)
    {
        while(fread(&artista,sizeof(stArtista),1,buffer)>0)
        {
            if(artista.idArtista == idBuscado)
            {
                flag = 1;
                break;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return flag;
}

void agregarCancion(stCancion cancion,int idBuscado,char archivoArtistas[],char archivoCanciones[])
{
    FILE* buffer = fopen(archivoCanciones,"ab");
    int existe = verificaArtista(idBuscado,archivoArtistas);

    if(buffer)
    {
        if(existe)
        {
            fwrite(&cancion,sizeof(stCancion),1,buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//EJERCICIO 4
//==================================================
int mejorRanking(stCancion arrCancione[],int val, int i)
{
    int posMejorRanking = i;
    if(i < val - 1)
    {
        posMejorRanking = mejorRanking(arrCancione,val,i+1);
        if(arrCancione[i].topRanking < arrCancione[posMejorRanking].topRanking)
        {
            posMejorRanking = i;
        }

    }
    return posMejorRanking;
}
//==================================================

//EJERCICIO 5
//==================================================
void mostrarUnArtista(stArtista artista)
{
    printf("\nId artista:%d",artista.idArtista);
    printf("\nNombre:%s",artista.nombre);
    printf("\nNacionalidad:%s",artista.nacionalidad);
    printf("\nGenero principal:%s",artista.generoPrincipal);
}

int buscarYMostrarArtista(char archivoArtista[],int idArtistaBuscado)
{
    FILE* buffer = fopen(archivoArtista,"rb");
    stArtista artista;
    int flag = 0;

    if(buffer)
    {
        while(fread(&artista,sizeof(stArtista),1,buffer)>0)
        {
            if(idArtistaBuscado == artista.idArtista)
            {
                mostrarUnArtista(artista);
                flag = 1;
                break;
            }
        }
        fclose(buffer);

    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return flag;
}

void mostrarUnaCancion(stCancion cancion)
{
    printf("\nId cancion:%d",cancion.idCancion);
    printf("\nId artista:%d",cancion.idArtista);
    printf("\nDuracion:%d",cancion.duracion);
    printf("\nNombre de la cancion:%s",cancion.nombreCancion);
    printf("\nTop Ranking:%d",cancion.topRanking);
}

void mostrarCancionesDeArtista(stCancion arrCanciones[],int val,int idArtistaBuscado, char archivoArtista[])
{
    int existe = buscarYMostrarArtista(archivoArtista,idArtistaBuscado);
    if(existe)
    {
        for(int i = 0; i < val; i++)
        {
            if(arrCanciones[i].idArtista == idArtistaBuscado)
            {
                mostrarUnaCancion(arrCanciones[i]);
            }
        }
    }
    else
    {
        printf("\nId no existe intente devuelta");
    }
}
//==================================================
