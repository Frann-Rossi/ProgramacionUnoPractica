#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define DIM 30
#define DIM_NOMBRE 30
#define MAX_PERSONAS 20

// ======================= EJ 1 =======================
void cargarPilaKms(Pila* kms)
{
    char seguirDia = 's';

    while(seguirDia == 's')
    {
        char seguirTramo = 's';

        while(seguirTramo == 's')
        {
            leer(kms);
            printf("Desea seguir cargando tramos del dia? (s/n): ");
            scanf(" %c", &seguirTramo);
        }

        apilar(kms, -1);

        printf("Desea cargar otro dia? (s/n): ");
        scanf(" %c", &seguirDia);
    }
}

// ======================= EJ 2 =======================
void tramoMasLargo(Pila kms, int* kmMayor, int* diaMayor)
{
    *kmMayor = 0;
    *diaMayor = 1;

    int diaActual = 1;
    int dato;

    while(!pilavacia(&kms))
    {
        dato = desapilar(&kms);

        if(dato == -1)
        {
            diaActual++;
        }
        else if(dato > *kmMayor)
        {
            *kmMayor = dato;
            *diaMayor = diaActual;
        }
    }
}

// ======================= EJ 3 =======================
void mostrarPila(Pila kms)
{
    int dato;

    printf("\n--- RECORRIDO ---\n");

    while(!pilavacia(&kms))
    {
        dato = desapilar(&kms);

        if(dato == -1)
        {
            printf("\n");
        }
        else
        {
            printf("|%d| ", dato);
        }
    }

    printf("\n");
}

// ======================= EJ 4 =======================
void calcularCantKm(Pila kms, int arr[], int* val)
{
    int sum = 0;
    *val = 0;
    int dato;

    while(!pilavacia(&kms))
    {
        dato = desapilar(&kms);

        if(dato != -1)
        {
            sum += dato;
        }
        else
        {
            if(sum > 0)
            {
                arr[*val] = sum;
                (*val)++;
                sum = 0;
            }
        }
    }

    if(sum > 0)
    {
        arr[*val] = sum;
        (*val)++;
    }
}

void mostrarKmSumados(int arr[], int val)
{
    printf("\n--- KM POR DIA ---\n");

    for(int i = 0; i < val; i++)
    {
        printf("Dia %d: %d km\n", i + 1, arr[i]);
    }
}

// ======================= EJ 5 =======================
void cargarNombre(char persona[])
{
    printf("Ingrese nombre: ");
    scanf("%s", persona);
}

int cargarNombres(char arr[][DIM_NOMBRE], int dim)
{
    char control = 's';
    int i = 0;

    while(control == 's' && i < dim)
    {
        cargarNombre(arr[i]);
        i++;

        printf("Desea seguir cargando nombres? (s/n): ");
        scanf(" %c", &control);
    }

    return i;
}

void mostrarNombres(char arr[][DIM_NOMBRE], int val)
{
    printf("\n--- LISTA DE PERSONAS ---\n");

    for(int i = 0; i < val; i++)
    {
        printf("%s\n", arr[i]);
    }
}

// ======================= EJ 6 =======================
void insertar(char arr[][DIM_NOMBRE], int val, char elem[])
{
    int i = val - 1;

    while(i >= 0 && strcmpi(elem, arr[i]) < 0)
    {
        strcpy(arr[i + 1], arr[i]);
        i--;
    }

    strcpy(arr[i + 1], elem);
}

void ordenamientoPorInsercion(char arr[][DIM_NOMBRE], int val, char arrNuevo[][DIM_NOMBRE])
{
    for(int i = 0; i < val; i++)
    {
        insertar(arrNuevo, i, arr[i]);
    }
}

// ======================= MAIN =======================
int main()
{
    char control = 's';
    int opcion;

    Pila kms;
    inicpila(&kms);

    int kmMasLargo = 0;
    int diaMayor = 0;

    int arrDeKms[DIM];
    int val;

    char arrDePersonas[MAX_PERSONAS][DIM_NOMBRE];
    int valPersonas = 0;

    char arrNuevoDePersonas[MAX_PERSONAS][DIM_NOMBRE];

    while(control == 's')
    {
        printf("\n=========== MENU ===========\n");
        printf("1. Cargar pila de kms\n");
        printf("2. Tramo mas largo y dia\n");
        printf("3. Mostrar recorrido por dias\n");
        printf("4. Calcular km por dia\n");
        printf("5. Cargar nombres\n");
        printf("6. Ordenar nombres (insercion en otro arreglo)\n");
        printf("0. Salir\n");
        printf("============================\n");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            cargarPilaKms(&kms);
            printf("\nPila cargada:\n");
            mostrar(&kms);
            break;

        case 2:
            tramoMasLargo(kms, &kmMasLargo, &diaMayor);
            printf("Tramo mas largo: %d km - Dia: %d\n", kmMasLargo, diaMayor);
            break;

        case 3:
            mostrarPila(kms);
            break;

        case 4:
            calcularCantKm(kms, arrDeKms, &val);
            mostrarKmSumados(arrDeKms, val);
            break;

        case 5:
            valPersonas = cargarNombres(arrDePersonas, MAX_PERSONAS);
            mostrarNombres(arrDePersonas, valPersonas);
            break;

        case 6:
            ordenamientoPorInsercion(arrDePersonas, valPersonas, arrNuevoDePersonas);
            mostrarNombres(arrNuevoDePersonas, valPersonas);
            break;

        case 0:
            control = 'n';
            printf("Saliendo...\n");
            break;

        default:
            printf("Opcion invalida\n");
        }

        if(control == 's')
        {
            printf("\nDesea continuar? (s/n): ");
            scanf(" %c", &control);
        }
    }

    return 0;
}
