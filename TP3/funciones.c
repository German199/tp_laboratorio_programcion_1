#include "funciones.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

void getCadena(char mensaje[], char cad[], int tam)
{
    printf("Ingrese %s", mensaje);
    fflush(stdin);
    scanf("%[^\n]", cad);
    validarTamCad(mensaje, cad, tam);
}

void validarTamCad(char msgError[], char cad[], int tam)
{
    while(strlen(cad) > tam)
    {
        printf("Reingrese %s", msgError);
        fflush(stdin);
        scanf("%[^\n]", cad);
    }
}

void primerLetraMayus(char cad[])
{
    strlwr(cad);
    cad[0] = toupper(cad[0]);

    for(int i = 0; i < strlen(cad); i++)
    {
        if(cad[i] == ' ')
        {
            cad[i + 1] = toupper(cad[i + 1]);
        }
    }
}


void getFloat(char msg[], float flotante)
{
    printf("Ingrese %s", msg);
    fflush(stdin);
    scanf("%f", &flotante);
}

int getInt(char msg[], int menor, int mayor)
{
    int entero;

    printf("Ingrese%s", msg);
    scanf("%d", &entero);
    while(entero > mayor || entero < menor)
    {
        printf("Error. Reingrese%s", msg);
        scanf("%d", &entero);
    }

    return entero;
}
