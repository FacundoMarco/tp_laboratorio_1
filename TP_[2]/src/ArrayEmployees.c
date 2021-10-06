/*
 * ArrayEmployees.c
 *
 *  Created on: 2 oct 2021
 *      Author: User
 */
#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"
#include "Validaciones.h"

#define TRUE 1
#define FALSE 0

struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}typedef Employee;


//Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
//(isEmpty) en TRUE en todas las posiciones del array.
int initEmployees(Employee listaEmpleados[] , int tam) {
	int FlagInicializacion = -1;
	if(listaEmpleados != NULL && tam > 0){
		for (int i = 0; i < tam; i++)
			    {
			      listaEmpleados[i].isEmpty = TRUE;
			      FlagInicializacion = 0;
			    }
	}


	 return FlagInicializacion;
}

int addEmployee(Employee listaEmpleados[], int tam, int id, char name[],char
		lastName[],float salary,int sector) {
	int flagCargar = 0;

	 for (int i = 0; i < tam; i++)
	    {

	      if (listaEmpleados[i].isEmpty == TRUE) {


	    	  listaEmpleados[i].id = id;

	    	  listaEmpleados[i].name = name;

	    	  listaEmpleados[i].lastName = lastName;

	    	  listaEmpleados[i].salary = salary;

	    	  listaEmpleados[i].sector = sector;

	    	  listaEmpleados[i].isEmpty = FALSE;

		  break;
		}
	      flagCargar = 1;
	    }

	return flagCargar;
}
int findEmployeeById(Employee listaEmpleados[], int tam, int id) {

	int buscarId;
	int i;
	int flagEmpleado = 1;
	buscarId = PedirEntero ("Ingrese ID del empleado a buscar : ");

	for (i = 0; i < tam; ++i) {
		if(buscarId == listaEmpleados[i].id){
				//para modificar empleados
			flagEmpleado = 0;
			}
	}

return flagEmpleado;
}

int removeEmployee(Employee listaEmpleados[], int tam, int id){

	int i;
	for ( i = 0;  i < tam; ++ i) {
		if(listaEmpleados[i]){

		}
	}

}

int sortEmployees(Employee* list, int len, int order)
{
 return 0;
}
int printEmployees(Employee* list, int length)
{
 return 0;
}
