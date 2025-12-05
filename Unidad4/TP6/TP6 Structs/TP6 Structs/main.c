#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*                  PRACTICO 6 - STRUCTS

Sea la estructura:
typedef struct {
    int legajo;
    char nombre[30];
    char genero; //m, f, o
} stAlumno;

1) Hacer una función que cargue un arreglo de struct alumno, hasta que el usuario lo decida.
2) Hacer una función que muestre un arreglo de alumnos por pantalla. Modularizar.
3) Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.
4) Hacer una función que ordene el arreglo de alumnos por medio del método de selección.
   El criterio de ordenación es el número de matrícula.
5) Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado
  (se envía por parámetro). Modularizar.
6) Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
7) Hacer una función que ordene el arreglo de alumnos por medio del método de inserción.
   El criterio de ordenación es el nombre.
8) Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado.
  (se envía por parámetro) que tiene un arreglo de alumnos.
9) Hacer una función principal que pruebe el funcionamiento de todos los incisos anteriores,
   con un menú de opciones para poder ejecutar todas las funciones requeridas.
   Tengan presente la correcta declaración y el ámbito de variables.
*/
/////////////////////////////////////////////////////////////////////////////////////////////////////////


// DEFINE STRUCT:
typedef struct
{
    int legajo;
    char nombre[30]; // un arreglo char, una palabra
    char genero;     // una variable char, una sola letra: m, f, o
} alumno;

//////////////////////////////////////////////////////////////////////////////////////////////
//prototipos:
alumno cargarUnAlumno ();
int cargarArregloAlumnos(alumno A[], int dimension);
int cargarArregloAlumnosBis (alumno A[], int dimension, int validos);
void mostrarUnAlumno (alumno A);
void mostrarArregloStructs (alumno A[], int validos);
int BuscarNombrePorlegajoArrStruct(alumno A[], int validos, int dato);
int buscaPosMenorArrStruct (alumno A[], int pos, int validos);
void ordenamSeleccionArrStructs (alumno A[], int validos);
void mostrarPorGenero (alumno A[], int validos, char genero);
int insertaNuevoPorOrdenlegajo(alumno A[], int validos, alumno Nuevo);
void insertaNuevoPorOrdenNombre(alumno A[], int validos, alumno Nuevo);
void ordenacionInsercion (alumno A[], int validos);
int contarPorGenero(alumno A[], int validos, char genero);
void mostrarArregloEnteros(int A[], int validos);


/////////////////////////////////////////////////////////////////////////////////////////////
// MAIN:

int main()
{
// ejerc 1 y 2: cargar y mostrar arreglo de structs:
    printf("\n\n\n\n\nArreglo de estructuras alumno\n\n");
    alumno ListaAlumnos [20]; //un arreglo de tipo alumno (la struct alumno) llamado ListaAlumnos q adentro tiene structs con cada alumno
    int validosArrStructs = cargarArregloAlumnos (ListaAlumnos, 20);
    /// o si quiero agregar a un arreglo ya cargado:
    /// validosArrStructs= cargarArregloAlumnosBis(ListaAlumnos, 20, validosArrStructs);

    mostrarArregloStructs (ListaAlumnos, validosArrStructs);
    system("pause");
    system("cls");

//ejerc 3:
    int mat;
    printf ("\nIngrese el legajo del alumno que desea buscar: ");
    scanf("%d", &mat);
    int pos= BuscarNombrePorlegajoArrStruct(ListaAlumnos, validosArrStructs, mat);

    if (pos==-1)
    {
        printf("\nEl legajo ingresado no existe\n");
    }
    else
    {
        mostrarUnAlumno(ListaAlumnos[pos]);
    }
    system("pause");
    system("cls");

//EJERC 4:
    ordenamSeleccionArrStructs(ListaAlumnos, validosArrStructs);
    printf("Arreglo de Structs Lista de Alumnos, ordenado por Nro. de legajo");
    mostrarArregloStructs (ListaAlumnos, validosArrStructs);
    system("pause");
    system("cls");

//EJERC 5: Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado
// que se envía por parámetro. Modularizar.
    char genero;
    printf("\nSi desea ver las alumnas mujeres presione f, si desea ver los varones presione m \n");
    fflush(stdin);
    scanf("%c", &genero);
    mostrarPorGenero (ListaAlumnos, validosArrStructs, genero);
    system("pause");
    system("cls");

// 6) Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.6) Hacer una función que inserte en un arreglo ordenado por matrícula un nuevo dato, conservando el orden.
    alumno Nuevo= cargarUnAlumno();
    validosArrStructs= insertaNuevoPorOrdenlegajo(ListaAlumnos, validosArrStructs, Nuevo);
    system("pause");
    system("cls");

// 7) Hacer una función que ordene el arreglo de alumnos por medio del método de inserción.
//  El criterio de ordenación es el nombre.
    ordenacionInsercion (ListaAlumnos, validosArrStructs);
    mostrarArregloStructs (ListaAlumnos, validosArrStructs);
    system("pause");
    system("cls");

// 8) Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado.
// (se envía por parámetro) que tiene un arreglo de alumnos.
    char genero8;
    printf("\nSi desea ver la cantidad de alumnas mujeres presione f, si desea ver cantidad de varones presione m \n");
    fflush(stdin);
    scanf("%c", &genero8);
    int cantGenero= contarPorGenero (ListaAlumnos, validosArrStructs, genero8);
    printf("La cantidad de %c en la lista es %d", genero8, cantGenero);


return 0;
}

