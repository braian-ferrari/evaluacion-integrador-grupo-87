#include<iostream>
#include <ctime>
#include "dadosbloqueadores.h"

using namespace std;

void dadosBloqueadores(int bloqueadores[]){
int dadosBloqueados[2];

  srand(time(0));

for(int i = 0; i<2;i++){
    bloqueadores[i] = rand() % 6 + 1;
}

}
