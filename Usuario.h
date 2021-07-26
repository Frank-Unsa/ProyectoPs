//
// Created by usuario on 24/07/2021.
//

#ifndef PROYECTPS_USUARIO_H
#define PROYECTPS_USUARIO_H


#include <iostream>
#include <string>

using namespace std;


class Usuario {
public:
    Usuario();
    Usuario(string n, string a, string c);
    string nombre;
    string apellido;
    string contrasenia;
    int cantReservas=0;
    void eliminarReserva(int p);
    void mostrarReservas();
};



#endif //PROYECTPS_USUARIO_H
