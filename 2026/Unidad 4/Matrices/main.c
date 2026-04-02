#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define DIMCOL 3
#define DIMFILA 3

#define DIMCOLSTR 30
#define DIMFILASTR 10

// --------------------------------------------------
// EJERCICIO 1
void cargarMatriz (int matriz[][DIMCOL])
{
    for(int f = 0; f < DIMFILA; f++)
    {
        for(int c = 0; c < DIMCOL; c++)
        {
            printf("Ingrese un numero para |%d||%d|:",f,c);
            scanf("%d",&matriz[f][c]);
        }
    }
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 2
void mostrarMatriz (int matriz[][DIMCOL])
{
    for(int f = 0; f < DIMFILA; f++)
    {
        for(int c = 0; c < DIMCOL; c++)
        {
            printf("|%d|",matriz[f][c]);
        }
        printf("\n");
    }
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 3
void cargarMatrizRandom(int matriz[][DIMCOL])
{
    srand(time(NULL));
    for(int f = 0; f < DIMFILA; f++ )
    {
        for(int c = 0; c < DIMCOL; c++ )
        {
            matriz[f][c] = rand()%10;
        }
    }
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 4
int sumarMatriz (int matriz[][DIMCOL])
{
    int sum = 0;
    for(int f = 0; f < DIMFILA; f++)
    {
        for(int c = 0; c < DIMCOL; c++)
        {
            sum += matriz[f][c];
        }
    }
    return sum;
}
// --------------------------------------------------

// --------------------------------------------------
int cantElemMatriz (int matriz[][DIMCOL])
{
    int cant = 0;
    for (int f = 0; f < DIMFILA; f++)
    {
        for (int c = 0; c < DIMCOL; c++)
        {
            cant++;
        }
    }
    return cant;
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 5
float promedioMatriz(int matriz[][DIMCOL])
{
    int suma = sumarMatriz(matriz);
    int cant = cantElemMatriz(matriz);
    float promedio = (float)suma / cant;
    return promedio;
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 6
int buscarElemMatriz (int matriz[][DIMCOL], int num)
{
    int flag = 0;
    for(int f = 0; f < DIMFILA; f++)
    {
        for(int c = 0; c < DIMCOL; c++)
        {
            if(num == matriz[f][c])
            {
                flag = 1;
            }
        }
    }
    return flag;
}
// --------------------------------------------------

// --------------------------------------------------
int pedirNumero()
{
    int num;
    printf("Ingrese un NUMERO:");
    scanf("%d",&num);
    return num;
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 7
int cargarMatrizPalabras(char matrizStr[][DIMCOLSTR])
{
    int i = 0;
    char control = 's';
    while(control == 's' && i < DIMFILASTR)
    {
        printf("Cargue una palabra:");
        scanf("%29s",matrizStr[i]);
        printf("Desea seguir 's/n':");
        scanf(" %c",&control);
        i++;
    }
    return i;
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 8
void mostrarMatrizDeStr(char matrizStr[][DIMCOLSTR], int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%s|\n",matrizStr[i]);
    }
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 9
int buscarString (char matrizStr[][DIMCOLSTR],int val, char palabraBuscada[])
{
    int flag = -1;
    for(int i = 0; i < val && flag == -1 ; i++)
    {
        if(strcmpi(matrizStr[i],palabraBuscada) == 0)
        {
            flag = i;
        }
    }
    return flag;
}
// --------------------------------------------------

// --------------------------------------------------
void pedirPalabra(char palabra[])
{
    printf("Ingrese la palabra:");
    fflush(stdin);
    scanf("%29s",palabra);
}
// --------------------------------------------------

// --------------------------------------------------
// EJERCICIO 10
// --------------------------------------------------


int main()
{
    char control = 's';
    int opcion;

    int matriz[DIMFILA][DIMCOL];
    int res;
    float promedio;
    int num;
    char matrizPalabras[DIMFILASTR][DIMCOLSTR];
    int valPalabras;
    char palabra[DIMCOLSTR];

    while(control == 's')
    {
        printf("Cargar MATRIZ == 1\n");
        printf("Mostrar MATRIZ == 2\n");
        printf("Cargar MATRIZ RANDOM == 3\n");
        printf("Sumar MATRIZ == 4\n");
        printf("Promedio MATRIZ == 5\n");
        printf("Encontrar NUM en MATRIZ == 6\n");
        printf("Cargar MATRIZ de PALABRAS == 7\n");
        printf("Mostrar MATRIZ de PALABRAS == 8\n");
        printf("Buscar String dentro de un arr == 9\n");
        printf("SALIR == 0\n");
        printf("\nIngrese una opcion:");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarMatriz(matriz);
            break;
        case 2:
            mostrarMatriz(matriz);
            break;
        case 3:
            cargarMatrizRandom(matriz);
            break;
        case 4:
            res = sumarMatriz(matriz);
            printf("La SUMA de la Matriz fue:%d\n",res);
            break;
        case 5:
            promedio = promedioMatriz(matriz);
            printf("El promedio de la matriz fue:%.2f\n",promedio);
            break;
        case 6:
            num = pedirNumero();
            res = buscarElemMatriz(matriz,num);
            if(res)
            {
                printf("El Numero %d fue encontrado",num);
            }
            else
            {
                printf("El Numero %d NO fue encontrado\n",num);
            }
            break;
        case 7:
            valPalabras = cargarMatrizPalabras(matrizPalabras);
            break;
        case 8:
            mostrarMatrizDeStr(matrizPalabras,valPalabras);
            break;
        case 9:
            pedirPalabra(palabra);
            res = buscarString(matrizPalabras,valPalabras,palabra);
            if(res != -1)
            {
                printf("La palabra se encuentra en la pos:%d\n",res);
            }
            else
            {
                printf("La palabra no se encontro\n");
            }
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo...\n");
            break;
        default:
            printf("\nIngrese un valor valido\n");
        }
        if(control == 's')
        {
            printf("\nDesea continuar 's/n':");
            scanf(" %c",&control);
        }
    }
}
