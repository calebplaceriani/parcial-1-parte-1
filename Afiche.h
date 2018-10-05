#ifndef AFICHE_H_INCLUDED
#define AFICHE_H_INCLUDED
#include "Cliente.h"

typedef struct
{
    int id;
    char nombre_del_archivo[30];
    char zona [20];
    int cantidad_afiches;
    int estado_afiche;
    int isEmpty;

}eAfiche;

int inicializarAfiche(eAfiche* arrayAfi,int len);
int buscarLugarlibreAfiche(eAfiche* arrayAfi,int len);
int altaAfiche(eAfiche* arrayAfi,int indice,int tamanio,eCliente* arrayCli,int lenCli);

#endif // AFICHE_H_INCLUDED
