#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int id;
    char nombre[20];
    char marca[20];
    int anioLanzamineto;
    int precioDeLista;
} ModeloSt;

// ==================================================
//EJERCIO 0
int cantElementos(char archivoModelo[]);
void crearArrDinModelo(ModeloSt** arrModelo,int cant);
int cargarArrModelo(char archivoModelo[],ModeloSt** arrModelo);
// ==================================================

// ==================================================
//EJERCIO 1
void mostrarUnModelo(ModeloSt modelo);
void mostrarArrRecuDeModelo(ModeloSt arrModelo[],int val,int i);
// ==================================================

// ==================================================
//EJERCIO 2
void mostrarArrPorMarca(ModeloSt arrModelo[],int val, char marca[]);
// ==================================================

// ==================================================
// ==================================================


const char archivoModelo[] = "modelos.bin";

int main()
{
    ModeloSt* arrDinModelo = NULL;
    int val = cargarArrModelo(archivoModelo,arrDinModelo);


    mostrarArrRecuDeModelo(arrDinModelo,val,i);

    return 0;
}


// ==================================================
//EJERCIO 0
int cantElementos(char archivoModelo[])
{
    FILE* buffer = fopen(archivoModelo,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(ModeloSt);
        fclose(buffer);
    }
    return cant;
}

void crearArrDinModelo(ModeloSt** arrModelo,int cant)
{
    *arrModelo = malloc(cant * sizeof(ModeloSt));
}

int cargarArrModelo(char archivoModelo[],ModeloSt** arrModelo)
{
    int cant = cantElementos(archivoModelo);
    FILE* buffer = fopen(archivoModelo,"rb");
    crearArrDinModelo(archivoModelo,arrModelo);
    int i = 0;
    if(buffer)
    {
        fread(*arrModelo,sizeof(ModeloSt),cant,buffer);
        fclose(buffer);
    }
    return cant;
}
// ==================================================

// ==================================================
//EJERCIO 1
void mostrarUnModelo(ModeloSt modelo)
{
    printf("\nID:%d",modelo.id);
    printf("\nNombre:%s",modelo.nombre);
    printf("\nMarca:%s",modelo.marca);
    printf("\nAnio Lanzamiento:%d",modelo.anioLanzamineto);
    printf("\nPrecio Lista:%d",modelo.precioDeLista);

}

void mostrarArrRecuDeModelo(ModeloSt arrModelo[],int val,int i)
{
    if(i < val)
    {
        mostrarUnModelo(arrModelo[i]);
        mostrarArrRecuDeModelo(arrModelo,val,i+1);
    }
}
// ==================================================


// ==================================================
//EJERCIO 2
void mostrarArrPorMarca(ModeloSt arrModelo[],int val, char marca[])
{
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(arrModelo[i],marca) == 0)
        {
            mostrarUnModelo(arrModelo[i]);
        }
    }
}
// ==================================================

// ==================================================
//EJERCIO 3

int marcarRepetida(char marca[],int val, char arrMarcas[][30])
{
    int flag = 0;
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(arrMarcas[i],marca)== 0)
        {
            flag = 1;
        }
    }
    return flag;
}

int guardarArrDeMarcasSinRepetir(ModeloSt arrModelo[],int val,char arrMarcas[10][30])
{
    int j = 0;
    for(int i = 0; i < val; i++)
    {
        if(!marcarRepetida(arrModelo[i].marca,val,arrMarcas))
        {
            strcpy(arrMarcas[j],arrModelo);
            j++;
        }

    }
    return j;
}
// ==================================================