/// FUNCIONES ////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////


/// 1) Cargar un arreglo de alumnos.

/// Modularizo: una funcion aux que carga un solo alumno
// Importante modularizar porque esta funcion luego nos sirve para cargar un alumno solo, un alumno en un arreglo, o un alumno en otros lugares

alumno cargarUnAlumno ()
{
        alumno A;

        printf("\nIngrese el nro de legajo del alumno  ");
        scanf("%d", &A.legajo);

        printf("\nIngrese el nombre del alumno. Máximo 30 caracteres  ");
        fflush(stdin);
        gets(A.nombre); // si uso scanf no toma nombre y apellido

        printf("\nIngrese el genero del alumno (m/f)  ");
        fflush(stdin);
        scanf("%c", &A.genero);
        /* y si quiero hacer una validacion agrego:
        while( (A[i].genero != 'm') && (A[i].genero != 'f') && (A[i].genero != 'o' ) )
            {
                printf("\ngenero erroneo, ingrese nuevamente: ");
                fflush(stdin);
                scanf("%c", &A[i].genero);
            } */

    return A;
}


/// funcion ppal que carga todo el arreglo:

int cargarArregloAlumnos(alumno A[], int dimension)
{
    int i=0;
    char control='s';

    while ((i<dimension) && (control == 's'))
    {
        A[i] = cargarUnAlumno();
        i++;

        printf("\nDesea continuar ingresando datos? presione s/n ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}


/// otra variante: funcion que puede agregar alumnos a un arreglo YA CARGADO o cargar arreglo desde 0:

int cargarArregloAlumnosBis (alumno A[], int dimension, int validos)
{
    int i= validos; //ARRANCA A CARGAR DESDE LA 1ra POSICION VACIA
    char control= 's';

    while ( (control=='s') && (i<dimension) )
    {
        A[i]= cargarUnAlumno();
        i++;

        printf("\nQuiere seguir cargando datos? presione s/n\n ");
        fflush(stdin);
        scanf("%c", &control);
    }
    return i;
}


/// ejerc 2: mostrar arreglo de alumnos

/// Importante modularizar
/// funcion aux que muestra un solo alumno:

void mostrarUnAlumno (alumno A) //y p mostrar varios con un ciclo for o while y ver el tema de A[i] como en cargar
{
    printf("\nLegajo:  %d. \t", A.legajo);
    printf("Nombre del alumno:  %s. \t", A.nombre);

    char M[]={"masculino"}; //un arreglo char p la palabra masculino y otro p la palabra femenino, q al llamarlos con un string imprime toda la palabra
    char F[]={"femenino"};
    char O[]={"otro"};
    if(A.genero=='m')
    {
        printf("Genero: %s\n----------------------------------------------\n", M);
    }
    else if (A.genero=='f')
    {
        printf("Genero: %s\n----------------------------------------------\n", F);
    }
    else
    {
        printf("Genero: %s\n----------------------------------------------\n", O);
    }
}

/// funcion ppal que muestra todo el arreglo:

void mostrarArregloStructs (alumno A[], int validos)
{
    int i=0;

    printf("\n******************Listado de alumnos************************\n");
    printf("______________________________________________________________\n");
    for (i=0; i<validos; i++)
    {
        mostrarUnAlumno(A[i]);
    }
    printf("______________________________________________________________\n");
}


/// 3) Hacer una función que muestre por pantalla los datos de un alumno, conociendo su matrícula. Modularizar.

int BuscarNombrePorlegajoArrStruct(alumno A[], int validos, int legajo)
{
    int i=0;
    int pos= -1; //no se inicializa en 0 porque 0 es una posicion valida

    while (i<validos && pos == -1)
    {
        if (A[i].legajo == legajo){
           pos= i;
        }
        else{
            i++;
        }
    }
    return pos; //no lo muestro en la funcion, lo retorno y lo muestro en el main
}


/// 4. Hacer 1 función que ordene el arreglo de struct alumno por el método de selección.
/// El criterio de ordenación es el N° de matrícula.

int buscaPosMenorArrStruct (alumno A[], int pos, int validos) //// funcion auxiliar que busca la posicion de la menor legajo
{
    int MiMenor= A[pos].legajo;
    int posmenor= pos;  //posicion menor, q 1º va a ser la 0 y luego se va a ir corriendo a medida q avance la "zona ordenada"
    int i= pos+1;      //posicion q le sigue a la menor, q es la q se va a comparar con la menor ya ordenada

    while(i<validos)
    {
        if(MiMenor > A[i].legajo)
        {
            MiMenor= A[i].legajo;  //A[i].legajo pasa a ser el nuevo menor, y
            posmenor= i;            //"i" pasa a ser la nueva posicion menor
        }
        i++;
    }
    return posmenor;
}

void ordenamSeleccionArrStructs (alumno A[], int validos) //como el arreglo es puntero, ya queda ordenado en el main
{
    int i= 0;   //posicion en la cual va a arrancar la funcion de buscar el menor
    int pmenor; //VARIABLE P LLAMAR A LA FUNCION de buscar la posicion menor
    alumno aux; //variable para el pivoteo, de tipo alumno (struct) para poder alojar toda la struct de cada posicion del array

    while(i<validos)
    {
        //busco el menor
        pmenor = buscaPosMenorArrStruct(A,i,validos); //busco la posicion del menor legajo
        //intercambios
        aux = A[pmenor];    //con la funcion anterior compara las posiciones en relacion al legajo, pero luego los pivoteos ya se hacen con la struct completa
        A[pmenor]=A[i];
        A[i]=aux;
        //avanzo
        i++;
    }
}

/// 5) Hacer una función que muestre por pantalla los datos de los estudiantes de un género determinado
///  (se envía por parámetro). Modularizar.

void mostrarPorGenero (alumno A[], int validos, char genero)
{
    int i;

    printf("\nLista de alumnos del genero buscado\n------------------------------------------------------\n");
    for (i=0; i<validos;i++)
    {
        if (A[i].genero == genero)
        {
            mostrarUnAlumno(A[i]); // importante modularizar
        }
    }
}

/// 6) Hacer 1 función q inserte en un arreglo ordenado por legajo 1 nuevo dato, conservando el orden.

int insertaNuevoPorOrdenlegajo(alumno A[], int validos, alumno Nuevo)
{
    int i = validos-1; //arranca en el final del arreglo y va hacia atras hasta la posicion 0; validos -1 es la ultima posicion valida

    while(i>=0 && A[i].legajo > Nuevo.legajo)
    {
        A[i+1]= A[i]; //lo q hay en A[i] se copia en A[i+1] y queda como valor en las 2 posiciones, y a medida q i va decreciendo, el valor de
                    //A[i+1] se va pisando con el valor de A[i] q se va copiando al que le sigue
        i--;
    }
    A[i+1]= Nuevo; //cuando se encuentra un (A[i] q ya no es mayor q la legajo del nuevo, el nuevo se aloja en A[i+1]

    return validos+1; //retorna 1 mas q los validos q habia al iniciar porq agregó uno más al arreglo
}


/// EJERC 7 : ORDENAR POR INSERCION POR EL NOMBRE

void insertaNuevoPorOrdenNombre(alumno A[], int pos, alumno Nuevo)
{
    int i= pos; //validos es la ultima posicion valida de la zona ordenDA

    while(i>=0 && (strcmpi(A[i].nombre, Nuevo.nombre) >0))
    {
        A[i+1]=A[i]; //lo q hay en A[i] se copia en A[i+1* y queda como valor en las 2 posiciones, y a medida q i va decreciendo, el valor de
                    //A[i+1] se va pisando con el valor de A[i] q se va copiando al que le sigue
        i--;
    }
    A[i+1]=Nuevo; //cuando se encuentra un (A[i] q ya no es mayor q la legajo del nuevo, el nuevo se aloja en A[i+1]
}

void ordenacionInsercion (alumno A[], int validos)
{
    int i = 0;
    while (i<validos-1)
    {
        insertaNuevoPorOrdenNombre(A, i, A[i+1]);
        i++;
    }
}

/// 8) Hacer una función que cuente y retorne la cantidad de estudiantes de un género determinado.
/// (se envía por parámetro) que tiene un arreglo de alumnos

int contarPorGenero(alumno A[], int validos, char genero)
{
    int i=0;
    int contados=0;

    for (i=0; i<validos; i++)
    {
        if(A[i].genero == genero)
        {
            contados++;
        }
    }
    return contados;
}

