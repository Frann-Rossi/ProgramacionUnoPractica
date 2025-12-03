#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define DIM_FILA 3
#define DIM_COL 3

#define DIM_FILA2 2
#define DIM_COL2 2

#define DIM_FILACHAR 30
#define DIM_COLCHAR 30

void cargarMatriz(int matriz[][DIM_COL])
{

    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            printf("Ingrese valor [%d][%d]: ", f, c);
            scanf("%d", &matriz[f][c]);
        }
    }
}
void mostrarMatriz (int matriz[][DIM_COL])
{
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            printf("|%d|",matriz[f][c]);
        }
        printf("\n");
    }
}

void cargarMatrizRandom (int matriz[][DIM_COL])
{
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            matriz[f][c] = rand() % 11;
        }
    }
}

int sumarMatriz(int matriz[][DIM_COL])
{
    int sum = 0;
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            sum += matriz[f][c];
        }
    }
    return sum;
}

float promedio (int matriz[][DIM_COL])
{
    int sum = 0;
    int cant = 0;
    float promedio;
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            sum += matriz[f][c];
            cant++;
        }
    }
    promedio = (float)sum / cant;
    return promedio;
}

int buscarNum (int matriz[][DIM_COL], int num)
{
    int flag = 0;
    for(int f = 0; f < DIM_FILA; f++)
    {
        for(int c = 0; c < DIM_COL; c++)
        {
            if(matriz[f][c] == num)
            {
                flag = 1;
            }
        }
    }
    return flag;
}

