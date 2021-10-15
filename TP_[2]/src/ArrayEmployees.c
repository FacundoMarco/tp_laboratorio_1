#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Validaciones.h"

#define TRUE 1
#define FALSE 0

int InitEmployees(Employee listaEmpleados[], int tam) {
	int FlagInicializacion = -1;

	if (listaEmpleados != NULL && tam > 0) {
		for (int i = 0; i < tam; i++) {
			listaEmpleados[i].isEmpty = TRUE;
			FlagInicializacion = 0;
		}
	}

	return FlagInicializacion;
}

int AddEmployee(Employee listaEmpleados[], int tam, int id, char name[],
		char lastName[], float salary, int sector) {
	int flagCargar = 0;

	for (int i = 0; i < tam; i++) {

		if (listaEmpleados[i].isEmpty == TRUE) {

			listaEmpleados[i].id = id;

			//listaEmpleados[i].name = name;
			strcpy(listaEmpleados[i].name, name);

			strcpy(listaEmpleados[i].lastName, lastName);

			//listaEmpleados[i].lastName = lastName;

			listaEmpleados[i].salary = salary;

			listaEmpleados[i].sector = sector;

			listaEmpleados[i].isEmpty = FALSE;

			flagCargar = 1;
			break;
		}

	}

	return flagCargar;
}

int FindEmployeeById(Employee listaEmpleados[], int tam, int id) {

	int buscarId = 0;
	int i;

	for (i = 0; i < tam; ++i) {
		if (listaEmpleados[i].id == id && listaEmpleados[i].isEmpty == FALSE) {
			buscarId = 1;

			break;
		}

	}

	return buscarId;
}

int RemoveEmployee(Employee listaEmpleados[], int tam, int id) {

	int flagRemover = 0;

	for (int i = 0; i < tam; i++) {

		if (listaEmpleados[i].isEmpty == FALSE && listaEmpleados[i].id == id) {
			listaEmpleados[i].isEmpty = TRUE;
			flagRemover = 1;
			break;
		}

	}
	return flagRemover;

}

int PrintEmployees(Employee listaEmpleados[], int tam) {

	int flagError = 1;

	if (listaEmpleados != NULL && tam > 0) {
		printf("ID		NAME		LASTNAME		SALARY		SECTOR  \n");
		for (int i = 0; i < tam; i++) {

			if (listaEmpleados[i].isEmpty == FALSE) {

				printf("%-15d %-15s %-23s %-15.2f %-15d \n",
						listaEmpleados[i].id, listaEmpleados[i].name,
						listaEmpleados[i].lastName, listaEmpleados[i].salary,
						listaEmpleados[i].sector);
				flagError = 0;

			}

		}

	}

	return flagError;
}

int ModifyEmployee(Employee listaEmpleados[], int tam, int id) {

	int flagModificar = 0;
	int opcion;

	for (int i = 0; i < tam; i++) {

		if (listaEmpleados[i].isEmpty != TRUE && listaEmpleados[i].id == id) {

			do {
				printf(
						"=====================================================\n");
				printf(
						"=====================================================\n");
				printf("1-MODIFICAR NOMBRE. \n"
						"2-MODIFICAR APELLIDO.\n"
						"3-MODIFICAR SECTOR.\n"
						"4-MODIFICAR SALARIO.\n"
						"5-SALIR.\n");
				printf(
						"=====================================================\n");
				printf(
						"=====================================================\n");
				opcion = PedirEntero("INGRESE UNA OPCION: ");
				flagModificar = 1;

				switch (opcion) {
				case 1:
					PedirString("Ingrese Nombre a Modificar :  ",
							listaEmpleados[i].name);
					break;
				case 2:
					PedirString("Ingrese Apellido a Modificar :  ",
							listaEmpleados[i].lastName);
					break;
				case 3:
					listaEmpleados[i].sector = PedirEntero(
							"Ingrese sector a modificar : ");
					break;
				case 4:
					listaEmpleados[i].salary = PedirFloat(
							"Ingrese salario a modificar : ");
					break;
				case 5:
					printf("MODIFICACIONES EXITOSAS. \n");
					break;
				default:
					printf("INGRESE OPCION VALIDA.\n");
					break;
				}
			} while (opcion != 5);

		}

	}
	return flagModificar;
}

int SortEmployees(Employee listaEmpleados[], int tam, int order) {
	int i;
	int j;
	Employee auxiliar;
	int retorno = 0;

	for (i = 0; i < tam; ++i) {

		for (j = 0 + 1; j < tam; ++j) {
			switch (order) {
			case 0: //DOWN
				if (strcmp(listaEmpleados[i].lastName,
						listaEmpleados[j].lastName) > 0) {

					auxiliar = listaEmpleados[i];
					listaEmpleados[i] = listaEmpleados[j];
					listaEmpleados[j] = auxiliar;
					retorno = 1;
				}
				if (strcmp(listaEmpleados[i].lastName,
						listaEmpleados[j].lastName) == 0
						&& listaEmpleados[i].sector
								> listaEmpleados[j].sector) {
					auxiliar = listaEmpleados[i];
					listaEmpleados[i] = listaEmpleados[j];
					listaEmpleados[j] = auxiliar;
					retorno = 1;
				}

				break;
			case 1: //UP
				if (strcmp(listaEmpleados[i].lastName,
						listaEmpleados[j].lastName) < 0) {

					auxiliar = listaEmpleados[i];
					listaEmpleados[i] = listaEmpleados[j];
					listaEmpleados[j] = auxiliar;
					retorno = 1;
				}
				if (strcmp(listaEmpleados[i].lastName,
						listaEmpleados[j].lastName) == 0
						&& listaEmpleados[i].sector
								< listaEmpleados[j].sector) {
					auxiliar = listaEmpleados[i];
					listaEmpleados[i] = listaEmpleados[j];
					listaEmpleados[j] = auxiliar;
					retorno = 1;
				}
				break;
			}

		}
	}
	return retorno;
}
//cambiar nombre a calcular
float CalcularSalarioTotal(Employee listaEmpleados[], int tam) {
	int i;
	float contadorSalario = 0;

	for (i = 0; i < tam; ++i) {
		if (listaEmpleados[i].isEmpty == FALSE) {
			contadorSalario = contadorSalario + listaEmpleados[i].salary;

		}
	}

	return contadorSalario;
}
float CalcularPromedio(Employee listaEmpleados[], int tam) {
	float salarioTotales;
	int empleadosTotal;
	float promedioSalarios;

	empleadosTotal = ContarEmpleados(listaEmpleados, tam);
	salarioTotales = CalcularSalarioTotal(listaEmpleados, tam);
	promedioSalarios = salarioTotales / empleadosTotal;

	return promedioSalarios;
}

int CalcularEmpleadosSueldoMayorAlPromedio(Employee listaEmpleados[], int tam) {
	int i;
	float promedioSalariosTotal;
	int empleadoConSueldoAlto = 0;

	promedioSalariosTotal = CalcularPromedio(listaEmpleados, tam);

	for (i = 0; i < tam; i++) {
		if (listaEmpleados[i].salary
				> promedioSalariosTotal&& listaEmpleados[i].isEmpty == FALSE) {
			empleadoConSueldoAlto++;
		}
	}
	return empleadoConSueldoAlto;
}
int ContarEmpleados(Employee listaEmpleados[], int tam) {
	int i;
	int contadorEmpleados = 0;
	for (i = 0; i < tam; ++i) {
		if (listaEmpleados[i].isEmpty == FALSE) {
			contadorEmpleados++;
		}
	}
	return contadorEmpleados;
}

