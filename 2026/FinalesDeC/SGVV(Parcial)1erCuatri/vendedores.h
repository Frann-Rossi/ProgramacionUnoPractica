#ifndef VENDEDORES_H
#define VENDEDORES_H

#define LARGO_NOMBRE 30

int cargarNombres(char arr[][LARGO_NOMBRE], int dim);
char pedirLetra();
void mostrarNombresPorInicial (char arr[][LARGO_NOMBRE],int val,char letra);
void mostrarNombres(char arr[][LARGO_NOMBRE],int val);
int modificarRegistros(char arr[][LARGO_NOMBRE],int val);

#endif // VENDEDORES_H
