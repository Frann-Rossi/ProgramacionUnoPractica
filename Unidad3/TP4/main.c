#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM_FILA 3
#define DIM_COL 3

#define DIM_FILACHAR 30
#define DIM_COLCHAR 30

void cargarMatriz(int matriz[][DIM_COL])
{

    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            printf("Ingrese valor [%d][%d]: ", f, c);
            scanf("%d", &matriz[f][c]);
        }
    }
}
void mostrarMatriz (int matriz[][DIM_COL])
{
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            printf("|%d|",matriz[f][c]);
        }
        printf("\n");
    }
}

void cargarMatrizRandom (int matriz[][DIM_COL])
{
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            matriz[f][c] = rand() % 11;
        }
    }
}

int sumarMatriz(int matriz[][DIM_COL])
{
    int sum = 0;
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            sum += matriz[f][c];
        }
    }
    return sum;
}

float promedio (int matriz[][DIM_COL])
{
    int sum = 0;
    int cant = 0;
    float promedio;
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            sum += matriz[f][c];
            cant++;
        }
    }
    promedio = (float)sum / cant;
    return promedio;
}

int buscarNum (int matriz[][DIM_COL], int num)
{
    int flag = 0;
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            if(matriz[f][c] == num)
            {
                flag = 1;
            }
        }
    }
    return flag;
}

int cargarMatrizChar(char matrizChar[][DIM_COLCHAR], int dim)
{
    int f = 0;
    char control = 's';

    while(control == 's' && f < dim)
    {
        printf("Cargue un NOMBRE\n");
        fflush(stdin);
        scanf("%s",matrizChar[f]);
        f++;
        printf("Desea seguir cargando nombres 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    return f;
}

int main()
{
    char control = 's';
    int opcion;
    int matriz[DIM_FILA][DIM_COL];
    srand(time(NULL));
    int total;
    int numBuscado;
    int val = 0;
    char matrizChar[DIM_FILACHAR][DIM_COLCHAR];

    while(control == 's')
    {
        printf("\n\n--- MENU TP N4: MATRICES ---\n");
        printf("1.  Cargar matriz (Usuario) \n");
        printf("2.  Mostrar matriz \n");
        printf("3.  Cargar matriz (Aleatoria) \n");
        printf("4.  Sumar contenido total \n");
        printf("5.  Promedio de matriz \n");
        printf("6.  Buscar elemento en matriz \n");
        printf("7.  Cargar arreglo de palabras \n");
        printf("8.  Mostrar arreglo de palabras \n");
        printf("9.  Buscar string en arreglo \n");
        printf("10. Buscar string (arreglo ordenado) \n");
        printf("11. Ordenar arreglo de palabras \n");
        printf("12. Determinante matriz 2x2 \n");
        printf("13. Verificar Inversa matriz 2x2 \n");
        printf("14. Verificar matriz Simetrica \n");
        printf("15. Generar Matriz Identidad \n");
        printf("16. Ejercicio Extra: Elecciones \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            cargarMatriz(matriz);
            break;
        case 2 :
            mostrarMatriz(matriz);
            break;
        case 3:
            cargarMatrizRandom(matriz);
            mostrarMatriz(matriz);
            break;
        case 4:
            total = sumarMatriz(matriz);
            printf("La SUMA de la matriz fue:%d\n", total);
            break;
        case 5:
            printf("El promedio de la matriz es:%.2f\n",promedio(matriz));
            break;
        case 6:
            printf("Ingrese un num para buscar:\n");
            scanf("%d",&numBuscado);
            if(buscarNum(matriz,numBuscado) == 1)
            {
                printf("El numero %d ESTA en la matriz\n",numBuscado);
            }
            else
            {
                printf("El numero %d NO ESTA en la matriz\n",numBuscado);
            }
            break;
        case 7:
            val = cargarMatrizChar(matrizChar,DIM_FILACHAR);
            printf("Se cargaron %d nombres\n", val);
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        printf("Desea Seguir en el PROGRAMA 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);

    }
    return 0;
}
