/*
 CONDICIONES DE USO DEL PROGRAMA:

 1.) El archivo de configuracion de red debe encontrarse en la siguiente ruta
 relativa:
 ../nombre_archivo.txt
 Y debe tener una extension .txt
*/
#include <iostream>

using namespace std;

int main()
{
    string archivo =  "";
    cout << "COSTOS DE UN ENRUTADOR A OTRO." << endl;
    cout << "\nIngrese el nombre del archivo que contiene la configuracion de red: " << endl;
    cin >> archivo;
    return 0;
}
