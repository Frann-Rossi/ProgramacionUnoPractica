#include <stdio.h>
#include <stdlib.h>

#define DIM 30

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

void ejercicio1()
{
    printf("\n--- Ejercicio 1: Punteros y Dobles Punteros ---\n");

    // 1. Declaración (Tal cual lo hiciste)
    int valor = 10; // Le doy un valor inicial para ver algo
    int * pint = &valor;
    int ** ppint = &pint;

    // 2. Mostrar direcciones (Pide direcciones de valor, pint y ppint)
    // Usamos %p para direcciones y (void*) para evitar warnings, o %d si tu compilador es viejo.
    printf("\n--- Direcciones de Memoria ---\n");
    printf("Direccion de variable 'valor' (&valor): %p \n", &valor);
    printf("Direccion que guarda 'pint' (pint):     %p \n", pint); // Debe coincidir con la de arriba

    printf("\nDireccion propia de 'pint' (&pint):     %p \n",&pint);
    printf("Direccion que guarda 'ppint' (ppint):   %p \n",ppint); // Debe coincidir con la de arriba

    printf("\nDireccion propia de 'ppint' (&ppint):   %p \n",&ppint);

    // 3. Asignar valores usando los punteros (Lo que te faltaba)
    printf("\n--- Modificacion de Valores ---\n");

    // Modificar usando puntero simple
    *pint = 20;
    printf("Valor modificado con *pint: %d\n", valor);

    // Modificar usando puntero doble (doble indirección)
    **ppint = 30;
    printf("Valor modificado con **ppint: %d\n", valor);
}

int cargarArr(int arr[],int dim)
{
    char control = 's';
    int i = 0;

    while(control == 's' && i < dim)
    {
        printf("Ingrese un numero para el arr:");
        scanf("%d",&arr[i]);
        i++;
        printf("Desea seguir cargando Numero en el arr 's/n':");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}

int contarNumPares(int arr[], int val)
{
    int cant = 0;
    for(int i = 0; i < val; i++)
    {
        if(arr[i] % 2 == 0)
        {
            cant++;
        }
    }
    return cant;
}

void pasarArrAArrDim(int arrEstatico[],int val,int arrDim[])
{
    int j = 0;
    for(int i = 0; i < val; i++)
    {
        if(arrEstatico[i] % 2 == 0)
        {
            arrDim[j] = arrEstatico[i];
            j++;
        }
    }
}

void mostrarArr(int arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%d|",arr[i]);
    }
    puts("");
}

int* crearArregloB(int arrEstatico[], int val, int cantPares)
{
    int* nuevoArr = malloc(cantPares * sizeof(int));

    if (nuevoArr == NULL)
    {
        return NULL; // Si falla, devolvemos NULL
    }

    int j = 0;
    for(int i = 0; i < val; i++)
    {
        if(arrEstatico[i] % 2 == 0)
        {
            nuevoArr[j] = arrEstatico[i];
            j++;
        }
    }
    return nuevoArr;
}


void crearArregloC(int arrEstatico[], int val, int cantPares, int ** arrDoble)
{
    *arrDoble = malloc(cantPares * sizeof(int));

    if (*arrDoble == NULL)
    {
        return;
    }

    int j = 0;
    for(int i = 0; i < val; i++)
    {
        if(arrEstatico[i] % 2 == 0)
        {
            (*arrDoble)[j] = arrEstatico[i];
            j++;
        }
    }
}

int cantElemArchivo(char nombreArchivo[])
{
    int cant = 0;
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stAlumno);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir archivo\n");
    }
    return cant;
}

void pasarArchivoAArrDim (stAlumno arrAlum[], char nombreArchivo[],int val)
{
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        for(int i = 0; i < val; i++)
        {
            fread(&arrAlum[i],sizeof(stAlumno),1,buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error en abrir el archivo\n");
    }
}
void mostrarAlumnos(stAlumno arr[], int val)
{
    printf("\n--- LISTA DE ALUMNOS ---\n");
    for(int i = 0; i < val; i++)
    {
        printf("Legajo: %d | Nombre: %s | Edad: %d\n",
               arr[i].legajo, arr[i].nombreYapellido, arr[i].edad);
    }
    printf("------------------------\n");
}

int main()
{
    char control = 's';
    int opcion;
    int arregloEstatico[DIM];
    int val;
    int cantPares;
    int *arrDim = NULL;
    stAlumno *arrDimAlum = NULL;

    char archivoAlum[] = "datosAlum.dat";

    while(control == 's')
    {
        printf("\n--- TRABAJO PRACTICO 8: PUNTEROS DOBLES Y DINAMICOS ---\n");
        printf("1.  Ej 1: Direcciones y Asignaciones (Punteros Dobles)\n");
        printf("------------------------------------------------------\n");
        printf("2.  Ej 2a: Arreglo Pares (Malloc en Main)\n");
        printf("3.  Ej 2b: Arreglo Pares (Malloc en Func + Return)\n");
        printf("4.  Ej 2c: Arreglo Pares (Malloc en Func + Doble Puntero)\n");
        printf("------------------------------------------------------\n");
        printf("5.  Ej 3a: Alumnos Archivo (Malloc en Main)\n");
        printf("6.  Ej 3b: Alumnos Archivo (Malloc en Func + Return)\n");
        printf("7.  Ej 3c: Alumnos Archivo (Malloc en Func + Doble Puntero)\n");
        printf("------------------------------------------------------\n");
        printf("8.  Ej 4: Redimensionar Arreglo (Realloc)\n");
        printf("------------------------------------------------------\n");
        printf("0.  Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            ejercicio1();
            break;
        case 2:
            val = cargarArr(arregloEstatico,DIM);
            printf("+++++\n");
            printf("ARR ESTATICO\n");
            mostrarArr(arregloEstatico,val);
            printf("+++++\n");
            cantPares = contarNumPares(arregloEstatico,val);
            arrDim = malloc(cantPares * sizeof(int));
            pasarArrAArrDim(arregloEstatico,val,arrDim);
            printf("+++++\n");
            printf("ARR DIM\n");
            mostrarArr(arrDim,cantPares);
            printf("+++++\n");
            break;
        case 3:
            val = cargarArr(arregloEstatico,DIM);
            printf("+++++\n");
            printf("ARR ESTATICO\n");
            mostrarArr(arregloEstatico,val);
            printf("+++++\n");
            cantPares = contarNumPares(arregloEstatico, val);
            arrDim = crearArregloB(arregloEstatico,val,cantPares);
            printf("+++++\n");
            printf("ARR DIM\n");
            mostrarArr(arrDim,cantPares);
            printf("+++++\n");
            break;
        case 4:
            val = cargarArr(arregloEstatico,DIM);
            printf("+++++\n");
            printf("ARR ESTATICO\n");
            mostrarArr(arregloEstatico,val);
            printf("+++++\n");
            cantPares = contarNumPares(arregloEstatico, val);
            crearArregloC(arregloEstatico,val,cantPares,&arrDim);
            printf("+++++\n");
            printf("ARR DIM\n");
            mostrarArr(arrDim,cantPares);
            printf("+++++\n");
            break;
        case 5:
            val = cantElemArchivo(archivoAlum);
            arrDimAlum = malloc(val * sizeof(stAlumno));
            pasarArchivoAArrDim(arrDimAlum, archivoAlum, val);
            mostrarAlumnos(arrDimAlum,val);
            break;
        case 0:
            control = 'n';
            printf("Saliendo.....");
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        if(control == 's')
        {
            printf("Desea seguir en el programa 's/n':");
            fflush(stdin);
            scanf("%c",&control);
        }
    }
    return 0;
}
