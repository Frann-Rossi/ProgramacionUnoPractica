#ifndef DUENIOS_H
#define DUENIOS_H

#define DIM 30
typedef struct
{
    int idDuenio;
    char nombre[DIM];
    char apellido[DIM];
    char telefono[DIM];
    int eliminado;

} stDuenio;

stDuenio cargarUnDuenio(char archi[]);
void cargarDueniosArchi (char archi[]);
void mostrarUnDuenio(stDuenio duenio);
void mostrarDueniosArchi(char archi[]);
int idExistenteDuenio(char archi[],int id);
void modificarDuenio(char archivo[],int id);
void eliminarDuenio(char archivo[],int id);
void buscarDuenioPorId (char archivo[],int id);
void pasarArchiToArrDuenios(char archi[],stDuenio arr[], int dim);
int posMenor(stDuenio arr[],int val, int pos);
void ordenamientoPorSeleccion(stDuenio arr[],int val);

#endif // DUENIOS_H
