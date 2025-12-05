#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*               PRACTICO 5 - ARREGLOS PARALELOS

Sean los arreglos paralelos, que simbolizan la entidad de software “alumno”:
int legajos[20];
char nombres[20][30];
int anios[20];

1. Crear una función que los cargue, hasta que el usuario lo decida.
2. Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor.
3. Hacer una función que reciba como parámetro todos los arreglos y encuentre el nombre correspondiente a
   un determinado legajo y lo imprima por pantalla. Se debe invocar la función 2
4. Hacer una función que reciba como parámetro todos los arreglos y los ordene por nombre
   (por el método de selección o inserción).
5. Mostrar por pantalla los 3 arreglos pero de a un “registro” o alumno por vez
(es decir: muestra el legajo, nombre y años del 1er alumno,
 luego el legajo, nombre y años del 2do alumno, y así sucesivamente).
*/



//////////////////////////////////////////////////////////////////////////////////////////////
//prototipos:
int cargarArreglosParalelos (int legajos[], char nombres[][30], int anios[], int dimension);
int buscarPosicionLegajo (int legajos[], int val, int legBuscado);
void buscarAlumnoPorlegajo (int legajos[], char nombres[][30], int anios[], int val, int legBuscado);
int buscaPosMenorArrPar (char nombre[][30], int pos, int val);
void ordenarArreglosParalelos (int legajos[], char nombres[][30], int anios[], int validos);
void intercambioPalabras(char palabra[][30], int posM, int i);
void intercambioNumeros(int numeros[], int posM, int i);
void Insercion(int Legajos[], char Nombres[][30], int Anios[], int val, char nombreInsert[30], int LegInsert, int AnioInsert);
void OrdenamientoInsercion (int Legajos[], char Nombres[][30],int Anios[], int validos);
void mostrarArreglosParalelos (int Legajos[], char Nombres[][30], int Anios[], int val);



/////////////////////////////////////////////////////////////////////////////////////////////
// MAIN:

