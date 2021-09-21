#include "conexion.h"
void conexion::cargarDatos(string _archivo){
    Caracteristicas enrutador;

    ifstream file;
    string linea;

    file.open(_archivo);
    string enrutadorSalida = "";

    bool encontrado = false;

    //Se recorre linea a linea el archivo de conexion, para mirar cuantos enrutadores
    //se tienen, cada vez que hay im nuevo enrutador se crea y se llema a su
    //constructor
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
            //Si no se encontro el eenrutador de salida, se crea el objeto tipo enrutador
            enrutadoresExistentes.push_back(enrutadorSalida);
            Enrutador enrutadorSalida(enrutadorSalida_);
            _topologia.push_back(enrutadorSalida);
        }
    }
    file.close();
    file.open(_archivo);

    string costoDirectoStr = "";
    int costoDirecto = 0;
    string enrutadorLlegada = "";

    //Ahora que se tiene  los objetos tipo enrutador creados se procede a recorrer
    //nuevamente el archivo para hallar las conexiones directas
    while(!file.eof()){
        file >> linea;
        costoDirectoStr = "";
        enrutadorSalida = linea[0];
        string enrutadorSalida_ = enrutadorSalida;
        enrutadorLlegada = linea[1];
        costoDirectoStr.append(linea,linea.find(",")+1,linea.find("\n"));
        costoDirecto = stoi(costoDirectoStr);
        //Se recorre el vector de enrutadores para aggerar las caracteristicas del enrutador de llegada
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
    file.close();

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
            //Si no se encontro se agrega el enrutador
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
    cout << "\nDatos cargados correctamente! :)" << endl;
    calcularRutas();
    system("PAUSE");
}

void conexion::cargarDatos(map<string, int> topologiaConsola){
    Caracteristicas enrutador;

    bool encontrado = false;
    string enrutadorSalida = "";

    //Se recorre el mapa de topologia por consola para ,mirar cuantos enrutadores
    //se tienen, cada vez que hay im nuevo enrutador se crea y se llema a su
    //construcor
    for(auto i = topologiaConsola.begin(); i != topologiaConsola.end(); i++){
        encontrado = false;
        enrutadorSalida = i->first[0];
        string enrutadorSalida_ = enrutadorSalida;
        //SE AGREGAN TODOS LOS ENRUTADORES AL VECTOR ENRUTADORES
        //CON EL OBJETIVO DE LUEGO HAYAR LAS CONEXIONES INDIRECTAS
        for(auto j = enrutadoresExistentes.begin(); j != enrutadoresExistentes.end(); j++){
            if(*j == enrutadorSalida){
                encontrado = true;
            }
        }
        if(encontrado == false){
            //Si no se encontro el eenrutador de salida, se crea el objeto tipo enrutador
            enrutadoresExistentes.push_back(enrutadorSalida);
            Enrutador enrutadorSalida(enrutadorSalida_);
            _topologia.push_back(enrutadorSalida);
        }
    }

    int costoDirecto = 0;
    string enrutadorLlegada = "";

    for(auto i = topologiaConsola.begin(); i != topologiaConsola.end(); i++){
        enrutadorSalida = i->first[0];
        string enrutadorSalida_ = enrutadorSalida;
        enrutadorLlegada = i->first[1];
        costoDirecto = i->second;
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

    /*for(auto i = _topologia.begin(); i != _topologia.end(); i++){
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
    }*/
    cout << "\nDatos cargados correctamente! :)" << endl;
    calcularRutas();
    system("PAUSE");
}

//FUNCION QUE PERMITE ELIMINAR ENRUTADORES DE LA CONEXION
void conexion::cambiarConfiguracion(string enrutadorEliminar){
    //Se elimina el enrutador del vecor de enrutadores existentes
    for(auto i = enrutadoresExistentes.begin(); i != enrutadoresExistentes.end(); i++){
        if(*i == enrutadorEliminar){
            enrutadoresExistentes.erase(i);
            break;
        }
    }
    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        if(nombreSalida == enrutadorEliminar){
            _topologia.erase(i);
            //i->~Enrutador();
            break;
        }
    }
    //ELIMINAMOS EL ENRUTADOR DE LOS DEMAS ENRUTADORES
    //cout << "ELIMINANDO EL ENLACE DE " << enrutadorEliminar << " DE LOS DEMAS ENRUTADORES." << endl;
    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        _enrutador.erase(enrutadorEliminar);
        i->setEnrutador(_enrutador);
    }

    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        //cout << endl << "Enrutador salida: " << nombreSalida << endl;
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
            //cout << endl << "Enrutador llegada: " << par->first << " - ";
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                enru->costo = 0;
                //cout << "Costo Directo: " << enru->costoDirecto << " - costo: " << enru->costo << " - ruta: " << enru->ruta << endl;
            }
        }
        i->setEnrutador(_enrutador);
        //cout << endl;
    }
    _rutas.clear();
    calcularRutas();
}

