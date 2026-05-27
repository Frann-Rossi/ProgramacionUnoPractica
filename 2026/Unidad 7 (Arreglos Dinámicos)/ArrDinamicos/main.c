#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int legajo;
    char nombreYapellido [30];
    int edad;
    int anio;
//año que cursa, recordar que no podemos utilizar la ñ para definir variables
} stAlumno;

void menu()
{
    printf("\n====================================\n");
    printf(" TP - ARREGLOS DINAMICOS\n");
    printf("====================================\n");

    printf("1  - Pasar numeros pares a arreglo dinamico\n");

    printf("2  - Pasar archivo de alumnos a arreglo dinamico\n");

    printf("3  - Filtrar alumnos mayores a edad dada\n");

    printf("4  - Unir dos arreglos dinamicos enteros\n");

    printf("5  - Duplicar tamanio de arreglo dinamico\n");

    printf("6  - Agregar elemento al final del arreglo dinamico\n");

    printf("7  - Pasar archivo de alumnos a Archivo filtando edad \n");

    printf("0  - Salir\n");

    printf("====================================\n");
    printf("Seleccione una opcion: ");
}

void arrDin(stAlumno** arr, int val)
{
    (*arr) = malloc(val * sizeof(stAlumno));
}

stAlumno* arrDinP (stAlumno* arr,int val)
{
    arr = malloc(val * sizeof(stAlumno));
    return arr;
}

int cantArchi (char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;
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

void pasarArchiAArr(char archivo[], stAlumno arr[],int val)
{
    FILE* buffer = fopen(archivo,"rb");
    stAlumno alumno;
    int i = 0;

    if(buffer)
    {
        while(fread(&alumno,sizeof(stAlumno),1,buffer)>0 && i < val)
        {
            arr[i] = alumno;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

void mostrarAlumno(stAlumno alumno)
{
    printf("\n=====");
    printf("\nLegajo:%d",alumno.legajo);
    printf("\nNombre y Apellido:%s",alumno.nombreYapellido);
    printf("\nEdad:%d",alumno.edad);
    printf("\nAnio:%d",alumno.anio);
    printf("\n=====");
}

void mostrarAlumnos(stAlumno arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarAlumno(arr[i]);
    }
}

int contarMayores(stAlumno arr[],int val)
{
    int cant = 0;
    for(int i = 0; i < val; i++)
    {
        if(arr[i].edad >= 18)
        {
            cant++;
        }
    }
    return cant;
}

void pasarArrAOtro(stAlumno arr[],stAlumno** arr2, int val,int edad)
{
    int cantMayores = contarMayores(arr,val);
    arrDin(arr2,cantMayores);
    int j = 0;
    for(int i = 0; i < val; i++)
    {
        if(arr[i].edad > edad)
        {
            (*arr2)[j] = arr[i];
            j++;
        }
    }
}

void pasarArchiAOtro(char archi[],char archi2[],int edad)
{
    FILE* buffer = fopen(archi,"rb");
    FILE* buffer2 = fopen(archi2,"wb");
    stAlumno alumnno;
    if(buffer && buffer2)
    {
        while(fread(&alumnno,sizeof(stAlumno),1,buffer)>0)
        {
            if(alumnno.edad >= edad)
            {
                fwrite(&alumnno,sizeof(stAlumno),1,buffer2);
            }
        }
        fclose(buffer);
        fclose(buffer2);
    }
    else
    {
        printf("Error al abrir el archivo\n");
    }
}

void mostrarAlumnosArchi(FILE* buffer)
{
    stAlumno alumnno;
    if(buffer)
    {
        while(fread(&alumnno,sizeof(stAlumno),1,buffer)>0)
        {
            mostrarAlumno(alumnno);
        }
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

    char archi[] = "archi.bin";
    char archi2[] = "archi2.bin";
    stAlumno *arrAlum;
    stAlumno *arrAlumMayores;
    int val = 0;
    int cantMayores = 0;
    //stAlumno *arrAlumP;
    FILE* buffer;

    while(control == 's')
    {
        menu();
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            val = cantArchi(archi);
            arrDin(&arrAlum,val);
            pasarArchiAArr(archi,arrAlum,val);
            mostrarAlumnos(arrAlum,val);
            //arrAlumP = arrDinP(arrAlumP,val);
            break;
        case 2:
            cantMayores = contarMayores(arrAlum,val);
            pasarArrAOtro(arrAlum,&arrAlumMayores,val,18);
            mostrarAlumnos(arrAlumMayores,cantMayores);
            break;
        case 7:
            pasarArchiAOtro(archi,archi2,18);
            buffer = fopen(archi2,"rb");
            mostrarAlumnosArchi(buffer);
            fclose(buffer);
            break;
        case 0:
            control = 'n';
            printf("Saliendo.....");
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        if(control == 's')
        {
            printf("\nDesea seguir en el programa 's/n':");
            scanf(" %c",&control);
        }
    }
    return 0;
}
