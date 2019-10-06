#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>


#include "ArrayEmployees.h"

#define LEN 1000



int main()
{
    Employee employeeList[LEN];
    int IDemployee = 1000;
    int cTrue;
    char continuar = 'n';

    initEmployees(employeeList, LEN);

 do
    {
        switch(menu()){
        case '1':
            if(newEmployee(employeeList, LEN, IDemployee)){
                IDemployee++;
            }
            break;
        case '2':
            cTrue = checkEmployee(employeeList, LEN);
            if (cTrue == 1){
                changingEmployee(employeeList, LEN);
            }
            else{
                printf("\nSe debe realizar otras acciones anteriores\n");
            }
            break;
        case '3':
            cTrue = checkEmployee(employeeList, LEN);
            if (cTrue == 1){
                removingEmployee(employeeList, LEN);
            }
            else{
            printf("\nSe debe realizar otras acciones anteriores\n");
            }
            break;
        case '4':
            cTrue = checkEmployee(employeeList, LEN);
            if (cTrue == 1){
                reportEmployees(employeeList, LEN);
            }
            else{
                printf("\nSe debe realizar otras acciones anteriores\n");
            }
            break;
        case '5':
            printf("\n\nConfirmar salir? (y/n): ");
            fflush(stdin);
            continuar = getchar();
            printf("\n");
            while(continuar != 'y' && continuar != 'n')
            {
                printf("\nOpcion incorrecta, intente nuevamente (y/n): \n");
                fflush(stdin);
                continuar = getchar();
            }
            break;
        default:
            system("cls");
            printf("Opcion elegida invalida\n");
            break;
        }
        printf("\n");
        system("pause");
    }
    while (continuar == 'n');

    return 0;
}

