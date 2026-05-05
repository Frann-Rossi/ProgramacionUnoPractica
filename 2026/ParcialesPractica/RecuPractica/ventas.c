#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include "ventas.h"
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

// EJERCICIO 4
// **************************************************
int rangoMayorDeCompra (Pila pila)
{
    int compraSuperio = desapilar(&pila);
    int nuevaCompraSup;
    while(!pilavacia(&pila))
    {
        nuevaCompraSup = desapilar(&pila);
        if(compraSuperio < nuevaCompraSup)
        {
            compraSuperio = nuevaCompraSup;
        }

    }
    return compraSuperio;
}
// **************************************************


