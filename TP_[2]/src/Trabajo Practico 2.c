#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Validaciones.h"

#define TAM 1000

int main(void) {

	setbuf(stdout, NULL);

	int opcion;
	int idAux = 0;
	char nameAux[51];
	char lastNameAux[51];
	float salaryAux;
	int sectorAux;
	int flagAddEmpleados;
	int empleadoBuscado;
	int idEmpleadoBaja;
	int flagRemover;
	int flagMostrarLista;
	int flagInicialisacionLista;
	float salarioTotal;
	float promedioSalarios;
	int canEmpleadosSupPromedio;
	int banderaModificarId;
	int modificarPorId;
	int banderaPrimerDato = 0;
	int order;

	Employee listaEmpleados[TAM]; //={{1,"Facu","Juarez",30000, 2 ,FALSE},{2,"Maty","Jimenez",35000, 3 ,FALSE},{3,"Nicolas","Quispe",40000, 4 ,FALSE}}

	flagInicialisacionLista = InitEmployees(listaEmpleados, TAM);

	if (flagInicialisacionLista == 0) {
		printf("Se a Inicializo la lista de empleados.\n");
	} else {
		printf("No se pudo inicializar la lista de empleados.\n");
	}

	do {
		printf("=====================================================\n");
		printf("=====================================================\n");
		printf("1-ALTAS DE EMPLEADOS\n"
				"2-MODIFICACIÓN DE EMPLEADOS\n"
				"3-BAJA DE EMPLEADOS\n"
				"4-INFORMAR\n"
				"5- SALIR\n");
		printf("=====================================================\n");
		printf("=====================================================\n");

		opcion = PedirEntero("Ingrese la opcion: ");

		switch (opcion) {
		case 1:
			banderaPrimerDato = 1;
			idAux++;
			PedirString("Ingrese Nombre:  ", nameAux);
			PedirString("Ingrese Apellido:  ", lastNameAux);
			salaryAux = PedirFloat("Ingrese el Salario:   ");
			sectorAux = PedirEntero("Ingrese Sector:   ");

			flagAddEmpleados = AddEmployee(listaEmpleados, TAM, idAux, nameAux,
					lastNameAux, salaryAux, sectorAux);
			if (flagAddEmpleados == 1) {
				printf("Empleado cargado correctamente.\n");
			} else {
				printf("No se pudo Cargar Empleado.\n");
			}

			break;

		case 2:
			if (banderaPrimerDato == 1) {
							flagMostrarLista = PrintEmployees(listaEmpleados, TAM);
							if (flagMostrarLista == 1) {
								printf("NO HAY EMPLEADOS CARGADOS\n");
							}

							modificarPorId = PedirEntero(
									"Ingrese ID del empleado a modificar:  ");
							banderaModificarId = ModifyEmployee(listaEmpleados, TAM,
									modificarPorId);
							if (banderaModificarId == 0) {
								printf("No se Pudo encontrar ID a Modificar.\n");
							}

						} else {
							printf("TODAVIA NO A INGRESADO EMPLEADOS.\n");
						}

			break;
		case 3:

			if (banderaPrimerDato == 0) {
							printf("TODAVIA NO A INGRESADO EMPLEADOS.\n");
						} else {
							flagMostrarLista = PrintEmployees(listaEmpleados, TAM);
							if (flagMostrarLista == 1) {
								printf("NO HAY EMPLEADOS CARGADOS\n");
							}
							idEmpleadoBaja = PedirEntero(
									"Ingrese ID de Empleado a dar de BAJA:  ");
							empleadoBuscado = FindEmployeeById(listaEmpleados, TAM,
									idEmpleadoBaja);
							if (empleadoBuscado == 1) {
								flagRemover = RemoveEmployee(listaEmpleados, TAM,
										idEmpleadoBaja);
								if (flagRemover == 1) {
									printf("SE DIO DE BAJA AL EMPLEADO CORRECTAMENTE.\n");
								} else {
									printf("NO SE PUDO ENCONTRAR ID.\n");
								}
							} else {
								printf("NO SE ENCONTRO EMPLEADO.\n");
							}

						}



			break;
		case 4:
			if (banderaPrimerDato == 0) {
				printf("TODAVIA NO A INGRESADO EMPLEADOS.\n");
			} else {
				do {
					printf(
							"=====================================================\n");
					printf(
							"=====================================================\n");
					printf(
							"1-Listado de los empleados ordenados alfabéticamente y por Sector.\n"
									"2-Total y promedio de los salarios, y cuantos empleados superan el salario promedio.\n"
									"3-Salir\n");
					printf(
							"=====================================================\n");
					printf(
							"=====================================================\n");
					flagMostrarLista = PrintEmployees(listaEmpleados, TAM);
					if (flagMostrarLista == 1) {
						printf("NO SE PUDO MOSTRAR LA LISTA CORRECTAMENTE\n");
					}
					opcion = PedirEntero("Ingrese Opcion : ");
					switch (opcion) {
					case 1:
						order =
								PedirEntero(
										"Ingrese 0 para Descendente y 1 para Ascendente: ");
						SortEmployees(listaEmpleados, TAM, order);
						flagMostrarLista = PrintEmployees(listaEmpleados, TAM);
						if (flagMostrarLista == 1) {
							printf(
									"NO HAY EMPLEADOS CARGADOS\n");
						}

						break;
					case 2:

						salarioTotal = CalcularSalarioTotal(listaEmpleados,
						TAM);
						promedioSalarios = CalcularPromedio(listaEmpleados,
						TAM);
						canEmpleadosSupPromedio =
								CalcularEmpleadosSueldoMayorAlPromedio(
										listaEmpleados, TAM);

						printf("El salario total es :%.2f \n", salarioTotal);
						printf("El Promedio De los salarios es :%.2f \n ",
								promedioSalarios);
						printf(
								"La cantidad de empleados que superan el salario promedio son :%d \n",
								canEmpleadosSupPromedio);

						break;
					case 3:
						printf(".......\n");
						break;
					default:
						printf("ERROR, Ingrese Opcion Valida\n");
						break;

					}

				} while (opcion != 3);

			}

			break;

		case 5:
			printf("HASTA LUEGO.\n");
			break;
		default:
			printf("ERROR OPCION INVALIDA.\n");
			break;

		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}

