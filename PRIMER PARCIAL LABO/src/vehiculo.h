#ifndef VEHICULO_H_
#define VEHICULO_H_

#include "utn.h"

//ESTADO ABM
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define TAM_COLOR 11
#define TAM_DESCRIP 31

typedef struct
{
	int idTipo;
	char descripcion[TAM_CHAR];
}eTipo;

typedef struct
{
	int idVehiculo;
	char descripcion[TAM_CHAR];
	int anioFabricacion; //modelo
	char color[TAM_COLOR];
	int tipoId;
	int isEmpty;
}eVehiculo;

int eVehiculo_getID(void);
void eVehiculo_inicializarlista(eVehiculo lista[], int TAM);
int eVehiculo_obtenerIndexLibre(eVehiculo lista[], int TAM);
int eVehiculo_buscarPorID(eVehiculo lista[], int TAM, int ID);
eVehiculo eVehiculo_ingresarDatos(void);
eVehiculo eVehiculo_modificarUno(eVehiculo vehiculo);
void eVehiculo_imprimirUno(eVehiculo vehiculo);
int eVehiculo_imprimirTodos(eVehiculo lista[], int TAM);
int eVehiculo_alta(eVehiculo lista[], int TAM);
int eVehiculo_baja(eVehiculo lista[], int TAM);
int eVehiculo_modificar(eVehiculo lista[], int TAM);
int eVehiculo_sort(eVehiculo lista[], int TAM);
void eVehiculo_listarTipo(void);
int eVehiculo_buscarPorTipo(eVehiculo lista[], int TAM, int idTipo);
int eVehiculo_imprimirPorTipo(eVehiculo lista[], int TAM);
int eVehiculo_establecerTipo(int idTipo, char* tipoDescripcion);

#endif /* VEHICULO_H_ */
