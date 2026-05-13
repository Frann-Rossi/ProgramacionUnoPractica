#include <stdio.h>
#include <stdlib.h>

#include "alumno.h"
#include "arreglo.h"


void mostrarMenu()
{
    printf("\n====================================\n");
    printf("   TP N°7 - ARCHIVOS (UTN)\n");
    printf("====================================\n");

    printf("1  - Agregar dato (primitivo)\n");
    printf("2  - Mostrar archivo (primitivo)\n");
    printf("3  - Contar registros (primitivo)\n");

    printf("4  - Cargar archivo de alumnos\n");
    printf("5  - Mostrar alumnos\n");
    printf("6  - Agregar alumno\n");

    printf("7  - Pasar legajos a pila (mayores de edad)\n");
    printf("8  - Contar alumnos mayores a edad dada\n");
    printf("9  - Mostrar alumnos por rango de edad\n");

    printf("10 - Mostrar alumno de mayor edad\n");
    printf("11 - Contar alumnos por anio\n");

    printf("12 - Copiar arreglo -> archivo / archivo -> arreglo\n");
    printf("13 - Cantidad de registros (fseek / ftell)\n");

    printf("14 - Mostrar alumno por posicion\n");
    printf("15 - Modificar alumno\n");
    printf("16 - Invertir archivo\n");

    printf("0  - Salir\n");

    printf("====================================\n");
    printf("Seleccione una opcion: ");
}


void menu()
{
    char control = 's';
    int opcion;

    char archi[] = "archi.dat";

    stAlumno arrAlumnos[DIM];
    int i = 0;
    int val = 0;

    while(control == 's')
    {
        mostrarMenu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            break;
        case 4:
            cargarAlumnosEnArchivo(archi);
            break;
        case 5:
            mostrarAlumnos(archi);
            break;
        case 17:
            val = cargarAlumnosRecu(arrAlumnos,DIM,i);
            mostrarAlumnosRecu(arrAlumnos,val,i);
            break;
        case 0:
            control = 'n';
            printf("Saliendo.....\n");
            break;
        default:
            printf("Ingrese un valor valido.");
        }

        if(control == 's')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }

    }
}
