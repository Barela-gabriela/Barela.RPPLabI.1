#ifndef ALUMNO_H_INCLUDED
#define ALUMNO_H_INCLUDED
typedef struct
{
    char paises[50];
    char continente[50];
    int idP;
    int codigoTel;
    int isEmpty;
}ePaises;
typedef struct
{
    int idT;
    int isEmpty;
    char tipo[50];

}eTipo;
typedef struct
{
    int idR;
    char descripcion[50];
    char tamanio[50];
    int isEmpty;
}eRaza;
typedef struct
{
    int id;
    int edad;
    int peso;
    int isEmpty;
    char nombre[50];
    char sexo;
    eRaza raza;
    ePaises pais;
    eTipo tipo;
}eMascotas;


///         Funciones Macotas

/// Funciones para mostrar

void showUnMascota(ePaises aPais);

void showMascotas(eMascotas pet[],int tam);

void mostrarmascota(eMascotas pet[],int tam, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip);

void mostrarRazas(eMascotas pet[],int tam, eRaza raz[], int tamRaz);

void sortPet(eRaza raz[],int tam);

void sortMascota(ePaises apais[],int tam);



///     Informes
void sortTipo2(eMascotas pet[],int tam,eTipo tip[],int tamTip);

void listadoMayorPais(ePaises aPais[], int tam);

void listadoInformes(eMascotas pet[],int tam, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip);

void sortMascotaTel(ePaises apais[],int tam);

void sortMascotaPeso(eMascotas pet[],int tam);

void mostrarTamPeso(eMascotas pet[],int tam, eRaza raz[], int tamRaz);

void mostrarRazaPaisTelefono(eMascotas pet[],int tam, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais);

void sortTipoPeso(eMascotas pet[],int tam,eTipo tip[],int tamTip);

void mostrarGato(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais);

void mostrarRaro(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais);

void mostrarPerro(eMascotas pet[],int tam,eTipo tip[],int tamTip,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais);



/// Funciones ABM


void inicializarmascota(eMascotas pet[],int tam,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip);

void harcodeoMacotas(eMascotas pet[],int tam, eRaza raza[],int tamRaza,ePaises pais[],int tamPais,eTipo tip[],int tamTip);

void harcodeoRazas(eRaza raza[], int tam);

void harcodeoPaises(ePaises pais[],int tamPais);

int addMascota(eMascotas pet[],int tam,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip);

void modificarMascota(eMascotas pet[],int tamMod, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip);

int generarNextId();

int buscarMascotaPorId(int id,eMascotas pet[],int tam,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip);

void seleccionBorrarRaza(eMascotas pet[],int tam,eRaza raz[]);

void borrarRaza(eRaza raz[],char razaBorrar[],int tam);

int buscarLugarLibre(eMascotas pet[],int tam,eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip);

void deletPet(eMascotas pet[],int tamDel, eRaza raz[],int tamRaz,ePaises aPais[],int tamPais,eTipo tip[],int tamTip);



#endif // ALUMNO_H_INCLUDED
