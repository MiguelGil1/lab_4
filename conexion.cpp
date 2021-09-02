#include "conexion.h"

map<string,list<Enrutador>> conexion::cargarDatos(map<string,list<Enrutador>> contenedor, string _archivo){
    Enrutador enrutador;
    //Enrutador enrutadorNoDirecto;
    vector<string> enrutadores;
    ifstream file;
    string linea;
    string costo = "";
    file.open("../"+ _archivo);
    string enrutador_salida = "";
    bool encontrado = false;
    while(!file.eof()){
        encontrado = false;
        file >> linea;
        costo = "";
        enrutador_salida = linea[0];
        enrutador.nombre = linea[1];
        costo.append(linea,linea.find(",")+1,linea.find("\n"));
        enrutador.costo = atoi(costo.c_str());
        enrutador.ruta = "";
        contenedor[enrutador_salida].push_back(enrutador);
        for(auto i = enrutadores.begin(); i != enrutadores.end(); i++){
            if(*i == enrutador_salida){
                encontrado = true;
            }
        }
        if(encontrado == false){
            enrutadores.push_back(enrutador_salida);
            enrutador_salida = linea[0];
            enrutador.nombre = linea[0];
            enrutador.costo = 0;
            enrutador.ruta = "";
            contenedor[enrutador_salida].push_back(enrutador);
        }
    }
    for(auto i = enrutadores.begin(); i != enrutadores.end(); i++){//SE RECORRE EL VECTOR DE ENRUTADORES
        for(auto par = contenedor.begin(); par != contenedor.end(); par++){//SE RECORRE EL MAPA
            encontrado = false;
            for(auto enru = par->second.begin(); enru != par->second.end(); enru++){//SE RECORRE LA LISTA DENTRO DEL MAPA
                if(*i == enru->nombre){
                    encontrado = true;
                    break;
                }
            }
            //SE EVALUA SI SE ENCONTRO EL ENRUTADOR EN LA LISTA DEL MAPA
            if(encontrado == false){
                enrutador_salida = par->first;
                enrutador.nombre = *i;
                enrutador.costo = -1;
                enrutador.ruta = "";
                contenedor[enrutador_salida].push_back(enrutador);
            }
        }
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
    contenedor.erase(a);

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

map<string, list<Enrutador> > conexion::cambiarConfiguracion(map<string, list<Enrutador> > contenedor, vector<string> enlaces){
    Enrutador enrutador;
    string enrutador_salida = "";
    string enrutador_llegada = "";
    string costo = "";
    for(auto i = enlaces.begin(); i != enlaces.end(); i++){
        enrutador_salida = "";
        enrutador_llegada = "";
        costo = "";
        enrutador_salida = i[0][0];
        enrutador_llegada = i[0][1];
        enrutador.nombre = enrutador_llegada;
        for(int j = 3; j <= int(i[0].length()) - 1; j++){
           costo += i [0][j];
        }
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
