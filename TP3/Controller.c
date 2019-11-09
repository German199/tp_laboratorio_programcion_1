#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "funciones.h"
#include "Controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char* archivo donde se guardan los datos
 * \param pArrayListEmployee LinkedList*
 * \return int 0 si no pudo cargar los datos, 1 si funciono correctamente
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    int returnAux;

    returnAux = parser_EmployeeFromText(path, pArrayListEmployee);

    return returnAux;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char* archivo donde se guardan los datos
 * \param pArrayListEmployee LinkedList*
 * \return int int 0 si no pudo cargar los datos, 1 si funciono correctamente
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    int returnAux = 0;

    returnAux = parser_EmployeeFromBinary(path, pArrayListEmployee);

    return returnAux;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int idMax = -1;
    int flag = 0;
    int returnAux = 0;
    char auxNombre[128];
    int auxSueldo;
    int auxHora;

    system("cls");
    printf("---MENU DE ALTA---\n\n");
    Employee* newEmp = new_employee();
    Employee* auxEmp;

    getCadena("nombre: ", auxNombre, 128);
    primerLetraMayus(auxNombre);
    employee_setNombre(newEmp, auxNombre);

    auxSueldo = getInt(" sueldo: $", 0, 1215752190);
    employee_setSueldo(newEmp, auxSueldo);

    auxHora = getInt(" horas trabajadas: ", 1, 730);
    employee_setHorasTrabajadas(newEmp, auxHora);

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        auxEmp = ll_get(pArrayListEmployee, i);

        if(flag == 0 || auxEmp->id > idMax)
        {
            idMax = auxEmp->id;
        }
    }

    employee_setId(newEmp, auxEmp->id + 1);
    ll_add(pArrayListEmployee, newEmp);

    returnAux = 1;

    return returnAux;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    char auxNombre[128];
    int auxInt;
    int flag = 0;
    int index;
    int opcion;
    int opcionMod;

    system("cls");
    printf("---MENU DE MODIFICACION---\n");

    controller_ListEmployee(pArrayListEmployee);

    printf("\n\nIngrese ID del empleado: ");
    scanf("%d", &id);

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        Employee* aux;
        aux = ll_get(pArrayListEmployee, i);
        if((id == aux->id))
        {
            flag = 1;
            index = i;
            break;
        }
    }

    if(flag == 0)
    {
        printf("\nNo se ha encontrado un empleado con ese ID.\n\n");
        system("pause");
        system("cls");

    }
    else
    {
        printf("\nEmpleado de ID: %d\n1.Modificar nombre.\n2.Modificar sueldo\n3.Modificar horas trabajadas.\n", id);
        opcion = getInt(": ", 1, 3);

        Employee* aux;
        if(opcion == 1)
        {
            getCadena("nuevo nombre: ", auxNombre, 50);
            printf("\nEsta seguro?\n1-Si.\n2-No\n");
            opcionMod = getInt(": ", 1, 2);

            if(opcionMod == 1)
            {
                aux = ll_get(pArrayListEmployee, index);
                strcpy(aux->nombre, auxNombre);
                primerLetraMayus(aux->nombre);
                printf("Se modifico exitosamente!\n");
                system("pause");
            }
            else
            {
                system("cls");
                printf("Se cancelo la operacion!\n");
                system("pause");
            }
        }
        else if(opcion == 2)
        {
            aux = ll_get(pArrayListEmployee, index);

            printf("Ingrese nuevo sueldo: ");

            scanf("%d", &auxInt);
            printf("\nEsta seguro?\n1-Si.\n2-No\n");
            opcionMod = getInt(": ", 1, 2);

            if(opcionMod == 1)
            {
                aux->sueldo = auxInt;
                printf("Se modifico exitosamente!\n");
                system("pause");
            }
            else
            {
                printf("Se cancelo la operacion!\n");
                system("pause");
            }

        }
        else
        {
            aux = ll_get(pArrayListEmployee, index);

            printf("Ingrese nuevas horas trabajadas: ");

            scanf("%d", &auxInt);

            printf("\nEsta seguro?\n1-Si.\n2-No\n");

            opcionMod = getInt(": ", 1, 2);

            if(opcionMod == 1)
            {
                aux->horasTrabajadas = auxInt;
                printf("Se modifico exitosamente!\n");
                system("pause");
            }
            else
            {
                printf("Se cancelo la operacion!\n");
                system("pause");
            }
        }
    }

    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id;
    int flag=0;
    int index;
    int opcion;

    system("cls");

    printf("---MENU DE BAJA---\n");

    controller_ListEmployee(pArrayListEmployee);

    printf("\n\nIngrese ID del empleado: ");
    scanf("%d", &id);

    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        Employee* aux;
        aux = ll_get(pArrayListEmployee, i);
        if((id == aux->id))
        {
            flag = 1;
            index = i;
            break;
        }
    }

    if(flag == 0)
    {
            printf("No se ha encontrado empleado con ese ID.\n\n");
            system("pause");
            system("cls");
    }
    else
    {
            printf("Esta seguro?\n1-Si.\n2-No.\n");
            opcion = getInt(": ", 1, 2);
            if(opcion == 1)
            {
                ll_remove(pArrayListEmployee, index);
                printf("Empleado eliminado exitosamente!\n");
                system("pause");
                system("cls");
            }
            else
            {
                printf("Se cancelo la operacion!\n");
                system("pause");
                system("cls");
            }
    }

    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    Employee* emp;

    printf("\n-ID-|.|    -NOMBRE-|.|   -HORAS-  |.|      -SUELDO-  |.|\n");
    printf("    |.|            |.|            |.|                |.|    \n");


    for(int i = 0; i < ll_len(pArrayListEmployee); i++)
    {
        emp = ll_get(pArrayListEmployee, i);
        printf("%4d|.|%12s|.|  %10d|.|          $%d|.|\n", emp->id, emp->nombre, emp->horasTrabajadas, emp->sueldo);
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    ll_sort(pArrayListEmployee, sortEmployees, 1);

    printf("Se ordeno la lista alfabeticamente! (A-Z)\n");
    system("pause");
    system("cls");

    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    int returnAux = -1;
    int sueldo;
    int hora;
    int id;
    char nombre[50];

    FILE* pFile;

    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
        for(int i = 0; i < (ll_len(pArrayListEmployee)); i++)
        {
            Employee* aux;

            aux = ll_get(pArrayListEmployee, i);

            id = aux->id;
            strcpy(nombre, aux->nombre);
            sueldo = aux->sueldo;
            hora = aux->horasTrabajadas;

            fprintf(pFile,"%d,%s,%d,%d\n", id, nombre, hora, sueldo);
        }
    }

    returnAux=1;

    fclose(pFile);

    return returnAux;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    int returnAux = -1;
    int sueldo;
    int hora;
    int id;
    char nombre[50];

    FILE* pFile;

    pFile = fopen(path, "wb");

    if(pFile != NULL)
    {

        for(int i = 0; i < (ll_len(pArrayListEmployee)); i++)
        {
            Employee* aux;

            aux = ll_get(pArrayListEmployee, i);

            id = aux->id;
            strcpy(nombre, aux->nombre);
            sueldo = aux->sueldo;
            hora = aux->horasTrabajadas;

            fprintf(pFile,"%d,%s,%d,%d\n", id, nombre, hora, sueldo);
        }
    }

    returnAux=1;

    fclose(pFile);

    return returnAux;
}
