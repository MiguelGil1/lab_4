/*
    Documentacion de la estructura:
     Tiene 3 atributos:
        costoDirecto: Entero que almacena el costo directo entre los enrutodres
        costo: Costo minimo
        ruta: Ruta minima

    Documentacion de la clase:
    -> Metodos:
        ->enrutador(string) = constructor que se encarga de crear el enrutador
        ->CalcularMejorRuta = Tiene como parametro un mapa de rutas, evalua la neor ruta para ir]
        de un enrutador de salida a uno de llegada
        ->Funciones setter y getter de los atributos privados

    -> Atributos:
        -> _enrutador: Mapa que tiene como clave el nombre el enrutador de llegada y como
        elemento una lista de tipo caracteristicas que almacena las caractericas de la
        coxion

        -> _nombre: Nombre del enrutador de salida

*/
#ifndef ENRUTADOR_H
#define ENRUTADOR_H
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
