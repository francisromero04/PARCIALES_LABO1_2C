#ifndef HOJASERVICIO_H_
#define HOJASERVICIO_H_

#include "utn.h"

//ESTADO ABM
#define LIBRE 0
#define OCUPADO 1
#define BAJA -1
#define TAM_COLOR 11
#define TAM_DESCRIP 31

typedef struct
{
	int day;
	int month;
	int year;
}eFecha;

typedef struct
{
	int idHoja;
	int fk_idVehiculo;
	char descripcion[TAM_CHAR];
	int precioServicio;
	eFecha fechaVuelo;
	int isEmpty;
}eHoja;

int eHoja_getID(void);
void eHoja_inicializarlista(eHoja lista[], int TAM);
int eHoja_obtenerIndexLibre(eHoja lista[], int TAM);
int eHoja_buscarPorID(eHoja lista[], int TAM, int ID);
eHoja eHoja_ingresarDatos(void);
eHoja eHoja_modificarUno(eHoja hoja);
void eHoja_imprimirUno(eHoja hoja);
int eHoja_imprimirTodos(eHoja lista[], int TAM);
int eHoja_alta(eHoja lista[], int TAM);
int eHoja_baja(eHoja lista[], int TAM);
int eHoja_modificar(eHoja lista[], int TAM);
int eHoja_imprimirPorFecha(eHoja lista[], int TAM);
int eHoja_acumularPrecio(eHoja lista[], int TAM, int* precioAcumulado);
int eHoja_acumularPrecioPorID(eHoja lista[], int TAM, int* precioAcumulado, int ID);

#endif /* HOJASERVICIO_H_ */
