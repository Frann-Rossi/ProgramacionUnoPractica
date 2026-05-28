#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "utilidades.h"
#include "mascotas.h"

void menuMascotasTxt()
{
    printf("\n=========== MENU MASCOTAS ===========\n");
    printf("1. Cargar Mascota\n");
    printf("2. Mostrar Mascotas\n");
    printf("3. Modificar Mascota\n");
    printf("4. Eliminar Mascota\n");
    printf("5. Buscar Mascota por ID\n");
    printf("6. Pasar Archivo a Arreglo\n");
    printf("7. Ordenar Mascotas por Nombre\n");
    printf("0. Volver al Menu Principal\n");
    printf("=====================================\n");
    printf("Ingrese una opcion: ");
}

void menuMascotas()
{
    char control = 's';
    int opcion;

    char archivoMascotas[] = "mascotasArchi.bin";
    stMascota *arrMascotas;
    int cantElem = 0;
    int id;

    while(control == 's' || control == 'S')
    {
        menuMascotasTxt();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarMascotaArchi(archivoMascotas);
            break;
        case 2:
            mostrarMascotasArchi(archivoMascotas);
            break;
        case 3:
            id = pedirNum("Ingrese un id para Modificar la mascota:");
            modificarMascota(archivoMascotas,id);
            break;
        case 4:
            id = pedirNum("Ingrese un id para Eliminar la mascota:");
            eliminarMascota(archivoMascotas,id);
            break;
        case 5:
            id = pedirNum("Ingrese un id para Buscar la mascota:");
            buscarMascotaPorId(archivoMascotas,id);
            break;
        case 6:
            cantElem = cantidadElemArchiMascotas(archivoMascotas);
            crearArregloDinamicoMascotas(&arrMascotas,cantElem);
            pasarArchiToArr(archivoMascotas,arrMascotas,cantElem);
            mostrarMascotasArr(arrMascotas,cantElem);
            break;
        case 7:
            ordenamientoPorInsercion(arrMascotas,cantElem);
            mostrarMascotasArr(arrMascotas,cantElem);
            break;
        case 0:
            control = 'n';
            printf("\n[INFO] Volviendo al menu principal...\n");
            break;
        default:
            printf("\n[ERROR] Opcion invalida.\n");
        }
        if(control == 's' || control == 'S')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }
}


void menuDueniosTxt()
{
    printf("\n======= MENU DE DUENIOS =======\n");
    printf("1. Cargar Duenio\n");
    printf("2. Mostrar Duenios\n");
    printf("3. Modificar Duenio\n");
    printf("4. Eliminar Duenio\n");
    printf("5. Buscar Duenio por ID\n");
    printf("0. Volver al Menu Principal\n");
    printf("================================\n");
    printf("Ingrese una opcion: ");
}

void menuDuenios()
{
    char control = 's';
    int opcion;

    char archivoDuenios[] = "dueniosArchi.bin";
    int id;

    while(control == 's' || control == 'S')
    {
        menuDueniosTxt();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            break;
        case 0:
            control = 'n';
            printf("\n[INFO] Volviendo al menu principal...\n");
            break;
        default:
            printf("\n[ERROR] Opcion invalida.\n");
        }
        if(control == 's' || control == 'S')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }
}

void menuTxt()
{
    printf("\n========== VETERINARIA ==========\n");
    printf("1. Gestion de Mascotas\n");
    printf("2. Gestion de Duenios\n");
    printf("0. Salir\n");
    printf("=================================\n");
    printf("Ingrese una opcion: ");
}

void menu()
{
    char control = 's';
    int opcion;

    char archivoMascotas[] = "mascotasArchi.bin";
    int id;

    while(control == 's' || control == 'S')
    {
        menuTxt();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            menuMascotas();
            break;
        case 2:
            menuDuenios();
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo del programa.....\n");
            break;
        default:
            printf("\n[ERROR] Opcion invalida.\n");
        }
        if(control == 's' || control == 'S')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }
}
