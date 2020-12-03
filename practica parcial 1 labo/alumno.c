#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#include "utn.h"
#include "division.h"
#include "menu.h"

///       *** Funciones primordiales ***

void inicializarmascota(eMascotas pet[],int tam,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip)
{
    int i;

    for(i=0; i<tam; i++)
    {
        pet[i].isEmpty=1;///si esta vacio es 1 (1=verdadero y 0=falso)
        raz[i].isEmpty=1;
        aPais[i].isEmpty=1;
        tip[i].isEmpty=1;
    }
}

int buscarLugarLibre(eMascotas pet[],int tam,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip)
{
    int indice=-1;///Para que empiece en 0
    int i;

    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==1) ///Pregunto si esta vacio (1 puerta aberta =! 0 puerta cerrada)
        {
            indice=i;
            break;
        }
        if(raz[i].isEmpty==1)
        {
            indice=i;
            break;
        }
        if(aPais[i].isEmpty==1)
        {
            indice=i;
            break;
        }
        if(tip[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int buscarMascotaPorId(int id,eMascotas pet[],int tam,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip)
{
    int indice=-1;///Empiezo desde 0
    int i;

    for(i=0; i<tam; i++)
    {
        if(pet[i].id==id && pet[i].isEmpty==0 && raz[i].idR==id && raz[i].isEmpty==0 && aPais[i].idP==id && aPais[i].isEmpty==0 && tip[i].isEmpty==0 && tip[i].idT)///Pregunta si existe el ID
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int generarNextId()
{
    static int id=0;
    id ++;
    return id;
}
///*** Funciones no tan primordiales pero necesarias para el funcionamiento de esta empresa***

int addMascota(eMascotas pet[],int tam,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip)
{
    int indice= buscarLugarLibre(pet,tam,raz,tamRaz,aPais,tamPais,tip,tamTip);///devuelve al indice a -1 cada vez que busca Id

    int myReturn=-1;

    char auxName[50];
    char auxSexo;

    int auxAge;
    int auxTipo;
    int auxTamanio;
    int auxPais;
    int auxRaza;
    int auxPeso;

    system("cls");
    printf("\nAlta de Mascotas\n");

    if(indice == -1)///HAY LUGAR?
    {
        printf("\nSistema Completo\n");
    }
    else
    {

        pet[indice].id=generarNextId();
        fflush(stdin);

        getValidString("\nIngrese Nombre\n","\n*******************  Warning  *******************\nIngrese solo caracteres","\nError se exedio del limite de caracteres\n",auxName,3,50);

        ///Nombre

        strcpy(pet[indice].nombre,auxName);

        ///Edad

        printf("Ingresa edad de la mascota:  \n");
        scanf("%d",&auxAge);
        pet[indice].edad=auxAge;

        ///Peso

        printf("Ingresa Peso de la mascota:  \n");
        scanf("%d",&auxPeso);
        pet[indice].peso=auxPeso;

        ///Edad

        fflush(stdin);
        getSexChar("\nSexo de la mascota:<f-m>\n","\n*******************  Warning  *******************\nIngrese solo caracteres",&auxSexo);
        pet[indice].sexo=auxSexo;

        /// TIPO

        printf("\nSelecciona el id de tipo <1-3>: ");

        printf("\n 1.Perro");
        printf("\n 2.Gato");
        printf("\n 3.Raro");

        fflush(stdin);
        getValidInt("\nIngrese el ID del tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-3>",1,3,&auxTipo);
        if(auxTipo==1)
        {
            strcpy(tip[indice].tipo,"Perro");
            pet[indice].tipo=tip[indice];
               mostrarPerro(pet,tam,tip,tamTip,raz,tamRaz,aPais,tamPais);

        }
        else if(auxTipo==2)
        {
            strcpy(tip[indice].tipo,"Gato");
             pet[indice].tipo=tip[indice];
              mostrarGato(pet,tam,tip,tamTip,raz,tamRaz,aPais,tamPais);
        }
        else
        {
            strcpy(tip[indice].tipo,"Raro");
            pet[indice].tipo=tip[indice];
              mostrarRaro(pet,tam,tip,tamTip,raz,tamRaz,aPais,tamPais);
        }
    }



    /// RAZA

    printf("\nSelecciona el id de Raza <1-5>: ");

    printf("\n 1.Siames");
    printf("\n 2.Doberman");
    printf("\n 3.Persa");
    printf("\n 4.Pastor Belga");
    printf("\n 5.Dogo");
    printf("\n 6.Pastor Aleman");
    fflush(stdin);
    getValidInt("\nIngrese el ID de la Raza:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-5>",1,6,&auxRaza);
    if(auxRaza==1)
    {
        strcpy(raz[indice].descripcion,"Siames");

    }
    else if(auxRaza==2)
    {
        strcpy(raz[indice].descripcion,"Poberman");

    }
    else if(auxRaza==3)
    {
        strcpy(raz[indice].descripcion,"Persa");

    }
    else if(auxRaza==4)
    {
        strcpy(raz[indice].descripcion,"Pastor belga");

    }
    else if(auxRaza==5)
    {
        strcpy(raz[indice].descripcion,"Dogo");

    }
    else
    {
        strcpy(raz[indice].descripcion,"Pastor aleman");

    }

    /// TAMANIO
    printf("\nSelecciona el id de Mascota <1-3>: ");

    printf("\n 1.Grande");
    printf("\n 2.Mediano");
    printf("\n 3.Chico");

    fflush(stdin);
    getValidInt("\nIngrese el ID del tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-3>",1,3,&auxTamanio);
    if(auxTamanio==1)
    {
        strcpy(raz[indice].tamanio,"Grande");
        pet[indice].raza=raz[indice];
    }
    else if(auxTamanio==2)
    {
        strcpy(raz[indice].tamanio,"Chico");
        pet[indice].raza=raz[indice];
    }
    else
    {
        strcpy(raz[indice].tamanio,"Mediano");
        pet[indice].raza=raz[indice];
    }

    /// PAIS-CONTONENTE-CODIGO TELEFONICO

    printf("\nSelecciona el id del Pais <1-5>: ");

    printf("\n 1.Tailandia");
    printf("\n 2.Alemania");
    printf("\n 3.Persia");
    printf("\n 4.Belgica");
    printf("\n 5.Argentina");

    fflush(stdin);
    getValidInt("\nIngrese el ID del tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-5>",1,5,&auxPais);
    if(auxPais==1)
    {
        strcpy(aPais[indice].paises,"Tailandia");
        aPais[indice].codigoTel=66;
        strcpy(aPais[indice].continente,"Asia");
        pet[indice].pais=aPais[indice];
    }
    else if(auxPais==2)
    {
        strcpy(aPais[indice].paises,"Alemania");
        aPais[indice].codigoTel=49;
        strcpy(aPais[indice].continente,"Europa");
        pet[indice].pais=aPais[indice];
    }
    else if(auxPais==3)
    {
        strcpy(aPais[indice].paises,"Persia");
        aPais[indice].codigoTel=98;
        strcpy(aPais[indice].continente,"Africano");
        pet[indice].pais=aPais[indice];
    }
    else if(auxPais==4)
    {
        strcpy(aPais[indice].paises,"Belgica");
        aPais[indice].codigoTel=32;
        strcpy(aPais[indice].continente,"Eropa");
        pet[indice].pais=aPais[indice];
    }
    else
    {
        strcpy(aPais[indice].paises,"Argentina");
        aPais[indice].codigoTel=54;
        strcpy(aPais[indice].continente,"America");
        pet[indice].pais=aPais[indice];
    }

    pet[indice].isEmpty=0;
    aPais[indice].isEmpty=0;
    raz[indice].isEmpty=0;


    return myReturn;
}

void deletPet(eMascotas pet[],int tamDel, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip)
{
    int indice;
    int id;
    char confirm;

    printf("Baja de Mascotas");
    printf("\nIngrese ID");

    scanf("%d",&id);

    indice=buscarMascotaPorId(id,pet,tamDel,raz,tamRaz,aPais,tamPais,tip,tamTip);

    if(indice==-1)
    {
        printf("\nNo hay registro de una Mascota con el id: %d",id);
    }
    else
    {
        printf("\nConfirma Baja?(s/n)");
        fflush(stdin);
        scanf("%c",&confirm);


        if(confirm== 's')
        {
            pet[indice].isEmpty=1;
            aPais[indice].isEmpty=1;
            raz[indice].isEmpty=1;
            tip[indice].isEmpty=1;


            printf("\nSe a realizado la baja con exito");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}

void borrarRaza(eRaza raz[],char razaBorrar[],int tam)
{
    int i;
    for(i=0; i<tam-1; i++)
    {
        if(raz[i].isEmpty==0)
        {
            if((strcmp(raz[i].descripcion, razaBorrar)) == 0)
            {
                raz[i].isEmpty=1;
            }
        }
    }
}

void seleccionBorrarRaza(eMascotas pet[],int tam, eRaza raz[])
{
    printf("\nSelecciona el id de Raza <1-4>: ");
    int auxRaza;
    printf("\n 1.Siames");
    printf("\n 2.Doberman");
    printf("\n 3.Persa");
    printf("\n 4.Pastor Belga");
    fflush(stdin);
    getValidInt("\nIngrese el ID de la Raza:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-4>",1,4,&auxRaza);
    if(auxRaza==1)
    {
        borrarRaza(raz, "Siames", tam);
    }
    else if(auxRaza==2)
    {
        borrarRaza(raz, "Doberman",tam);
    }
    else if(auxRaza==3)
    {
        borrarRaza(raz, "Persa",tam);
    }
    else if(auxRaza==4)
    {
        borrarRaza(raz, "Pastor Belga",tam);
    }
    else if(auxRaza==5)
    {
        borrarRaza(raz, "Dogo",tam);
    }
    else
    {
        borrarRaza(raz, "Pastor Aleman",tam);
    }
}

void modificarMascota(eMascotas pet[],int tamMod, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip)
{

    int options;
    int id;
    int indice;
    char confirm;
    char auxName[50];
    char auxSexo;

    int auxAge;
    int auxTipo;
    int auxTamanio;
    int auxPais;
    int auxRaza;
//    int auxPeso;

    printf("Modificar Mascota");
    printf("\nIngrese Id: ");
    scanf("%d",&id);

    indice=buscarMascotaPorId(id,pet,tamMod,raz,tamRaz,aPais,tamPais,tip,tamTip);
    if(indice==-1)
    {
        printf("\nNo hay registro de un Mascota con el id: %d",id);
    }
    else
    {

        printf("\nModificar Mascotas?(s/n)");
        fflush(stdin);
        scanf("%c",&confirm);

        if(confirm=='s')
        {
            printf("\nQue desa modificar?");
            printf("\n1.Nombre");
            printf("\n2.Edad");
            printf("\n3.Sexo");
            printf("\n4.Iipo");
            printf("\n5.Raza");
            printf("\n6.Tamanio");
            printf("\n7.Pais");

            scanf("%d",&options);
            switch(options)
            {
            case 1:
                getValidString("\nIngrese Nombre\n","\n*******************  Warning  *******************\nIngrese solo caracteres","\nError se exedio del limite de caracteres\n",auxName,3,50);

                strcpy(pet[indice].nombre,auxName);
                break;
            case 2:
                printf("Ingresa edad de la mascota:  \n");
                fflush(stdin);
                scanf("%d",&auxAge);
                break;
            case 3:
                fflush(stdin);
                getSexChar("\nSexo de la mascota:<f-m>\n","\n*******************  Warning  *******************\nIngrese solo caracteres",&auxSexo);
                pet[indice].sexo=auxSexo;
                break;
            case 4:
                printf("\nSelecciona el id de tipo <1-3>: ");

                printf("\n 1.Perro");
                printf("\n 2.Gato");
                printf("\n 3.Raro");

                fflush(stdin);
                getValidInt("\nIngrese el ID del tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-3>",1,3,&auxTipo);
                if(auxTipo==1)
                {
                    strcpy(tip[indice].tipo,"Perro");
                }
                else if(auxTipo==2)
                {
                    strcpy(tip[indice].tipo,"Gato");
                }
                else
                {
                    strcpy(tip[indice].tipo,"Raro");
                }

                break;
            case 5:
                printf("\nSelecciona el id de Raza <1-6>: ");

                printf("\n 1.Siames");
                printf("\n 2.Doberman");
                printf("\n 3.Persa");
                printf("\n 4.Pastor Belga");
                printf("\n 5.Dogo");
                printf("\n 6.Pastor Aleman");
                fflush(stdin);
                getValidInt("\nIngrese el ID de la Raza:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-6>",1,6,&auxRaza);
                if(auxRaza==1)
                {
                    strcpy(raz[indice].descripcion,"Siames");
                }
                else if(auxRaza==2)
                {
                    strcpy(raz[indice].descripcion,"Doberman");
                }
                else if(auxRaza==3)
                {
                    strcpy(raz[indice].descripcion,"Persa");
                }
                else if(auxRaza==4)
                {
                    strcpy(raz[indice].descripcion,"Pastor Belga");
                }
                else if(auxRaza==5)
                {
                    strcpy(raz[indice].descripcion,"Dogo");
                }
                else
                {
                    strcpy(raz[indice].descripcion,"Pastor Aleman");
                }
                break;
            case 6:
                printf("\nSelecciona el id de Mascota <1-3>: ");

                printf("\n 1.Grande");
                printf("\n 2.Mediano");
                printf("\n 3.Chico");

                fflush(stdin);
                getValidInt("\nIngrese el ID del tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-3>",1,3,&auxTamanio);
                if(auxTamanio==1)
                {
                    strcpy(raz[indice].tamanio,"Grande");
                }
                else if(auxTamanio==2)
                {
                    strcpy(raz[indice].tamanio,"Chico");
                }
                else
                {
                    strcpy(raz[indice].tamanio,"Mediano");
                }
                break;
            case 7:
                printf("\nSelecciona el id del Pais <1-5>: ");

                printf("\n 1.Tailandia");
                printf("\n 2.Alemania");
                printf("\n 3.Persia");
                printf("\n 4.Belgica");
                printf("\n 5.Argentina");

                fflush(stdin);
                getValidInt("\nIngrese el ID del tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-5>",1,5,&auxPais);
                if(auxPais==1)
                {
                    strcpy(aPais[indice].paises,"Tailandia");
                    aPais[indice].codigoTel=66;
                    strcpy(aPais[indice].continente,"Asia");
                }
                else if(auxPais==2)
                {
                    strcpy(aPais[indice].paises,"Alemania");
                    aPais[indice].codigoTel=49;
                    strcpy(aPais[indice].continente,"Europa");
                }
                else if(auxPais==3)
                {
                    strcpy(aPais[indice].paises,"Persia");
                    aPais[indice].codigoTel=98;
                    strcpy(aPais[indice].continente,"Africano");
                }
                else if(auxPais==4)
                {
                    strcpy(aPais[indice].paises,"Belgica");
                    aPais[indice].codigoTel=32;
                    strcpy(aPais[indice].continente,"Eropa");
                }
                else
                {
                    strcpy(aPais[indice].paises,"Argentina");
                    aPais[indice].codigoTel=54;
                    strcpy(aPais[indice].continente,"America");
                }
                break;
            }
            printf("\nSe a realizado la modificacion con exito");
        }
        else
        {
            printf("\nSe ha cancelado la operacion");
        }
    }
}

void harcodeoRazas(eRaza raza[], int tamRaza)
{
    int i;

    char desRaza[7][50]= {"Siames","Doberman","Persa","Pastor Belga","Siames","Dogo","Pastor Aleman"};
    char desTam[7][50]= {"Grande","Mediano","Chico","Grande","Mediano","Mediano","Grande"};

    for(i=0; i<7; i++)
    {
        strcpy(raza[i].descripcion,desRaza[i]);
        strcpy(raza[i].tamanio,desTam[i]);

        raza[i].isEmpty=0;
    }
}

void hardcodeoTipos(eTipo tip[], int tamtip)
{
    int i;

    char tipo[7][50]= {"Perro","Gato","Perro","Gato","Gato","Raro","Perro"};

    for(i=0; i<7; i++)
    {
        strcpy(tip[i].tipo,tipo[i]);
        tip[i].isEmpty=0;
    }
}

void harcodeoMacotas(eMascotas pet[],int tam, eRaza raza[],int tamRaza,ePaises apais[],int tamPais,eTipo tip[],int tamTip)
{
    int i;

    char namePet[7][50]= {"titan","peluza","man","yackye","goeb","DD","Momo"};
    char sexoPet[7] = {'m','f','m','f','f','m','f'};
    int ages[7]= {1,2,3,4,5,6,7};
    int peso[7]= {10,20,4,2,5,6,9};

    for(i=0; i<7; i++)
    {
        pet[i].id=generarNextId();
        pet[i].peso=peso[i];
        pet[i].edad=ages[i];
        pet[i].sexo=sexoPet[i];
        pet[i].tipo=tip[i];
         pet[i].pais=apais[i];
        //strcpy(tip[i].tipo,tipo[i]);
        strcpy(pet[i].nombre,namePet[i]);

        pet[i].isEmpty=0;
    }
}

void harcodeoPaises(ePaises pais[],int tamPais)
{
    int i;

    int codigoTel[7]= {66,49,98,32,66,54,49};
    char desPais[7][50]= {"Tailandia","Alemania","Persia","Belgica","Tailandia","Argentina","Alemania"};
    char continente[7][50]= {"Asia","Europa","Africano","Europa","Asia","Americano","Europa"};

    for(i=0; i<7; i++)
    {
        pais[i].codigoTel=codigoTel[i];
        strcpy(pais[i].paises,desPais[i]);
        strcpy(pais[i].continente,continente[i]);

        pais[i].isEmpty=0;
    }
}



///                 ***Funciones para mostrar***



void mostrarmascota(eMascotas pet[],int tam, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip)///LISTADO COMPLETO
{
    int i;
    printf("\n\t\t\t\t***LISTA DE MASCOTAS***\n\n");
    printf("  *************************************************************************************************************\n");
    printf(" |ID  Mascota      edad       sexo        tipo      raza     tamanio         pais    codigo Telefonico     Peso|");
    printf("\n  *************************************************************************************************************\n\n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0 && raz[i].isEmpty==0  )
        {
            printf("%d %10s %10d %10c %10s  %10s  %10s %10s %10d %15d\n\n",pet[i].id,pet[i].nombre,pet[i].edad,pet[i].sexo,tip[i].tipo,raz[i].descripcion,raz[i].tamanio,aPais[i].paises,aPais[i].codigoTel,pet[i].peso);
        }
    }
}

void mostrarRazaPaisTelefono(eMascotas pet[],int tam, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais)
{
    int i;
    printf("\n\t\t\t\t***LISTA DE MASCOTAS***\n\n");
    printf("  ************************************************************\n");
    printf(" |ID  Mascota        raza          pais    codigo Telefonico  |");
    printf("\n  ************************************************************\n\n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0 && raz[i].isEmpty==0)
        {
            printf("   %d %10s  %10s %15s %15d \n\n",pet[i].id,pet[i].nombre,raz[i].descripcion,aPais[i].paises,aPais[i].codigoTel);
        }
    }
}


void mostrarRazaPaisTipoUno(eMascotas pet, eRaza raz,ePaises aPais)
{

    printf("\n\t\t\t\t***LISTA DE MASCOTAS***\n\n");
    printf("  ************************************************************\n");
    printf(" |ID  Mascota        raza          pais    codigo  tipo  |");
    printf("\n  ************************************************************\n\n");


        if(pet.isEmpty==0 && raz.isEmpty==0)
        {
            printf(" %d %10s  %10s %15s %15s \n\n",pet.id,pet.nombre,raz.descripcion,aPais.paises,pet.tipo.tipo);
        }

}


void sortTipo(eTipo tip[],int tamTip)
{
    eTipo auxRaz;
    int i;
    for(i=0; i<tamTip-1; i++)
    {
        for(int j=i+1; j<tamTip; j++)
        {
            if(tip[i].isEmpty==0)
            {
                if(strcmp(tip[i].tipo,tip[j].tipo)>0 )
                {
                    auxRaz=tip[i];
                    tip[i]=tip[j];
                    tip[j]=auxRaz;
                }
                /*else  if(strcmp(raz[i].tamanio,raz[j].tamanio)==0 && raz[i].idR==raz[j].idR)
                {
                    auxRaz=raz[i];
                    raz[i]=raz[j];
                    raz[j]=auxRaz;
                }*/
            }
        }
    }
}


void sortTipo2(eMascotas pet[],int tam,eTipo tip[],int tamTip)
{
    eMascotas auxPet;
    eTipo auxT;
    int i;
    for(i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(pet[i].isEmpty==0)
            {
                if(pet[i].peso<pet[j].peso)
                {
                    auxPet=pet[i];
                    pet[i]=pet[j];
                    pet[j]=auxPet;
                }
                if(strcmp(tip[i].tipo,tip[j].tipo)>0)
                {
                    auxT=tip[i];
                    tip[i]=tip[j];
                    tip[j]=auxT;
                }
                else  if(strcmp(tip[i].tipo,tip[j].tipo)==0 && tip[i].idT==tip[j].idT )
                {
                    auxT=tip[i];
                    tip[i]=tip[j];
                    tip[j]=auxT;
                }
            }
        }
    }
}
void mostrarTipoPeso(eMascotas pet[],int tam,eTipo tip[],int tamTip)
{
  int i;

    int contadorPerro=0;
    int contadorGato=0;
    int contadorRaro=0;

    int aucmPerro=0;
    int aucmGato=0;
    int aucmRaro=0;
    sortTipo(tip,tamTip);


    printf("\n\t\t\t\t**LISTA DE MASCOTAS**\n\n");
    printf("  ************\n");
    printf(" |ID          tipo           Peso  |");
    printf("\n  ************\n\n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if (strcmp(tip[i].tipo,"Perro")==0)
            {
                contadorPerro++;
                aucmPerro=pet[i].peso+aucmPerro;
            }
            else if(strcmp(tip[i].tipo,"Gato")==0)
            {
                contadorGato++;
                aucmGato=pet[i].peso+aucmGato;
            }
            else
            {
                contadorRaro++;
                aucmRaro=pet[i].peso+aucmRaro;
            }
            printf(" %d  %10s  %10d \n\n",pet[i].id,tip[i].tipo,pet[i].peso);

        }
    }

    printf("\nCantidad perros: %d\n",contadorPerro);
    printf("Suma peso perros: %d\n",aucmPerro);
    printf("promedio peso perros: %.2f\n\n",(float)aucmPerro/contadorPerro);


    printf("\nCantidad gatos: %d\n",contadorGato);
    printf("Suma peso gatos: %d\n",aucmGato);
    printf("Promedio peso gatos: %.2f\n\n",(float)aucmGato/contadorGato);


    printf("\nCantidad raros: %d\n",contadorRaro);
    printf("Suma peso raros: %d\n",aucmRaro);
    printf("Promedio peso raros: %.2f\n\n",(float)aucmRaro/contadorRaro);

}
void mostrarPesito(eMascotas pet[],int tam,eTipo tip[],int tamTip)
{
    int i;

    int contadorPerro=0;
    int contadorGato=0;
    int contadorRaro=0;

    int aucmPerro=0;
    int aucmGato=0;
    int aucmRaro=0;

    sortTipo(tip,tamTip);


    printf("\n\t\t\t\t***LISTA DE MASCOTAS***\n\n");
    printf("  ************************************\n");
    printf(" |ID          tipo           Peso  |");
    printf("\n  ************************************\n\n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if (strcmp(tip[i].tipo,"Perro")==0)
            {
                contadorPerro++;
                aucmPerro=pet[i].peso+aucmPerro;
            }
            else if(strcmp(tip[i].tipo,"Gato")==0)
            {
                contadorGato++;
                aucmGato=pet[i].peso+aucmGato;
            }
            else
            {
                contadorRaro++;
                aucmRaro=pet[i].peso+aucmRaro;
            }
            printf("   %d  %10s  %15d \n\n",pet[i].id,tip[i].tipo,pet[i].peso);

        }
    }
}
void mostrarGrande(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises apais[],int tamPais)
{
    int i;
    int contadorPeso=0;
    int acumPeso=0;

    printf("\nTAMANIO     PAIS        TIPO      PESO\n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0 && raz[i].isEmpty==0 )
        {
            if(strcmp(raz[i].tamanio,"Grande")==0)
            {
                contadorPeso++;
                acumPeso+=pet[i].peso;
                printf("\n %s %10s %10s %10d\n",raz[i].tamanio,apais[i].paises,tip[i].tipo,pet[i].peso);
            }
        }
    }
    printf("\nSuma total peso Grandes: %d\n",acumPeso);
    printf("\n\n");
}









void mostrarPerro(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises apais[],int tamPais)
{
    int i;

    printf("\ MASCOTA  PAIS        TIPO      \n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0 && raz[i].isEmpty==0 )
        {
            if(strcmp(pet[i].tipo.tipo,"Perro")==0)
            {

                printf("\n %s %10s %10s \n",pet[i].nombre,pet[i].pais.paises,pet[i].tipo.tipo);
            }
        }
    }
    printf("\n\n");
}





void mostrarGato(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises apais[],int tamPais)
{
    int i;


    printf("\ MASCOTA  PAIS        TIPO      \n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0 && raz[i].isEmpty==0 )
        {
            if(strcmp(pet[i].tipo.tipo,"Gato")==0)
            {

                printf("\n %s %10s %10s \n",pet[i].nombre,pet[i].pais.paises,pet[i].tipo.tipo);
            }
        }
    }
    printf("\n\n");
}






void mostrarRaro(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises apais[],int tamPais)
{
    int i;

    printf("\ MASCOTA  PAIS        TIPO      \n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(strcmp(pet[i].tipo.tipo,"Raro")==0)
            {

                printf("\n %s %10s %10s \n",pet[i].nombre,pet[i].pais.paises,pet[i].tipo.tipo);
            }
        }
    }
    printf("\n\n");
}

























void mostrarTodosLosTipos(eMascotas pet[],int tam,eTipo tip[],int tamTip)
{

    int acumPesoGato=0;
    int cantidadGato=0;


    int acumPesoPerro=0;
    int cantidadPerro=0;


    int acumPesoRaro=0;
    int cantidadRaro=0;

    for(int i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(strcmp(tip[i].tipo,"Perro")==0)
            {
                cantidadPerro++;
                acumPesoPerro+=pet[i].peso;
            }
        }
    }

    for(int i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(strcmp(tip[i].tipo,"Gato")==0)
            {
                cantidadGato++;
                acumPesoGato+=pet[i].peso;
            }
        }
    }
    for(int i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(strcmp(tip[i].tipo,"Raro")==0)
            {
                cantidadRaro++;
                acumPesoRaro+=pet[i].peso;
            }
        }
    }

    printf("\nSuma total peso Gato: %d\n",acumPesoGato);
    printf("\Promedio total peso Gato: %.2f\n",(float)acumPesoGato/cantidadGato);
    printf("\nCantidad Gatos: %d\n",cantidadGato);
    printf("\n\n");

    printf("\nSuma total peso Perro: %d\n",acumPesoPerro);
    printf("\Promedio total peso Perro: %.2f\n",(float)acumPesoPerro/cantidadPerro);
    printf("\nCantidad Perros: %d\n",cantidadPerro);
    printf("\n\n");

    printf("\nSuma total peso Raro: %d\n",acumPesoRaro);
    printf("\Promedio total peso Raro: %.2f\n",(float)acumPesoRaro/cantidadRaro);
    printf("\nCantidad Raros: %d\n",cantidadRaro);
    printf("\n\n");

}

