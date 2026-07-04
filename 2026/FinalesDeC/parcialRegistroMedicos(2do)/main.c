#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idRegistro;
    int idPaciente;
    int idEspecilidadMedica;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char especialidadMedica[30];
    char nombreDoctor[30];
    float precioAtencion;
} stRegistroMedico;

char seguir (char msj[])
{
    char control;
    printf("%s",msj);
    scanf(" %c",&control);
    return control;
}

int pedirNum (char msj[])
{
    int num;
    printf("%s",msj);
    scanf("%d",&num);
    return num;
}

void menu ()
{
    printf("\nEj 1 == 1");
    printf("\nSalir == 0");
}

stRegistroMedico cargarUnRegistro()
{
    stRegistroMedico registro;
    printf("\n=====Cargando Registro=====");
    printf("\nIngrese el ID del REGISTRO");
    scanf("%d",&registro.idRegistro);
    printf("\nIngrese el ID del PACIENTE");
    scanf("%d",&registro.idPaciente);
    printf("\nIngrese el ID de la ESPECIALIDAD MEDICA");
    scanf("%d",&registro.idEspecilidadMedica);
    printf("\nIngrese el NOMBRE del paciente");
    scanf("%s",registro.nombrePaciente);
    printf("\nIngrese el APELLIDO del paciente");
    scanf("%s",registro.apellidoPaciente);
    printf("\nIngrese el DIAGNOSTICO del paciente");
    scanf("%s",registro.diagnostico);
    printf("\nIngrese la FECHA de ATENCION del paciente");
    scanf("%s",registro.fechaAtencion);
    printf("\nIngrese ESPECIALIDAD MEDICA");
    scanf("%s",registro.especialidadMedica);
    printf("\nIngrese NOMBRE del DOCTOR");
    scanf("%s",registro.nombreDoctor);
    printf("\nIngrese el PRECIO de la ATENCION");
    scanf("%f",&registro.precioAtencion);
    return registro;
}

int cargarRegistros(stRegistroMedico arr[],int dim)
{
    char control = 's';
    int i = 0;

    while(control != 'n' && i < dim)
    {
        arr[i] = cargarUnRegistro();
        i++;
        control = seguir("Desea seguir cargando REGISTROS 's/n':");
    }
    return i;
}

void mostrarUnRegistro(stRegistroMedico registro)
{
    printf("\nID del REGISTRO%d",registro.idRegistro);
    printf("\nID del PACIENTE%d",registro.idPaciente);
    printf("\nID de la ESPECIALIDAD MEDICA%d",registro.idEspecilidadMedica);
    printf("\nNOMBRE del paciente%s",registro.nombrePaciente);
    printf("\nAPELLIDO del paciente%s",registro.apellidoPaciente);
    printf("\nDIAGNOSTICO del paciente%s",registro.diagnostico);
    printf("\nFECHA de ATENCION del paciente%s",registro.fechaAtencion);
    printf("\nESPECIALIDAD MEDICA%s",registro.especialidadMedica);
    printf("\nNOMBRE del DOCTOR%s",registro.nombreDoctor);
    printf("\nPRECIO de la ATENCION%.2f",registro.precioAtencion);
}

void mostrarRegistros(stRegistroMedico arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarUnRegistro(arr[i]);
    }
}

