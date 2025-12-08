#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

#define MAX_NOMBRE 30
#define MAX_ALUMNOS 30

typedef struct
{
    int legajo;
    char nombreYapellido [MAX_NOMBRE];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;


void agregarNumArchivo(char nombreArchivo[])
{
    int num;
    char control = 's';
    FILE *buffer = fopen(nombreArchivo,"ab");

    if(buffer)
    {
        while(control == 's')
        {
            printf("Ingrese un numero: ");
            scanf("%d", &num);
            fwrite(&num,sizeof(int),1,buffer);
            printf("Desea seguir 's/n':");
            fflush(stdin);
            scanf("%c",&control);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

void leerNumArchivo(char nombreArchivo[])
{
    int num;
    FILE *buffer = fopen(nombreArchivo,"rb");
    if(buffer)
    {
        while(fread(&num,sizeof(int),1,buffer)>0)
        {
            printf("Numero:%d\n",num);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

int contarRegistrosArchivo(char nombreArchivo[])
{
    int cant = 0;
    FILE *buffer = fopen(nombreArchivo,"rb");
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(int);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
    return cant;
}

stAlumno cargarAlum ()
{
    stAlumno alum;
    printf("Ingrese LEGAJO:");
    scanf("%d",&alum.legajo);
    printf("\nIngrese NOMBRE y APELLIDO:");
    fflush(stdin);
    gets(alum.nombreYapellido);
    printf("\nIngrese EDAD:");
    scanf("%d",&alum.edad);
    printf("\nIngrese ANIO:");
    scanf("%d",&alum.anio);
    return alum;
}

void cargarAlumArchivo(char nombreArchivo[])
{
    stAlumno alum;
    char control = 's';
    FILE *buffer = fopen(nombreArchivo,"wb");

    if(buffer)
    {
        while(control == 's')
        {
            alum = cargarAlum();
            fwrite(&alum,sizeof(stAlumno),1,buffer);
            printf("Desea seguir 's/n':");
            fflush(stdin);
            scanf("%c",&control);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}



void mostrarAlum(stAlumno alum)
{
    printf("++++++++++\n");
    printf("Legajo: %d\n", alum.legajo);
    printf("Nombre y Apellido: %s\n", alum.nombreYapellido);
    printf("Edad: %d\n", alum.edad);
    printf("Anio: %d\n", alum.anio);
    printf("++++++++++\n");
}

void mostrarAlumArchivo(char nombreArchivo[])
{
    stAlumno alum;
    FILE *buffer = fopen(nombreArchivo,"rb");
    if(buffer)
    {

        while(fread(&alum,sizeof(stAlumno),1,buffer)>0)
        {
            mostrarAlum(alum);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

void agregarAlumArchivo (char nombreArchivo[])
{
    stAlumno alum;
    FILE *buffer = fopen(nombreArchivo,"ab");

    if(buffer)
    {
        alum = cargarAlum();
        fwrite(&alum,sizeof(stAlumno),1,buffer);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

void pasarLegajosAPila (char nombreArchivo[], Pila *origen)
{
    stAlumno alum;
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        while(fread(&alum,sizeof(stAlumno),1,buffer) > 0)
        {
            if(alum.edad >= 18)
            {
                apilar(origen,alum.legajo);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

int contarMayoresEdad(char nombreArchivo[], int edadLimite)
{
    stAlumno alum;
    int cont = 0;
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        while(fread(&alum,sizeof(stAlumno),1,buffer) > 0)
        {
            if(alum.edad > edadLimite)
            {
                cont++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }

    return cont;

}

void rangoDeEdad (stAlumno alum, int min, int max)
{
    if(alum.edad > min && alum.edad <= max)
    {
        mostrarAlum(alum);
    }
}

void mostrarNombresPorEdad (char nombreArchivo[],int min, int max)
{
    stAlumno alum;
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        while(fread(&alum,sizeof(stAlumno),1,buffer)>0)
        {
            rangoDeEdad(alum,min,max);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

stAlumno buscarAlumnoMayor(char nombreArchivo[])
{
    stAlumno alum;
    stAlumno alumMayor;
    alumMayor.edad = -1;
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        while(fread(&alum,sizeof(stAlumno),1,buffer) > 0)
        {
            if(alumMayor.edad == -1 || alum.edad > alumMayor.edad)
            {
                alumMayor = alum;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
    return alumMayor;

}

void mostrarMayorDelArchivo(char nombreArchivo[])
{
    stAlumno alum;
    alum = buscarAlumnoMayor(nombreArchivo);
    if(alum.edad != -1)
    {
        printf("\n--- ALUMNO CON MAYOR EDAD ---\n");
        mostrarAlum(alum);
    }
    else
    {
        printf("No se pudo determinar el alum (archivo vacio o error).\n");
    }
}

int cantDeAlumDeUnAnio(char nombreArchivo[],int anioBuscado)
{
    stAlumno alum;
    int cant = 0;
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        while(fread(&alum, sizeof(stAlumno), 1, buffer) > 0)
        {
            if(alum.anio == anioBuscado)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
    return cant;
}

int cargarAlumnos(stAlumno arrAlum[], int dim)
{
    int i = 0 ;
    char control = 's';

    while(control == 's' && i < dim)
    {
        arrAlum[i] = cargarAlum();
        i++;
        printf("Desea seguir cargando ALUMNOS en el arr 's/n':");
        fflush(stdin);
        scanf("%c",&control);
    }
    return i;
}
void mostrarAlumnosArr(stAlumno arrAlum[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarAlum(arrAlum[i]);
    }
}

void pasarArrAlumAArchivo (char nombreArchivo[], stAlumno arrAlum[], int val)
{
    FILE *buffer = fopen(nombreArchivo,"wb");

    if(buffer)
    {
        for(int i = 0; i < val; i++)
        {
            fwrite(&arrAlum[i],sizeof(stAlumno),1,buffer);
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

int pasarArchivoAlumAArr (char nombreArchivo [], stAlumno arrAlum[],int anio)
{
    stAlumno alum;
    int i = 0;
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        while(fread(&alum,sizeof(stAlumno),1,buffer)>0)
        {
            if(alum.anio == anio)
            {
                arrAlum[i] = alum;
                i++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
    return i;
}

int cantDeRegistro (char nombreArchivo[])
{
    stAlumno alum;
    int cant = 0;
    FILE *buffer = fopen(nombreArchivo,"rb");

    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stAlumno);
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
    return cant;
}

void mostrarAlumnoPorPosicion(char nombreArchivo[], int pos)
{
    int cant = cantDeRegistro(nombreArchivo);
    if(pos >= 0 && pos < cant)
    {
        stAlumno alum;
        FILE *buffer = fopen(nombreArchivo,"rb");
        if(buffer)
        {
            fseek(buffer,pos * sizeof(stAlumno),SEEK_SET);
            fread(&alum,sizeof(stAlumno),1,buffer);
            printf("\n--- ALUMNO EN POSICION %d ---\n", pos);
            mostrarAlum(alum);
            fclose(buffer);
        }
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

void modificarRegistro(char nombreArchivo[], int pos)
{
    int cant =  cantDeRegistro(nombreArchivo);
    if(pos >= 0 && pos < cant)
    {
        stAlumno alum;
        FILE *buffer = fopen(nombreArchivo,"r+b");
        if(buffer)
        {
            fseek(buffer,pos * sizeof(stAlumno),SEEK_SET);
            fread(&alum,sizeof(stAlumno),1,buffer);
            printf("\n--- DATOS ACTUALES ---\n");
            mostrarAlum(alum);
            printf("\n--- INGRESE LOS NUEVOS DATOS ---\n");
            printf("Nuevo Nombre: ");
            fflush(stdin);
            gets(alum.nombreYapellido);
            printf("Nueva Edad: ");
            scanf("%d", &alum.edad);
            printf("Nuevo Anio: ");
            scanf("%d", &alum.anio);
            fseek(buffer, -1 * (long)sizeof(stAlumno), SEEK_CUR);
            fwrite(&alum, sizeof(stAlumno), 1, buffer);
            printf("\nRegistro modificado exitosamente.\n");
            fclose(buffer);
        }
    }
}

void invertirArchivo(char nombreArchivo[])
{
    stAlumno alumInicio;
    stAlumno alumFinal;
    int posInicio = 0;
    int posFinal = cantDeRegistro(nombreArchivo) - 1; // El ultimo es cantidad - 1

    // Abrimos en lectura y escritura
    FILE *buffer = fopen(nombreArchivo, "r+b");

    if (buffer)
    {
        // El bucle va mientras el inicio no se cruce con el final
        while (posInicio < posFinal)
        {
            // 1. Buscamos y leemos el del INICIO
            fseek(buffer, posInicio * sizeof(stAlumno), SEEK_SET);
            fread(&alumInicio, sizeof(stAlumno), 1, buffer);

            // 2. Buscamos y leemos el del FINAL
            fseek(buffer, posFinal * sizeof(stAlumno), SEEK_SET);
            fread(&alumFinal, sizeof(stAlumno), 1, buffer);

            // 3. Escribimos el del INICIO en la posicion del FINAL
            // (Ojo: fseek es necesario porque acabamos de leer)
            fseek(buffer, posFinal * sizeof(stAlumno), SEEK_SET);
            fwrite(&alumInicio, sizeof(stAlumno), 1, buffer);

            // 4. Escribimos el del FINAL en la posicion del INICIO
            fseek(buffer, posInicio * sizeof(stAlumno), SEEK_SET);
            fwrite(&alumFinal, sizeof(stAlumno), 1, buffer);

            // 5. Movemos los punteros hacia el centro
            posInicio++;
            posFinal--;
        }

        fclose(buffer);
        printf("\nArchivo invertido correctamente!\n");
    }
    else
    {
        printf("Error al abrir el archivo.\n");
    }
}

int main()
{
    char control = 's';
    int opcion;
    char archivoNum[] = "datos.dat";
    char archivoAlum[] = "datosAlum.dat";
    int num;
    int cant;
    Pila origen;
    inicpila(&origen);
    int min, max;
    char arrAlumnos[MAX_ALUMNOS];
    int val;

    while(control == 's')
    {
        printf("\n\t--- TRABAJO PRACTICO 7: ARCHIVOS ---\n");
        printf("\n\t=== DATOS PRIMITIVOS (INT) ===\n");
        printf("1.  Agregar un numero al final del archivo\n");
        printf("2.  Mostrar archivo de numeros\n");
        printf("3.  Contar cantidad de numeros en el archivo\n");

        printf("\n\t=== ESTRUCTURA ALUMNO ===\n");
        printf("4.  Cargar archivo de alumnos (Sobreescribe/Crea nuevo)\n");
        printf("5.  Mostrar lista de alumnos\n");
        printf("6.  Agregar un alumno al final\n");
        printf("7.  Pasar legajos de mayores de edad a Pila\n");
        printf("8.  Contar alumnos mayores a una edad especifica\n");
        printf("9.  Mostrar alumnos en un rango de edad\n");
        printf("10. Mostrar el alumno de mayor edad\n");
        printf("11. Contar alumnos por anio de cursada\n");
        printf("12. Copiar Arreglo a Archivo (y viceversa)\n");
        printf("13. Contar registros (usando fseek/ftell)\n");
        printf("14. Mostrar alumno por posicion especifica (0-9)\n");
        printf("15. Modificar un registro de alumno\n");
        printf("16. Invertir el orden del archivo\n");
        printf("0.  Salir\n");

        printf("\nIngrese su opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            agregarNumArchivo(archivoNum);
            break;
        case 2:
            leerNumArchivo(archivoNum);
            break;
        case 3:
            cant = contarRegistrosArchivo(archivoNum);
            printf("Cantidad de elementos son:%d\n",cant);
            break;
        case 4:
            cargarAlumArchivo(archivoAlum);
            break;
        case 5:
            mostrarAlumArchivo(archivoAlum);
            break;
        case 6:
            agregarAlumArchivo(archivoAlum);
            break;
        case 7:
            pasarLegajosAPila(archivoAlum,&origen);
            mostrar(&origen);
            break;
        case 8 :
            printf("Ingrese la edad base para contar: ");
            scanf("%d", &num);
            cant = contarMayoresEdad(archivoAlum, num);
            printf("Hay %d alumnos mayores a %d anios.\n", cant, num);
            break;
        case 9:
            printf("Ingrese edad minima: ");
            scanf("%d", &min);
            printf("Ingrese edad maxima: ");
            scanf("%d", &max);
            mostrarNombresPorEdad(archivoAlum, min, max);
            break;
        case 10:
            mostrarMayorDelArchivo(archivoAlum);
            break;
        case 11:
            printf("Ingrese el anio a contar: ");
            scanf("%d", &num);
            cant = cantDeAlumDeUnAnio(archivoAlum, num);
            printf("Hay %d alumnos en el anio %d.\n", cant, num);
            break;
        case 12:
            printf("\n--- CARGA DE ARREGLO ---\n");
            val = cargarAlumnos(arrAlumnos, MAX_ALUMNOS);
            printf("\n--- CONTENIDO DEL ARR ---\n");
            mostrarAlumnosArr(arrAlumnos, val);

            pasarArrAlumAArchivo(archivoAlum, arrAlumnos, val);

            printf("\n--- CONTENIDO DEL ARCHIVO ---\n");
            mostrarAlumArchivo(archivoAlum);

            printf("\n--- FILTRAR ARCHIVO -> ARREGLO ---\n");
            printf("Ingrese anio a buscar: ");
            scanf("%d", &num);

            val = pasarArchivoAlumAArr(archivoAlum, arrAlumnos, num);

            printf("\n--- RESULTADO FINAL EN ARREGLO ---\n");
            mostrarAlumnosArr(arrAlumnos, val);
            break;
        case 13:
            cant = cantDeRegistro(archivoAlum);
            printf("Cantidad de Alumnos son:%d\n",cant);
            break;
        case 14:
            printf("Ingrese una POS a buscar: ");
            scanf("%d", &num);
            mostrarAlumnoPorPosicion(archivoAlum,num);
            break;
        case 15:
            printf("Ingrese la posicion a modificar: ");
            scanf("%d", &num);
            modificarRegistro(archivoAlum, num);
            break;
        case 16:
            invertirArchivo(archivoAlum);
            break;
        case 0:
            printf("Saliendo del programa...\n");
            control = 'n';
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        if(control == 's')
        {
            printf("Desea seguir en el programa 's/n':");
            fflush(stdin);
            scanf("%c",&control);
        }

    }
    return 0;
}
