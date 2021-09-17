#include "Enrutador.h"

Enrutador::Enrutador(string _enrutadorSalida){
    //Constructor, se aggrega a si mismo como un enrtudatoy su ruta es cero
    _nombre = _enrutadorSalida;
    Caracteristicas enrutador;
    enrutador.costoDirecto = 0;
    enrutador.costo = 0;
    enrutador.ruta = _enrutadorSalida;
    _enrutador[_enrutadorSalida].push_back(enrutador);
    //Se le hace pushback al vector de enrutadores
}

void Enrutador::calcularMejorRuta(map<string, int> _rutas){
    //Se calcula la mejor ruta
    string rutaMenor = "";
    for(auto parRutas = _rutas.begin(); parRutas != _rutas.end(); parRutas++){//Se recorre el contenedor _rutas
        if(parRutas->first[0] == _nombre[0]){//Se evalua si el primer enrutador en la ruta es el nombre del objeto
            for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
                rutaMenor = parRutas->first;
                int cantCaracteres = rutaMenor.length();
                if(rutaMenor[cantCaracteres-1] == par->first[0]){//Se evalua si el final de la ruta es el enrutador de llegada
                    for(auto enru = begin(par->second); enru != end(par->second); enru++){
                        if(enru->costo == 0){//Si el cosot es cero, se agrega la ruta como ruta menor
                            enru->ruta = rutaMenor;
                            enru->costo = parRutas->second;
                        }else if(enru->costo > parRutas->second){//Si la ruta actual es menor a la ruta que se tiene, se realiza el cambio
                            enru->ruta = rutaMenor;
                            enru->costo = parRutas->second;
                        }
                    }
                }
            }
        }
    }
}

//METODOS SETTER Y GETTER DE LOS ATRIBUTOS PRIVADOS
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
