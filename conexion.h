/*
    DOCUMENTACION DE LA CLASE:

    La clase llamada constructor tiene las sigueintes caracteristicas:

    METODOS

    1.) constructor: Se encargara de traducir la info. contenida en el archivo
    que contenga la configuracion de la conexion y representarla en un contenedor
    en este caso sera un mapa, que todavia se tiene la duda si este sera la
    tabla de enrutamiento o solo conendra las conexiones fijas

    ATRIBUTOS:

    1.) _conexion: Mapa anidado que aun esta por definirse si contendra la tabla
    de enrutamiento o sera nada mas un mapa que contenga las conexions diractas

    2.) _enrutadoresDeLaRuta: Contenedor (que aun esta por definirse cual) el
    cual contendra los enrutadores a utilizados en una ruta, se crea con la intesion
    de que se cnsulte primero en este contenedor antes de saltar a otro enrutador
    para evitar casos como un bucle infinito entre enrutaodres o pasar dos veces
    por el mismo enrutador en una ruta.
*/
#ifndef CONEXION_H
#define CONEXION_H
#include <map>
#include <vector>
#include <iterator>
#include <iostream>
using namespace std;

class conexion{
public:
    conexion();
private:
    //Mapa de las conexiones directas? / Mapa de la tabla de enrutamiento?
    map<char, map<char, int>> _conexion;
    //Vector que almacena
    vector<char> _enrutadoresDeLaRuta;
};

#endif // CONEXION_H
