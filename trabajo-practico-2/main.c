#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "library.h"
#include "ArrayEmployee.h"
#define CANT_EMPLEADOS 1000

int main()
{
    Empleado empleados[CANT_EMPLEADOS];
    int opcion;
    int id;
    int indiceVacio;
    int bandera=0;
    int salir=0;
    cargarDatosVacio(empleados,CANT_EMPLEADOS);
    do
    {
        system("cls");
        fflush(stdin);
        if(chequearIndice(empleados,CANT_EMPLEADOS) == -1)
        {
            bandera = 1;
        }
        else
        {
            bandera = 0;
        }
        getEntero(&opcion,3,"1)Cargar empleados:\n2)Modificar datos de empleados\n3)Baja de empleados\n4)Mostrar lista de empleados ordenada\n5)Calcular total, promedio y cuantos empleados superan el salario promedio\n6)Salir\n","\nError\n",6,0);
        switch(opcion)
        {
                case 1:
                    if(indicesVacios(empleados,CANT_EMPLEADOS,&indiceVacio)==0)
                    {
                        cargarIndice(empleados,indiceVacio,CANT_EMPLEADOS);
                        break;
                    }
                    else
                    {
                        printf("\nNo hay indice.\n");
                    }
                    break;
                case 2:
                    if(bandera == 1)
                    {
                        if(getEntero(&id,2,"\nIngrese el ID a modificar: ","Error", CANT_EMPLEADOS,-1) == 0)
                        {
                            if(id >=0)
                            {
                                modificarID(empleados,id,CANT_EMPLEADOS);
                            }
                            else
                            {
                                printf("\nError, indice invalido.\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 3:
                    if(bandera == 1)
                    {
                        if(getEntero(&id,2,"\nIngrese el ID para borrar: ", "Error", CANT_EMPLEADOS, -1) == 0)
                        {
                            if(id >=0)
                            {
                                borrarPantallaPorID(empleados,id,CANT_EMPLEADOS);
                            }
                            else
                            {
                                printf("\nError, indice invalido.\n");
                            }
                        }
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 4:
                    if(bandera == 1)
                    {
                        mostrarEmpleadosOrdenados(empleados,CANT_EMPLEADOS);
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 5:
                    if(bandera == 1)
                    {
                        calcularTotalPromedioSalarios(empleados,CANT_EMPLEADOS);
                    }
                    else
                    {
                        printf("\nNo hay datos cargados\n");
                    }
                    system("pause");
                    break;
                case 6:
                salir = 1;
        }
    }while(salir==0);
    return 0;
}
