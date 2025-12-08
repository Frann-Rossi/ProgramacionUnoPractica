#include <stdio.h>
#include <stdlib.h>

//**************** TRABAJO PRACTICO N° 9 : recursividad ********************************************************************

/*// *********** recursividad con variables simples y arreglos ************

1. Calcular el factorial de un número en forma recursiva.
2. Calcular la potencia de un número en forma recursiva.
3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos en
   forma invertida (recursivo).
5. Determinar en forma recursiva si un arreglo es capicúa.
6. Sumar en forma recursiva los elementos de un arreglo de enteros y retornar el total de la suma.
7. Buscar el menor elemento de un arreglo en forma recursiva.

// ****************** recursiv con archivos *************************************
8. Buscar el menor elemento de un archivo números de enteros.
9. Invertir los elementos de un archivo de números enteros de forma recursiva
   (si no te sale, primero proba con invertir los elementos de un arreglo de int)
10. Recorrer un archivo y mostrar sus elementos en forma invertida de forma recursiva
11. Ingresar valores a una variable de tipo char (por teclado) y mostrarlo en el orden inverso
   (hasta ingresar un ‘*’). NO usar arreglos.
12. Determinar si un arreglo contiene un determinado elemento de forma recursiva.
    (Pueden intentarlo también con una función void)
    (Tener en cuenta para un arreglo desordenado y el caso para un arreglo ordenado)
*/

///*********************** FUNCIONES (el Main está al final) //////////////////////////////////////////////////////////////////

/// ********************** Recursividad con variables simples y arreglos ****************************

/// 1 Calcular el factorial de un número en forma recursiva

int factorialRecursivo (int x) {
    int rta;

    if(x==0){    // corta en 0 en vez de 1 por si quiero calcular factorial de 0
        rta= 1;  //ojo! ver en qué casos 0 o 1- suma 0, multiplic 1
    }
    else {
        rta= x * factorialRecursivo(x-1);
    }
    return rta;
}


int factorialPro(int x){
    return (x==0) ? 1 : x*factorialPro(x-1);
}

/// 2 Calcular la potencia de un número en forma recursiva

int potencia(int x, int factor)
{
    int rta;

    if(factor==0){
        rta= 1; // devuelve 1 y en el camino de vuelta empieza a multiplicarse y acumularse
    }          // 4*1, 4*4, 4*16, 4*68...
    else{
        rta= x * potencia(x,factor-1);
    }
    return rta;
}


/// 3 Recorrer un arreglo y mostrar sus elementos en forma recursiva


void muestraArregloRecursivo1(int A[], int val, int i)
{
    if(i==val){
        printf("\n");
    }
    else {
        printf(" %d  ", A[i]);
        muestraArregloRecursivo1(A, val, i+1);
        // printf(" %d  ", A[i]);  /// ojo! es diferente ponerlo arriba o abajo
    }
}


void muestraArregloRecursivo2(int A[], int val, int i)
{
    if(i==val-1){
        printf(" %d  ", A[i]);
        printf("\n");
    }
    else {
        printf(" %d  ", A[i]);
        muestraArregloRecursivo2(A, val, i+1);
    }
}


void muestraArregloRecursivoSolTrivImplicita(int arreglo[], int validos, int i)
{
// la condición de corte esta implicita, cuando llega al final del arreglo no hace nada
    if(i<validos){
       printf(" %d  ", arreglo[i]);
       muestraArregloRecursivoSolTrivImplicita (arreglo, validos, i+1);
    }
}

/// LA MEJOR DE TODAS: NO NECESITA RECIBIR i POR PARAMETRO!!

int imprimirArregloRecursivoSinContador(int arreglo[], int validos)
{
    if(validos!=0){
        imprimirArregloRecursivoSinContador(arreglo, validos-1);
        printf(" %d  ", arreglo[validos-1]); //imprime en el "camino de vuelta" porque arranca desde atras
    }
}


/// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar sus elementos
/// en forma invertida (recursivo).

void muestraArregloInvertido(int A[], int i, int cant)
{
    if(i==cant-1)
        printf(" %d \n", A[i]);
    else {
        muestraArregloInvertido(A, i+1, cant);
        printf(" %d", A[i]);
    }
}

void muestraArregloInvertidoSinContador(int arreglo[], int validos)
{   // es mejor porq no necesita recibir i por parametro
    if(validos!=0){
        printf("%d ", arreglo[validos-1]);
        muestraArregloInvertidoSinContador(arreglo, validos-1);
    }
}

/// 5 Determinar en forma recursiva si un arreglo es capicúa

