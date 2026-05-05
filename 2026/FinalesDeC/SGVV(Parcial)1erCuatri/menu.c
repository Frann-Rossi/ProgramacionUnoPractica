#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "ventas.h"
#include "vendedores.h"

#define DIM 30
#define LARGO_NOMBRE 30
#define NOMBRES 10

void mostrarMenu()
{
    printf("\n===== SISTEMA DE GESTION DE VENTAS =====\n");
    printf("1. Registrar ventas\n");
    printf("2. Calcular promedio de ventas\n");
    printf("3. Clasificar ventas en pilas\n");
    printf("4. Contar ventas por tipo\n");
    printf("5. Buscar vendedores por letra\n");
    printf("6. Modificar registros a mayusculas\n");
    printf("0. Salir\n");
    printf("========================================\n");
    printf("Ingrese una opcion: ");
}

void menu()
{
    char control = 's';
    int opcion;

    int arrVentas[DIM];
    int validos = 0;
    float promedio = 0;
    char arrDeNombres[NOMBRES][LARGO_NOMBRE];
    char letra;
    int valNombres = 0;
    int valNombresMod = 0;

    while(control == 's')
    {
        mostrarMenu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            validos = registrarVentas(arrVentas,DIM);
            mostrarVentas(arrVentas,validos);
            break;
        case 2:
            promedio = calcularPromedio(arrVentas,validos);
            printf("El promedio fue de:%.2f",promedio);
            break;
        case 5:
            valNombres = cargarNombres(arrDeNombres,NOMBRES);
            letra = pedirLetra();
            mostrarNombresPorInicial(arrDeNombres,valNombres,letra);
            break;
        case 6:
            valNombresMod = modificarRegistros(arrDeNombres,valNombres);
            mostrarNombres(arrDeNombres,valNombresMod);
            break;
        case 0:
            control = 'n';
            printf("Saliendo.....\n");
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
}
