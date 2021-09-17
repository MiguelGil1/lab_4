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
#include "Enrutador.h"

class conexion{
public:
    //vector<Enrutador> cargarDatos(vector<Enrutador> contenedor, string _archivo);
    //Funcion que me permite cargar los daros desde el archivo
    void cargarDatos(string _archivo);
    void cargarDatos(map<string,int> topologiaConsola);

    //A continuacion se sobrecarga la funcion cambiarConfiguracion
    void cambiarConfiguracion(string a);//Permite eliminar enrutadores
    void cambiarConfiguracion(string a, string b, int c);//Permite cambiar el costo entre enrutadores
    void cambiarConfiguracion(string a, string b, string c);//Permite enlazar dos enrutadores
    void cambiarConfiguracion(vector<string> enlaces, string salida);//Permite agregar enrutadores a la topologia

    //Funciones que permitan el calculo del costo y ruta minima
    void imprimirRuta(string a, string b);//Imprime la ruta y el costo para llegar de un enrutador a otro
    void calcularRutas();//Calcula todas las rutas posibles de la topologia
private:
    map<string,int> _rutas;
    vector<Enrutador> _topologia;
    vector<string> enrutadoresExistentes;
};


#endif // CONEXION_H
