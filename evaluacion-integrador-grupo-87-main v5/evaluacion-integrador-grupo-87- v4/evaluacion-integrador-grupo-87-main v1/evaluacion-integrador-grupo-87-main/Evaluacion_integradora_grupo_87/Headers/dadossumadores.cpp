#include<iostream>
#include "dadossumadores.h"
#include <ctime>
using namespace std;

void dadosSumadores(int dados[], int tam) {
    for (int i = 0; i < tam; i++) {
        dados[i] = rand() % 6 + 1; // Genera un n�mero aleatorio entre 1 y 6
    }

    // Mostrar los valores de los dados sumadores para referencia
    cout << "Dados Sumadores: "<<endl;
    for (int i = 0; i < tam; i++) {
        cout << dados[i] << " "<<endl;
    }
    cout << endl;
}