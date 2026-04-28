#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUMNOS 20
#define DIM_NOMBRE 30

void cargarAlumno(int* legajo,char nombre[],int* anio)
{
    printf("Ingrese LEGAJO:");
    scanf("%d",legajo);
    printf("Ingrese NOMBRE:");
    scanf("%s",nombre);
    printf("Ingrese ANIO:");
    scanf("%d",anio);
}

int cargarAlumnos(int legajos[],char nombres[][DIM_NOMBRE],int anios[],int dim)
{
    int i = 0;
    char control  = 's';

    while(control == 's' && i < dim)
    {
        cargarAlumno(&legajos[i],nombres[i],&anios[i]);
        i++;
        printf("Desea seguir cargando 's/n':");
        scanf(" %c",&control);
    }
    return i;
}

void mostrarAlumno(int legajo,char nombre[],int anio)
{
    printf("******************************\n");
    printf("Legajo: %d\n", legajo);
    printf("Nombre: %s\n", nombre);
    printf("Anio: %d\n", anio);

}

void mostrarAlumnos(int legajos[],char nombres[][DIM_NOMBRE],int anios[], int val)
{
    for(int i = 0; i < val ; i++)
    {
        mostrarAlumno(legajos[i],nombres[i],anios[i]);
    }
}

int main()
{
    int legajos[MAX_ALUMNOS];
    char nombres[MAX_ALUMNOS][DIM_NOMBRE];
    int anios[MAX_ALUMNOS];

    char control = 's';
    int opcion;

    int val = 0;

    while(control == 's')
    {
        printf("Ej == 1\n");
        printf("SALIR == 0\n");
        printf("Ingrese una opcion:");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            val = cargarAlumnos(legajos,nombres,anios,MAX_ALUMNOS);
            break;
        case 2:
            mostrarAlumnos(legajos,nombres,anios,val);
            break;
        case 0:
            control = 'n';
            printf("SALIENDO.....\n");
            break;
        default:
            printf("Ingrese un valor correcto\n");
        }
        if(control == 's')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }

}
