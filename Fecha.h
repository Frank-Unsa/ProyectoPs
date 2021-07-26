//
// Created by usuario on 24/07/2021.
//

#ifndef PROYECTPS_FECHA_H
#define PROYECTPS_FECHA_H


class Fecha {
public:
    Fecha();
    Fecha(int d, int m, int a);

    Fecha(Fecha *pFecha);

    int dia;
    int mes;
    int anio;
    int getdia();
    int getmes();
    int getYear();
};



#endif //PROYECTPS_FECHA_H
