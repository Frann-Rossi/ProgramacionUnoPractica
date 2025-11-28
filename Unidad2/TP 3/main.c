#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

int existeElemento (char arrCaracteres[],int val, char letra)
{
    int flag = 0;
    for(int i = 0; i < val; i++)
    {
        if(arrCaracteres[i] == letra)
        {
            flag = 1;
        }
    }
    return flag;
}

void insertarCaracter(char arrCaracteres[],int *val, char letra)
{
    int i = *val - 1;

    while(i >= 0 && arrCaracteres[i] > letra)
    {
        arrCaracteres[i+1] = arrCaracteres[i];
        i--;
    }
    arrCaracteres[i+1] = letra;
    (*val)++;
}

char maxCaracter(char arrCaracteres[],int val)
{
    char max = arrCaracteres[0];
    for(int i = 0; i < val; i++)
    {
        if(arrCaracteres[i] > max)
        {
            max = arrCaracteres[i];
        }
    }
    return max;
}

int esCapicua(int arr[],int val)
{
    int i = 0;
    int f = val - 1;
    int flag = 1;

    while(i < f)
    {
        if(arr[i] != arr[f])
        {
            flag = 0;
        }
        i++;
        f--;
    }
    return flag;
}

void invertirArreglo(int arr[], int val)
{
    int aux;
    int i = 0;
    int f = val- 1;
    while (i < f)
    {
        aux = arr[i];
        arr[i] = arr[f];
        arr[f] = aux;
        i++;
        f--;
    }
}

int buscarMenor (int arr[], int val,int posInicio)
{
    int posMenor = posInicio;
    int menor = arr[posInicio];
    for(int i = posInicio + 1; i < val; i++)
    {
        if(arr[i] < menor)
        {
            posMenor = i;
            menor = arr[i];
        }
    }
    return posMenor;
}

void ordenamientoPorSeleccion (int arr[],int val)
{
    int posMenor;
    int aux;
    for(int i = 0; i < val; i++)
    {
        posMenor = buscarMenor(arr,val,i);

        aux = arr[i];
        arr[i] = arr[posMenor];
        arr[posMenor] = aux;
    }
}

void insertarElemento(int arr[], int val,int elem)
{
    int i = val - 1;
    while(i >= 0 && elem < arr[i])
    {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i+1] = elem;
}

void ordenamientoPorInsercion(int arr[],int val)
{
    int aux;
    for(int i = 0; i < val; i++)
    {
        aux = arr[i];
        insertarElemento(arr,i,aux);
    }
}

void intercalarArreglos(char A[], int vA, char B[], int vB, char C[], int *vC)
{
    int i = 0; // índice para A
    int j = 0; // índice para B
    int k = 0; // índice para C

    // 1. EL DUELO: Mientras queden elementos en AMBOS arreglos
    while(i < vA && j < vB)
    {
        if(A[i] < B[j])
        {
            C[k] = A[i]; // Ganó A, lo guardo en C
            i++;         // Avanzo solo en A
        }
        else
        {
            C[k] = B[j]; // Ganó B (o son iguales), lo guardo en C
            j++;         // Avanzo solo en B
        }
        k++; // En C avanzo siempre porque acabo de guardar algo
    }

    // 2. LOS SOBRANTES DE A: Si A tenía más elementos o eran muy grandes
    while(i < vA)
    {
        C[k] = A[i];
        i++;
        k++;
    }

    // 3. LOS SOBRANTES DE B: Si B tenía más elementos
    while(j < vB)
    {
        C[k] = B[j];
        j++;
        k++;
    }

    // Guardamos la cantidad total de elementos resultantes
    *vC = k;
}


void sumarVector (int arr[],int val,int arrSum[])
{
    int sum = 0;
    for(int i = 0; i < val; i++)
    {
        sum += arr[i];
        arrSum[i] = sum;
    }
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
    char letra;
    char max;
    int capicua;
    int arrSum[DIM];

    // Arreglo 1 (Ordenado)
    char A[] = {'a', 'd', 'f', 'j'};
    int vA = 4;

    // Arreglo 2 (Ordenado)
    char B[] = {'b', 'c', 'e', 'h', 'i'};
    int vB = 5;

    // Arreglo para el resultado (con espacio suficiente)
    char C[100];
    int vC = 0;


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
            scanf("%c",&letra);
            printf("La letra seleccionada fue encotrada %c\n",letra);
            break;
        case 7:
            valChar = cargarArrCaracteres(arrCaracteres,DIM);
            mostrarArrCaracteres(arrCaracteres,valChar);
            printf("Elija una letra para agregar\n");
            fflush(stdin);
            scanf("%c",&letra);
            insertarCaracter(arrCaracteres,&valChar,letra);
            mostrarArrCaracteres(arrCaracteres,valChar);
            break;
        case 8:
            valChar = cargarArrCaracteres(arrCaracteres,DIM);
            max = maxCaracter(arrCaracteres,valChar);
            printf("El caracter mas grande fue %c\n",max);
            break;
        case 9:
            val = cargarArr(arr,DIM);
            capicua = esCapicua(arr,val);
            if (capicua)
                printf("El arreglo de enteros ES capicúa.\n");
            else
                printf("El arreglo de enteros NO es capicúa.\n");
            break;
        case 10:
            val = cargarArr(arr,DIM);
            mostrarArr(arr,val);
            invertirArreglo(arr,val);
            mostrarArr(arr,val);
            break;
        case 11:
            val = cargarArr(arr,DIM);
            mostrarArr(arr,val);
            ordenamientoPorSeleccion(arr,val);
            printf("SELECCION\n");
            mostrarArr(arr,val);
            ordenamientoPorInsercion(arr,val);
            printf("INSERCION\n");
            mostrarArr(arr,val);
            break;
        case 12:
            intercalarArreglos(A,vA,B,vB,C,&vC);
            mostrarArrCaracteres(C,vC);
            break;
        case 13:
            val = cargarArr(arr,DIM);
            mostrarArr(arr,val);
            sumarVector(arr,val,arrSum);
            mostrarArr(arrSum,val);
            break;
        default:
            printf("Elija un valor valido\n");
        }
        printf("Desea seguir en el PROGRAMA 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
    }
}
