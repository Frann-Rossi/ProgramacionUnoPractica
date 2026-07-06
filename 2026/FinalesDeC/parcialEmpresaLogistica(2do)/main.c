#include <stdio.h>
#include <stdlib.h>

#define PESO_MINIMO 10000.0

typedef struct
{
    int idBuque;
    char nombre[50];
    char paisOrigen[30];
    int capacidadMaxContenedores;
    int tieneContenedores;
} stBuque;

typedef struct
{
    int idContenedor;
    int idBuque; // Clave foránea al Buque
    char tipoCarga[40];
    float pesoKg;
    char destino[50];
} stContenedor;


// FUNCIONES

void menu()
{
    printf("\n======================================================\n");
    printf("         SISTEMA LOGISTICO - PUERTO DIGITAL           \n");
    printf("======================================================\n");
    printf("  [1] Cargar contenedores pesados (> 10000kg)\n");
    printf("  [2] Cargar buques sin contenedores asignados\n");
    printf("  [3] Mostrar registros cargados en el sistema\n");
    printf("  [4] Ingresar un nuevo contenedor a un buque\n");
    printf("  [5] Calcular promedio de peso de contenedores\n");
    printf("  [6] Exportar contenedores por peso (Archivos)\n");
    printf("  [0] Salir del programa\n");
    printf("======================================================\n");
}

char seguir (char msj[])
{
    char control;
    printf("%s",msj);
    scanf(" %c",&control);
    return control;
}

int pedirNum(char msj[])
{
    int num;
    printf("%s",msj);
    scanf("%d",&num);
    return num;
}

stBuque cargarUnBuque()
{
    stBuque buque;
    printf("\n=====Cargando Buque=====");
    printf("\nIngre ID del BUQUE;");
    scanf("%d",&buque.idBuque);
    printf("\nIngre NOMBRE del BUQUE:");
    scanf("%s",buque.nombre);
    printf("\nIngre PAIS ORIGEN del BUQUE:");
    scanf("%s",buque.paisOrigen);
    printf("\nIngre CAPACIDAD MAX CONTEN. del BUQUE:");
    scanf("%d",&buque.capacidadMaxContenedores);
    printf("\nIngre si TIENE CONTEN. del BUQUE:");
    scanf("%d",&buque.tieneContenedores);
    return buque;
}

void mostrarUnBuque(stBuque buque)
{
    printf("\n=====Mostrar Buque=====");
    printf("\nID del BUQUE:%d",buque.idBuque);
    printf("\nNOMBRE del BUQUE:%s",buque.nombre);
    printf("\nPAIS ORIGEN del BUQUE:%s",buque.paisOrigen);
    printf("\nCAPACIDAD MAX CONTEN. del BUQUE%d",buque.capacidadMaxContenedores);
    printf("\nTIENE CONTEN. del BUQUE%d",buque.tieneContenedores);
}

stContenedor cargarUnContenedor()
{
    stContenedor contenedor;
    printf("\n=====Cargando Contenedor=====");
    printf("\nIngrese ID del CONTENEDOR");
    scanf("%d",&contenedor.idContenedor);
    printf("\nIngre ID del BUQUE:");
    scanf("%d",&contenedor.idBuque);
    printf("\nIngre TIPO de CARGA:");
    scanf("%s",contenedor.tipoCarga);
    printf("\nIngre PESO KG:");
    scanf("%f",&contenedor.pesoKg);
    printf("\nIngre DESTINO:");
    scanf("%s",contenedor.destino);
    return contenedor;
}

void mostrarUnContenedor(stContenedor contenedor)
{
    printf("\nID del CONTENEDOR: %d", contenedor.idContenedor);
    printf("\nID del BUQUE: %d", contenedor.idBuque);
    printf("\nTIPO de CARGA: %s", contenedor.tipoCarga);
    printf("\nPESO KG: %.2f", contenedor.pesoKg);
    printf("\nDESTINO: %s", contenedor.destino);
}


