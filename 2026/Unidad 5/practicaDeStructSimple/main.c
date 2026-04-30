#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 30

typedef struct
{
    int idEquipo;
    char nombreEquipo[30];
    int idJugador;
    int nroCamiseta;
    char nombreJugador[30];
    int puntosAnotados;
} stJugadorEquipo;


// EJERCIO 2
// **************************************************
stJugadorEquipo cargarJugador()
{
    stJugadorEquipo jugador;
    printf("Ingrese ID EQUIPO:");
    scanf("%d",&jugador.idEquipo);
    printf("Ingrese NOMBRE EQUIPO:");
    scanf("%s",&jugador.nombreEquipo);
    printf("Ingrese ID JUGADOR:");
    scanf("%d",&jugador.idJugador);
    printf("Ingrese NOMBRE JUGADOR:");
    scanf("%s",&jugador.nombreJugador);
    printf("Ingrese PUNTOS ANOTADOS:");
    scanf("%d",&jugador.puntosAnotados);
    return jugador;
}

void mostrarJugador(stJugadorEquipo jugador)
{
    printf("\n******************************\n");
    printf("ID EQUIPO:%d\n",jugador.idEquipo);
    printf("NOMBRE EQUIPO:%s\n",jugador.nombreEquipo);
    printf("ID JUGADOR:%d\n",jugador.idJugador);
    printf("NOMBRE JUGADOR:%s\n",jugador.nombreJugador);
    printf("PUNTOS ANOTADOS:%d\n",jugador.puntosAnotados);
    printf("******************************\n");
}
// **************************************************

// EJERCIO 3
// **************************************************
int cargarJugadores(stJugadorEquipo arr[], int dim)
{
    char control = 's';
    int i = 0;
    while(control == 's' && i < dim)
    {
        printf("CARGANDO JUGADOR\n");
        arr[i] = cargarJugador();
        i++;
        printf("\nDesea seguir cargando datos 's/n':");
        scanf(" %c",&control);
    }
    return i;
}

void mostrarJugadores(stJugadorEquipo arr[], int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarJugador(arr[i]);
    }
}
// **************************************************

// EJERCIO 4
// **************************************************
void mostrarJugadoresPorPuntos(stJugadorEquipo arr[],int val, int puntos)
{
    for(int i = 0; i < val; i ++)
    {
        if(arr[i].puntosAnotados > puntos)
        {
            mostrarJugador(arr[i]);
        }
    }
}
// **************************************************

int pedirPuntos()
{
    int num;
    printf("Ingrese un valor de puntos: se mostraran los jugadores con mas puntos que ese valor: ");
    scanf("%d",&num);
    return num;
}

// EJERCIO 5
// **************************************************
void modificarJugador(stJugadorEquipo arr[], int val, int idJugador)
{
    int flag = 0;
    for(int i = 0; i < val; i ++)
    {
        if(idJugador == arr[i].idJugador)
        {
            arr[i].puntosAnotados += 5;
            mostrarJugador(arr[i]);
            flag = 1;
        }
    }

    if(flag == 0)
    {
        printf("El jugador no existe\n");
    }
}
// **************************************************

int main()
{
    char control = 's';
    int opcion;

    stJugadorEquipo auxJugador;
    stJugadorEquipo auxJugador2 = {2, "Honda2", 22, 10, "PABLO", 12};

    stJugadorEquipo arrJugadores[DIM];
    int val = 0;

    int puntos;

    while(control == 's')
    {
        printf("Carga Manual de Jugador + Mostrar == 1\n");
        printf("Carga Por Teclado de Jugador + Mostrar == 2\n");
        printf("Carga de Varios Jugadores + Mostrar == 3\n");
        printf("Mostrar Jugador por Cantidad de Puntos == 4\n");
        printf("Salir del Programa == 0\n");
        printf("Ingrese una opcion:\n");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            auxJugador.idEquipo = 1;
            strcpy(auxJugador.nombreEquipo, "Honda");
            auxJugador.idJugador = 22;
            strcpy(auxJugador.nombreJugador, "Matias");
            auxJugador.puntosAnotados = 12;
            mostrarJugador(auxJugador);
            mostrarJugador(auxJugador2);

            break;
        case 2:
            auxJugador = cargarJugador();
            mostrarJugador(auxJugador);
            break;
        case 3:
            val = cargarJugadores(arrJugadores,DIM);
            mostrarJugadores(arrJugadores,val);
            break;
        case 4:
            puntos = pedirPuntos();
            mostrarJugadoresPorPuntos(arrJugadores,val,puntos);
            break;
        case 5:
            modificarJugador(arrJugadores,val,1);
            break;
        case 0:
            control = 'n';
            printf("Saliendo.....\n");
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        if(control == 's')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }

    return 0;
}
