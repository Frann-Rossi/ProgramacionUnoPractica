#include <stdio.h>
#include <stdlib.h>

#define DIM 30

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

stAlumno cargarAlum ()
{
    stAlumno alum;

    printf("Ingrese MATRICULA:");
    scanf("%d",&alum.matricula);

    printf("Ingrese NOMBRE:");
    scanf("%s",&alum.nombre);

    printf("Ingrese GENERO(m/f/o):");
    scanf(" %c",&alum.genero);
    return alum;
}

int cargarAlumnos(stAlumno arr[],int dim)
{
    int i = 0;
    char control = 's';

    while(control == 's' && i < dim)
    {
        arr[i] = cargarAlum();
        i++;

        printf("\nDesea seguir cargando ALUMNOS:");
        scanf(" %c",&control);
    }
    return i;
}

void mostrarAlum (stAlumno alum)
{
    printf("\nMATRICULA:%d",alum.matricula);
    printf("\nNOMBRE:%s",alum.nombre);
    printf("\nGENERO:%c",alum.genero);
}

void mostrarAlumnos(stAlumno arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("\n+++++");
        mostrarAlum(arr[i]);
        printf("\n+++++\n");
    }
}


int main()
{

    char control = 's';
    int opcion;

    stAlumno arrAlumnos[DIM];
    int val;

    while(control == 's')
    {
        printf("ej1 == 1 \n");
        printf("SALIR == 0 \n");
        printf("\nIngrese un valor:");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            val = cargarAlumnos(arrAlumnos,DIM);
            break;
        case 2:
            mostrarAlumnos(arrAlumnos,val);
            break;
        case 0:
            control = 'n';
            printf("SALIENDO.....\n");
            break;
        default:
            printf("\nIngrese un valor VALIDO\n");
        }
        if(control == 's')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }

    return 0;
}
