#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
            menor =  arr[i].matricula;
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
void mostrarAlumnosPorGenero(stAlumno arr[],int val, char generoBuscar)
{
    for(int i = 0; i < val; i++)
    {
        if(generoBuscar == arr[i].genero)
        {
            printf("\n+++++");
            mostrarAlum(arr[i]);
            printf("\n+++++\n");
        }
    }
}

char pedirGenero()
{
    char genero;
    printf("Ingrese un genero a buscar m/f:");
    scanf(" %c",&genero);
    return genero;
}
// --------------------------------------------------

// EJERCICIO 6
// --------------------------------------------------
int insertarAlumno(stAlumno arr[], int val, stAlumno alum)
{
    int i = val -1;
    while(i >= 0 && alum.matricula < arr[i].matricula)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i + 1] = alum;
    return val + 1;
}
// --------------------------------------------------

// EJERCICIO 7
// --------------------------------------------------
void insertar(stAlumno arr[],int val,stAlumno elem)
{
    int i = val - 1;
    stAlumno aux;
    while(i >= 0 && strcmpi(elem.nombre,arr[i].nombre) < 0)
    {
        arr[i+1] = arr[i];
        i--;
    }
    arr[i+1] = elem;
}

int ordenamientoPorInsercion (stAlumno arr[], int val)
{
    stAlumno aux;
    for(int i = 0; i < val; i++)
    {
        aux = arr[i];
        insertar(arr,i,aux);
    }
}

// --------------------------------------------------

// EJERCICIO 8
// --------------------------------------------------
int cantidadDeAlumPorGenero(stAlumno arr[],int val, char genero)
{
    int contador = 0;

    for(int i = 0; i < val ; i++)
    {
        if(genero == arr[i].genero)
        {
            contador++;
        }
    }
    return contador;
}
// --------------------------------------------------


int main()
{

    char control = 's';
    int opcion;

    stAlumno arrAlumnos[DIM];
    int val = 0;
    int alumPorMatriculaBuscado;
    int nroMatricula;
    char genero;
    stAlumno nuevoAlum;
    int contadorDeAlum;

    while(control == 's')
    {
        printf("\n========= MENU PRINCIPAL =========\n");
        printf("1. Cargar alumnos\n");
        printf("2. Mostrar todos los alumnos\n");
        printf("3. Buscar alumno por matricula\n");
        printf("4. Ordenar alumnos por matricula (Seleccion)\n");
        printf("5. Mostrar alumnos por genero\n");
        printf("6. Insertar alumno (ordenado por matricula)\n");
        printf("7. Ordenar alumnos por nombre (Insercion)\n");
        printf("8. Contar alumnos por genero\n");
        printf("0. Salir\n");
        printf("==================================\n");
        printf("Ingrese una opcion: ");
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
        case 5:
            genero = pedirGenero();
            mostrarAlumnosPorGenero(arrAlumnos,val,genero);
            break;
        case 6:
            nuevoAlum = cargarAlum();
            val = insertarAlumno(arrAlumnos,val,nuevoAlum);
            break;
        case 7:
            ordenamientoPorInsercion(arrAlumnos,val);
            break;
        case 8:
            genero = pedirGenero();
            contadorDeAlum = cantidadDeAlumPorGenero(arrAlumnos,val,genero);
            if(contadorDeAlum > 0)
            {
                printf("Cantidad de alumnos del genero %c: %d\n", genero, contadorDeAlum);
            }
            else
            {
                printf("NO hay alumnos del genero|%c|",genero);
            }
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
