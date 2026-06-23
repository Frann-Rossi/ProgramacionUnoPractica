#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("\nCargar EQUIPO de JUGADORES == 1");
    printf("\nMostrar EQUIPOS + JUGADORES ordenados de MENOR a MAYOR == 2");
    printf("\nSUMAR puntos a EQUIPO == 3");
    printf("\nSalir == 0");
    printf("\nIngrese una opcion:");
}

//Ejercicio 1
//=======================================================
stJugador cargarUnJugador()
{
    stJugador jugador;
    printf("\n===Cargando Jugador===");
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
    char control = 's';
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
    printf("\n=====JUGADOR=====");
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

stEquipo cargarUnEquipo()
{
    stEquipo equipo;
    printf("\n=====EQUIPO=====:");
    printf("\nIngrese NOMBRE del equipo:");
    scanf("%s",equipo.nombreEquipo);
    equipo.puntosGanados = -1;
    printf("\nIngrese DATOS del JUGADOR:");
    equipo.valEquipo = cargarJugadores(equipo.dato,25);
    return equipo;
}

int cargarEquipos(stEquipo arr[],int dim)
{
    char control = 's';
    int i = 0;

    do
    {
        arr[i] = cargarUnEquipo();
        i++;
        control = continuar("\nDesea seguir cargando EQUIPOS 's/n':");
    }
    while(control != 'n' && i < dim);
    return i;
}

void mostrarUnEquipo(stEquipo equipo)
{
    printf("\n=====EQUIPO=====");
    printf("\nNOMBRE del equipo:%s",equipo.nombreEquipo);
    printf("\nPUNTOS del equipo:%d",equipo.puntosGanados);
    printf("\nDATOS de los JUGADORES:");
    mostrarJugadores(equipo.dato,equipo.valEquipo);
}

void mostrarEquipos(stEquipo arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarUnEquipo(arr[i]);
    }
}
//=======================================================

// Ejericio 2
//=======================================================
int buscarPosMenor(stJugador arr[],int val, int pos)
{
    int posMenor = pos;
    int menor = arr[pos].puntosGanados;
    for(int i = pos+1; i < val; i++)
    {
        if(menor > arr[i].puntosGanados)
        {
            menor = arr[i].puntosGanados;
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenamientoPorSeleccion(stJugador arr[],int val)
{
    int posMenor;
    stJugador aux;
    for(int i = 0; i < val; i++)
    {
        posMenor = buscarPosMenor(arr,val,i);

        aux = arr[i];
        arr[i] = arr[posMenor];
        arr[posMenor] = aux;
    }
}

void ordenarJugDeEquipos (stEquipo arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        ordenamientoPorSeleccion(arr[i].dato,arr[i].valEquipo);
    }
}
//=======================================================

//Ejercicio 3
//=======================================================
int sumarPuntosRecu (stJugador arr[], int val,int i)
{
    int sum = 0;
    if(i < val)
    {
        sum = arr[i].puntosGanados + sumarPuntosRecu(arr,val,i+1);
    }
    return sum;
}
//=======================================================

//Ejercicio 4
//=======================================================
void modPuntosEquipoRecu(stEquipo arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        arr[i].puntosGanados = sumarPuntosRecu(arr[i].dato,arr[i].valEquipo,0);
    }
}
//=======================================================

//Ejercicio 5
//=======================================================
int buscarJugador (stEquipo equipo,int val,int i, char nombre[])
{
    int flag = -1;

    if(i < val)
    {
        if(strcmpi(arr.dato[i].nombre,nombre) == 0)
        {
            flag = arr.dato[i].id;
        }
        else
        {
            flag = buscarJugador(arr,val,i+1,nombre);
        }
    }

    return flag;
}
//=======================================================

//Ejercicio 6
//=======================================================
//Punto a
void pasarEquipoToArchi(char archivo[],stEquipo arr[],int val,char nombre[])
{
    FILE* buffer = fopen(archivo,"wb");
    if(buffer)
    {
        for(int i = 0; i < val; i++)
        {
            if(strcmpi(arr[i].nombreEquipo,nombre)== 0)
            {
                fwrite(&arr[i].dato,sizeof(stJugador),1,buffer);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

//Punto b
void arrDin(stJugador** arr, int cant)
{
    *arr = calloc(cant,sizeof(stJugador));
}

int cantDeElemArchi (char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stJugador);
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return cant;
}

int pasarJugadorToArr(char archivo[],stJugador** arr)
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = cantDeElemArchi(archivo);
    arrDin(arr,cant);
    int i = 0;
    stJugador jugador;
    if(buffer)
    {
        while(fread(&jugador,sizeof(stJugador),1,buffer)>0)
        {
            (*arr)[i] = jugador;
            i++;
        }
        fclose(buffer);
    }
    return i;
}
//=======================================================

int main()
{
    char control = 's';
    int opcion;

    stEquipo arrEquipos[30];
    int valEquipos = 0;

    int res = 0;
    int i = 0;
    char nombre[20];

    char archivo[] = "archi.bin";
    stJugador *arrJugador;
    int valJugadores = 0;

    while(control != 'n')
    {
        menu();
        switch(pedirNum("\nIngrese una opcion:"))
        {
        case 1:
            valEquipos = cargarEquipos(arrEquipos,10);
            mostrarEquipos(arrEquipos,valEquipos);
            break;
        case 2:
            ordenarJugDeEquipos(arrEquipos,valEquipos);
            mostrarEquipos(arrEquipos,valEquipos);
            break;
        case 3:
            modPuntosEquipoRecu(arrEquipos,valEquipos);
            break;
        case 4:
            printf("\nIngrese un nombre a buscar:");
            scanf("%s",nombre);
            res = buscarJugador(arrEquipos[0],arrEquipos[0].valEquipo,i,nombre);
            if(res != -1)
            {
                printf("\nEl jugador se encontro");
            }
            else
            {
                printf("\nEl jugador no existe");
            }
            break;
        case 5:
            printf("\nIngrese un nombre a buscar:");
            scanf("%s",nombre);
            pasarEquipoToArchi(archivo,arrEquipos,valEquipos,nombre);
            break;
        case 6:
            valJugadores = pasarJugadorToArr(archivo,&arrJugador);
            mostrarJugadores(arrJugador,valJugadores);
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
