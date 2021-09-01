/*
 CONDICIONES DE USO DEL PROGRAMA:

 1.) El archivo de configuracion de red debe encontrarse en la siguiente ruta
 relativa:
 ../nombre_archivo.txt
 Y debe tener una extension .txt
*/
#include <iostream>
#include <fstream>
//INCLUIMOS LA LIBRERIA "conexion.h"
#include "conexion.h"

using namespace std;

int main(){
    map<string,list<Enrutador>> enrutadores;
    string archivo =  "";
    cout << "COSTOS DE UN ENRUTADOR A OTRO." << endl;
    cout << "\nIngrese el nombre del archivo que contiene la configuracion de red: ";
    cin >> archivo;
    archivo += ".txt";
    bool abierto = false;
    ifstream outfile;

    while(!abierto){
        outfile.open("../"+archivo);
        if(!outfile.is_open()){
            archivo = "";
            cout << "El archivo no fue abierto adecuadamente.\nIntentelo nuevamente." << endl;
            system("PAUSE");
            system("cls");
            cout << "COSTOS DE UN ENRUTADOR A OTRO." << endl;
            cout << "\nIngrese el nombre del archivo que contiene la configuracion de red: ";
            cin >> archivo;
            archivo += ".txt";
        }else{
            abierto = true;
        }
    }
    outfile.close();
    conexion conection;
    enrutadores = conection.cargarDatos(enrutadores,archivo);
    system("cls");
    int opt = 0;
    bool key = true;
    while(key){
        cout << "Que desea hacer?" << endl;
        cout << "1.) Agregar enrutador." << endl;
        cout << "2.) Eliminar enrutador." << endl;
        cout << "3.) Cambiar costo de enlace." << endl;
        cout << "4.) Calcular ruta y costos." << endl;
        cout << "5.) Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opt;
        switch (opt) {
        case 1:{
            vector<string> enlaces;
            string aggEnrutador;
            cout << "Ingrese el nombre del enrutador a agregar: ";
            cin >> aggEnrutador;
            bool agg = true;
            string aggMas = "", enlace = "", costo = "";
            while(agg){
                aggMas = "";
                enlace = "";
                costo = "";
                cout << "Ingrese el nombre del enrutador directamente conectado: ";
                cin >> enlace;
                cout << "Ingrese el costo del enlace: ";
                cin >> costo;
                enlaces.push_back(aggEnrutador+enlace+","+costo);
                cout << "Desea agregar otra conexion directa?(y/n): ";
                cin >> aggMas;
                if(aggMas == "N"){
                    agg = false;
                }
            }
            enrutadores = conection.cambiarConfiguracion(enrutadores,enlaces);
            break;
        }
        case 2:{
            string eliminarEnrutador;
            cout << "Ingrese el nombre del enrutador a eliminar: ";
            cin >> eliminarEnrutador;
            enrutadores = conection.cambiarConfiguracion(enrutadores,eliminarEnrutador);
            //conexion.cambiarConfiguracion(enrutador);
            break;
        }
        case 3:{
            string enrutadorSalida,enrutadorLlegada;
            int costo;
            cout << "Ingrese el nombre del primer enrutador: ";
            cin >> enrutadorSalida;
            cout << "Ingrese el nombre del segundo enrutador: ";
            cin >> enrutadorLlegada;
            cout << "Ingrese el costo actualizado: ";
            cin >> costo;
            enrutadores = conection.cambiarConfiguracion(enrutadores,enrutadorSalida,enrutadorLlegada,costo);
            break;
        }
        case 4:
            break;
        case 5:
            cout << "Gracias por utilizar nuestros servicios :)" << endl;
            key = false;
            break;
        default:
            cout << "Opcion fuera de rango." << endl;
            break;
        }
        if(opt <= 1 || opt <= 4){
            system("PAUSE");
            system("CLS");
        }
    }

    return 0;
}