// VERSION CON SOL TRIVIAL EXPRESA :

int capicuaSTExpresa (int A[], int i, int validos)
{
    int rta;
    if(i<validos)
    {
        if(A[i] == A[validos-1]){
            rta= capicuaSTExpresa(A,i+1,validos-1);
        }
        else{
            rta= 0;  /// otra sol trivial
        }
    }
    else{
        rta= 1; ///sol trivial: si llegó a que i es = a validos es porque todo era capicua
    }
    return rta;
}


// CON SOL TRIVIAL IMPLICITA (si i no es < u no hace nada)
int capicua(int A[], int i, int validos)
{
    int rta=1;
    if(i<validos)
    {
        if(A[i]==A[validos-1])
        {
            rta=capicua(A,i+1,validos-1);
        }
        else
        {
         rta=0; // en cuanto encuentre un par distinto corta la recursion y devuelve 0
        }
    }
    return rta;
}



/// 6 Sumar en forma recursiva los elementos de un arreglo de enteros

int sumaArrayRecursiva1(int arreglo[], int validos, int i) ///ojo! el i va fuera!!
{
    int suma=0;

    if(i==validos-1){  //ver en qué casos llegar hasta validos o hasta 1 menos que validos
        suma = arreglo[i];
    }
    else{
        suma = arreglo[i] + sumaArrayRecursiva1(arreglo, validos, i+1);
    }

    return suma;
}

int sumaArrayRecursiva2(int arreglo[], int validos, int i) ///ojo! el i va fuera!!
{
    int suma=0;
    if(i==validos){  //ver en qué casos llegar hasta validos o hasta 1 menos que validos
        suma = 0;
    }
    else{
        suma = arreglo[i] + sumaArrayRecursiva2(arreglo, validos, i+1);
    }
    return suma;
}


int sumaArrayRecursivaMejorada (int arr[], int validos)
{   // va de atras hacia adelante para no tener que usar i por parametro
    int rta;
    if(validos==0){
       rta=0;
    }
    else {
        rta= arr[validos-1] + sumaArrayRecursivaMejorada (arr, validos-1);
    }
  return rta;
}


int sumaArregloRecursivoSolTrivImplicita (int a[], int v, int i){
    int suma=0;
    if(i<v){
        suma= a[i] + sumaArregloRecursivoSolTrivImplicita (a,v,i+1);
    }
    return suma;
}


int sumaArregloRecursivoPro(int a[], int v, int i){
    return (i<v) ? a[i]+sumaArregloRecursivoPro(a,v,i+1) : 0;
}



/// 7 Buscar el menor elemento de un arreglo en forma recursiva

int buscarMenorArregloPro (int arr[], int validos)
{
    int menor;
    if (0 == validos-1){
        menor= arr[validos-1]; // cuando llego al final del arreglo, retorno ese valor
    }                 // para comparar con los de las etapas recursivas anteriores
    else {
       menor= buscarMenorArregloPro (arr, validos-1);
       if(menor > arr[validos-1]){   // en esta compara en el camino de vuelta
            menor= arr[validos-1];
       }
    }
 return menor;
}


int buscarMenorArregloSolTrivExpresa (int arr[], int validos, int i)
{
    int menor;

    if (i==validos-1)
    {
        menor= arr[i]; // cuando llego al final del arreglo, retorno ese valor
    }                 // para comparar con los de las etapas recursivas anteriores
    else
    {
       menor= buscarMenorArregloSolTrivExpresa (arr, validos, i+1);
       if(menor > arr[i]){   // en esta compara en el camino de vuelta
            menor= arr[i];
       }
    }
 return menor;
}


int buscarMenorArraySolTrivImplicita(int array[],int validos,int i, int menor){
    if(i<validos){
        if(array[i] <= menor){  // en esta compara en el camino de ida
            menor= array[i];
        }
        menor= buscarMenorArraySolTrivImplicita (array,validos,i+1, menor);
    }
    return menor;
}


int buscaPosicionDelMenorEnArreglo(int Arr[],int Validos,int i,int PosMenor)
{
    if(i<Validos)
    {
        if(Arr[i]<Arr[PosMenor])
        {
            PosMenor= i;

        }
        PosMenor= buscaPosicionDelMenorEnArreglo(Arr,Validos,i+1,PosMenor);
    }
    return PosMenor;
}

/// ********************************** recursiv con archivos ****************************************

/// 8  Buscar el menor elemento de un archivo en forma recursiva

