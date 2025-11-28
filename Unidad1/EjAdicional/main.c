#include <stdio.h>
#include <stdlib.h>

int main()
{
    char control = 's';
    int opcion;

    int cantidad = 0;
    float precio = 0.00;
    float total = 0;

    while(control == 's')
    {
        printf("\n======================================================\n");
        printf("          SISTEMA DE GESTION - EMPRESA PIRULO         \n");
        printf("======================================================\n");
        printf(" 1. Realizar Venta (Cargar producto)\n");
        printf(" 2. Cerrar Caja (Mostrar totales del dia y salir)\n");
        printf("======================================================\n");
        printf("Ingrese opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            productosComprados(&cantidad,&precio);
            total = devolverMontoTotal(cantidad,precio);
            printf("Monto total de la venta:%.2f\n",total);
            break;
        default:
            printf("Ingrese un valor valido\n");
            break;
        }
        printf("Desea seguir 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
    }

    return 0;
}
