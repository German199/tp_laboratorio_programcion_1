#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int -1 si algun puntero viene en estado NULL, 0 si los punteros no están en NULL pero no pudo hacer el parseo, 1 si todo funciono correctamente
 *
 */
int parser_EmployeeFromText(char* pFile, LinkedList* pArrayListEmployee)
{
    int leer;
    int returnAux = -1;
    char auxId[10];
    char auxNombre[128];
    char auxSalario[10];
    char auxHoras[10];

    Employee* aux;

    FILE* data;

    data = fopen(pFile, "r");

    if(pFile != NULL && pArrayListEmployee != NULL && data != NULL)
    {
        returnAux = 0;

        do
        {
            leer = fscanf(data, "%[^,],%[^,],%[^,],%[^\n]", auxId, auxNombre, auxHoras, auxSalario);

            if(leer == 4)
            {
                aux = employee_newParametros(auxId, auxNombre, auxHoras, auxSalario);
                ll_add(pArrayListEmployee, aux);
            }

        }while(!feof(data));

        fclose(data);

        returnAux = 1;

        printf("\nDatos cargados correctamante\n");

        printf("Cantidad de datos cargados: %d\n", ll_len(pArrayListEmployee));
        printf("\n\n");
        system("pause");
        system("cls");

    }

    return returnAux;
}

/** \brief
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(char* pFile, LinkedList* pArrayListEmployee)
{
    int leer;
    int returnAux = -1;
    char auxId[10];
    char auxNombre[35];
    char auxSalario[10];
    char auxHoras[10];

    Employee* aux;

    FILE* data;

    data = fopen(pFile, "rb");

    if(pFile != NULL && pArrayListEmployee != NULL && data != NULL)
        {
        returnAux = 0;

        do{leer = fscanf(data, "%[^,],%[^,],%[^,],%[^\n]", auxId, auxNombre, auxSalario, auxHoras);

        if(leer == 4)
        {
            aux = employee_newParametros(auxId, auxNombre, auxHoras, auxSalario);
            ll_add(pArrayListEmployee, aux);
        }
        }while(!feof(data));

        returnAux=1;

        fclose(data);

        printf("\nDatos cargados correctamante\n");

        printf("Cantidad de datos cargados: %d\n",ll_len(pArrayListEmployee));
        printf("\n\n");
        system("pause");
        system("cls");
        }

    return returnAux;
}
