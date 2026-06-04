#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alumno.h"


// Ejercicio 4
// ==================================================
stAlumno cargarAlumno()
{
    stAlumno alumno;
    printf("\n=====CARGANDO ALUMNO=====\n");
    printf("Ingrese Legajo:");
    scanf("%d",&alumno.legajo);
    printf("\nIngrese Nombre Y Apellido:");
    scanf("%29s",&alumno.nombreYapellido);
    printf("\nIngrese la Edad:");
    scanf("%d",&alumno.edad);
    printf("\nIngrese el Anio:");
    scanf("%d",&alumno.anio);
    return alumno;
}

void cargarAlumnosEnArchivo(char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");
    char control = 's';
    stAlumno alumno;

    if(buffer)
    {
        while(control == 's')
        {
            alumno = cargarAlumno();
            fwrite(&alumno, sizeof(stAlumno), 1, buffer);
            printf("Desea seguir cargando Alumnos 's/n':");
            scanf(" %c", &control);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }

}
// ==================================================

// Ejercicio 5
// ==================================================
void mostrarAlumno(stAlumno alumno)
{
    printf("\n------------------------\n");
    printf("Legajo: %d\n", alumno.legajo);
    printf("Nombre: %s\n", alumno.nombreYapellido);
    printf("Edad: %d\n", alumno.edad);
    printf("Anio: %d\n", alumno.anio);
    printf("------------------------\n");
}

void mostrarAlumnosArchivo(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;

    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer)>0)
        {
            mostrarAlumno(alumno);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}
// ==================================================

// Ejercicio 6
// ==================================================
void agregarAlumno(char archivo[])
{
    FILE* buffer = fopen(archivo,"ab");
    stAlumno alumno;

    if(buffer)
    {
        alumno = cargarAlumno();
        fwrite(&alumno,sizeof(stAlumno),1,buffer);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}
// ==================================================

// Ejercicio 7
// ==================================================
void pasarLegajosAPila (char archivo[],Pila* a)
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;
    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer) > 0)
        {
            if(alumno.edad >= 18)
            {
                apilar(a,alumno.legajo);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}
// ==================================================

// Ejercicio 8
// ==================================================
int contarCantDeAlumnosMayorDeEdad (char archivo[],int edad)
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;
    int cant = 0;
    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer)>0)
        {
            if(alumno.edad > edad)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return cant;
}

int pedirEntero(char mensaje[])
{
    int num;

    printf("%s", mensaje);
    scanf("%d", &num);

    return num;
}
// ==================================================

// Ejercicio 9
// ==================================================
void mostrarAlumnosEnRango(char archivo[],int minEdad, int maxEdad)
{
    FILE* buffer = fopen(archivo,"rb");

    stAlumno alumno;

    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer)>0)
        {
            mostrarNombreAlumno(alumno,minEdad,maxEdad);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

void mostrarNombreAlumno(stAlumno alumno,int minEdad,int maxEdad)
{
    if(alumno.edad >= minEdad && alumno.edad <= maxEdad)
    {
        printf("%s\n", alumno.nombreYapellido);
    }
}
// ==================================================

// Ejercicio 10
// ==================================================
void mostrarAlumnosMayorDeEdad(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;
    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer)>0)
        {
            if(alumno.edad >= 18)
            {
                mostrarAlumno(alumno);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}
// ==================================================

// Ejercicio 11
// ==================================================
int cantidadDeAlumnosPorAnio (char archivo[], int anio)
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;
    int cant = 0;

    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer)>0)
        {
            if(alumno.anio == anio)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }

    return cant;
}
// ==================================================

// Ejercicio 12
// ==================================================
int cargarAlumnos(stAlumno arr[],int dim)
{
    char control = 's';
    int i = 0;
    while(control == 's' && i < dim)
    {
        arr[i] = cargarAlumno();
        i++;
        printf("\nDesea seguir cargndo alumnos al ARR 's/n':");
        scanf(" %c",&control);
    }
    return i;
}

void mostrarAlumnos(stAlumno arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarAlumno(arr[i]);
    }
}

int pasarArchiAArr(char archivo[],stAlumno arr[], int dim,int anio)
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;
    int i = 0;

    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer)>0 && i < dim)
        {
            if(alumno.anio == anio)
            {
                arr[i] = alumno;
                i++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return i;
}

void pasarArrAArchi (stAlumno arr[],int val,char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");
    if(buffer)
    {
        for(int i = 0; i < val; i++)
        {
            fwrite(&arr[i],sizeof(stAlumno),1,buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}
// ==================================================

// Ejercicio 13
// ==================================================
int cantDeRegistros(char archivo[])
{
    FILE* buffer = fopen(archivo, "rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stAlumno);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
    return cant;
}
// ==================================================

// Ejercicio 14
// ==================================================
void mostrarAlumnoPorPosicion(char archivo[], int pos)
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;
    int cant = cantDeRegistros(archivo);

    if(buffer)
    {
        if(pos >= 0 && pos <= cant)
        {
            fseek(buffer,pos * sizeof(stAlumno),SEEK_SET);
            fread(&alumno,sizeof(stAlumno),1,buffer);
            mostrarAlumno(alumno);

        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

// ==================================================
