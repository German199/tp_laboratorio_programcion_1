#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include "ArrayEmployees.h"



int menu(){

    char option;
    system("cls");

    printf("\n**********  Nomina de Empleados  **********\n");
    printf("\n1 - Alta de Empleados\n");
    printf("\n2 - Modificacion de Empleados\n");
    printf("\n3 - Baja de Empleado\n");
    printf("\n4 - Informe de Empleados\n");
    printf("\n5 - Salir\n");
    printf("\nElija la opcion deseada: \n\n");
    fflush(stdin);
    option = getchar();


    return option;
}

int initEmployees(Employee employees[], int len){
    int allOk = 0;
    for (int i = 0; i < len; i++)
    {
        employees[i].isEmpty = 1;
        allOk = 1;
    }
    return allOk;
}

Employee addEmployee(int id, char name[],char lastName[],float salary,int sector){
    Employee newEmployee;

            newEmployee.id = id;
            strcpy(newEmployee.name, name);
            strcpy(newEmployee.lastName, lastName);
            newEmployee.salary = salary;
            newEmployee.sector = sector;
            newEmployee.isEmpty = 0;


    return newEmployee;
}

int searchEmpty(Employee employees[], int len){
    int ind = -1;
    for(int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 1)
        {
            ind = i;
            break;
        }
    }
    return ind;
}

int newEmployee(Employee employees[], int len, int id){
    int allOk = 0;
    int flag = 0;
    int ind;
    int salary;
    int tries = 5;
    int sector;
    char check = 'g';
    char name[51];
    char lastName[51];
    char auxCad[100];

    system("cls");
    printf("**********  Alta de Empleados  **********\n");
    ind = searchEmpty(employees, len);
    if (ind == -1){
        printf("\nNomina de Empleados llena imposible ingresar mas empleados\n");
    }
    else{
        while (check == 'g' || flag == 0){
            printf("Ingrese el nombre del nuevo empleado, 25 caracteres como MAXIMO: \n");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad)>25 && tries > 0){
                printf("Nombre con mayor a 25 caracteres, intente nuevamente: \n");
                fflush(stdin);
                gets(auxCad);
                tries--;
            }
            if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                check = 'f';
                break;
            }
            strcpy(name, auxCad);
            tries = 5;

            printf("Ingrese el apellido del nuevo empleado, 25 caracteres como MAXIMO: \n");
            fflush(stdin);
            gets(auxCad);
            while(strlen(auxCad)>25 && tries > 0){
                printf("Apellido con mayor a 25 caracteres, intente nuevamente: \n");
                fflush(stdin);
                gets(auxCad);
                tries--;
            }
            if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                check = 'f';
                break;
            }
            strcpy(lastName, auxCad);
            tries = 5;

            printf("Ingrese salario del nuevo empleado: \n");
            scanf("%d", &salary);
            while (tries > 0 && (salary > 100000 || salary < 10000)){
                printf("Salario ingresado incorrecto, intente nuevamente(10.000-100.000): \n");
                scanf("%d", &salary);
                tries--;
            }
            if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                check = 'f';
                break;
            }
            printf("\n");
            tries = 3;

            printf("Ingrese sector del nuevo empleado (1-30): \n");
            scanf("%d", &sector);
            while ((sector > 30 || sector < 1) && tries > 0){
                printf("Numero de sector incorrecto, intente nuevamente (1-30): ");
                scanf("%d", &sector);
                tries--;
            }
            if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                check = 'f';
                break;
            }
            flag = 1;
            check = 't';
        }
        if (check == 't'){
            employees[ind] = addEmployee(id, name, lastName, salary, sector);
            printf("\nEmpleado ingresado al sistema\n");
            allOk = 1;
        }
        else{
            printf("No se ha podido ingresar el nuevo empleado\n");
        }
    }
    return allOk;
}

int findEmployeeById(Employee employees[], int len, int id){
    int ind = -1;
    for(int i = 0; i < len; i++){
        if (employees[i].isEmpty == 0 && employees[i].id == id)
        {
            ind = i;
            break;
        }
    }
    return ind;

}

void removingEmployee(Employee employees[], int len){
    int auxID;
    int ind;

    printf("\n**********  ID de Empleados  **********\n");
    printf("Ingrese el ID del empleado deseado desde el 1000: \n");
    scanf("%d", &auxID);
    ind = findEmployeeById(employees, len, auxID);
    if (ind == -1){
        printf("ID ingresado no existe en el sistema.\n\n");
        system("pause");
    }
    else{
        removeEmployee(employees, len, auxID);
    }
}

