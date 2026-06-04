#ifndef ALUMNO_H
#define ALUMNO_H

#include "pila.h"

#define DIM 30

typedef struct
{
    int legajo;
    char nombreYapellido[DIM];
    int edad;
    int anio;
} stAlumno;

stAlumno cargarAlumno();
void cargarAlumnosEnArchivo(char archivo[]);
void mostrarAlumno(stAlumno alumno);
void mostrarAlumnosArchivo(char archivo[]);
void agregarAlumno(char archivo[]);
void pasarLegajosAPila (char archivo[],Pila* a);
int contarCantDeAlumnosMayorDeEdad (char archivo[],int edad);
int pedirEntero(char mensaje[]);
void mostrarAlumnosEnRango(char archivo[],int minEdad, int maxEdad);
void mostrarNombreAlumno(stAlumno alumno,int minEdad,int maxEdad);
void mostrarAlumnosMayorDeEdad(char archivo[]);
int cantidadDeAlumnosPorAnio (char archivo[], int anio);
int cargarAlumnos(stAlumno arr[],int dim);
void mostrarAlumnos(stAlumno arr[],int val);
int pasarArchiAArr(char archivo[],stAlumno arr[], int dim,int anio);
void pasarArrAArchi (stAlumno arr[],int val,char archivo[]);
void mostrarAlumnoPorPosicion(char archivo[], int pos);

#endif
