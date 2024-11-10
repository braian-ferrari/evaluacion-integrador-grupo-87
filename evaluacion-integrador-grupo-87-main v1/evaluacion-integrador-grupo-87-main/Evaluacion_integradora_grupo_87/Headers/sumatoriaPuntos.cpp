#include <iostream>
#include "sumatoriaPuntos.h"
using namespace std;

int sumarPuntos(int dadosSumadores[], int dadosBloqueadores[], int tam) {
    int puntos = 0;

    // Verificar cu�les dados en `dadosSumadores` est�n bloqueados
    for (int i = 0; i < tam; i++) {
        bool dadoValido = true;
        for (int j = 0; j < tam; j++) {
            if (dadosSumadores[i] == dadosBloqueadores[j]) {
                dadoValido = false; // Marcar el dado como inv�lido si est� bloqueado
                break;
            }
        }

        // Sumar solo los dados que est�n marcados como v�lidos
        if (dadoValido) {
            puntos += dadosSumadores[i];
        }
    }

    cout << "Total de puntos (excluyendo dados bloqueados): " << puntos << endl;
    return puntos;
}


