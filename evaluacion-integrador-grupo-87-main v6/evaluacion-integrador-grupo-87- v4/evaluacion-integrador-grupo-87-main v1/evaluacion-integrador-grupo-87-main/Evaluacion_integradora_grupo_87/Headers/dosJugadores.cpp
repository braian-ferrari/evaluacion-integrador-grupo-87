#include <iostream>
#include "nombrejugador.h"
#include "dadosbloqueadores.h"
#include "cambioDeRonda.h"
#include "estadisticas.h"
#include <ctime>
using namespace std;

void dosJugadores() {
    string nombre1 = nombreJugador();
    string nombre2 = nombreJugador();
    int puntosTotales1 = 0, puntosTotales2 = 0;
    int puntosTotalesRondas1 = 0, puntosTotalesRondas2 = 0;
    int tamBloqueados = 2;
    int dadosBloqueados[2];
    char eleccionUjugador = 's';

    cout << "Modo dos jugadores seleccionado" << endl;
    cout << "-------------------------------------" << endl;

    for (int ronda = 1; ronda <= 3; ronda++) {
        cout << endl << "RONDA: " << ronda << " para " << nombre1 << endl << endl;
        dadosBloqueadores(dadosBloqueados); // Generar dados bloqueadores para la ronda
        int tamActual = 5;
        puntosTotales1 = 0;

        cambioDeRonda(dadosBloqueados, tamBloqueados, tamActual, puntosTotales1, eleccionUjugador, ronda);
        puntosTotalesRondas1 += puntosTotales1;

        cout << endl << "RONDA: " << ronda << " para " << nombre2 << endl << endl;
        dadosBloqueadores(dadosBloqueados); // Generar nuevos dados bloqueadores para el segundo jugador
        tamActual = 5;
        puntosTotales2 = 0;

        cambioDeRonda(dadosBloqueados, tamBloqueados, tamActual, puntosTotales2, eleccionUjugador, ronda);
        puntosTotalesRondas2 += puntosTotales2;
    }

    cout << endl << endl << "Finalizo el juego." << endl;
    cout << "-------------------------------------" << endl;
    cout << "El jugador " << nombre1 << " hizo una totalidad de: " << puntosTotalesRondas1 << " puntos." << endl;
    cout << "El jugador " << nombre2 << " hizo una totalidad de: " << puntosTotalesRondas2 << " puntos." << endl;

    // Guardar estadísticas de ambos jugadores
    estadisticas(nombre1, puntosTotalesRondas1);
    estadisticas(nombre2, puntosTotalesRondas2);

    // Mostrar las estadísticas actualizadas
    mostrarEstadisticas();
}
