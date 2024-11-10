#include<iostream>
#include "dadossumadores.h"
#include <ctime>
using namespace std;

int dadosSumadores(){
    int dados[5];

srand(time(0));

    for (int i = 0; i < 5; i++) {
        dados[i] = rand() % 6 + 1;
    }
    for (int i = 0; i < 5; i++) {
        cout << " " << dados[i] << endl;
    }
    return dados[5];
}
