#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    int id;
    int cuit;
    char nombre[20];
    char apellido[20];
    int id_afiche;
    int isEmpty;

}eCliente;

int inicializarCliente(eCliente* arrayCli,int len);
int buscarLugarlibreCliente(eCliente* arrayCli,int len);
int altaCliente(eCliente* arrayCli,int indice,int tamanio);
int modificarCliente(eCliente* arrayCli,int tamanio,int indice);
int buscarClientePorId(eCliente* arrayCli,int tamanio,int id);
int bajaDeCliente(eCliente* arrayCli,int id,int len);
void mostrarClientes(eCliente* arrayCli,int len);
#endif // CLIENTE_H_INCLUDED
