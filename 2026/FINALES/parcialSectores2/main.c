#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{

    return 0;
}

// ==================================================
// Ejercicio 1

int buscarSector(char archivoSector[],int id)
{
    FILE* buffer = fopen(archivoSector,"rb");
    stSector sector;
    int flag = 0;
    if(buffer)
    {
        while(fread(&sector,sizeof(stSector),1,buffer)>1)
        {
            if(sector.id == id)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    return flag;
}

stSector copiarSector(char archivoSector[],int id)
{
    FILE* buffer = fopen(archivoSector,"rb");
    stSector sectorActual;
    stSector auxSector;
    if(buffer)
    {
        while(fread(&sectorActual,sizeof(stSector),1,buffer)>1)
        {
            if(sectorActual.id == id)
            {
                auxSector = sectorActual;
            }
        }
        fclose(buffer);
    }
    return auxSector;
}

stVendedor cargarUnVendedor(char archivoSector[],int id)
{
    stVendedor vendedor;
    printf("\nIngrese DNI:");
    scanf("%s",vendedor.dni);
    printf("\nIngrese nombre y apellido:");
    fgets(vendedor.nombreYapellido,sizeof(vendedor.nombreYapellido),stdin);
    printf("\nIngrese monto vendido")
    int sectorEncontrado = buscarSector(archivoSector,id)
    printf("\nIngrese un id de sector para agregar");
    while(sectorEncontrado == 1)
    {
        vendedor.sector = copiarSector(archivoSector,id);
    }
    return vendedor
}

int cargarVendedores(stVendedor arrVendedor[],int dim,char archivoSector[],int id)
{
    int i = 0;
    char control = 's';
    while(control == 's' && i < dim)
    {
        arrVendedor[i] = cargarUnVendedor(archivoSector,id);
        printf("\nDesea seguir cargando vendedores???");
        scanf(" %c",&control);
    }
    return i;
}
// ==================================================


