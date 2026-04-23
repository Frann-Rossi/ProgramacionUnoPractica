#include <stdio.h>
#include <stdlib.h>

#define DIM 30

typedef struct
{
    int matricula;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

// --------------------------------------------------
// EJERCICIO 1
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

        printf("\nDesea seguir cargando ALUMNOS 's/n':");
        scanf(" %c",&control);
    }
    return i;
}
// --------------------------------------------------

// EJERCICIO 2
// --------------------------------------------------
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
// --------------------------------------------------

// EJERCICIO 3
// --------------------------------------------------
int pedirMatricula()
{
    int num;
    printf("Ingrese Una MATRICULA:");
    scanf("%d",&num);
    return num;
}

int buscarAlumPorMatricula (stAlumno arr[], int val, int matriculaBuscada)
{
    int flag = -1;
    for(int i = 0; i < val; i++)
    {
        if(matriculaBuscada == arr[i].matricula)
        {
            flag = i;
        }
    }
    return flag;
}
// --------------------------------------------------

// EJERCICIO 4
// --------------------------------------------------
int posMenor (stAlumno arr[],int val, int pos)
{
    int menor = arr[pos].matricula;
    int posMenor = pos;
    for(int i = pos + 1; i < val; i++)
    {
        if(menor > arr[i].matricula)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenamientoPorSeleccion (stAlumno arr[],int val)
{
    int menor;
    stAlumno aux;
    for(int i = 0; i < val - 1; i++)
    {
        menor = posMenor(arr,val,i);
        aux = arr[i];
        arr[i] = arr[menor];
        arr[menor] = aux;
    }
}

// --------------------------------------------------

// EJERCICIO 5
// --------------------------------------------------
// --------------------------------------------------

int main()
{

    char control = 's';
    int opcion;

    stAlumno arrAlumnos[DIM];
    int val = 0;
    int alumPorMatriculaBuscado;
    int nroMatricula;

    while(control == 's')
    {
        printf("Cargar ALUMNOS == 1 \n");
        printf("Mostrar ALUMNOS == 2 \n");
        printf("Buscar ALUMNO por MATRICULA == 3 \n");
        printf("Ordenamiento por SELECCION == 4 \n");
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
        case 3:
            nroMatricula = pedirMatricula();
            alumPorMatriculaBuscado = buscarAlumPorMatricula(arrAlumnos,val,nroMatricula);
            if(alumPorMatriculaBuscado != -1)
            {
                mostrarAlum(arrAlumnos[alumPorMatriculaBuscado]);
            }
            else
            {
                printf("\nNo se encontro el alumno\n");
            }
            break;
        case 4:
            ordenamientoPorSeleccion(arrAlumnos,val);
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
