#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "Library.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = 0;
    FILE* pFile;
    pFile = fopen(path,"r");
    if(parser_EmployeeFromText(pFile , pArrayListEmployee) == 0)
    {
        printf("Se cargaron los datos correctamente.");
        retorno = 0;
    }
    else
    {
        printf("No se pudieron cargar los datos.");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno=-1;
    FILE* pFile;
    pFile = fopen(path, "rb");
    if(pFile != NULL && parser_EmployeeFromBinary(pFile, pArrayListEmployee) == 0)
    {
        printf("Se cargaron los datos correctamente.");
        retorno = 0;
    }
    else
    {
        printf("No se pudieron cargar los datos.");
    }
    fclose(pFile);
    return retorno;
}

/** \brief Alta de empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

    int retorno = -1;
    if(employee_cargarEmployee(pArrayListEmployee) == 0)
    {
        printf("El nuevo empleado ha sido agregado correctamente.");
        retorno = 0;
    }
    else
    {
        printf("El nuevo empleado no ha podido ser agregado correctamente.");
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_modificarEmployee(pArrayListEmployee) == 0)
    {
        printf("El empleado se ha modificado exitosamente.");
        retorno = 0;
    }
    else
    {
        printf("El empleado no ha podido ser modificado correctamente.");
    }
    return retorno;
}

/** \brief Baja de empleado
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno =- 1;
    if(employee_borrarEmployee(pArrayListEmployee) == 0)
    {
        printf("El empleado se ha borrado correctamente.");
        retorno=0;
    }
    else
    {
        printf("El empleado no se ha podido borrar correctamente.");
    }
    return retorno;
}

/** \brief Listar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    employee_mostrarEmployee(pArrayListEmployee);
    return 1;
}

/** \brief Ordenar empleados
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(pArrayListEmployee != NULL)
    {
        ll_sort(pArrayListEmployee,employee_ordenarPorNombre,1);
        printf("Los empleados han sido ordenados exitosamente.");
        retorno = 0;
    }
    else
    {
        printf("Los empleados no han podido ser ordenados como corresponde.");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosenTexto(pArrayListEmployee, path) == 0)
    {
        printf("Los datos han sido guardados correctamente.");
        retorno = 0;
    }
    else
    {
        printf("Los datos no se han guardaron, intente nuevamente.");
    }
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    if(employee_guardarDatosenBinario(pArrayListEmployee, path)==0)
    {
        printf("Los datos han sido guardados correctamente.");
        retorno = 0;
    }
    else
    {
        printf("Los datos no se han guardado, intente nuevamente.");
    }
    return retorno;
}

