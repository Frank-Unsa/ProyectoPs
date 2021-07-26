//
// Created by usuario on 24/07/2021.
//

#ifndef PROYECTPS_AVION_H
#define PROYECTPS_AVION_H

#include <iostream>
#include <string>
#include "Fecha.h"
#include "Hora.h"
using namespace std;

class Avion {
public:
    Avion();
    Avion(string n, int p, Fecha v, Hora par, Hora lle);
    int cantPas=0; //numero de pasajeros actuales
    bool  asientos [100] ={false}; // # de asientos en total (80 sc y 20 pc)
    string aerolinea; //nombre de la aerolinea a la que pertenece
    int preBol; // precio de boleto
    Fecha fVuelo;
    Hora hPartida;
    Hora hLlegada;
    string verNombre();
    void agregarPasajero(int n);
    void retirarPasajero(int n);
    bool verAsientoOcupado(int n);
    int verCantidadDePasajeros();

};


#endif //PROYECTPS_AVION_H
