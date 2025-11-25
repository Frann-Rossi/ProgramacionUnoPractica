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

int sumarPila2Primero (Pila *origen)
{
    int num = desapilar (origen);
    int suma = num + tope(origen);
    apilar(origen,num);
    return suma;
}

int sumarPila(Pila *origen)
{
    int suma = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(origen))
    {
        suma += tope(origen);
        apilar(&aux,desapilar(origen));
    }
    while(!pilavacia(&aux))
    {
        apilar(origen,desapilar(&aux));
    }

    return suma;
}

int contarElemPila(Pila *origen)
{
    int cont = 0;
    Pila aux;
    inicpila(&aux);
    while(!pilavacia(origen))
    {
        cont++;
        apilar(&aux,desapilar(origen));
    }

    while(!pilavacia(&aux))
    {
        apilar(origen,desapilar(&aux));
    }

    return cont;
}

float dividir(int dividendo, int divisor)
{
    return (float) dividendo / divisor;
}

float promedioPila (Pila *origen)
{
    int sum = sumarPila(origen);
    int cant = contarElemPila(origen);
    float promedio = dividir(sum,cant);
    return promedio;
}

int transformarPilaEnDecimal (Pila *origen)
{
    int num = 0;
    int digito;

    Pila aux;
    inicpila(&aux);
    pasarAPila(origen,&aux);

    while(!pilavacia(&aux))
    {
        digito = desapilar(&aux);

        num = (num * 10) + digito;
    }
    return num;
}

void cargarPila (Pila *origen)
{
    char control = 's';
    int num;
    while(control == 's')
    {
        printf("Ingrese un numero para la PILA\n");
        scanf("%d",&num);
        apilar(origen,num);
        printf("Seguir? s/n: ");
        fflush(stdin);
        scanf("%c", &control);
    }
}

void mostrarPila(Pila *origen)
{
    int num;
    Pila aux;
    inicpila(&aux);
    pasarAPila(origen,&aux);
    while(!pilavacia(&aux))
    {
        num = desapilar(&aux);
        printf("|%d|",num);
        apilar(origen,num);
    }
    printf("\n");
}

int main()
{
    char control = 's';
    int opcion;

    int num;
    int menor;
    int resultado;
    int sumPila;
    int contPila;
    float resPromedio;
    int resPilaEnDecimal;

    Pila origen;
    Pila destino;
    inicpila(&origen);
    inicpila(&destino);

    while(control == 's')
    {
        printf("\n======================================================\n");
        printf("      TRABAJO PRACTICO N2 - FUNCIONES CON PILAS       \n");
        printf("======================================================\n");
        printf(" 1. Cargar Pila (Ingresar elementos a voluntad)\n");
        printf(" 2. Pasar de Pila A a Pila B (Invierte orden)\n");
        printf(" 3. Pasar de Pila A a Pila B (Conservando orden)\n");
        printf(" 4. Menor Elemento: Buscar, retornar y borrar\n");
        printf(" 5. Ordenamiento por SELECCION (Usa Ej. 4)\n");
        printf(" 6. Insertar elemento en Pila Ordenada (Mantiene orden)\n");
        printf(" 7. Ordenamiento por INSERCION (Usa Ej. 6)\n");
        printf(" 8. Suma tope y anterior (Sin alterar pila)\n");
        printf(" 9. Calcular Promedio (Suma / Cantidad)\n");
        printf("10. Transformar Pila de digitos a Decimal\n");
        printf("11. Extra: Carga manual (Sin usar leer)\n");
        printf("12. Extra: Mostrar manual (Sin usar mostrar)\n");
        printf(" 0. Salir\n");
        printf("======================================================\n");
        printf("Ingrese opcion: ");
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
        case 8:
            resultado = sumarPila2Primero(&origen);
            printf("La suma fue de:%d",resultado);
            mostrar(&origen);
            break;
        case 9:
            sumPila = sumarPila(&origen);
            printf("Suma:%d\n",sumPila);
            contPila = contarElemPila(&origen);
            printf("Contador:%d\n",contPila);
            resPromedio = promedioPila(&origen);
            printf("El promedio fue de:%.2f\n",resPromedio);
            break;
        case 10:
            resPilaEnDecimal = transformarPilaEnDecimal(&origen);
            printf("%d\n",resPilaEnDecimal);
            break;
        case 11:
            cargarPila(&origen);
            mostrar(&origen);
        case 12:
            cargarPila(&origen);
            mostrarPila(&origen);

        default:
            printf("Ingrese un valor valido\n");
        }
        printf("Seguir? s/n: ");
        fflush(stdin);
        scanf(" %c", &control);
    }
    return 0;
}
