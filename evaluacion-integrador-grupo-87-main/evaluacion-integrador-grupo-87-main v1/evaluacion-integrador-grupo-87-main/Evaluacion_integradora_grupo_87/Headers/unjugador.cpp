#include <iostream>
#include "nombrejugador.h"
#include "dadosbloqueadores.h"
#include "dadossumadores.h"
#include "sumatoriaPuntos.h"
#include <ctime>
using namespace std;

void unJugador()
{
    char seguirJugando = 's';
    char eleccionUjugador;
    int puntos;
    int puntosTotales = 0;

    cout << "Modo un jugador seleccionado" << endl;
    cout << "-------------------------------------" << endl;

    string nombre = nombreJugador();

    // Generar los dados bloqueadores solo una vez
    int dadosBloqueados[5];
    int tamBloqueados = 5; // Tamaño inicial del array de dados bloqueadores
    dadosBloqueadores(dadosBloqueados); // Llenar el array de dados bloqueadores una vez

    int tamActual = 5; // Tamaño actual del array de dados sumadores
    cout << "--------------------------------------" << endl;

    do
    {
        // Mostrar los dados bloqueadores actuales
        cout << "DADOS BLOQUEADORES: "<<endl;
        for (int i = 0; i < tamBloqueados; i++)
        {
            cout << dadosBloqueados[i] << " "<<endl;
        }
        cout << endl;
        cout << "--------------------------------------" << endl;

        // Generar dados sumadores solo para el tamaño actual
        int dadosAsumar[5];
        dadosSumadores(dadosAsumar, tamActual); // Llenar solo el número de dados activos

        // Sumar puntos excluyendo los dados bloqueados

        puntos = sumarPuntos(dadosAsumar, dadosBloqueados, tamActual, tamBloqueados);

        // Crear un nuevo array para los dados sumadores restantes después de eliminar repetidos
        int nuevosDados[5];
        int nuevoTam = 0;

        // Verificar dados que no se repiten para mantenerlos en el siguiente turno
        for (int i = 0; i < tamActual; i++)
        {
            bool esRepetido = false;
            for (int j = 0; j < tamBloqueados; j++)
            {
                if (dadosAsumar[i] == dadosBloqueados[j])
                {
                    esRepetido = true;
                    break;
                }
            }
            if (!esRepetido)
            {
                nuevosDados[nuevoTam++] = dadosAsumar[i];
            }
        }

        // Actualizar el array de dados sumadores y el tamaño para la próxima ronda
        for (int i = 0; i < nuevoTam; i++)
        {
            dadosAsumar[i] = nuevosDados[i];
        }
        tamActual = nuevoTam; // Actualizar el tamaño actual

        cout << "Desea seguir jugando? (s/n): ";
        cin >> eleccionUjugador;
        puntosTotales = puntosTotales + puntos;
    }
    while (eleccionUjugador == seguirJugando && tamActual > 0);

    cout<<"El jugador/a: "<<nombre<<" hizo "<<puntosTotales<<endl;


    if (tamActual == 0)
    {
        cout << "Todos los dados han sido eliminados. Fin del juego." << endl;
    }
}


