#include <stdio.h>
#include <stdlib.h>
#include "Afiche.h"
#include "Cliente.h"
#include "utn.h"
#include <string.h>
#define CANT_AFICHES 20   //***CAMBIAR ESTO ******
#define CANT_CLIENTES 10 //***CAMBIAR ESTO ******

int main()
{
    eCliente clientes[CANT_CLIENTES];
    eAfiche afiches[CANT_AFICHES];

    inicializarCliente(clientes,CANT_CLIENTES);
    inicializarAfiche(afiches,CANT_AFICHES);

    int opcionMenu,indiceLibre,indiceCambio,indiceAux,idBaja;


    do
    {
        printf("\n1 - ALTA DE CLIENTE\n");
        printf("\n2 - MODIFICAR DATOS DE CLIENTE\n");
        printf("\n3 - BAJA DE CLIENTE\n");
        printf("\n4 - VENDER AFICHES\n");
        printf("\n5 - EDITAR VENTA\n");
        printf("\n6 - COBRAR VENTA\n");
        printf("\n7 - IMPRIMIR CLIENTES\n");
        printf("\n\n8 - SALIR\n\n");

        scanf("\n\n%d",&opcionMenu);

        switch(opcionMenu)
        {
            case 1:
                    indiceLibre=buscarLugarlibreCliente(clientes,CANT_CLIENTES);
                    if(altaCliente(clientes,indiceLibre,CANT_CLIENTES)==0)
                        printf("\nALTA EXITOSA");
                    break;

            case 2:
                    mostrarClientes(clientes,CANT_CLIENTES);
                    utn_getInt(&indiceAux,"\n\nIngrese el id del cliente a modificar","Error id invalido",0,CANT_CLIENTES+1,2);
                    indiceCambio=buscarClientePorId(clientes,CANT_CLIENTES,indiceAux);
                    printf("%d",indiceCambio);
                    modificarCliente(clientes,CANT_CLIENTES,indiceCambio);

                    break;

            case 3:
                    mostrarClientes(clientes,CANT_CLIENTES);
                    utn_getInt(&idBaja,"\n\nIngrese el id a dar de baja " , "ERROR ID INVALIDO",0,CANT_CLIENTES+1,2);
                    if(idBaja!=-1)
                        if(bajaDeCliente(clientes,idBaja,CANT_CLIENTES)==0)
                            printf("BAJA EXITOSA");
                        else
                        {
                            printf("ERROR - NO SE PUDO REALIZAR LA BAJA");
                        }

                     break;


            case 4:
                    indiceLibre=buscarLugarlibreAfiche(afiches,CANT_AFICHES);
                    if(altaAfiche(afiches,indiceLibre,CANT_AFICHES,clientes,CANT_CLIENTES)==0)
                        printf("\nVenta EXITOSA");
                    break;


                     break;

            case 5:

                    break;

            case 6:

                    break;

            case 7:

                     break;


            case 8:

                     break;
            default:
                    printf("ERROR - INGRESE UNA OPCION VALIDA");
        }
    }while(opcionMenu!=8);

    return 0;
}
