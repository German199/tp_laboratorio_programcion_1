#include "Employee.h"
#include "string.h"
#include "LinkedList.h"

Employee* new_employee()
{
    Employee * emp;
    emp = (Employee*) malloc(sizeof(Employee));

    if(emp != NULL)
    {
        emp->id = 0;
        strcpy(emp->nombre, " ");
        emp->horasTrabajadas = 0;
        emp->sueldo = 0;
    }

    return emp;
}

Employee* employee_newParametros(char* idCad, char* nombreCad, char* horasCad, char* sueldoCad)
{
    int id;
    int sueldo;
    int horas;

    Employee* newEmployee;

    newEmployee = new_employee();

    id = atoi(idCad);
    sueldo = atoi(sueldoCad);
    horas = atoi(horasCad);

    employee_setId(newEmployee, id);
    employee_setNombre(newEmployee, nombreCad);
    employee_setHorasTrabajadas(newEmployee, horas);
    employee_setSueldo(newEmployee, sueldo);

    return newEmployee;
}

void employee_delete(Employee* emp)
{
    if(emp != NULL)
    {
        free(emp);
    }
}

int employee_setId(Employee* emp, int id)
{
    int returnInt = -1;

    if(emp != NULL)
    {
        returnInt = 0;
        emp->id = id;
        returnInt = 1;
    }

    return returnInt;
}

int employee_getId(Employee* emp, int* id)
{
    int returnInt = -1;

    if(emp != NULL)
    {
        returnInt = 0;
        *id = emp->id;
        returnInt = 1;
    }

    return returnInt;
}

int employee_setNombre(Employee* emp, char* nombre)
{
    int returnInt = -1;

    if(emp != NULL)
    {
      returnInt = 0;
      strcpy(emp->nombre, nombre);
      returnInt = 1;
    }

    return returnInt;
}

int employee_getNombre(Employee* emp, char* nombre)
{
    int returnInt = -1;

    if(emp != NULL)
    {
        returnInt = 0;
        strcpy(nombre, emp->nombre);
        returnInt = 1;
    }

    return returnInt;
}

int employee_setHorasTrabajadas(Employee* emp, int hora)
{
    int returnInt=-1;

    if(emp != NULL)
    {
        returnInt = 0;
        emp->horasTrabajadas = hora;
        returnInt = 1;
    }

    return returnInt;
}

int employee_getHorasTrabajadas(Employee* emp, int* hora)
{
    int returnInt = -1;
    if(emp != NULL)
    {
        returnInt = 0;
        *hora = emp->horasTrabajadas;
        returnInt = 1;
    }

    return returnInt;
}

int employee_setSueldo(Employee* emp, int sueldo)
{
    int returnInt = -1;

    if(emp != NULL)
    {
        returnInt = 0;
        emp->sueldo = sueldo;
        returnInt = 1;
    }

    return returnInt;
}


int employee_getSueldo(Employee* emp, int* sueldo)
{
    int returnInt = -1;

    if(emp != NULL)
    {
        returnInt = 0;
        *sueldo = emp->sueldo;
        returnInt = 1;
    }

    return returnInt;
}

int sortEmployees(void* emp, void* auxEmp)
{
    Employee* aux = emp;
    Employee* aux2 = auxEmp;

    return strcmp(aux->nombre, aux2->nombre);
}

