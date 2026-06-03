#include <stdio.h>
#include <stdlib.h>

#define DIM 10

void menu()
{
    printf("\n====================================\n");
    printf(" TP N°9 - RECURSION\n");
    printf("====================================\n");

    printf("1  - Factorial recursivo\n");

    printf("2  - Potencia recursiva\n");

    printf("3  - Mostrar arreglo recursivamente\n");

    printf("4  - Mostrar arreglo invertido recursivamente\n");

    printf("5  - Verificar si arreglo es capicua\n");

    printf("6  - Sumar elementos de arreglo recursivamente\n");

    printf("7  - Buscar menor elemento de arreglo\n");

    printf("8  - Buscar menor elemento de archivo\n");

    printf("9  - Invertir archivo recursivamente\n");

    printf("10 - Mostrar archivo invertido recursivamente\n");

    printf("11 - Mostrar caracteres invertidos\n");

    printf("12 - Buscar elemento en arreglo recursivamente\n");

    printf("0  - Salir\n");

    printf("====================================\n");
    printf("Seleccione una opcion: ");
}

int pedirNum (char mensaje[])
{
    int num;
    printf("%s",mensaje);
    scanf("%d",&num);
    return num;
}

int factorial (int num)
{
    int rta = 0;
    if(num == 1)
    {
        rta = 1;
    }
    else
    {
        rta = num * factorial(num - 1);
    }
    return rta;
}

int potencia (int base, int exponente)
{
    int rta = 0;
    if(exponente == 0)
    {
        rta = 1;
    }
    else
    {
        rta = base * potencia(base,exponente - 1);
    }
    return rta;
}

int cargarArr(int arr[],int dim,int i)
{
    char control = 's';
    int val = i;
    if(i < dim)
    {
        arr[i] = pedirNum("\nIngrese un numero para el arr:");
        printf("\nDesea seguir cargando numero 's/n':");
        scanf(" %c",&control);
        if(control == 's')
        {
            val = cargarArr(arr,dim,i+1);
        }
        else
        {
            val = i + 1;
        }

    }
    return val;
}

void mostrarArr(int arr[],int val, int i)
{

    if(i < val)
    {
        printf("|%d|",arr[i]);
        mostrarArr(arr,val,i+1);
    }
}

void mostrarArrInvertido(int arr[],int val, int i)
{

    if(i < val)
    {
        mostrarArrInvertido(arr,val,i+1);
        printf("|%d|",arr[i]);
    }
}

int sumarArrRecursiva(int arr[],int val, int i)
{
    int suma = 0;
    if(i < val)
    {
        suma = arr[i] + sumarArrRecursiva(arr,val,i+1);
    }
    return suma;
}

int arrCapicuaRecursiva(int arr[],int val, int i)
{
    int rta;
    int j =  val - 1 - i;
    if(i >= j)
    {
        rta = 1;
    }
    else
    {
        if(arr[i] != arr[j])
        {
            rta = 0;
        }
        else
        {
            rta = arrCapicuaRecursiva(arr, val, i + 1);
        }
    }
    return rta;
}

int buscarMenorElementoRecursiva (int arr[],int val,int i)
{
    int menor = 0;
    if(i < val)
    {
        if(arr[i] < menor)
        {
            menor = arr[i];
        }
        menor = buscarMenorElementoRecursiva(arr,val,i+1);
    }
    return menor;
}

void cargarArchiNumeros(char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");
    int num;
    char control = 's';
    if(buffer)
    {
        while(control == 's')
        {
            num = pedirNum("\nIngrese un numero para el archivo:");
            fwrite(&num,sizeof(int),1,buffer);
            printf("\nDesea seguir cargando numero al archivo 's/n':");
            scanf(" %c",&control);
        }
        fclose(buffer);
    }
}

void mostrarArchivoNum(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int num;
    if(buffer)
    {
        while(fread(&num,sizeof(int),1,buffer)>0)
        {
            printf("|%d|",num);
        }
        fclose(buffer);
    }
}

int buscarMenorElementoRecursivaArchivo(FILE* buffer)
{
    int num;
    int menor;
    if(fread(&num,sizeof(int),1,buffer)>0)
    {
        menor = buscarMenorElementoRecursivaArchivo(buffer);
        if(num < menor)
        {
            menor = num;
        }
    }
    else
    {
        menor = 999999;
    }
    return menor;
}



int main()
{
    char control = 's';
    int opcion;

    int res = 0;
    int num;
    int base;
    int exponente;

    int arr[DIM];
    int i = 0;
    int val = 0;

    char archivo[] = "archiNum.bin";

    while(control == 's')
    {
        menu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            num = pedirNum("Ingrese un num para factorial:");
            res = factorial(num);
            printf("El factorial de %d fue:%d",num,res);
            break;
        case 2:
            base = pedirNum("Ingrese la base: ");
            exponente = pedirNum("Ingrese el exponente: ");
            res = potencia(base, exponente);
            printf("La potencia de %d con el exponente %d es de:%d",base,exponente,res);
            break;
        case 3:
            val = cargarArr(arr,DIM,i);
            mostrarArr(arr,val,i);
            break;
        case 4:
            mostrarArrInvertido(arr,val,i);
            break;
        case 8:
            cargarArchiNumeros(archivo);
            mostrarArchivoNum(archivo);
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
    return 0;
}
