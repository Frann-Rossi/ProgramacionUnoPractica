#include <stdio.h>
#include <stdlib.h>

#define MAX_ALUMNOS 20
#define DIM_NOMBRE 30



int main()
{
    int legajos[MAX_ALUMNOS];
    char nombres[MAX_ALUMNOS][DIM_NOMBRE];
    int anios[MAX_ALUMNOS];

    char control = 's';
    int opcion;

    int val = 0;

    while(control == 's')
    {
        printf("Ej == 1\n");
        printf("SALIR == 0\n");
        printf("Ingrese una opcion:");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            break;
        case 2:

            break;
        case 0:
            control = 'n';
            printf("SALIENDO.....\n");
            break;
        default:
            printf("Ingrese un valor correcto\n");
        }
        if(control == 's')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }

}
