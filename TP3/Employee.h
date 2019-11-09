#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

#endif // employee_H_INCLUDED

Employee* new_employee();

Employee* employee_newParametros(char* idCad, char* nombreCad, char* horasCad, char* sueldoCad);

void employee_delete(Employee* emp);

int employee_setId(Employee* emp, int id);
int employee_getId(Employee* emp, int* id);

int employee_setNombre(Employee* emp, char* nombre);
int employee_getNombre(Employee* emp, char* nombre);

int employee_setHorasTrabajadas(Employee* emp, int hora);
int employee_getHorasTrabajadas(Employee* emp, int* hora);

int employee_setSueldo(Employee* emp, int sueldo);
int employee_getSueldo(Employee* emp, int* sueldo);

int sortEmployees(void* emp, void* auxEmp);