int main()
{
    int legajo[20];
    char nombre [20][30];
    int anios[20];

//ejerc 1: cargar los 3 arreGlos de forma paralela
    int validos= cargarArreglosParalelos (legajo,nombre, anios, 20);
    mostrarArreglosParalelos(legajo,nombre, anios, validos);
    system("pause");
    system("cls");

//ejerc 2:
    int leg;
    printf ("\nIngrese el legajo cuya posicion desea buscar: ");
    scanf("%d", &leg);
    int pos= buscarPosicionLegajo (legajo, validos, leg);// esta funcion devuelve -1 si no la encontró, o la
    if (pos==-1)                                        // posicion del legajo si lo encontró
    {
        printf("\nEl legajo ingresado no existe\n");
    }
    else
    {
        printf("\nEl legajo %d ocupa la posicion Nro %d\n", leg, pos);
    }
    system("pause");
    system("cls");

//ejerc 3;
    int leg3;
    printf ("\nIngrese el legajo cuyo nombre de alumno desea saber: ");
    scanf("%d", &leg3);
    buscarAlumnoPorlegajo (legajo, nombre, anios, validos, leg3);
    system("pause");
    system("cls");

//ejerc 4: ordenamientos
    printf("\nArreglos paralelos ordenados por nombre:\n");
    //ordenarArreglosParalelos(legajo,nombre, anios, validos);
    OrdenamientoInsercion(legajo, nombre, anios, validos);
    mostrarArreglosParalelos(legajo,nombre, anios, validos);
    system("pause");
    system("cls");

// ejerc 5: Mostrar por pantalla los 3 arreglos pero de a un “registro” por vez.
    mostrarArreglosParalelos(legajo,nombre, anios, validos);


return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/// FUNCIONES:


/// EJERC 1: Crear una función que los cargue, hasta que el usuario lo decida.

int cargarArreglosParalelos (int legajos[], char nombres[][30], int anios[], int dimension)
{
    int i=0;
    char control='s';

    while ((i<dimension) && (control=='s'))
    {
        printf("\nIngrese el nro de legajo del alumno  ");
        scanf("%d", &legajos[i]);
        printf("\nIngrese el nombre del alumno correspondiente al legajo anterior. Máximo 30 caracteres  ");
        fflush(stdin);
        gets(nombres[i]); //al ser strings, es como si fuera un arreglo de palabras, avanza sobre cada una de las filas
        printf("\nIngrese la edad del alumno  ");
        scanf("%d", &anios[i]);

        i++;

        printf("\nDesea continuar ingresando alumnos? Presione s/n  ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;//retorna los validos.La puedo hacer void si cargo los arreglos completos,aca la hago int porque es el usuario el q decide cuantos carga
}


/// 2: Crear una función que busque dentro del arreglo de legajos y retorne la posición de un determinado valor.

int buscarPosicionLegajo (int legajos[], int val, int legBuscado)
{
    int i=0;
    int pos= -1; //es como si fuera un flag, pero en vez de 0 le asigno -1 porque es la unica posicion no valida

    while (i<val && pos==-1)
    {
        if (legajos[i] == legBuscado)
        {
           pos= i;
        }
        i++;
    }
return pos;
}



/// EJERC 3: Hacer una función que reciba como parámetro todos los arreglos y encuentre el nombre
/// correspondiente a un determinado legajo y lo imprima por pantalla. Se debe invocar la función 2

void buscarAlumnoPorlegajo (int legajos[], char nombres[][30], int anios[], int val, int legBuscado)
{
    int pos= buscarPosicionLegajo(legajos, val, legBuscado);

    if (pos==-1)
    {
        printf("\nEl legajo ingresado no existe\n"); ///podria imprimir en el main p q la funcion sea mas reutilizable, pero no lo hago porq esta
                                                        // se pidio que la funcion imprima el nombre
    }
    else
    {
        printf("\nEl legajo %d, pertenece al alumno %s, que tiene %d anios\n", legajos[pos], nombres[pos], anios[pos]);
    }
}


/// EJERC 4: Hacer una función que reciba como parámetro todos los arreglos y los ordene por nombre

/// 4) A) ORDEN POR SELECCION:

int buscaPosMenorArrPar (char nombre[][30], int pos, int val) //FUNCION AUX QUE BUSCA LA POS MENOR
{
    char MiMenor[30]; //Este va a ser el 1º menor hipotetico con el cual voy a empezar a comparar, y 1º va a ser el que esta en la posicion 0
    strcpy(MiMenor,nombre[pos]);

    int posmenor = pos; //posicion menor, q 1º va a ser la 0 y luego se va a ir corriendo a medida q avance la "zona ordenada"
    int i = pos+1; //posicion q le sigue a la menor, q es la q se va a comparar con la menor ya ordenada

    while(i<val)
    {
        if((strcmp(MiMenor,nombre[i])) >0) // la funcion de comparar strings devuelve 0 si las cadenas son iguales o <0 o >0 si 1 es mayor q la otra
        {       //en este caso, dice q si el nombre en MiMenor es mayor q el nombre en i, i va a copiarse a MiMenor y va a ser el nuevo menor
            strcpy(MiMenor,nombre[i]); //nombre[i] pasa a ser el nuevo menor
            posmenor= i;            //e "i" pasa a ser la nueva posicion menor
        }
        i++;
    }
    return posmenor;
}


void ordenarArreglosParalelos (int legajos[], char nombres[][30], int anios[], int validos) //por seleccion
{
    int i=0; //posicion en la cual va a arrancar la funcion de buscar el menor
    int posmenor=0; //VARIABLE P LLAMAR A LA FUNCION de buscar la posicion menor

    while(i<validos)
    {
        posmenor = buscaPosMenorArrPar(nombres,i,validos); //busco la pos menor para en los 2 renglones seguidos intercambiar la matric y el nombre al
                                                    //1º lugar y a los subsiguientes q le correspondan
        intercambioPalabras(nombres, posmenor, i); //en la 1 vta i vale 0, y en esa pos voy a guardar lo q esté en la pos q la funcion de buscar menor
        intercambioNumeros(legajos, posmenor, i);  //encontró como menor.En la 2º vta i vale 1, y ahi voy a alojar el 2º menor: En la 3º vuelta
        intercambioNumeros(anios, posmenor, i); //i vale 2 y ahi se aloja el 3º menor. Y siguiendo...
                                                  //la funcion de intercambiar hace el pivoteo
        i++;
    }
}

void intercambioPalabras(char palabra[][30], int posM, int i)
{
    char aux[30];

    strcpy(aux,palabra[posM]);
    strcpy(palabra[posM], palabra[i]);
    strcpy(palabra[i],aux);
}

void intercambioNumeros(int numeros[], int posM, int i)
{
    int aux = numeros[posM];
    numeros[posM]=numeros[i];
    numeros[i]=aux;
}

/// 4) B) ORDEN POR INSERCION:

void Insercion(int Legajos[], char Nombres[][30], int Anios[], int val, char nombreInsert[30], int LegInsert, int AnioInsert)
{
    char aux[30]; // DEBO USAR UN AUX EN VEZ DE LA PALABRA A INSERTAR PORQ AL SER PUNTERO SE MODIFICA LA MATRIZ ORIGINAL
    strcpy(aux, nombreInsert);
    int i= val;

    while ( i>=0 && (strcmp (Nombres[i], aux)>0) )
    {
        Legajos[i+1]=Legajos[i];
        strcpy (Nombres [i+1], Nombres[i]);
        Anios[i+1]= Anios[i];
        i--;
    }
    Legajos[i+1]= LegInsert;
    strcpy (Nombres[i+1], aux);
    Anios[i+1]= AnioInsert;
}

void OrdenamientoInsercion (int Legajos[], char Nombres[][30],int Anios[], int validos)
{
    int i = 0;

    while (i < validos-1)
    {
        Insercion (Legajos,Nombres,Anios, i,Nombres[i+1],Legajos[i+1],Anios[i+1]);
        i++;
    }
}

/// ejerc 5: Mostrar por pantalla los 3 arreglos pero de a un “registro” por vez.

void mostrarArreglosParalelos (int Legajos[], char Nombres[][30], int Anios[], int val)
{
    int i=0;
    for (i=0; i<val; i++)
    {
       printf("\nLegajo:  %d, Alumno:  %s, Anios:  %i\n\n", Legajos[i], Nombres[i], Anios[i]);
    }
}

