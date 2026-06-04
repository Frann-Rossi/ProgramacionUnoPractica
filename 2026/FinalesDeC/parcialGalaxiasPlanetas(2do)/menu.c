#include <stdio.h>
#include <stdlib.h>

#include "planeta.h"
#include "galaxia.h"

void menuTxt()
{
    printf("\n--- PUNTO 1: CARGA DE GALAXIAS ---\n");
    printf("\n--- PUNTO 2: MOSTRAR GALAXIAS POR TIPO ---\n");
    printf("\n--- PUNTO 3: CONTAR SATELITES ---\n");
    printf("\n--- PUNTO 4: GUARDAR PLANETAS POR MASA ---\n");
    printf("\n--- PUNTO 5: ARCHIVO A ARREGLO DINAMICO ---\n");
}

void menu()
{
    char control = 's';
    int opcion;

    int val = 0;
    int valPlanetas = 0;
    stGalaxia arrGalaxias[DIM];
    char tipoGalaxia[DIM];
    int cantSatelites = 0;
    char archivo[] = "archi.bin";
    stPlaneta *arrPlanetasDin;
    float masa;

    while(control == 's')
    {
        menuTxt();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            val = cargarGalaxias(arrGalaxias,DIM);
            break;
        case 2:
            pedirGalaxia(tipoGalaxia);
            mostrarGalaxiasPorTipo(arrGalaxias,val,tipoGalaxia);
            break;
        case 3:
            cantSatelites = contarSatelitesDeGalaxias(arrGalaxias,val);
            printf("\nCantidad total de satelites: %d", cantSatelites);
            break;
        case 4:
            masa = pedirFloat("\nIngrese un valor para la masa:");
            guardarPlanetasGalaxiasPorMasa(archivo,arrGalaxias,val,masa);
            break;
        case 5:
            valPlanetas = pasarArchiToArr(archivo,&arrPlanetasDin);
            mostrarPlanetas(arrPlanetasDin,valPlanetas);
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....");
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        if(control == 's')
        {
            printf("\nDesea seguir en el programa s/n:");
            scanf(" %c",&control);
        }
    }
}
