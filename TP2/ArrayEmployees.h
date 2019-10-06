#ifndef ARRAYEMPLOYEE_H_INCLUDED
#define ARRAYEMPLOYEE_H_INCLUDED

typedef struct{

int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;

}Employee;

#endif // ARRAYEMPLOYEE_H_INCLUDED


int menu();
/** \brief switch con opciones numericas para el uso del menu
 *
 * \param 5 cases, del case 1 al 4 llega la funcion por parametro
 * \param excepto el 5 que es la opcion de salida
 * \return la opcion seleccionada
 *
 */


int initEmployees(Employee employees[], int len);
/** \brief agrega una lista exitente de empleados recibidos por paramentros
 *en la primera posicion
 * \param
 * \param Employee employees[], int len
 * \return En el momento de agregar valores si isEmpty = 0 entonces newEmployee dara un error
 *
 */


Employee addEmployee(int id, char name[],char lastName[],float salary,int sector);
/** \brief de ser posible, agrega mas valores a la estructura
 *
 * \param int id, char name[],char lastName[],float salary,int sector
 * \param
 * \return al cargar todo en ind = i, luegose carga todo a la nueva estrucura
 *
 */


int searchEmpty(Employee employees[], int len);
/** \brief busca un espacio vacio en el vector
 *
 * \param Employee employees[], int len
 * \param
 * \return el espacio vacio para ser usado en funcion "newEmployee"
 *
 */


int newEmployee(Employee employees[], int len, int id);
/** \brief solicita los valores para agregar a un nuevo empleado
 *
 * \param Employee employees[], int len
 * \param
 * \return agrega un nuevo empleado si return = 1
 *
 */

int findEmployeeById(Employee employees[], int len, int id);
/** \brief encuentra un empleado por su ID
 *
 * \param
 * \param Employee employees[], int len, int id
 * \return regresa la informacion del vector donde se encuentra el ID
 *
 */

void printEmployee(Employee employeeX);
/** \brief muestra un empleado especifico
 *
 * \param Employee employeeX
 * \param
 * \return muestra el empleado en el sistema
 *
 */


void printEmployees(Employee employees[], int len);
/** \brief muestra a los empleados del sistema
 *
 * \param
 * \param Employee employees[], int len
 * \return regresa todos los empleados del sistema
 *
 */


int removeEmployee(Employee employees[], int len, int id);
/** \brief puede quitar un vector de un empleado deseado po id
 *
 * \param
 * \param contiene la opcion de concelar la operacion
 * \return quita el empleado
 *
 */


void removingEmployee(Employee employees[], int len);
/** \brief busca al empleado por ID
 *
 * \param Employee employees[], int len
 * \param
 * \return devuelve el empleado buscado por ID
 *
 */


int sortEmployees(Employee employees[], int len, int order);
/** \brief ordena los elementos del array
 *
 * \param Employee employees[], int len, int order
 * \param
 * \return regresa allOk = 0 si esta todo correcto y -1 si es un error
 *
 */


void changeMenuCases(Employee employess[], int tam, int id);
/** \brief contiene un switch de opciones para cambiar datos de empleados buscado por ID
 *
 * \param Employee employess[], int tam, int id
 * \param
 * \return regresa los cambios realizados dentro del switch
 *
 */


void changingEmployee(Employee employees[], int len);
/** \brief pide el ID y llama a la funcion changeMenuCases
 *
 * \param
 * \param Employee employees[], int len
 * \return modifica el ID del empleado
 *
 */


int changeMenu(Employee employees[], int len, int id);
/** \brief contiene un menu de opciones
 *
 * \param
 * \param Employee employees[], int len, int id
 * \return envia el menu para ser usada en la funcion changeMenuCases
 *
 */


void reportEmployees(Employee employees[], int len);
/** \brief informa los datos de los empleados
 *
 * \param
 * \param contiene un pequeño switch para las opciones deseadas
 * \return regresa el orden de informe seleccionado en el menu interno
 *
 */

void sortEmployeesSalary(Employee employees[], int len);
/** \brief reporta los salarios de los empleados
 *
 * \param Employee employees[], int len
 * \param
 * \return regresa los salarios, el promedio y los salarios que superan el minimo
 *
 */


int checkEmployee(Employee employees[], int len);
/** \brief verifica que todos los datos estan correctos
 *
 * \param
 * \param Employee employees[], int len
 * \return si esta todo correcto "Ok = 1", de no ser asi "Ok = 0"
 *
 */
