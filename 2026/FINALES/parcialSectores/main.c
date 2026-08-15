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
stVendedor cargarUnVendedor()
{
    stVendedor vendedor;
    printf("\nIngrese DNI del vendedor:");
    scanf("%s",vendedor.dni);
    printf("\nIngrese NOMBRE y APELLIDO del vendedor:");
    scanf("%s",vendedor.nombreYapellido);
    printf("\nIngrese MONTO VENDIDO del vendedor:");
    scanf("%s",vendedor.nombreYapellido);
    return vendedor;
}

int cargarVendedores(stVendedor arr[],int dim,char archivoSector[])
{
    int i = 0;
    char control = 's';

    int id;
    int idSector;
    while (control == 's' && i < dim)
    {
        id = pedirNum("\nIngrese un id SECTOR para ser cargado");
        idSector = buscarId(archivoSector,id);
        if(idSector == 1)
        {
            pasarArchiToArr(archivo,arr,i);
        }
        arr[i] = cargarUnVendedor();
        i++;
        control = seguir("\nDesea seguir cargando VENDEDORES 's/n':");
    }
    return i;
}

void pasarArchiToArr(char archivoSector[], stVendedor arr[],int* i)
{
    FILE* buffer = fopen(archivoSector,"rb");
    stSector sector;
    int val = 0;
    if(buffer)
    {
        while(fread(&sector,sizeof(stSector),1,buffer)>0)
        {
            arr[i].sector = sector;
            val++
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }

    *i = val;
}

int buscarId(char archivoSector[],int buscarId)
{
    FILE* buffer = fopen(archivoSector,"rb");
    stSector sector;
    int flag = 0;

    if(buffer)
    {
        while(fread(&sector,sizeof(stSector),1,buffer)>0)
        {
            if(sector.id == buscarId)
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
//==================================================


//Ejercio 2
//==================================================
void mostrarUnSector(stSector sector)
{
    printf("\nID del SECTOR:%d",sector.id);
    printf("\nNOMBRE del SECTOR:%s",sector.nombreSector);
    printf("\nCOMISIONES POR VENTA del SECTOR:%.2f",sector.comisionesPorVenta);
    printf("\nSUELDO BASICO del SECTOR:%d",sector.sueldoBasicoDelSector);
}

void mostrarUnVendedor(stVendedor vendedor)
{
    printf("\nDNI del vendedor:%s",vendedor.dni);
    printf("\nNOMBRE y APELLIDO del vendedor:%s",vendedor.nombreYapellido);
    printf("\nMONTO VENDIDO del vendedor:%s",vendedor.nombreYapellido);
    mostrarUnSector(vendedor.sector);
}

void mostrarVendedores (stVendedor arr[],int val)
{
    int i = val - 1;

    while(i >= 0)
    {
        mostrarUnVendedor(arr[i]);
    }
}
//==================================================

//Ejercio 3
//==================================================
void guardarMontosVendidos(stVendedor arr[],int val, Pila* ropa, Pila* calzado)
{
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(arr[i].sector.nombreSector,"ropa")== 0 && strcmpi(arr[i].sector.nombreSector,"calzado")== 0)
        {
            apilar(ropa,arr[i].sector.comisionesPorVenta);
            apilar(calzado,arr[i].sector.comisionesPorVenta);
        }
    }
}
//==================================================

//Ejercicio 4
//==================================================
void guardarArchiVendedor(char archivoVendedor[],stVendedor arr[],int val)
{
    FILE* buffer = fopen(archivoVendedor,"wb");
    stVendedor vendedor;
    if(buffer)
    {
        for(int i = 0; i < val; i++)
        {
            fwrite(&arr[i],sizeof(stVendedor),1,buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }

}
//==================================================

//Ejercicio 5
//==================================================
void mostrarArchiVendedores(FILE* buffer)
{
    stVendedor vendedor;
    if(fread(&vendedor,sizeof(vendedor),1,buffer)>0)
    {
        mostrarUnVendedor(vendedor);
        mostrarArchiVendedores(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//Ejercio 6
//==================================================
void modificarNombreApellidoArchivo(char archivo[],int dniBuscado)
{
    FILE* buffer = fopen(archivo,"r+b");
    stVendedor vendedor;

    if(buffer)
    {
        while(fread(&vendedor,sizeof(stVendedor),1,buffer)>0)
        {
            if(vendedor.sector.id == dniBuscado)
            {
                fseek(buffer,-sizeof(stVendedor),SEEK_CUR);
                printf("\nIngrese NUEVO Nombre y Apellido:");
                scanf("%s",vendedor.nombreYapellido);
                fwrite(&vendedor,sizeof(stVendedor),1,buffer);
            }
        }
        fclose(buffer);
    }
}
//==================================================

//Ejercicio 7
//==================================================
void arrDinVendedores(stVendedor** arr, int cant)
{
    *arr = calloc(cant,sizeof(stVendedor));
}

int cantDeElemDeUnSector(char archivoVendedores[],char sector[])
{
    FILE* buffer = fopen(archivoVendedores,"rb");
    stVendedor vendedor;

    int cant = 0;

    if(buffer)
    {
        while(fread(&vendedor,sizeof(stVendedor),1,buffer)>0)
        {
            if(strcmpi(vendedor.sector.nombreSector,sector)== 0)
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

int arrDeSector(char archivoVendedores[],char sector[],stVendedor** arr)
{
    FILE* buffer = fopen(archivoVendedores,"rb");
    stVendedor vendedor;
    int cant = cantDeElemDeUnSector(archivoVendedores,sector);
    arrDinVendedores(*arr,cant);
    int i = 0;

    if(buffer)
    {
        while(fread(&vendedor,sizeof(stVendedor),1,buffer)>0)
        {
            if(strcmpi(vendedor.sector.nombreSector,sector)== 0)
            {
                (*arr)[i] = vendedor;
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

char seguir (char msj[])
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

void menu()
{
    printf("\nCargar ARR de VENDEDORES == 1");
    printf("\nMostrar ARR de VENDEDORES == 2");
    printf("\nPasar a PILA de ropa y calzado == 3");
    printf("\nGuardar Archivo VENDEDORES == 4");
    printf("\n == 5");
}

int main()
{
    char control = 's';
    int opcion;


    char archivoSectores = "archivoSectores.bin";
    stVendedor arrVendedores[20];
    int valVendedores = 0;

    Pila ropa;
    Pila calzado;
    inicpila(&ropa);
    inicpila(&calzado);

    char archivoVendedores = "archivoVendedores.bin";
    FILE* buffer;

    while(contrlol == 's')
    {
        menu();
        opcion = pedirNum("\nIngrese una opcion:");
        switch(opcion)
        {
        case 1:
            valVendedores = cargarVendedores(arrVendedores,20,archivoSectores)
                            break;
        case 2:
            mostrarVendedores(arrVendedores,valVendedores);
            break;
        case 3:
            guardarMontosVendidos(arrVendedores,valVendedores,&ropa,&calzado);
            mostrar(&ropa);
            mostrar(&calzado);
            break;
        case 4:
            guardarArchiVendedor(archivoVendedores,arrVendedores,valVendedores);
            break;
        case 5:
            if(buffer)
            {
                mostrarArchiVendedores(buffer);
                fclose(buffer);
            }
            else
            {
                printf("\nError al abrir el archivo");
            }
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....");
            break;
        default:
            printf("\nIngrese un valor valido:");
        }
        if(control == 's')
        {
            control = seguir("\nDesea seguir en el programa 's/n'");
        }
    }
    return 0;
}
