#ifndef ENRUTADOR_H
#define ENRUTADOR_H
//#include "conexion.h"
#include <vector>
#include <iterator>
#include <iostream>
#include <fstream>
#include <list>
#include <map>

using namespace std;

struct Caracteristicas{
    int costoDirecto;
    int costo;
    string ruta;
};

class Enrutador{
public:
    Enrutador(string);
    void calcularMejorRuta(map<string,int> _rutas);

    string Getnombre() const;
    void setNombre(const string &nombre);

    map<string, list<Caracteristicas>> Getenrutador() const;
    void setEnrutador(const map<string, list<Caracteristicas> > &enrutador);

private:
    map<string,list<Caracteristicas>> _enrutador;
    string _nombre;
};

#endif // ENRUTADOR_H