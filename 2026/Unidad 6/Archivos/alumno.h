#ifndef ALUMNO_H
#define ALUMNO_H

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
void mostrarAlumnos(char archivo[]);

//Recursividad
int cargarAlumnosRecu(stAlumno arr[],int dim,int i);
void mostrarAlumnosRecu(stAlumno arr[],int val,int i);

#endif