void mostrarMediano(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises apais[],int tamPais)
{
    int i;
    int contadorPeso=0;
    int acumPeso=0;

    printf("TAMANIO     PAIS    TIPO    PESO\n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(strcmp(raz[i].tamanio,"Mediano")==0)
            {
                contadorPeso++;
                acumPeso=pet[i].peso+acumPeso;
                printf("\n %s %10s %10s %10d\n",raz[i].tamanio,apais[i].paises,tip[i].tipo,pet[i].peso);
            }
        }
    }
    printf("\nSuma total peso Mediano: %d\n",acumPeso);
    printf("\n\n");
}
void mostrarChico(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises apais[],int tamPais)
{
    int i;
    int contadorPeso=0;
    int acumPeso=0;

    printf("TAMANIO     PAIS    TIPO    PESO\n");
    for(i=0; i<tam; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(strcmp(raz[i].tamanio,"Chico")==0)
            {
                contadorPeso++;
                acumPeso=pet[i].peso+acumPeso;
                printf("\n %s %10s %10s %10d\n",raz[i].tamanio,apais[i].paises,tip[i].tipo,pet[i].peso);
            }
        }
    }
    printf("\nSuma total peso Chico: %d\n",acumPeso);
    printf("\n\n");
}
void infoTamPeso(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises apais[],int tamPais)
{
    int i;
    int auxTamanio;
    printf("\nSelecciona el id de Tamanio <1-3>: ");

    printf("\n 1.Grande");
    printf("\n 2.Mediano");
    printf("\n 3.Chico");
    fflush(stdin);
    getValidInt("\nIngrese el ID del tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-3>",1,3,&auxTamanio);

    for(i=0; i<1; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(auxTamanio==1)
            {
                mostrarGrande(pet,tam,tip,tamTip,raz,tamRaz,apais,tamPais);
            }
            else if(auxTamanio==2)
            {
                mostrarMediano(pet,tam,tip,tamTip,raz,tamRaz,apais,tamPais);
            }
            else
            {
                mostrarChico(pet,tam,tip,tamTip,raz,tamRaz,apais,tamPais);
            }
        }
    }
}


