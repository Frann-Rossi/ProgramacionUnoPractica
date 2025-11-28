#include "ventas.h"

void productosComprados(int *cantidad, float *precio)
{
    printf("Cantidad de productos\n");
    scanf("%d",cantidad);
    printf("Valor de producto\n");
    scanf("%f",precio);
}

float devolverMontoTotal(int cantidad, float precio)
{
    return (float)cantidad * precio;
}
