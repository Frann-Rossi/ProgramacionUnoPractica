#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int dni;
    char nombre [20];
    char apellido [20];
} ClienteSt;

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
    ModeloSt modelo;
    ClienteSt cliente;
    int entregado; // 1 -> entregado y 0 -> no entregado (por defecto cuando se crea es 0).
} PedidoSt;


void arrDinModelo(ModeloSt** arrModelo, int cant);
int cantElem(char archivoModelos[]);
int pasarArchiToArrModel(char archivoModelo[],ModeloSt** arrModelo);

//Ejercicio 1
//==================================================
void mostrarUnModelo(ModeloSt modelo);
void mostrarModelosRecu(ModeloSt arrModelos[],int val, int i);
//==================================================

//Ejercicio 2
//==================================================
void mostrarModelosPorMarca(ModeloSt arrModelos[],int val, char marcaBuscada[]);
//==================================================

//Ejercicio 3
//==================================================
int guardarMarcas(ModeloSt arrModelo[],int val, char arrDeMarca[][20]);
int existePalabra(char arrPalabras[][20],int val,char arrPalabrasSinRepetir[][20]);
//==================================================

//Ejercicio 4
//==================================================
ClienteSt cargarUnCliente();
int buscarId(ModeloSt arrModelos[],int val,int idBuscado);
ModeloSt cargarUnModelo(ModeloSt arrModelos[],int val,int idBuscado);
PedidoSt cargarUnPedido(ModeloSt arrModelos[],int val);
void cargarPedidos(char archivoPedidos[],int dim,ModeloSt arrModelos[],int val);
//==================================================

//Ejercio 5
//==================================================
void modificarEstado(char archivoPedidos[],int dni,int id,int pos);
//==================================================

//Ejercicio 6
//==================================================
void pasarPreciosToPila(char archivoPedidos[],Pila* precio);
int sumarPrecioPila(Pila precio);
//==================================================

int main()
{
    ModeloSt* arrModelo = NULL;
    int valModelosDin = 0;
    char archivoModelo[] = "modelos.bin";
    valModelosDin = pasarArchiToArrModel(archivoModelo,&arrModelo);

    char marcaBuscada[20];

    char arrMarcas[10][20];
    int valMarcas = 0;
    char arrMarcasSinRepetir[10][20];
    int valMarcasSinRepetir = 0;

    char archivoPedidos[] = "pedidos.bin";

    Pila precio;
    inicpila(&precio);
    int sumPrecio = 0;

    //Ejercicio 1
    mostrarModelosRecu(arrModelo,valModelosDin,0);

    //Ejercicio 2
    printf("\nIngrese una marca a buscar:");
    scanf("%s",&marcaBuscada);
    mostrarModelosPorMarca(arrModelo,valModelosDin,marcaBuscada);

    //Ejercicio 3
    valMarcas = guardarMarcas(arrModelo,valModelosDin,arrMarcas);
    valMarcasSinRepetir =  guardarMarcasSinRepetir(arrMarcas,valMarcas,arrMarcasSinRepetir);

    //Ejercicio 4
    cargarPedidosArchivo(archivoPedidos,arrModelo,valModelosDin);
    //Ejercicio 5

    modificarEstado(archivoPedidos,3872713,1,0);

    //Ejercicio 6
    pasarPreciosToPila(archivoPedidos,&precio);
    sumPrecio = sumarPrecioPila(precio);
    printf("\nLa suma fue de:%d",sumPrecio);
    return 0;
}


//==================================================
void arrDinModelo(ModeloSt** arrModelo, int cant)
{
    *arrModelo = malloc(cant* sizeof(ModeloSt));
}

int cantElem(char archivoModelos[])
{
    FILE* buffer = fopen(archivoModelos,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(ModeloSt);
        fclose(buffer);
    }
    return cant;
}

int pasarArchiToArrModel(char archivoModelo[],ModeloSt** arrModelo)
{
    FILE* buffer = fopen(archivoModelo,"rb");
    ModeloSt modelo;
    int i = 0;
    if(buffer)
    {
        while(fread(&modelo,sizeof(ModeloSt),1,buffer)>0)
        {
            (*arrModelo)[i] = modelo;
        }
        fclose(buffer);
    }
    return i;
}
//==================================================


//Ejercicio 1
//==================================================
void mostrarUnModelo(ModeloSt modelo)
{
    printf("\nID:%d",modelo.id);
    printf("\nNombre:%s",modelo.nombre);
    printf("\nMarca:%s",modelo.marca);
    printf("\nAnio de lanzamiento:%d",modelo.anioLanzamineto);
    printf("\nPrecio de lista:%d",modelo.precioDeLista);
}

void mostrarModelosRecu(ModeloSt arrModelos[],int val, int i)
{
    if(i < val)
    {
        mostrarUnModelo(arrModelos[i]);
        mostrarModelosRecu(arrModelos,val,i+1);
    }
}
//==================================================

