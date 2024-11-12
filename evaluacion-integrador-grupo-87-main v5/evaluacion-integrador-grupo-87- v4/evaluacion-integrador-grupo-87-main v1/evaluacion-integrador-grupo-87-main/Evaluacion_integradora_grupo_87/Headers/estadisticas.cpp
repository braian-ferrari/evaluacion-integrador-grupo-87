#include "estadisticas.h"
#include <iostream>
#include <string>
using namespace std;

string nombresTop[5] = {""};
int puntajesTop[5] = {0};

void estadisticas(const string& nombre, int puntaje) {
    int minIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (puntajesTop[i] < puntajesTop[minIndex]) {
            minIndex = i;
        }
    }

    if (puntaje > puntajesTop[minIndex]) {
        puntajesTop[minIndex] = puntaje;
        nombresTop[minIndex] = nombre;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (puntajesTop[j] > puntajesTop[i]) {
                int tempPuntaje = puntajesTop[i];
                puntajesTop[i] = puntajesTop[j];
                puntajesTop[j] = tempPuntaje;

                string tempNombre = nombresTop[i];
                nombresTop[i] = nombresTop[j];
                nombresTop[j] = tempNombre;
            }
        }
    }
}

void mostrarEstadisticas() {
    cout << "Top 5 puntajes:\n";
    for (int i = 0; i < 5; i++) {
    if (puntajesTop[i] > 0) { // Mostrar solo si el puntaje es mayor a 0
        cout<<"----------------------------------------------------"<<endl;
        cout << nombresTop[i] << ": " << puntajesTop[i] << " puntos" << endl;
        cout<<"--------------------------------------------------------"<<endl;
    }
}

}

