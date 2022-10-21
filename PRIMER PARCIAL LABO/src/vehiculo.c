#include "vehiculo.h"

int eVehiculo_getID(void)
{
	///INICIALIZADO UNA UNICA VEZ AL COMIENZO DEL PROGRAMA CON ALCANCE UNICAMENTE EN FUNCION sProducts_getID();
	static int idIncremental = 100;
	static int rtn;

	rtn = idIncremental++;

	return rtn;
}

void eVehiculo_inicializarlista(eVehiculo lista[], int TAM)
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

int eVehiculo_obtenerIndexLibre(eVehiculo lista[], int TAM)
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

int eVehiculo_buscarPorID(eVehiculo lista[], int TAM, int ID)
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
			if (lista[i].idVehiculo == ID && lista[i].isEmpty == OCUPADO)
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

int eVehiculo_buscarPorTipo(eVehiculo lista[], int TAM, int idTipo)
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
			if (lista[i].tipoId == idTipo && lista[i].isEmpty == OCUPADO)
			{
				///SI ENCONTRO EL ID
				///DEVUELVE EL INDEX DE DONDE ESTA EL ID BUSCADO Y SALGO
				rtn = idTipo;
				break;
			}
		}
	}

	return rtn;
}

eVehiculo eVehiculo_ingresarDatos(void)
{
	eVehiculo auxiliar;
	int opcionTipo;

	utn_getString("\nINGRESE DESCRIPCION DEL VEHICULO: ", "ERROR. ", 3, TAM_DESCRIP, auxiliar.descripcion);
	utn_getNumero("INGRESE AÑO DE FABRICACION DEL VEHICULO (1950-2022): ", "ERROR. ", 1950, 2022, 3, &auxiliar.anioFabricacion);
	utn_getString("INGRESE EL COLOR DEL VEHICULO: ", "ERROR. ", 3, TAM_COLOR, auxiliar.color);
	utn_getNumero("INGRESE TIPO DE VEHICULO: (1. CAMIONETA | 2. SEDAN 3PTAS | 3. SEDAN 5PTAS): ", "ERROR. ", 1, 3, 3, &opcionTipo);

	switch(opcionTipo)
	{
		case 1:
			auxiliar.tipoId = 1;
		break;

		case 2:
			auxiliar.tipoId = 2;
		break;

		case 3:
			auxiliar.tipoId = 3;
		break;
	}

	return auxiliar;
}

void eVehiculo_imprimirUno(eVehiculo vehiculo)
{
	printf("|%4d|%-21s|%-5d|%-13s|", vehiculo.idVehiculo, vehiculo.descripcion, vehiculo.anioFabricacion, vehiculo.color);

	switch(vehiculo.tipoId)
	{
		case 1:
			printf("%-11s|\n", "CAMIONETA");
		break;

		case 2:
			printf("%-11s|\n", "SEDAN 3PTAS");
		break;

		case 3:
			printf("%-11s|\n", "SEDAN 5PTAS");
		break;
	}
}

int eVehiculo_establecerTipo(int idTipo, char* tipoDescripcion)
{
	int rtn = 1;

	if(idTipo > 0 && tipoDescripcion != NULL)
	{
		switch(idTipo)
		{
			case 1:
				strcpy(tipoDescripcion, "CAMIONETA");
			break;

			case 2:
				strcpy(tipoDescripcion, "SEDAN 3PTAS");
			break;

			case 3:
				strcpy(tipoDescripcion, "SEDAN 5PTAS");
			break;
		}

		rtn = 1;
	}

	return rtn;
}


