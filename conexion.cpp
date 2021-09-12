#include "conexion.h"

/*map<string,list<Enrutador>> conexion::cargarDatos(map<string,list<Enrutador>> contenedor, string _archivo){
    Enrutador enrutador;
    //Enrutador enrutadorNoDirecto;
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
        //SE AGREGAN TODOS LOS ENRUTADORES AL VECTOR ENRUTADORES
        //CON EL OBJETIVO DE LUEGO HAYAR LAS CONEXIONES INDIRECTAS
        for(auto i = enrutadoresExistentes.begin(); i != enrutadoresExistentes.end(); i++){
            if(*i == enrutador_salida){
                encontrado = true;
            }
        }
        if(encontrado == false){
            enrutadoresExistentes.push_back(enrutador_salida);
            //CASO EN EL QUE ENRUTADOR DE SALIDA = ENRUTADOR DE LLEGADA
            enrutador_salida = linea[0];
            enrutador.nombre = linea[0];
            enrutador.costo = 0;
            enrutador.ruta = "";
            contenedor[enrutador_salida].push_back(enrutador);
        }
    }
    for(auto i = enrutadoresExistentes.begin(); i != enrutadoresExistentes.end(); i++){//SE RECORRE EL VECTOR DE ENRUTADORES
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
}*/

//FUNCION QUE PERMITE CAMBIAR EL COSOTO DE ENLACE ENTRE ENRUTADORES
/*map<string,list<Enrutador>> conexion::cambiarConfiguracion(map<string, list<Enrutador>> contenedor, string a, string b, int costo){
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        if(par->first == a){
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                if(enru->nombre == b){                    
                    if(enru->costo == -1){
                        cout << "\nAdertencia: Cambiando enrutadores no dierectos a directos." << endl;
                    }
                    enru->costo = costo;*/
                    /*if(enru->costo != -1){
                        enru->costo = costo;
                    }else{
                        cout << "Advertencia!\nNo se puede cambiar el costo entre " << a
                             << " y " << b << " porque son enrutadores no conectados dierectamente!" << endl;
                        indirectos = true;
                    }*/
               /* }
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
}*/

//FUNCION QUE PERMITE ELIMINAR ENRUTADORES DE LA CONEXION
/*map<string, list<Enrutador> > conexion::cambiarConfiguracion(map<string, list<Enrutador> > contenedor, string a){
    Enrutador enrutador;
    //list <Enrutador> *my_list;
    //ELIMINAMOS LA EL ENRUTADOR SELECCIONADO
    cout << "ELIMINANDO EL ENRUTADOR " << a << endl;
    contenedor.erase(a);

    //ELIMINAMOS EL ENRUTADOR DE LOS DEMAS ENRUTADORES
    cout << "ELIMINANDO EL ENLACE DE " << a << " DE LOS DEMAS ENRUTADORES." << endl;
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        for (auto enru = begin(par->second); enru != end(par->second); enru++){         
            if(enru->nombre == a){
                par->second.erase(enru);
                break;
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
}*/

