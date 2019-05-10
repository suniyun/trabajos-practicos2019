#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"

static int getInt(int* pResultado);
static int getFloat(float* pResultado);
static int isFloat(char* pBuffer);
static int isInt(char* pBuffer);

int getString(char* pBufferString,int limite)
{
    fflush(stdin);
    fgets(pBufferString,limite,stdin);
    if(pBufferString[strlen(pBufferString)-1]=='\n')
    {
        pBufferString[strlen(pBufferString)-1]='\0';
    }
    return 0;
}
int getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo)
{
    int auxiliarNum;
    int retorno = -1;
    for(;reint>0;reint--)
    {
        printf(msg);
        if(getInt(&auxiliarNum) == 0)
        {
            if(auxiliarNum > minimo && auxiliarNum < maximo)
            {
                *pNum = auxiliarNum;
                retorno = 0;
                break;

            }else
            {
                printf(msgError);
            }


        }else
        {
            printf(msgError);
        }
    }


    return retorno;
}
int getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo)
{
    float buffer;
    int retorno = -1;

    if(pNum != NULL && msg != NULL && msgError !=NULL && minimo<=maximo && reint >= 0)
    {

        do
        {
            reint--;
            printf("%s",msg);
            if(getFloat(&buffer) == 0 &&
                buffer <= maximo && buffer >= minimo )
            {
                    *pNum = buffer;
                    retorno = 0;
                    break;

            }else
            {
                printf("%s",msgError);
                fflush(stdin);
            }


        }while(reint >= 0);

    }

    return retorno;
}
static int getInt(int* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(getString(bufferString,4096) == 0 && isInt(bufferString)==0)
        {

            *pResultado=atof(bufferString);
            retorno=0;

        }
    }
    return retorno;
}
static int getFloat(float* pResultado)
{
    int retorno=-1;
    char bufferString[4096];
    if(pResultado != NULL)
    {
        if(getString(bufferString,4096) == 0 && isFloat(bufferString)==0)
        {

            *pResultado=atof(bufferString);
            retorno=0;

        }
    }
    return retorno;
}
static int isFloat(char* pBuffer)
{
    int i=0;
    int retorno=0;
    int contadorPuntos=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i]=='.' && contadorPuntos==0)
        {
            contadorPuntos++;
            i++;
        }
        if((pBuffer[i] < '0' || pBuffer[i] > '9'))
        {

            retorno=-1;
            break;
        }
        i++;
    }

    if(contadorPuntos > 2)
    {
        retorno=-1;
    }

    return retorno;
}
static int isInt(char* pBuffer)
{
    int i=0;
    int retorno=0;
    while(pBuffer[i] != '\0')
    {
        if(pBuffer[i] < '0' || pBuffer[i] > '9')
        {
            retorno=-1;
            break;
        }
        i++;
    }
    return retorno;
}
