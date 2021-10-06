
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Validaciones.h"

#define tam 1000

int main(void) {

	int opcion;
	int idAux;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;

	int flagAddEmpleados;

	Employee listaEmpleados[];

	do {
		printf("1- ALTA Producto\n"
				"2-BAJA Producto\n"
				"3-MODIFICACIÓN Producto\n"
				"4-LISTADO Productos\n"
				"5-LISTADO ordenado por precio\n"
				"6-LISTADO ordenado por descripción\n"
				"7-SALIR\n");

		opcion = PedirEntero("Ingrese la opcion: ");

		switch (opcion) {
		case 1:

			idAux =	 rand() % 1001;
			nameAux = PedirString("Ingrese Nombre : ");
			lastNameAux = PedirString("Ingrese Apellido : ");
			salaryAux = PedirFloat("Ingrese el Salario : ");
			sectorAux = PedirEntero("Ingrese Sector : ");

			flagAddEmpleados = addEmployee (listaEmpleados , tam, idAux, nameAux,
					lastNameAux, salaryAux , sectorAux);

			break;
		case 2:

			break;
		case 3:

			break;
		case 4:

			break;
		case 5:

		case 6:

			break;

		case 7:

			break;
		}

	} while (opcion != 7);

	return EXIT_SUCCESS;
}
