#include <iostream>
#include "Headers/menu.h"
#include "Headers/unjugador.h"
#include "headers/creditos.h"
#include "rlutil.h"
#include <ctime>


using namespace std;

int main(){
    srand(time(0));
    int eleccionUsuario;
    rlutil::setBackgroundColor(rlutil::GREEN);
    rlutil::setColor(rlutil::WHITE);

    do
    {
        system("cls"); //es para que se pise y no este creando un nuevo menu

        eleccionUsuario = seleccionDelUsuario();
        procesarLaEleccion(eleccionUsuario);

        cout << "presione cualquier tecla para continuar...";
        system ("pause >nul");
    }
    while (eleccionUsuario != 5);

    return 0;
}
