#include "mis_funciones.h"

// Funcion: Paso por Valor (Copia)
Pila ingresarValores(Pila origen)
{
    char control = 's';
    while(control == 's')
    {
        // Usamos & porque la funcion 'leer' pide puntero,
        // asi que le damos la direccion de nuestra copia local.
        leer(&origen);

        printf("Desea seguir cargando? 's'/'n': ");
        fflush(stdin);
        scanf(" %c", &control);
    }

    return origen; // <--- ¡No te olvides el punto y coma!
}
