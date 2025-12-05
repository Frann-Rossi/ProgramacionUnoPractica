#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 20
#define LARGO_NOMBRE 30

int cargarAlum (int legajo[], char nombre[][LARGO_NOMBRE], int anio[], int dim)
{
    char control = 's';
    int i = 0;

    while(control == 's' && i < dim)
    {
        printf("LEGAJO\n");
        fflush(stdin);
        scanf("%d",&legajo[i]);
        printf("NOMBRE\n");
        fflush(stdin);
        scanf("%s",&nombre[i]);
        printf("ANIO\n");
        fflush(stdin);
        scanf("%d",&anio[i]);
        i++;
        printf("Desea seguir cargando ALUMNOS\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}

void mostrarAlum(int legajo[], char nombre[][LARGO_NOMBRE], int anio[], int val)
{
    for(int i = 0; i < val ; i++)
    {
        printf("|Legajo:%d|//|Nombre:%s|//|Anio:%d|\n",legajo[i],nombre[i],anio[i]);
    }

}

int buscarLegajo(int legajo[],int val, int legajoBuscado)
{
    int flag = -1;
    for(int i = 0; i < val; i++)
    {
        if(legajo[i] == legajoBuscado)
        {
            flag = i;
        }
    }
    return flag;
}

void buscarYMostrarNombre (int legajo[], char nombre[][LARGO_NOMBRE], int anio[], int val)
{
    int numLegajo;
    int legajoBuscado;
    printf("Ingrese el legajo del alum a BUSCAR:");
    scanf("%d",&numLegajo);
    legajoBuscado = buscarLegajo(legajo,val,numLegajo+1);

    if(legajoBuscado != -1)
    {
        printf("Legajo:%d\n",legajo[numLegajo]);
        printf("Nombre:%s\n",nombre[numLegajo]);
    }
    else
    {
        printf("El legajo %d NO se encontro\n", numLegajo);
    }


}

int buscarMenor (char nombre[][LARGO_NOMBRE], int val, int posInicio)
{
    int posMenor = posInicio;
    for(int i = posInicio + 1; i < val; i++)
    {
        if(strcmpi(nombre[i],nombre[posMenor])<0)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenamientoPorSeleccion(int legajo[], char nombre[][LARGO_NOMBRE], int anio[], int val)
{
    int posMenor;
    char auxNombre[LARGO_NOMBRE];
    int aux;
    for(int i = 0; i < val; i++)
    {
        posMenor = buscarMenor(nombre,val,i);
        if(posMenor != i)
        {
            strcpy(auxNombre,nombre[i]);
            strcpy(nombre[i],nombre[posMenor]);
            strcpy(nombre[posMenor],auxNombre);


        aux = legajo[i];
        legajo[i] = legajo[posMenor];
        legajo[posMenor] = aux;

        aux = anio[i];
        anio[i] = anio[posMenor];
        anio[posMenor] = aux;
        }
    }
}

int main()
{
    char control = 's';
    int opcion;
    int val;
    int legajos[MAX_ALUMNOS];
    char nombres[MAX_ALUMNOS][LARGO_NOMBRE];
    int anios[MAX_ALUMNOS];
    int legajoBuscado;
    int num;

    while(control == 's')
    {
        printf("\n\n--- MENU DE ALUMNOS (ARREGLOS PARALELOS) ---\n");
        printf("1. Cargar alumnos\n");
        printf("2. Mostrar todos los alumnos\n");
        printf("3. Buscar posicion de un legajo (Interna)\n"); // Generalmente para uso interno, pero la ponemos en el menú para probar
        printf("4. Buscar nombre por legajo\n");
        printf("5. Ordenar alumnos por nombre\n");
        printf("6. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            val = cargarAlum(legajos,nombres,anios,MAX_ALUMNOS);
            break;
        case 2:
            mostrarAlum(legajos,nombres,anios,val);
            break;
        case 3:
            printf("Ingrese un legajo para Buscar:");
            scanf("%d",&num);
            legajoBuscado = buscarLegajo(legajos,val,num+1);
            if(legajoBuscado != -1)
            {
                printf("El legajo %d se encontro en la pos %d\n", num, legajoBuscado);
            }
            else
            {
                printf("El legajo %d NO se encontro\n", num);
            }
            break;
        case 4:
            buscarYMostrarNombre(legajos,nombres,anios,val);
        default:
            printf("Ingrese un valor valido\n");
        }

        printf("Desea seguir en el programa 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
    }

}
