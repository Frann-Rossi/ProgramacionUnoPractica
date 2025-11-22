#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mis_funciones.h"

int main()
{
    srand(time(NULL));

    char control = 's';
    int opcion;
    int nro;
    int nro2;
    int menor,mayor;
    int opcionCalcu;

    while(control == 's')
    {
        printf("Ej 1 \n");
        printf("Ej 2 \n");
        printf("Ej 3 \n");
        printf("Ej 4 \n");
        printf("Ej 5 \n");
        printf("Ej 6 \n");
        printf("Ej 7 \n");
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
        case 4:
        {
            printf("Ingrese un Numero \n");
            scanf("%d", &nro);
            tablaMultiplicar(nro);

            break;
        }
        case 5:
        {
            printf("Elija una opcion para la calculadora con sus dos numeros \n");
            scanf("%d",&nro);
            scanf("%d",&nro2);
            printf("1.Sumar 2.Restar 3.Mult 4.Div\nOpcion: ");
            scanf("%d",&opcionCalcu);
            calculadora(nro,nro2,opcionCalcu);
            break;
        }

        case 6:
        {
            printf("Ingrese un Numero \n");
            scanf("%d", &nro);
            printf("El numero pasado en negativo %d\n",devolverNroNegativo(nro));
            break;
        }

        case 7:
        {
            valoresPorReferencia(&nro,&nro2);
            printf("Nro1 == %d // Nro2 == %d\n",nro,nro2);
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
