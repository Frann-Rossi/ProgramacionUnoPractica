#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void ingresarValoresPila (Pila *origen)
{
    char control = 's';
    while(control == 's')
    {
        leer(origen);
        printf("Desea seguir 's/n'");
        fflush(stdin);
        scanf("%c",&control);
    }
}

void pasarAPila (Pila *origen, Pila *destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino, desapilar(origen));
    }
}

void pasarAPilaMantenerOrden(Pila *origen, Pila *destino)
{
    pasarAPila(origen,destino);
    while(!pilavacia(destino))
    {
        apilar(origen, desapilar(destino));
    }
}

int buscarMenor (Pila *origen)
{
    Pila aux;
    inicpila (&aux);
    int menor = desapilar(origen);
    while(!pilavacia(origen))
    {
        if(menor > tope(origen))
        {
            apilar(&aux,menor);
            menor = desapilar(origen);
        }
        else
        {
            apilar(&aux, desapilar(origen));
        }
    }
    while(!pilavacia(&aux))
    {
        apilar(origen, desapilar(&aux));
    }
    return menor;
}

void ordenamientoPorSeleccion(Pila *origen, Pila *destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino,buscarMenor(origen));
    }
}

void insertarElemento(Pila *origen,int num)
{
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen) && tope(origen) < num)
    {
        apilar(&aux, desapilar(origen));
    }
    apilar(origen,num);

    while(!pilavacia(&aux))
    {
        apilar(origen,desapilar(&aux));
    }
}

void ordenamientoPorInsercion (Pila *origen, Pila *destino)
{
    int num;
    while(!pilavacia(origen))
    {
        num = desapilar(origen);
        insertarElemento(destino,num);
    }
}

void sumarPilar (Pila *origen){
    int num;
    Pila aux;
    inicpila(&aux);

    while(!pilavacia(origen)){
        num = desapilar(origen) + tope(origen);
        apilar()
    }
}

int main()
{
    char control = 's';
    int opcion;
    int menor;
    int num;

    Pila origen;
    Pila destino;
    inicpila(&origen);
    inicpila(&destino);

    while(control == 's')
    {
        printf("Ej 1\n");
        printf("Ej 2\n");
        printf("Ej 3\n");
        printf("Ej 4\n");
        printf("Ej 5\n");
        printf("Ej 6\n");
        printf("Ej 7\n");
        printf("Ej 8\n");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            ingresarValoresPila(&origen);
            mostrar(&origen);
            break;
        case 2:
            pasarAPila(&origen,&destino);
            printf("Origen\n");
            mostrar(&origen);
            printf("Destino\n");
            mostrar(&destino);
            break;
        case 3:
            pasarAPilaMantenerOrden(&origen,&destino);
            printf("Origen\n");
            mostrar(&origen);
            printf("Destino\n");
            mostrar(&destino);
        case 4:
            menor = buscarMenor(&origen);
            printf("Origen\n");
            mostrar(&origen);
            printf("El numero menor de la pila fue %d\n",menor);
            break;
        case 5:
            ordenamientoPorSeleccion(&origen,&destino);
            mostrar(&destino);
            break;
        case 6:
            printf("ingrese un numero para la pila\n");
            scanf("%d",&num);
            insertarElemento(&origen,num);
            mostrar(&origen);
            break;
        case 7:
            ordenamientoPorInsercion(&origen, &destino);
            mostrar(&destino);
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        printf("Seguir? s/n: ");
        fflush(stdin);
        scanf(" %c", &control);
    }
    return 0;
}
