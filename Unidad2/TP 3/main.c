#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define DIM 30

int cargarArr(int arr[],int dim)
{
    int val = 0;
    char control = 's';
    while(control == 's' && val <= dim)
    {
        printf("Ingrese un numero para el arr\n");
        scanf("%d",&arr[val]);
        printf("Desea seguir 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
        val++;
    }
    return val;
}

void mostrarArr(int arr[],int val)
{
    for(int i = 0; i < val; i++ )
    {
        printf("|%d|",arr[i]);
    }
    printf("\n");
}

int sumarArr(int arr[], int val)
{
    int sum = 0;
    for(int i = 0; i < val; i++)
    {
        sum += arr[i];
    }
    return sum;
}

void pasarElemDeArrAPila(int arr[],int val, Pila *destino)
{
    for(int i = 0; i < val; i++)
    {
        apilar(destino,arr[i]);
    }
}

float cargarArrFloat(float arr[],int dim)
{
    int val = 0;
    char control = 's';
    while(control == 's' && val <= dim)
    {
        printf("Ingrese un numero para el arr\n");
        scanf("%f",&arr[val]);
        printf("Desea seguir 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
        val++;
    }
    return val;
}

void mostrarArrFloat(float arr[],int val)
{
    for(int i = 0; i < val; i++ )
    {
        printf("|%.2f|",arr[i]);
    }
    printf("\n");
}

float sumarArrFloat(float arr[], int val)
{
    float sum = 0;
    for(int i = 0; i < val; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int cargarArrCaracteres (char arrCaracteres[],int dim)
{
    int val = 0;
    char control = 's';
    while(control == 's' && val <= dim)
    {
        printf("Ingrese un numero para el arr\n");
        fflush(stdin);
        scanf("%c",&arrCaracteres[val]);
        printf("Desea seguir 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
        val++;
    }
    return val;
}

void mostrarArrCaracteres(char arrCaracteres[],int val)
{
    for(int i = 0; i < val; i++ )
    {
        printf("|%c|",arrCaracteres[i]);
    }
    printf("\n");
}

int existeElemento (char arrCaracteres[],int val, char letra){
    int flag = 0;
    for(int i = 0; i < val; i++){
        if(arrCaracteres[i] == letra){
            flag = 1;
        }
    }
    return flag;
}

int main()
{
    char control = 's';
    int opcion;
    int arr[DIM];
    int val = 0;
    int resultado;
    Pila origen;
    inicpila(&origen);
    float arrReales[DIM];
    int valReales = 0;
    float sumaReales = 0;
    char arrCaracteres[DIM];
    int valChar = 0;
    char letraBuscada;


    while(control == 's')
    {
        printf("\n\n================ MENÚ DE EJERCICIOS ================\n");
        printf("1. Cargar arreglo de enteros\n");
        printf("2. Mostrar arreglo de enteros\n");
        printf("3. Sumar elementos del arreglo de enteros\n");
        printf("4. Copiar arreglo a Pila\n");
        printf("5. Sumar arreglo de reales (float)\n");
        printf("6. Buscar carácter en arreglo\n");
        printf("7. Insertar carácter en orden\n");
        printf("8. Máximo carácter del arreglo\n");
        printf("9. Determinar si arreglo enteros es capicúa\n");
        printf("10. Invertir arreglo (sin auxiliar)\n");
        printf("11. Ordenar arreglo enteros (Selección e Inserción)\n");
        printf("12. Intercalar dos arreglos de caracteres ordenados\n");
        printf("13. Generar vector acumulado\n");
        printf("0. Salir\n");
        printf("====================================================\n");
        printf("Elija una opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            val = cargarArr(arr,DIM);
            break;
        case 2:
            mostrarArr(arr,val);
            break;
        case 3:
            resultado = sumarArr(arr,val);
            printf("La suma fue de:%d\n",resultado);
            break;
        case 4:
            pasarElemDeArrAPila(arr,val,&origen);
            mostrar(&origen);
            break;
        case 5:
            valReales = cargarArrFloat(arrReales, DIM);
            mostrarArrFloat(arrReales, valReales);
            sumaReales = sumarArrFloat(arrReales, valReales);
            printf("La suma de los reales es: %.2f\n", sumaReales);
            break;
        case 6:
            valChar = cargarArrCaracteres(arrCaracteres,DIM);
            mostrarArrCaracteres(arrCaracteres,valChar);
            printf("Elija una letra para buscar\n");
            fflush(stdin);
            scanf("%c",&letraBuscada);
            printf("La letra seleccionada fue encotrada %c\n",letraBuscada);
            break;
        default:
            printf("Elija un valor valido\n");
        }
        printf("Desea seguir en el PROGRAMA 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
    }
}
