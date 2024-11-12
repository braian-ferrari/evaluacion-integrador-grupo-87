#include<iostream>
#include <string>
#include "nombreJugador.h"

using namespace std;

string nombreJugador() {
    string nombre;
    cout << "Ingrese el nombre del jugador: ";
    cin >> nombre;
    return nombre;
}
