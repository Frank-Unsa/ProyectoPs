//
// Created by usuario on 24/07/2021.
//

#ifndef PROYECTPS_BOLETA_H
#define PROYECTPS_BOLETA_H

#include <iostream>
#include "Hora.h"
#include "Fecha.h"
#include "Cliente.h"
#include "Avion.h"

class Boleta {
public:
    Boleta();
    Boleta(Cliente u, Avion a, int asiento);
    string nombre;
    string apellido;
    int asiento;
    int contador=0;
    string aerolinea;
    Fecha fechaV;
    Hora horaPartida;
    Hora horaLlegada;
    int costo;
    void generarBoleta();
    void exportarBoleta();
};

#endif //PROYECTPS_BOLETA_H
