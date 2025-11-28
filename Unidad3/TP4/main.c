#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char control = 's';
    int opcion;
    while(control == 's')
    {
        printf("\n\n--- MENU TP N4: MATRICES ---\n");
        printf("1.  Cargar matriz (Usuario) \n");
        printf("2.  Mostrar matriz \n");
        printf("3.  Cargar matriz (Aleatoria) \n");
        printf("4.  Sumar contenido total \n");
        printf("5.  Promedio de matriz \n");
        printf("6.  Buscar elemento en matriz \n");
        printf("7.  Cargar arreglo de palabras \n");
        printf("8.  Mostrar arreglo de palabras \n");
        printf("9.  Buscar string en arreglo \n");
        printf("10. Buscar string (arreglo ordenado) \n");
        printf("11. Ordenar arreglo de palabras \n");
        printf("12. Determinante matriz 2x2 \n");
        printf("13. Verificar Inversa matriz 2x2 \n");
        printf("14. Verificar matriz Simetrica \n");
        printf("15. Generar Matriz Identidad \n");
        printf("16. Ejercicio Extra: Elecciones \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        printf("Desea Seguir en el PROGRAMA 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);

    }
    return 0;
}
