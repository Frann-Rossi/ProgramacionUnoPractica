#ifndef NOMBRES_H
#define NOMBRES_H

#define MAX_NOMBRES 10
#define LARGO_NOMBRE 30

int nombreExiste (char arrNombres[][LARGO_NOMBRE],int val, char palabra[]);
int cargarNombres(char arrNombres[][LARGO_NOMBRE],int dim);
void mostrarNombres(char arrNombres[][LARGO_NOMBRE],int val);

#endif
