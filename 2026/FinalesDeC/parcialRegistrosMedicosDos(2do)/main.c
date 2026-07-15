#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

typedef struct
{
    int idRegistro;
    int idPaciente;
    int idEspecialidad;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11]; /// formato: AAAA-mm-DD
    char especialidadMedica[30];
    char nombreDoctor[30];
    float precioAtencion;
} stRegistroMedico;

//EJERCICIO 1
//==================================================
int pasarArchivoToArrRegistros(char archivoRegistros[],stRegistroMedico arrRegistros[],int dim);
int especilidadExite(stRegistroMedico arrNuevo[],int val,int id);
int arrRegistrosSinRepe(stRegistroMedico arrRegistro[],int val,stRegistroMedico arrNuevo[]);
//==================================================

//EJERCICIO 2
//==================================================
void mostrarUnRegistro(stRegistroMedico registro);
void mostrarRegistros(stRegistroMedico arrRegistros[],int val);
//==================================================

//EJERCICIO 3
//==================================================
int posMenor (stRegistroMedico arrRegistro[],int val, int pos);
void ordenamientoPorSeleccion(stRegistroMedico arrRegistros[], int val);
//==================================================

//EJERCICIO 4
//==================================================
void archivoAtencionesPrecioSup(stRegistroMedico arrRegistro[],int val, char archivoNuevoRegistros[],float precio);
//==================================================

//EJERCICIO 5
//==================================================
int contarRegistros (char rutaArchivo[]);
float porcentajeEspecialidad (char archivoRegistro[],char especlidad[]);
//==================================================


//EJERCICIO 6
//==================================================
void pasarPila(Pila* origen, Pila* destino);
void precioAtencionPila(stRegistroMedico arrRegistro[],int val,Pila* precio);
//==================================================

int main()
{

    return 0;
}


//EJERCICIO 1
//==================================================
int pasarArchivoToArrRegistros(char archivoRegistros[],stRegistroMedico arrRegistros[],int dim)
{
    FILE* buffer = fopen(archivoRegistros,"rb");
    stRegistroMedico registro;

    int i = 0;
    if(buffer)
    {
        while(i < dim && fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            arrRegistros[i] = registro;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return i;
}

int especilidadExite(stRegistroMedico arrNuevo[],int val,int id)
{
    int i = 0;

    while(i < val && arrNuevo[i].idEspecialidad != id )
    {
        i++;
    }
    return i;
}

int arrRegistrosSinRepe(stRegistroMedico arrRegistro[],int val,stRegistroMedico arrNuevo[])
{
    int cant = 0;
    for(int i = 0; i < val; i++)
    {
        if(!especilidadExite(arrNuevo,cant,arrRegistro[i].idEspecialidad))
        {
            arrNuevo[cant].idEspecialidad = arrRegistro[i].idEspecialidad;
            strcpy(arrNuevo[cant].especialidadMedica,arrRegistro[i].especialidadMedica);
            cant++;
        }
    }
    return cant;
}
//==================================================

//EJERCICIO 2
//==================================================
void mostrarUnRegistro(stRegistroMedico registro)
{
    printf("\nNombre del doctor:%s",registro.nombreDoctor);
    printf("\nNombre del paciente:%s",registro.nombrePaciente);
    printf("\nNombre de la especilidad:%s",registro.especialidadMedica);
}

void mostrarRegistros(stRegistroMedico arrRegistros[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarUnRegistro(arrRegistros[i]);
    }
}
//==================================================

//EJERCICIO 3
//==================================================
int posMenor (stRegistroMedico arrRegistro[],int val, int pos)
{
    int posMenor = pos;
    float menor = arrRegistro[pos].precioAtencion;
    for(int i = pos+1; i < val; i++)
    {
        if(arrRegistro[i].precioAtencion < menor)
        {
            posMenor = i;
            menor = arrRegistro[i].precioAtencion;
        }
    }
    return posMenor;
}

void ordenamientoPorSeleccion(stRegistroMedico arrRegistros[], int val)
{
    int menor;
    stRegistroMedico aux;
    for(int i = 0; i < val; i++)
    {
        menor = posMenor(arrRegistros,val,i);
        aux = arrRegistros[i];
        arrRegistros[i] = arrRegistros[menor];
        arrRegistros[menor] = aux;

    }
}
//==================================================

//EJERCICIO 4
//==================================================
void archivoAtencionesPrecioSup(stRegistroMedico arrRegistro[],int val, char archivoNuevoRegistros[],float precio)
{
    FILE* buffer = fopen(archivoNuevoRegistros,"wb");

    if(buffer)
    {
        for(int i = 0; i < val; i++)
        {
            if(arrRegistro[i].idPaciente % 2 == 0 && arrRegistro[i].precioAtencion > precio)
            {
                fwrite(&arrRegistro[i],sizeof(stRegistroMedico),1,buffer);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================

//EJERCICIO 5
//==================================================
int contarRegistros (char rutaArchivo[])
{
    FILE* buffer = fopen(rutaArchivo,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stRegistroMedico);
        fclose(buffer);
    }
    return cant;
}

float porcentajeEspecialidad (char archivoRegistro[],char especlidad[])
{
    FILE* buffer = fopen(archivoRegistro,"rb");
    stRegistroMedico registro;
    int cantRegistros = contarRegistros(archivoRegistro);
    int cant = 0;
    float promedio = 0;
    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            if(strcmpi(registro.especialidadMedica,especlidad) == 0)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    promedio = ((float)cantRegistros / cant)* 100;
    return promedio;
}
//==================================================


//EJERCICIO 6
//==================================================
void pasarPila(Pila* origen, Pila* destino)
{
    while(!pilavacia(origen))
    {
        apilar(destino,desapilar(origen));
    }
}

void precioAtencionPila(stRegistroMedico arrRegistro[],int val,Pila* precio)
{
    Pila aux;
    inicpila(&aux);
    int precioAtencion = 0;

    for(int i = 0; i < val; i++)
    {
        precioAtencion = (int)arrRegistro[i].precioAtencion;

        while(!pilavacia(precio) && tope(precio) > precioAtencion)
        {
            apilar(&aux, desapilar(precio));
        }
        apilar(precio, precioAtencion);

        pasarPila(&aux, precio);
    }
}
//==================================================
