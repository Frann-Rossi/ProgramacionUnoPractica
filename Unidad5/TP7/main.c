#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 30

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

int main()
{
    char control = 's';
    int opcion;
    char archivoNum[] = "datos.dat";
    char archivoAlum[] = "datosAlum.dat";
    int num;
    int cant;

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
