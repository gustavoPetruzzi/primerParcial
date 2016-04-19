#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <string.h>
#define TAM 10
typedef struct{
    int dia,mes,anio;

}eFecha;

typedef struct{
    int legajo;
    char nombre[30];
    char apellido[30];
    float salario;
    char sector;
}eEmpleado;
eEmpleado cargarEmpleado(int, char[], char[], float, char);
int buscarLibre(eEmpleado[], int);

int main()
{
    int i,j;
    char opcion;
    int auxInt;
    int respuesta;
    int legajo;
    char nombre[30];
    char apellido[30];
    float salario;
    char sector;

    int auxlegajo[5] ={1,2,3,4,5};
    char *auxnombre[5] ={"jose", "carlos", "juan","roberto", "puto"};
    char *auxapellido[5]={"rodriguez","alberto","perugia","carlos","lee"};
    float auxsalario[5]= {1234.13, 3214.12, 4456.62, 7773.12, 9932.33};
    char auxsector[5]={'1', '2', '3', '1', '4'};
    eEmpleado empleados[TAM];

    for(i = 0; i<TAM; i++)
    {
        empleados[i].legajo = -1;
    }

    for(i = 0; i<5; i++)
    {
        empleados[i].legajo = auxlegajo[i];
        empleados[i].salario = auxsalario[i];


    }


    do
    {
        opcion = mostrarMenu("1-ALTAS\n2-MODIFICAR\n3-BAJAS\n4-INFORMAR\n5-LISTAR\n6-SALIR", '1', '6');
        switch(opcion)
        {
            case '1':
                auxInt = buscarLibre(empleados, TAM);
                printf("%d", auxInt);
                if(auxInt !=-1)
                {

                    respuesta = getName(nombre,"Ingrese el nombre:", "ERROR: solo se permiten letras", 2, 30);
                    if(respuesta == -1)
                    {
                        respuesta = getName(nombre,"Ingrese el nombre:", "ERROR: solo se permiten letras", 2, 30);
                    }

                    respuesta = getName(apellido,"Ingrese el apellido:", "ERROR: solo se permiten letras", 2, 30);
                    if(respuesta== -1)
                    {
                        respuesta = getName(apellido,"Ingrese el apellido:", "ERROR: solo se permiten letras", 2, 30);
                    }

                    respuesta = getFloat(&salario, "Ingrese el salario:", "ERROR: solo se permiten numeros", 2, 999999);
                    if(respuesta == -1)
                    {
                        respuesta = getFloat(&salario, "Ingrese el salario:", "ERROR: solo se permiten numeros", 2, 999999);
                    }

                    respuesta = getChar(&sector,"Ingrese el sector\n1-Contabilidad\n2-Administracion\n3-Compras\n4-Ventas","ERROR", '1', '4' );
                    if(respuesta == -1)
                    {
                        respuesta = getChar(&sector,"Ingrese el sector\n1-Contabilidad\n2-Administracion\n3-Compras\n4-Ventas","ERROR", '1', '4' );
                    }

                    if(auxInt == 0)
                    {
                        legajo = 1;

                    }
                    else
                    {
                        legajo = auxInt +1;
                    }




                    empleados[auxInt] = cargarEmpleado(legajo, nombre, apellido, salario, sector);

                }
                else
                {
                    printf("Nomina de empleados llena!");
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
            case '6':
                break;
        }
    }while(opcion!='6');
    if(empleados[0].legajo != -1)
    {
        printf("Legajo\tNombre\tApellido\tSector\tSalario\n");
        for(i=0;i<TAM; i++)
        {

            printf("%d\t%s\t%s", empleados[i].legajo, empleados[i].nombre, empleados[i].apellido);
            printf("\t%c\t%.2f\n", empleados[i].sector, empleados[i].salario );
        }
    }
    return 0;
}

eEmpleado cargarEmpleado(int legajo, char nombre[], char apellido[], float salario , char sector)
{
    eEmpleado auxEmpleado;
    auxEmpleado.legajo = legajo;
    strcpy(auxEmpleado.nombre, nombre);
    strcpy(auxEmpleado.apellido, apellido);
    auxEmpleado.salario = salario;
    auxEmpleado.sector = sector;

    return auxEmpleado;
}



int buscarLibre(eEmpleado empleado[], int MAX)
{

    int index = -1;
    int i;

    for(i= 0; i<MAX; i++)
    {
        if(empleado[i].legajo == -1)
        {
            index = i;
            break;
        }
    }

    return index;
}
