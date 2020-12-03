#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "alumno.h"
#include "menu.h"

int menuPrincipal()
{
    int opcion;

    printf("\n\t\t\t***Menu de opciones***");
    printf("\n\n");
       printf("\t\t\ --------------------------------");
    printf("\n\t\t\|1. Menu de Listados de mascotas |");
    printf("\n\t\t\|2. Alta de mascota              |");
    printf("\n\t\t\|3. Baja de Mascota              |");
    printf("\n\t\t\|4. Modificar Mascota            |");
    printf("\n\t\t\|5. Salir                        |\n");
       printf("\t\t\ --------------------------------");
       printf("\n\n");
       printf(" \t***Elija una opcion***\n\t\t Opcion Num: ");

       scanf("%d",&opcion);

       fflush(stdin);
       system("pause");
       system("cls");

       return opcion;
}

int menuInformes()
{
    int opcionInfo;
    printf("\n\t\t\t**Menu de Listados**");
    printf("\n\n");
    printf("\t\t\ ----------------------------------");
    printf("\n\t\t\|1. Listado de Mascotas            |");
    printf("\n\t\t\|2. Listado de Razas               |");
    printf("\n\t\t\|3. Listado de Razas, Pais y Tel   |");
    printf("\n\t\t\|4. Listado de Mayor Pais Mascota  |");
    printf("\n\t\t\|5. Listado Ordenado codigo Tel    |");
    printf("\n\t\t\|6. Listado tipo y promedio de peso|");
    printf("\n\t\t\|7. Listar por Tamanio y Peso      |");
    printf("\n\t\t\|8. Listado Raza y Nombre Mascota  |");
    printf("\n\t\t\|9. Listar promedio Peso del Tipo  |");
    printf("\n\t\t\|10. Listar por tipo y peso        |");
    printf("\n\t\t\|10. Listar por tipo y pais        |");
    printf("\n\t\t\|12. Salir                         |\n");
    printf("\t\t\ ----------------------------------");
    printf("\n\n");
    printf(" \t**Elija una opcion**\n\t\t Opcion Num: ");

       scanf("%d",&opcionInfo);

       fflush(stdin);
       system("pause");
       system("cls");

       return opcionInfo;
}

void razas(eRaza raz[],int tamRaz)
{
    printf("\n\t\t** LISTADO DE LAS RAZAS  **");


    for(int i=0;i<tamRaz; i++){
            if(raz[i].isEmpty==0){

        printf("%s\n", raz[i].descripcion);
            }
    }

}