void infoTipo(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises apais[],int tamPais)
{
    int i;
    int auxTipo;
    printf("\nSelecciona el id de Tamanio <1-3>: ");

    printf("\n 1.Perro");
    printf("\n 2.Gato");
    printf("\n 3.Raro");
    fflush(stdin);
    getValidInt("\nIngrese el ID del tipo:\n","\n*******************  Warning  *******************\nIngrese solo numeros del <1-3>",1,3,&auxTipo);

    for(i=0; i<1; i++)
    {
        if(pet[i].isEmpty==0)
        {
            if(auxTipo==1)
            {
               mostrarPerro(pet,tam,tip,tamTip,raz,tamRaz,apais,tamPais);
            }
            else if(auxTipo==2)
            {
              mostrarGato(pet,tam,tip,tamTip,raz,tamRaz,apais,tamPais);
            }
            else
            {
              mostrarRaro(pet,tam,tip,tamTip,raz,tamRaz,apais,tamPais);
            }
        }
    }
}



void sortMascotaPeso(eMascotas pet[],int tam)
{
    eMascotas auxPet;

    int i;
    int j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(pet[i].isEmpty==0)
            {
                if(pet[i].peso<pet[j].peso)
                {
                    auxPet=pet[i];
                    pet[i]=pet[j];
                    pet[j]=auxPet;
                }
            }
        }
    }
}

