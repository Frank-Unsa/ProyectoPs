//
// Created by usuario on 24/07/2021.
//

#include "Usuario.h"

Usuario::Usuario() {
    nombre="";
    apellido="";
    contrasenia="";
}

Usuario::Usuario(string n, string a, string c) {
    nombre=n;
    apellido=a;
    contrasenia=c;
}

/*void Usuario::crearReserva(int n, Avion a) {
    reservas[cantReservas].nombre=nombre;
    reservas[cantReservas].apellido=apellido;
    reservas[cantReservas].asiento=n;
    reservas[cantReservas].aerolinea=a.aerolinea;
    reservas[cantReservas].fechaV.dia=a.fVuelo.dia;
    reservas[cantReservas].fechaV.mes=a.fVuelo.mes;
    reservas[cantReservas].fechaV.anio=a.fVuelo.anio;
    reservas[cantReservas].horaPartida.hora=a.hPartida.hora;
    reservas[cantReservas].horaPartida.minuto=a.hPartida.minuto;
    reservas[cantReservas].horaLlegada.hora=a.hLlegada.hora;
    reservas[cantReservas].horaLlegada.minuto=a.hLlegada.minuto;
    reservas[cantReservas].costo=a.preBol;
    reservas[cantReservas].generarBoleta();
    cantReservas++;
    cout<<"Se creo exitosamente su reserva"<<endl;
}*/
/*
void Usuario::eliminarReserva(int p) {
    if(p>0 && p<10){
        reservas[p-1]=reservas[cantReservas-1];
        cantReservas--;
        cout<<"Se elimino exitosamente la reserva"<<endl;
    }
}

void Usuario::mostrarReservas() {
    for (int i = 0; i <cantReservas; i++) {
        cout<<"Reserva "<<i<<endl;
        cout<<"Nombre del Usuario: "<<nombre<<" "<<apellido<<endl;
        cout<<"Numero de asiento : "<<reservas[i].asiento<<endl;
        cout<<"Aerolinea: "<<reservas[i].aerolinea<<endl;
        cout<<"Fecha de Vuelo: "<<reservas[i].fechaV.dia<<"/"<<reservas[i].fechaV.mes<<"/"<<reservas[i].fechaV.anio<<endl;
        cout<<"Hora de Partida: "<<reservas[i].horaPartida.hora<<":"<<reservas[i].horaPartida.minuto<<endl;
        cout<<"Hora de Llegada: "<<reservas[i].horaLlegada.hora<<":"<<reservas[i].horaLlegada.minuto<<endl;
        cout<<"Costo de Vuelo: "<<reservas[i].costo<<endl;
    }

}*/