//PERMITE CAMBIAR COSTOS
void conexion::cambiarConfiguracion(string a, string b, int c){
    for (auto i = begin(_topologia); i != end(_topologia); i++){
        string nombreSalida = i->Getnombre();
        if(nombreSalida == a || nombreSalida == b){
            map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
            for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
                if(par->first == b || par->first == a){
                    for(auto enru = par->second.begin(); enru != par->second.end(); enru++){
                        if(enru->costoDirecto == -1){
                            cout << "\nNo se puede cambiar el costo por que ambos son enrutadores indirectos\nDebe enlazarlos pra poder cambiar el cosoto." << endl;
                        }else{
                            enru->costoDirecto = c;
                            i->setEnrutador(_enrutador);
                        }
                    }
                }
            }
        }
    }

    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        //cout << endl << "Enrutador salida: " << nombreSalida << endl;
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
            //cout << endl << "Enrutador llegada: " << par->first << " - ";
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                enru->costo = 0;
                //cout << "Costo Directo: " << enru->costoDirecto << " - costo: " << enru->costo << " - ruta: " << enru->ruta << endl;
            }
        }
        i->setEnrutador(_enrutador);
        //cout << endl;
    }
    _rutas.clear();
    calcularRutas();
}

//PERMITE AGREGAR ENRUTADORES
void conexion::cambiarConfiguracion(vector<string> enlaces, string salida){
    Caracteristicas enrutador;

    string enrutador_salida = "";
    string enrutador_llegada = "";
    string costoDirecto = "";
    bool encontrado = false;

    //Primero evaluamos si el enrutador que se esta agregando ya existe en la topologi
    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        if(nombreSalida == salida){
            cout << "\nEl enrutador que usted esta intentando agregar, ya se enceuntra alojado en la conexion." << endl;
            encontrado = true;
            break;
        }
    }

    //Si no se encuentra se procesde a agregar el enrutador a la topologia
    if(encontrado == false){
        //Primero se crea el enrutador
        Enrutador enrutadorSalida(salida);
        enrutadoresExistentes.push_back(salida);
        _topologia.push_back(enrutadorSalida);
        //LUEGO SE EVALUAN LAS DEMAS CONEXIONES
        //SE DEBE EVALUAR QUE LA CONEXION EXISTA
        //EN AMBOS SENTIDOS DE ENRUTADOR_A_AGREGAR - ENRUTADOR_DIRECTO
        for(auto i = enlaces.begin(); i != enlaces.end(); i++){
            encontrado = false;
            enrutador_salida = "";
            enrutador_llegada = "";
            costoDirecto = "";
            enrutador_salida = i[0][0];
            enrutador_llegada = i[0][1];
             if(enrutador_llegada == salida){
                 //Se evalua si el enrutador de salida exista
                 for(auto i = _topologia.begin(); i != _topologia.end(); i++){
                     string nombreSalida = i->Getnombre();
                     if(nombreSalida == enrutador_salida){
                         encontrado = true;
                         break;
                     }
                 }
                 //Si existe, se procede a crear la conexion agg las caracteristicas
                 if (encontrado == true){
                     for(auto k = _topologia.begin(); k != _topologia.end(); k++){
                         string nombreSalida = k->Getnombre();
                         if(enrutador_salida == nombreSalida){
                             for(int j = 3; j <= int(i[0].length()) - 1; j++){
                                costoDirecto += i [0][j];
                             }
                             enrutador.costoDirecto = stoi(costoDirecto);
                             enrutador.costo = 0;
                             enrutador.ruta = "";
                             map<string, list<Caracteristicas>> _enrutador = k->Getenrutador();
                             _enrutador[enrutador_llegada].push_back(enrutador);
                             k->setEnrutador(_enrutador);
                         }
                     }
                 }else{
                     //Si no existe, se imprime el siguiente mensaje
                     cout << "No se pudo agregar el enlace " <<
                             enrutador_salida << " - " << enrutador_llegada <<
                             " porque el enrutador de salida no existe en la conexion." << endl;
                 }

             }else if (enrutador_salida == salida){
                 //OPCION SI EL ENRUTADOR DE SALIDA ES IGUAL AL DE SALIDA
                 //Se evalua si se encuentra en elrutador de llegada
                 for(auto i = _topologia.begin(); i != _topologia.end(); i++){
                     string nombreSalida = i->Getnombre();
                     if(nombreSalida == enrutador_llegada){
                         encontrado = true;
                         break;
                     }
                 }
                 if(encontrado == true){
                     //Si se encuentra se procede a crear la conexion con sus caracteristicas
                     for(auto k = _topologia.begin(); k != _topologia.end(); k++){
                         string nombreSalida = k->Getnombre();
                         if(enrutador_salida == nombreSalida){
                             for(int j = 3; j <= int(i[0].length()) - 1; j++){
                                costoDirecto += i [0][j];
                             }
                             enrutador.costoDirecto = stoi(costoDirecto);
                             enrutador.costo = 0;
                             enrutador.ruta = "";
                             map<string, list<Caracteristicas>> _enrutador = k->Getenrutador();
                             _enrutador[enrutador_llegada].push_back(enrutador);
                             k->setEnrutador(_enrutador);
                         }
                     }
                 }else{
                     //Si no existe se procede a imprimir lo siguiente
                     cout << "No se pudo aggregar la conexion directa " <<
                             enrutador_salida << " - " << enrutador_llegada <<
                             " porque el enrutador de llegada no existe en la conexion." << endl;
                 }
             }
        }
    }
    //CALCULAMOS RUTAS INDIRECTAS
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
        //cout << endl << "Enrutador salida: " << nombreSalida << endl;
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
            //cout << endl << "Enrutador llegada: " << par->first << " - ";
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                enru->costo = 0;
                //cout << "Costo Directo: " << enru->costoDirecto << " - costo: " << enru->costo << " - ruta: " << enru->ruta << endl;
            }
        }
        i->setEnrutador(_enrutador);
        //cout << endl;
    }
    _rutas.clear();
    calcularRutas();
}