void sortMascotaTel(ePaises apais[],int tam)
{
    ePaises auxPais;

    int i;
    int j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(apais[i].isEmpty==0)
            {
                if(apais[i].codigoTel<apais[j].codigoTel)
                {
                    auxPais=apais[i];
                    apais[i]=apais[j];
                    apais[j]=auxPais;
                }
            }
        }
    }
}

void mostrarRazas(eMascotas pet[],int tam, eRaza raz[], int tamRaz)
{
    int i;
    printf("Nombre    Raza\n ");
    for(i=0; i<tam; i++)
    {
        if (pet[i].isEmpty== 0  && pet[i].isEmpty== 0)
        {

            printf("\n %s   %10s\n",pet[i].nombre,raz[i].descripcion);
        }
    }
}

void mostrarTamPeso(eMascotas pet[],int tam, eRaza raz[], int tamRaz)
{
    int i;
    printf("nombre    Tamanio  Peso\n ");
    for(i=0; i<tam; i++)
    {
        if (pet[i].isEmpty== 0 && raz[i].isEmpty== 0)
        {

            printf("\n %10s   %10s %d\t\n",pet[i].nombre,raz[i].tamanio,pet[i].peso);
        }
    }
}

void showUnMascota(ePaises aPais)
{
    printf("\n%s\t\n",aPais.paises);
}

