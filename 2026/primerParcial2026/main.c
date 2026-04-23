#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIM 30

//EJ 1
void cargarPilaKms(Pila* kms)
{
    char control = 's';
    int num;

    while(control == 's')
    {
        while(control == 's')
        {
            leer(kms);
            printf("\nDesea seguir cargando KMS 's/n':");
            scanf(" %c",&control);
        }
        apilar(kms,-1);
        printf("\nDesea seguir cargando DIAS 's/n':");
        scanf(" %c",&control);
    }
}

void pasarPilas(Pila* origen, Pila* destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

//EJ 2
void tramoMasLargo (Pila kms,int* kmMayor, int* cantDias)
{
    *cantDias = 0;
    *kmMayor = 0;
    int num = 0;
    while(!pilavacia(&kms))
    {
        num = desapilar(&kms);
        if(num == -1)
        {
            (*cantDias)++;
        }
        if(num > *kmMayor)
        {
            *kmMayor = num;
        }
    }
}


//EJ 3
void mostrarPila(Pila kms)
{
    int num = 0;
    while(!pilavacia(&kms))
    {
        num = desapilar(&kms);
        if(num != -1)
        {
            printf("|%d|",num);
        }
        else
        {
            printf("\n");
        }
    }
}

//EJ 4
void calcularCantKm(Pila kms, int arr[],int* val)
{
    int sum = 0;
    *val = 0;
    while(!pilavacia(&kms))
    {
        sum = desapilar(&kms);
        if(sum != -1)
        {
            sum += desapilar(&kms);
        }
        else
        {
            arr[*val] = sum;
            sum = 0;
            (*val)++;
        }
    }
}

void mostrarKmSumados(int arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%d|",arr[i]);
    }
}

int main()
{
    char control = 's';
    int opcion;

    Pila kms;
    inicpila(&kms);

    int kmMasLargo = 0;
    int cantDias = 0;

    int arrDeKms[DIM];

    int val;

    while(control == 's')
    {
        printf("Punto 1 == 1\n");
        printf("Punto 2 == 2\n");
        printf("Punto 3 == 3\n");
        printf("SALIR == 0\n");
        printf("Ingrese el valor:");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarPilaKms(&kms);
            mostrar(&kms);
            break;
        case 2:
            tramoMasLargo(kms,&kmMasLargo, &cantDias);
            printf("Dia con mas KM:%d // Cantidad de DIAS hechos:%d\n",kmMasLargo,cantDias);
            break;
        case 3:
            mostrarPila(kms);
            break;
        case 4:
            calcularCantKm(kms,arrDeKms,&val);
            mostrarKmSumados(arrDeKms,val);
            break;
        case 0:
            control = 'n';
            printf("SALIENDO.....");
            break;
        default:
            printf("Ingrese un valor valido");
        }

        if(control == 's')
        {
            printf("\nDesea seguir en el PROGRAMA 's/n':");
            scanf(" %c",&control);
        }
    }
}
