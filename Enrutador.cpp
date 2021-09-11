#include "Enrutador.h"

Enrutador::Enrutador(string _enrutadorSalida){
    _nombre = _enrutadorSalida;
    Caracteristicas enrutador;
    enrutador.costoDirecto = 0;
    enrutador.costo = 0;
    enrutador.ruta = _enrutadorSalida;
    _enrutador[_enrutadorSalida].push_back(enrutador);
}

string Enrutador::Getnombre() const{
    return _nombre;
}

void Enrutador::setNombre(const string &nombre){
    _nombre = nombre;
}

map<string, list<Caracteristicas> > Enrutador::Getenrutador() const{
    return _enrutador;
}

void Enrutador::setEnrutador(const map<string, list<Caracteristicas> > &enrutador){
    _enrutador = enrutador;
}
