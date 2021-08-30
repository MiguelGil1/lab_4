#include "conexion.h"

conexion::conexion(string _archivo){
    ifstream file;
    string linea;
    string costo = "";
    file.open("../"+_archivo);
    while(!file.eof()){
        costo = "";
        file >> linea;
        costo.append(linea,linea.find(",")+1,linea.find("\n"));
        cout << "[" << linea[0] << "," << linea[1] << "] = " << costo << endl;
        //cout << linea.find(",") << endl;
        //cout << linea.append(",") << endl;
        //_conexion[linea[0]][linea[1]] = {10};
    }
    /*for(auto outer_iter=_conexion.begin(); outer_iter!=_conexion.end(); ++outer_iter) {
        for(auto inner_iter=outer_iter->second.begin(); inner_iter!=outer_iter->second.end(); ++inner_iter) {
            cout << "Key = " << outer_iter->first << "  Valor = " << inner_iter->first << " - " << inner_iter->second << endl;
        }
    }*/


    /*for(auto var : _conexion){
        cout << var.first << endl;
    }*/
    system("PAUSE");
}
