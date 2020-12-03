#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "menu.h"
#include "alumno.h"
#include "informes.h"
#define TAM 10
#define TAMR 10
#define TAMP 10
#define TAMT 10

int main()
{
   // int options;
   // int flag=0;

    char confirm;
    char seguir='s';

    eMascotas pet[TAM];
    eRaza raza[TAMR];
    ePaises pais[TAMP];
    eTipo tip[TAMT];

    inicializarmascota(pet,TAM,raza,TAMR,pais,TAMP,tip,TAMT);

    harcodeoRazas(raza,7);
    harcodeoPaises(pais,7);
    hardcodeoTipos(tip,7);
    harcodeoMacotas(pet,7,raza,7,pais,7,tip,7);

    do
    {
        switch(menuPrincipal())
        {
            case 1:
                //mostrarmascota(pet,TAM,raza,TAMR,pais,TAMP); EL CHECKEADOR
                listadoInformes(pet, TAM,raza,TAMR,pais,TAMP,tip,TAMT);
        break;
            case 2:
                addMascota(pet,TAM,raza,TAMR,pais,TAMP,tip,TAMT);
        break;
            case 3:
                deletPet(pet,TAM,raza,TAMR,pais,TAMP,tip,TAMT);
        break;
            case 4:
                modificarMascota(pet,TAM,raza,TAMR,pais,TAMP,tip,TAMT);
        break;
            case 5:
            printf("\nConfirma salida?(s/n)\t");
            fflush(stdin);
            scanf("%c",&confirm);
            if(confirm=='s')
            {
                seguir='n';
            }
        break;
        }
        fflush(stdin);
        system("pause");
        system("cls");
    }
    while(seguir=='s');

    return 0;
}
