#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIM 5

//********************
// Ejercicio 1
int cargarArr (int arr[],int dim)
{
    char control = 's';
    int i = 0;
    while(control == 's' && i < dim )
    {
        printf("\nIngrese un NUMERO:");
        scanf("%d",&arr[i]);
        printf("\nDesea seguir 's/n':");
        scanf(" %c",&control);
        i++;
    }
    return i;
}

void cargarArrPuntero (int arr[],int dim, int *val)
{
    char control = 's';
    while(control == 's' && *val < dim )
    {
        printf("\nIngrese un NUMERO:");
        scanf("%d",&arr[*val]);
        printf("\nDesea seguir 's/n':");
        scanf(" %c",&control);
        (*val)++;
    }
}
//********************

//********************
// Ejercicio 2
void mostrarArr(int arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%d|",arr[i]);
    }
}

int cantDeElemArr(int arr[],int val)
{
    int cant;
    for(int i = 0; i < val; i++)
    {
        cant++;
    }
    return cant;
}
//********************

//********************
// Ejercicio 3
int sumarArr(int arr[],int val)
{
    int sum = 0;
    for(int i = 0; i < val; i++)
    {
        sum += arr[i];
    }
    return sum;
}
//********************


//********************
// Ejercicio 4

void pasarArrAPila(int arr[],int val,Pila *a)
{
    for(int i = 0; i < val; i++)
    {
        apilar(a,arr[i]);
    }
}
//********************

//********************
// Ejercicio 6
int encontrarElemento(int arr[],int val, int nroBuscado)
{
    int flag = 0;
    for(int i = 0; i < val; i++)
    {
        if(nroBuscado == arr[i])
        {
            flag = 1;
        }
    }
    return flag;
}

void solicitarNro(int *nro)
{
    printf("Ingrese un Nro:");
    scanf("%d",nro);
}

//********************

//********************
// Ejercicio 7
int cargarArrChar(char arrChar[], int dim)
{
    char control = 's';
    int i = 0;
    while(control == 's' && i < dim)
    {
        printf("\nIngrese una letra:");
        scanf(" %c",&arrChar[i]);
        printf("\nDesea seguir 's/n':");
        scanf(" %c",&control);
        i++;
    }
    return i;
}

void mostrarArrChar(char arrChar[],int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%c|",arrChar[i]);
    }
}

int agregarElem (char arrChar[], int val,char letra)
{
    int i;
    for(i = val - 1; i >= 0 && letra < arrChar[i] ; i--)
    {
        arrChar[i+1] = arrChar[i];
    }
    arrChar[i+1] = letra;

    return val+1;
}

//********************
int main()
{
    char control = 's';
    int opcion;

    int arr[DIM];
    int val;
    int sumNum;

    Pila a;
    inicpila(&a);

    int nro;
    int res;
    int cant = 0;

    char arrChar[DIM];

    while(control == 's')
    {
        printf("Cargar ARR == 1\n");
        printf("Cargar ARR por Punteros == 2\n");
        printf("Mostrar ARR == 3\n");
        printf("Caluclar Suma de ARR == 4\n");
        printf("Pasar ARR a Pila == 5\n");
        printf("Encontrar Numero en ARR == 6\n");
        printf("Cargar ARR de Char y Mostrar == 7\n");
        printf("Salir == 0\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            val = cargarArr(arr,DIM);
            break;
        case 2:
            cargarArrPuntero(arr,DIM,&val);
            break;
        case 3:
            cant = cantDeElemArr(arr,val);
            printf("La CANTIDAD de Elementos en el ARR es:%d\n",cant);
            mostrarArr(arr,val);
            break;
        case 4:
            sumNum = sumarArr(arr,val);
            printf("La suma del ARR fue de:%d\n",sumNum);
            break;
        case 5:
            pasarArrAPila(arr,val,&a);
            mostrar(&a);
            break;
        case 6:
            solicitarNro(&nro);
            res = encontrarElemento(arr,val,nro);
            if(res)
            {
                printf("El Numero %d fue encontrado\n", nro);
            }
            else
            {
                printf("El Numero %d NO fue encontrado\n",nro);
            }
            break;
        case 7:
            val = cargarArrChar (arrChar,DIM);
            mostrarArrChar(arrChar,val);
            val = agregarElem(arrChar,val,'b');
            printf("\n");
            mostrarArrChar(arrChar,val);
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