int eVehiculo_imprimirTodos(eVehiculo lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;

	if (lista != NULL && TAM > 0)
	{
		puts("\n\t\t LISTA DE VEHICULOS");
		puts("+----------------------------------------------------------+");
		puts("| ID |     DESCRIPCION     | AÑO |    COLOR    |    TIPO   |");
		puts("+----------------------------------------------------------+");

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == OCUPADO)
			{
				eVehiculo_imprimirUno(lista[i]);
				puts("+----------------------------------------------------------+");
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

int eVehiculo_imprimirPorTipo(eVehiculo lista[], int TAM)
{
	int i;
	int rtn = 0;
	int cantidad = 0;
	int idTipo;
	int idEncontrado;

	if (lista != NULL && TAM > 0)
	{
		utn_getNumero("\nINGRESE EL TIPO REQUERIDO (1. CAMIONETA | 2. SEDAN 3PTAS | 3. SEDAN 5PTAS): ", "ERROR. ", 1, 3, 3, &idTipo);

		puts("\n\t\t LISTA DE VEHICULOS");
		puts("+----------------------------------------------------------+");
		puts("| ID |     DESCRIPCION     | AÑO |    COLOR    |    TIPO   |");
		puts("+----------------------------------------------------------+");

		idEncontrado = eVehiculo_buscarPorTipo(lista, TAM, idTipo);

		for (i = 0; i < TAM; i++)
		{
			if (lista[i].isEmpty == OCUPADO && idEncontrado != -1)
			{
				if(lista[i].tipoId == idTipo)
				{
					eVehiculo_imprimirUno(lista[i]);
					puts("+----------------------------------------------------------+");
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

void eVehiculo_listarTipo(void)
{
	printf("\nTIPOS DE VEHICULO: \n"
		   "1. SEDAN 3PTAS\n"
		   "2. SEDAN 5PTAS\n"
		   "3. CAMIONETA\n");
}

eVehiculo eVehiculo_modificarUno(eVehiculo vehiculo) //usar en nexo
{
	int opcionMenuModificar;

	do
	{
		puts("\nCAMPOS A MODIFICAR:");
		puts("1. DESCRIPCION");
		puts("2. PRECIO DE SERVICIO");
		puts("3. GUARDAR CAMBIOS\n");

		utn_getNumero("INGRESE LA OPCION DEL CAMPO A MODIFICAR: ", "ERROR. ", 1, 3, 1, &opcionMenuModificar);

		switch(opcionMenuModificar)
		{
			case 1:
				if(	utn_getString("\nINGRESE DESCRIPCION DEL VEHICULO: ", "ERROR. ", 3, TAM_DESCRIP, vehiculo.descripcion) )
				{
					puts("EL DESTINO SE HA MODIFICADO.");
				}
			break;

			case 2:
				if( utn_getString("INGRESE EL COLOR DEL VEHICULO: ", "ERROR. ", 3, TAM_COLOR, vehiculo.color) )
				{
					puts("EL COLOR DEL VEHICULO SE HA MODIFICADO.");
				}
			break;

			case 3:
				puts("\nDATOS MODIFICADOS CORRECTAMENTE, CAMBIOS GUARDADOS.");
			break;
		}
	}while(opcionMenuModificar != 3);

	return vehiculo;
}

int eVehiculo_sort(eVehiculo lista[], int TAM)
{
	int rtn = -1; //SI EL ARRAY NO EXISTE Y EL TAM ES INVALIDO
	int i;
	int j;
	eVehiculo aux;


	//SI EXISTE EL ARRAY Y EL TAM ES VALIDO
	if (lista != NULL && TAM > 0)
	{
		for (i = 0; i < TAM - 1; i++)
		{
			for (j = i + 1; j < TAM; j++)
			{
				//PREGUNTO POR ESTADO "OCUPADO" DE AMBOS
				if (lista[i].isEmpty == OCUPADO && lista[j].isEmpty == OCUPADO)
				{
					//SI ID EN LA POSICION DE I ES MAYOR QUE ID EN LA POSICION DE J
					if (lista[i].tipoId > lista[j].tipoId)
					{
						//INTERCAMBIO POSICIONES EN ARRAY
						aux = lista[i];
						lista[i] = lista[j];
						lista[j] = aux;
					}
					else
					{
						//SI AMBAS CADENAS SON IGUALES QUE ORDENE POR ID
						if(lista[i].tipoId == lista[j].tipoId)
						{
							//SI ID EN LA POSICION DE I ES MAYOR QUE ID EN LA POSICION DE J
							if (stricmp(lista[i].descripcion, lista[j].descripcion) > 0)
							{
								//INTERCAMBIO POSICIONES EN ARRAY
								aux = lista[i];
								lista[i] = lista[j];
								lista[j] = aux;
							}
						}
					}
				}
			}
		}

		rtn = 1; ///SI SALIO BIEN RETORNA 1
	}
	return rtn;
}

//-----------------------------------------------------ABM---------------------------------------------------------------

int eVehiculo_alta(eVehiculo lista[], int TAM)
{
	int rtn = -1;
	eVehiculo auxvehiculo;

	///BUSCO ESPACIO EN lista
	int index = eVehiculo_obtenerIndexLibre(lista, TAM);

	///SI INDEX == -1 lista LLENO
	///SI INDEX != -1 TENGO EN INDEX POSICION DE lista LIBRE

	if (index != -1)
	{
		///PIDO DATOS - CARGO Products AUXILIAR
		auxvehiculo = eVehiculo_ingresarDatos();

		///SETEO ID UNICO - VARIABLE ESTATICA AUTOINCREMENTAL
		auxvehiculo.idVehiculo = eVehiculo_getID();

		///CAMBIO SU ESTADO A "OCUPADO"
		auxvehiculo.isEmpty = OCUPADO;

		///SETEO EL lista CON AUXILIAR EN INDEX LIBRE OBTENIDO PREVIAMENTE
		lista[index] = auxvehiculo;

		///RETORNO 1 PARA SABER QUE FUE DADO DE ALTA SATISFACTORIAMENTE
		rtn = index;
	}

	return rtn;
}

int eVehiculo_baja(eVehiculo lista[], int TAM)
{
	int rtn = 0;
	int idProducto;
	int index;
	int flag = 0;

	///LISTO TODOS LOS Products
	if(eVehiculo_imprimirTodos(lista, TAM))
	{
		///BANDERA EN 1 SI HAY Products DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	///SI HAY Products PARA DAR DE BAJA
	if(flag)
	{
		///PIDO ID A DAR DE BAJA
		utn_getNumero("\nINGRESE ID DEL PRODUCTO A DAR DE BAJA: ", "ERROR. ", 100, 1000, 3, &idProducto);

		///BUSCO INDEX POR ID EN lista
		while (eVehiculo_buscarPorID(lista, TAM, idProducto) == -1)
		{
			puts("\nNO EXISTE ID.");

			///PIDO OTRA VEZ ID A DAR DE BAJA
			utn_getNumero("\nINGRESE ID DEL PRODUCTO A DAR DE BAJA: ", "ERROR. ", 100, 1000, 3, &idProducto);
		}

		///OBTENGO INDEX DEL lista DE Products A DAR DE BAJA
		index = eVehiculo_buscarPorID(lista, TAM, idProducto);
		lista[index].isEmpty = BAJA;
		puts("\nSE HA DADO DE BAJA EL PRODUCTO. \n");
		rtn = 1;
	}

	return rtn;
}

int eVehiculo_modificar(eVehiculo lista[], int TAM)
{
	int rtn = 0;
	int idPasajero;
	int index;
	int flag = 0;
	eVehiculo auxiliar;

	///LISTO TODOS LOS Pasajeros
	if(eVehiculo_imprimirTodos(lista, TAM))
	{
		///BANDERA EN 1 SI HAY Pasajeros DADOS DE ALTA PARA LISTAR
		flag = 1;
	}

	///SI HAY Pasajeros PARA MODIFICAR
	if(flag)
	{
		///PIDO ID A MODIFICAR
		utn_getNumero("\nINGRESE ID DEL vehiculo A MODIFICAR: ", "ERROR. ", 100, 1000, 3, &idPasajero);

		///BUSCO INDEX POR ID EN ARRAY
		while(eVehiculo_buscarPorID(lista, TAM, idPasajero) == -1)
		{
			puts("NO EXISTE ID.");
			///PIDO ID A MODIFICAR
			utn_getNumero("\nREINGRESE ID DEL vehiculo A MODIFICAR: ", "ERROR. ", 100, 1000, 3, &idPasajero);
		}

		///OBTENGO INDEX DEL ARRAY DE Pasajeros A MODIFICAR
		index = eVehiculo_buscarPorID(lista, TAM, idPasajero);

		///LLAMO A FUNCION QUE MODIFICA Pasajeros
		auxiliar = eVehiculo_modificarUno(lista[index]);

		///MODIFICACION ACEPTADA
		lista[index] = auxiliar;

		//RETORNO 1 SI SE MODIFICO CORRECTAMENTE
		rtn = 1;
	}

	return rtn;
}
