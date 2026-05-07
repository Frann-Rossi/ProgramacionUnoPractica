#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "alumno.h"


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
    FILE* buffer = fopen(archivo,"ab");
    char control = 's';
    stAlumno alumno;

    if(buffer)
    {
        while(control == 's')
        {
            alumno = cargarAlumno();
            fwrite(&alumno, sizeof(stAlumno), 1, archivo);
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

void mostrarAlumno(stAlumno alumno)
{
    printf("\n------------------------\n");
    printf("Legajo: %d\n", alumno.legajo);
    printf("Nombre: %s\n", alumno.nombreYapellido);
    printf("Edad: %d\n", alumno.edad);
    printf("Anio: %d\n", alumno.anio);
    printf("------------------------\n");
}

void mostrarAlumnos(char archivo[])
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
int cargarAlumnosRecu(stAlumno arr[],int dim,int i)
{
    char control = 's';
    int val = 0;
    if(i < dim)
    {
        arr[i] = cargarAlumno();
        val++;
        printf("Desea seguir cargando 's/n':");
        scanf(" %c",&control);
        if(control == 's')
            {

                val += cargarAlumnosRecu(arr,dim,i+1);
            }
    }
    return val;
}

void mostrarAlumnosRecu(stAlumno arr[],int val,int i)
{
    if(i < val)
    {
        mostrarAlumno(arr[i]);
        mostrarAlumnosRecu(arr,val,i+1);
    }
}
// ==================================================
