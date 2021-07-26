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
    string codigo;
    int asiento;
    string aerolinea;
    Fecha fechaV;
    Hora horaPartida;
    Hora horaLlegada;
    int costo;
    void generarBoleta();
    void exportarBoleta();
    string getcodigo();
};


#endif //PROYECTPS_BOLETA_H