// funcion aux cargar archivos
void Cargar_Archivo(char Nombre[])
{
    FILE* archi=NULL;
    int Numeros=0;
    char control='s';

    archi= fopen(Nombre, "ab");
    if(archi != NULL)
    {
        while (control!='n')
        {
            printf("Ingrese un numero por favor: ");
            scanf("%d",&Numeros);
            fwrite(&Numeros,sizeof(int),1,archi);
            printf("Desea ingresar otro numero al archivo?? ");
            fflush(stdin);
            scanf("%c",&control);
        }
        fclose(archi);
    }
}

// funcion aux mostrar archivos
void Mostrar_Archivo(char Nombre[])
{
    FILE* archi;
    int Numeros= 0;

    archi= fopen(Nombre, "rb");
    if(archi != NULL)
    {
        printf("\n\nContenido del archivo: ");
        while (fread(&Numeros,sizeof(int),1,archi)>0)
        {
            printf(" %d ", Numeros);
        }
        fclose(archi);
    }
}


int buscarMenorArchivoPpalIterativa(char nombreArchivo[]){

     FILE* arch = fopen(nombreArchivo, "rb");
     int menor;

     if(arch!=NULL){
       menor= buscarMenorArchivoAuxRecurs(arch);
       fclose (arch);
     }
     return menor;
}


int buscarMenorArchivoAuxRecurs (FILE* arch){
    int menor;
    int valor;

    //como lee y luego evalua, en cada llamada quedó guardado en valor lo leido
    if(fread(&valor,sizeof(int),1,arch)==0) // COND CORTE: no leyó nada, cuando llego al final del archivo
    {
        fseek(arch, -1*sizeof(int), SEEK_END); // me muevo uno para atras p poder leer
        fread(&menor, sizeof(int),1,arch); // leo el ultimo elemento para retornarlo
    }
    else {
        menor= buscarMenorArchivoAuxRecurs(arch);

        if(menor > valor){
            menor= valor;
        }
    }
    return menor;
}


/// 9  Invertir los elementos de un archivo

// funcion aux de la ppal
int cuentaRegistroArchivo(FILE* arch)
{
    int cant=0;

    fseek(arch, 0, SEEK_END);
    cant= ftell(arch)/sizeof(int);

    return cant;
}

void invertirArchivoPpalIterativa(char nombreArchivo[]){

    FILE* arch = fopen(nombreArchivo, "r+b");

    if(arch){
        int cantidad= cuentaRegistroArchivo(arch);
        invertirArchivoAuxRecurs(arch, cantidad-1, 0);
        fclose(arch);
     }
     else {
        printf("Fallo la apertura del archivo...");
     }
}


void invertirArchivoAuxRecurs(FILE* FP, int posUlt, int posPrim)
{
    int ppio,fin;

    if(posPrim < posUlt) // cond de corte implícita. va invirtiendo en el camino de ida
    {
    // leemos el 1° y el ultimo dato del archivo
            fseek(FP,sizeof(int)*posUlt,0); // posiciono el cursor en el extremo final del archivo
            fread(&fin,sizeof(int),1,FP); // leemos el ultimo dato

            fseek(FP,sizeof(int)*posPrim,0); // posiciono el cursor en el extremo inicial del archivo
            fread(&ppio,sizeof(int),1,FP); // leemos el primer dato
    // y ahora hacemos el intercambio
            fseek(FP,sizeof(int)*posPrim,0);  // posiciono el cursor otra vez en el extremo inicial del archivo
            fwrite(&fin,sizeof(int),1,FP); // guardamos el ultimo al ppio

            fseek(FP,sizeof(int)*posUlt,0); // posiciono el cursor otra vez en el extremo final del archivo
            fwrite(&ppio,sizeof(int),1,FP); // guardamos el 1° al final

            invertirArchivoAuxRecurs(FP, posUlt-1, posPrim+1); // ahora hacemos la llamada recursiva
                                                    // con la aproximacion a la condicion de corte
    }
}


/// otra version

void invertir_archivo(FILE* archi)
{
    int dato;

    if( (fread(&dato,sizeof(int),1,archi)) >0 )
    {
        invertir_archivo(archi);
        fwrite(&dato,sizeof(int),1,archi);
    }
    else
    {
        fseek(archi,0,SEEK_SET);
    }
}


/// 10  Recorrer un archivo y mostrar sus elementos en forma invertida

void muestraArchivoInvertidoPpalIterativa(char nombre[])
{
    FILE* arch= fopen(nombre, "rb");

    if(arch!=NULL){
        printf("\n\nContenido del archivo invertido: ");
        muestraArchivoInvertidoAuxRecursSTExpresa(arch);
        fclose(arch);
    }
    else{
        printf("Houston... tenemos un problema...");
    }
}


