#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int id;
    char nombre [20];
    char posicion [20];
    int curso;
    int puntosGanados;
} stJugador;

typedef struct
{
    char nombreEquipo[20];
    int puntosGanados;
    stJugador dato[25];
    int valEquipo;
} stEquipo;

char continuar(char msj[])
{
    char opcion;
    printf("%s",msj);
    scanf(" %c",&opcion);
    return opcion;
}

int pedirNum (char msj[])
{
    int num;
    printf("%s",msj);
    scanf("%d",&num);
    return num;
}

void menu()
{
    printf("\nEj 1 == 1");
    printf("\nSalir == 0");
}

//Ejercicio 1
//=======================================================
stJugador cargarUnJugador()
{
    stJugador jugador;
    printf("\n===Cargando Jugador===\n");
    printf("\nIngrese ID:");
    scanf("%d",&jugador.id);
    printf("\nIngrese NOMBRE:");
    scanf("%s",jugador.nombre);
    printf("\nIngrese POSICION:");
    scanf("%s",jugador.posicion);
    printf("\nIngrese CURSO:");
    scanf("%d",&jugador.curso);
    printf("\nIngrese PUNTOS GANADOS:");
    scanf("%d",&jugador.puntosGanados);
    return jugador;
}

int cargarJugadores(stJugador arr[],int dim)
{
    char control;
    int i = 0;
    do
    {
        arr[i] = cargarUnJugador();
        i++;
        control = continuar("\nDesea seguir cargando JUGADORES 's/n':");
    }
    while(control != 'n' && i < dim);
    return i;
}

void mostrarUnJugador(stJugador jugador)
{
    printf("\n==========");
    printf("\nID:%d",jugador.id);
    printf("\nNOMBRE:%s",jugador.nombre);
    printf("\nPOSICION:%s",jugador.posicion);
    printf("\nCURSO:%d",jugador.curso);
    printf("\nPUNTOS GANADOS:%d",jugador.puntosGanados);
    printf("\n==========");
}

void mostrarJugadores(stJugador arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarUnJugador(arr[i]);
    }
}
//=======================================================

int main()
{
    char control;
    int opcion;

    stJugador arr[30];
    int val = 0;

    while(control != 'n')
    {
        menu();
        switch(pedirNum("\nIngrese una opcion:"))
        {
        case 1:
            val = cargarJugadores(arr,10);
            mostrarJugadores(arr,val);
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo...\n");
            break;
        default:
            printf("\nIngrese una opcion valida\n");
        }
        if(control != 'n')
        {
            control = continuar("\nDesea seguir en el programa 's/n':");
        }
    }
    return 0;
}