void cargarArchivo(char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");
    stRegistroMedico registro;
    char control = 's';

    if(buffer)
    {
        while(control != 'n')
        {
            registro = cargarUnRegistro();
            fwrite(&registro,sizeof(stRegistroMedico),1,buffer);
            control = seguir("\nDesea seguir cargando REGISTROS 's/n':");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

void mostrarArchivo(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;

    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            mostrarUnRegistro(registro);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

int pasarDeArchiToArr(char archivo[],stRegistroMedico arr[],int dim)
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;
    int i = 0;
    if(buffer)
    {
        while(i < dim && fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            arr[i] = registro;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return i;
}

void mostrarRegistrosRecu(stRegistroMedico arr[],int val, int i)
{
    if(i < val)
    {
        mostrarUnRegistro(arr[i]);
        mostrarRegistrosRecu(arr,val,i+1);
    }
}

float sumarAtencionesRecu(stRegistroMedico arr[],int val,int i)
{
    float sum = 0;

    if(i < val)
    {
        if(arr[i].precioAtencion > 500)
        {
            sum = arr[i].precioAtencion + sumarAtencionesRecu(arr,val,i+1);
        }
        else
        {
            sum = sumarAtencionesRecu(arr,val,i+1);
        }
    }
    return sum;
}

void pasarDeArrToArchivo(stRegistroMedico arr[],int val, char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");

    if(buffer)
    {
        for(int i = 0; i < val; i++)
        {
            if(arr[i].precioAtencion > 1500)
            {
                fwrite(&arr[i],sizeof(stRegistroMedico),1,buffer);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

void mostrarRegistrosDeUnDok(char archivo[],char nombre[])
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;

    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            if(strcmpi(registro.nombreDoctor,nombre) == 0)
            {
                mostrarUnRegistro(registro);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\Error al abrir el archivo");
    }
}

int contarCantElem(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stRegistroMedico);
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return cant;
}

float promedioDeEspecialidad(char archivo[],char especialidad[])
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;
    int cant = contarCantElem(archivo);
    int cantidadEspecialidad  = 0;
    float promedio = 0;
    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            if(strcmpi(registro.especialidadMedica,especialidad)== 0)
            {
                cantidadEspecialidad ++;
            }
        }
        fclose(buffer);
    }

    promedio =(float)cantidadEspecialidad * 100 / cant;
    return promedio;
}

void arrDin(stRegistroMedico** arr,int cant)
{
    *arr = calloc(cant,sizeof(stRegistroMedico));
}

int existeEspecilidad (stRegistroMedico arr[],int val,char especialidad[])
{
    int flag = 0;

    for(int i = 0; i < val; i++)
    {
        if(strcmpi(arr[i].especialidadMedica, especialidad) == 0)
        {
            flag = 1;
        }
    }
    return flag;
}

int crearArrDinDeEspecialidad(char archivo[],stRegistroMedico** arr)
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;
    int cant = contarCantElem(archivo);
    arrDin(arr,cant);
    int i = 0;
    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            if(existeEspecilidad(*arr,i,registro.especialidadMedica) == 0)
            {
                (*arr)[i] = registro;
                i++;
            }
        }
        *arr = realloc(*arr, i * sizeof(stRegistroMedico));
        fclose(buffer);
    }
    else
    {
        printf("\Error al abrir el archivo");
    }
    return i;
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idRegistro;
    int idPaciente;
    int idEspecilidadMedica;
    char nombrePaciente[30];
    char apellidoPaciente[30];
    char diagnostico[100];
    char fechaAtencion[11];
    char especialidadMedica[30];
    char nombreDoctor[30];
    float precioAtencion;
} stRegistroMedico;

char seguir (char msj[])
{
    char control;
    printf("%s",msj);
    scanf(" %c",&control);
    return control;
}

int pedirNum (char msj[])
{
    int num;
    printf("%s",msj);
    scanf("%d",&num);
    return num;
}

void menu()
{
    printf("\n========== MENU ==========");
    printf("\n1 - Cargar registros en arreglo");
    printf("\n2 - Mostrar registros del arreglo");
    printf("\n3 - Cargar registros en archivo");
    printf("\n4 - Mostrar registros del archivo");
    printf("\n5 - Mostrar registros recursivo");
    printf("\n6 - Sumar atenciones mayores a 500");
    printf("\n7 - Pasar registros con precio mayor a 1500 a otro archivo");
    printf("\n8 - Mostrar registros de un doctor");
    printf("\n9 - Porcentaje de una especialidad");
    printf("\n10 - Crear arreglo dinamico sin especialidades repetidas");
    printf("\n0 - Salir");
}

stRegistroMedico cargarUnRegistro()
{
    stRegistroMedico registro;
    printf("\n=====Cargando Registro=====");
    printf("\nIngrese el ID del REGISTRO");
    scanf("%d",&registro.idRegistro);
    printf("\nIngrese el ID del PACIENTE");
    scanf("%d",&registro.idPaciente);
    printf("\nIngrese el ID de la ESPECIALIDAD MEDICA");
    scanf("%d",&registro.idEspecilidadMedica);
    printf("\nIngrese el NOMBRE del paciente");
    scanf("%s",registro.nombrePaciente);
    printf("\nIngrese el APELLIDO del paciente");
    scanf("%s",registro.apellidoPaciente);
    printf("\nIngrese el DIAGNOSTICO del paciente");
    scanf("%s",registro.diagnostico);
    printf("\nIngrese la FECHA de ATENCION del paciente");
    scanf("%s",registro.fechaAtencion);
    printf("\nIngrese ESPECIALIDAD MEDICA");
    scanf("%s",registro.especialidadMedica);
    printf("\nIngrese NOMBRE del DOCTOR");
    scanf("%s",registro.nombreDoctor);
    printf("\nIngrese el PRECIO de la ATENCION");
    scanf("%f",&registro.precioAtencion);
    return registro;
}

int cargarRegistros(stRegistroMedico arr[],int dim)
{
    char control = 's';
    int i = 0;

    while(control != 'n' && i < dim)
    {
        arr[i] = cargarUnRegistro();
        i++;
        control = seguir("Desea seguir cargando REGISTROS 's/n':");
    }
    return i;
}

void mostrarUnRegistro(stRegistroMedico registro)
{
    printf("\nID del REGISTRO%d",registro.idRegistro);
    printf("\nID del PACIENTE%d",registro.idPaciente);
    printf("\nID de la ESPECIALIDAD MEDICA%d",registro.idEspecilidadMedica);
    printf("\nNOMBRE del paciente%s",registro.nombrePaciente);
    printf("\nAPELLIDO del paciente%s",registro.apellidoPaciente);
    printf("\nDIAGNOSTICO del paciente%s",registro.diagnostico);
    printf("\nFECHA de ATENCION del paciente%s",registro.fechaAtencion);
    printf("\nESPECIALIDAD MEDICA%s",registro.especialidadMedica);
    printf("\nNOMBRE del DOCTOR%s",registro.nombreDoctor);
    printf("\nPRECIO de la ATENCION%.2f",registro.precioAtencion);
}

void mostrarRegistros(stRegistroMedico arr[],int val)
{
    for(int i = 0; i < val; i++)
    {
        mostrarUnRegistro(arr[i]);
    }
}

void cargarArchivo(char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");
    stRegistroMedico registro;
    char control = 's';

    if(buffer)
    {
        while(control != 'n')
        {
            registro = cargarUnRegistro();
            fwrite(&registro,sizeof(stRegistroMedico),1,buffer);
            control = seguir("\nDesea seguir cargando REGISTROS 's/n':");
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

void mostrarArchivo(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;

    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            mostrarUnRegistro(registro);
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

int pasarDeArchiToArr(char archivo[],stRegistroMedico arr[],int dim)
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;
    int i = 0;
    if(buffer)
    {
        while(i < dim && fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            arr[i] = registro;
            i++;
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return i;
}

void mostrarRegistrosRecu(stRegistroMedico arr[],int val, int i)
{
    if(i < val)
    {
        mostrarUnRegistro(arr[i]);
        mostrarRegistrosRecu(arr,val,i+1);
    }
}

float sumarAtencionesRecu(stRegistroMedico arr[],int val,int i)
{
    float sum = 0;

    if(i < val)
    {
        if(arr[i].precioAtencion > 500)
        {
            sum = arr[i].precioAtencion + sumarAtencionesRecu(arr,val,i+1);
        }
        else
        {
            sum = sumarAtencionesRecu(arr,val,i+1);
        }
    }
    return sum;
}

void pasarDeArrToArchivo(stRegistroMedico arr[],int val, char archivo[])
{
    FILE* buffer = fopen(archivo,"wb");

    if(buffer)
    {
        for(int i = 0; i < val; i++)
        {
            if(arr[i].precioAtencion > 1500)
            {
                fwrite(&arr[i],sizeof(stRegistroMedico),1,buffer);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
}

void mostrarRegistrosDeUnDok(char archivo[],char nombre[])
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;

    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            if(strcmpi(registro.nombreDoctor,nombre) == 0)
            {
                mostrarUnRegistro(registro);
            }
        }
        fclose(buffer);
    }
    else
    {
        printf("\Error al abrir el archivo");
    }
}

int contarCantElem(char archivo[])
{
    FILE* buffer = fopen(archivo,"rb");
    int cant = 0;
    if(buffer)
    {
        fseek(buffer,0,SEEK_END);
        cant = ftell(buffer) / sizeof(stRegistroMedico);
        fclose(buffer);
    }
    else
    {
        printf("\nError al abrir el archivo");
    }
    return cant;
}

float promedioDeEspecialidad(char archivo[],char especialidad[])
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;
    int cant = contarCantElem(archivo);
    int cantidadEspecialidad  = 0;
    float promedio = 0;
    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            if(strcmpi(registro.especialidadMedica,especialidad)== 0)
            {
                cantidadEspecialidad ++;
            }
        }
        fclose(buffer);
    }

    promedio =(float)cantidadEspecialidad * 100 / cant;
    return promedio;
}

void arrDin(stRegistroMedico** arr,int cant)
{
    *arr = calloc(cant,sizeof(stRegistroMedico));
}

int existeEspecilidad (stRegistroMedico arr[],int val,char especialidad[])
{
    int flag = 0;

    for(int i = 0; i < val; i++)
    {
        if(strcmpi(arr[i].especialidadMedica, especialidad) == 0)
        {
            flag = 1;
        }
    }
    return flag;
}

int crearArrDinDeEspecialidad(char archivo[],stRegistroMedico** arr)
{
    FILE* buffer = fopen(archivo,"rb");
    stRegistroMedico registro;
    int cant = contarCantElem(archivo);
    arrDin(arr,cant);
    int i = 0;
    if(buffer)
    {
        while(fread(&registro,sizeof(stRegistroMedico),1,buffer)>0)
        {
            if(existeEspecilidad(*arr,i,registro.especialidadMedica) == 0)
            {
                (*arr)[i] = registro;
                i++;
            }
        }
        *arr = realloc(*arr, i * sizeof(stRegistroMedico));
        fclose(buffer);
    }
    else
    {
        printf("\Error al abrir el archivo");
    }
    return i;
}

int main()
{
    char control = 's';
    int opcion;

    char archivo[] = "registros.dat";

    stRegistroMedico arr[100];
    stRegistroMedico arrArchivo[100];

    stRegistroMedico *arrDinamico = NULL;

    int validos = 0;
    int cantArchivo = 0;
    int cantDinamico = 0;

    char nombreDoctor[30];
    char especialidad[30];

    while(control != 'n')
    {
        menu();
        opcion = pedirNum("\nIngrese un valor:");
        switch(opcion)
        {
        case 1:
            validos = cargarRegistros(arr,100);
            break;
        case 2:
            mostrarRegistros(arr,validos);
            break;
        case 3:
            cargarArchivo(archivo);
            break;
        case 4:
            mostrarArchivo(archivo);
            break;
        case 5:
            cantArchivo = pasarDeArchiToArr(archivo,arrArchivo,100);
            mostrarRegistrosRecu(arrArchivo,cantArchivo,0);
            break;
        case 6:
            cantArchivo = pasarDeArchiToArr(archivo,arrArchivo,100);
            printf("\nTotal: %.2f",sumarAtencionesRecu(arrArchivo,cantArchivo,0));
            break;
        case 7:
            cantArchivo = pasarDeArchiToArr(archivo,arrArchivo,100);
            pasarDeArrToArchivo(arrArchivo,cantArchivo,"precio.dat");
            break;
        case 8:
            printf("\nIngrese doctor: ");
            scanf("%s",nombreDoctor);
            mostrarRegistrosDeUnDok(archivo,nombreDoctor);
            break;
        case 9:
            printf("\nIngrese especialidad: ");
            scanf("%s",especialidad);
            printf("\nPorcentaje: %.2f%%",promedioDeEspecialidad(archivo,especialidad));
            break;

        case 10:
            cantDinamico = crearArrDinDeEspecialidad(archivo,&arrDinamico);
            mostrarRegistros(arrDinamico,cantDinamico);
            free(arrDinamico);
            arrDinamico = NULL;
            break;
        case 0:
            control = 'n';
            printf("\nSaliendo.....");
            break;
        default:
            printf("\nIngrese un valor valido");
        }


        if(control != 'n')
        {
            control = seguir("\nDesea seguir en el programa 's/n':");
        }
    }
    return 0;
}
