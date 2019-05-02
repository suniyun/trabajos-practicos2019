#include <stdio.h>
#include <stdlib.h>
#include "Biblioteca.h"

int main()
{
    int opcion;
    float primerNumero;
    float segundoNumero;
    float valorSuma;
    float valorResta;
    float valorMultiplicacion;
    float valorDivision;
    float valorFactoreo1;
    float valorFactoreo2;

    do
    {
        printf("Calculadora \n");

        printf(" 1) Ingrese su primer numero: \n");
        printf(" 2) Ingrese el segundo numero: \n");

        printf("------------------------------------------------------- \n");

        printf(" 3) Operaciones: \n ");
        printf("Nota: Se mostraran los resultados de todas las operaciones disponibles. \n");

        printf("1. Suma \n");
        printf("2. Resta \n");
        printf("3. Multiplicacion \n");
        printf("4. Division \n");
        printf("5. Factoreo \n");

        printf("------------------------------------------------------- \n");

        printf(" 4) Mostrar resultados. \n");

        printf(" 5) Salir. \n");

        opcion = ingresarEntero();

        switch(opcion)
        {
          case 1:

              primerNumero = ingresarFloat();
              printf("Su primer numero ingresado es: %.2f \n", primerNumero);

            break;
          case 2:

              segundoNumero = ingresarFloat();
              printf("Su segundo numero ingresado es: %.2f \n", segundoNumero);

            break;
          case 3:

              printf("------------------------------------------------ \n");
              printf("La calculadora esta trabajando... \n");
              valorSuma = sumar(primerNumero, segundoNumero);
              valorResta = restar(primerNumero, segundoNumero);
              valorMultiplicacion = multiplicar(primerNumero, segundoNumero);
              valorDivision = dividir(primerNumero, segundoNumero);
              valorFactoreo1 = factorear1(primerNumero);
              valorFactoreo2 = factorear1(segundoNumero);

            break;
          case 4:

            printf("--------------------------------------------------- \n");
            printf("Los resultados son: \n");
            printf("1. Suma = %.2f + %.2f = %.2f \n", primerNumero, segundoNumero, valorSuma);
            printf("2. Resta = %.2f - %.2f = %.2f \n", primerNumero, segundoNumero, valorResta);
            printf("3. Multiplicacion = %.2f * %.2f = %.2f \n", primerNumero, segundoNumero, valorMultiplicacion);
            printf("4. Division = %.2f / %.2f = %.2f \n", primerNumero, segundoNumero, valorDivision);
            printf("5. Factorial de %.2f = %.2f y el factorial de %.2f = %.2f \n", primerNumero, valorFactoreo1, segundoNumero, valorFactoreo2);

            break;
          case 5:

            opcion = 5;

            break;
          default:

            printf("Ingrese una opcion valida.");

            system("pause");

            break;
        }
        system("pause");
        system("cls");
    }

    while (opcion != 5);

    return 0;
}
