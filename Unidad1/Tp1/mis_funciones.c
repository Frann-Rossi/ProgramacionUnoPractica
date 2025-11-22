#include <stdio.h>
#include <stdlib.h>
#include "mis_funciones.h"


//EJ 1
int nroRandom ()
{
    return rand() % 101;
}

//EJ 2
int devuelveMenor (int nro1, int nro2, int nro3)
{
    if(nro1 < nro2 && nro1 < nro3)
    {
        return nro1;
    }
    else if(nro2 < nro1 && nro2 < nro3)
    {
        return nro2;
    }
    else
    {
        return nro3;
    }
}

int devuelveMayor (int nro1, int nro2, int nro3)
{
    if(nro1 > nro2 && nro1 > nro3)
    {
        return nro1;
    }
    else if(nro2 > nro1 && nro2 > nro3)
    {
        return nro2;
    }
    else
    {
        return nro3;
    }
}

void devuelveMayorYMenor(int nro1, int nro2, int nro3, int *menor, int *mayor)
{
    *menor = devuelveMenor(nro1,nro2,nro3);
    *mayor = devuelveMayor(nro1,nro2,nro3);
}

//EJ 3
int sumarNro (int nro)
{
    int suma = 0;
    for (int i = 0; i  < nro; i++)
    {
        suma += i;
    }
    return suma;
}

//EJ 4
void tablaMultiplicar (int nro)
{
    int resultado;
    for(int i = 0; i <= 10; i++)
    {
        resultado = nro * i;
        printf("%d * %d = %d\n",nro,i, resultado);
    }
}

//EJ 5
int sumar(int nro1,int nro2)
{
    return nro1 + nro2;
}

int restar(int nro1,int nro2)
{
    return nro1 - nro2;
}

int multiplicar(int nro1,int nro2)
{
    return nro1 * nro2;
}

int dividir(int nro1,int nro2)
{
    if(nro2 == 0)
    {
        printf("No puede dividir por 0");
        return 0;
    }
    return nro1 / nro2;
}

void calculadora(int nro1, int nro2, int opcion) {
    int res = 0;
    // Agregué printf para ver los resultados
    switch(opcion) {
        case 1:
            res = sumar(nro1, nro2);
            printf("Resultado suma: %d\n", res);
            break;
        case 2:
            res = restar(nro1, nro2);
            printf("Resultado resta: %d\n", res);
            break;
        case 3:
            res = multiplicar(nro1, nro2);
            printf("Resultado mult: %d\n", res);
            break;
        case 4:
            res = dividir(nro1, nro2);
            if(nro2 != 0) printf("Resultado div: %d\n", res);
            break;
        default:
            printf("Opcion invalida\n");
    }
}

// Ej 6
int devolverNroNegativo(int nro){
 return -nro;
}

void valoresPorReferencia(int* nro1, int* nro2){
    printf("Ingrese dos Numeoros\n");
    scanf("%d",nro1);
    scanf("%d",nro2);
}

