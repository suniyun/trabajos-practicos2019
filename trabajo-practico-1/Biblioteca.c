#include "Biblioteca.h"
#include <stdio.h>
#include <stdlib.h>

int ingresarEntero(void)
{
    int numero;

    printf("Ingrese una opcion: ");
    scanf("%d", &numero);

    return numero;
}

float ingresarFloat(void)
{
    float numero;

    printf("Ingrese un numero: ");
    scanf("%f", &numero);

    return numero;
}

float sumar (float primerNumero, float segundoNumero)
{
    float suma;
    suma = primerNumero + segundoNumero;
    return suma;
}
float restar (float primerNumero, float segundoNumero)
{
    float resta;
    resta = primerNumero - segundoNumero;
    return resta;
}
float multiplicar (float primerNumero, float segundoNumero)
{
    float multiplicacion;
    multiplicacion = primerNumero * segundoNumero;
    return multiplicacion;
}
float dividir (float primerNumero, float segundoNumero)
{
    float division;

    if(segundoNumero == 0)
    {
    printf("No se puede dividir por 0. Ingrese un numero valido. \n");
    }
    division = primerNumero / segundoNumero;
    return division;
}

float factorear1 (float primerNumero)
{
    float factor1;
    float factorial1;
    factor1 = 1;

     if(primerNumero < 0)
    {
        printf("No se puede factorear el primer numero porque es un numero negativo. Ingrese un numero valido. \n");
    }

        for(factorial1 = primerNumero; factorial1 > 0; factorial1--)
            {
                factor1 = factor1 * factorial1;
            }

        return factor1;
}

float factorear2 (float segundoNumero)
{
    float factor2;
    float factorial2;
    factor2 = 1;

     if(segundoNumero < 0)
    {
        printf("No se puede factorear el segundo numero porque es un numero negativo. Ingrese un numero valido. \n");
    }
        for(factorial2 = segundoNumero; factorial2 > 0; factorial2--)
            {
                factor2 = factor2 * factorial2;
            }

        return factor2;
}


