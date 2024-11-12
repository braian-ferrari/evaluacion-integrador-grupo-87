#include <iostream>
#include "menu.h"
#include "unjugador.h"
#include "dosjugadores.h"
#include "creditos.h"
#include "estadisticas.h"
#include <string>
#include "rlutil.h"

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
    string nombre;
    int puntajeTotal;
        switch (eleccionUsuario) {
        case 1:
           unJugador();
            break;
        case 2:
            cout << "Modo dos jugadores seleccionado" << endl;
            dosJugadores();
            break;
        case 3:
            cout << "Estadisticas seleccionadas" << endl;
             mostrarEstadisticas();
            break;
        case 4:
            mostrarCreditos();
            break;
        case 5:
            cout << "Gracias por usar el juego! Saliendo..." << endl;
            break;
        default:
            rlutil::setColor(rlutil::RED);
            cout << "Opcion no valida, intente nuevamente" << endl;
            break;
    }
}
