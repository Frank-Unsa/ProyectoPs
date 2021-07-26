//
// Created by usuario on 26/07/2021.
//

#include "Cliente.h"

Cliente::Cliente() {
    nombre="";
    apellido="";
    codigo="";
}
Cliente::Cliente(string n, string a) {
    nombre=n;
    apellido=a;
    codigo=nombre.substr(0,2)+apellido.substr(0,2);
}
string Cliente::getNombre() {
    return nombre;
}
string Cliente::getApellido() {
    return apellido;
}
string  Cliente::getCodigo() {
    return codigo;
}