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

/// @fn int InitEmployees(Employee[], int )
/// @brief Incia la lista de empleados cambiando a isEmpty a TRUE
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @return Retorna -1 si no se pudo inciar y 0 si se pudo iniciar
int InitEmployees(Employee listaEmpleados[], int tam);

/// @fn int AddEmployee(Employee[], int, int, char[], char[], float, int)
/// @brief Agrega empleados por parametro y verifica si se pudo cargar o no
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @param id ID del empleado por parametro
/// @param name Nombre del empleado por parametro
/// @param lastName Apellido del empleado por parametro
/// @param salary Salario del empleado por parametro
/// @param sector Sector del empleado por parametro
/// @return Retorna 1 si se pudo agregar empleados 0 si no
int AddEmployee(Employee listaEmpleados[], int tam, int id, char name[],
		char lastName[], float salary, int sector);

/// @fn int FindEmployeeById(Employee[], int , int )
/// @brief Busca una id ingresada por paremetro y devuelve si se encontro o no
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @param id ID del empleado que se realizara la busqueda
/// @return Retorna 1 si se encontro empleado 0 si no
int FindEmployeeById(Employee listaEmpleados[], int tam, int id);

/// @fn int RemoveEmployee(Employee[], int, int)
/// @brief Remueve empleado poniendo estado isEmpty en TRUE
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @param id ID del empleado que se realizara la baja
/// @return Retorna 1 si se removio empleado 0 si no
int RemoveEmployee(Employee listaEmpleados[], int tam, int id);

/// @fn int PrintEmployees(Employee[], int)
/// @brief Imprime en pantalla la lista de empleados
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @return Retorna 0 si se pudo mostrar la lista 1 si no
int PrintEmployees(Employee listaEmpleados[], int tam);

/// @fn int ModifyEmployee(Employee[], int, int)
/// @brief  Imprime un menu de opciones y te permite modificar nombres, apellidos, salarios y sectores
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @param id ID del empleado a modificar pasada por parametro
/// @return Retorna 1 si se pudo modiciar 0 si no
int ModifyEmployee(Employee listaEmpleados[], int tam, int id);

/// @fn int SortEmployees(Employee[], int, int)
/// @brief Imprime un submenu que deja ordenar de forma ascendente y descendente los apellidos y por sector en caso de apellidos iguales
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @param order Se pide por parametro la opcion a elegir 1 ascendente 0 descendente
/// @return Retorna 1 si se pudo hacer el ordenamiento 0 si no
int SortEmployees(Employee listaEmpleados[], int tam, int order);

/// @fn float CalcularSalarioTotal(Employee[], int)
/// @brief Calcula el salario total de los empleados
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @return Retorna el salario total de todos los empleados
float CalcularSalarioTotal(Employee listaEmpleados[], int tam);

/// @fn float CalcularPromedio(Employee[], int)
/// @brief  Llama a las funciones CalcularSalarioTotal y ContarEmpleados y calcula el promedio de los salarios
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @return Retorna el promedio de los salarios
float CalcularPromedio(Employee listaEmpleados[], int tam);

/// @fn int CalcularEmpleadosSueldoMayorAlPromedio(Employee[], int)
/// @brief  Calcula los empleados que superan el sueldo promedio
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @return Retorna cantidad de empleados que superan el sueldo promedio
int CalcularEmpleadosSueldoMayorAlPromedio(Employee listaEmpleados[], int tam);

/// @fn int ContarEmpleados(Employee[], int)
/// @brief  Cuenta la cantidad de empleados dados de alta
///
/// @param listaEmpleados Array que se le va a pasar
/// @param tam Tamaño de listaEmpleados
/// @return Retorna cantidad de empleados
int ContarEmpleados(Employee listaEmpleados[], int tam);

#endif /* ARRAYEMPLOYEES_H_ */
