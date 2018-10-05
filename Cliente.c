#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "Afiche.h"
#include "Cliente.h"
#include "utn.h"
#include <string.h>
#define TRUE 1
#define FALSE 0

int inicializarCliente(eCliente* arrayCli,int len)
{
    int i;
    int retorno=-1;
    if(arrayCli!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            arrayCli[i].isEmpty=TRUE;
            retorno=0;
        }
    }
    return retorno;
}

int buscarLugarlibreCliente(eCliente* arrayCli,int len)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<len;i++)
    {
        if(arrayCli[i].isEmpty==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}

int altaCliente(eCliente* arrayCli,int indice,int tamanio)
{
    int retorno=-1;
    int auxCuit;
    char auxNombre[20];
    char auxApellido[20];

    if(indice>=0 && indice<tamanio)
    {
            printf("Ingrese el cuit");
            scanf("\n%d",&auxCuit);

            printf("\nIngrese El Nombre");
            scanf("%s",auxNombre);
            if(isLetras(auxNombre)==0)
              {
                printf("\nIngrese El Apellido");
                scanf("%s",auxApellido);
                if(isLetras(auxApellido)==0)
                   {
                        strcpy(arrayCli[indice].nombre,auxNombre);
                        strcpy(arrayCli[indice].apellido,auxApellido);
                        arrayCli[indice].cuit=auxCuit;
                        arrayCli[indice].id=generarID();
                        arrayCli[indice].isEmpty=FALSE;

                        retorno=0;
                    }
                }

        }


    return retorno;

}

int buscarClientePorId(eCliente* arrayCli,int tamanio,int id)
{
    int i;
    int retorno=-1;
    for(i=0;i<tamanio;i++)
    {
        if(arrayCli[i].isEmpty==FALSE && arrayCli[i].id==id)
        {
            retorno=i;
            break;
        }
    }
    return retorno;
}


int modificarCliente(eCliente* arrayCli,int tamanio,int indice)
 {
     int retorno=-1;
     int opcion;
     char nombreAuxiliar[50];
     char apellidoAuxiliar[50];
     int auxiliarCuit;

     if (indice>=0 && indice<tamanio)
        {
            if(utn_getInt(&opcion,"\nIngrese:\n1 para modificar nombre\n2 para modificar direccion\n3 para modificar precio\n4 para modificar tipo\n","\Error, ingrese opcion valida\n",1,4,3)==0)
                {
                    switch(opcion)
                    {
                        case 1:
                                if(utn_getLetra(nombreAuxiliar,50,3,"\nIngrese nuevo nombre\n","\nError, nombre no valido")==0)
                                {
                                    strncpy(arrayCli[indice].nombre,nombreAuxiliar,50);
                                    retorno=0;
                                }
                            break;

                        case 2:
                                if(utn_getLetra(apellidoAuxiliar,50,3,"\n ingrese nuevo apellido\n","error - apellido invalido")==0)
                                {
                                    strncpy(arrayCli[indice].apellido,apellidoAuxiliar,50);
                                    retorno=0;
                                }
                            break;

                        case 3:
                                if(utn_getInt(&auxiliarCuit,"\nIngrese nuevo cuit\n","\nError cuit no valido\n",0,10000000,3)==0)
                                {
                                    arrayCli[indice].cuit=auxiliarCuit;
                                    retorno=0;
                                }
                            break;

                        default:
                                printf("Ingrese una opcion correcta");

                    }
                }
        }

     return retorno;
 }

 int bajaDeCliente(eCliente* arrayCli,int id,int len)
{
    int i=0;
    int retorno=-1;
    if(arrayCli!=NULL && id>=0)
        {
            for (i=0;i<len;i++)
                {
                    if(arrayCli[i].id==id)
                        {
                            arrayCli[i].isEmpty=TRUE;
                            retorno=0;
                            break;
                        }
                }
        }
        return retorno;
}

void mostrarClientes(eCliente* arrayCli,int len)
{
    int i;
   if(arrayCli!=NULL&&len>0)
    {
        for(i=0;i<len;i++)
        {
            if(arrayCli[i].isEmpty==FALSE)
                {
                    printf("\n\nNOMBRE:%s \nAPELLIDO:%s \nCUIT:%d \n ID:%d \nISEMPTY:%d \n\n",arrayCli[i].nombre,arrayCli[i].apellido,arrayCli[i].cuit,arrayCli[i].id,arrayCli[i].isEmpty);
                }
        }
    }
}
