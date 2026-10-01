#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30

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


// ==================================================
// Ejercicio 1
int existeSector(char archivoSector[],int id);
stSector copiarSector(char archivoSector[],int id);
stVendedor cargarUnVendedor(char archivoSector[]);
int cargarVendedores(stVendedor arrVendedor[],int dim,char archivoSector[]);
// ==================================================

// ==================================================
// Ejercicio 2
void mostrarUnSector(stSector sector);
void mostrarUnVendedor(stVendedor vendedor);
void mostrarVendedores(stVendedor arrVendedores[], int val);
// ==================================================

// ==================================================
// Ejercicio 3
void pasarVentas(stVendedor arrVendedores[], int val,Pila* ropa, Pila* calzado);
// ==================================================

int main()
{
    char archivoSector[] = "archivoSectores.bin";
    stVendedor arrVendedor[DIM];
    int valVendedor = cargarVendedores(arrVendedor,DIM,archivoSector);

    mostrarVendedores(arrVendedor,valVendedor);

    return 0;
}

// ==================================================
// Ejercicio 1

int existeSector(char archivoSector[],int id)
{
    FILE* buffer = fopen(archivoSector,"rb");
    stSector sector;
    int flag = 0;
    if(buffer)
    {
        while(fread(&sector,sizeof(stSector),1,buffer) > 0)
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
        while(fread(&sectorActual,sizeof(stSector),1,buffer) > 0)
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

stVendedor cargarUnVendedor(char archivoSector[])
{
    stVendedor vendedor;
    printf("\nIngrese DNI:");
    scanf("%s",vendedor.dni);
    fflush(stdin);
    printf("\nIngrese nombre y apellido:");
    gets(vendedor.nombreYapellido);
    fflush(stdin);
    printf("\nIngrese el monto vendido:");
    scanf("%d",vendedor.montoVendido);

    printf("\nIngrese un id de sector para agregar:");
    int id;
    scanf("%d", &id);
    int sectorEncontrado = existeSector(archivoSector,id);
    while(sectorEncontrado == 0)
    {
        printf("\nSector inexistente. Ingrese otro ID:");
        scanf("%d", &id);

        sectorEncontrado = existeSector(archivoSector, id);
    }
    vendedor.sector = copiarSector(archivoSector, id);
    return vendedor;
}

int cargarVendedores(stVendedor arrVendedor[],int dim,char archivoSector[])
{
    int i = 0;
    char control = 's';
    while(control == 's' && i < dim)
    {
        arrVendedor[i] = cargarUnVendedor(archivoSector);
        i++;
        printf("\nDesea seguir cargando vendedores???");
        scanf(" %c",&control);
    }
    return i;
}
// ==================================================

// ==================================================
// Ejercicio 2
void mostrarUnSector(stSector sector)
{
    printf("\n===SECTOR===");
    printf("\nID %d",sector.id);
    printf("\nNombre sector %s",sector.nombreSector);
    printf("\nComision por venta %.2f",sector.comisionesPorVenta);
    printf("\nSueldo basico %d",sector.sueldoBasicoDelSector);
}
void mostrarUnVendedor(stVendedor vendedor)
{
    printf("\n===VENDEDOR===");
    printf("\nDni %s",vendedor.dni);
    printf("\nNombre y Apellido %s",vendedor.nombreYapellido);
    printf("\nMonto Vendido %d",vendedor.montoVendido);
    mostrarUnSector(vendedor.sector);
}
void mostrarVendedores(stVendedor arrVendedores[], int val)
{
    for(int i = val-1; i >= 0; i--)
    {
        mostrarUnVendedor(arrVendedores[i]);
    }
}
// ==================================================


// ==================================================
// Ejercicio 3
void pasarVentas(stVendedor arrVendedores[], int val,Pila* ropa, Pila* calzado)
{
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(arrVendedores[i].sector,"ropa") == 0)
        {
            apilar(ropa,arrVendedores[i].montoVendido);
        }

        if(strcmpi(arrVendedores[i].sector,"calzado") == 0)
        {
            apilar(calzado,arrVendedores[i].montoVendido);
        }
    }
}
// ==================================================


