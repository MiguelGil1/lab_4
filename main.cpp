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
    //vector<Enrutador> topologia;
    //map<string,list<Enrutador>> topologia;
    //A -
    string archivo =  "";
    bool flag = true;
    int optMenuPrincipal = 0;
    while(flag){
        cout << "COSTOS DE UN ENRUTADOR A OTRO." << endl;
        cout << "1.) Cargar topologia desde archivo." << endl;
        cout << "2.) Cargar topologia desde consola." << endl;
        cout << "Seleccione una opcion: ";
        cin >> optMenuPrincipal;
        switch (optMenuPrincipal){
            case 1:{
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
                        cout << "\nIngrese el nombre del archivo que contiene la configuracion de red: ";
                        cin >> archivo;
                        archivo += ".txt";
                    }else{
                        abierto = true;
                    }
                }
                outfile.close();
                flag = false;
                break;
            }
            case 2:{
                flag = false;
                break;
            }
            default:{
                cout << "Opcion fuera de rango." << endl;
                break;
            }
        }
    }
    conexion conection;
    if(optMenuPrincipal == 1){
        conection.cargarDatos(archivo);
    }else{
        cout << "Por favor ingrese las conexiones de la Topologia:" << endl;
        cout << "Tenga en cuenta que si quiere conectar los enrutadores AB, tambien debe escribir la cponexion BA" << endl;
        bool flag = false;
        while (flag == false){
            string enrutadorSalida = "";
            string enrutadorLleguada = "";
            int costo = 0;
            string ingresar = "";
            cout << "Ingrese el nombre del enrutador de salida: ";
            cin >> enrutadorSalida;
            cout << "Ingrese el nombre del enrutador de llegada: ";
            cin >> enrutadorLleguada;
            cout << "Ingrese el costo del enlace: ";
            cin >> costo;
            bool flag2 = false;
            while(flag2 == false){
                cout << "Desea ingresar otro enrutador? (Y/N): ";
                cin >> ingresar;
                if(ingresar == "Y" || ingresar == "y" || ingresar == "N" || ingresar == "n"){
                    flag2 = true;
                }else{
                    cout << "Opcion fuera de rango" << endl;
                }
            }

            if(ingresar == "N" || ingresar == "n"){
                flag = true;
                //conection.cargarDatos(archivo);
            }
        }
    }
    system("cls");
    int opt = 0;
    bool key = true;
    while(key){
        cout << "Que desea hacer?" << endl;
        cout << "1.) Agregar enrutador." << endl;
        cout << "2.) Enlazar enrutadores." << endl;
        cout << "3.) Eliminar enrutador." << endl;
        cout << "4.) Cambiar costo de enlace." << endl;
        cout << "5.) Calcular ruta y costos." << endl;
        cout << "6.) Salir." << endl;
        cout << "Seleccione una opcion: ";
        cin >> opt;
        switch (opt) {
            case 1:{
                vector<string> enlaces;
                string aggEnrutador;
                cout << "Ingrese el nombre del enrutador a agregar: ";
                cin >> aggEnrutador;
                bool agg = true;
                //enlaces.push_back(aggEnrutador+aggEnrutador+",0");
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
                    enlaces.push_back(enlace+aggEnrutador+","+costo);
                    cout << "Desea agregar otra conexion directa?(Y/N): ";
                    cin >> aggMas;
                    if(aggMas == "N"){
                        agg = false;
                    }
                }
                conection.cambiarConfiguracion(enlaces,aggEnrutador);
                //topologia = conection.cambiarConfiguracion(topologia,enlaces,aggEnrutador);
                enlaces.clear();
                break;
            }
            case 2:{
                break;
            }
            case 3:{
                string eliminarEnrutador;
                cout << "Ingrese el nombre del enrutador a eliminar: ";
                cin >> eliminarEnrutador;
                conection.cambiarConfiguracion(eliminarEnrutador);
                break;
            }
            case 4:{
                string enrutadorSalida,enrutadorLlegada;
                int costoDirecto;
                cout << "Ingrese el nombre del primer enrutador: ";
                cin >> enrutadorSalida;
                cout << "Ingrese el nombre del segundo enrutador: ";
                cin >> enrutadorLlegada;
                cout << "Ingrese el costo actualizado: ";
                cin >> costoDirecto;
                conection.cambiarConfiguracion(enrutadorSalida, enrutadorLlegada, costoDirecto);
                //topologia = conection.cambiarConfiguracion(topologia,enrutadorSalida,enrutadorLlegada,costo);
                break;
            }
            case 5:{
                string enrutadorSalida = "", enrutadorLlegada = "";
                cout << "Ingrese el enrutador de salida: ";
                cin >> enrutadorSalida;
                cout << "Ingrese el enrutador de destino: ";
                cin >> enrutadorLlegada;
                conection.imprimirRuta(enrutadorSalida,enrutadorLlegada);
                //conection.imprimirRuta(topologia,enrutadorSalida,enrutadorLlegada);
                break;
            }
            case 6:{
                cout << "Gracias por utilizar nuestros servicios :)" << endl;
                key = false;
                break;
            }
            default:{
                cout << "Opcion fuera de rango." << endl;
                break;
            }
        }
        if(opt <= 1 || opt <= 5){
            system("PAUSE");
            system("CLS");
        }
    }
    return 0;
}
