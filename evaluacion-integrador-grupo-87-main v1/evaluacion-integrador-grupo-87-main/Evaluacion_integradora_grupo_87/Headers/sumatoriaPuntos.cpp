#include <iostream>
#include "sumatoriaPuntos.h"
using namespace std;

int sumarPuntos(int dadosSumadores[], int dadosBloqueadores[], int tam) {
    int puntos = 0;

    // Verificar cuáles dados en `dadosSumadores` están bloqueados
    for (int i = 0; i < tam; i++) {
        bool dadoValido = true;
        for (int j = 0; j < tam; j++) {
            if (dadosSumadores[i] == dadosBloqueadores[j]) {
                dadoValido = false; // Marcar el dado como inválido si está bloqueado
                break;
            }
        }

        // Sumar solo los dados que están marcados como válidos
        if (dadoValido) {
            puntos += dadosSumadores[i];
        }
    }

    cout << "Total de puntos (excluyendo dados bloqueados): " << puntos << endl;
    return puntos;
}