void sortPet(eRaza raz[],int tam)
{
    eRaza auxRaz;
    int i;
    for(i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(raz[i].isEmpty==0)
            {
                if(strcmp(raz[i].tamanio,raz[j].tamanio)>0 )
                {
                    auxRaz=raz[i];
                    raz[i]=raz[j];
                    raz[j]=auxRaz;
                }
                else  if(strcmp(raz[i].tamanio,raz[j].tamanio)==0 && raz[i].idR==raz[j].idR)
                {
                    auxRaz=raz[i];
                    raz[i]=raz[j];
                    raz[j]=auxRaz;
                }
            }
        }
    }
}

void sortMascota(ePaises apais[],int tam)
{
    ePaises auxPais;

    int i;
    int j;

    for(i=0; i<tam-1; i++)
    {
        for(j=i+1; j<tam; j++)
        {
            if(apais[i].isEmpty==0)
            {
                if(apais[i].codigoTel<apais[j].codigoTel)
                {
                    auxPais=apais[i];
                    apais[i]=apais[j];
                    apais[j]=auxPais;
                }
            }
        }
    }
}

///                 INFORMES
void listadoInformes(eMascotas pet[],int tam, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[], int tamTip)
{
//    int opcionInfo;
    char seguirInfo= 's';
    char confirmInfo;

    do
    {
        switch(menuInformes())
        {
        case 1:
            sortTipo(tip,tamTip);
            mostrarmascota(pet,tam,raz,tamRaz,aPais,tamPais,tip,tamTip);
            break;
        case 2:
            razas(raz,tamRaz);
            break;
        case 3:
            mostrarRazaPaisTelefono(pet,tam,raz,tamRaz,aPais,tamPais);
            break;
        case 4:
            listadoMayorPais(aPais,tam);
            break;
        case 5:
            sortMascotaTel(aPais,tamPais);
            mostrarmascota(pet,tam,raz,tamRaz,aPais,tamPais,tip,tamTip);
            break;
        case 6:
             infoTamPeso(pet,tam,tip,tamTip,raz,tamRaz,aPais,tamPais);
            break;
        case 7:
            mostrarTamPeso(pet,tam,raz,tamRaz);
            break;
        case 8:
            mostrarRazas(pet,tam,raz,tamRaz);
            break;
        case 9:
           mostrarTipoPeso(pet,tam,tip,tamTip);
            break;
        case 10:
            sortTipo2(pet,tam,tip,tamTip);
            //sortTipoPeso(pet,tam,tip,tamTip);
            mostrarmascota(pet,tam,raz,tamRaz,aPais,tamPais,tip,tamTip);
            break;
            case 11:
            infoTipo(pet,tam,tip,tamTip,raz,tamRaz,aPais,tamPais);
            break;
        case 12:
            printf("\nConfirma salida?(s/n)\t");
            fflush(stdin);
            scanf("%c",&confirmInfo);
            if(confirmInfo=='s')
            {
                seguirInfo='n';
            }
            break;
        }
        fflush(stdin);
        system("pause");
        system("cls");

    }
    while(seguirInfo=='s');
}
void sortTipoPeso(eMascotas pet[],int tam,eTipo tip[],int tamTip)
{
    eMascotas auxPet;
    eTipo auxT;
    int i;
    for(i=0; i<tam-1; i++)
    {
        for(int j=i+1; j<tam; j++)
        {
            if(pet[i].isEmpty==0)
            {
                if(pet[i].peso<pet[j].peso)
                {
                    auxPet=pet[i];
                    pet[i]=pet[j];
                    pet[j]=auxPet;
                }
                if(strcmp(tip[i].tipo,tip[j].tipo)>0)
                {
                    auxT=tip[i];
                    tip[i]=tip[j];
                    tip[j]=auxT;
                }
                else  if(strcmp(tip[i].tipo,tip[j].tipo)==0 && tip[i].idT==tip[j].idT )
                {
                    auxT=tip[i];
                    tip[i]=tip[j];
                    tip[j]=auxT;
                }
            }
        }
    }
    mostrarPesito(pet,tam,tip,tamTip);
}

void listadoMayorPais(ePaises aPais[], int tam)
{
    //int j;
    int contador=0;
    int paisMayor=0;
    int flag=0;

    for(int i=0; i<tam-1; i++)
    {
        contador=0;
        for(int j= i+1 ; j<tam; j++)
        {
            if (aPais[i].isEmpty==0)
            {

                if(strcmp(aPais[i].paises,aPais[j].paises)==0)
                {
                    contador ++;
                }
            }
        }
        if((contador>paisMayor)||(flag==0))
        {
            paisMayor=contador;
            flag=1;
        }
    }
    for(int i=0; i<tam-1; i++)
    {
        contador=0;
        for(int j= i+1 ; j<tam; j++)
        {
            if (aPais[i].isEmpty==0)
            {
                if(strcmp(aPais[i].paises,aPais[j].paises)==0)
                {
                    contador++;
                }
            }
        }
        if(contador==paisMayor)
        {
            printf("El pais con mayor cantidad en la veterinaria es: %s \n",aPais[i].paises);
        }
    }
}


