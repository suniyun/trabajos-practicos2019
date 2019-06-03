#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

int library_getNombre(char* pNombre, char* msg, char* msgError);
int library_getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
int library_getEnteroSinLimites(int* pNum, int reint, char* msg, char* msgError);
int library_getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
int library_getString(char* pBufferString,int limite);
int isInt(char* pBuffer);
int isIntConGuiones(char* pBuffer);
int isLetra(char* pBuffer);

#endif // LIBRARY_H_INCLUDED