//FUNCION QUE POSIBILITA ENLAZAR UN ENRUTADOR CON OTRO
/*map<string, list<Enrutador> > conexion::cambiarConfiguracion(map<string, list<Enrutador> > contenedor, vector<string> enlaces, string salida){
    Enrutador enrutador;
    string enrutador_salida = "";
    string enrutador_llegada = "";
    string costo = "";
    bool encontrado = false;*/
    /*for(auto j = contenedor.begin(); j != contenedor.end(); j++){
        if(j->first == salida){
            cout << "El enrutador que usted esta intentando agregar, ya se enceuntra alojado en la conexion." << endl;
            return contenedor;
        }
    }*/
    /*for(auto i = enlaces.begin(); i != enlaces.end(); i++){
        if (i == enlaces.begin()){
            //SE DEBE EN PRIMERA INSTACIA AGREGAR LA CONEXION SALIDA-SALIDA
            //LA CUAL ES IGUAL A 0 Y SIEMPRE VA A ESTAR EN LA PRIMER POSICION
            //DEL VECTOR ENRUTADORES
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
        }else{
            //LUEGO SE EVALUAN LAS DEMAS CONEXIONES
            //SE DEBE EVALUAR QUE LA CONEXION EXISTA
            //EN AMBOS SENTIDOS DE ENRUTADOR_A_AGREGAR - ENRUTADOR_DIRECTO
            encontrado = false;
            enrutador_salida = "";
            enrutador_llegada = "";
            costo = "";
            enrutador_salida = i[0][0];
            enrutador_llegada = i[0][1];
            //SE EVALUA SI EXISTE LA CLAVE
            if(enrutador_llegada == salida){
                for(auto i = contenedor.begin(); i != contenedor.end(); i++){
                    //se evalua que el enrutador de llegada exista en en la conexion
                    if(i->first == enrutador_salida){
                        encontrado = true;
                    }
                }
                if(encontrado == true){
                    enrutador.nombre = enrutador_llegada;
                    for(int j = 3; j <= int(i[0].length()) - 1; j++){
                       costo += i [0][j];
                    }
                    enrutador.costo = atoi(costo.c_str());
                    enrutador.ruta = "";
                    contenedor[enrutador_salida].push_back(enrutador);
                }else{
                    cout << "No se pudo agregar el enlace " <<
                            enrutador_salida << " - " << enrutador_llegada <<
                            " porque el enrutador de salida no existe en la conexion." << endl;
                }
            }else if(enrutador_salida == salida){
                for(auto i = contenedor.begin(); i != contenedor.end(); i++){
                    //se evalua que el enrutador de llegada exista en en la conexion
                    if(i->first == enrutador_llegada){
                        encontrado = true;
                    }
                }
                if(encontrado == true){
                    enrutador.nombre = enrutador_llegada;
                    for(int j = 3; j <= int(i[0].length()) - 1; j++){
                       costo += i [0][j];
                    }
                    enrutador.costo = atoi(costo.c_str());
                    enrutador.ruta = "";
                    contenedor[enrutador_salida].push_back(enrutador);
                }else{
                    cout << "No se pudo aggregar la conexion directa " <<
                            enrutador_salida << " - " << enrutador_llegada <<
                            " porque el enrutador de llegada no existe en la conexion." << endl;
                }
            }
        }
    }
    encontrado = false;
    //PARA HALLAR CONECCIONES INDIRECTAS AL ENRUTADOR CREADO
    for(auto par = contenedor.begin(); par != contenedor.end(); par++){//SE RECORRE EL MAPA
        encontrado = false;
        for(auto enru = par->second.begin(); enru != par->second.end(); enru++){//SE RECORRE LA LISTA DENTRO DEL MAPA
            if(salida == enru->nombre){
                encontrado = true;
                break;
            }
        }
        //SE EVALUA SI SE ENCONTRO EL ENRUTADOR EN LA LISTA DEL MAPA
        if(encontrado == false){
            enrutador_salida = par->first;
            enrutador.nombre = salida;
            enrutador.costo = -1;
            enrutador.ruta = "";
            contenedor[enrutador_salida].push_back(enrutador);
            enrutador_salida = salida;
            enrutador.nombre = par->first;
            enrutador.costo = -1;
            enrutador.ruta = "";
            contenedor[enrutador_salida].push_back(enrutador);
        }
    }
    for (auto par = begin(contenedor); par != end(contenedor); par++){
        cout << endl << "Enrutador salida: " << par->first << endl;
        for (auto enru = begin(par->second); enru != end(par->second); enru++){
            cout << "Enrutador llegada: " << enru->nombre << " - costo: " << enru->costo << " - ruta: " << enru->ruta << endl;
        }
    }
    return contenedor;
}*/

