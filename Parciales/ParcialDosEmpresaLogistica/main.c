#include <stdio.h>
#include <stdlib.h>

#define PESO_MINIMO = 10000.0

typedef struct
{
    int idBuque;
    char nombre[50];
    char paisOrigen[30];
    int capacidadMaxContenedores;
    int tieneContenedores;
} Buque;

typedef struct
{
    int idContenedor;
    int idBuque; // Clave foránea al Buque
    char tipoCarga[40];
    float pesoKg;
    char destino[50];
} Contenedor;

//Ej 1
int pesosSuperior (int peso){
    Contenedor aux;
    if(aux.pesoKg == peso){
        return peso;
    }
}

Contenedor* cargarContenedoresPesados(char nombreArchivoContenedores[], int* dimension) {

    FILE *buffer = fopen(nombreArchivoContenedores,"wb");
}


int main()
{
    char control = 's';
    int opcion;

    int *arrDim;
    while(control == 's')
    {
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            break;
        case 0:
            control = 'n';
            printf("Saliendo...");
            break;
        default:
            printf("Ingrese un valor valido\n");
            break;
        }
        if(control == 's')
        {
            printf("Desea seguir en el PROGRAMA 's/n':");
            fflush(stdin);
            scanf("%c",&control);
        }
    }
    return 0;
}
