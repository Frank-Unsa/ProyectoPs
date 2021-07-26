//
// Created by usuario on 24/07/2021.
//

#ifndef PROYECTPS_HORA_H
#define PROYECTPS_HORA_H

class Hora {
public:
    Hora();
    Hora(int h, int m);

    Hora(Hora *pHora);

    int hora;
    int minuto;
};




#endif //PROYECTPS_HORA_H
