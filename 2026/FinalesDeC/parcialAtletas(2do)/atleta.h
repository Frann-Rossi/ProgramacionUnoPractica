#ifndef ATLETA_H
#define ATLETA_H
typedef struct
{
    int id;
    char nombre[30];
    char categoria[20];
    int edad;
    float tiempoCarrera; // en segundos
    int puntos;
} stAtleta;

stAtleta cargarUnAtleta();
void cargarArchivoDeAtleta(char archivo[]);
int pasarArrToArchiPorCateg(char archivo[],stAtleta arr[], int dim,char categoria[]);
void mostrarUnAtleta(stAtleta atleta);
void mostrarArchivoDeAtleta(char archivo[]);
void mostrarArrDeAtleta(stAtleta arr[],int val);
int contarJugadoresRecur(stAtleta arr[],int val,int i);
int buscarAtleta(stAtleta arr[],int val,int i, int id);
void aumentarPuntos(char archivo[],float tiempo);
void arrDinamico(stAtleta** arr, int cant);
int contarCant(char archivo[]);
int contarTiemposMenores20(char archivo[]);
int pasarToArrTiempoMenores(char archivo[],float** arr);
char continuar(char msj[]);

#endif // ATLETA_H
