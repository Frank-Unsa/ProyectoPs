//
// Created by usuario on 26/07/2021.
//

#include "Cliente.h"

Cliente::Cliente() {
    nombre="";
    apellido="";
}
Cliente::Cliente(string n, string a) {
    nombre=n;
    apellido=a;
}
string Cliente::getNombre() {
    return nombre;
}
string Cliente::getApellido() {
    return apellido;
}