#ifndef NEXO_H_
#define NEXO_H_

#include "vehiculo.h"
#include "hojaServicio.h"

int nexo_alta(eVehiculo listaVehiculos[], int TAM_VEHICULOS, eHoja listaHojas[], int TAM_HOJAS);
int nexo_imprimirImportePorVehiculo(eVehiculo listaVehiculo[], int TAM_VEHICULO, eHoja listaHoja[], int TAM_HOJA);
int nexo_imprimirImportePorTipoFecha(eVehiculo listaVehiculo[], int TAM_VEHICULO, eHoja listaHoja[], int TAM_HOJAS);

#endif /* NEXO_H_ */
