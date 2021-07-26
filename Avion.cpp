//
// Created by usuario on 24/07/2021.
//
#include "Avion.h"
#include "Fecha.h"
#include "Hora.h"
using namespace std;

string Avion::verNombre() {
    return aerolinea;
}

void Avion::agregarPasajero(int n) {
    if(asientos[n-1]==true){
        cout<<"Este asiento ya esta ocupado, Seleccione otro"<<endl;
    }else{
        cout<<"Asiento registrado exitosamente"<<endl;
        asientos[n-1]=true;
        cantPas++;
    }
}

void Avion::retirarPasajero(int n) {
    if(asientos[n-1]==false){
        cout<<"Este asiento actualmente se encuentra vacio, operacion no valida"<<endl;
    }else{
        cout<<"Se retiro el registro del asiento exitosamente"<<endl;
        asientos[n-1]=false;
        cantPas--;
    }
}

int Avion::verCantidadDePasajeros() {
    return cantPas;
}

Avion::Avion(string n, int p, Fecha v, Hora par, Hora lle) {
    aerolinea=n;
    preBol=p;
    fVuelo=v;
    hPartida=par;
    hLlegada=lle;
}

Avion::Avion() {
    aerolinea="";
    preBol=0;
    fVuelo=new Fecha(0,0,0);
    hPartida=new Hora(0, 0);
    hLlegada=new Hora(0, 0);
}
bool Avion:: verAsientoOcupado(int n){
    if (asientos[n-1]){
        cout<<"Asiento Ocupado"<<endl;
        return true;
    }
    return false;
}
bool Avion::marcarAsiento(int number){   //   true -> ocupado       false -> desocupado
    if(!verAsientoOcupado(number)){
        asientos[number-1]= true;
        return true;
    }
    return false;
}
