#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define MAX_NOMBRES 10
#define LARGO_NOMBRE 30
#define DIM 30

// EJERCICIO 1
// **************************************************
void cargarCompras(Pila* pila, int* suma, int* cant)
{
    int sumElem = 0;
    int cantElem = 0;
    int dato;
    char control = 's';
    while (control == 's')
    {
        printf("Ingrese un valor:");
        scanf("%d",&dato);
        apilar(pila,dato);
        sumElem += dato;
        cantElem++;
        printf("Desea seguir cargando elementos 's/n':");
        scanf(" %c", &control);
    }
    *suma = sumElem;
    *cant = cantElem;
}
// **************************************************

void pasarPilaAOtra (Pila* origen, Pila* destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino,desapilar(origen));
    }
}


// EJERCICIO 2
// **************************************************
void ordenamientoPorSeleccion(Pila* pila)
{
    Pila aux;
    Pila aux2;
    inicpila(&aux);
    inicpila(&aux2);
    int dato = 0;
    while(!pilavacia(pila))
    {
        dato = desapilar(pila);
        while(!pilavacia(&aux) && tope(&aux) > dato)
        {
            apilar(pila,desapilar(&aux));
        }
        apilar(&aux,dato);
    }
    pasarPilaAOtra(&aux, &aux2);
    pasarPilaAOtra(&aux2, pila);

}
// **************************************************

// EJERCICIO 3
// **************************************************
int cantDigitos (int num)
{
    int cant = 0;
    while(num > 0)
    {
        num = num / 10;
        cant++;
    }
    return cant;
}

void contarPorDigitos (Pila* pila, int arr[], int dim)
{
    Pila aux;
    inicpila(&aux);

    int dato;
    int dig;

    for(int i = 0; i < dim; i++)
    {
        arr[i] = 0;
    }


    while(!pilavacia(pila))
    {
        dato = desapilar(pila);
        dig = cantDigitos(dato);

        if(dig <= dim)
        {
            arr[dig - 1]++;
        }
        apilar(&aux,dato);
    }
    pasarPilaAOtra(&aux,pila);
}

// **************************************************

void mostrarArr(int arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        if(arr[i] > 0)
        {
            printf("%d digitos: %d compras\n", i+1, arr[i]);
        }
    }
}

// EJERCICIO 6
// **************************************************

int nombreExiste (char arrNombres[][LARGO_NOMBRE],int val, char palabra[])
{
    int flag = -1;
    for(int i = 0; i < val; i++)
    {
        if(strcmpi(palabra,arrNombres[i]) == 0)
        {
            flag = i;
        }
    }
    return flag;
}

int cargarNombres(char arrNombres[][LARGO_NOMBRE],int dim)
{
    char control = 's';
    int i = 0;

    int nombre = 0;
    while (control == 's' && i < dim)
    {
        printf("Ingrese el nombre:");
        scanf("%s",&arrNombres[i]);
        nombre = nombreExiste (arrNombres,i,arrNombres[i]);
        if(nombre == -1)
        {
            i++;
        }
        else
        {
            printf("El Nombre ya existe\n");
        }
        printf("Desea seguir 's/n':");
        scanf(" %c", &control);
    }
    return i;
}

void mostrarNombres(char arrNombres[][LARGO_NOMBRE],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%s|\n",arrNombres[i]);
    }
}

// **************************************************

int main()
{
    char control = 's';
    int opcion;

    int sumaElementos = 0;
    int cantElementos = 0;
    Pila pila;
    inicpila(&pila);

    int arr[DIM];

    char arrNombres[MAX_NOMBRES][LARGO_NOMBRE];
    int val = 0;

    while(control == 's')
    {
        printf("Ej 1 == 1\n");
        printf("SALIR == 0\n");
        printf("Ingrese un valor:");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarCompras(&pila,&sumaElementos,&cantElementos);
            printf("Suma:%d\n",sumaElementos);
            printf("cant:%d\n",cantElementos);
            printf("PILA\n");
            mostrar(&pila);
            break;
        case 2:
            ordenamientoPorSeleccion(&pila);
            mostrar(&pila);
            break;
        case 3:
            contarPorDigitos(&pila,arr,DIM);
            mostrarArr(arr,DIM);
            break;
        case 6:
            val = cargarNombres(arrNombres,MAX_NOMBRES);
            mostrarNombres(arrNombres,val);
            break;
        case 0:
            control = 'n';
            printf("Saliendo.....");
            break;
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