//Ejercicio 2
//==================================================
void mostrarModelosPorMarca(ModeloSt arrModelos[],int val, char marcaBuscada[])
{
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(arrModelos[i].marca,marcaBuscada)== 0)
        {
            mostrarUnModelo(arrModelos[i]);
        }
    }
}
//==================================================


//Ejercicio 3
//==================================================
int guardarMarcas(ModeloSt arrModelo[],int val, char arrPalabras[][20])
{
    int j = 0;
    for(int i = 0; i < val; i++)
    {
        strcpy(arrPalabras[j],arrModelo[i].marca);
        j++;
    }
    return j;
}

int existePalabra(char arrPalabras[][20],int val,char arrPalabrasSinRepetir[][20])
{
    int flag = 0;
    int j = 0;
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(arrPalabras[i],arrPalabrasSinRepetir[j]== 0))
        {
            flag = 1;
            j++;
        }
    }
    return flag;
}

int guardarMarcasSinRepetir(char arrPalabras[][20],int val,char arrPalabrasSinRepetir[][20])
{
    int j = 0;
    int existe = existePalabra(arrPalabras,val,arrPalabrasSinRepetir);
    for(int i = 0; i < val; i++)
    {
        if(existe == 0)
        {
            strcpy(arrPalabrasSinRepetir[j],arrPalabras[i]);
            j++;
        }
    }
    return j;
}
//==================================================

//Ejercicio 4
//==================================================
ClienteSt cargarUnCliente()
{
    ClienteSt cliente;
    printf("\nIngrese DNI:");
    scanf("%d",&cliente.dni);
    printf("\nIngrese Nombre:");
    scanf("%s",cliente.nombre);
    printf("\nIngrese Apellido:");
    scanf("%s",cliente.apellido);
}

int buscarId(ModeloSt arrModelos[],int val,int idBuscado)
{
    int flag = 0;
    for(int i = 0; i < val; i++)
    {
        if(arrModelos[i].id == idBuscado)
        {
            flag = 1;
        }
    }
    return flag;
}

ModeloSt cargarUnModelo(ModeloSt arrModelos[],int val,int idBuscado)
{
    ModeloSt modelo;
    for(int i = 0; i < val; i++)
    {
        if(arrModelos[i].id == idBuscado)
        {
            modelo = arrModelos[i];
        }
    }
    return modelo;
}

PedidoSt cargarUnPedido(ModeloSt arrModelos[],int val)
{
    PedidoSt pedido;
    int idBuscado;
    int existe;
    do
    {
        printf("\nIngrese ID para buscar y ser agregado:");
        scanf("%d",&idBuscado);
        existe = buscarId(arrModelos,val,idBuscado);
        if(existe)
        {
            pedido.modelo = cargarUnModelo(arrModelos,val,idBuscado);
        }
        else
        {
            printf("\nEl ID no existe intente de nuevo");
        }
    }
    while(existe == 0);
    pedido.cliente = cargarUnCliente();
    pedido.entregado = 0;
    printf("\nIngrese si el pedido fue entra '1=si' y '0=no'");
    scanf("%d",pedido.entregado);
    return pedido;

}

void cargarPedidosArchivo(char archivoPedidos[],ModeloSt arrModelos[],int val)
{
    FILE* buffer = fopen(archivoPedidos,"wb");
    PedidoSt pedido;
    char control = 's';

    if(buffer)
    {
        while(control == 's')
        {
            pedido = cargarUnPedido(arrModelos,val);
            fwrite(&pedido,sizeof(PedidoSt),1,buffer);
            printf("\nDesea seguir cargando pedidos 's/n':");
            scanf(" %c",&control);
        }
        fclose(buffer);
    }


}
//==================================================

//Ejercio 5
//==================================================
void modificarEstado(char archivoPedidos[],int dni,int id,int pos)
{
    FILE* buffer = fopen(archivoPedidos,"r+b");
    PedidoSt pedido;
    if(buffer)
    {
        if(dni == pedido.cliente.dni && id == pedido.modelo.id)
        {
            fseek(buffer,pos*sizeof(PedidoSt),SEEK_SET);
            pedido.entregado = 1;
            fwrite(&pedido,sizeof(PedidoSt),1,buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//Ejercicio 6
//==================================================
void pasarPreciosToPila(char archivoPedidos[],Pila* precio)
{
    FILE* buffer = fopen(archivoPedidos,"rb");
    PedidoSt pedido;
    if(buffer)
    {
        if(pedido.entregado == 1)
        {
            apilar(precio,pedido.entregado);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

int sumarPrecioPila(Pila precio)
{
    int sum = 0;
    while(!pilavacia(&precio))
    {
        sum += desapilar(&precio);
    }
    return sum;
}
//==================================================
