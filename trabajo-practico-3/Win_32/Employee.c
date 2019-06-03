#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Library.h"
#include <string.h>

static int isValidNombre(char* name);
static int isValidHorasTrabajadas(char* horasTrabajadas);
static int isValidSueldo(char* sueldo);
static int isValidId(char* id);

/**
    employee_new: Crea un nuevo espacio en memoria con una variable de tipo Employee.
    @return Direccion de memoria creada.
*/

Employee* employee_new(void)
{
    return (Employee*) malloc(sizeof(Employee));
}

/**
    employee_newParametros: Crea un nuevo espacio en memoria y setea datos en una variable tipo Employee.
    @param idStr: Es la cadena de caracteres con el id a guardar.
    @param nombreStr: Es la cadena de caracteres con el nombre a guardar.
    @param horasTrabajadasStr: Es la cadena de caracteres con las horas trabajadas a guardar.
    @param sueldoStr: Es la cadena de caracteres con el sueldo a guardar.
    @return Direccion de memoria creada.
*/

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* this = NULL;
    this = employee_new();
    if(this == NULL ||
        employee_setId(this, idStr) ||
        employee_setNombre(this, nombreStr) ||
        employee_setHorasTrabajadas(this, horasTrabajadasStr) ||
        employee_setSueldo(this, sueldoStr))
    {
        employee_delete(this);
        this = NULL;
    }
    return this;
}

/**
    employee_delete: Borra un espacio en memoria.
    @param this: Es el espacio en memoria a borrar.
    @return 0 OK, -1 Error.
*/

