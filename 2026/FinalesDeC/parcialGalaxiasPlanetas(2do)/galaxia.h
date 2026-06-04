#ifndef GALAXIA_H
#define GALAXIA_H

#include "planeta.h"
#define DIM 20

typedef struct
{
    char nombreGalaxia [DIM];
    char tipoGalaxia [DIM];
    char descubiertoPor [DIM];
    stPlaneta listaPlanetas[DIM];
    int valPlanetas;
} stGalaxia;

stGalaxia cargarUnaGalaxia();
int cargarGalaxias(stGalaxia arr[],int dim);
void mostrarUnaGalaxia(stGalaxia galaxia);
void mostrarGalaxias(stGalaxia arr[],int val);
void mostrarGalaxiasPorTipo(stGalaxia arr[],int val, char tipoBuscado[]);
int contarSatelitesDeGalaxias(stGalaxia arr[],int val);
void pedirGalaxia(char galaxia[]);
void guardarPlanetasGalaxiasPorMasa(char archivo[],stGalaxia arr[],int val,float masa);
#endif // GALAXIA_H