void muestraArchivoInvertidoAuxRecursSTExpresa (FILE* arch)
{
    int valor;

    if( (fread(&valor, sizeof(int),1,arch)) ==0 ) { // cond corte explicita: llegué al final del archivo
        printf("\n");   // solucion trivial
    }
    else {
        muestraArchivoInvertidoAuxRecursSTExpresa (arch);    // llamada recursiva
        printf(" %d", valor);   // muestra el elemento cuando vuelve de la recursion..
    }
}


/// otra version, con Sol Trivial Implicita

void muestraArchivoInvertidoAuxRecursSTImplicita (FILE* arch)
{
    int valor;

    if( (fread(&valor, sizeof(int),1,arch)) >0)
    {
        muestraArchivoInvertidoAuxRecursSTImplicita (arch);
        printf(" %d", valor);
    } //no queda explicita la condicion de corte con su solucion final
      // si llegó al final del archivo no hace nada...
}


/// 11. Ingresar valores a una variable (por teclado) y mostrarla
/// en el orden inverso (hasta ingresar un ‘*’). NO usar arreglos.

/// Con condicion de corte explicita

void ingresaPorTecladoYMuestraInvertidoSTE()
{
    char valor;

    printf("\nIngrese un caracter (corta con *): \n");
    fflush(stdin);
    scanf("%c", &valor);

    if(valor == '*')
    {
         printf("\n "); /// O: printf("%c ",valor);
    }
    else
    {
         ingresaPorTecladoYMuestraInvertidoSTE();
         printf("%c  ",valor);
    }
}

/// Con condicion de corte implicita

void ingresaPorTecladoYMuestraInvertidoSTI()
{
    char valor;

    printf("\nIngrese un caracter (corta con *): \n");
    fflush(stdin);
    scanf("%c", &valor);

    if(valor != '*')
    {
        ingresaPorTecladoYMuestraInvertidoSTI();
        printf("%c ",valor);
    }
}


/// 12. Determinar si un arreglo contiene un determinado elemento.
/// la funcion retorna 0 si no lo encuentra, 1 si el elemento esta


int ExisteElementoEnArreglo(int A[], int validos, int i, int valor)
{
    int rta=0; // supongo que el elemento no esta

    if(i<validos)
    {
        if(A[i]==valor)
        {
            rta= 1;
        }
        else
        {
            rta= ExisteElementoEnArreglo(A, validos, i+1, valor);
        }
    }
    return rta;
}


int determinaElementoEnArregloPro(int A[], int validos, int i, int valor)
{
    int rta=0; // supongo que el elemento no esta

    if(i<validos)
    {
        rta = (A[i]==valor) ? 1 : determinaElementoEnArregloPro(A, validos,i+1, valor);
    }
    return rta;
}



/// RECURSIVIDAD INDIRECTA: FUNCION PAR/IMPAR

int impar (int num)
{
    if (num==0)
    {
        return 0;
    }
    else
    {
        return par(num-1);
    }
}

int par (int num)
{
    if (num==0)
    {
        return 1;
    }
    else
    {
        return impar(num-1);
    }
}

/// Evitando el doble return
int imparPro(int num){
    return (num==0)? 0 : parPro(num-1);
}

int parPro(int num){
    return (num==0)? 1 : imparPro(num-1);
}


///*************************************  MAIN *******************************************////////////////////////////////////////////////


