#include "nexo.h"

int nexo_alta(eVehiculo listaVehiculos[], int TAM_VEHICULOS, eHoja listaHojas[], int TAM_HOJAS)
{
	int rtn = -1;
	int auxId;//id vehiculo a buscar
	eHoja auxHoja;
	int idEncontrado;
	int index;

	if(listaVehiculos != NULL && TAM_VEHICULOS > 0 && listaHojas != NULL && TAM_HOJAS > 0)
	{
		///BUSCO ESPACIO EN lista
		index = eHoja_obtenerIndexLibre(listaHojas, TAM_HOJAS);

		eVehiculo_imprimirTodos(listaVehiculos, TAM_VEHICULOS);
		utn_getNumero("\nPARA HABILITAR UN VOUCHER, SELECCIONE UN VIAJE INGRESANDO SU ID: ", "ERROR. ", 100, 1000, 3, &auxId);
		idEncontrado = eVehiculo_buscarPorID(listaVehiculos, TAM_VEHICULOS, auxId);

		if(idEncontrado == -1)
		{
			puts("\nNO EXISTE ID.");
		}

		if (index != -1 && idEncontrado != -1)  //si tengo posicion de array libre
		{
			///PIDO DATOS - CARGO Products AUXILIAR
			auxHoja = eHoja_ingresarDatos();

			///SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
			auxHoja.idHoja = eHoja_getID();

			///CAMBIO SU ESTADO A "OCUPADO"
			auxHoja.isEmpty = OCUPADO;

			///ASIGNO ID VIAJE EN ESTRUCTURA VOUCHER
			auxHoja.fk_idVehiculo = auxId;

			///SETEO EL lista CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
			listaHojas[index] = auxHoja;

			///RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
			rtn = index;
		}
	}

	return rtn;
}

int nexo_imprimirImportePorVehiculo(eVehiculo listaVehiculo[], int TAM_VEHICULO, eHoja listaHoja[], int TAM_HOJA)
{
	int rtn = -1;
	int precioAcumulado;
	int idABuscar;
	int index;

	if(listaVehiculo != NULL && TAM_VEHICULO > 0 && listaHoja != NULL && TAM_HOJA > 0)
	{
		eVehiculo_imprimirTodos(listaVehiculo, TAM_VEHICULO);
		index =	utn_getNumero("\nINGRESE ID DEL VEHICULO A BUSCAR: ", "ERROR. ", 100, 1000, 3, &idABuscar);

		for(int i = 0; i < TAM_VEHICULO; i++)
		{
			for(int j = 0; j < TAM_HOJA; j++)
			{
				if(index != -1)
				{
					if(listaVehiculo[i].idVehiculo == idABuscar)
					{
						eHoja_acumularPrecioPorID(listaHoja, TAM_HOJA, &precioAcumulado, idABuscar);
						rtn = 1;
					}
				}
				else
				{
					puts("ID NO ENCONTRADO.");
					break;
				}
			}
		}

		printf("\nIMPORTE TOTAL DE LOS SERVICIOS REALIZADOS EN EL VEHICULO %d ES DE $%d\n", index, precioAcumulado);
	}

	return rtn;
}

int nexo_imprimirImportePorTipoFecha(eVehiculo listaVehiculo[], int TAM_VEHICULO, eHoja listaHoja[], int TAM_HOJAS)
{
	int rtn = -1;
	int precioAcumulado;
	int dia, mes, anio;
	int idABuscar;
	int idTipoEcontrado;
	char tipo[TAM_CHAR];

	if(listaVehiculo != NULL && TAM_VEHICULO > 0 && listaHoja != NULL && TAM_HOJAS > 0)
	{
		utn_getNumero("\nINGRESE EL TIPO DE VEHICULO (1. CAMIONETA | 2. SEDAN 3PTAS | 3. SEDAN 5PTAS): ", "ERROR. ", 1, 3, 3, &idABuscar);
		utn_getNumero("INGRESE DIA EN EL QUE SE REALIZO LA HOJA DE SERVICIO: ", "ERROR. ", 1, 31, 3, &dia);
		utn_getNumero("INGRESE MES EN EL QUE SE REALIZO LA HOJA DE SERVICIO: ", "ERROR. ", 1, 12, 3, &mes);
		utn_getNumero("INGRESE EN EL QUE SE REALIZO LA HOJA DE SERVICIO: ", "ERROR. ", 2022, 2025, 3, &anio);

		for(int i = 0; i < TAM_VEHICULO; i++)
		{
			for(int j = 0; j < TAM_HOJAS; j++)
			{
				idTipoEcontrado = eVehiculo_buscarPorTipo(listaVehiculo, TAM_VEHICULO, idABuscar);

				if(idTipoEcontrado != -1)
				{
					if(listaVehiculo[i].tipoId == idTipoEcontrado &&
							listaHoja[j].fechaVuelo.day == dia &&
							listaHoja[j].fechaVuelo.month == mes &&
							listaHoja[j].fechaVuelo.year == anio)
					{
						eHoja_acumularPrecio(listaHoja, TAM_HOJAS, &precioAcumulado);
						eVehiculo_establecerTipo(idTipoEcontrado, tipo);
					}
				}
			}
		}
		printf("\nIMPORTE TOTAL DE LOS VOUCHERS REALIZADOS CON TIPO %s ES DE $%d PLANIFICADO EL %2d/%1d/%4d\n", tipo, precioAcumulado, dia, mes, anio);
		rtn = 1;
	}

	return rtn;
}