int interMenu(Employee employees[], int len, int id){

    int option;
    int ind;

    ind = findEmployeeById(employees, len, id);
    system("cls");
    printf("ID del empleado que desea modificar: %d\n", id);
    printf("Nombre del empleado que desea modificar: %s %s\n\n", employees[ind].name, employees[ind].lastName);

    printf("\n   **********  Modificar Empleados  **********   \n");
    printf("1 - Modificar nombre\n");
    printf("2 - Modificar apellido\n");
    printf("3 - Modificar salario\n");
    printf("4 - Modificar sector\n");
    printf("5 - Salir\n");
    printf("Elija la opcion deseada: ");
    scanf("%d", &option);

    return option;
}

void changingEmployee(Employee employees[], int len){
    int auxID;
    int ind;

    printf("\n**********  ID de Empleados  **********\n");
    printf("Ingrese el ID del empleado deseado desde el 1000: \n");
    scanf("%d", &auxID);
    ind = findEmployeeById(employees, len, auxID);
    if(ind == -1){
        printf("ID ingresado no existe en el sistema.\n\n");
        system("pause");
    }
    else
    {
        changeMenuCases(employees, len, auxID);
    }
}

void changeMenuCases(Employee employess[], int tam, int id){

    char name[51];
    char lastName[51];
    char respuesta;
    char continuar = 'n';
    int ind;
    int tries = 5;
    int salary;
    int sector;

    ind = findEmployeeById(employess, tam, id);

    do{
        switch(interMenu(employess, tam, id)){
        case 1:
            printf("Ingrese el nuevo nombre: \n");
            fflush(stdin);
            gets(name);
            while (strlen(name) > 25 && tries > 0){
                printf("Nombre con mayor a 25 caracteres, intente nuevamente: \n");
                gets(name);
                tries--;
            }
            if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                system("pause");
            }
            else{
                tries = 5;
                printf("Confirmar cambio (y/n): ");
                fflush(stdin);
                respuesta = getchar();
                while (tries > 0 && respuesta != 'y' && respuesta != 'n'){
                    printf("Respuesta incorrecta, intente nuevamente (y/n): ");
                    tries--;
                    fflush(stdin);
                    respuesta = getchar();
                }
                if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                    system("pause");
                }
                if (respuesta == 'y'){
                    strcpy(employess[ind].name, name);
                    printf("Nuevo nombre ingresado\n");
                    system("pause");
                }
                else{
                    printf("Se ha cancelado la operacion\n");
                    system("pause");
                }
            }
            break;
        case 2:
            printf("Ingrese el nuevo apellido: \n");
            fflush(stdin);
            gets(lastName);
            while (strlen(lastName) > 25 && tries > 0){
                printf("Apellido con mayor a 25 caracteres, intente nuevamente: \n");
                gets(lastName);
                tries--;
            }
            if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                system("pause");
            }
            else{
                tries = 5;
                printf("Confirmar cambio (y/n): ");
                fflush(stdin);
                respuesta = getchar();
                while (tries > 0 && respuesta != 'y' && respuesta != 'n'){
                    printf("Respuesta incorrecta, intente nuevamente (y/n): ");
                    tries--;
                    fflush(stdin);
                    respuesta = getchar();
                }
                if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                    system("pause");
                }
                if (respuesta == 'y'){
                    strcpy(employess[ind].lastName, lastName);
                    printf("Nuevo apellido ingresado\n");
                    system("pause");
                }
                else{
                    printf("Se ha cancelado la operacion\n");
                    system("pause");
                }
            }
            break;
        case 3:
            printf("Ingrese el nuevo salario: \n");
            scanf("%d", &salary);
            while (tries > 0 && (salary > 100000 || salary < 10000)){
                printf("Salario ingresado incorrecto, intente nuevamente(10.000-100.000): ");
                scanf("%d", &salary);
                tries--;
            }
            if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                system("pause");
            }
            else{
                tries = 5;
                printf("Confirmar cambio (y/n): ");
                fflush(stdin);
                respuesta = getchar();
                while (tries > 0 && respuesta != 'y' && respuesta != 'n'){
                    printf("Respuesta incorrecta, intente nuevamente (y/n): ");
                    tries--;
                    fflush(stdin);
                    respuesta = getchar();
                }
                if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                    system("pause");
                }
                if (respuesta == 'y'){
                    employess[ind].salary = salary;
                    printf("Nuevo salario modificado\n");
                    printf("**ID**    **NOMBRE**     **APELLIDO**     **SALARIO**     **SECTOR**\n");
                    printEmployee(employess[ind]);
                    system("pause");
                }
                else{
                    printf("Se ha cancelado la operacion\n");
                    system("pause");
                }
            }
            break;
        case 4:
            printf("Ingrese el nuevo secor: \n");
            scanf("%d", &sector);
            while (tries > 0 && (sector > 30 || sector < 1)){
                printf("Numero de Sector ingresado incorrecto, intente nuevamente (1-30): ");
                scanf("%d", &sector);
                tries--;
            }
            if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                system("pause");
            }
            else{
                tries = 5;
                printf("Confirmar cambio (y/n): ");
                fflush(stdin);
                respuesta = getchar();
                while (tries > 0 && respuesta != 'y' && respuesta != 'n'){
                    printf("Respuesta incorrecta, intente nuevamente (y/n): ");
                    tries--;
                    fflush(stdin);
                    respuesta = getchar();
                }
                if (tries == 0){
                printf("\nUsted a utilizado todos los intentos\n");
                    system("pause");
                }
                if (respuesta == 'y'){
                    employess[ind].sector = sector;
                    printf("Nuevo secor modificado \n");
                    printf("**ID**    **NOMBRE**     **APELLIDO**     **SALARIO**     **SECTOR**\n");
                    printEmployee(employess[ind]);
                    system("pause");
                }
                else{
                    printf("Se ha cancelado la operacion\n");
                    system("pause");
                }
            }
            break;
        case 5:
            printf("Confirmar Salida (y/n): ");
            fflush(stdin);
            continuar = getchar();
            while(continuar != 'y' && continuar != 'n'){
                printf("\nOpcion incorrecta, intente nuevamente (y/n): \n");
                fflush(stdin);
                continuar = getchar();
            }
            break;
        default:
            printf("Opcion seleccionada incorrecta\n");
            break;
            system("pause");
        }
    }
    while(continuar == 'n');
}

