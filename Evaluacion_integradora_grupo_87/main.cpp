#include <iostream>
#include "Headers/menu.h"
#include "Headers/unjugador.h"

using namespace std;

int main() {

    int eleccionUsuario;

    do {
        eleccionUsuario = seleccionDelUsuario();
        procesarLaEleccion(eleccionUsuario);
    } while (eleccionUsuario != 5);

    return 0;
}
