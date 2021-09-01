#include "conexion.h"

map<string,list<Enrutador>> conexion::cargarDatos(map<string,list<Enrutador>> contenedor, string _archivo){
    Enrutador enrutador;
    ifstream file;
    string linea;
    string costo = "";
    file.open("../"+ _archivo);
    string enrutador_salida = "";
    while(!file.eof()){
        file >> linea;
        costo = "";
        enrutador_salida = linea[0];
        enrutador.nombre = linea[1];
        costo.append(linea,linea.find(",")+1,linea.find("\n"));
        enrutador.costo = atoi(costo.c_str());
        enrutador.ruta = "";
        contenedor[enrutador_salida].push_back(enrutador);
    }
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        cout << endl << "Enrutador salida: " << par->first << endl;
        for (auto enru = begin(par->second); enru != end(par->second); enru++){
            cout << "Enrutador llegada: " << enru->nombre << " - costo: " << enru->costo << " - ruta: " << enru->ruta << endl;
        }
    }
    system("PAUSE");
    return contenedor;
}

map<string,list<Enrutador>> conexion::cambiarConfiguracion(map<string, list<Enrutador>> contenedor, string a, string b, int costo){
    //Enrutador enrutador;
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        if(par->first == a){
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                if(enru->nombre == b){
                    enru->costo = costo;
                }
            }
        }else if(par->first == b){
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                if(enru->nombre == a){
                    enru->costo = costo;
                }
            }
        }
    }
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        cout << endl << "Enrutador salida: " << par->first << endl;
        for (auto enru = begin(par->second); enru != end(par->second); enru++){
            cout << "Enrutador llegada: " << enru->nombre << " - costo: " << enru->costo << endl;
        }
    }
    return contenedor;
}

map<string, list<Enrutador> > conexion::cambiarConfiguracion(map<string, list<Enrutador> > contenedor, string a){
    Enrutador enrutador;
    list <Enrutador> * my_list;
    //ELIMINAMOS LA EL ENRUTADOR SELECCIONADO
    //contenedor.erase(a);



    //ELIMINAMOS EL ENRUTADOR DE LOS DEMAS ENRUTADORES
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        for (auto enru = begin(par->second); enru != end(par->second); enru++){
            if(enru->nombre == a){
                my_list->push_back(*enru);
            }
        }
        for(auto i = my_list->begin(); i != my_list->end(); i++){
            cout << "Se va a eliminar " << par->first << " - " << i->nombre << endl;
            par->second.erase(i);
        }
    }
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        cout << endl << "Enrutador salida: " << par->first << endl;
        for (auto enru = begin(par->second); enru != end(par->second); enru++){
            cout << "Enrutador llegada: " << enru->nombre << " - costo: " << enru->costo << endl;
        }
    }
    return contenedor;
}

map<string, list<Enrutador> > conexion::cambiarConfiguracion(map<string, list<Enrutador> > contenedor, vector<string>){
    return contenedor;
}

/*conexion::conexion(string _archivo){
    ifstream file;
    string linea;
    string costo = "";
    string enrutador = "";
    file.open("../"+_archivo);
    while(!file.eof()){
        costo = "";
        enrutador = "";
        file >> linea;
        costo.append(linea,linea.find(",")+1,linea.find("\n"));
        //_conexion[linea[0]][linea[1]] = atoi(costo.c_str());
        enrutador = enrutador + linea[0] + "-" + costo;
        _conexion[linea[0]].push_back(enrutador);
    }
    for(auto outer_iter=_conexion.begin(); outer_iter!=_conexion.end(); ++outer_iter) {
        for(auto inner_iter=outer_iter->second.begin(); inner_iter!=outer_iter->second.end(); ++inner_iter) {
            cout << "[" << outer_iter->first << "," << inner_iter->first << "] = " << inner_iter->second << endl;
        }
    }
    for(auto par = _conexion.begin(); par != _conexion.end(); par++){
        for(auto enru = par->second.begin(); enru != par->second.end();enru++){
            cout << "[" << par->first << "] = " << par->second<< endl;
        }
    }
    auto search = _conexion.find('A');
    cout << search->first << endl;



    for(auto var : _conexion){
        cout << var.first << endl;
    }
    system("PAUSE");
}*/

/*void conexion::cambiarConfiguracion(char*a, char *b, int costo){
    this->_conexion[*a][*b] = costo;
    this->_conexion[*b][*a] = costo;
    for(auto outer_iter=_conexion.begin(); outer_iter!=_conexion.end(); ++outer_iter) {
        for(auto inner_iter=outer_iter->second.begin(); inner_iter!=outer_iter->second.end(); ++inner_iter) {
            cout << "[" << outer_iter->first << "," << inner_iter->first << "] = " << inner_iter->second << endl;
        }
    }
}*/

/*void conexion::cambiarConfiguracion(char *a){
    for(auto outer_iter=_conexion.begin(); outer_iter!=_conexion.end(); ++outer_iter) {
        if(outer_iter->first == *a){
            this->_conexion.erase(*a);
        }
    }*/
    /*for(auto outer_iter=_conexion.begin(); outer_iter!=_conexion.end(); ++outer_iter) {
        for(auto inner_iter=outer_iter->second.begin(); inner_iter!=outer_iter->second.end(); ++inner_iter) {
            cout << "[" << outer_iter->first << "," << inner_iter->first << "] = " << inner_iter->second << endl;
        }
    }
}*/