void printEmployee(Employee employeeX){
    printf("%d   %10s        %10s         %.2f          %02d\n",
           employeeX.id,
           employeeX.name,
           employeeX.lastName,
           employeeX.salary,
           employeeX.sector);
}

void printEmployees(Employee employees[], int len){
    int flag = 0;

    printf("\n**ID**    **NOMBRE**     **APELLIDO**      **SALARIO**     **SECTOR**\n");

    for(int i=0; i < len; i++){
        if(employees[i].isEmpty == 0)
        {
            printEmployee(employees[i]);
            flag = 1;
        }
    }
    if (flag == 0){
        system("cls");
        printf("\nNo se han encontrados empleados\n");
    }

}

int removeEmployee(Employee employees[], int len, int id){

    int continuar = 0;
    int tries = 5;
    char resp;
    int ind;

    system("cls");
    printf("\n**********  Baja de Empleados  **********\n");
    printf("\n**ID**    **NOMBRE**     **APELLIDO**      **SALARIO**     **SECTOR**\n");
    ind = findEmployeeById(employees, len, id);
    printEmployee(employees[ind]);
    printf("Confirmar baja (y/n): \n");
    fflush(stdin);
    resp = getchar();
    while(resp != 'y' && resp != 'n' && tries > 0){
        printf("\nOpcion incorrecta, intente nuevamente (y/n): ");
        fflush(stdin);
        resp = getchar();
        tries--;
    }
    if (tries == 0){
    printf("\nUsted a utilizado todos los intentos\n");
    }
    if (resp == 'y'){
        employees[ind].isEmpty = 1;
        printf("Se ha dado de baja el empleado\n");
        continuar = 1;
    }
    else{
        printf("Operacion cancelada");
    }
    return continuar;
}

