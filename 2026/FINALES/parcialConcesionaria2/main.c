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

typedef struct
{
    int dni;
    char nombre [20];
    char apellido [20];
} ClienteSt;

typedef struct
{
    ModeloSt modelo;
    ClienteSt cliente;
    int entregado; // 1 -> entregado y 0 -> no entregado (por defecto cuando se crea es 0).
} PedidoSt;


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
//EJERCIO 3
int guardarArrDeMarcasSinRepetir(ModeloSt arrModelo[],int val,char arrMarcas[10][30]);
// ==================================================


const char archivoModelo[] = "modelos.bin";

int main()
{
    ModeloSt* arrDinModelo = NULL;
    int val = cargarArrModelo(archivoModelo,arrDinModelo);


//    mostrarArrRecuDeModelo(arrDinModelo,val,i);
    char arrDeMarcas[10][30];
    int valMarcas = guardarArrDeMarcasSinRepetir(arrDinModelo,val,arrDeMarcas);

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
        if(strcmpi(arrModelo[i].marca,marca) == 0)
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


// ==================================================
//EJERCIO 4
ClienteSt cargarUnCliente()
{
    ClienteSt cliente;
    printf("\nIngrese el dni del cliente:");
    scanf("%d",&cliente.dni);
    printf("\nIngrese el nombre del cliente:");
    scanf("%d",&cliente.nombre);
    printf("\nIngrese el apellido del cliente:");
    scanf("%d",&cliente.apellido);
    return cliente;

}


int buscarPosModelo(ModeloSt arrModelo[],int val,int id)
{
    int flag = -1;

    for(int i = 0; i < val; i++)
    {
        if(arrModelo[i].id == id)
        {
            flag = i;
        }
    }
    return flag;
}
ClienteSt inicCliente()
{
    ClienteSt nuevo;
    strcpy(nuevo.apellido,"No creado");
    strcpy(nuevo.nombre,"No creado");
    nuevo.dni=-1;
}
ModeloSt inicModelo()
{
    ModeloSt nuevo;
    nuevo.anioLanzamineto=-1;
    nuevo.id=-1;
    strcpy(nuevo.marca,"No creado");
    strcpy(nuevo.nombre,"No creado");
    nuevo.precioDeLista=-1;
}
PedidoSt inicPedido()
{
    PedidoSt nuevo;
    nuevo.entregado = -1;
    nuevo.cliente = inicCliente();
    nuevo.modelo=inicModelo();
}
PedidoSt cargarUnPedido(ModeloSt arrModelo[],int val,int id)
{
    ModeloSt modelo;
    PedidoSt pedidoNuevo=inicPedido();
    int pos = buscarPosModelo(arrModelo,val,id);
    if(pos != -1)
    {
        pedidoNuevo.modelo = arrModelo[pos];
        pedidoNuevo.cliente = cargarUnCliente();
        pedidoNuevo.entregado = 0;
    }
    else
    {
        printf("Id no fue encontrado");
    }
    return pedidoNuevo;

}

void cargarPedidos(char archivoPedidos[],ModeloSt arrModelo[],int val,int id)
{
    FILE* buffer = fopen(archivoPedidos,"ab");
    PedidoSt pedido;

    if(buffer)
    {
        pedido = cargarUnPedido(arrModelo,val,id);
        fwrite(&pedido,sizeof(PedidoSt),1,buffer);
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
// ==================================================


// ==================================================
//EJERCIO 5
void modificarPedido(char archivoPedidos[],int dni,int idModelo)
{
    FILE buffer = fopen(archivoPedidos,"r+b");
    PedidoSt pedido;
    if(buffer)
    {
        while(fread(&pedido,sizeof(PedidoSt),1,buffer)>0)
        {
            if(pedido.cliente.dni == dni && pedido.modelo.id == idModelo && pedido.entregado == 0)
            {
                fseek(buffer,-pedido,SEEK_CUR);
                pedido.entregado = 1;
                fwrite(&pedido,sizeof(PedidoSt),1,buffer);
            }
        }

        fclose(buffer);
    }
    else
        printf("\nError en la apertura del archivo.");
}
// ==================================================
