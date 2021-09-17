/*
    DOCUMENTACION DE LA CLASE:

    La clase llamada constructor tiene las sigueintes caracteristicas:

    METODOS:
    1.) el metodo cargar datos sobregargado Cargan los datos desde el archivo o desde consoa para
    consigurar la topologia

    2.) La funcion cambiarCOnfigutacion sobrecargada: Se encarga de realizar modificaciones sobre
    la topologia

    3.) CalcularRutas: Se encarga de calcuar todas la rutas posiblkes y su respectivo
    costo, una vez terminado el calculo de rutas, llama el metodo calcular meor ruta
    y le envia el mapa de rutas para que cada enrutador calcule sus mejores rutas

    4.) ImprimirRuta: Se encarga de imprimir la mejor ruta junto con su costo asociado.

    ATRIBUTOS:

    1.) enrutadoresExistentes: Vector que se envarga de guardar los enrutadores que existen en
    la topologia

    2.) _rutas = Mapa que tiene clave un string que almacena ruta y como elemento un
    entero que reperenta el totpal del cosnto de la ruta

    2.) _topologia: Vector de enrutadores

    PARA QUE ESTA LIBRERIA FUNCUONE SE DEBE INCLUIR LA LIBRERIA "Enrutador.h"
    De lo contrario no se asegura un correcto funcionamiento.
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
