#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED

struct S_empleado{
int ID;
char nombre[51];
int sector;
char apellido[51];
float salario;
int isEmpty;
}typedef Empleado;

int cargarDatosVacio(Empleado* pEmpleados,int limite);
int cargarIndice(Empleado* pEmpleados,int indice,int limite);
int indicesVacios(Empleado* pEmpleados,int limite,int* indiceVacio);
int buscarPantallaPorID(Empleado* pEmpleados, int limite, int id);
int modificarID(Empleado* pEmpleados, int indice, int limite);
int borrarPantallaPorID(Empleado* pEmpleados, int id, int limite);
int chequearIndice(Empleado* pEmpleados,int limite);
int calcularTotalPromedioSalarios(Empleado* pEmpleados, int limite);
int mostrarEmpleadosOrdenados(Empleado* pEmpleados,int limite);
int ordenarApellidos(Empleado* pEmpleados, int limite);
int ordenarSectores(Empleado* pEmpleados, int limite);

#endif //ARRAYEMPLOYEE_H_INCLUDED


