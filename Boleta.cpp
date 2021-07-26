//
// Created by usuario on 24/07/2021.
//

#include "Boleta.h"
#include <fstream>
int contador=1;
string fecha;
Boleta::Boleta() {

}
Boleta::Boleta(Cliente u, Avion a, int as) {
    nombre=u.getNombre();
    apellido=u.getApellido();
    codigo=u.getCodigo();
    asiento=as;
    aerolinea=a.aerolinea;
    fechaV=a.fVuelo;
    horaPartida=a.hPartida;
    horaLlegada=a.hLlegada;
    costo=a.preBol;

}

void Boleta::generarBoleta() {

    cout << "============ GENERACION DE SU RESERVA ============" << endl;
    cout << "==================================================" << endl;
    cout<<"Nombre del Usuario: "<<nombre<<" "<<apellido<<endl;
    cout<<"Codigo: "<<codigo<<endl;
    cout<<"Numero de asiento : "<<asiento<<endl;
    cout<<"Aerolinea: "<<aerolinea<<endl;
    cout<<"Fecha de Vuelo: "<<fechaV.dia<<"/"<<fechaV.mes<<"/"<<fechaV.anio<<endl;
    cout<<"Hora de Partida: "<<horaPartida.hora<<":"<<horaPartida.minuto<<endl;
    cout<<"Hora de Llegada: "<<horaLlegada.hora<<":"<<horaLlegada.minuto<<endl;
    cout<<"Costo de Vuelo: "<<costo<<endl;
    cout << "==================================================" << endl;

}
void Boleta::exportarBoleta(){
    if(fechaV.getdia()<10 && fechaV.getmes()<10){
        fecha="0"+to_string(fechaV.getdia())+"/0"+ to_string(fechaV.getmes())+"/"+to_string(fechaV.getYear()) ;
    }else if(fechaV.getdia()<10 && fechaV.getmes()>10){
        fecha="0"+to_string(fechaV.getdia())+"/"+ to_string(fechaV.getmes())+"/"+to_string(fechaV.getYear()) ;
    }else if(fechaV.getdia()>10 && fechaV.getmes()<10){
        fecha=to_string(fechaV.getdia())+"/0"+ to_string(fechaV.getmes())+"/"+to_string(fechaV.getYear()) ;
    }else if(fechaV.getdia()>10 && fechaV.getmes()>10){
        fecha=to_string(fechaV.getdia())+"/"+ to_string(fechaV.getmes())+"/"+to_string(fechaV.getYear()) ;
    }
    string reserva="Reserva Nro "+to_string(contador)+".txt";
    fstream archivo(reserva);

    if (!archivo.is_open())
    {
        archivo.open(reserva, ios ::out);
    }
    archivo<<"Codigo: "<<codigo<<endl;
    archivo<<"Nombre del Usuario: "<<nombre+" "+apellido<<endl;
    archivo<<"Numero de asiento : "<<asiento<<endl;
    archivo<<"Aerolinea: "<<aerolinea<<endl;
    archivo<<"Fecha de Vuelo: "<<fecha<<endl;
    archivo<<"Hora de Partida: "<<horaPartida.hora<<":"<<horaPartida.minuto<<endl;
    archivo<<"Hora de Llegada: "<<horaLlegada.hora<<":"<<horaLlegada.minuto<<endl;
    archivo<<"Costo de Vuelo: "<<costo<<endl;
    system("cls");
    cout << "registro guardado con exito... \n";
    system("pause");
    system("cls");

    archivo.close();
    contador++;
}
string Boleta::getcodigo() {
    return codigo;
}
