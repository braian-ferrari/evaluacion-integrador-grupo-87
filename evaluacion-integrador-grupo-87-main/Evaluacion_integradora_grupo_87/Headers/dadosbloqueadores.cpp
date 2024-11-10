#include<iostream>
#include <ctime>
#include "dadosbloqueadores.h"

using namespace std;


int dadosBloqueadores(){
int dadosBloqueados[2];

  srand(time(0));

for(int i = 0; i<2;i++){
    dadosBloqueados[i] = rand() % 6 + 1;
}

for (int i = 0; i<2; i++) {
        cout << " " << dadosBloqueados[i] << endl;
    }

    return dadosBloqueados[2];
}
