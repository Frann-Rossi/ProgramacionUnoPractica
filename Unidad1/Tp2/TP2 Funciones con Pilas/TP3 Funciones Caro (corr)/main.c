#include <stdio.h>
#include <stdlib.h>
#include "pila.h"
#include <math.h>

/*
PRACTICO 2 - FUNCIONES

(Este practico hace con funciones todos los ejerc de los TP1 y TP2 de pilas.
SOLO SON NUEVOS EL EJERC 8 Y EL 10)

NOTA: todas las funciones pedidas deben recibir por parámetro la/s pila/s cargadas con los datos.
No se debe usar la función leer() dentro de la función, excepto en la función 1.
1. Hacer una función que permita ingresar varios elementos a una Pila, tantos como quiera el
usuario.
2. Hacer una función que pase todos los elementos de una pila a otra.
3. Hacer una función que pase todos los elementos de una pila a otra, pero conservando el
orden.
4. Hacer una función que encuentre el menor elemento de una pila y lo retorna.
La misma debe eliminar ese dato de la pila
/// 5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 4.
6. Hacer una función que inserte en una pila ordenada un nuevo elemento, conservando el
orden de esta.
//// 7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
nueva pila ordenada. Usar la función del ejercicio 6.
8. Hacer una función que sume y retorne los dos primeros elementos de una pila (tope y
anterior), sin alterar su contenido.
9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer
también una función que calcule la suma, otra para la cuenta y otra que divida. En total son
cuatro funciones, y la función que calcula el promedio invoca a las otras 3.
10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad
de quien usa el programa) y que transforme esos dígitos en un número decimal. Por ejemplo,
la pila: debe retornar el número: 14675

Ejercicios extra: Con el fin de generar una experiencia de usuario diferente a la que otorga
la librería, se requiere desarrollar las siguientes funciones:

* Realizar una función que cargue la pila sin utilizar la función leer.
* Realizar una función que muestre la pila sin utilizar la función mostrar*/


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FUNCIONES:


/// 1. Hacer una función que permita ingresar varios elementos a una Pila,
/// tantos como quiera el usuario.


