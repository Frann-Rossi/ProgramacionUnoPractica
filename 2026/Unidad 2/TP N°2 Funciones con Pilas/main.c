#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

void cargarPila(Pila* dirPila)
{
    char control = 's';
    while(control == 's')
    {
        leer(dirPila);
        printf("\nDesea seguir cargando valores 's/n':");
        scanf(" %c",&control);
    }

}

void pasarPilaAOtra(Pila* a, Pila* b)
{
    while(!pilavacia(a))
    {
        apilar(b,desapilar(a));
    }
}

void pasarPilaAOtraMantieneOrden (Pila* a, Pila* b)
{
    Pila aux;
    inicpila(&aux);

    pasarPilaAOtra(a,&aux);
    pasarPilaAOtra(&aux,b);
}

void invertirValores(Pila* a)
{
    Pila aux;
    Pila aux2;
    inicpila(&aux);
    inicpila(&aux2);

    pasarPilaAOtra(a,&aux);
    pasarPilaAOtra(&aux,&aux2);
    pasarPilaAOtra(&aux2,a);
}

int buscarElemento (Pila* a, int numBuscado)
{
    Pila aux;
    inicpila(&aux);
    int flag = 0;
    int num;
    while(!pilavacia(a))
    {
        num = tope(a);
        if(numBuscado == num)
        {
            flag = 1;
        }
        apilar(&aux, desapilar(a));
    }
    pasarPilaAOtra(&aux,a);
    return flag;
}

int solicitarNum (int num)
{
    printf("Ingrese un numero:");
    scanf("%d",&num);
    return num;
}

void eliminarElemento(Pila* a, int num)
{
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(a))
    {
        if(num == tope(a))
        {
            desapilar(a);
        }
        else
        {
            apilar(&aux,desapilar(a));
        }

    }
    pasarPilaAOtra(&aux,a);
}

int buscarMenor(Pila* a)
{
    Pila aux;
    inicpila(&aux);
    int menor = desapilar(a);
    while(!pilavacia(a))
    {
        if(tope(a) <  menor)
        {
            apilar(&aux,menor);
            menor = desapilar(a);
        }
        else
        {
            apilar(&aux,desapilar(a));
        }
    }
    pasarPilaAOtra(&aux,a);
    return menor;
}

int main()
{
    char control = 's';
    int opc;

    Pila a;
    Pila b;
    inicpila(&a);
    inicpila(&b);
    int numBuscado;
    int res;


    while(control == 's')
    {
        printf("Cargar Pila == 1\n");
        printf("Pasar valores a otra pila == 2\n");
        printf("Pasar valores a otra pila manteniendo orden == 3\n");
        printf("Invertir valores cargados de una Pila ya cargada == 4\n");
        printf("Buscar Numero en pila == 5\n");
        printf("Eliminar Numero en pila == 6\n");
        printf("Buscar el Numero Menor en pila == 7\n");
        printf("Salir == 0\n");
        scanf("%d",&opc);
        switch(opc)
        {
        case 1:
            cargarPila(&a);
            mostrar(&a);
            break;
        case 2:
            pasarPilaAOtra(&a,&b);
            printf("Pila A:\n");
            mostrar(&a);
            printf("Pila B:\n");
            mostrar(&b);
            break;
        case 3:
            pasarPilaAOtraMantieneOrden(&a,&b);
            printf("Pila A:\n");
            mostrar(&a);
            printf("Pila B:\n");
            mostrar(&b);
            break;
        case 4:
            invertirValores(&a);
            printf("Pila A invertida:\n");
            mostrar(&a);
            break;
        case 5:
            numBuscado = solicitarNum(numBuscado);
            res = buscarElemento(&a,numBuscado);
            if(res)
            {
                printf("El numero %d fue encontrado en la pila\n", numBuscado);
                mostrar(&a);
            }
            else
            {
                printf("El numero %d NO fue encontrado en la pila\n",numBuscado);
                mostrar(&a);
            }
            break;
        case 6:
            numBuscado = solicitarNum(numBuscado);
            eliminarElemento(&a,numBuscado);
            mostrar(&a);
            break;
        case 7:
            res = buscarMenor(&a);
            printf("El numero mas chico fue:%d\n",res);
            mostrar(&a);
            break;
        case 0:
            control = 'n';
            printf("Saliendo...\n");
            break;
        default:
            printf("Ingrese un valor correcto\n");
        }
        if(control == 's')
        {
            printf("\nDesea continuar en el programa 's/n':");
            scanf(" %c",&control);
        }
    }
    return 0;
}
