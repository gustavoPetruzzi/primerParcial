#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"
#define TAM 6

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
void mostrarEmpleado(eEmpleado);
void mostrarNomina(eEmpleado[], int);
int buscarLibre(eEmpleado empleado[], int);
float calculoSueldo(float *totalsueldo, eEmpleado[], int);

int main()
{
    int i,j;
    char opcion;
    int auxInt;
    float auxFloat;
    float promedio;
    int respuesta;
    int legajo;
    char nombre[30];
    char apellido[30];
    float salario;
    char sector;

    int auxlegajo[5] ={1,2,3,4,5};
    char *auxnombre[5] ={"jose", "carlos", "juan","roberto", "puto"};
    char *auxapellido[5]={"rodriguez","alberto","perugia","carlos","lee"};
    float auxsalario[5]= {5000, 5000, 5000, 5000, 5000};
    char auxsector[5]={'1', '2', '3', '1', '4'};
    eEmpleado empleados[TAM];
    eEmpleado auxEmpleado;

    for(i = 0; i<TAM; i++)
    {
        empleados[i].legajo = -1;
    }

    for(i = 0; i<5; i++)
    {
        empleados[i].legajo = auxlegajo[i];
        empleados[i].salario = auxsalario[i];
        empleados[i].sector = auxsector[i];
        strcpy(empleados[i].nombre, auxnombre[i]);
        strcpy(empleados[i].apellido, auxapellido[i]);
    }


    do
    {
        opcion = mostrarMenu("1-ALTAS\n2-MODIFICAR\n3-BAJAS\n4-INFORMAR\n5-LISTAR\n6-SALIR", '1', '6');
        system("cls");
        switch(opcion)
        {
            case '1':
                auxInt = buscarLibre(empleados, TAM);

                if(auxInt !=-1)
                {

                    respuesta = getName(nombre,"Ingrese el nombre: ", "ERROR: solo se permiten letras", 2, 30); // crear funcion
                    if(respuesta == -1)
                    {
                        respuesta = getName(nombre,"Ingrese el nombre: ", "ERROR: solo se permiten letras", 2, 30);
                    }
                    system("cls");
                    respuesta = getName(apellido,"Ingrese el apellido: ", "ERROR: solo se permiten letras", 2, 30);
                    if(respuesta== -1)
                    {
                        respuesta = getName(apellido,"Ingrese el apellido: ", "ERROR: solo se permiten letras", 2, 30);
                    }
                    system("cls");
                    respuesta = getFloat(&salario, "Ingrese el salario: ", "ERROR: solo se permiten numeros", 2, 999999);
                    if(respuesta == -1)
                    {
                        respuesta = getFloat(&salario, "Ingrese el salario: ", "ERROR: solo se permiten numeros", 2, 999999);
                    }
                    system("cls");
                    respuesta = getChar(&sector,"Ingrese el sector\n1-Contabilidad\n2-Administracion\n3-Compras\n4-Ventas","ERROR", '1', '4' );
                    if(respuesta == -1)
                    {
                        respuesta = getChar(&sector,"Ingrese el sector\n1-Contabilidad\n2-Administracion\n3-Compras\n4-Ventas\n","ERROR", '1', '4' );
                    }
                    system("cls");
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
                    printf("Nomina de empleados llena!\n");
                    system("pause");
                }
                system("cls");
                break;
            case '2':
                respuesta = getInt(&legajo,"Ingrese el legajo a buscar:", "ERROR: ingrese un numero valido", 0, 10000);
                for(i= 0; i<TAM; i++)
                {
                    if(empleados[i].legajo == legajo)
                    {
                        do
                        {
                            opcion = mostrarMenu("Modificar:\n1-Nombre\n2-Apellido\n3-salario\n4-Sector\n5-Salir", '1', '5');
                            system("cls");
                            switch(opcion)
                            {
                                case '1':
                                    system("cls");
                                    respuesta = getName(nombre, "Ingrese su nombre: ", "error: nombre no valido", 2, 50);
                                    strcpy(empleados[i].nombre, nombre);
                                    break;
                                case '2':
                                    system("cls");
                                    respuesta = getName(apellido, "Ingrese su apellido: ", "error: nombre no valido", 2, 50);
                                    strcpy(empleados[i].apellido, apellido);
                                    break;
                                case '3':
                                    system("cls");
                                    respuesta = getFloat(&salario, "Ingrese salario: ", "Error: salario no valido", 2, 60);
                                    empleados[i].salario = salario;
                                    break;
                                case '4':
                                    system("cls");
                                    respuesta = getChar(&sector, "Ingrese sector: ", "Error: sector no valido", 2, 60);
                                    empleados[i].sector = sector;
                                    break;
                                case '5':
                                    break;
                            }
                        }while(opcion!= '5');
                        break;
                    }
                }
                break;
            case '3':
                respuesta = getInt(&legajo,"Ingrese el legajo a buscar:", "ERROR: ingrese un numero valido", 0, 10000);
                for(i= 0; i<TAM; i++)
                {
                    if(empleados[i].legajo == legajo)
                    {
                        printf("Desea dar de baja a: s/n\n");
                        printf("Legajo\tNombre\tApellido\tSector\tSalario\n");
                        printf("%d\t%s\t%s", empleados[i].legajo, empleados[i].nombre, empleados[i].apellido);
                        printf("\t%c\t%.2f\n", empleados[i].sector, empleados[i].salario );
                        fflush(stdin);
                        scanf("%c", &opcion);
                        if(opcion == 's')
                        {
                            empleados[i].legajo = -1;
                        }
                    }   break;
                }
                break;
            case '4':
                do
                {
                    opcion = mostrarMenu("A-Nomina de empleados\nB-Total y promedio de los salarios\nC-Salir", 'A', 'C');
                    system("cls");
                    switch(opcion)
                    {
                        case 'A':
                            system("cls");
                            printf("Legajo\tNombre\tApellido\tSector\tSalario\n");
                            mostrarNomina(empleados, TAM);

                            break;
                        case 'B':
                            system("cls");
                            auxInt = 1;
                            promedio = calculoSueldo(&auxFloat, empleados, TAM);

                            printf("Importe total de sueldos: $%.2f\n", auxFloat);
                            printf("Promedio sueldo: $%.2f\n", promedio);
                            for(i=0;i<TAM; i++)
                            {
                                if((empleados[i].salario > promedio) && empleados[i].legajo != -1)
                                {
                                    if(auxInt)
                                    {
                                        printf("Empleados que superan el promedio:\n");
                                        printf("Legajo\tNombre\tApellido\tSector\tSalario\n");
                                        auxInt = 0;
                                    }

                                    mostrarEmpleado(empleados[i]);
                                }

                            }
                            break;
                        case 'C':
                            break;
                        default:
                            system("cls");
                            printf("Ingrese una opcion valida ( A o B)");

                            break;
                    }
                }while(opcion == 'A' || opcion == 'B');
                break;
            case '5':
                for( i= 0; i<TAM-1;i++)
                {
                    for(j = i+ 1; j<TAM; j++)
                    {
                        if(empleados[i].sector>empleados[j].sector)
                        {
                            auxEmpleado = empleados[i];
                            empleados[i] = empleados[j];
                            empleados[j] = auxEmpleado;
                        }
                        else if(empleados[i].sector == empleados[j].sector)
                        {
                            if(empleados[i].apellido > empleados[j].apellido)
                            {
                                auxEmpleado = empleados[i];
                                empleados[i] = empleados[j];
                                empleados[j] = auxEmpleado;
                            }
                        }
                    }
                }
                break;
            case '6':
                printf("SALIENDO...");
                break;
        }
    }while(opcion!='6');
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

void mostrarEmpleado(eEmpleado empleados)
{
    printf("%d\t%s\t%s", empleados.legajo, empleados.nombre, empleados.apellido);
    printf("\t%c\t%.2f\n", empleados.sector, empleados.salario );
}

void mostrarNomina(eEmpleado empleados[], int MAX)
{
    int i;
    for(i= 0;i<MAX; i++)
    {
        if(empleados[i].legajo != -1)
        {
            mostrarEmpleado(empleados[i]);
        }
    }

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
