#include <iostream>
#include "nombrejugador.h"
#include "dadosbloqueadores.h"
#include "dadossumadores.h"
#include "sumatoriaPuntos.h"
#include "cambioDeRonda.h"
#include "estadisticas.h"
#include <ctime>
using namespace std;

void unJugador()
{
    char eleccionUjugador = 's';
    int puntosTotales = 0;
    int puntosTotalesRondas = 0;
    int puntajeTotal;

    cout << "Modo un jugador seleccionado" << endl;
    cout << "-------------------------------------" << endl;

    string nombre = nombreJugador();

    // Inicializar los arrays de dados bloqueadores
    int dadosBloqueados[5];
    int tamBloqueados = 5;
    cout << "--------------------------------------" << endl;

    // Repetir exactamente 3 rondas
    for (int ronda = 1; ronda <= 3; ronda++) {
        cout << "RONDA: " << ronda << endl;

        // Resetear puntos de la ronda actual y volver a 5 dados
        puntosTotales = 0;
        int tamActual = 5;

        // Generar nuevos dados bloqueadores para la ronda actual
        dadosBloqueadores(dadosBloqueados);

        // Llamar a cambioDeRonda para manejar la lógica de la ronda
        cambioDeRonda(dadosBloqueados, tamBloqueados, tamActual, puntosTotales, eleccionUjugador, ronda);

        // Sumar los puntos de la ronda actual al total de todas las rondas
        puntosTotalesRondas += puntosTotales;
    }

    cout << "Finalizo el juego." << endl;
    cout << "-------------------------------" << endl;
    cout << "El jugador " << nombre << " hizo una totalidad de: " << puntosTotalesRondas << " puntos." << endl;

    puntajeTotal = puntosTotalesRondas;

    // Registrar el puntaje total en las estadísticas
    estadisticas(nombre, puntajeTotal);

}