//PERMITE ENLAZAR DOS ENRUTADORES
void conexion::cambiarConfiguracion(string a, string b, string c){
    for (auto i = begin(_topologia); i != end(_topologia); i++){
        string nombreSalida = i->Getnombre();
        if(nombreSalida == a || nombreSalida == b){
            map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
            for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
                if(par->first == b || par->first == a){
                    for(auto enru = par->second.begin(); enru != par->second.end(); enru++){
                        if(enru->costoDirecto != -1){
                            //Si el costoDirecto es diferente de - se procede a imprir lo siguiente
                            cout << "\nNo se pueden enlazar los enrutadores, debido a que ya estan enlazados.\nSi desea cambiar el costo entre ambos, debe ingresar a la opcion 4." << endl;
                        }else{
                            //De lo contrario se enlazan los enrutadores
                            enru->costoDirecto = stoi(c);
                            i->setEnrutador(_enrutador);
                        }
                    }
                }
            }
        }
    }

    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        string nombreSalida = i->Getnombre();
        //cout << endl << "Enrutador salida: " << nombreSalida << endl;
        map<string, list<Caracteristicas>> _enrutador = i->Getenrutador();
        for(auto par = _enrutador.begin(); par != _enrutador.end(); par++){
            //cout << endl << "Enrutador llegada: " << par->first << " - ";
            for (auto enru = begin(par->second); enru != end(par->second); enru++){
                enru->costo = 0;
                //cout << "Costo Directo: " << enru->costoDirecto << " - costo: " << enru->costo << " - ruta: " << enru->ruta << endl;
            }
        }
        i->setEnrutador(_enrutador);
        //cout << endl;
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
    //Recorre las rutas directas encontradas
    for(auto par = _rutas.begin(); par != _rutas.end(); par++){
        ruta = par->first;
        for(auto i = _topologia.begin(); i != _topologia.end(); i++){
            string nombreSalida = i->Getnombre();
            encontrado = false;
            //Se evalua si estamos en el enrutador de la primera posicion de la ruta
            for(int i = 0; i < int(ruta.length()); i++){
                if(ruta[i] == par->first[0]){
                    encontrado = true;
                    break;
                }
            }
            //ruta[0]+nombreSalida == ruta
            //Si lo estamos, procedemos a calcular rutas
            if(encontrado == true){
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

    //Se recorre el vector de enrutadores y se encuentra la mejor ruta
    for(auto i = _topologia.begin(); i != _topologia.end(); i++){
        i->calcularMejorRuta(_rutas);
    }

    //IMPRIMIMOS EL MAPA DE RUTAS
    /*for(auto par = _rutas.begin(); par != _rutas.end(); par++){
        cout << "RUTA = " << par->first << " - COSTO = " << par->second << endl;
    }*/
}

void conexion::imprimirRuta(string a, string b){
    bool encontradoSalida = false;
    bool encontrarLlegada = false;
    //Se evalua si ambos enrutadores existen
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
        //Si existen, se procede a imprimir la mejor ruta
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
