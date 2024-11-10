#include<iostream>
#include "dadossumadores.h"
#include <ctime>
using namespace std;

void dadosSumadores(int dados[], int tam) {
    srand(time(0) + 1); // Cambia la semilla cada vez que se ejecuta
    for (int i = 0; i < tam; i++) {
        dados[i] = rand() % 6 + 1; // Genera un número aleatorio entre 1 y 6
    }

    // Mostrar los valores de los dados sumadores para referencia
    cout << "Dados Sumadores: ";
    for (int i = 0; i < tam; i++) {
        cout << dados[i] << " ";
    }
    cout << endl;
}