int cargarMatrizChar(char matrizChar[][DIM_COLCHAR], int dim)
{
    int f = 0;
    char control = 's';

    while(control == 's' && f < dim)
    {
        printf("Cargue un NOMBRE\n");
        fflush(stdin);
        scanf("%s",matrizChar[f]);
        f++;
        printf("Desea seguir cargando nombres 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);
    }
    return f;
}

void mostrarMatrizChar (char matrizChar[][DIM_COLCHAR], int val)
{
    for(int i = 0; i < val; i++)
    {
        printf("|%s|\n",matrizChar[i]);
    }
}

int econtrarString (char matrizChar[][DIM_COLCHAR],int val, char palabra[])
{
    int flag = -1;
    for(int i = 0; i < val ; i++)
    {
        if(strcmpi(matrizChar[i],palabra) == 0)
        {
            flag = i;
        }
    }
    return flag;
}

int buscarStringOrdenado(char matrizChar[][DIM_COLCHAR], int val, char palabra[])
{
    int i = 0;

    // Mientras no llegue al final
    while(i < val)
    {

        // Comparamos la palabra de la matriz con la buscada
        int comparacion = strcmpi(matrizChar[i], palabra);

        if (comparacion == 0)
        {
            return i; // ¡La encontre! (Son iguales)
        }

        if (comparacion > 0)
        {
            return -1; // ¡Me pasé! (La de la matriz ya es "mayor" que la buscada).
            // Como esta ordenado, no hace falta seguir.
        }

        i++;
    }

    return -1; // Llegue al final y no estaba
}

int buscarMenor (char matrizChar[][DIM_COLCHAR],int val,int posInicio)
{
    int posMenor = posInicio;
    for(int i = posInicio + 1; i < val; i++)
    {
        if(strcmpi(matrizChar[i],matrizChar[posMenor]) < 0)
        {
            posMenor = i;
        }
    }
    return posMenor;
}

void ordenamientoPorSeleccion(char matrizChar[][DIM_COLCHAR], int val)
{
    int posMenor;
    char aux[DIM_COLCHAR];
    for(int i = 0; i < val; i++)
    {
        posMenor = buscarMenor(matrizChar,val,i);

        strcpy (aux,matrizChar[i]);
        strcpy (matrizChar[i],matrizChar[posMenor]);
        strcpy (matrizChar[posMenor],aux);
    }
}

void insertarElemento (char matrizChar[][DIM_COLCHAR], int val, char elem[])
{
    int i = val - 1;

    while(i >= 0 && strcmpi(elem,matrizChar[i]) < 0)
    {
        strcpy(matrizChar[i+1],matrizChar[i]);
        i--;
    }

    strcpy(matrizChar[i+1], elem);
}

void ordenamientoPorInsercion(char matrizChar[][DIM_COLCHAR], int val)
{
    char aux[DIM_COLCHAR];
    for(int i = 0; i < val; i++)
    {
        strcpy(aux,matrizChar[i]);
        insertarElemento(matrizChar,i,aux);
    }
}

int devolverDeterminanteMatriz (int matriz[][DIM_COL2])
{
    int determinante;
    int diagPrincipal = matriz[0][0] * matriz[1][1];
    int diagSecundaria = matriz[1][0] * matriz[0][1];
    determinante = diagPrincipal - diagSecundaria;
    return determinante;
}

int tieneInversa(int matriz[][DIM_COL2])
{
    int det = devolverDeterminanteMatriz(matriz);
    int flag = 0;

    if(det != 0)
    {
        flag = 1;
    }
    return flag;
}

int esSimetrica(int matriz[][DIM_COL])
{
    int flag = 1;
    for(int f = 0; f < DIM_FILA2; f++)
    {
        for(int c = 0; c < DIM_COL2; c++)
        {
            if(matriz[f][c] != matriz[c][f])
            {
                flag = 0;
            }
        }
    }
    return flag;
}

void generarMatrizIdentidad(int matriz[][DIM_COL2])
{
    for(int f = 0; f < DIM_FILA2; f++)
    {
        for(int c = 0; c < DIM_COL2; c++)
        {

            if ( f == c )
            {
                matriz[f][c] = 1;
            }
            else
            {
                matriz[f][c] = 0;
            }
        }
    }
}

void cargarMatriz2x2(int matriz[][DIM_COL2])
{

    for(int f = 0; f < DIM_FILA2; f++)
    {
        for(int c = 0; c < DIM_COL2; c++)
        {
            matriz[f][c] = rand() % 11;
        }
    }
}
void mostrarMatriz2x2 (int matriz[][DIM_COL2])
{
    for(int f = 0; f < DIM_FILA2; f++)
    {
        for(int c = 0; c < DIM_COL2; c++)
        {
            printf("|%d|",matriz[f][c]);
        }
        printf("\n");
    }
}


int main()
{
    char control = 's';
    int opcion;
    int matriz[DIM_FILA][DIM_COL];
    srand(time(NULL));
    int total;
    int numBuscado;
    int val = 0;
    char matrizChar[DIM_FILACHAR][DIM_COLCHAR];
    int posPalabra;
    char palabra[DIM_COLCHAR];
    int matriz2x2[DIM_FILA2][DIM_COL2];
    int det;
    int inversa;
    int simetrica;

    while(control == 's')
    {
        printf("\n\n--- MENU TP N4: MATRICES ---\n");
        printf("1.  Cargar matriz (Usuario) \n");
        printf("2.  Mostrar matriz \n");
        printf("3.  Cargar matriz (Aleatoria) \n");
        printf("4.  Sumar contenido total \n");
        printf("5.  Promedio de matriz \n");
        printf("6.  Buscar elemento en matriz \n");
        printf("7.  Cargar arreglo de palabras \n");
        printf("8.  Mostrar arreglo de palabras \n");
        printf("9.  Buscar string en arreglo \n");
        printf("10. Buscar string (arreglo ordenado) \n");
        printf("11. Ordenar arreglo de palabras \n");
        printf("12. Determinante matriz 2x2 \n");
        printf("13. Verificar Inversa matriz 2x2 \n");
        printf("14. Verificar matriz Simetrica \n");
        printf("15. Generar Matriz Identidad \n");
        printf("16. Ejercicio Extra: Elecciones \n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            cargarMatriz(matriz);
            break;
        case 2 :
            mostrarMatriz(matriz);
            break;
        case 3:
            cargarMatrizRandom(matriz);
            mostrarMatriz(matriz);
            break;
        case 4:
            total = sumarMatriz(matriz);
            printf("La SUMA de la matriz fue:%d\n", total);
            break;
        case 5:
            printf("El promedio de la matriz es:%.2f\n",promedio(matriz));
            break;
        case 6:
            printf("Ingrese un num para buscar:\n");
            scanf("%d",&numBuscado);
            if(buscarNum(matriz,numBuscado) == 1)
            {
                printf("El numero %d ESTA en la matriz\n",numBuscado);
            }
            else
            {
                printf("El numero %d NO ESTA en la matriz\n",numBuscado);
            }
            break;
        case 7:
            val = cargarMatrizChar(matrizChar,DIM_FILACHAR);
            printf("Se cargaron %d nombres\n", val);
            break;
        case 8:
            mostrarMatrizChar(matrizChar,val);
            break;
        case 9:
            printf("Palabra a BUSCAR\n");
            scanf("%s",&palabra);
            posPalabra = econtrarString(matrizChar,val,palabra);
            if(posPalabra != -1)
            {
                printf("La palabra '%s' se encontra en la pos %d\n",palabra,posPalabra);
            }
            else
            {
                printf("La palabra no se encuentra en la lista\n");
            }

            break;
        case 10:
            printf("Palabra a BUSCAR\n");
            scanf("%s",&palabra);
            posPalabra = buscarStringOrdenado(matrizChar,val,palabra);
            if(posPalabra != -1)
            {
                printf("La palabra '%s' se encontra en la pos %d\n",palabra,posPalabra);
            }
            else
            {
                printf("La palabra no se encuentra en la lista\n");
            }
            break;
        case 11:
            printf("SELECCION\n");
            ordenamientoPorSeleccion(matrizChar,val);
            mostrarMatrizChar(matrizChar,val);
            printf("INSERCION\n");
            ordenamientoPorInsercion(matrizChar,val);
            mostrarMatrizChar(matrizChar,val);
            break;
        case 12:
            cargarMatriz2x2(matriz2x2);
            mostrarMatriz2x2(matriz2x2);
            det = devolverDeterminanteMatriz(matriz2x2);
            printf("El determinante es:%d\n",det);
            break;
        case 13:
            inversa = tieneInversa(matriz2x2);
            if(inversa != 0)
            {
                printf("Tiene inversa\n");
            }
            else
            {
                printf("No tiene inversa");
            }
            break;
        case 14:
            simetrica = esSimetrica(matriz2x2);
            if(simetrica != 0)
            {
                printf("Es simetrica\n");
            }
            else
            {
                printf("No es simetrica");
            }
            break;
        case 15:
            generarMatrizIdentidad(matriz2x2);
            mostrarMatriz2x2(matriz2x2);
            break;
        default:
            printf("Ingrese un valor valido\n");
        }
        printf("Desea Seguir en el PROGRAMA 's/n'\n");
        fflush(stdin);
        scanf("%c",&control);

    }
    return 0;
}
