#include <iostream>
#include <stdio.h>
#include <cstdlib>

#include <cstdio>
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
void eliminarReserva();


// Usuarios por default
static Usuario usuarios[10];
static Boleta boletasCreadas[100];
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
        cout << "============ Inicio de Sesion ============" << endl;
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
int count=0;
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
    string nom;//nombre de la aerolinea
    bool valido= false;
    string  name;//nombre del usuario a registrar
    string apell;//apellido del usuario a registrar
    Cliente nuevo;
    int posicion;//nos ayuda a identificar la posicion del avion seleccionado
    int asiento;//Numero de asiento a registrar
    string code;//codigo de la persona que se genera
    int post=0;//posicion en la que se encuntra la boleta seleccionada
    bool valor=false;//nos ayudara a ordenar las boletas luego de eliminar una de ellas
    int contad;
    char eliminar[100];
    string eli;//nombre del archivo a eliminar
    int tamanio;
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
                //afr.getFlota()[posicion] obtener el avion
                //verificamos si el asiento esta o no ocupado
                while(true){
                    if(afr.getFlota()[posicion].marcarAsiento(asiento)== true){
                        break;
                    }else{
                        cout<<"Vuela a ingresar el numero de asiento"<<endl;
                        cin>>asiento;
                    }
                }
                Cliente n1(name,apell);
                Boleta b1(n1, afr.getFlota()[posicion], asiento);
                b1.generarBoleta();
                b1.exportarBoleta();
                boletasCreadas[count] = b1;
                count++;

            }else{
                cout<<"Avion no encontrado";
            }
            mostrarMenu();
            break;
        case 2: //Mostrar todas las reservaciones
            cout <<"Estoy aqui"<< endl;
            for (int j = 0; j < count; ++j) {
                boletasCreadas[j].generarBoleta();
            }
            cout << endl;
            cout << "Presione cualquier tecla para volver al menu.." << endl;
            mostrarMenu();
            break;
        case 3: //eliminar reservacion




            contad=count;
            cout<<"Ingrese el codigo (los primeros caracteres de su nombre y apellido) " <<endl;
            cin >> code;
            for (int j = 0; j < count; ++j) {
                if(boletasCreadas[j].getcodigo()==code){
                    valor=true;
                    break;
                }
                post++;
            }
            //


            if(valor){

                for (int j = 0; j < sizeof (afr.getFlota()); ++j) {

                    if(afr.getFlota()[j].verNombre()==boletasCreadas[post].aerolinea){
                        posicion=j;
                        valido=true;
                        break;
                    }
                }
                //eliminacion del asiento
                afr.getFlota()[posicion].retirarPasajero(boletasCreadas[post].asiento);

                for(i=post;i<contad;i++){
                    boletasCreadas[i]=boletasCreadas[i+1];
                }
                count--;

                eli="Reserva Nro "+ to_string(post+1)+".txt";
                tamanio = eli.length();
                eliminar[tamanio + 1];
                strcpy(eliminar, eli.c_str());//copiar una cadena dentro de otra cadena
                remove(eliminar);//elimina un archivo
                system("pause");

            }else{
                cout<<"Codigo no encontrado"<< endl;
            }
            cout << "Presione cualquier tecla para volver al menu.." << endl;
            mostrarMenu();
            break;
        case 4: //salir del programa
            cout << "============ Fin del programa ============" << endl;
            break;
        default: //opcion no valida
            cout << "Opción desconocida!" << endl;
            break;
    }
}