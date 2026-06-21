#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define DIM 30

// UTILIDADES
char seguir(char msj[])
{
    char opcion;
    printf("%s",msj);
    scanf(" %c",&opcion);
    return opcion;
}

void menu()
{
    printf("\n========== MENU ==========\n");
    printf("1 - Cargar datos de la pila\n");
    printf("2 - Buscar mayor tramo y dia correspondiente\n");
    printf("3 - Mostrar contenido de la pila por dias\n");
    printf("4 - Procesar datos del arreglo\n");
    printf("5 - Cargar y mostrar nombres\n");
    printf("6 - Ordenar nombres alfabeticamente\n");
    printf("0 - Salir\n");
    printf("==========================\n");
    printf("Ingrese opcion: ");
}

void pasarPila(Pila* origen, Pila* destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino,desapilar(origen));
    }
}

// EJERCICIOS
void cargarTramos(Pila* pila)
{
    char control = 's';
    int num;
    while(control == 's')
    {
        while(control == 's')
        {
            printf("\nIngrese un tramo:");
            scanf("%d",&num);
            apilar(pila,num);
            control = seguir("\nDesea seguir cargando KM 's/n':");
        }
        apilar(pila,-1);
        control = seguir("\nDesea seguir cargando DIAS 's/n':");
    }
}

int mayorTramo(Pila pila,int* dia)
{
    Pila aux;
    inicpila(&aux);
    pasarPila(&pila,&aux);
    int diaActual = 1;
    int contador = 0;
    int mayor = 0;
    int elem = 0;
    while(!pilavacia(&aux))
    {
        elem = desapilar(&aux);
        if(elem == -1)
        {
            diaActual++;
        }
        else
        {
            if(elem > mayor)
            {
                mayor = elem;
                contador = diaActual;
            }
        }
    }
    (*dia) = contador;
    return mayor;
}

void mostrarContenido(Pila pila)
{
    Pila aux;
    inicpila(&aux);
    pasarPila(&pila,&aux);
    int cont = 1;
    int elem;
    printf("\nDia:%d",cont);
    while(!pilavacia(&aux))
    {
        elem = desapilar(&aux);

        if(elem != -1)
        {
            printf("|%d|",elem);
        }
        else
        {
            cont++;
            if(!pilavacia(&aux))
            {
                printf("\nDia:%d",cont);
            }
        }
    }
}

int cantidadKm (Pila pila, int arr[],int dim)
{
    Pila aux;
    inicpila(&aux);
    pasarPila(&pila,&aux);
    int elem;
    int i = 0;
    int suma = 0;
    while(!pilavacia(&aux) && i < dim)
    {
        elem = desapilar(&aux);
        if(elem != -1)
        {
            suma += elem;
            arr[i] = suma;
        }
        else
        {
            suma = 0;
            i++;
        }
    }
    return i;
}

void mostrarKmSumados(int arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%d|",arr[i]);
    }
}

int cargarNombres(char arrDeNombres[][DIM],int dim)
{
    char control = 's';
    int i = 0;

    while(control == 's' && i < dim)
    {
        printf("\nIngrese un NOMBRE:");
        scanf("%s",&arrDeNombres[i]);
        i++;
        control = seguir("\nDesea seguir cargando NOMBRES 's/n':");
    }
    return i;
}

void mostrarNombres(char arrDeNombres[][DIM],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%s|\n",arrDeNombres[i]);
    }
}

void insertar(char arrOrdenado[][DIM],int val, char elemento[])
{
    int i = val - 1;

    while(i >= 0 && strcmpi(elemento,arrOrdenado[i])<0)
    {
        strcpy(arrOrdenado[i+1],arrOrdenado[i]);
        i--;
    }
    strcpy(arrOrdenado[i+1],elemento);
}

void ordenamientoPorInsecion(char arrDeNombres[][DIM],int val,char arrDeNombresOrdenado[][DIM])
{
    for(int i = 0; i < val; i++)
    {
        insertar(arrDeNombresOrdenado,i,arrDeNombres[i]);
    }
}

int main()
{
    char control = 's';
    int opcion;

    Pila pila;
    Pila pila2;
    inicpila(&pila);
    inicpila(&pila2);

    int dia = 0;
    int mayorKm = 0;
    int arr[DIM];
    int val = 0;
    char arrNombres[DIM][DIM];
    char arrNombresOrdenado[DIM][DIM];
    int valNombres = 0;

    while(control == 's')
    {
        menu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarTramos(&pila);
            mostrar(&pila);
            break;
        case 2:
            mayorKm = mayorTramo(pila,&dia);
            printf("Mayor KM:%d fue en el dia:%d",mayorKm,dia);
            break;
        case 3:
            mostrarContenido(pila);
            break;
        case 4:
            val = cantidadKm(pila,arr,DIM);
            mostrarKmSumados(arr,val);
            break;
        case 5:
            valNombres = cargarNombres(arrNombres,DIM);
            mostrarNombres(arrNombres,valNombres);
            break;
        case 6:
            ordenamientoPorInsecion(arrNombres,valNombres,arrNombresOrdenado);
            mostrarNombres(arrNombresOrdenado,valNombres);
            break;
        case 0:
            printf("\nSaliendo...");
            control = 'n';
            break;
        default:
            printf("\nIngrese un valor valido\n");
        }
        if(control == 's')
        {
            control = seguir("\nDesea seguir en el programa 's/n':");
        }
    }
    return 0;
}