//EJERCICIO 1
//==================================================
void arrDinContenedor(stContenedor** arr,int cant)
{
    *arr = calloc(cant,sizeof(stContenedor));
}
int contarCantElemContenedorPeso(char archivoContenedores[])
{
    FILE* buffer = fopen(archivoContenedores,"rb");
    stContenedor contenedor;
    int cant = 0;
    if(buffer)
    {
        while(fread(&contenedor,sizeof(stContenedor),1,buffer)>0)
        {
            if(contenedor.pesoKg > PESO_MINIMO)
            {
                cant++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return cant;
}
int cargarContenedoresPesados(char archivoContenedores[],stContenedor** arr)
{
    FILE* buffer = fopen(archivoContenedores,"rb");
    stContenedor contenedor;
    int cant = contarCantElemContenedorPeso(archivoContenedores);
    arrDinContenedor(arr,cant);
    int i = 0;
    if(buffer)
    {
        while(fread(&contenedor,sizeof(stContenedor),1,buffer)>0)
        {
            if(contenedor.pesoKg > PESO_MINIMO)
            {
                (*arr)[i] = contenedor;
                i++;
            }
        }
        fclose(buffer);
    }
    return i;
}
//==================================================

//EJERCiCIO 2
//==================================================
void arrDinBuque(stBuque** arr,int dim)
{
    *arr = realloc(*arr,dim*sizeof(stBuque));
}

int cargarBuquesSinCarga(char archivoBuque[],stBuque** arr)
{
    FILE* buffer = fopen(archivoBuque,"rb");
    stBuque buque;
    int i = 0;
    int dim = 10;
    *arr = malloc(dim * sizeof(stBuque));

    if(buffer)
    {
        while(fread(&buque,sizeof(stBuque),1,buffer)>0)
        {
            if(buque.tieneContenedores == 0)
            {

                if(i == dim)
                {
                    dim += 10;
                    arrDinBuque(arr,dim);
                }
                (*arr)[i] = buque;
                i++;
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return i;
}
//==================================================

//EJERCICIO 3
//==================================================
void mostrarBuquesRecu(stBuque arrBuque[],int val, int i)
{
    if(i < val)
    {
        mostrarUnBuque(arrBuque[i]);
        mostrarBuquesRecu(arrBuque,val,i+1);
    }
}

void mostrarContenedoresRecu(stContenedor arrContenedor[],int val,int i)
{
    if(i < val)
    {
        mostrarUnContenedor(arrContenedor[i]);
        mostrarContenedoresRecu(arrContenedor,val,i+1);
    }
}
//==================================================

//EJERCICIO 4
//==================================================
int almacenarContenedorYActualizarBuque(char archivoBuques[],char archivoContenedores[],int idBuscado,stContenedor contenedor)
{
    FILE* buffer = fopen(archivoBuques,"rb");
    FILE* buffer2 = fopen(archivoContenedores,"ab");

    stBuque buque;
    int flag = 0;

    if(buffer && buffer2)
    {
        while(fread(&buque,sizeof(stBuque),1,buffer)>0)
        {
            if(buque.idBuque == idBuscado)
            {
                flag = 1;
                fwrite(&contenedor,sizeof(stContenedor),1,buffer2);
            }
        }
        fclose(buffer);
        fclose(buffer2);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return flag;
}
//==================================================

//EJERCICIO 5
//==================================================
float sumarCantElemContenedorPeso(stContenedor arrContenedor[],int val,int i)
{
    float sum = 0;

    if(i < val)
    {
        sum += arrContenedor[i].pesoKg + sumarCantElemContenedorPeso(arrContenedor,val,i+1);
    }
    return sum;
}


float promedioDelPesoContedores(float sum, int cant)
{
    float promedio = 0;
    if(cant > 0)
    {
        promedio = sum / cant;
    }
    return promedio;
}
//==================================================

//EJERCICIO 6
//==================================================
void escribirArchivosPorPeso(char archivoMasPesados[], char archivoMenosPesados[],
                             stContenedor arrContenedor[],int val,float promedio)
{
    FILE* buffer = fopen(archivoMasPesados,"wb");
    FILE* buffer2 = fopen(archivoMenosPesados,"wb");

    if(buffer && buffer2)
    {
        for(int i = 0; i < val; i++)
        {
            if(arrContenedor[i].pesoKg <= promedio)
            {
                fwrite(&arrContenedor[i],sizeof(stContenedor),1,buffer2);
            }
            else
            {
                fwrite(&arrContenedor[i],sizeof(stContenedor),1,buffer);
            }
        }
        fclose(buffer);
        fclose(buffer2);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}
//==================================================


int main()
{
    char control = 's';
    int opcion;

    char archivoBuques[] = "archiBuques.bin";
    char archivoContenedores[] = "archiContenedores.bin";

    int valBuques = 0;
    int valCotenedores = 0;

    stBuque* arrBuque = NULL;
    stContenedor* arrContenedor = NULL;
    stContenedor miNuevoContenedor;

    int res = 0;
    float sum = 0;
    float promedio = 0;

    char archivoMasPesados[] = "masPesados.bin";
    char archivoMenosPesados[] = "menosPesados.bin";

    while(control == 's')
    {
        menu();
        opcion = pedirNum("\nIngrese una opcion:");
        switch(opcion)
        {
        case 1:
            valCotenedores = cargarContenedoresPesados(archivoContenedores,&arrContenedor);
            break;
        case 2:
            valBuques = cargarBuquesSinCarga(archivoBuques,&arrBuque);
            break;
        case 3:
            mostrarBuquesRecu(arrBuque,valBuques,0);
            mostrarContenedoresRecu(arrContenedor,valCotenedores,0);
            break;
        case 4:
            miNuevoContenedor = cargarUnContenedor();
            res = almacenarContenedorYActualizarBuque(archivoBuques,archivoContenedores,1,miNuevoContenedor);
            if(res == 1)
            {
                printf("\n¡Contenedor guardado con éxito!\n");
            }
            else
            {
                printf("\nERROR: El buque ingresado no existe en el registro.\n");
            }
            break;
        case 5 :
            sum = sumarCantElemContenedorPeso(arrContenedor,valCotenedores,0);
            promedio = promedioDelPesoContedores(sum,valCotenedores);
            printf("\nEl promedio fue:%.2f",promedio);
            break;
        case 6:
            if(promedio > 0)
            {
                escribirArchivosPorPeso(archivoMasPesados, archivoMenosPesados, arrContenedor, valCotenedores, promedio);
                printf("\n¡Archivos de pesos generados con éxito!\n");
            }
            else
            {
                printf("\nPrimero debe calcular el promedio (Opcion 5).\n");
            }
            break;
        case 0:
            control = 'n';
            printf("Saliendo...");
            break;
        default:
            printf("Ingrese un valor valido\n");
            break;
        }
        if(control == 's')
        {
            control = seguir("Desea seguir en el PROGRAMA 's/n':");
        }
    }
    return 0;
}
