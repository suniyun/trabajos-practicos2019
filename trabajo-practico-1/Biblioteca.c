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
    else
    {
    division = primerNumero / segundoNumero;
    }
    
    return division;
}

float factorear1 (float primerNumero)
{
    int resultado1;
    
    do{
        primerNumero = (int) primerNumero;
        resultado = primerNumero * factorear1(primerNumero - 1);
        
    }while (primerNumero > 0);
    
    return resultado1;
}

