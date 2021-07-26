#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <conio.h> // getch
#include <vector>
#include "Usuario.h"
#include "Fecha.h"
#include "Hora.h"
#include "Avion.h"
#include "Aeropuerto.h"
#include "Cliente.h"
#include "Boleta.h"

//nuevo
#define ENTER 13
#define BACKSPACE 8
#define INTENTOS 3
using namespace std;

int menuPrincipal();
void inicioSesion();
void registro();
void mostrarMenu();
void adminMenu();


// Usuarios por default
static Usuario usuarios[10];
static Boleta boletasCreadas[12];
Usuario a("jimy", "revilla", "tellez");
Usuario b("bryan","gallegos","carlos");

//Creando aviones por default
Avion plane1("Latam", 100, new Fecha(23,10,2021), new Hora(12,30), new Hora(14,15));
Avion plane2("Avianca", 100, new Fecha(5,9,2021), new Hora(14,00), new Hora(17,30));
Avion plane3("Airlines", 100, new Fecha(14,11,2021), new Hora(16,15), new Hora(21,00));

//Creando aeropuerto por default
static Aeropuerto afr("Alfredo Rodriguez");




int main()
{
    usuarios[0] = a;
    usuarios[1] = b;
    afr.addAvion(plane1);
    afr.addAvion(plane2);
    afr.addAvion(plane3);
    int valor;
    valor = menuPrincipal();
    switch (valor)
    {
        case 1: //inicio de sesion
            inicioSesion();
            break;
        case 2: //registro de usuario
            registro();
            break;
        case 3: //salir del programa
            break;
        default: //opcion no valida
            cout << "\t\t Opcion desconocida" << endl;
            break;
    }

    return 0;
}

int menuPrincipal()
{
    int op;
    cout << "============ Reservaciones de Pasajes ============" << endl;
    cout << " \t\t1. Iniciar Sesion  " << endl;
    cout << " \t\t2. Registrarse " << endl;
    cout << " \t\t3. Salir " << endl;
    cout << "==================================================" << endl;
    cout << " Ingrese una opcion: ";

    cin >> op;
    return op;
}


void inicioSesion()
{
    string usuario, password;

    int contador = 0;
    bool ingresa = false;

    do
    {
        system("cls");
        cout << "============ Inicio de Sesión ============" << endl;
        cout << "\t\t\tLOGIN DE USUARIO" << endl;
        cout << "\t\t\t----------------" << endl;
        cout << "\n\tUsuario: ";
        cin>>usuario;
        cout<<endl;

        char caracter;
        cout << "\tPassword: ";
        caracter = getch();

        password = "";
        while (caracter != ENTER)
        {
            if (caracter != BACKSPACE)
            {
                password.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (password.length() > 0)
                {
                    cout << "\b \b";
                    password = password.substr(0, password.length() - 1);
                }
            }
            caracter = getch();
        }
        for (int i = 0; i < sizeof(usuarios); i++)
        {
            if (usuarios[i].nombre == usuario && usuarios[i].contrasenia == password)
            {
                ingresa = true;
                break;
            }
        }
        if (!ingresa)
        {
            cout << "\n\n\tEl usuario y/o password son incorrectos" << endl;
            cin.get();
            contador++;
        }
    } while (ingresa == false && contador < INTENTOS);
    if (ingresa == false)
    {
        cout << "\n\tUsted no pudo ingresar al sistema. ADIOS" << endl;
    }
    else
    {
        cout << "\n\n\tBienvenido al sistema" << endl;
        mostrarMenu();
    }
}


