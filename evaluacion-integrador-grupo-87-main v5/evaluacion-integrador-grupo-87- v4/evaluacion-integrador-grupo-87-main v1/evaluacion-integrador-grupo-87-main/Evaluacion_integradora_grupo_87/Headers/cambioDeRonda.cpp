#include <iostream>
#include "dadossumadores.h"
#include "sumatoriaPuntos.h"
#include <cctype>
using namespace std;

void cambioDeRonda(int dadosBloqueados[], int tamBloqueados, int& tamActual, int& puntosTotales, char& eleccionUjugador, int ronda) {
    int puntosRonda = 0;

    do {
        int puntosTirada = 0;
        int dadosAsumar[5];
        dadosSumadores(dadosAsumar, tamActual);

        cout << "DADOS BLOQUEADORES: ";
        for (int i = 0; i < tamBloqueados; i++) {
            cout << dadosBloqueados[i] << " ";
        }
        cout << endl;

        // Comprobar si todos los dados son iguales y que haya más de uno
        bool todosIguales = (tamActual > 1);
        for (int i = 1; i < tamActual && todosIguales; i++) {
            if (dadosAsumar[i] != dadosAsumar[0]) {
                todosIguales = false;
            }
        }

        // Si todos los dados son iguales y no son bloqueadores, duplicar el puntaje
        bool sonDiferentesABloqueadores = true;
        for (int i = 0; i < tamBloqueados; i++) {
            if (dadosAsumar[0] == dadosBloqueados[i]) {
                sonDiferentesABloqueadores = false;

            }
        }

        // Calcular puntos y aplicar duplicación si es necesario
        puntosTirada = sumarPuntos(dadosAsumar, dadosBloqueados, tamActual, tamBloqueados);

        if (todosIguales && sonDiferentesABloqueadores) {
            puntosTirada *= 2; // Duplica el puntaje de la tirada
            cout << "¡Todos los dados son iguales! Se duplican los puntos obtenidos en esta tirada." << endl;
            dadosSumadores(dadosAsumar, tamActual); // Regenerar los dados sumadores para la nueva tirada forzada
            eleccionUjugador = 's'; // Obligar a tirar de nuevo
        } else {
            cout << "Puntos obtenidos en esta tirada: " << puntosTirada << endl;
            eleccionUjugador = 'n'; // Permitir la elección del jugador si no fue tirada forzada
        }

        puntosRonda += puntosTirada;
        cout << "--------------------------------------" << endl;

        // Crear un nuevo array para los dados sumadores restantes después de eliminar repetidos
        int nuevosDados[5];
        int nuevoTam = 0;

        // Verificar dados que no se repiten para mantenerlos en el siguiente turno
        for (int i = 0; i < tamActual; i++) {
            bool esRepetido = false;
            for (int j = 0; j < tamBloqueados; j++) {
                if (dadosAsumar[i] == dadosBloqueados[j]) {
                    esRepetido = true;

                }
            }
            if (!esRepetido) {
                nuevosDados[nuevoTam++] = dadosAsumar[i];
            }
        }

        // Copiar nuevos dados no bloqueados a dadosAsumar y ajustar tamActual
        for (int i = 0; i < nuevoTam; i++) {
            dadosAsumar[i] = nuevosDados[i];
        }
        tamActual = nuevoTam;

        // Preguntar al jugador si desea continuar solo si quedan dados activos y no se forzó a tirar de nuevo
        if (tamActual > 0 && !(todosIguales && sonDiferentesABloqueadores)) {
            cout << "Desea realizar otra tirada en esta ronda? (s/n): ";
            cin >> eleccionUjugador;
            eleccionUjugador = tolower(eleccionUjugador);
        } else if (tamActual == 0) {
            cout << "Perdiste la ronda, todos los dados han sido eliminados. Cambiando de ronda." << endl;
            puntosRonda = 0;
            eleccionUjugador = 'n';
            tamActual = 5; // Restablecer los dados sumadores para la siguiente ronda
        }

    } while (eleccionUjugador == 's' && tamActual > 0);

    cout << "Puntos acumulados en la ronda " << ronda << " : " << puntosRonda << endl;
    puntosTotales += puntosRonda;
}


