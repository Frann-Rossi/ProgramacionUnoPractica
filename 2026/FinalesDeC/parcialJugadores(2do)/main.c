#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idEquipo;
    char nombreEquipo[30];
    int idJugador;
    int nroCamiseta;
    char nombreJugador[30];
    int puntosAnotados;
} stJugadorEquipo;

char seguir (char msj[])
{
    char control;
    printf("%s",msj);
    scanf(" %c",&control);
    return control;
}

int pedirNum (char msj[])
{
    int num;
    printf("%s", msj);
    scanf("%d",&num);
    return num;
}

void mensaje()
{
    printf("\nEj 1 == 1");
    printf("\nSalir == 0");
}

stJugadorEquipo cargarUnJugador()
{
    stJugadorEquipo jugador;
    printf("\n=====CARGAR JUGADOR=====:");
    printf("\nIngrese ID EQUIPO:");
    scanf("%d",&jugador.idEquipo);
    printf("\nIngrese NOMBRE del EQUIPO:");
    scanf("%s",jugador.nombreEquipo);
    printf("\nIngrese ID JUGADOR:");
    scanf("%d",&jugador.idJugador);
    printf("\nIngrese NRO de la CAMISETA:");
    scanf("%d",&jugador.nroCamiseta);
    printf("\nIngrese NOMBRE del JUGADOR:");
    scanf("%s",jugador.nombreJugador);
    printf("\nIngrese PUNTOS ANOTADOS:");
    scanf("%d",&jugador.puntosAnotados);
    return jugador;
}

void mostrarUnJugador(stJugadorEquipo jugador)
{
    printf("\nID EQUIPO:%d",jugador.idEquipo);
    printf("\nNOMBRE del EQUIPO:%s",jugador.nombreEquipo);
    printf("\nID JUGADOR:%d",jugador.idJugador);
    printf("\nNRO de la CAMISETA:%d",&jugador.nroCamiseta);
    printf("\nNOMBRE del JUGADOR:%s",jugador.nombreJugador);
    printf("\nPUNTOS ANOTADOS:%d",jugador.puntosAnotados);
}

// Ejercicio 1
//==================================================
void arrDin(stJugadorEquipo** arr, int cant)
{
    *arr = calloc(cant,sizeof(stJugadorEquipo));
}

int cantElementos (char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;

    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stJugadorEquipo);
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

int pasarArchiToArr (char archivo[], stJugadorEquipo** arr)
{
    FILE* buffer = fopen(archivo,"rb");
    stJugadorEquipo jugador;
    int cant = cantElementos(archivo);
    arrDin(arr,cant);
    int i = 0;

    if(buffer)
    {
        while(fread(&jugador,sizeof(stJugadorEquipo),1,buffer)>0)
        {
            (*arr)[i] = jugador;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return i;
}
//==================================================

//Ejercicio 2
//==================================================
void mostrarJugadoresEquipo(stJugadorEquipo arr[],int val, int i, char equipoBuscado[])
{
    if(i < val)
    {
        if(strcmpi(arr[i].nombreEquipo,equipoBuscado) == 0)
        {
            mostrarUnJugador(arr[i]);
        }
        mostrarJugadoresEquipo(arr,val,i+1,equipoBuscado);
    }
}
//==================================================

//Ejercio 3
//==================================================
int sumarPuntosRecu(stJugadorEquipo arr[], int val, int i, char equipoBuscado[])
{
    int suma = 0;
    if(i < val)
    {
        if(strcmpi(arr[i].nombreEquipo, equipoBuscado)== 0)
        {
            suma = arr[i].puntosAnotados;
        }
        suma += sumarPuntosRecu(arr,val,i+1,equipoBuscado);
    }
    return suma;
}
//==================================================

//Ejercicio 4
//==================================================
void sobreEscribirArchivo(char archivo[],int nroRegistro )
{
    FILE* buffer = fopen(archivo,"r+b");
    stJugadorEquipo jugador;

    if(buffer)
    {
        fseek(buffer,nroRegistro * sizeof(stJugadorEquipo),SEEK_SET);
        jugador = cargarUnJugador();
        fwrite(&jugador,sizeof(stJugadorEquipo),1,buffer);
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//Ejerccio 5
//==================================================
void modPuntosDeEquipo(char archivo[],char nombreEquipo[],char nombreJugador[])
{
    FILE* buffer = fopen(archivo,"r+b");
    stJugadorEquipo jugador;

    if(buffer)
    {
        while(fread(&jugador,sizeof(stJugadorEquipo),1,buffer)>0)
        {
            if(strcmpi(jugador.nombreEquipo,nombreEquipo)== 0 &&
                    strcmpi(jugador.nombreJugador,nombreJugador)== 0)
            {
                printf("\nModificar Puntos");
                scanf("%d",&jugador.puntosAnotados);
                fseek(buffer,-sizeof(stJugadorEquipo),SEEK_CUR);
                fwrite(&jugador,sizeof(stJugadorEquipo),1,buffer);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//Ejercicio 6
//==================================================
int existe (char archivo[],char nombreEquipo[])
{
    FILE* buffer = fopen(archivo,"rb");
    stJugadorEquipo jugador;
    int flag = 0;

    if(buffer)
    {
        while(fread(&jugador,sizeof(stJugadorEquipo),1,buffer)>0)
        {
            if(strcmpi(jugador.nombreEquipo, nombreEquipo)== 0)
            {
                flag = 1;
            }
        }
        fclose(buffer);
    }
    return flag;
}

void nuevoArchiNombres(char archivo[],char archiNombres[])
{
    FILE* buffer = fopen(archivo,"rb");
    FILE* buffer2 = fopen(archiNombres,"wb");
    stJugadorEquipo jugador;
    int flag;

    if(buffer && buffer2)
    {
        while(fread(&jugador,sizeof(stJugadorEquipo),1,buffer)>0)
        {
            flag = existe(archiNombres,jugador.nombreEquipo);
            if(flag != 1)
            {
                fwrite(&jugador,sizeof(stJugadorEquipo),1,buffer2);
            }
        }
        fclose(buffer);
        fclose(buffer2);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//Ejercicio 7
//==================================================
int jugadorExisteRecu(stJugadorEquipo arr[],int val, int i, char nombreJugador[])
{
    int rta = 0;
    if(i < val)
    {
        if(strcmpi(arr[i].nombreJugador,nombreJugador)== 0)
        {
            rta = 1;
        }
        else
        {
            rta = jugadorExisteRecu(arr,val,i+1,nombreJugador);
        }
    }
    return rta;
}
//==================================================

int main()
{
    char control = 's';
    int opcion;

    while(control == 's')
    {
        mensaje();
        opcion = pedirNum("\nIngrese una opcion:");

        switch(opcion)
        {
        case 1:
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....");
            break;
        default:
            printf("\nIngrese un valor valido");
        }

        if(control == 's')
        {
            control = seguir("\nDesea seguir en el programa 's/n':");
        }
    }
    return 0;
}
