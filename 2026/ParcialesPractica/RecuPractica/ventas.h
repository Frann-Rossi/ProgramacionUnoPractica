#ifndef VENTAS_H
#define VENTAS_H

#include "pila.h"

void cargarCompras(Pila* pila, int* suma, int* cant);
void pasarPilaAOtra (Pila* origen, Pila* destino);
void ordenamientoPorSeleccion(Pila* pila);
int cantDigitos (int num);
void contarPorDigitos (Pila* pila, int arr[], int dim);
void mostrarArr(int arr[],int val);
int rangoMayorDeCompra (Pila pila);

#endif
