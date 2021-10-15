/*
 * ArrayEmployees.h
 *
 *  Created on: 2 oct 2021
 *      Author: User
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

#define TRUE 1
#define FALSE 0

struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
}typedef Employee;

int InitEmployees(Employee listaEmpleados[], int tam);
int AddEmployee(Employee listaEmpleados[], int tam, int id, char name[],
		char lastName[], float salary, int sector);
int FindEmployeeById(Employee listaEmpleados[], int tam, int id);
int RemoveEmployee(Employee listaEmpleados[], int tam, int id);
int PrintEmployees(Employee listaEmpleados[], int tam);
int ModifyEmployee(Employee listaEmpleados[], int tam, int id);
int SortEmployees(Employee listaEmpleados[], int tam, int order);
float CalcularSalarioTotal(Employee listaEmpleados[], int tam);
float CalcularPromedio(Employee listaEmpleados[], int tam);
int CalcularEmpleadosSueldoMayorAlPromedio(Employee listaEmpleados[], int tam);
int ContarEmpleados(Employee listaEmpleados[], int tam);

#endif /* ARRAYEMPLOYEES_H_ */