int sortEmployees(Employee employees[], int len, int order){
    int allOk = 0;

    int auxSal;
    int auxId;
    int auxSector;
    char auxCad[51];


    for (int i = 0; i < len - 1; i++){
        for(int j = i + 1; j < len; j++){
            if (order == 1){
                if (employees[i].isEmpty == 0 && employees[j].isEmpty == 0 && employees[i].sector > employees[j].sector){

                    strcpy(auxCad, employees[i].lastName);
                    strcpy(employees[i].lastName, employees[j].lastName);
                    strcpy(employees[j].lastName, auxCad);

                    auxSector = employees[i].sector;
                    employees[i].sector = employees[j].sector;
                    employees[j].sector = auxSector;

                    strcpy(auxCad, employees[i].name);
                    strcpy(employees[i].name, employees[j].name);
                    strcpy(employees[j].name, auxCad);

                    auxSal = employees[i].salary;
                    employees[i].salary = employees[j].salary;
                    employees[j].salary = auxSal;

                    auxId = employees[i].id;
                    employees[i].id = employees[j].id;
                    employees[j].id = auxId;
                    allOk = 1;
                }
                if (employees[i].sector == employees[j].sector && strcmp(employees[i].lastName,employees[j].lastName) > 0 && employees[i].isEmpty == 0 && employees[j].isEmpty == 0){

                    strcpy(auxCad, employees[i].lastName);
                    strcpy(employees[i].lastName, employees[j].lastName);
                    strcpy(employees[j].lastName, auxCad);

                    auxSector = employees[i].sector;
                    employees[i].sector = employees[j].sector;
                    employees[j].sector = auxSector;

                    strcpy(auxCad, employees[i].name);
                    strcpy(employees[i].name, employees[j].name);
                    strcpy(employees[j].name, auxCad);

                    auxSal = employees[i].salary;
                    employees[i].salary = employees[j].salary;
                    employees[j].salary = auxSal;

                    auxId = employees[i].id;
                    employees[i].id = employees[j].id;
                    employees[j].id = auxId;
                    allOk = 1;
                }
            }
        }
    }
    return allOk;
}
void reportEmployees(Employee employees[], int len){

    char salir = 't';
    char option;
    int tries = 5;
    int sort;
    do{
        system("cls");
        printf("\n**********  Informe de Empleados  **********\n");
        printf("1 - Informar empleados ordenados alfabeticamente por Apellido y Sector\n");
        printf("2 - Informar total y promedio los salarios, y que empleados superan el salario promedio\n");
        printf("3 - Salir\n");
        printf("\n**********  Empleados Actuales  **********\n");
        printEmployees(employees, len);
        printf("Elija la opcion deseada: ");
        fflush(stdin);
        scanf("%c", &option);
        while ((option != '1' && option != '2' && option != '3') && tries > 0)
        {
            printf("Opcion seleccionada incorrecta, intente nuevamente ('1','2' o '3'): ");
            fflush(stdin);
            tries--;
            scanf("%c", &option);
        }
        if (tries == 0)
        {
            printf("\nUsted a utilizado todos los intentos\n");
            salir = 'f';
            system("pause");
        }
        switch(option)
        {
        case '1':
            sort = sortEmployees(employees, len, 1);
            if (sort == 1)
            {
                printf("\n**********  Empleados Ordenados  **********\n");
                printEmployees(employees, len);
                system("pause");
            }
            else
            {
                printf("\nEl proceso ha fallado\n");
                system("pause");
            }
            break;
        case '2':
            sortEmployeesSalary(employees, len);
            break;
        case '3':
            salir = 'f';
            break;
        }
    }
    while(salir == 't');
}

void sortEmployeesSalary(Employee employees[], int len)
{
    float mayor;
    float promedio;
    int cantEmployee = 0;
    int acum = 0;
    int cont = 0;
    for (int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 0)
        {
            cantEmployee++;
        }
    }
    for(int i = 0; i < cantEmployee; i++)
    {
        acum += employees[i].salary;
        promedio = acum / cantEmployee;
        if(mayor < employees[i].salary && employees[i].isEmpty == 0)
        {
            mayor = employees[i].salary;
        }
    }
    for (int i = 0; i < len; i++)
    {
        if(employees[i].salary > promedio && employees[i].isEmpty == 0)
        {
            cont++;
        }
    }
    printf("\n**********  Informe  **********\n");
    printf("Salarios totales: %d\n", acum);
    printf("Promedio de salarios totales: %.2f\n", promedio);
    printf("Empleados que superan el salario promedio: %d\n\n", cont);
    cont = 0;
    system("pause");
}

int checkEmployee(Employee employees[], int len)
{
    int OK = 0;
    for(int i = 0; i < len; i++)
    {
        if (employees[i].isEmpty == 0)
        {
            OK = 1;
        }
    }
    return OK;
}
