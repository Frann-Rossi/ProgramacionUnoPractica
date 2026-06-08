#include <stdio.h>
#include <stdlib.h>

#include "menu.h"
#include "atleta.h"

void mostrarMenu()
{
    printf("\n========================================");
    printf("\n      PARCIAL ATLETAS");
    printf("\n========================================");
    printf("\n1. Pasar archivo a arreglo por categoria");
    printf("\n2. Contar atletas mayores de edad y con mas de 20 puntos (Recursivo)");
    printf("\n3. Buscar atleta por ID (Recursivo)");
    printf("\n4. Guardar atletas en archivos de mayores y menores");
    printf("\n5. Aumentar 5 puntos segun tiempo de carrera");
    printf("\n6. Crear arreglo dinamico con tiempos menores a 20 segundos");
    printf("\n7. Calcular promedio de tiempos");
    printf("\n8. Mostrar archivo original");
    printf("\n9. Mostrar arreglo");
    printf("\n0. Salir");
    printf("\n========================================");
    printf("\nIngrese una opcion: ");
}

void menu()
{
    char control = 's';
    int opcion;

    char archivoAtleta[] = "atleta.bin";

    while(control == 's')
    {
        mostrarMenu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarArchivoDeAtleta(archivoAtleta);
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....");
            break;
        default:
            printf("\nIngrese un valor valido...");
        }
        if(control == 's')
        {
            control = continuar("\nDesea seguir en el programa 's/n':");

        }
    }
}
