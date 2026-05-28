#ifndef MASCOTA_H
#define MASCOTA_H

#define DIM 30

typedef struct
{
    int idMascota;
    char nombre[DIM];
    char especie[DIM];
    char raza[DIM];
    int edad;
    int idDuenio;
    int eliminado;
} stMascota;

stMascota cargarUnaMascota(char archi[]);
void cargarMascotaArchi (char archi[]);
void mostrarUnaMascota(stMascota mascota);
void mostrarMascotasArchi(char archi[]);
int idExistenteMascota(char archi[],int id);
void modificarMascota(char archivo[],int id);
int pedirNum(char msj[]);
void eliminarMascota(char archivo[],int id);
void buscarMascotaPorId (char archivo[],int id);
void pasarArchiToArr(char archi[],stMascota arr[], int dim);
void mostrarMascotasArr(stMascota arr[],int val);
void insertar(stMascota arr[],int val,stMascota elem);
void ordenamientoPorInsercion(stMascota arr[],int val);

#endif
