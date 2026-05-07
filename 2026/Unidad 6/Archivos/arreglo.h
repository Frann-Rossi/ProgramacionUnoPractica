#ifndef ARREGLO_H
#define ARREGLO_H

int cargarArr(int arr[],int dim);
void mostrarArr(int arr[],int val);
int cantNumPares(int arr[], int val);
int* cant(int cant);
void pasarArrAArrDim (int arr[],int val,int* arrDim);
int crearArrDinamico(int** arr, int dim);
void arrDimDoble (int arr[],int val,int** arrDim);

#endif
