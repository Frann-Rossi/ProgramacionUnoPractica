#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int id;
    char nombreSector[30];
    float comisionesPorVenta;
    int sueldoBasicoDelSector;
} stSector;

typedef struct
{
    char dni[10];
    char nombreYapellido[40];
    stSector sector;
    int montoVendido;
} stVendedor;

//EJERCICIO 1
//==================================================
stVendedor cargarUnVendedor(char archivoSector[]);
int cargarVendedores(stVendedor arrVendedores[],int dim,char archivoSector[]);
stSector cargarUnSector(char archivoSector[],int idSector);
int buscarSector(char archivoSector[],int idSector);
//==================================================

//EJERCICIO 2
//==================================================
void mostrarUnSector(stSector sector);
void mostrarUnVendedor(stVendedor vendedor);
void mostrarVendedores(stVendedor arrVendedores[],int val);
//==================================================

//EJERCICIO 3
//==================================================s
void guardarMontosVendidos(stVendedor arrVendedores[], int val, Pila* ropa, Pila* calzado);
//==================================================

//EJERCICIO 4
//==================================================
void cargarArchivoVendedores(char archivoVendedores[],stVendedor arrVenedodres[],int val);
//==================================================

//EJERCICIO 5
//==================================================
void mostrarVendedoresRecu(FILE* buffer);
//==================================================

//EJERCICIO 6
//==================================================
void modificarNombreApellido(char archivoVendedores[],char dniBuscado[]);
//==================================================

//EJERCICIO 7
//==================================================
int contarCantDeUnSector(char archivoVendedores[],char sectorBuscado[]);
void pasarDeArchiToArrDin(char archivoVendedores[],char sectorBuscado[],stVendedor arrVendedores[]);
int arrDinVendedores(stVendedor** arrVendedores,char archivoVendedores[],char sectorBuscado[]);
//==================================================

char seguir(char msj[]);
int pedirNum(char msj[]);
void menu();

int main()
{
    char control = 's';
    int opcion;

    char archivoSectores[] = "archivoSectores.bin";
    stVendedor arrVendedores[30];
    int valVendedores = 0;

    Pila ropa;
    Pila calzado;
    inicpila(&ropa);
    inicpila(&calzado);

    char archivoVendedores[] = "archivoVendedores.bin";

    FILE* buffer = fopen(archivoVendedores,"rb");

    char dni[15];

    stVendedor* arrVendedoresDin = NULL;
    char sector[15];
    int valVendedoresDin = 0;

    while(control == 's')
    {
        menu();
        opcion = pedirNum("\nIngrese una opcion:");
        switch(opcion)
        {
        case 1:
            valVendedores = cargarVendedores(arrVendedores,30,archivoSectores);
            break;
        case 2:
            mostrarVendedores(arrVendedores,valVendedores);
            break;
        case 3:
            guardarMontosVendidos(arrVendedores,valVendedores,&ropa,&calzado);
            printf("\nROPA");
            mostrar(&ropa);
            printf("\nCALZADO");
            mostrar(&calzado);
            break;
        case 4:
            cargarArchivoVendedores(archivoVendedores,arrVendedores,valVendedores);
            break;
        case 5:
            if(buffer)
            {
                mostrarVendedoresRecu(buffer);
                fclose(buffer);
            }
            else
            {
                printf("\Error al abrir el archivo");
            }
            break;
        case 6:
            printf("\nIngrese DNI para Modificar:");
            scanf("%s",&dni);
            modificarNombreApellido(archivoVendedores,dni);
            break;
        case 7:
            printf("\nIngrese SECTOR para CARGAR en ARR dinamico:");
            scanf("%s",&sector);
            valVendedoresDin = arrDinVendedores(&arrVendedoresDin,archivoVendedores,sector);
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....");
            break;
        }

        if(control == 's')
        {
            control = seguir("\nDesea seguir en el programa 's/n':");
        }
    }

    return 0;
}

void menu()
{
    printf("\nCargar ARR de VENDEDORES == 1");
    printf("\nMostrar ARR de VENDEDORES == 2");
    printf("\nGuardar VENTAS en PILAS == 3");
    printf("\nCargar ARCHIVO de VENDEDORES == 4");
    printf("\nMostrar ARCHIVO de VENDEDORES Recu == 5");
    printf("\nModificar NOMBRE y APELLIDO de VENDEDORES == 6");
    printf("\nArr DIN de VENDEDORES de los SECTORES == 7");
    printf("\nSalir == 0");
}

char seguir(char msj[])
{
    char control;
    printf("%s",msj);
    scanf(" %c",&control);
    return control;
}

int pedirNum(char msj[])
{
    int num;
    printf("%s",msj);
    scanf("%d",&num);
    return num;
}

//EJERCICIO 1
//==================================================
stVendedor cargarUnVendedor(char archivoSector[])
{
    stVendedor vendedor;
    int idSector;
    int existe = 0;
    printf("\nIngrese DNI del VENDEDOR:");
    scanf("%s",vendedor.dni);
    printf("\nIngrese NOMBRE y APELLIDO del VENDEDOR:");
    fflush(stdin);
    gets_s(vendedor.nombreYapellido,sizeof(vendedor.nombreYapellido));
    printf("\nIngrese el MONTO VENDIDO del VENDEDOR:");
    scanf("%d",&vendedor.montoVendido);
    do
    {
        printf("\nIngrese el ID del SECTOR para cargar en el VENDEDOR:");
        scanf("%d",&idSector);
        existe = buscarSector(archivoSector,idSector);

        if(existe)
        {
            vendedor.sector = cargarUnSector(archivoSector,idSector);
        }
        else
        {
            printf("\nEl sector no existe. Ingrese otro.");
        }
    }
    while(existe == 0);
    return vendedor;
}

