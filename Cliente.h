//
// Created by usuario on 26/07/2021.
//

#ifndef PROYECTPS_CLIENTE_H
#define PROYECTPS_CLIENTE_H


#include <iostream>
#include <string>

using namespace std;
class Cliente {
public:
    Cliente();
    Cliente(string n, string a);
    string nombre;
    string apellido;
    string codigo;
    string getNombre();
    string getApellido();
    string getCodigo();
};

#endif //PROYECTPS_CLIENTE_H
