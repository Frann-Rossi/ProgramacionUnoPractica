#ifndef MIS_FUNCIONES_H
#define MIS_FUNCIONES_H

// EJ 1
int nroRandom();

// EJ 2
int devuelveMenor(int nro1, int nro2, int nro3);
int devuelveMayor(int nro1, int nro2, int nro3);
void devuelveMayorYMenor(int nro1, int nro2, int nro3, int *menor, int *mayor);

// EJ 3
int sumarNro(int nro);

// EJ 4
void tablaMultiplicar(int nro);

// EJ 5 (Calculadora y sus auxiliares)
int sumar(int nro1, int nro2);
int restar(int nro1, int nro2);
int multiplicar(int nro1, int nro2);
int dividir(int nro1, int nro2);
void calculadora(int nro1, int nro2, int opcion);

//EJ 6
int devolverNroNegativo(int nro);

//EJ 7
void valoresPorReferencia(int* nro1, int* nro2);

#endif // MIS_FUNCIONES_H
