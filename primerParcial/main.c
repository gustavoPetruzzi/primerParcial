#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define MAX 10
typedef struct{

    int legajo;
    char nombre[50];
    char apellido[50];
    float salario;
    char sector;
    int isEmpty;
}eEmpleados;
int main()
{
    int i;
    int legajo[] = {1,4,21,8,5};
    float sueldo[] = {1234.1, 15000.44, 13700.11, 8532, 7001,11};
    char sector[] = {'1','2','3','4'};
    char *nombre [] = {"Jose","Juan","Carlos","Roberto","Pepe"};
    char *apellido[]= {"rodriguez", "Perez", "Alberto", "Carlos", "Mujica"};
    char opcion;
    int auxInt;
    float auxFloat;
    char auxChar;
    char auxString[50];
    int respuesta;
    eEmpleados empleado[50];




    for(i = 0; i<MAX; i++)
    {
        empleado[i].isEmpty = 1;
    }

    for(i = 0; i<5; i++)
    {
        empleado[i].isEmpty = 0;
        empleado[i].legajo = legajo[i];
        empleado[i].salario = sueldo[i];
        empleado[i].sector = sector[i];
        strcpy( empleado[i].nombre, nombre[i]);
        strcpy( empleado[i].apellido, apellido[i]);
    }
    printf("%d\n", empleado[3].legajo);
    opcion = mostrarMenu("1-ALTA\n2-MODIFICAR\n3-BAJAR\n4-INFORMAR\n5-LISTAR", '0', '5');
    switch(opcion)
    {
        case '1':
            for(i = 0; i<MAX; i++)
            {
                if(empleado[i].isEmpty == 1)
                {
                    do
                    {
                        respuesta = getInt(&auxInt, "Ingrese su legajo:\n","ERROR: reingrese", 1, 10000);
                        for(i = 0; i<MAX; i++)
                        {
                            if(auxInt == empleado[i].legajo)
                            {
                                printf("ESE LEGAJO YA EXISTE!");
                                respuesta = -1;
                                break;
                            }
                        }
                    }while(respuesta!=0);
                    printf("%d", auxInt);
                    empleado[i].legajo = auxInt;


                    do
                    {
                        respuesta = getName(auxString, "Ingrese su nombre:\n","ERROR: reingrese", 2, 49);
                    }while(respuesta!=0);
                    strcpy(empleado[i].nombre, auxString);

                    do
                    {
                        respuesta = getName(auxString, "Ingrese su Apellido:\n","ERROR: reingrese", 2, 49);
                    }while(respuesta!=0);
                    strcpy(empleado[i].apellido, auxString);
                    do
                    {
                        respuesta = getFloat(&auxFloat, "Ingrese su salario:\n","ERROR: reingrese", 2, 999999);
                    }while(respuesta!=0);
                    empleado[i].salario = auxFloat;

                    empleado[i].isEmpty = 0;
                    /*printf("\tLegajo\tNombre\tApellido\tSalario\n");
                    printf("\t%d\t%s\t%s\t%.2f\n", empleado[i].legajo, empleado[i].nombre, empleado[i].apellido, empleado[i].salario);*/
                    break;
                }
            }
            break;
        case '2':
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;

    }

    printf("\tLegajo\tNombre\tApellido\tSalario\n");
    for(i = 0; i<MAX; i++)
    {
       /* if(empleado[i].isEmpty == 0)
        {*/
            printf("\t%d\t%s\t%s\t%.2f\n", empleado[i].legajo, empleado[i].nombre, empleado[i].apellido, empleado[i].salario);
        //}

    }

    return 0;

}