/*void conexion::imprimirRuta(map<string, list<Enrutador> > contenedor, string a, string b){
    bool encontradoSalida = false;
    bool encontrarLlegada = false;
    for(auto i = enrutadoresExistentes.begin(); i != enrutadoresExistentes.end(); i++){
        if(*i == a){
            encontradoSalida = true;
        }
        if(*i == b){
            encontrarLlegada = true;
        }
    }
    if(encontradoSalida == false && encontrarLlegada == false){
        cout << "No se encontraron los enrutadores ingresados :(" << endl;
    }else if(encontrarLlegada == false){
        cout << "No se encontro el enrutador de llegada :(" << endl;
    }else if(encontradoSalida == false){
        cout << "No se encontro el enrutador de salida :(" << endl;
    }else{
        for(auto par = contenedor.begin(); par != contenedor.end(); par++){
            if(par->first == a){
                for(auto enru = par->second.begin(); enru != par->second.end(); enru++){
                    if(enru->nombre == b){
                        cout << "Ruta: " << enru->ruta << endl;
                        cout << "Costo: " << enru->costo << endl;
                    }
                }
            }
        }
    }
}*/

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

void conexion::cargarDatos(string _archivo){
    Caracteristicas enrutador;

    ifstream file;
    string linea;

    file.open("../"+ _archivo);
    string enrutadorSalida = "";

    bool encontrado = false;
    while(!file.eof()){
        encontrado = false;
        file >> linea;
        enrutadorSalida = linea[0];
        string enrutadorSalida_ = enrutadorSalida;
        //SE AGREGAN TODOS LOS ENRUTADORES AL VECTOR ENRUTADORES
        //CON EL OBJETIVO DE LUEGO HAYAR LAS CONEXIONES INDIRECTAS
        for(auto i = enrutadoresExistentes.begin(); i != enrutadoresExistentes.end(); i++){
            if(*i == enrutadorSalida){
                encontrado = true;
            }
        }
        if(encontrado == false){
            enrutadoresExistentes.push_back(enrutadorSalida);
            Enrutador enrutadorSalida(enrutadorSalida_);
            _topologia.push_back(enrutadorSalida);
        }
    }
    file.close();
    file.open("../"+ _archivo);

    string costoDirectoStr = "";
    int costoDirecto = 0;
    string enrutadorLlegada = "";
    while(!file.eof()){
        file >> linea;
        costoDirectoStr = "";
        enrutadorSalida = linea[0];
        string enrutadorSalida_ = enrutadorSalida;
        enrutadorLlegada = linea[1];
        costoDirectoStr.append(linea,linea.find(",")+1,linea.find("\n"));
        costoDirecto = stoi(costoDirectoStr);
        for(auto i = _topologia.begin(); i != _topologia.end(); i++){
            string nombreSalida = i->Getnombre();
            if(enrutadorSalida_ == nombreSalida){
                enrutador.costoDirecto = costoDirecto;
                enrutador.costo = 0;
                enrutador.ruta = "";
                map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
                _enrutador[enrutadorLlegada].push_back(enrutador);
                i->setEnrutador(_enrutador);
            }
        }

    }

    //ENCONTRAMOS ENLACES INDIRECTOS
    for(auto i = enrutadoresExistentes.begin(); i != enrutadoresExistentes.end(); i++){
        for(auto j = _topologia.begin(); j != _topologia.end(); j++){
            string nombreSalida = j->Getnombre();
            map<string, list<Caracteristicas>> _enrutador = j->Getenrutador();
            for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
                encontrado = false;
                if(*i == par->first){
                    encontrado = true;
                    break;
                }
            }
            if(encontrado == false){
                enrutador.costoDirecto = -1;
                enrutador.costo = 0;
                enrutador.ruta = "";
                _enrutador[*i].push_back(enrutador);
                j->setEnrutador(_enrutador);
            }
        }
    }

    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        cout << endl << "Enrutador salida: " << nombreSalida << endl;
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
            cout << endl << "Enrutador llegada: " << par->first << " - ";
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                cout << "Costo Directo: " << enru->costoDirecto << " - costo: " << enru->costo << " - ruta: " << enru->ruta << endl;
            }
        }
        cout << endl;
    }
    calcularRutas();
    system("PAUSE");
}

