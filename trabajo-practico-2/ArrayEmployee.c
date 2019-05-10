#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployee.h"
#include "library.h"

static int generarID(void);
/**
    cargarDatosVacio: Carga un valor en el mismo campo de todas las posiciones del array recibido.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int cargarDatosVacio(Empleado* pEmpleados, int limite)
{
    int i;
    for(i=0;i<limite;i++)
    {
        pEmpleados[i].isEmpty=-1;
    }
    return 0;
}
/**
    cargarIndice: carga valores en la posicion del array recibido.
    \param pEmpleado: Guarda el array recibido.
    \param indice: Guarda el int de la posicion del array.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int cargarIndice(Empleado* pEmpleados,int indice,int limite)
{
    char auxNombre[32];
    char auxApellido[32];
    int auxSector;
    float auxSalario;
    printf("Nombre:\n");
    if(getString(auxNombre,32)==0)
    {

                printf("Apellido: \n");
                if(getString(auxApellido,128)==0)
                {
                    if(getEntero(&auxSector,2,"Sector: \n", "\nError\n",6,0) == 0)
                    {
                        if(getNumeroDecimal(&auxSalario, 2, "Salario: \n", "\nError\n",15000,0)== 0)
                        {
                                strncpy(pEmpleados[indice].nombre,auxNombre,32);
                                strncpy(pEmpleados[indice].apellido,auxApellido,128);
                                pEmpleados[indice].sector = auxSector;
                                pEmpleados[indice].salario = auxSalario;
                                pEmpleados[indice].isEmpty = 0;
                                pEmpleados[indice].ID = generarID();
                        }
                    }
                }

    }
    return 0;
}
/**
    indicesVacios: Busca dentro del array hasta encontrar un indice vacio donde cargar un dato.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \param indiceVacio: Guarda el indice de la posicion vacia del array.
    \return return 0 OK, -1 Error.
*/
int indicesVacios(Empleado* pEmpleados,int limite,int* indiceVacio)
{
    int i = 0;
    int retorno = -1;
    while(i < limite)
    {
        if(pEmpleados[i].isEmpty == -1)
        {
            *indiceVacio = i;
            retorno = 0;
            break;
        }
        i++;
    }
    return retorno;
}
/**
    generarID: Genera un ID. Comienza en -1 para ir generando IDs desde el 0 en adelante.
    \param cont: Contador.
    \return return cont + 1.
*/
static int generarID(void)
{
    static int cont = -1;
    return ++cont;
}
/**
    buscarPantallaPorID: Recibe un ID para buscar un empleado.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \param id: Guarda el int del empleado a buscar.
    \return return el indice del array donde esta el empleado.
*/
int buscarPantallaPorID(Empleado* pEmpleados, int limite, int id)
{
    int i;
    int retorno = -1;
    for(i = 0; i < limite; i++)
    {
        if(pEmpleados[i].isEmpty == 0 && pEmpleados[i].ID == id)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}
/**
    modificarIndice: Recibe un ID para modificar una posicion del array.
    \param pEmpleado: Guarda el array recibido.
    \param id: Guarda el int recibido del ID a modificar.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int modificarID(Empleado* pEmpleados, int indice, int limite)
{
    char auxNombre[51];
    char auxApellido[51];
    int auxSector;
    float auxSalario;
    int id;
    int opciones;
    int salir=0;
    id = buscarPantallaPorID(pEmpleados,limite,indice);
    if(id >= 0)
    {
        if(pEmpleados != NULL && limite >0)
        {
            do
            {
                system("cls");
                fflush(stdin);
                getEntero(&opciones,4,"1)Modificar nombre del empleado:\n2)Modificar apellido del empleado:\n3)Modificar sector del empleado\n4)Modificar salario del empleado\n5)Salir\n","\nError\n",6,0);
                switch(opciones)
                {
                        case 1:
                            printf("Nuevo nombre:\n");
                            if(getString(auxNombre,51)==0)
                            {
                                 strncpy(pEmpleados[indice].nombre,auxNombre,51);
                            }
                            break;
                        case 2:
                             printf("Nuevo apellido: \n");
                            if(getString(auxApellido,128)==0)
                            {
                                strncpy(pEmpleados[indice].apellido,auxApellido,51);
                            }
                            break;
                        case 3:
                            if(getEntero(&auxSector,2,"Nuevo sector: \n", "\nError\n",4,0) == 0)
                            {
                                pEmpleados[indice].sector = auxSector;
                            }
                            break;
                        case 4:
                            if(getNumeroDecimal(&auxSalario,2,"Nuevo salario: \n","\nError\n",15000,0) == 0)
                            {
                                pEmpleados[indice].salario = auxSalario;
                            }
                            system("pause");
                            break;
                        case 5:
                        salir = 1;
                }
            }while(salir==0);
        }
    }
    return 0;
}
/**
    borrarPantallaPorID: Recibe un ID para borrar un empleado.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \param id: Guarda el int del empleado a borrar.
    \return return 0 OK, -1 Error.
*/
int borrarPantallaPorID(Empleado* pEmpleados, int id, int limite)
{
    int retorno = -1;
    int i;
    for(i = 0; i < limite; i++)
    {
        if(pEmpleados[i].isEmpty == 0 && pEmpleados[i].ID == id)
        {
            pEmpleados[i].isEmpty = -1;
            retorno = 0;
            break;
        }
    }
    return retorno;
}
/**
    chequearIndice: Recibe el array para chequear si esta cargado o no.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int chequearIndice(Empleado* pEmpleados,int limite)
{
    int i=0;
    int retorno = 0;
    if(pEmpleados != NULL && limite > 0)
    {
         while(i<limite)
        {
            if(pEmpleados[i].isEmpty==0)
            {
                retorno = -1;
                break;
            }
            i++;
        }
    }

    return retorno;
}
/**
    mostrarEmpleadosOrdenados: Muestra los datos ordenados alfabeticamente y por sector de
    todas las posiciones del array.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int mostrarEmpleadosOrdenados(Empleado* pEmpleados,int limite)
{
    int retorno=-1;
    int i;
    if(pEmpleados != NULL && limite > 0)
    {
        if(ordenarApellidos(pEmpleados, limite) == 0 && ordenarSectores(pEmpleados, limite) == 0)
        {
            for(i=0;i<limite;i++)
            {
                if(pEmpleados[i].isEmpty==0)
                {
                    printf("\nEl nombre del empleado es: %s", pEmpleados[i].nombre);
                    printf("\nEl apellido del empleado es: %s", pEmpleados[i].apellido);
                    printf("\nEl sector del empleado es: %d", pEmpleados[i].sector);
                    printf("\nEl salario del empleado es: %.2f\n", pEmpleados[i].salario);
                    printf("El ID del empleado es: %d\n", pEmpleados[i].ID);
                    retorno=0;
                }
            }
        }
    }

    return retorno;
}
/**
    ordenarApellidos: Recibe el array y lo ordena alfabeticamente usando el metodo Insertion.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int ordenarApellidos(Empleado* pEmpleados, int limite)
{
    int retorno = -1;
    int i;
    int j;
    int auxID;
    int auxSector;
    float auxSalario;
    char auxNombre[51];
    char auxApellido[51];
    if(pEmpleados != NULL && limite > 0)
    {
        for(i=0; i < limite; i++)
        {
            if(pEmpleados[i].isEmpty == 0)
            {
                strcpy(auxNombre, pEmpleados[i].nombre);
                strcpy(auxApellido, pEmpleados[i].apellido);
                auxSector = pEmpleados[i].sector;
                auxSalario = pEmpleados[i].salario;
                auxID = pEmpleados[i].ID;
                j = i-1;
                while(j>=0 && strcmp(auxApellido, pEmpleados[j].apellido)<0)
                {
                    pEmpleados[j+1] = pEmpleados[j];
                    j--;
                }
                strcpy(pEmpleados[j+1].nombre, auxNombre);
                strcpy(pEmpleados[j+1].apellido, auxApellido);
                pEmpleados[j+1].sector = auxSector;
                pEmpleados[j+1].salario = auxSalario;
                pEmpleados[j+1].ID = auxID;
            }
        retorno = 0;
        }
    }
    return retorno;
}
/**
    ordenarSectores: Recibe el array y lo ordena por sectores usando el metodo Insertion.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int ordenarSectores(Empleado* pEmpleados, int limite)
{
    int retorno = -1;
    int i;
    int j;
    int auxID;
    int auxSector;
    float auxSalario;
    char auxNombre[51];
    char auxApellido[51];
    if(pEmpleados != NULL && limite > 0)
    {
        for(i=0; i < limite; i++)
        {
            if(pEmpleados[i].isEmpty == 0)
            {
                strcpy(auxNombre, pEmpleados[i].nombre);
                strcpy(auxApellido, pEmpleados[i].apellido);
                auxSector = pEmpleados[i].sector;
                auxSalario = pEmpleados[i].salario;
                auxID = pEmpleados[i].ID;
                j = i-1;
                while(j>=0 && auxSector < pEmpleados[j].sector)
                {
                    pEmpleados[j+1] = pEmpleados[j];
                    j--;
                }
                strcpy(pEmpleados[j+1].nombre, auxNombre);
                strcpy(pEmpleados[j+1].apellido, auxApellido);
                pEmpleados[j+1].sector = auxSector;
                pEmpleados[j+1].salario = auxSalario;
                pEmpleados[j+1].ID = auxID;
            }
        retorno = 0;
        }
    }
    return retorno;
}
/**
    calcularTotalPromedioSalarios: Recibe el array y realiza las operaciones de los salarios
    pedidas por el ejercicio.
    \param pEmpleado: Guarda el array recibido.
    \param limite: Guarda el int del limite del array.
    \return return 0 OK, -1 Error.
*/
int calcularTotalPromedioSalarios(Empleado* pEmpleados, int limite)
{
    int retorno = -1;
    int i;
    int bandera = 0;
    float acumuladorEmpleados = 0;
    float cantSalarios = 0;
    float promedio;
    int cantMayorSalario =0;
    if(pEmpleados != NULL && limite > 0)
    {
        for(i = 0; i < limite; i++)
        {
            if(pEmpleados[i].isEmpty == 0)
            {
                acumuladorEmpleados += pEmpleados[i].salario;
                cantSalarios++;
            }
        }

        promedio = acumuladorEmpleados / cantSalarios;

        for(i = 0; i < limite; i++)
        {
            if(pEmpleados[i].isEmpty == 0 && pEmpleados[i].salario > promedio)
            {
                cantMayorSalario++;
                bandera = 1;
            }
        }
        retorno = 0;
    }
    if(cantSalarios > 0)
    {
        printf("El total de los salarios es: %.2f", acumuladorEmpleados);
        printf(" y el promedio es: %.2f\n", promedio);
    }
    if(bandera == 1)
    {
        printf("La cantidad de salarios que superan el promedio es de: %d\n", cantMayorSalario);
    }else
    {
        printf("\nNingun salario supera al promedio\n");
    }
    return retorno;

}
