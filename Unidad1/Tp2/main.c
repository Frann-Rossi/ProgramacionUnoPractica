#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

Pila ingresarValoresPila (Pila origen){
    char control = 's';
    while(control == 's'){
        leer(&origen);
        printf("Desea seguir 's/n'");
        fflush(stdin);
        scanf("%c",&control);
    }
}

int main()
{
    char control = 's';
    int opcion;

    Pila origen;
    inicpila(&origen);

    while(control == 's'){
        printf("\n1. Cargar Pila\nOption: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                ingresarValoresPila(origen);
                mostrar(&origen);
                break;
        }
        printf("Seguir? s/n: ");
        fflush(stdin);
        scanf(" %c", &control);
    }
    return 0;
}
