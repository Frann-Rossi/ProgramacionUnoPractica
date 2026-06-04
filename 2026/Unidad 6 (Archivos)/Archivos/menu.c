#include <stdio.h>
#include <stdlib.h>

#include "alumno.h"
#include "pila.h"

void mostrarMenu()
{
    printf("\n====================================\n");
    printf("   TP N°7 - ARCHIVOS (UTN)\n");
    printf("====================================\n");

    printf("1  - Agregar dato (primitivo)\n");
    printf("2  - Mostrar archivo (primitivo)\n");
    printf("3  - Contar registros (primitivo)\n");

    printf("4  - Cargar archivo de alumnos\n");
    printf("5  - Mostrar alumnos del archivo\n");
    printf("6  - Agregar alumno al archivo\n");

    printf("7  - Pasar legajos de mayores a una pila\n");
    printf("8  - Contar alumnos mayores a una edad\n");
    printf("9  - Mostrar alumnos por rango de edad\n");

    printf("10 - Mostrar alumnos mayores de edad\n");
    printf("11 - Pasar alumnos de un anio a arreglo\n");

    printf("12 - Pasar arreglo a archivo y mostrarlo\n");
    printf("13 - Cantidad de registros (fseek/ftell)\n");

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

    char archi[] = "archi.bin";
    Pila pila;
    inicpila(&pila);
    int edad;
    int res = 0;
    int anio;

    stAlumno arrAlumnos[DIM];
    int val = 0;
    char archiArr[] = "archiArr.bin";

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
            mostrarAlumnosArchivo(archi);
            break;
        case 6:
            agregarAlumno(archi);
            break;
        case 7:
            pasarLegajosAPila(archi,&pila);
            mostrar(&pila);
            break;
        case 8:
            edad = pedirEntero("Ingrese una edad: ");
            res  = contarCantDeAlumnosMayorDeEdad(archi,edad);
            printf("La canidad de alumonos por la edad pasada fueron:%d\n",res);
            break;
        case 9:
            mostrarAlumnosEnRango(archi,29,32);
            break;
        case 10:
            mostrarAlumnosMayorDeEdad(archi);
            break;
        case 11:
            anio = pedirEntero("Ingrese un anio: ");
            res = cantidadDeAlumnosPorAnio(archi, anio);
            printf("La cantidad de alumnos del anio elegido es: %d\n", res);
            val = pasarArchiAArr(archi, arrAlumnos, res, anio);
            printf("\n===== ARR =====\n");
            mostrarAlumnos(arrAlumnos, val);
            break;
        case 12:
            printf("\n===== ARCHIVO =====\n");
            pasarArrAArchi(arrAlumnos, val, archiArr);
            mostrarAlumnosArchivo(archiArr);
            break;
        case 13:
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
