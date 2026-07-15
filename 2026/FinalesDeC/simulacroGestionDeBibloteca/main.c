#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int idAutor;
    char nombreYapellido[5];
    char nacionalidad[3];
} stAutor;

typedef struct
{
    int idLibro;
    int idAutor; // Relación con el autor
    char titulo[5];
    int cantidadPaginas;
    float precio;
} stLibro;

//EJERCICIO 1
//==================================================
int cantElemTamPag(char archivoLibros[]);
void arrDinLibros(stLibro** arrLibros,int cant);
int pasarArchiToArrLibros(char archivoLibros[],stLibro** arrLibros);
//==================================================

//EJERCICIO 2
//==================================================
void mostrarUnLibro(stLibro libro);
void mostrarLibrosRecu(stLibro arrLibros[],int val, int i);
//==================================================

//EJERCICIO 3
//==================================================
int buscarIdLibroMasCaro(char archivoLibros[]);
void modificarPrecio(char archivoLibros[]);
//==================================================


//EJERCICIO 4
//==================================================
void guardarLibrosDeAutor(char archivoLibros[],int idAutorBuscado,Pila* libroAuth)
//==================================================

int main()
{
    return 0;
}

//EJERCICIO 1
//==================================================
int cantElemTamPag(char archivoLibros[])
{
    FILE* buffer = fopen(archivoLibros,"rb");
    stLibro libro;
    int cant = 0;

    if(buffer)
    {
        while(fread(&libro,sizeof(stLibro),1,buffer)>0)
        {
            if(libro.cantidadPaginas > 300)
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

void arrDinLibros(stLibro** arrLibros,int cant)
{
    *arrLibros = malloc(cant*sizeof(stLibro));
}

int pasarArchiToArrLibros(char archivoLibros[],stLibro** arrLibros)
{
    FILE* buffer = fopen(archivoLibros,"rb");
    stLibro libro;

    int cant = cantElemTamPag(archivoLibros);
    arrDinLibros(arrLibros,cant);
    int i = 0;

    if(buffer)
    {
        while(fread(&libro,sizeof(stLibro),1,buffer)>0)
        {
            if(libro.cantidadPaginas > 300)
            {
                (*arrLibros)[i] = libro;
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
void mostrarUnLibro(stLibro libro)
{
    printf("\nId libro %d",libro.idLibro);
    printf("\nId autor %d",libro.idAutor);
    printf("\nTitulo %s",libro.titulo);
    printf("\nCantidad de Paginas %d",libro.cantidadPaginas);
    printf("\nPrecio %.2f",libro.precio);
}

void mostrarLibrosRecu(stLibro arrLibros[],int val, int i)
{
    if(i < val)
    {
        if(arrLibros[i].precio > 5000)
        {
            mostrarUnLibro(arrLibros[i]);
        }
        mostrarLibrosRecu(arrLibros,val,i+1);
    }
}
//==================================================

//EJERCICIO 3
//==================================================
int buscarIdLibroMasCaro(char archivoLibros[])
{
    FILE* buffer = fopen(archivoLibros,"rb");
    stLibro libro;
    float precioMasAlto = -1;
    int idMasCaro = -1;

    if(buffer)
    {
        while(fread(&libro,sizeof(stLibro),1,buffer)>0)
        {
            if(libro.precio > precioMasAlto)
            {
                precioMasAlto = libro.precio;
                idMasCaro = libro.idLibro;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return idMasCaro;
}

void modificarPrecio(char archivoLibros[])
{
    FILE* buffer = fopen(archivoLibros,"r+b");
    stLibro libro;

    int idMasCaro = buscarIdLibroMasCaro(archivoLibros);

    if(buffer)
    {
        while(fread(&libro,sizeof(stLibro),1,buffer)>0)
        {
            if(idMasCaro == libro.idLibro)
            {
                fseek(buffer,-(long)sizeof(stLibro),SEEK_CUR);
                libro.precio -= libro.precio * 0.15;
                fwrite(&libro,sizeof(stLibro),1,buffer);
                break;
            }
        }
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//EJERCICIO 4
//==================================================
void guardarLibrosDeAutor(char archivoLibros[],int idAutorBuscado,Pila* libroAuth)
{
    FILE* buffer = fopen(archivoLibros,"rb");
    stLibro libro;

    if(buffer)
    {
        while(fread(&libro,sizeof(stLibro),1,buffer)>0)
        {
            if(libro.idAutor == idAutorBuscado)
            {
                apilar(libroAuth,libro.idLibro);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================
