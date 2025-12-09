#include <stdio.h>
#include <stdlib.h>

#define DIM 30

int factorial(int num)
{
    int res;

    if(num == 0)
    {
        res = 1;
    }
    else
    {
        res = num * factorial(num - 1);
    }
    return res;
}

int potencia(int base, int exp)
{
    int res;
    if(exp == 0)
    {
        res = 1;
    }
    else
    {
        res = base * potencia(base,exp - 1);
    }
    return res;
}

int cargarArr(int arr[],int i,int dim)
{
    int cantidad;
    char continuar = 's';
    if(i == dim)
    {
        cantidad = dim;
    }
    else
    {
        printf("Ingrese valor para la posicion %d: ", i);
        scanf("%d", &arr[i]);
        printf("Desea continuar? (s/n): ");
        fflush(stdin);
        scanf("%c", &continuar);
        if(continuar == 's')
        {
            cantidad = cargarArr(arr,i+1,dim);
        }
        else
        {
            cantidad = i + 1;
        }
    }
    return cantidad;
}

void mostrarArr(int arr[], int i, int validos)
{
    if(i < validos)
    {
        printf("[%d] ", arr[i]);
        mostrarArr(arr, i + 1, validos);
    }
}

void mostrarArrInvertida(int arr[], int i, int validos)
{
    if(i < validos)
    {
        mostrarArrInvertida(arr, i + 1, validos);
        printf("[%d] ", arr[i]);
    }
}

int capicua(int arr[], int i, int val)
{
    int res;
    if(i >= val / 2)
    {
        res = 1;
    }
    else
    {
        if(arr[i]==arr[val-1-i])
        {
            res = capicua(arr, i+1,val);
        }
        else
        {
            res = 0;
        }
    }
    return res;
}

int sumarRecuriva(int arr[], int val,int i){

    int rta;

    if(i == val){
        rta = 0;
    }
    else{
        rta = arr[i] + sumarRecuriva(arr,val,i+1);
    }
    return rta;
}

int main()
{
    char control = 's';
    int opcion;
    int num,res,b, e;
    int arr[DIM];
    int val = 0;

    while(control == 's')
    {
        printf("\n--- TRABAJO PRACTICO N9: RECURSION ---\n");
        printf("1.  Calcular factorial (recursivo)\n");
        printf("2.  Calcular potencia (recursivo)\n");
        printf("3.  Recorrer y mostrar arreglo (recursivo)\n");
        printf("4.  Recorrer y mostrar arreglo invertido (recursivo)\n");
        printf("5.  Determinar si un arreglo es capicua\n");
        printf("6.  Sumar elementos de arreglo (recursivo)\n");
        printf("7.  Buscar menor elemento de arreglo (recursivo)\n");
        printf("8.  Buscar menor elemento en ARCHIVO (recursivo)\n");
        printf("9.  Invertir elementos de ARCHIVO (recursivo)\n");
        printf("10. Mostrar elementos de ARCHIVO invertidos\n");
        printf("11. Invertir caracteres ingresados (sin arreglos)\n");
        printf("12. Buscar elemento en arreglo (recursivo)\n");
        printf("0.  Salir\n");
        printf("------------------------------------------\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("\nIngrese un numero para calcular su factorial: ");
            scanf("%d",&num);
            res = factorial(num);
            printf("El factorial de %d es: %d\n", num, res);
            break;
        case 2:
            printf("Ingrese base: ");
            scanf("%d", &b);
            printf("Ingrese exponente: ");
            scanf("%d", &e);
            printf("El resultado es: %d\n", potencia(b, e));
            break;
        case 3:
            printf("\n--- Cargando Arreglo ---\n");
            val = cargarArr(arr, 0, DIM);

            printf("\n--- Mostrando Arreglo (Recursivo) ---\n");
            mostrarArr(arr, 0, val);
            printf("\n");
            break;
        case 4:
            printf("\n--- Cargando Arreglo ---\n");
            val = cargarArr(arr, 0, DIM);
            printf("\n--- Mostrando Arreglo (Recursivo) ---\n");
            mostrarArrInvertida(arr, 0, val);
            printf("\n");
            break;
        case 5:
            if( capicua(arr, 0, val) == 1 )
            {
                printf("El arreglo ES CAPICUA.\n");
            }
            else
            {
                printf("El arreglo NO ES CAPICUA.\n");
            }
            break;
        case 0:
            control = 'n';
            printf("Saliendo.....");
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        if(control == 's')
        {
            printf("Desea seguir en el programa 's/n':");
            fflush(stdin);
            scanf("%c",&control);
        }
    }
    return 0;
}
