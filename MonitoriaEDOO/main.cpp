#include <iostream>
#include "Ponta.h"
#include "Libero.h"
#include "Levantador.h"
#include "Oposto.h"
#include "Central.h"
#include "Relatorio.h"

using namespace std;

int main() {
    Ponta ponta1, ponta2;
    Libero serginho;
    Levantador bruninho;
    Oposto wallace;
    Central lucao;

    cin >> ponta1 >> ponta2 >> serginho >> bruninho >> wallace >> lucao;

    Jogador* time[6] = { &ponta1, &ponta2, &serginho, &bruninho, &wallace, &lucao };
    Relatorio::gerarRelatorio(time);

    return 0;
}
