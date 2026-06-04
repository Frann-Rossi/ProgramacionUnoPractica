#ifndef PLANETA_H
#define PLANETA_H

#define DIM 20

typedef struct
{
    char nombrePlaneta [DIM];
    char estrella [DIM];
    int cantidadSatelites;
    float masa;
    int tempMax;
    int tempMin;
} stPlaneta;

stPlaneta cargarUnPlaneta();
int cargarPlanetas(stPlaneta arr[],int dim);
void mostrarUnPlaneta(stPlaneta planeta);
void mostrarPlanetas(stPlaneta arr[],int val);
int contarSatelites(stPlaneta arr[],int val, int i);
int contarCantElemArchi(char archivo[]);
void arrDinamico(stPlaneta** arr,int cant);
int pasarArchiToArr(char archivo[],stPlaneta** arr);
float pedirFloat (char msj[]);

#endif
