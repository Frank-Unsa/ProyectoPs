//
// Created by usuario on 24/07/2021.
//

#ifndef PROYECTPS_AEROPUERTO_H
#define PROYECTPS_AEROPUERTO_H

#include "Avion.h"
#include <string>
using namespace std;


class Aeropuerto {
public:
    Aeropuerto();
    Aeropuerto(string n);
    Avion flota [10];
    int i=0;
    string nombre;
    void verTodos();
    string verNombre();
    void addAvion(Avion a);
    Avion* getFlota();
    int getCantidad();
    Avion getAvion(int i);
    void mostrarAviones();
};

#endif //PROYECTPS_AEROPUERTO_H
