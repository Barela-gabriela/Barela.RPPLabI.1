#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.h"
#include "informes.h"
#include "alumno.h"
#include "utn.h"

/*
void showCursoPorSeparado(eMascotas pet[],int tam)
{
    int i;
    int auxCurso;

    printf("\t\t********");
    printf("\n\t\t| CURSOS |\n");
    printf("\t\t********");
    printf("\n100.1-A");
    printf("\n101.1-B");
    printf("\n102.1-C\n");

    getValidInt("\nIngrese ID del curso:\n","\n*******************  Warning  *******************\nIngrese los datos correctamente",100,102,&auxCurso);

    for(i=0;i<tam;i++)
    {
        if(pet[i].raza.idCurso==auxCurso)
        {
            showUnAlumno(pet[i]);
        }
    }
}
void cursoMayorAlumnos(eMascotas pet[],int tam)
{
    int i;
    int j;
    eMascotas auxAlumno;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(pet[i].isEmpty==0)
            {
                if(pet[i].raza.idCurso>pet[j].raza.idCurso)
                {
                    auxAlumno=pet[i];
                    pet[i]=pet[j];
                    pet[j]=auxAlumno;


                    showUnAlumno(pet[i]);
                }
            }
        }
    }
}


void segundoCuatrimestre(eMascotas pet[],int tam)
{
    int i;
    int auxCurso;

      printf("\t\t *************");
    printf("\n\t\t|CUATRIMESTRES|\n");
      printf("\t\t *************");
    printf("\n1. Primer Cuatrimestre");
    printf("\n2. Segundo Cuatrimestre\n");

    getValidInt("\nIngrese ID del cuatrimestre:\n","\n*******************  Warning  *******************\nIngrese solo caracteres",1,2,&auxCurso);

    for(i=0;i<tam;i++)
    {
        if(pet[i].raza.cuatrimestre==auxCurso)
        {
            showUnAlumno(pet[i]);
        }
    }
}

void showSexoFem(eMascotas pet[],int tam)
{
    int i;
    int auxCurso=0;

     for(i=0;i<tam;i++)
    {
        if(pet[i].sexo =='f')
        {
            //printf("%c",pet[i].sexo);
            showUnAlumno(pet[i]);
        }
    }
}
*/
/*
void deletRaza(eMascotas pet[], int tamdel)
{
    int indice;
    int raza;
    char confirm;

    printf("Baja de Raza");

     printf("\nSelecciona el id de Raza <1-4>: ");

                printf("\n 1.Siames");
                printf("\n 2.Doberman");
                printf("\n 3.Persa");
                printf("\n 4.Pastor Belga");
                fflush(stdin);
                getValidInt("\nIngrese el ID de la Raza:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-4>",1,4,&raza);
                if(raza==1)
                {
                    strcpy(pet[indice].raza.descripcion,"siames");
                }
                else if(raza==2)
                {
                    strcpy(pet[indice].raza.descripcion,"poberman");
                }
                else if(raza==3)
                {
                    strcpy(pet[indice].raza.descripcion,"persa");
                }
                else
                {
                    strcpy(pet[indice].raza.descripcion,"pastor belga");
                }


}*/
/*
void sortAlumno(eMascotas pet[], int tam)//string
{
    eMascotas auxAlumno;

    int i;
    int j;

    for(j=i+1; j<tam;i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(strcmp(pet[i].lastName,pet[j].lastName)>0)
            {
                auxAlumno= pet[i];
                pet[i]=pet[j];
                pet[j]=auxAlumno;
            }
            else if(strcmp(pet[i].lastName,pet[j].lastName)==0)
            {
                auxAlumno= pet[i];
                pet[i]=pet[j];
                pet[j]=auxAlumno;
            }
        }
    }
}
void sortSexo(eMascotas pet[], int tam)//string
{
    eMascotas auxAlumno;

    int i;
    int j;

    for(j=i+1; j<tam;i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(strcmp(pet[i].sexo,pet[j].sexo)>0)
            {
                auxAlumno= pet[i];
                pet[i]=pet[j];
                pet[j]=auxAlumno;
            }
            else if(strcmp(pet[i].sexo,pet[j].sexo)==0)
            {
                auxAlumno= pet[i];
                pet[i]=pet[j];
                pet[j]=auxAlumno;
            }
        }
    }
}
*/
