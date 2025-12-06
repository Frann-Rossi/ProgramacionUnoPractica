#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 30
#define MAX_ALUMNOS 50

typedef struct
{
    int matricula;
    char nombre[MAX_NOMBRE];
    char genero; //m, f, o
} stAlumno;

stAlumno cargarAlumno ()
{
    stAlumno alum;
    printf("Matricula:");
    scanf("%d",&alum.matricula);
    printf("\nNombre:");
    fflush(stdin);
    scanf("%s",alum.nombre);
    //gets(alum->nombre);
    printf("\nGenero:");
    fflush(stdin);
    scanf("%c",&alum.genero);
    return alum;
}

int cargarAlumnos(stAlumno arrAlum[], int dim)
{
    int i = 0;
    char control = 's';

    while(control == 's' && i < dim )
    {
        arrAlum[i] = cargarAlumno();
        i++;
        printf("Desea seguir cargando ALUMNOS 's/n':");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}

void mostrarAlumno(stAlumno alum)
{
    printf("|Matricula:%d|//|Nombre:%s||Genero:%c|\n",alum.matricula,alum.nombre,alum.genero);
}

void mostrarAlumnos(stAlumno arrAlum[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarAlumno(arrAlum[i]);
    }
}

int buscarMatricula (stAlumno arrAlum[], int val, int numBuscado)
{
    int flag = -1;
    for(int i = 0; i < val ; i++)
    {
        if(arrAlum[i].matricula == numBuscado)
        {
            flag = i;
        }
    }
    return flag;
}

void mostrarAlumnoPorMatricula (stAlumno arrAlum[],int val)
{
    int posicion;
    int numBuscado;
    printf("Ingrese matricula a buscar:");
    scanf("%d",&numBuscado);

    posicion = buscarMatricula(arrAlum,val,numBuscado);

    if(posicion != -1)
    {
        printf("\nAlumno Encontrado:\n");
        mostrarAlumno(arrAlum[posicion]);
    }
    else
    {
        printf("No se encontro ningun alumno con esa matricula.\n");
    }
}

int buscarMenor(stAlumno arrAlum[],int val, int posInicial)
{
    int posMenor = posInicial;
    for(int i = posInicial + 1; i < val; i++)
    {
        if(arrAlum[i].matricula < arrAlum[posMenor].matricula)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenamientoPorSeleccion (stAlumno arrAlum[],int val)
{
    int posMenor;
    stAlumno aux;
    for(int i = 0; i < val - 1; i++)
    {
        posMenor = buscarMenor(arrAlum,val,i);
        aux = arrAlum[posMenor];
        arrAlum[posMenor] = arrAlum[i];
        arrAlum[i] = aux;

    }
}

void mostrarPorGenero(stAlumno arrAlum[],int val, char letraGenero)
{
    for(int i = 0; i < val; i++)
    {
        if(arrAlum[i].genero == letraGenero)
        {
            mostrarAlumno(arrAlum[i]);
        }
    }

}

int insertar(stAlumno arrAlum[], int val, stAlumno nuevoAlum)
{
    int i = val - 1;

    while(i >= 0 && nuevoAlum.matricula < arrAlum[i].matricula)
    {
        arrAlum[i + 1] = arrAlum[i];
        i--;
    }

    arrAlum[i + 1] = nuevoAlum;

    return val + 1;
}

void insertarElem(stAlumno arrAlum[], int tope, stAlumno elem)
{
    int i = tope;
    while(i >= 0 && strcmpi(elem.nombre,arrAlum[i].nombre) < 0 )
    {
        arrAlum[i + 1] = arrAlum[i];
        i--;
    }
    arrAlum[i +1] = elem;
}

void ordenamientoPorInsercion (stAlumno arrAlum[], int val)
{
    for(int i = 0; i < val - 1 ; i++)
    {
        insertarElem(arrAlum,i,arrAlum[i+1]);
    }
}

int cantDeAlumPorGenero(stAlumno arrAlum[],int val, char genero){
    int cont = 0;
    for(int i = 0; i < val; i++){
        if(arrAlum[i].genero == genero){
            cont++;
        }
    }
    return cont;
}

int main()
{
    char control = 's';
    int opcion;

    stAlumno arrAlumnos[MAX_ALUMNOS];
    int val = 0;
    char generoBuscado;
    stAlumno alumNuevo;
    int alumCantPorGenero;

    while(control == 's')
    {
        printf("\n\n--- TRABAJO PRACTICO 6: ESTRUCTURAS ---\n");
        printf("1. Cargar arreglo de alumnos\n");
        printf("2. Mostrar arreglo de alumnos\n");
        printf("3. Buscar alumno por matricula\n");
        printf("4. Ordenar por matricula (Seleccion)\n");
        printf("5. Mostrar alumnos de un genero\n");
        printf("6. Insertar alumno en arreglo ordenado (por matricula)\n");
        printf("7. Ordenar por nombre (Insercion)\n");
        printf("8. Contar estudiantes de un genero\n");
        printf("0. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            val = cargarAlumnos(arrAlumnos,MAX_ALUMNOS);
            printf("Se cargaron %d alumnos\n",val);
            break;
        case  2:
            mostrarAlumnos(arrAlumnos,val);
            break;
        case 3:
            mostrarAlumnoPorMatricula(arrAlumnos,val);
            break;
        case 4:
            ordenamientoPorSeleccion(arrAlumnos,val);
            mostrarAlumnos(arrAlumnos,val);
            break;
        case 5:
            printf("Ingrese genero a listar (m/f): ");
            fflush(stdin);
            scanf("%c", &generoBuscado);
            mostrarPorGenero(arrAlumnos,val,generoBuscado);
            break;
        case 6:
            alumNuevo = cargarAlumno();
            val = insertar(arrAlumnos,val,alumNuevo);
            mostrarAlumnos(arrAlumnos,val);
            break;
        case 7:
            ordenamientoPorInsercion(arrAlumnos,val);
            mostrarAlumnos(arrAlumnos,val);
            break;
        case 8:
            printf("Ingrese un genero para contar:");
            fflush(stdin);
            scanf("%c",&generoBuscado);
            alumCantPorGenero = cantDeAlumPorGenero(arrAlumnos,val,generoBuscado);
            printf("El genero elegido %c y la cantidad fue %d\n",generoBuscado,alumCantPorGenero);
            break;
        case 0:
            printf("Saliendo del programa...\n");
            control = 'n';
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