int cargarVendedores(stVendedor arrVendedores[],int dim,char archivoSector[])
{
    int i = 0;
    char control = 's';

    while(control == 's' && i < dim)
    {
        arrVendedores[i] = cargarUnVendedor(archivoSector);
        i++;
        control = seguir("\nDesea seguir cargando VENDEDORES 's/n':");
    }
    return i;
}

stSector cargarUnSector(char archivoSector[],int idSector)
{
    FILE* buffer = fopen(archivoSector,"rb");
    stSector sector;
    stSector sectorAux;

    if(buffer)
    {
        while(fread(&sector,sizeof(stSector),1,buffer)>0)
        {
            if(sector.id == idSector)
            {
                sectorAux = sector;
            }
            else
            {
                printf("\Error el id no existe ingrese otro");
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return sectorAux;
}

int buscarSector(char archivoSector[],int idSector)
{
    FILE* buffer = fopen(archivoSector,"rb");
    stSector sector;
    int flag = 0;

    if(buffer)
    {
        while(fread(&sector,sizeof(stSector),1,buffer)>0)
        {
            if(sector.id == idSector)
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
//==================================================

//Ejercicio 2
//==================================================
void mostrarUnSector(stSector sector)
{
    printf("\nId Sector:%d",sector.id);
    printf("\nNombre del Sector:%s",sector.nombreSector);
    printf("\nComision del Sector:%.2f",sector.comisionesPorVenta);
    printf("\nSueldos del Sector:%d",sector.sueldoBasicoDelSector);
}

void mostrarUnVendedor(stVendedor vendedor)
{
    printf("\nDni del Vendedor:%s",vendedor.dni);
    printf("\nNombre y Apellido del Vendedor:%s",vendedor.nombreYapellido);
    printf("\nMonto Vendido del Vendedor:%d",vendedor.montoVendido);
    mostrarUnSector(vendedor.sector);
}

void mostrarVendedores(stVendedor arrVendedores[],int val)
{
    for(int i = val - 1; i >= 0; i--)
    {
        mostrarUnVendedor(arrVendedores[i]);
    }
}
//==================================================

//Ejercicio 3
//==================================================
void guardarMontosVendidos(stVendedor arrVendedores[], int val, Pila* ropa, Pila* calzado)
{
    for(int i = 0; i < val; i++)
    {
        if(stricmp(arrVendedores[i].sector.nombreSector,"ropa")== 0)
        {
            apilar(ropa,arrVendedores[i].montoVendido);
        }
        else if(stricmp(arrVendedores[i].sector.nombreSector,"calzado")== 0)
        {
            apilar(calzado,arrVendedores[i].montoVendido);
        }
    }
}
//==================================================

//Ejercicio 4
//==================================================
void cargarArchivoVendedores(char archivoVendedores[],stVendedor arrVenedodres[],int val)
{
    FILE* buffer = fopen(archivoVendedores,"wb");
    stVendedor vendedor;

    if(buffer)
    {
        fwrite(&arrVenedodres,sizeof(stVendedor),val,buffer);
        fclose(buffer);
    }
}
//==================================================

//Ejercicio 5
//==================================================
void mostrarVendedoresRecu(FILE* buffer)
{
    stVendedor vendedor;
    if(fread(&vendedor,sizeof(stVendedor),1,buffer)>0)
    {
        mostrarUnVendedor(vendedor);
        mostrarVendedoresRecu(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//Ejercicio 6
//==================================================
void modificarNombreApellido(char archivoVendedores[],char dniBuscado[])
{
    FILE* buffer = fopen(archivoVendedores,"r+b");
    stVendedor vendedor;

    if(buffer)
    {
        while(fread(&vendedor,sizeof(stVendedor),1,buffer)>0)
        {
            if(strcmpi(vendedor.dni,dniBuscado)== 0)
            {
                fseek(buffer,-sizeof(stVendedor),SEEK_CUR);
                printf("\nIngrese el nuevo NOMBRE y APELLIDO:");
                scanf("%s",vendedor.nombreYapellido);
                fwrite(&vendedor,sizeof(vendedor),1,buffer);
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

//Ejercicio 7
//==================================================
int contarCantDeUnSector(char archivoVendedores[],char sectorBuscado[])
{
    FILE* buffer = fopen(archivoVendedores,"rb");
    stVendedor vendedor;

    int cant = 0;

    if(buffer)
    {
        while(fread(&vendedor,sizeof(stVendedor),1,buffer)>0)
        {
            if(strcmpi(vendedor.sector.nombreSector,sectorBuscado)== 0)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    return cant;
}

void pasarDeArchiToArrDin(char archivoVendedores[],char sectorBuscado[],stVendedor arrVendedores[])
{
    FILE* buffer = fopen(archivoVendedores,"rb");
    stVendedor vendedor;

    int i = 0;
    if(buffer)
    {
        while(fread(&vendedor,sizeof(stVendedor),1,buffer)>0)
        {
            if(strcmpi(vendedor.sector.nombreSector,sectorBuscado)== 0)
            {
                arrVendedores[i] = vendedor;
                i++;
            }
        }
        fclose(buffer);
    }
}

int arrDinVendedores(stVendedor** arrVendedores,char archivoVendedores[],char sectorBuscado[])
{
    int cant = contarCantDeUnSector(archivoVendedores,sectorBuscado);
    *arrVendedores = malloc(cant*sizeof(stVendedor));
    if (cant > 0)
    {
        *arrVendedores = malloc(cant * sizeof(stVendedor));
        pasarDeArchiToArrDin(archivoVendedores, sectorBuscado, *arrVendedores);
    }
    return cant;
}
//==================================================
