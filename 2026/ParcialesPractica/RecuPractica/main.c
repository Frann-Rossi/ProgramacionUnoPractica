#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pila.h"
#include "menu.h"
#include "ventas.h"
#include "nombres.h"

#define DIM 30


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
    int compraSuperior = 0;

    while(control == 's')
    {
        mostrarMenu();
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
        case 4:
            compraSuperior = rangoMayorDeCompra(pila);
            printf("La compra superio fue:%d",compraSuperior);
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
