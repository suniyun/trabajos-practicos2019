#ifndef LIBRARY_H_INCLUDED
#define LIBRARY_H_INCLUDED

int getEntero(int* pNum,int reint,char* msg,char* msgError,int maximo,int minimo);
int getNumeroDecimal(float *pNum, int reint, char* msg, char* msgError,float maximo,float minimo);
int getString(char* pBufferString,int limite);

#endif //LIBRARY_H_INCLUDED
