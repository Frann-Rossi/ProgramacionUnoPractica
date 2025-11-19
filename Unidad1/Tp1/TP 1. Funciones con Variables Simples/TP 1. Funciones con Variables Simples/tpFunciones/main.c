#include <stdio.h>
#include <stdlib.h>

// ----- Prototipado ----- //
int retornarUnRandom();
int retornarMenor(int num1, int num2, int num3);
int retornarMayor(int num1, int num2, int num3);
void mostrarMayorYMenor(int num1, int num2, int num3);
int sumaEnterosPositivos(int num);
void tablaDeMultiplicar(int numero);
float suma(float num1, float num2);
float resta(float num1, float num2);
float multiplicacion(float num1, float num2);
float division(float num1, float num2);
void solicitar_operacion();
void cambiarNumANegativo(int *numero);
void cargarNumeros(int *num1, int *num2);
void cargarNumeros(int *num1, int *num2) ;

int main()
{
    /// Ejercicio 1 //
    int numRandom = retornarUnRandom();
    printf("El numero random obtenido fue: %i\n", numRandom);

    /// Ejercicio 2 //
    int numero1, numero2, numero3;

    printf("Ingrese el primer numero: ");
    fflush(stdin);
    scanf("%i", &numero1);

    printf("Ingrese el segundo numero: ");
    fflush(stdin);
    scanf("%i", &numero2);

    printf("Ingrese el tercer numero: ");
    fflush(stdin);
    scanf("%i", &numero3);

    mostrarMayorYMenor(numero1, numero2, numero3);

    /// Ejercicio 3 //
    int num, resultado;

    printf("Ingrese un numero entero para calcular la sumatoria: ");
    fflush(stdin);
    scanf("%i", &num);

    resultado = sumaEnterosPositivos(num);

    printf("La suma de los numeros enteros positivos menores que %i es: %i\n", num, resultado);

    /// Ejercicio 4 //
    int numero;

    printf("Ingrese un numero entero a multiplicar: ");
    fflush(stdin);
    scanf("%i", &numero);

    tablaDeMultiplicar(numero);

    /// Ejercicio 5 //
    solicitar_operacion();

    /// Ejercicio 6 //
    int numerito;

    printf("Ingrese un número positivo entero: ");
    fflush(stdin);
    scanf("%i", &numerito);

    cambiarNumANegativo(&numerito);

    printf("El numero negativo es: %i\n", numerito);

    /// Ejercicio 7 //
    int elemento1, elemento2;

    cargarNumeros(&elemento1, &elemento2);

    printf("Los numeros ingresados son: %i y %i\n", elemento1, elemento2);


    return 0;
}


///1. Desarrollar una función que devuelva un valor RANDOM en el rango de 0 a 100.

int retornarUnRandom(){
    srand(time(NULL));
    int random = rand()%100;

    return random;
}

///2. Diseñe una función que reciba 3 números enteros y muestre el mayor y el menor.

int retornarMenor(int num1, int num2, int num3) {
    if (num1 < num2 && num1 < num3) {
        return num1;
    } else if (num2 < num1 && num2 < num3) {
        return num2;
    } else {
        return num3;
    }
}

int retornarMayor(int num1, int num2, int num3) {
    if (num1 > num2 && num1 > num3) {
        return num1;
    } else if (num2 > num1 && num2 > num3) {
        return num2;
    } else {
        return num3;
    }
}

void mostrarMayorYMenor(int num1, int num2, int num3) {
    int mayor = retornarMayor(num1, num2, num3);
    int menor = retornarMenor(num1, num2, num3);

    printf("El mayor es: %i\n", mayor);
    printf("El menor es: %i\n", menor);
}


///3.Diseñe una función que reciba un número entero N y realice la suma de los números enteros positivos menores que N y lo retorne.
///N es un  dato ingresado por el usuario en el main.

int sumaEnterosPositivos(int num) {
    int suma = 0;

    for (int i = 1; i < num; i++) {
            suma += i;
    }

    return suma;
}


///4. Desarrollar una función que muestre la tabla de multiplicar de un número entero recibido por parámetro

void tablaDeMultiplicar(int numero) {
    printf("Tabla de multiplicar del %i:\n", numero);

    for (int i = 1; i <= 10; i++) {
        printf("%i x %i = %i\n", numero, i, numero * i);
    }
}


///5. Realice una pequeña calculadora, utilizando funciones (una función de suma, una de multiplicación, una de resta, una de división…)

float suma(float num1, float num2) {
    return num1 + num2;
}

float resta(float num1, float num2) {
    return num1 - num2;
}

float multiplicacion(float num1, float num2) {
    return num1 * num2;
}

float division(float num1, float num2) {
    if (num2 != 0) {
        return num1 / num2;
    } else {
        printf("Error: no se puede dividir por cero.\n");
        return 0;
    }
}

void solicitar_operacion() {
    float num1, num2;
    int opcion;

    printf("\nPor favor, seleccione la operación deseada:\n");
    printf("1. Suma (+)\n");
    printf("2. Resta (-)\n");
    printf("3. Multiplicación (*)\n");
    printf("4. División (/)\n");

    printf("Ingrese el número de la operación: ");
    fflush(stdin);
    scanf("%i", &opcion);

    printf("Ingrese el primer número: ");
    scanf("%f", &num1);

    printf("Ingrese el segundo número: ");
    scanf("%f", &num2);

    switch (opcion) {
        case 1:
            printf("El resultado de la suma es: %.2f\n", suma(num1, num2));
            break;
        case 2:
            printf("El resultado de la resta es: %.2f\n", resta(num1, num2));
            break;
        case 3:
            printf("El resultado de la multiplicación es: %.2f\n", multiplicacion(num1, num2));
            break;
        case 4:
            printf("El resultado de la división es: %.2f\n", division(num1, num2));
            break;
        default:
            printf("Opción no válida.\n");
    }
}


///6. Realizar una función que reciba un número positivo entero por parámetro por referencia, y cambie su signo a negativo.

void cambiarNumANegativo(int *numero) {
    if (*numero > 0) {
        *numero = *numero * (-1);
    } else {
        printf("El número ya es negativo.\n");
    }
}


///7. Realizar una función que reciba dos números enteros por parámetro por referencia y cargue sus valores el usuario dentro de la función

void cargarNumeros(int *num1, int *num2) {
    printf("Ingrese el primer número entero: ");
    fflush(stdin);
    scanf("%i", num1);

    printf("Ingrese el segundo número entero: ");
    fflush(stdin);
    scanf("%i", num2);
}
