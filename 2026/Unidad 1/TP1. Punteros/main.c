#include <stdio.h>
#include <stdlib.h>

void valorNegativo (int* num)
{
    printf("\nIngrese un numero:");
    scanf("%d",num);
    *num = -*num;
}

void cargarNumeros (int* num1, int* num2)
{
    printf("Ingrese el numero 1:");
    scanf("%d",num1);
    printf("\nIngrese el numero 2:");
    scanf("%d",num2);
}

void validarEdad (int* edad)
{
    int flag = 1;
    while(flag)
    {
        printf("Ingrese una edad:");
        scanf("%d",edad);
        if(*edad > 0 && *edad <= 18)
        {
            printf("Edad ingresada es:%d",*edad);
            flag = 0;
        }
        else
        {
            printf("La edad no es correcta ingrese nuevamente una edad\n");
        }

    }
}

int dividir (int dividendo, int divisor, int* resto)
{
    int res;
    printf("\nIngrese un dividendo:");
    scanf("%d",&dividendo);
    printf("\nIngrese un divisor:");
    scanf("%d",&divisor);
    if(divisor != 0)
    {
        res = dividendo / divisor;
        *resto = dividendo % divisor;
    }
    else
    {
        res = 0;
        *resto = 0;
        printf("No  puede dividirse por 0\n");
    }
    return res;
}

int convertirTiempo(int seg, int* horas)
{
    printf("Ingrse seg:");
    scanf("%d",&seg);
    *horas = seg / 3600;
    int min = seg / 60;
    return min;

}

int main()
{
    char control = 's';
    int opc;
    int a;
    int b;
    int edad;
    int res;
    int resto;
    int minutos;

    while (control == 's')
    {
        printf("\nPasar numero a negativo == 1\n");
        printf("Cargar Numeros == 2\n");
        printf("Validar EDAD == 3\n");
        printf("Dividir == 4\n");
        printf("Tiempo a Min y Horas == 5\n");
        printf("Salir del Programa == 0\n");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            valorNegativo(&a);
            printf("El numero:%d\n",a);
            break;
        case 2:
            cargarNumeros(&a,&b);
            printf("El numero1:%d\n",a);
            printf("El numero2:%d\n",b);
            break;
        case 3:
            validarEdad(&edad);
            break;
        case 4:
            res = dividir(a,b,&resto);
            printf("Resultado:%d//Resto:%d\n", res,resto);
            break;
        case 5:
            minutos = convertirTiempo(a,&b);
            printf("Minutos:%d\n",minutos);
            printf("Horas:%d\n",b);
            break;
        case 0:
            control = 'n';
            printf("Saliendo...\n");
            break;
        default:
            printf("Ingrese un valor valido\n");
        }

        if(control == 's')
        {
            printf("\nDesea continuar 's/n':");
            scanf(" %c",&control);
        }
    }

    return 0;
}
