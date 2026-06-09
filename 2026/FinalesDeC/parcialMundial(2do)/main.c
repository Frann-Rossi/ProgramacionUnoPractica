#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre[20];
    char apellido[20];
    char pais[20];
    int edad;
} stFigurita;

char continuar(char msj[])
{
    char control;
    printf("%s",msj);
    scanf(" %c",&control);
    return control;
}

void menuTexto()
{
    printf("\nCargar archivo de FIGURITAS == 1");
    printf("\nSalir del Programa == 0");
    printf("\nIngrese una opcion:");
}


stFigurita cargarUnaFigurita ()
{
    char control = 's';
    stFigurita figu;
    do
    {
        printf("\nIngrese una edad mayor a 18 y menor a 40: ");
        scanf("%d",&figu.edad);

    }
    while(18 >= figu.edad || 40 <= figu.edad);
    printf("\nIngrese ID:");
    scanf("%d",&figu.id);
    printf("\nIngrese NOMBRE:");
    scanf("%s",figu.nombre);
    printf("\nIngrese APELLIDO:");
    scanf("%s",figu.apellido);
    printf("\nIngrese PAIS:");
    scanf("%s",figu.pais);
    return figu;
}

void cargarArchivo(char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");
    stFigurita figu;
    char control = 's';

    if(buffer)
    {
        while(control == 's')
        {
            figu = cargarUnaFigurita();
            fwrite(&figu,sizeof(stFigurita),1,buffer);
            control = continuar("\nDesea seguir cargando figuritas 's/n':");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo...\n");
    }
}

void mostrarUnaFigurita (stFigurita figu)
{
    printf("\nID:|%d|",figu.id);
    printf("\nNOMBRE:|%s|",figu.nombre);
    printf("\nAPELLIDO:|%s|",figu.apellido);
    printf("\nPAIS:|%s|",figu.pais);
    printf("\nEDAD:|%d|",figu.edad);
}

void mostrarArchivoRecu(FILE* buffer)
{
    stFigurita figu;
    if(fread(&figu,sizeof(stFigurita),1,buffer)>0)
    {
        mostrarUnaFigurita(figu);
        mostrarArchivoRecu(buffer);
    }
}

void arrDin(stFigurita** arr,int cant)
{
    (*arr) = realloc(*arr,cant*sizeof(stFigurita));
}

int cantElementosArchi(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stFigurita);
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo...\n")
    }
    return cant;
}

int pasarArchivoToArr(char archivo[],stFigurita** arr)
{
    FILE* buffer = fopen(archivo,"rb");
    stFigurita figu;
    int i = 0;

    if(buffer)
    {
        while(fread(&figu,sizeof(stFigurita),1,buffer)>0)
        {
            arrDin(arr,i+1);
            (*arr)[i] = figu;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo...\n");
    }
    return i;
}

int suma(stFigurita arr[],int val, int i)
{
    int suma = 0;
    if(i < val)
    {
        suma = arr[i].edad + suma(arr,val,i+1);
    }

    return suma;
}

float promedioEdades (stFigurita arr[],int val)
{
    float promedio = 0;
    promedio = (float)suma(arr,val,i+1) / val;
    return promedio
}

int buscarPosMenor (char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int posMenor = 0;

    if(buffer)
    {
        fseek(buffer,posMenor * sizeof(stFigurita),SEEK_SET);
        fclose(buffer);
    }
    return posMenor;
}

void figuritaMenor(char archivo[], int edad)
{
    FILE* buffer = fopen(archivo,"r+b");
    stFigurita figu;
    if(buffer)
    {
        while(fread(&figu,sizeof(stFigurita),1,buffer)>0)
        {
            if(figu.edad < edad)
            {
                fseek(buffer,-sizeof(stFigurita),SEEK_CUR);
                figu.edad *= 2;
                fwrite(&figu,sizeof(stFigurita),1,buffer);
            }
        }
        fclose(buffer);
    }
}


int main()
{
    char control = 's';
    int opcion;

    char archiFigus[] = "figuritas.bin";
    FILE* buffer;

    while(control == 's')
    {
        menuTexto();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarArchivo(archiFigus);
            break;
        case 2:
            buffer = fopen(archiFigus,"rb");
            if(buffer)
            {
                mostrarArchivoRecu(buffer);
                fclose(buffer);
            }
            else
            {
                printf("\nError al abrir el archivo...\n");
            }
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....\n");
            break;
        default:
            printf("\nIngrese un valor valido...\n");
        }
        if(control == 's')
        {
            control = continuar("\nDesea seguir en el programa 's/n':");
        }
    }
    return 0;
}