//FUNCION QUE PERMITE ELIMINAR ENRUTADORES DE LA CONEXION
void conexion::cambiarConfiguracion(string enrutadorEliminar){
    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        if(nombreSalida == enrutadorEliminar){
            _topologia.erase(i);
            //i->~Enrutador();
            break;
        }
    }
    //ELIMINAMOS EL ENRUTADOR DE LOS DEMAS ENRUTADORES
    cout << "ELIMINANDO EL ENLACE DE " << enrutadorEliminar << " DE LOS DEMAS ENRUTADORES." << endl;
    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        _enrutador.erase(enrutadorEliminar);
        i->setEnrutador(_enrutador);
    }

    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        cout << endl << "Enrutador salida: " << nombreSalida << endl;
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
            cout << endl << "Enrutador llegada: " << par->first << " - ";
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                cout << "Costo Directo: " << enru->costoDirecto << " - costo: " << enru->costo << " - ruta: " << enru->ruta << endl;
            }
        }
        cout << endl;
    }
    _rutas.clear();
    calcularRutas();
}

void conexion::calcularRutas(){
    string ruta = "";
    //HALLAMOS RUTAS DE CONEXIONES DIRECTAS
    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                if(enru->costoDirecto != -1 and nombreSalida != par->first){
                    _rutas[nombreSalida+par->first] = enru->costoDirecto;
                }
            }
        }
    }

    bool encontrado = false;
    for(auto par = _rutas.begin(); par != _rutas.end(); par++){
        ruta = par->first;
        for(auto i = _topologia.begin(); i != _topologia.end(); i++){
            string nombreSalida = i->Getnombre();
            encontrado = false;
            for(int i = 0; i < int(ruta.length()); i++){
                if(ruta[i] == par->first[0]){
                    encontrado = true;
                    break;
                }
            }
            //ruta[0]+nombreSalida == ruta
            if(encontrado == true){//PROBLEMA SOLO ME VA A TOMAR 3 ENRUTADORES MAXIMO -> RESUELTO
                //PROBLEMA: COSTOS! NO IMPRIME LOS COSTOS COMO SON
                map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
                for(auto parTop = _enrutador.begin(); parTop != _enrutador.end(); parTop++){
                    encontrado = false;
                    for(int i = 0; i < int(ruta.length()); i++){
                        if(ruta[i] == parTop->first[0]){
                            encontrado = true;
                        }
                    }

                    for (auto enru = begin(parTop->second); enru != end(parTop->second); enru++){
                        if(enru->costoDirecto != -1 and encontrado == false){
                            int costo = 0;
                            string rutaIngresar = "";
                            rutaIngresar = ruta+parTop->first[0];
                            //cout << rutaIngresar << endl;
                            for(int i = 0; i < int(rutaIngresar.length())-1; i++){
                                string r = "";
                                r += rutaIngresar[i];
                                r+= rutaIngresar[i+1];
                                //cout << r << endl;
                                costo += _rutas.find(r)->second;
                            }
                            _rutas[rutaIngresar] = costo;
                            //_rutas[ruta+parTop->first] = enru->costoDirecto + par->second;
                        }
                    }
                }
            }
        }
    }

    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        i->calcularMejorRuta(_rutas);
    }

    //IMPRIMIMOS EL MAPA DE RUTAS
    for(auto par = _rutas.begin(); par != _rutas.end(); par++){
        cout << "RUTA = " << par->first << " - COSTO = " << par->second << endl;
    }
}

void conexion::imprimirRuta(string a, string b){
    bool encontradoSalida = false;
    bool encontrarLlegada = false;
    for(auto i = enrutadoresExistentes.begin(); i != enrutadoresExistentes.end(); i++){
        if(*i == a){
            encontradoSalida = true;
        }
        if(*i == b){
            encontrarLlegada = true;
        }
    }
    if(encontradoSalida == false && encontrarLlegada == false){
        cout << "No se encontraron los enrutadores ingresados :(" << endl;
    }else if(encontrarLlegada == false){
        cout << "No se encontro el enrutador de llegada :(" << endl;
    }else if(encontradoSalida == false){
        cout << "No se encontro el enrutador de salida :(" << endl;
    }else{
        for(auto i = _topologia.begin(); i != _topologia.end(); i++){
            string nombreSalida = i->Getnombre();
            if(nombreSalida == a){
                map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
                for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
                    if(par->first == b){
                        for (auto enru = begin(par->second); enru != end(par->second); enru++){
                            cout << "Ruta: " << enru->ruta << " - costo: " << enru->costo << endl;
                        }
                    }
                }
            }
        }
    }
}