int i=4;
void registro()
{
    string nombre, apellido, usuario, contrasenia;

    cout << "============ Registro ============" << endl;
    cout << "\t\t Nombre:" << endl;
    cin >> nombre;
    cout <<endl;
    cout << "\t\t Apellido: " << endl;
    cin >> apellido;
    cout <<endl;
    cout << "\t\t Usuario: " << endl;
    cin >> usuario;
    cout <<endl;
    cout << "\t\t Contraseña" << endl;
    cin >> contrasenia;
    cout <<endl;
    Usuario a(nombre,apellido,contrasenia);
    usuarios[i]=a;
    i++;

    cout << "============ Registro Exitoso ============" << endl;
    inicioSesion();
}
void mostrarMenu()
{
    int opc;
    cout << "============ Opciones ============" << endl;
    cout << "\t\t 1. Nueva Reservacion: " << endl;
    cout << "\t\t 2. Mostrar Reservacion: " << endl;
    cout << "\t\t 3. Eliminar Reservacion: " << endl;
    cout << "\t\t 4. Salir " << endl;
    cout << "==================================================" << endl;
    cout << " Ingrese una opcion: ";
    cin >> opc;
    string nom;
    string dia;
    bool valido= false;
    string  name;
    string apell;
    Cliente nuevo;
    int posicion;
    int asiento;
    int contador=0;
    switch (opc)
    {
        case 1: //Añadir nueva reservación
            cout << endl;
            cout << "============ Aerolineas Exixtentes ============" << endl;
            afr.mostrarAviones();
            cout << endl;
            cout << "==================================================" << endl;
            cout<<endl;
            cout << "\tIngrese nombre de aerolinea ";
            cin>>nom;
            for (int j = 0; j < sizeof (afr.getFlota()); ++j) {
                //cout<<afr.getFlota()[j].verNombre();
                if(afr.getFlota()[j].verNombre()==nom){
                    posicion=j;
                    valido=true;
                    break;
                }
            }
            if (valido){
                //cout<<"Aqui";
                cout<<"Ingrese Nombre: ";
                cin>>name;
                cout<<"Ingrese Apellido: ";
                cin>>apell;
                cout<< "Ingrese su numero su numero de Asiento [1-100]: ";
                cin>>asiento;
                Cliente n1(name,apell);

                Boleta b1(n1, afr.getFlota()[posicion], asiento);
                b1.generarBoleta();
                boletasCreadas[contador] = b1;

            }else{
                cout<<"Avion no encontrado";
                menuPrincipal();
            }
            break;
        case 2: //Mostrar todas las reservaciones
            cout <<"Estoy aqui"<< endl;
            for (int j = 0; j < sizeof(boletasCreadas); ++j) {
                boletasCreadas[j].generarBoleta();
            }
            cout << endl;
            cout << "Presione cualquier tecla para volver al menu.." << endl;
            getch();
            break;
        case 3: //eliminar reservacion
            cout << "¿Cual numero de reservacion desea eliminar?";
            cin >> nom;
            /*
                    codigo de eliminacion de reservacion
                */
            cout << "Presione cualquier tecla para volver al menu.." << endl;
            getch();
            break;
        case 4: //salir del programa
            cout << "============ Fin del programa ============" << endl;
            break;
        default: //opcion no valida
            cout << "Opción desconocida!" << endl;
            break;
    }
}
void adminMenu()
{
    int opci;
    cout << "============ Opciones ============" << endl;
    cout << "\t\t 1. Crear nuevo vuelo" << endl;
    cout << "\t\t 2. Eliminar vuelo registrado" << endl;
    cout << "\t\t 4. Generar Reporte " << endl;
    cout << "\t\t 5. Salir" << endl;
    cout << "==================================================" << endl;
    cout << " Ingrese una opcion: ";
    cin >> opci;
    string aerolinea;
    int preBol;
    Fecha f;
    string fec;
    int d,m,y;
    Hora p;
    Hora lleg;
    string hour;
    string hourlle;
    int h,min,hlle,mlle;
    switch (opci)
    {
        case 1:
            cout << endl;
            cout << "Ingrese nombre de aerolinea..\t";
            cin >> aerolinea;
            cout << endl;
            cout << "Ingrese el precio de cada boleto..\t";
            cin >> preBol;
            cout << endl;
            cout<< "Ingrese Fecha del vuelo(dd/mm/yy) \t";
            cin>>fec;
            d= stoi(fec.substr(0,2));
            m= stoi(fec.substr(3,5));
            y= stoi(fec.substr(6,fec.length()));
            cout<< "Ingrese Hora de Partida del vuelo(hh:mm) \t";
            cin>>hour;
            h=stoi(hour.substr(0,2));
            m= stoi(hour.substr(3,hour.length()));
            cout<<endl;
            cout<< "Ingrese Hora de LLegada del vuelo(hh:mm) \t";
            cin>>hourlle;
            hlle=stoi(hourlle.substr(0,2));
            mlle= stoi(hourlle.substr(3,hourlle.length()));
            cout<<endl;
            cout << "============ Vuelo Registrado Correctamente ============" << endl;
            adminMenu();

            break;
        case 2:
            cout << endl;
            /*
                    Mostrar todas las aerolineas
                 */
            cout << endl;
            cout << "Ingresar nombre de aerolinea a eliminar..\t";
            cin >> aerolinea;
            cout << endl;
            cout << "Presione cualquier tecla para volver al menu.." << endl;
            getch();
            break;
        case 3:
            cout << endl;
            cout << "============ Generar Reporte ============";
            /*
                 codigo de generacion de reporte
                 */
            cout << "Presione cualquier tecla para volver al menu.." << endl;
            getch();
            break;
        case 4:
            cout << "============ Fin del programa ============" << endl;
            break;
        default: //opcion no valida
            cout << "Opción desconocida!" << endl;
            break;
    }
}