int employee_delete(Employee* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_setNombre: Recibe un nombre para guardarlo.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param nombre: Es la cadena de caracteres con el nombre.
    @return 0 OK, -1 Error.
*/

int employee_setNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && isValidNombre(nombre) == 0)
    {
        strcpy(this->nombre,nombre);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getNombre: Recibe una variable tipo Employee donde se buscara un nombre y se devolvera ese nombre.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param nombre: Es una cadena de caracteres donde se guardara el nombre a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getNombre(Employee* this, char* nombre)
{
    int retorno = -1;
    if(this != NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidNombre: Recibe una cadena de caracteres de un nombre para validar que solo sean letras, espacios o guiones.
    @param nombre: Es una cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidNombre(char* nombre)
{
    int retorno = -1;
    if(isLetra(nombre) == -1)
    {
        printf("\nNombre invalido\n");
        printf("\n%s\n", nombre);
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    employee_setHorasTrabajadas: Recibe una cantidad de horas trabajadas para guardarla.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param horasTrabajadas: Es la cadena de caracteres con las horas trabajadas.
    @return 0 OK, -1 Error.
*/

int employee_setHorasTrabajadas(Employee* this, char* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && isValidHorasTrabajadas(horasTrabajadas) == 0)
    {
        this->horasTrabajadas = atoi(horasTrabajadas);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getHorasTrabajadas: Recibe un dato tipo Employee donde se buscara la cantidad de horas trabajadas y se devolvera esa cantidad.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param horasTrabajadas: Es el puntero a un int donde se guardara las horas a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getHorasTrabajadas(Employee* this, int* horasTrabajadas)
{
    int retorno = -1;
    if(this != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = this->horasTrabajadas;
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidHorasTrabajadas: Recibe una cadena de caracteres de horas trabajadas para validar que solo sean numeros.
    @param horasTrabajadas: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidHorasTrabajadas(char* horasTrabajadas)
{
    int retorno = -1;
    if(isInt(horasTrabajadas) == -1)
    {
        printf("\nLas horas trabajadas no son validas\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    employee_setSueldo: Recibe un sueldo para guardarlo.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param sueldo: Es la cadena de caracteres con el sueldo.
    @return 0 OK, -1 Error.
*/

int employee_setSueldo(Employee* this, char* sueldo)
{
    int retorno = -1;
    if(this != NULL && isValidSueldo(sueldo) == 0)
    {
        this->sueldo = atoi(sueldo);
        retorno = 0;
    }
    return retorno;
}

/**
    employee_getSueldo: Recibe un dato tipo Employee donde se buscara un sueldo y se devolvera ese sueldo.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param sueldo: Es el puntero a un int donde se guardara el sueldo a buscar.
    @return 0 OK, -1 Error.
*/

int employee_getSueldo(Employee* this, int* sueldo)
{
    int retorno = -1;
    if(this != NULL && sueldo != NULL)
    {
        *sueldo = this->sueldo;
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidSueldo: Recibe una cadena de caracteres de sueldo para validar que solo sean numeros.
    @param sueldo: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidSueldo(char* sueldo)
{
    int retorno = -1;
    if(isInt(sueldo) == -1)
    {
        printf("\nEl sueldo no es valido\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    employee_setId: Recibe un id para guardarlo.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param id: Es la cadena de caracteres con el id del Employee.
    @return 0 OK, -1 Error.
*/

int employee_setId(Employee* this, char* id)
{
    int retorno = -1;
    static int proximoId = -1;
    int auxID;
    if(this != NULL && isValidId(id) == 0)
    {
        auxID = atoi(id);
        if(auxID == -1)
        {
            proximoId++;
            this->id = proximoId;
            retorno = 0;
        }else if(auxID > proximoId)
        {
            proximoId = auxID;
            this->id = proximoId;
            retorno = 0;
        }
    }
    return retorno;
}

/**
    employee_getId: Recibe un dato tipo Employee donde se buscara un id y se devolvera ese id.
    @param this: Es el espacio en memoria de una variable tipo Employee donde se buscara.
    @param id: Es el puntero a un int donde se guardara el id buscado.
    @return 0 OK, -1 Error.
*/

int employee_getId(Employee* this, int* id)
{
    int retorno = -1;
    if(this != NULL && id != NULL)
    {
        *id = this->id;
        retorno = 0;
    }
    return retorno;
}

/**
    employee_isValidId: Recibe una cadena de caracteres de un id para validar que solo sean numeros.
    @param id: Es la cadena de caracteres a validar.
    @return 0 OK, -1 Error.
*/

static int isValidId(char* id)
{
    int retorno = -1;
    if(isIntConGuiones(id) == -1)
    {
        printf("\nEl id ingresado es invalido.\n");
    }
    else
    {
        retorno = 0;
    }
    return retorno;
}

/**
    employee_mostrarEmployee: Lista todo el contenido del array LinkedList.
    @param arrayLinkedList: Recibe el array a mostrar.
*/

void employee_mostrarEmployee(LinkedList* pArrayListEmployee)
{
    int i;
    int auxId;
    char auxNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    int size;
    size = ll_len(pArrayListEmployee);
    Employee* auxEmployee;
    if(size > 0)
    {
        for(i=0; i < size; i++)
        {
            auxEmployee = ll_get(pArrayListEmployee, i);
            if( employee_getId(auxEmployee, &auxId) == 0 &&
                employee_getNombre(auxEmployee, auxNombre) == 0 &&
                employee_getHorasTrabajadas(auxEmployee, &auxHorasTrabajadas) == 0 &&
                employee_getSueldo(auxEmployee, &auxSueldo) == 0)
            {
                printf("ID: %d - Nombre: %s - Horas Trabajadas: %d - Sueldo: %d \n", auxId, auxNombre, auxHorasTrabajadas, auxSueldo);
            }
            else
            {
                printf("\nNo se pudo mostrar la lista.\n");
            }
        }
         printf("\nLa cantidad de empleados es: %d.", size);
    }
    else
    {
        printf("\nNo se encuentra la lista cargada.\n");
    }
}

/**
    employee_cargarEmployee: Agrega nuevos datos al array LinkedList.
    @param pArrayLinkedList: Recibe el array en el que se cargaran los datos de la variable.
    @return 0 OK, -1 Error.
*/

int employee_cargarEmployee(LinkedList* pArrayEmployee)
{
    int retorno = -1;
    char auxNombre[1024];
    char auxID[1024] = "-1";
    int auxHorasTrabajadas;
    int auxSueldo;
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    Employee* auxPunteroEmployee;
    if( library_getNombre(auxNombre, "\nIngrese el nombre del empleado: \n","\nEl nombre ingresado es invalido\n") == 0 &&
        library_getEnteroSinLimites(&auxHorasTrabajadas, 10, "\nIngrese las horas trabajadas del empleado: \n","\nError, horas de trabajo invalidas\n") == 0 &&
        library_getEnteroSinLimites(&auxSueldo, 10, "\nIngrese el sueldo del empleado: \n","\nError, sueldo invalido\n") == 0)
    {
        itoa(auxHorasTrabajadas, bufferHorasTrabajadas, 10);
        itoa(auxSueldo, bufferSueldo, 10);
        auxPunteroEmployee = employee_newParametros(auxID, auxNombre, bufferHorasTrabajadas, bufferSueldo);
        if(auxPunteroEmployee != NULL)
        {
            ll_add(pArrayEmployee, auxPunteroEmployee);
        }
        retorno=0;
    }
    return retorno;
}

/**
    employee_modificarEmployee: Modifica datos actuales al array LinkedList.
    @param pArrayLinkedList: Recibe el array en el que se modificara los datos de la variable.
    @return 0 OK, -1 Error.
*/

int employee_modificarEmployee(LinkedList* pArrayEmployee)
{
    int retorno = -1;
    int idEmployee;
    int indice;
    char auxNombre[1024];
    int auxHorasTrabajadas;
    int auxSueldo;
    Employee* auxPEmployee;
    if(pArrayEmployee != NULL && library_getEnteroSinLimites(&idEmployee, 10, "\nIngrese el ID del empleado a modificar: \n", "\nEl id ingresado es invalido\n") == 0)
    {
        indice = employee_buscarPorId(pArrayEmployee, idEmployee);
        if(indice >= 0)
        {
            auxPEmployee = ll_get(pArrayEmployee, indice);
            if( library_getNombre(auxNombre, "Ingrese el nuevo nombre del empleado: \n","\nEl nombre ingresado es invalido\n")==0 &&
                library_getEnteroSinLimites(&auxHorasTrabajadas, 10, "\nIngrese la nueva cantidad de horas trabajadas: \n", "\nLas horas de trabajo ingresadas son invalidas\n") == 0 &&
                library_getEnteroSinLimites(&auxSueldo, 10,"\nIngrese el nuevo sueldo: \n", "\nEl sueldo ingresado es invalido\n") == 0)
            {
                auxPEmployee->horasTrabajadas = auxHorasTrabajadas;
                auxPEmployee->sueldo = auxSueldo;
                strcpy(auxPEmployee->nombre, auxNombre);
                retorno = 0;
            }
        }else
        {
            printf("El id ingresado no existe.");
        }
    }
    return retorno;
}

/**
    employee_buscarPorId: Recibe una LinkedList y un int con un Id para encontrar en que posicio esta ese Id o si existe.
    @param pArrayEmployee: Recibe el array a recorrer.
    @param idEmployee: Es el id que se compara con los Id del array hasta encontrar el igual.
    @return Un int con la posicion de un array.
*/

int employee_buscarPorId(LinkedList* pArrayEmployee, int idEmployee)
{
    int retorno = -1;
    int i;
    int limite = ll_len(pArrayEmployee);
    Employee* auxPEmployee;
    if(pArrayEmployee != NULL)
    {
        for(i = 0; i < limite; i++)
        {
            auxPEmployee = (Employee*)ll_get(pArrayEmployee, i);
            if(auxPEmployee != NULL && auxPEmployee->id == idEmployee)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
    employee_borrarEmployee: Borra datos actuales al array LinkedList.
    @param pArrayLinkedList: Recibe el array en el que se borrara el dato.
    @return 0 OK, -1 Error.
*/

int employee_borrarEmployee(LinkedList* pArrayEmployee)
{
    int retorno=-1;
    int idEmployee;
    int id;
    Employee* auxPEmployee;
    if(pArrayEmployee != NULL && library_getEnteroSinLimites(&idEmployee, 10, "Ingrese el ID del empleado a borrar: /n", "El Id ingresado no es valido./n") == 0)
    {
        id = employee_buscarPorId(pArrayEmployee, idEmployee);
        if(id >= 0)
        {
            auxPEmployee = ll_get(pArrayEmployee,id);
            if(employee_delete(auxPEmployee) == 0)
            {
                retorno = 0;
                ll_remove(pArrayEmployee,id);
            }
        }else
        {
            printf("El Id ingresado no existe./n");
        }
    }
    return retorno;
}

/**
    employee_ordenarPorNombre: Utiliza el strcmp para comparar 2 nombres y retorna el valor del strcmp.
    @param thisA: Es el dato uno a comparar.
    @param thisB: Es el dato dos a comparar.
    @return retorno: Valor del strcmp.
*/

int employee_ordenarPorNombre(void* thisA,void* thisB)
{
    int retorno = 0;
    char nombreA[1024];
    char nombreB[1024];
    employee_getNombre((Employee*)thisA,nombreA);
    employee_getNombre((Employee*)thisB,nombreB);
    if(strcmp(nombreA,nombreB) > 0)
    {
        retorno = 1;
    }else if(strcmp(nombreA,nombreB) < 0)
    {
        retorno = -1;
    }
    return retorno;
}

/**
    employee_guardarDatosEnTexto: Guarda los datos del LinkedList en la ruta del archivo recibido en modo texto.
    @param pArrayLinkedList: Recibe el array a guardar.
    @param path: Es el nombre del archivo donde se guardaran los datos.
    @return 0 OK, -1 Error.
*/

int employee_guardarDatosenTexto(LinkedList* pArrayEmployee, char* path)
{
    int retorno = -1;
    int i;
    int size;
    FILE* pFile = fopen(path,"w");
    size = ll_len(pArrayEmployee);
    Employee* auxPEmployee;
    if(pFile != NULL)
    {
        retorno = 0;
        for(i = 0; i < size; i++)
        {
            auxPEmployee = ll_get(pArrayEmployee,i);
            fprintf(pFile, "%d,%s,%d,%d\n", auxPEmployee->id, auxPEmployee->nombre, auxPEmployee->horasTrabajadas, auxPEmployee->sueldo);
        }
    }
    fclose(pFile);
    return retorno;
}

/**
    employee_guardarDatosEnBinario: Guarda los datos del LinkedList en la ruta del archivo recibido en modo binario.
    @param pArrayLinkedList: Recibe el array a guardar.
    @param path: Es el nombre del archivo donde se guardaran los datos.
    @return 0 OK, -1 Error.
*/

int employee_guardarDatosenBinario(LinkedList* pArrayEmployee, char* path)
{
    int retorno = -1;
    FILE* pFile = fopen(path,"wb");
    Employee* auxPEmpleado;
    int i;
    int size = ll_len(pArrayEmployee);
    if(pFile != NULL)
    {
        retorno = 0;
        for(i = 0; i < size; i++)
        {
            auxPEmpleado = ll_get(pArrayEmployee, i);
            fwrite(auxPEmpleado, sizeof(Employee), 1, pFile);
        }
    }
    fclose(pFile);
    return retorno;
}



