#include <stdio.h>
#include <stdlib.h>

int montoTotal (int cant, int precio)
{
    return cant * precio;
}

float descuento (int cant, int total)
{
    float desc = 0;

    if (cant >= 20 && total > 100000)
    {
        desc = total * 0.20;
    }
    else if(cant > 10 && total > 50000)
    {
        desc = total * 0.15;
    }

    return desc;
}

float montoFinal(int total, float descuento)
{
    return total - descuento;
}

void mostrarInfo (int cant, int precio,int total, float desc, float pagar)
{
    printf("Cantidad de productos ---------- %d un.\n",cant);
    printf("Precio por producto ------------ $%d\n",precio);
    printf("Total parcial ------------------ $%d\n",total);
    printf("Descuento aplicado ------------- $%d\n",desc);
    printf("Monto a pagar ------------------ $%d\n",pagar);
}

int main()
{
    int opc;
    char control = 's';
    int cant;
    int precio;
    int totalVenta = 0;
    float descuentoCompra = 0;
    float pagar;

    while(control == 's')
    {
        printf("\n1- Calcular total\n");
        printf("2- Calcular descuento\n");
        printf("3- Calcular monto final\n");
        printf("4- Mostrar compra final\n");
        printf("0- Salir del Programa\n");
        scanf("%i",&opc);

        switch(opc)
        {
        case 1:
            printf("\nIngrese la cantidad de productos: ");
            scanf("%i",&cant);
            printf("\nIngrese el valor del producto: ");
            scanf("%i",&precio);
            totalVenta = montoTotal(cant,precio);
            printf("\nEl valor final fue de:%i\n",totalVenta);
            break;
        case 2:
            totalVenta = montoTotal(cant,precio);
            descuentoCompra = descuento(cant,totalVenta);
            printf("El descuento fue de: %.2f\n",descuentoCompra);
            break;
        case 3:
            pagar = montoFinal(totalVenta, descuentoCompra);
            printf("Monto final a pagar: %.2f\n", pagar);
            break;
        case 4:
            mostrarInfo(cant,precio,totalVenta,descuentoCompra,pagar);
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
