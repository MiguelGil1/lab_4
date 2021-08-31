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
    conexion conexion(archivo);
    system("cls");
    int opt = 0;
    while(opt > 4 || opt < 1 ){
        cout << "Que desea hacer?" << endl;
        cout << "1.) Agregar enrutador." << endl;
        cout << "2.) Eliminar enrutador." << endl;
        cout << "3.) Cambiar costo de enlace." << endl;
        cout << "4.) Calcular ruta y costos." << endl;
        cout << "5.) Salir." << endl;
        cin >> opt;
        if(opt > 4 || opt < 1){
            cout << "Opcion fuera de rango." << endl;
            system("PAUSE");
            system("CLS");
        }
    }
    switch (opt) {
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
    return 0;
}
