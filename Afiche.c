#include <stdio.h>
#include <stdlib.h>
#include "Afiche.h"
#include "Cliente.h"
#include "utn.h"
#include <string.h>
#define COBRADO 0
#define A_COBRAR 1
#define TRUE 1
#define FALSE 0


static int pedirDatosCliente(eCliente* arrayCli,int lenClientes);

int inicializarAfiche(eAfiche* arrayAfi,int len)
{
    int i;
    int retorno=-1;
    if(arrayAfi!=NULL && len>0)
    {
        for(i=0;i<len;i++)
        {
            arrayAfi[i].isEmpty=TRUE;
            retorno=0;
        }
    }
    return retorno;
}

int buscarLugarlibreAfiche(eAfiche* arrayAfi,int len)
{
    int i;
    int retornoIndice=-1;
    for(i=0;i<len;i++)
    {
        if(arrayAfi[i].isEmpty==TRUE)
        {
            retornoIndice=i;
            break;
        }
    }
    return retornoIndice;
}

static int pedirDatosCliente(eCliente* arrayCli,int lenClientes)
{
    int retorno=-1;
    int i;
    int idAux;

    if(utn_getInt(idAux,"Ingrese el ID del cliente que realiza la compra","ERROR ID INVALIDO",0,lenClientes+1,2)==0)
    {
        retorno=idAux;
    }
    return retorno;
}

int altaAfiche(eAfiche* arrayAfi,int indice,int tamanio,eCliente* arrayCli,int lenCli)
{
    int retorno=-1;
    int auxCuit;
    char auxNombre[30];
    char auxZona[20];

    if(indice>=0 && indice<tamanio)
    {
            if(pedirDatosCliente(arrayCli,lenCli)!=-1)
                printf("\nIngrese El Nombre del archivo de imagen");
                scanf("%s",auxNombre);
                if(isLetras(auxNombre)==0)
                {
                    printf("\nIngrese La zona (zona oeste - zona sur - CABA)");
                    scanf("%s",auxZona);
                    if(isLetras(auxZona)==0)
                    {
                        strcpy(arrayAfi[indice].nombre_del_archivo,auxNombre);
                        strcpy(arrayAfi[indice].zona,auxZona);
                        arrayAfi[indice].estado_afiche=A_COBRAR;
                        arrayAfi[indice].id=generarID();
                        arrayAfi[indice].isEmpty=FALSE;
                        arrayCli[indice].id_afiche=arrayAfi->id;

                        retorno=0;
                    }
                }

        }


    return retorno;

}
