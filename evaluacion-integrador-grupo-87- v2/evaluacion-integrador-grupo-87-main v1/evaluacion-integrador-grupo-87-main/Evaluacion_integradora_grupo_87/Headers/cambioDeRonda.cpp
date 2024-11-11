#include <iostream>
#include "nombrejugador.h"
#include "dadosbloqueadores.h"
#include "dadossumadores.h"
#include "sumatoriaPuntos.h"
#include "cambioDeRonda.h"
#include <ctime>
#include <cctype> // Para usar tolower
using namespace std;

void cambioDeRonda(int* dadosBloqueados, int tamBloqueados, int& tamActual, int& puntosTotales, char& eleccionUjugador,int ronda)
{
    int puntosRonda = 0; // Variable para acumular los puntos de la ronda actual

    do {
        int puntosTirada = 0; // Acumulador de puntos de cada tirada

        // Regenerar dados sumadores solo para el tama�o actual
        int dadosAsumar[5];
        dadosSumadores(dadosAsumar, tamActual); // Aseg�rate de que `dadosSumadores` es una funci�n v�lida

        // Mostrar los dados bloqueadores actuales
        cout << "DADOS BLOQUEADORES: " << endl;
        for (int i = 0; i < tamBloqueados; i++) {
            cout << dadosBloqueados[i] << " "; // Aseg�rate de que `dadosBloqueados` es un arreglo de enteros
        }
        cout << endl;
        cout << "--------------------------------------" << endl;

        // Sumar puntos excluyendo los dados bloqueados
        puntosTirada = sumarPuntos(dadosAsumar, dadosBloqueados, tamActual, tamBloqueados);

        // Agregar los puntos de la tirada al acumulador de la ronda
        puntosRonda += puntosTirada;

        cout << "Puntos obtenidos en esta tirada: " << puntosTirada << endl;
        cout<<"-----------------------------------------"<<endl;
        //cout << "Puntos acumulados en la ronda: " << puntosRonda << endl;

        // Crear un nuevo array para los dados sumadores restantes despu�s de eliminar repetidos
        int nuevosDados[5];
        int nuevoTam = 0;

        // Verificar dados que no se repiten para mantenerlos en el siguiente turno
        for (int i = 0; i < tamActual; i++) {
            bool esRepetido = false;
            for (int j = 0; j < tamBloqueados; j++) {
                if (dadosAsumar[i] == dadosBloqueados[j]) { // Aseg�rate de que `dadosBloqueados[j]` es un entero, no una funci�n
                    esRepetido = true;
                    break;
                }
            }
            if (!esRepetido) {
                nuevosDados[nuevoTam++] = dadosAsumar[i];
            }
        }

        // Actualizar el array de dados sumadores y el tama�o para la pr�xima tirada
        for (int i = 0; i < nuevoTam; i++) {
            dadosAsumar[i] = nuevosDados[i];
        }
        tamActual = nuevoTam; // Actualizar el tama�o actual

        // Preguntar al jugador si desea continuar solo si quedan dados activos
        if (tamActual > 0) {
            cout << "Desea realizar otra tirada en esta ronda? (s/n): ";
            cin >> eleccionUjugador;
            cout<<"---------------------------------------------"<<endl;
            eleccionUjugador = tolower(eleccionUjugador); // Convertir a min�scula
        } else {
            cout<<"---------------------------------------------"<<endl;
            cout << "Perdiste la ronda todos los dados han sido eliminados. Cambiando de ronda." << endl;
            puntosRonda = 0; // Si todos los dados son eliminados, los puntos de la ronda son 0
            eleccionUjugador = 'n'; // Salir de la ronda si no quedan dados
        }

    } while (eleccionUjugador == 's' && tamActual > 0);
        cout << "Puntos acumulados en la ronda "<<ronda<<" : " << puntosRonda << endl;
        cout<<"-----------------------------------------"<<endl;
    // Al final de la ronda, agregar los puntos acumulados de la ronda al total general
    puntosTotales += puntosRonda;
}
