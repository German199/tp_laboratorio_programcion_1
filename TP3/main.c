#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado.
     4. Modificar datos de empleado.
     5. Baja de empleado.
     6. Listar empleados.
     7. Ordenar empleados.
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir.
*****************************************************/


int main()
{
    int opcion;
    int flag = 0;
    LinkedList* listaEmpleados = ll_newLinkedList();

    do
    {
        printf("                      **********Empleados********** \n\n1- Cargar datos de nuevos empleados (modo texto)\n\n2- Cargar datos de nuevos empleados (modo binario)\n\n3- Alta Empleado\n\n4- Modificar Empleado\n\n5- Baja Empleado\n\n6- Listar Empleados\n\n7- Ordenar Empleados\n\n8- Guardar datos de empleados (modo texto)\n\n9- Guardar datos de empleados (modo binario)\n\n10- Salida\n\nOpcion: ");

        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            if(flag == 0){
                controller_loadFromText("data.csv", listaEmpleados);
                flag = 1;
            }
            else{
                printf("\n\nError, lista ya cargada.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 2:
            if(flag == 0){
                flag = 1;
                if(controller_loadFromBinary("data.bin", listaEmpleados) == -1){
                    printf("\nError, lista ya cargada.\n\n");
                    system("pause");
                    system("cls");
                }
            }
            else{
                printf("\nError, lista ya cargada.\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 3:
            if(flag == 1){
                controller_addEmployee(listaEmpleados);
                system("cls");
            }
            else{
                printf("\nEs necesario cargar un Empleado primero para no repetir ID\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 4:
            if(flag == 1){
                controller_editEmployee(listaEmpleados);
                system("cls");
            }
            else{
                printf("\nEs necesario cargar un Empleado primero\n\n");
                system("pause");
                system("cls");
            }

            break;
        case 5:
            if(flag == 1){
                controller_removeEmployee(listaEmpleados);
            }
            else{
                printf("\nEs necesario cargar un Empleado primero\n\n");
                system("pause");
                system("cls");
            }
            break;
        case 6:
            system("cls");
            printf("                        -*-*-*-* LISTA *-*-*-*-\n");
            controller_ListEmployee(listaEmpleados);
            printf("\n");
            system("pause");
            system("cls");
            break;
        case 7:
            controller_sortEmployee(listaEmpleados);
            break;
        case 8:
            if(flag==1){
                if(controller_saveAsText("data.csv", listaEmpleados))
                {
                    printf("Se guardo en texto exitosamente!\n");
                    system("pause");
                    system("cls");
                }
                else{
                    printf("Hubo un error!\n");
                    system("pause");
                    system("cls");
                }
            }
            else{
                printf("Se necesitan cargar empleados para guardarlos!\n");
                system("pause");
                system("cls");
            }
            break;
        case 9:
            if(flag == 1){
                if(controller_saveAsBinary("data.bin",listaEmpleados)){
                    printf("Se guardo en binario exitosamente!\n");
                    system("pause");
                    system("cls");
                }
                else{
                    printf("Hubo un error!\n");
                    system("pause");
                    system("cls");
                }
            }
            else{
                printf("Se necesitan cargar empleados para guardarlos!\n");
                system("pause");
                system("cls");
            }
            break;
        }
    }
    while(opcion != 10);
    return 0;
}
