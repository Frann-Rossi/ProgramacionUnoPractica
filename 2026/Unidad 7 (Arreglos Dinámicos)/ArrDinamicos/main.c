#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

void arrDin(stAlumno** arr, int val)
{
    (*arr) = malloc(val * sizeof(stAlumno));
}

int cantArchi (char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stAlumno);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
    return cant;
}

void pasarArchiAArr(char archivo[], stAlumno arr[],int val)
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;
    int i = 0;

    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer)>0 && i < val)
        {
            arr[i] = alumno;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

void mostrarAlumno(stAlumno alumno)
{
    printf("\n=====");
    printf("\nLegajo:%d",alumno.legajo);
    printf("\nNombre y Apellido:%s",alumno.nombreYapellido);
    printf("\nEdad:%d",alumno.edad);
    printf("\nAnio:%d",alumno.anio);
    printf("\n=====");
}

void mostrarAlumnos(stAlumno arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarAlumno(arr[i]);
    }
}

int main()
{
    char control = 's';
    int opcion;

    char archi[] = "archi.bin";
    stAlumno *arrAlum;
    int val = 0;

    while(control == 's')
    {
        printf("Ej 1 == 1\n");
        printf("\nIngrese un valor:");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            val = cantArchi(archi);
            arrDin(&arrAlum,val);
            pasarArchiAArr(archi,arrAlum,val);
            mostrarAlumnos(arrAlum,val);
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
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }
    return 0;
}
