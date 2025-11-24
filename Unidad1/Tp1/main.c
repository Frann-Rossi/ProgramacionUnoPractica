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
        printf("\n======================================================\n");
        printf("    TRABAJO PRACTICO N1 - FUNCIONES CON VARIABLES     \n");
        printf("======================================================\n");
        printf(" 1. Generar numero Random (0 a 100)\n");
        printf(" 2. Mayor y Menor de 3 numeros\n");
        printf(" 3. Sumatoria de anteriores a N\n");
        printf(" 4. Tabla de multiplicar de un numero\n");
        printf(" 5. Calculadora (Suma, Resta, Mult, Div)\n");
        printf(" 6. Cambiar signo a Negativo (Paso por Referencia)\n");
        printf(" 7. Cargar dos valores dentro de funcion (Referencia)\n");
        printf(" 0. Salir\n");
        printf("======================================================\n");
        printf("Ingrese opcion: ");
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
