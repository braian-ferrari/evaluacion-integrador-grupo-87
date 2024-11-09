#include <iostream>
#include "nombrejugador.h"
#include "dadosbloqueadores.h"
#include "dadossumadores.h"
#include <ctime>
using namespace std;


void unJugador() {
    char seguirJugando = 's';
    char eleccionUjugador;

    cout << "Modo un jugador seleccionado" << endl;
    cout<<"-------------------------------------"<<endl;

    string nombre = nombreJugador();

    do{
        cout<<"DADOS BLOQUEADORES"<<endl;
    dadosBloqueadores();
    cout<<"--------------------------------------"<<endl;
    dadosSumadores();

    cout<<"Seguir Jugando?"<<endl;
    cin>>eleccionUjugador;
    }while(eleccionUjugador==seguirJugando);


}
