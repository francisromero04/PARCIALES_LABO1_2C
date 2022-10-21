#include "hojaServicio.h"

int eHoja_getID(void)
{
	///INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION sProducts_getID();
	static int idIncremental = 20000; //20k
	static int rtn;

	rtn = idIncremental++;

	return rtn;
}

void eHoja_inicializarlista(eHoja lista[], int TAM)
{
	int i;

	if (lista != NULL && TAM > 0)
	{
		for (i = 0; i < TAM; i++)
		{
			lista[i].isEmpty = LIBRE;
		}
	}
}

int eHoja_obtenerIndexLibre(eHoja lista[], int TAM)
{
	int rtn = -1;
	int i;

	///SI EXISTE EL lista Y EL LIMITE ES VALIDO
	if (lista != NULL && TAM > 0)
	{
		//RECORRO EL lista
		for (i = 0; i < TAM; i++)
		{
			///PREGUNTA POR EL ESTADO "LIBRE"
			if (lista[i].isEmpty == LIBRE)
			{
				///OBTIENE EL PRIMER INDEX DEL VECTOR "LIBRE" Y SALGO
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}

int eHoja_buscarPorID(eHoja lista[], int TAM, int ID)
{
	int rtn = -1;
	int i;

	///SI EXISTE EL lista Y EL LIMITE ES VALIDO
	if (lista != NULL && TAM > 0)
	{
		///RECORRE EL lista
		for (i = 0; i < TAM; i++)
		{
			///BUSCO QUE ESTE "OCUPADO" Y QUE CONCIDA EL ID QUE ESTOY BUSCANDO
			if (lista[i].idHoja == ID && lista[i].isEmpty == OCUPADO)
			{
				///SI ENCONTRO EL ID
				///DEVUELVE EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = i;
				break;
			}
		}
	}

	return rtn;
}

eHoja eHoja_ingresarDatos(void)
{
	eHoja auxiliar;

	utn_getString("INGRESE DESCRIPCION DE LA HOJA DE SERVICIO: ", "ERROR. ", 3, TAM_CHAR, auxiliar.descripcion);
	utn_getNumero("INGRESE PRECIO DEL SERVICIO: ", "ERROR. ", 1, 999999, 3, &auxiliar.precioServicio);
	//fecha
	printf("\nFECHA DE VUELO\n");
	utn_getNumero("INGRESE DIA DE VUELO: ", "ERROR. ", 1, 31, 3, &auxiliar.fechaVuelo.day);
	utn_getNumero("INGRESE MES DE VUELO: ", "ERROR. ", 1, 31, 3, &auxiliar.fechaVuelo.month);
	utn_getNumero("INGRESE AÑO DE VUELO: ", "ERROR. ", 1, 2025, 3, &auxiliar.fechaVuelo.year);

	return auxiliar;
}

void eHoja_imprimirUno(eHoja voucher)
{
	printf("|%4d|%-15s|%-10d|", voucher.idHoja, voucher.descripcion, voucher.precioServicio);
	printf("%2d/%1d/%4d|\n",voucher.fechaVuelo.day, voucher.fechaVuelo.month, voucher.fechaVuelo.year);
}

int eHoja_imprimirTodos(eHoja lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && TAM > 0)
	{
		puts("\n\t\t LISTA DE HOJAS DE SERVICIO");
		puts("+------------------------------------------+");
		puts("|  ID |  DESCRIPCION  |  PRECIO  |  FECHA  |");
		puts("+------------------------------------------+");

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == OCUPADO)
			{
				eHoja_imprimirUno(lista[i]);
				puts("+------------------------------------------+");
				cantidad++;
			}
		}
	}

	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}

int eHoja_imprimirPorFecha(eHoja lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int dia, mes, anio;

	if (lista != NULL && TAM > 0)
	{
		puts("");
		utn_getNumero("INGRESE DIA EN EL QUE SE REALIZO EL SERVICIO: ", "ERROR. ", 1, 31, 3, &dia);
		utn_getNumero("INGRESE MES EN EL QUE SE REALIZO EL SERVICIO: ", "ERROR. ", 1, 12, 3, &mes);
		utn_getNumero("INGRESE AÑO EN EL QUE SE REALIZO EL SERVICIO (2022-2023): ", "ERROR. ", 2022, 2023, 3, &anio);

		puts("\n\t\t LISTA DE VOUCHERS");
		puts("+------------------------------------------+");
		puts("|  ID |  DESCRIPCION  |  PRECIO  |  FECHA  |");
		puts("+------------------------------------------+");

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == OCUPADO)
			{
				if(lista[i].fechaVuelo.day == dia && lista[i].fechaVuelo.month == mes && lista[i].fechaVuelo.year == anio)
				{
					eHoja_imprimirUno(lista[i]);
					puts("+------------------------------------------+");
					cantidad++;
				}
			}
		}
	}

	if (cantidad > 0)
	{
		rtn = 1;
	}

	return rtn;
}

int eHoja_acumularPrecio(eHoja lista[], int TAM, int* precioAcumulado)
{
	int rtn = -1;
	int acumuladorPrecio = 0;

	if (lista != NULL && TAM > 0)
	{
		for (int i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == OCUPADO)
			{
				acumuladorPrecio += lista[i].precioServicio;
				rtn = 1;
			}
		}
	}

	*precioAcumulado = acumuladorPrecio;

	return rtn;
}

int eHoja_acumularPrecioPorID(eHoja lista[], int TAM, int* precioAcumulado, int ID)
{
	int rtn = -1;
	int acumuladorPrecio = 0;

	if (lista != NULL && TAM > 0)
	{
		for (int i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == OCUPADO && lista[i].fk_idVehiculo == ID)
			{
				acumuladorPrecio += lista[i].precioServicio;
				rtn = 1;
			}
		}
	}

	*precioAcumulado = acumuladorPrecio;

	return rtn;
}
