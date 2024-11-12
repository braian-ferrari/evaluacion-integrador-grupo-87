#include <iostream>
#include "sumatoriaPuntos.h"
using namespace std;


int sumarPuntos(int dadosSumadores[], int dadosBloqueadores[], int tamSumadores, int tamBloqueadores) {
     int puntos = 0;
    // Verificar cada dado en `dadosSumadores`
    for (int i = 0; i < tamSumadores; i++) {
        bool dadoValido = true;
        // Comprobar si el dado actual coincide con alguno de los dados bloqueadores
        for (int j = 0; j < tamBloqueadores; j++) {
            if (dadosSumadores[i] == dadosBloqueadores[j]) {
                dadoValido = false; // Marcar el dado como inválido si coincide con un bloqueador

            }
        }

        // Solo sumar el dado si es válido (no coincide con ningún bloqueador)
        if (dadoValido) {
            puntos += dadosSumadores[i];
        }
    }


    return puntos;
}


