#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idDireccion;
    char nombre[30];
    char apellido[30];
    int cantPremios;
    int cantPelisDirigidas;
} stDireccion;

typedef struct
{
    int idPelicula;
    char nombre[30];
    int minutosDuracion;
    char genero[30];
    char pais[30];
    int tipoMetraje;
    int idDireccion;
} stPelicula;

char seguir(char msj[])
{
    char opcion;
    printf("%s",msj);
    scanf(" %c",&opcion);
    return opcion;
}

int pedirNum (char msj[])
{
    int num;
    printf("%s",msj);
    scanf("%d",&num);
    return num;
}

void menu()
{
    printf("\nEJ 1 == 1");
    printf("\nSalir == 0");
}



//Ejercicio 1
//==================================================
stDireccion cargarUnaDireccion()
{
    stDireccion direccion;
    printf("\n=====Cargando Direccion=====");
    printf("\nIngrese ID de la DIRECCION:");
    scanf("%d",&direccion.idDireccion);
    printf("\nIngrese NOMBRE:");
    scanf("%s",direccion.nombre);
    printf("\nIngrese APELLIDO:");
    scanf("%s",direccion.apellido);
    printf("\nIngrese Cant de PREMIOS:");
    scanf("%d",&direccion.cantPremios);
    printf("\nIngrese Cant de PELIS DIRIGIDAS:");
    scanf("%d",&direccion.cantPelisDirigidas);
    return direccion;
}


void cargarArchivoDirecciones(char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");
    stDireccion direccion;
    char control = 's';
    if(buffer)
    {
        while(control == 's')
        {
            direccion = cargarUnaDireccion();
            fwrite(&direccion,sizeof(stDireccion),1,buffer);
            control = seguir("\nDesea seguir cargando DIRECCION en el ARCHIVO 's/n':");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

int existeDireccion(char archivoDireccion[],int idBuscado)
{
    FILE* buffer = fopen(archivoDireccion,"rb");
    stDireccion direccion;
    int flag = 0;

    if(buffer)
    {
        while(fread(&direccion,sizeof(stDireccion),1,buffer)>0 && flag == 0)
        {
            if(direccion.idDireccion == idBuscado)
            {
                flag = 1;
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

stPelicula cargarUnaPelicula(char archivoDireccion[])
{
    stPelicula pelicula;

    printf("\n=====Cargando Peliculas=====");
    do
    {
        printf("\nIngrese ID de la DIRECCION:");
        scanf("%d",&pelicula.idDireccion);

        if(existeDireccion(archivoDireccion,pelicula.idDireccion) == 0)
        {
            printf("\nEse id no existe elija otro");
        }
    }
    while(existeDireccion(archivoDireccion,pelicula.idDireccion) == 0);
    printf("\nIngrese ID pelicula:");
    scanf("%d",&pelicula.idPelicula);
    printf("\nIngrese nombre:");
    scanf("%s",pelicula.nombre);
    pelicula.tipoMetraje = -9;
    return pelicula;
}

void cargarArchivoPeliculas (char archivoPelis[],char archivoDireccion[])
{
    FILE* buffer = fopen(archivoPelis,"wb");
    stPelicula pelis;
    char control = 's';
    if(buffer)
    {
        while(control == 's')
        {
            pelis = cargarUnaPelicula(archivoDireccion);
            fwrite(&pelis,sizeof(stPelicula),1,buffer);
            control = seguir("\nDesea seguir cargando PELICULAS 's/n':");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//Ejercicio 2
//==================================================
void modTipoMetraje(char archivoPelis[])
{
    FILE* buffer = fopen(archivoPelis,"r+b");
    stPelicula pelis;
    int cortometraje = 0;
    int largometraje = 1;

    if(buffer)
    {
        while(fread(&pelis,sizeof(stPelicula),1,buffer)>0)
        {
            if(pelis.minutosDuracion > 45)
            {
                pelis.tipoMetraje = largometraje;
            }
            else
            {
                pelis.tipoMetraje = cortometraje;
            }
            fseek(buffer,-sizeof(stPelicula),SEEK_CUR);
            fwrite(&pelis,sizeof(stPelicula),1,buffer);
        }
        fclose(buffer);
    }
}
//==================================================

//Ejercicio 3
//==================================================
void arrDinPelis(stPelicula** arr, int cant)
{
    *arr = calloc(cant,sizeof(stPelicula));
}

int cantElemPelis(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stPelicula);
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return cant;
}

int pasarArchiToArr (char archivoPelis[],stPelicula** arr)
{
    FILE* buffer = fopen(archivoPelis,"rb");
    stPelicula pelis;
    int cant = cantElemPelis(archivoPelis);
    arrDinPelis(arr,cant);
    int i = 0;
    if(buffer)
    {
        while(fread(&pelis,sizeof(stPelicula),1,buffer)>0)
        {
            (*arr)[i] = pelis;
            i++;
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

//Ejercicio 4
//==================================================
void mostrarUnaPelicula(stPelicula pelicula)
{
    printf("\nID de la DIRECCION:%d",pelicula.idDireccion);
    printf("\nID pelicula:%d",pelicula.idPelicula);
    printf("\nNombre:%s",pelicula.nombre);
    printf("\Tipo METRAJE:%d",pelicula.tipoMetraje);
}

void mostrarGenero(stPelicula arr[],int val, int i, char genero[])
{
    if(i < val)
    {
        if(strcmpi(arr[i].genero,genero) == 0)
        {
            mostrarUnaPelicula(arr[i]);
        }
        mostrarGenero(arr,val,i+1,genero);
    }
}
//==================================================

//Ejercicio 5
//==================================================
int contarPelisDeUnPais(stPelicula arr[],int val, int i,char paisBuscado[])
{
    int cont = 0;

    if(i < val)
    {
        if(strcmpi(arr[i].pais,paisBuscado)== 0)
        {
            cont++;
        }
        cont = cont + contarPelisDeUnPais(arr,val,i+1,paisBuscado);
    }
    return cont;
}
//==================================================


int main()
{
    char control = 's';
    int opcion;

    while(control == 's')
    {
        menu();
        opcion = pedirNum("\nIngrese una opcion:");
        switch(opcion)
        {
        case 1:
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....");
            break;
        default:
            printf("\nIngrese un valor valido");
        }
        if(control == 's')
        {
            control = seguir("\nDesea seguir en el programa 's/n':");
        }
    }
    return 0;
}
