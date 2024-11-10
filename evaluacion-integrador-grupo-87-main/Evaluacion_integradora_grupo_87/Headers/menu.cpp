#include <iostream>
#include "menu.h"
#include "unjugador.h"

using namespace std;

int seleccionDelUsuario() {
    int eleccionUsuario;
    cout << "GREDD" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "1 - MODO UN JUGADOR" << endl;
    cout << "2 - MODO DOS JUGADORES" << endl;
    cout << "3 - ESTADISTICAS" << endl;
    cout << "4 - CREDITOS" << endl;
    cout << "----------------------------------------------------" << endl;
    cout << "5 - SALIR" << endl;
    cin >> eleccionUsuario;
    return eleccionUsuario;
}

void procesarLaEleccion(int eleccionUsuario) {
    switch (eleccionUsuario) {
        case 1:
           unJugador();
            break;
        case 2:
            cout << "Modo dos jugadores seleccionado" << endl;
            break;
        case 3:
            cout << "Estadísticas seleccionadas" << endl;
            break;
        case 4:
            cout << "Créditos seleccionados" << endl;
            break;
        case 5:
            cout << "Saliendo..." << endl;
            break;
        default:
            cout << "Opción no válida" << endl;
            break;
    }
}
