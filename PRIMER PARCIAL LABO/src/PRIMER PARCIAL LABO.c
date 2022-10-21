#include <stdio.h>
#include <stdlib.h>
#include "nexo.h"

#define TAM_LISTA 100

int main(void)
{
	setbuf(stdout, NULL);

	int opcion;
	int opcionInforme;
	int flagAlta = 0;
	int salir;
	eVehiculo listaVehiculos[TAM_LISTA];
	eHoja listaHojas[TAM_LISTA];
	eVehiculo_inicializarlista(listaVehiculos, TAM_LISTA);
	eHoja_inicializarlista(listaHojas, TAM_LISTA);

	do
	{
		printf("\nMENU DE OPCIONES\n\n"
			   "1. ALTA VEHICULO\n"
			   "2. MODIFICAR VEHICULO\n"
			   "3. BAJA VEHICULO\n"
			   "4. LISTAR VEHICULO\n"
			   "5. LISTAR TIPOS DE VEHICULO\n"
			   "6. ALTA HOJA DE SERVICIO\n"
			   "7. LISTAR HOJA DE SERVICIO\n"
			   "8. INFORMES\n"
			   "9. SALIR \n\n");
		utn_getNumero("INGRESE LA OPCION: ", "ERROR. ", 1, 9, 3, &opcion);

		switch(opcion)
		{
			case 1:
				eVehiculo_alta(listaVehiculos, TAM_LISTA);
				flagAlta = 1;
			break;

			case 2:
				if(flagAlta == 1)
				{
					eVehiculo_modificar(listaVehiculos, TAM_LISTA);
				}
				else
				{
					printf("\nNO ES POSIBLE MODIFICAR SIN HABER DADO DE ALTA UN VEHICULO PRIMERO.\n");
				}
			break;

			case 3:
				if(flagAlta == 1)
				{
					eVehiculo_baja(listaVehiculos, TAM_LISTA);
				}
				else
				{
					printf("\nNO ES POSIBLE DAR DE BAJA SIN HABER DADO DE ALTA UN VEHICULO PRIMERO.\n");
				}
			break;

			case 4:
				if(flagAlta == 1)
				{
					eVehiculo_sort(listaVehiculos, TAM_LISTA);
					eVehiculo_imprimirTodos(listaVehiculos, TAM_LISTA);
				}
				else
				{
					printf("\nNO ES POSIBLE IMPRIMIR SIN HABER DADO DE ALTA UN VEHICULO PRIMERO.\n");
				}
			break;

			case 5:
				eVehiculo_listarTipo();
			break;

			case 6:
				if(flagAlta == 1)
				{
					nexo_alta(listaVehiculos, TAM_LISTA, listaHojas, TAM_LISTA);
				}
				else
				{
					printf("\nNO ES POSIBLE ACTIVAR UNA HOJA DE SERVICIO SIN HABER DADO DE ALTA UN VEHICULO PRIMERO.\n");
				}
			break;

			case 7:
				eHoja_imprimirTodos(listaHojas, TAM_LISTA);
			break;

			case 8:
				if(flagAlta == 1)
				{
					//informe tres sumar todos los precios que van a cierto destino
					printf("\nINFORMES\n"
						   "1. MOSTRAR VIAJES DE UN TIPO SELECCIONADO\n"
						   "2. MOSTRAR TODOS LOS VOUCHERS EFECTUADOS EN UNA FECHA RELACIONADA.\n"
						   "3. INFORMAR IMPORTE TOTAL DE LOS VIAJES REALIZADOS A UN CIERTO DESTINO\n"
						   "4. INFORMAR IMPORTE TOTAL DE TODOS LOS VOUCHERS DE UN TIPO EN UNA FECHA SELECCIONADA\n\n");
					utn_getNumero("SELECCIONE EL INFORME QUE DESEA VER: ", "ERROR. ", 1, 4, 3, &opcionInforme);

					switch(opcionInforme)
					{
						case 1:
							eVehiculo_imprimirPorTipo(listaVehiculos, TAM_LISTA);
						break;

						case 2:
							eHoja_imprimirPorFecha(listaHojas, TAM_LISTA);
						break;

						case 3:
							nexo_imprimirImportePorVehiculo(listaVehiculos, TAM_LISTA, listaHojas, TAM_LISTA);
						break;

						case 4:
							nexo_imprimirImportePorTipoFecha(listaVehiculos, TAM_LISTA, listaHojas, TAM_LISTA);
						break;
					}
				}
			break;

			case 9:
				salir = funcionContinuar("\nDESEA SALIR? (s/n): ", "ERROR. ");
			break;
		}

	}while(salir != 1);

	return 0;
}