Pila cargarPilaConRetorno (Pila A)
{
    char control = 's';
    while (control == 's' || control == 'S')
    {
        leer (&A);
        printf("desea continuar ingresar Nros. a la pila? presione s o S si desea hacerlo, si no, presione cualquier otra letra ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return A;
}


void cargarPilaPuntero (Pila* A)
{
    char control='s';

    while(control=='s')
    {
       leer(A);
       printf("\n Quiere seguir cargando? presione s si quiere seguir\n");
       fflush(stdin);
       scanf("%c", &control);
    }
}



/// 2) Hacer una función que pase todos los elementos de una pila a otra.

Pila pasarDeUnaPilaAotra(Pila origen)///origen queda igual en el main... si quiero
                /// que quede vacía en el main, uso puntero, como se hizo ne la funcion de mas abajo
{
    Pila Destino;
    inicpila(&Destino);

    while (!pilavacia(&origen))
    {
        apilar(&Destino, desapilar(&origen));
    }
   return Destino;
}


Pila pasarDeUnaPilaAotraRecibeLasDos(Pila origen, Pila destino)
{
    while (!pilavacia (&origen))
    {
        apilar(&destino, desapilar(&origen));
    }

    return destino;
}


void pasarDeUnaPilaAotraPuntero(Pila* origen, Pila* destino)
{
    while (!pilavacia (origen))
    {
        apilar(destino, desapilar(origen));
    }
}



/// 3)Hacer una función que pase todos los elementos de una pila a otra, pero conservando el orden.

Pila pasarAotraEnMismoOrden(Pila Origen) ///podria pasar tambien por parametro la pila destino, y
{                                       /// no tendria que declararla e inicializarla dentro de la
    Pila Destino; inicpila(&Destino);      /// funcion, solo la retornaria (ver funcion de mas abajo)
    Pila Aux; inicpila(&Aux);

    while (!pilavacia(&Origen))
    {
        apilar(&Aux, desapilar(&Origen));
    }
    while (!pilavacia(&Aux))
    {
        apilar(&Destino, desapilar(&Aux));
    }

    return Destino;
}


Pila pasarDeUnaPilaAotraEnOrdenRecibeLasDos(Pila origen, Pila destino)
{
    Pila aux; inicpila(&aux);

    while (!pilavacia (&origen))
    {
        apilar(&aux, desapilar(&origen));
    }
    while (!pilavacia (&aux))
    {
        apilar(&destino, desapilar(&aux));
    }
    /// o... version mas pro:
    ///aux = pasarDeUnaPilaAotra(origen, aux);
    ///destino= pasarDeUnaPilaAotra(aux, destino);

    return destino;
}


/// 4) Hacer una función que encuentre el menor elemento de una pila y lo retorna.
/// La misma debe eliminar ese dato de la pila
///METODO SELECCION


int encontrarMenorSeleccion(Pila * A)
{
    Pila Menor; inicpila(&Menor);
    Pila Descarte; inicpila(&Descarte);

    if (!pilavacia(A)) // importante para que no se rompa el codigo
        apilar(&Menor, desapilar(A)); //menor va con & porque no es puntero y A sin & porque es puntero
    while (!pilavacia(A))
    {
        if (tope(A) < tope(&Menor))
        {
          apilar(&Descarte, desapilar(&Menor));
          apilar(&Menor, desapilar(A));
        }
        else // si el tope de A es mayor que el tope de Menor
        {
          apilar(&Descarte, desapilar(A));
        }
    }
    while (!pilavacia(&Descarte)) // como A es puntero,para q A vuelva llena tengo que volver los elementos a A, no importa
    {                              // que haya cambiado el orden
        apilar(A, desapilar(&Descarte));
    }
    return tope(&Menor);
}


/// 5. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
/// nueva pila ordenada. Usar la función del ejercicio 4.
/// ORDENAMIENTO POR SELECCION


Pila ordenarPorSeleccion(Pila Desordenada) // como trabajo sin punteros la pila desordenada queda igual
{               // puedo tambien pasar por parametro la pila ordenada, y no tendria que declararla e iniciarla dentro de la funcion
    Pila Ordenada; inicpila(&Ordenada);
    int Menor;

    while (!pilavacia(&Desordenada)){
        Menor = encontrarMenorSeleccion(&Desordenada);//desordenada va quedando con el menor extraido y vuelvo a buscar el menor
        apilar(&Ordenada, Menor);
    }

    return Ordenada;
}


/// o puedo trabajar con punteros y no tengo que retornar la pila ordenada, y la desordenada queda vacia:
void ordenarPorSeleccionPuntero (Pila *origen, Pila *destino)
{
    while (!pilavacia(origen))
    {
         apilar(destino, encontrarMenorSeleccion(origen));///origen no lleva * porq ya es puntero
    }
}


/// 6. Hacer una función que inserte en una pila ordenada un nuevo elemento,
/// conservando el Orden de esta. // METODO INSERCION

Pila insertarEnOrden(Pila Ordenada, int NumInsertar)
{
    Pila Aux; inicpila(&Aux);

    while ((!pilavacia(&Ordenada)) && (tope(&Ordenada)<NumInsertar))
    {
      apilar(&Aux, desapilar(&Ordenada));//apilo en Aux todos los que son menores al Nro a insertar (la pila esta ordenada con el > abajo y <arriba)
    }

    apilar(&Ordenada, NumInsertar);

    while (!pilavacia(&Aux))
    {
        apilar(&Ordenada, desapilar(&Aux));// vuelvo a A los menores al Nro a Insertar
    }

    return Ordenada;
}


/// Tbien puedo trabajar con punteros..
/// y el dato a insertar tambien puede ser una pila en vez de un entero:

void insertarEnOrdenConPuntero (Pila* ordenada, Pila* DatoAInsertar)
{
    Pila aux; inicpila(&aux);

    while ((!pilavacia(ordenada)) && (tope(ordenada)<tope(DatoAInsertar)))
    {
        apilar(&aux, desapilar(ordenada));
    }

    apilar(ordenada, desapilar(DatoAInsertar));

    while (!pilavacia(&aux))
    {
        apilar(ordenada, desapilar(&aux));
    }
}


/// 7. Hacer una función que pase los elementos de una pila a otra,
/// de manera que se genere una nueva pila ordenada. Usar la función del ejercicio 6.
/// ORDENAMIENTO POR INSERCION

Pila ordenarPorInsercion(Pila desordenada) //A es la desordenada. la ordenada podria tambien entrar por parametro y no tengo q declararla dentro
{
    Pila Ordenada; inicpila(&Ordenada);

    while(!pilavacia(&desordenada))
    {
        Ordenada = insertarEnOrden(Ordenada, desapilar(&desordenada));
    }

    return Ordenada;
}


/// tambien puedo trabajar con punteros para no tener que devolver la ordenada
/// y que la desordenada quede vacia:
void ordenarPorInsercion2 (Pila *ordenada, Pila *desordenada)
{
    while (!pilavacia(desordenada))
    {
        insertarEnOrdenConPuntero(ordenada, desordenada); // en esta funcion lo que se pasa como 2do parametro es una pila
    }
}


/// EJERC 8) Hacer una función que sume y retorne los dos primeros elementos de una pila
/// (tope y anterior), sin alterar su contenido

int sumaTopeyAnterior (Pila dada)
{
    Pila aux; inicpila(&aux);
    int suma=0;
    int contador=0;

    while ((!pilavacia(&dada)) && (contador<2))
    {
        suma= suma + tope(&dada);
        apilar(&aux, (desapilar(&dada)));
        contador ++;
    }
     return suma;
}


/// 9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer
/// también una función que calcule la suma, otra para la cuenta y otra que divida. En total
/// SON 4 funciones, y la función que calcula el promedio invoca a las otras 3.

int sumarPila(Pila A)
{
    int rta=0;
    Pila Aux; inicpila(&Aux);

    while (!pilavacia(&A))
    {
        rta = rta + tope(&A);
        apilar(&Aux, desapilar(&A));
    }
    return rta;
}


int contarPila(Pila A)
{
    int cantidad=0;
    Pila Aux; inicpila(&Aux);

    while (!pilavacia(&A))
    {
        apilar(&Aux, desapilar(&A));
        cantidad++;
    }
    return cantidad;
}



float dividir (int suma, int cantidad)
{
    float result = (float)suma / (float) cantidad;  //hacer conversion tipos
return result;
}


float calcularPromedio(Pila A)
{
    int suma = sumarPila(A);
    int cantidad = contarPila(A);
    float promedio = dividir(suma, cantidad);
    return promedio;
}


/// EJERC 10) Hacer una función que reciba una pila con números de un solo dígito (es
/// responsabilidad de quien usa el programa) y que transforme esos dígitos en un N° decimal.
/* Por ejemplo, la pila:
        1
        4
        6
        7
        5     Debe retornar el número: 14675                                  */


int transformaPilaEnNro(Pila dada)
{
    Pila aux;
    inicpila(&aux);
    int numero=0;

    while (!pilavacia(&dada))
    {
        numero= (numero * 10) + tope(&dada);
        apilar (&aux, desapilar(&dada));
    }
    return numero;
}


double transformaPilaEnNroConPow(Pila dada)
{
    Pila aux; inicpila(&aux);
    int i=0;
    double numero=0;

    while (!pilavacia(&dada))
    {
        numero= numero + (tope(&dada) * pow(10, i));
        apilar (&aux, desapilar(&dada));
        i++;
    }
    return numero;
}


/// OTRA FORMA:

int transformaPilaEnNroBis (Pila dada)
{
    Pila aux, aux2;
    inicpila(&aux);
    inicpila(&aux2);

    int decimal = 0;
    int multiplicador = 1;

    while (!pilavacia(&dada)) ///si no quedan los nros en orden inverso - si quiere los numeros inversos descomentar este codigo
    {
        apilar(&aux, desapilar(&dada));
    }

    while (!pilavacia(&aux))
    {
        decimal = decimal + (tope(&aux)* multiplicador);
        apilar(&aux2, desapilar(&aux));
        multiplicador = multiplicador * 10;
    }

    return decimal;
}


/*Ejercicios extra, con el fin de generar una experiencia de usuario diferente a la que otorga la librería
se requiere desarrollar las siguientes funciones:
* Realizar una función que cargue la pila sin utilizar la función leer.
* Realizar una función que muestre la pila sin utilizar la función mostrar*/


void LeerporTeclado(Pila* p)
{
    int valor;
    char continuar='s';
    while (continuar=='s')
    {
        printf("Ingrese un numero\n ");
        scanf("%d",&valor);
        apilar(p,valor);

        printf("desea continuatuar s/n\n");
        fflush(stdin);
        scanf("%c",&continuar);
    }
}



void MostrarPila(Pila p)
{
    Pila aux;
    inicpila(&aux);
    printf("\nBase----------------------Tope\n");
    while(!pilavacia(&p))
        apilar(&aux,desapilar(&p));
    while(!pilavacia(&aux))
        printf(" %d ",desapilar(&aux));

    printf("\nBase----------------------Tope\n");
}



/*****************************************************************************************************************************/
/// MAIN:



int main()
{

/// 1)  Hacer una función que permita ingresar varios elementos a una Pila,
/// tantos como quiera el usuario.
    Pila P1;
    inicpila(&P1);
    P1 = cargarPilaConRetorno(P1);
    printf("Pila P1:\n"); mostrar(&P1);

/// 2. Hacer una función que pase todos los elementos de una pila a otra.
    Pila P2;
    inicpila(&P2);
    P2 = pasarDeUnaPilaAotra(P1);
    printf("Pila P2:\n"); mostrar(&P2);

///3. Hacer una función que pase todos los elementos de una pila a otra,
/// pero conservando el orden.
    Pila P3;
    inicpila(&P3);
    P3 = pasarAotraEnMismoOrden(P1);
    printf("Pila P3:\n"); mostrar(&P3);

/// 4. Hacer una función que encuentre el menor elemento de una pila y lo retorna.
/// La misma debe eliminar ese dato de la pila.
/// SELECCION:
    int menor = encontrarMenorSeleccion(&P1);   //& porque trabaja con puntero la funcion
    printf("Menor encontrado en la pila P1: %d \n", menor);
    printf("\nPila P1 con el menor extraido"); mostrar(&P1);

/// 5. Hacer una función que pase los elementos de una pila a otra, de manera
/// que se genere una nueva pila ordenada. Usar la función del ejercicio 4.
/// ORDENAMIENTO POR SELECCION:
    Pila Ordenada;
    inicpila(&Ordenada);
    Ordenada = ordenarPorSeleccion(P1);
    printf("Pila Ordenda por seleccion\n"); mostrar(&Ordenada);

/// 6. Insertar un elemento en una pila ordenada de menor (tope) a mayor (base)
/// de forma tal que se conserve el orden // METODO INSERCION
    Pila POrdenada;
    inicpila(&POrdenada);
    POrdenada = cargarPilaConRetorno(POrdenada);
    printf("\nPila POrdenada\n");mostrar(&POrdenada);
    int numInsertar = 4;

    POrdenada = insertarEnOrden(POrdenada, numInsertar);
    printf("\nPila POrdenada luego de la insercion del 4\n");
    mostrar(&POrdenada);

/// 7. Hacer una función que pase los elementos de una pila a otra, de manera que se genere una
/// nueva pila ordenada. Usar la función del ejercicio 6. // ORDENAMIENTO POR INSERCION
    Pila P7;
    inicpila(&P7);
    P7 = cargarPilaConRetorno(P7);
    Pila POrdenada7;
    inicpila(&POrdenada7);
    POrdenada7 = ordenarPorInsercion(P7);
    printf("\nPila POrdenada7 luego del ordenamiento por insercion\n");
    mostrar(&POrdenada7);

/// 8. Hacer una función que sume y retorne los dos primeros elementos de una pila
/// (tope y anterior), sin alterar su contenido.
    Pila P8;
    inicpila(&P8);
    P8 = cargarPilaConRetorno(P8);
    int resultado8 = sumaTopeyAnterior (P8);
    printf("\n La suma del tope y el anterior es: %d. Y la pila P8 es:\n", resultado8);
    mostrar(&P8);

/// 9. Hacer una función que calcule el promedio de los elementos de una pila, para ello hacer
/// también una función que calcule la suma, otra para la cuenta y otra que divida.
/// En total son 4 funciones, y la función que calcula el promedio invoca a las otras 3.
    float promedio;
    promedio = calcularPromedio(P8);
    printf("\nEl promedio de la pila P8 es %f\n", promedio);

/// 10. Hacer una función que reciba una pila con números de un solo dígito (es responsabilidad
/// de quien usa el programa) y que transforme esos dígitos en un número decimal.

    Pila P10;
    inicpila(&P10);
    printf("\nCUIDADO!! Solo puede ingresar Nros de un solo digito\n");
    P10 = cargarPilaConRetorno (P10);

    int result = transformaPilaEnNro (P10);
    printf("\nLos digitos de la pila corresponden al Nro decimal: %d, y la pila original era: \n", result);
    mostrar(&P10);

    /// o usando pow...
    double decimal= transformaPilaEnNroConPow(P10);
    printf("La pila transforma en numero decimal es: %.2f\n", decimal);


    return 0;
}



