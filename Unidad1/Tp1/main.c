#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void devuelveMayorYMenor(int nro1, int nro2, int nro3, int *menor, int *mayor){
    *menor = devuelveMenor(nro1,nro2,nro3);
    *mayor = devuelveMayor(nro1,nro2,nro3);
}

int sumarNro (int nro)
{
    int suma = 0;
    for (int i = 0; i  < nro; i++)
    {
        suma += i;
    }
    return suma;
}

int main()
{
    srand(time(NULL));

    char control = 's';
    int opcion;
    int nro;

    int menor;
    int mayor;

    while(control == 's')
    {
        printf("Ej 1 \n");
        printf("Ej 2 \n");
        printf("Ej 3 \n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
        {
            printf("Valor random: %d\n",nroRandom());
            break;
        }
        case 2:
        {
            devuelveMayorYMenor(1,2,3,&menor,&mayor);
            printf("Menor: %d, Mayor: %d\n", menor, mayor);
            break;
        }
        case 3:
        {
            printf("Ingrese un Numero \n");
            scanf("%d", &nro);
            printf("La suma de los numeros es:%d \n", sumarNro(nro));

            break;
        }
        default:
        {
            printf("Valor invalido \n");
            break;
        }
        }
        printf("Desea seguir 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
    }

    return 0;
}