int main()
{
    printf("Hello RECURSIVIDAD!\n");

    int arreglo[5]={100,20,30,400,5};

/// Ej 1: factorial

    int factorialRe= factorialRecursivo(5);
    printf("factorial de 5 recursivo: %d \n", factorialRe);
    int factorial3= factorialPro(5);
    printf("factorial de 5 recursivo pro: %d \n\n", factorial3);

/// ej 2: Calcular la potencia de un número en forma recursiva.
    int pot= potencia(2, 3);
    printf("2 al cubo es: %d \n\n", pot);

/// Ej 3. Recorrer un arreglo y mostrar sus elementos en forma recursiva.
    printf("Muestra arreglo en forma recursiva en sus cuatro variantes: \n");
    muestraArregloRecursivo1 (arreglo, 5, 0);
    muestraArregloRecursivo2 (arreglo, 5, 0);
    muestraArregloRecursivoSolTrivImplicita (arreglo, 5, 0);
    printf("\n");
    imprimirArregloRecursivoSinContador(arreglo, 5);
    printf("\n\n");

/// 4. Recorrer un arreglo comenzando desde la posición 0 y mostrar
/// sus elementos en forma invertida (recursivo).
    printf("\nMuestra arreglo en forma recursiva invertido: \n");
    muestraArregloInvertido(arreglo, 0, 5);
    printf("\nMuestra arreglo en forma recursiva invertido otra funcion: \n");
    muestraArregloInvertidoSinContador(arreglo, 5);
    printf("\n\n");

/// 5. Determinar en forma recursiva si un arreglo es capicúa.
    printf("\nDeterminar en forma recursiva si un arreglo es capicua (inicializamos uno que si lo es): \n");
    int arreglo2[5]={1,2,3,2,1};
    int rtaC= capicuaSTExpresa(arreglo2, 0, 5);
    if (rtaC==0)
        printf("\n El arreglo NO es capicua\n");
    else
        printf("\n El arreglo ES capicua\n");

/// 6. Sumar en forma recursiva los elementos de un arreglo de enteros.

    int rta2 = sumaArrayRecursiva1(arreglo, 5, 0);
    printf("suma arreglo recursiva 1 corta en validos -1: %d \n\n\n", rta2);
    int rta3= sumaArrayRecursiva2 (arreglo, 5, 0);
    printf("suma arreglo recursiva 2 corta en validos: %d \n", rta3);
    int rta4= sumaArrayRecursivaMejorada (arreglo, 5);
    printf("suma arreglo recursiva mejorada (no precisa validos por parametro): %d \n", rta4);
    int rta5= sumaArregloRecursivoSolTrivImplicita (arreglo, 5, 0);
    printf("suma arreglo recursiva con solucion trivial implicita: %d \n\n\n", rta5);
    int rta6= sumaArregloRecursivoPro(arreglo, 5, 0);
    printf("suma arreglo recursiva pro: %d \n\n\n", rta6);

/// 7. Buscar el menor elemento de un arreglo en forma recursiva.
    int menorPro= buscarMenorArregloPro(arreglo, 5);
    printf("Menor del arreglo buscado con solucion pro: %d \n", menorPro);

    int posMenor= buscaPosicionDelMenorEnArreglo(arreglo, 5, 0, 0);
    printf("posicion del menor del arreglo: %d \n", posMenor);

    int menor1= buscarMenorArregloSolTrivExpresa(arreglo, 5, 0);
    printf("menor del arreglo funcion con sol trivial expresa: %d \n", menor1);
    int menor2= buscarMenorArraySolTrivImplicita(arreglo, 5, 0, arreglo[0]);
    printf("menor del arreglo funcion sol trivial implicita: %d \n", menor2);

    system("pause");
    system("cls");

/// ************** recursiv con archivos ***************************

/// 8. Buscar el menor elemento de un archivo números de enteros.
    printf("\nCargo un archivo de enteros\n");
    Cargar_Archivo("archivito");
    printf("\nMuestro el archivo de enteros\n");
    Mostrar_Archivo("archivito");
    printf("\n\n");
    int menorA= buscarMenorArchivoPpalIterativa("archivito");
    printf("\nEl menor es %d\n", menorA);

/// 9. Invertir los elementos de un archivo de números enteros.
    invertirArchivoPpalIterativa("archivito");
    printf("\nInvierto archivo...");
    Mostrar_Archivo("archivito");

/// 10.Recorrer un archivo y mostrar sus elementos en forma invertida.
    muestraArchivoInvertidoPpalIterativa("archivito");
    system("pause");
    system("cls");

/// 11. Ingresar valores a una variable (por teclado) y mostrarlo en el orden inverso
/// (hasta ingresar un ‘*’). NO usar arreglos.
    printf("\nIngresar valores a una variable (por teclado) y mostrarlo en el orden inverso (hasta ingresar un '*')\n");
    ingresaPorTecladoYMuestraInvertidoSTI();
    printf("\nIngresar valores a una variable (por teclado) y mostrarlo en el orden inverso (hasta ingresar un '*')\n");
    ingresaPorTecladoYMuestraInvertidoSTE();

/// 12.Determinar si un arreglo contiene un determinado elemento
    int aBuscar3= 20;
    int rta7= ExisteElementoEnArreglo(arreglo, 5, 0, aBuscar3);
    if (rta7==0)
        printf("\n El nro buscado %d NO esta en el arreglo\n", aBuscar3);
    else
        printf("\n El nro buscado %d SI esta en el arreglo\n", aBuscar3);


    return 0;
}
