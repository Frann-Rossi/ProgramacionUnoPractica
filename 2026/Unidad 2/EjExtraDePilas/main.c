#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPila(Pila* a)
{
    char control = 's';
    while(control == 's')
    {
        leer(a);
        printf("Desea seguir 's/n':");
        scanf(" %c", &control);
    }
}

void pasarPilaAOtra(Pila* a, Pila* b)
{
    while(!pilavacia(a))
    {
        apilar(b,desapilar(a));
    }
}

void pasarTopeABase (Pila* a)
{
    Pila aux;
    inicpila(&aux);
    int numTope = desapilar(a);
    while(!pilavacia(a))
    {
        apilar(&aux,desapilar(a));
    }
    apilar(a,numTope);
    pasarPilaAOtra(&aux,a);
}

void repartirElementos(Pila* mazo, Pila* jug1, Pila* jug2)
{
    while(!pilavacia(mazo))
    {
        apilar(jug1,desapilar(mazo));
        apilar(jug2,desapilar(mazo));
    }
}

int menorCantidad (Pila a, Pila b)
{
    int flag;
    while(!pilavacia(&a) && !pilavacia(&b))
    {
        desapilar(&a);
        desapilar(&b);
    }

    if(pilavacia(&a) == pilavacia(&b))
    {
        flag = 0;
    }
    else if(pilavacia(&a))
    {
        flag = -1;
    }
    else
    {
        flag = 1;
    }
    return flag;
}

int sonIguales (Pila a, Pila b)
{
    int flag;
    Pila auxA;
    Pila auxB;
    inicpila(&auxA);
    inicpila(&auxB);
    int numA = desapilar(&a);
    int numB = desapilar(&b);


    while(numA == numB && !pilavacia(&a) && !pilavacia(&b))
    {
        numA = desapilar(&a);
        numB = desapilar(&b);
        apilar(&auxA,numA);
        apilar(&auxB,numB);

    }

    if(pilavacia(&a) && pilavacia(&b))
    {
        flag = 1;
    }
    else if(numA!=numB)
    {
        flag = 0;
    }

    return flag;
}

int main()
{
    char control = 's';
    int opcion;

    Pila a,b,c;
    inicpila(&a);
    inicpila(&b);
    inicpila(&c);

    int res;

    while(control == 's')
    {
        printf("Cargar PILA == 1\n");
        printf("Pasar Tope a Base == 2\n");
        printf("Repartir ELEMENTOS == 3\n");
        printf("Compara cantidad de elementos == 4\n");
        printf("Compara si son iguales ambas pilas == 5\n");
        printf("SALIR == 0\n");
        printf("Ingres una opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            cargarPila(&a);
            cargarPila(&b);
            mostrar(&a);
            mostrar(&b);
            break;
        case 2:
            pasarTopeABase(&a);
            mostrar(&a);
            break;
        case 3:
            repartirElementos(&a,&b,&c);
            printf("MAZO:\n");
            mostrar(&a);
            printf("Jugador 1:\n");
            mostrar(&b);
            printf("Jugador 2:\n");
            mostrar(&c);
            break;
        case 4:
            res = menorCantidad(a,b);
            printf("%d\n",res);
            break;
        case 5:
            res = sonIguales(a,b);
            printf("%d\n",res);
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
            printf("Desea seguir en el programa 's/n': ");
            scanf(" %c", &control);
        }
    }
    return 0;
}
